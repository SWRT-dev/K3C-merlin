/* vi: set sw=4 ts=4: */
/*
 * iptunnel.c	       "ip tunnel"
 *
 * Licensed under the GPL v2 or later, see the file LICENSE in this tarball.
 *
 * Authors:	Alexey Kuznetsov, <kuznet@ms2.inr.ac.ru>
 *
 * Changes:
 *
 * Rani Assaf <rani@magic.metawire.com> 980929:	resolve addresses
 * Rani Assaf <rani@magic.metawire.com> 980930:	do not allow key for ipip/sit
 * Phil Karn <karn@ka9q.ampr.org>	990408:	"pmtudisc" flag
 */

#include <netinet/ip.h>
#include <net/if.h>
#include <net/if_arp.h>
#include <asm/types.h>

#ifndef __constant_htons
#define __constant_htons htons
#endif

// FYI: #define SIOCDEVPRIVATE 0x89F0

/* From linux/if_tunnel.h. #including it proved troublesome
 * (redefiniton errors due to name collisions in linux/ and net[inet]/) */
#define SIOCGETTUNNEL   (SIOCDEVPRIVATE + 0)
#define SIOCADDTUNNEL   (SIOCDEVPRIVATE + 1)
#define SIOCDELTUNNEL   (SIOCDEVPRIVATE + 2)
#define SIOCCHGTUNNEL   (SIOCDEVPRIVATE + 3)
//#define SIOCGETPRL      (SIOCDEVPRIVATE + 4)
//#define SIOCADDPRL      (SIOCDEVPRIVATE + 5)
//#define SIOCDELPRL      (SIOCDEVPRIVATE + 6)
//#define SIOCCHGPRL      (SIOCDEVPRIVATE + 7)
#define GRE_CSUM        __constant_htons(0x8000)
//#define GRE_ROUTING     __constant_htons(0x4000)
#define GRE_KEY         __constant_htons(0x2000)
#define GRE_SEQ         __constant_htons(0x1000)
//#define GRE_STRICT      __constant_htons(0x0800)
//#define GRE_REC         __constant_htons(0x0700)
//#define GRE_FLAGS       __constant_htons(0x00F8)
//#define GRE_VERSION     __constant_htons(0x0007)
struct ip_tunnel_parm {
	char            name[IFNAMSIZ];
	int             link;
	uint16_t        i_flags;
	uint16_t        o_flags;
	uint32_t        i_key;
	uint32_t        o_key;
	struct iphdr    iph;
};
/* SIT-mode i_flags */
//#define SIT_ISATAP 0x0001
//struct ip_tunnel_prl {
//	uint32_t          addr;
//	uint16_t          flags;
//	uint16_t          __reserved;
//	uint32_t          datalen;
//	uint32_t          __reserved2;
//	/* data follows */
//};
///* PRL flags */
//#define PRL_DEFAULT 0x0001


/* Start of ip6_tunnel */
#define IPV6_TLV_TNL_ENCAP_LIMIT 4
#define IPV6_DEFAULT_TNL_ENCAP_LIMIT 4

/* don't add encapsulation limit if one isn't present in inner packet */
#define IP6_TNL_F_IGN_ENCAP_LIMIT 0x1
/* copy the traffic class field from the inner packet */
#define IP6_TNL_F_USE_ORIG_TCLASS 0x2
/* copy the flowlabel from the inner packet */
#define IP6_TNL_F_USE_ORIG_FLOWLABEL 0x4
/* being used for Mobile IPv6 */
#define IP6_TNL_F_MIP6_DEV 0x8
/* copy DSCP from the outer packet */
#define IP6_TNL_F_RCV_DSCP_COPY 0x10

struct ip6_tnl_parm {
    char name[IFNAMSIZ];    /* name of tunnel device */
    int link;       /* ifindex of underlying L2 interface */
    __u8 proto;     /* tunnel protocol */
    __u8 encap_limit;   /* encapsulation limit for tunnel */
    __u8 hop_limit;     /* hop limit for tunnel */
    __u32 flowinfo;    /* traffic class and flowlabel for tunnel */ // FIXME: should be __be32 ?
    __u32 flags;        /* tunnel flags */
    struct in6_addr laddr;  /* local tunnel end-point address */
    struct in6_addr raddr;  /* remote tunnel end-point address */
};
/* End of ip6_tunnel */

#include "ip_common.h"  /* #include "libbb.h" is inside */
#include "rt_names.h"
#include "utils.h"


/* Dies on error */
static int do_ioctl_get_ifindex(char *dev)
{
	struct ifreq ifr;
	int fd;

	strncpy_IFNAMSIZ(ifr.ifr_name, dev);
	fd = xsocket(AF_INET, SOCK_DGRAM, 0);
	xioctl(fd, SIOCGIFINDEX, &ifr);
	close(fd);
	return ifr.ifr_ifindex;
}

static int do_ioctl_get_iftype(char *dev)
{
	struct ifreq ifr;
	int fd;
	int err;

	strncpy_IFNAMSIZ(ifr.ifr_name, dev);
	fd = xsocket(AF_INET, SOCK_DGRAM, 0);
	err = ioctl_or_warn(fd, SIOCGIFHWADDR, &ifr);
	close(fd);
	return err ? -1 : ifr.ifr_addr.sa_family;
}

static char *do_ioctl_get_ifname(int idx)
{
	struct ifreq ifr;
	int fd;
	int err;

	ifr.ifr_ifindex = idx;
	fd = xsocket(AF_INET, SOCK_DGRAM, 0);
	err = ioctl_or_warn(fd, SIOCGIFNAME, &ifr);
	close(fd);
	return err ? NULL : xstrndup(ifr.ifr_name, sizeof(ifr.ifr_name));
}

static int do_get_ioctl(const char *basedev, void *p)
{
	struct ifreq ifr;
	int fd;
	int err;

	strncpy_IFNAMSIZ(ifr.ifr_name, basedev);
	ifr.ifr_ifru.ifru_data = (void*)p;
	fd = xsocket(preferred_family, SOCK_DGRAM, 0);
	err = ioctl_or_warn(fd, SIOCGETTUNNEL, &ifr);
	close(fd);
	return err;
}

/* Dies on error, otherwise returns 0 */
static int do_add_ioctl(int cmd, const char *basedev, const char *name, void *p)
{
	struct ifreq ifr;
	int fd;

/*printf("[%s:%d]\n", __func__, __LINE__); */
	if (cmd == SIOCCHGTUNNEL && name[0]) {
/*printf("[%s:%d]\n", __func__, __LINE__); */
		strncpy_IFNAMSIZ(ifr.ifr_name, name);
	} else {
		strncpy_IFNAMSIZ(ifr.ifr_name, basedev);
	}
	ifr.ifr_ifru.ifru_data = (void*)p;
	fd = xsocket(preferred_family, SOCK_DGRAM, 0);
#if ENABLE_IOCTL_HEX2STR_ERROR
	/* #define magic will turn ioctl# into string */
	if (cmd == SIOCCHGTUNNEL)
		xioctl(fd, SIOCCHGTUNNEL, &ifr);
	else
		xioctl(fd, SIOCADDTUNNEL, &ifr);
#else
	xioctl(fd, cmd, &ifr);
#endif
/*printf("[%s:%d]\n", __func__, __LINE__); */
	close(fd);
	return 0;
}

/* Dies on error, otherwise returns 0 */
static int do_del_ioctl(const char *basedev, const char *name, void *p)
{
	struct ifreq ifr;
	int fd;

	if (name[0]) {
		strncpy_IFNAMSIZ(ifr.ifr_name, name);
	} else {
		strncpy_IFNAMSIZ(ifr.ifr_name, basedev);
	}
	ifr.ifr_ifru.ifru_data = (void*)p;
	fd = xsocket(preferred_family, SOCK_DGRAM, 0);
	xioctl(fd, SIOCDELTUNNEL, &ifr);
	close(fd);
	return 0;
}

/* Dies on error */
static void parse_args(char **argv, int cmd, struct ip_tunnel_parm *p)
{
	static const char keywords[] ALIGN1 =
		"mode\0""ipip\0""ip/ip\0""gre\0""gre/ip\0""sit\0""ipv6/ip\0"
		"key\0""ikey\0""okey\0""seq\0""iseq\0""oseq\0"
		"csum\0""icsum\0""ocsum\0""nopmtudisc\0""pmtudisc\0"
		"remote\0""any\0""local\0""dev\0"
		"ttl\0""inherit\0""tos\0""dsfield\0"
		"name\0";
	enum {
		ARG_mode, ARG_ipip, ARG_ip_ip, ARG_gre, ARG_gre_ip, ARG_sit, ARG_ip6_ip,
		ARG_key, ARG_ikey, ARG_okey, ARG_seq, ARG_iseq, ARG_oseq,
		ARG_csum, ARG_icsum, ARG_ocsum, ARG_nopmtudisc, ARG_pmtudisc,
		ARG_remote, ARG_any, ARG_local, ARG_dev,
		ARG_ttl, ARG_inherit, ARG_tos, ARG_dsfield,
		ARG_name
	};
	int count = 0;
	char medium[IFNAMSIZ];
	int key;

	memset(p, 0, sizeof(*p));
	medium[0] = '\0';

	p->iph.version = 4;
	p->iph.ihl = 5;
#ifndef IP_DF
#define IP_DF 0x4000  /* Flag: "Don't Fragment" */
#endif
	p->iph.frag_off = htons(IP_DF);

	while (*argv) {
		key = index_in_strings(keywords, *argv);
		if (key == ARG_mode) {
			NEXT_ARG();
			key = index_in_strings(keywords, *argv);
			if (key == ARG_ipip ||
			    key == ARG_ip_ip
			) {
				if (p->iph.protocol && p->iph.protocol != IPPROTO_IPIP) {
					bb_error_msg_and_die("%s tunnel mode", "you managed to ask for more than one");
				}
				p->iph.protocol = IPPROTO_IPIP;
			} else if (key == ARG_gre ||
				   key == ARG_gre_ip
			) {
				if (p->iph.protocol && p->iph.protocol != IPPROTO_GRE) {
					bb_error_msg_and_die("%s tunnel mode", "you managed to ask for more than one");
				}
				p->iph.protocol = IPPROTO_GRE;
			} else if (key == ARG_sit ||
				   key == ARG_ip6_ip
			) {
				if (p->iph.protocol && p->iph.protocol != IPPROTO_IPV6) {
					bb_error_msg_and_die("%s tunnel mode", "you managed to ask for more than one");
				}
				p->iph.protocol = IPPROTO_IPV6;
			} else {
				bb_error_msg_and_die("%s tunnel mode", "can't guess");
			}
		} else if (key == ARG_key) {
			unsigned uval;
			NEXT_ARG();
			p->i_flags |= GRE_KEY;
			p->o_flags |= GRE_KEY;
			if (strchr(*argv, '.'))
				p->i_key = p->o_key = get_addr32(*argv);
			else {
				uval = get_unsigned(*argv, "key");
				p->i_key = p->o_key = htonl(uval);
			}
		} else if (key == ARG_ikey) {
			unsigned uval;
			NEXT_ARG();
			p->i_flags |= GRE_KEY;
			if (strchr(*argv, '.'))
				p->o_key = get_addr32(*argv);
			else {
				uval = get_unsigned(*argv, "ikey");
				p->i_key = htonl(uval);
			}
		} else if (key == ARG_okey) {
			unsigned uval;
			NEXT_ARG();
			p->o_flags |= GRE_KEY;
			if (strchr(*argv, '.'))
				p->o_key = get_addr32(*argv);
			else {
				uval = get_unsigned(*argv, "okey");
				p->o_key = htonl(uval);
			}
		} else if (key == ARG_seq) {
			p->i_flags |= GRE_SEQ;
			p->o_flags |= GRE_SEQ;
		} else if (key == ARG_iseq) {
			p->i_flags |= GRE_SEQ;
		} else if (key == ARG_oseq) {
			p->o_flags |= GRE_SEQ;
		} else if (key == ARG_csum) {
			p->i_flags |= GRE_CSUM;
			p->o_flags |= GRE_CSUM;
		} else if (key == ARG_icsum) {
			p->i_flags |= GRE_CSUM;
		} else if (key == ARG_ocsum) {
			p->o_flags |= GRE_CSUM;
		} else if (key == ARG_nopmtudisc) {
			p->iph.frag_off = 0;
		} else if (key == ARG_pmtudisc) {
			p->iph.frag_off = htons(IP_DF);
		} else if (key == ARG_remote) {
			NEXT_ARG();
			key = index_in_strings(keywords, *argv);
			if (key != ARG_any)
				p->iph.daddr = get_addr32(*argv);
		} else if (key == ARG_local) {
			NEXT_ARG();
			key = index_in_strings(keywords, *argv);
			if (key != ARG_any)
				p->iph.saddr = get_addr32(*argv);
		} else if (key == ARG_dev) {
			NEXT_ARG();
			strncpy_IFNAMSIZ(medium, *argv);
		} else if (key == ARG_ttl) {
			unsigned uval;
			NEXT_ARG();
			key = index_in_strings(keywords, *argv);
			if (key != ARG_inherit) {
				uval = get_unsigned(*argv, "TTL");
				if (uval > 255)
					invarg(*argv, "TTL must be <=255");
				p->iph.ttl = uval;
			}
		} else if (key == ARG_tos ||
			   key == ARG_dsfield
		) {
			uint32_t uval;
			NEXT_ARG();
			key = index_in_strings(keywords, *argv);
			if (key != ARG_inherit) {
				if (rtnl_dsfield_a2n(&uval, *argv))
					invarg(*argv, "TOS");
				p->iph.tos = uval;
			} else
				p->iph.tos = 1;
		} else {
			if (key == ARG_name) {
				NEXT_ARG();
			}
			if (p->name[0])
				duparg2("name", *argv);
			strncpy_IFNAMSIZ(p->name, *argv);
			if (cmd == SIOCCHGTUNNEL && count == 0) {
				struct ip_tunnel_parm old_p;
				memset(&old_p, 0, sizeof(old_p));
				if (do_get_ioctl(*argv, &old_p))
					exit(EXIT_FAILURE);
				*p = old_p;
			}
		}
		count++;
		argv++;
	}

	if (p->iph.protocol == 0) {
		if (memcmp(p->name, "gre", 3) == 0)
			p->iph.protocol = IPPROTO_GRE;
		else if (memcmp(p->name, "ipip", 4) == 0)
			p->iph.protocol = IPPROTO_IPIP;
		else if (memcmp(p->name, "sit", 3) == 0)
			p->iph.protocol = IPPROTO_IPV6;
	}

	if (p->iph.protocol == IPPROTO_IPIP || p->iph.protocol == IPPROTO_IPV6) {
		if ((p->i_flags & GRE_KEY) || (p->o_flags & GRE_KEY)) {
			bb_error_msg_and_die("keys are not allowed with ipip and sit");
		}
	}

	if (medium[0]) {
		p->link = do_ioctl_get_ifindex(medium);
	}

	if (p->i_key == 0 && IN_MULTICAST(ntohl(p->iph.daddr))) {
		p->i_key = p->iph.daddr;
		p->i_flags |= GRE_KEY;
	}
	if (p->o_key == 0 && IN_MULTICAST(ntohl(p->iph.daddr))) {
		p->o_key = p->iph.daddr;
		p->o_flags |= GRE_KEY;
	}
	if (IN_MULTICAST(ntohl(p->iph.daddr)) && !p->iph.saddr) {
		bb_error_msg_and_die("broadcast tunnel requires a source address");
	}
}

/* Return value becomes exitcode. It's okay to not return at all */
static int do_add(int cmd, char **argv)
{
	struct ip_tunnel_parm p;

/*printf("[%s:%d]\n", __func__, __LINE__);  */
	parse_args(argv, cmd, &p);

	if (p.iph.ttl && p.iph.frag_off == 0) {
		bb_error_msg_and_die("ttl != 0 and noptmudisc are incompatible");
	}

	switch (p.iph.protocol) {
	case IPPROTO_IPIP:
/*printf("[%s:%d]\n", __func__, __LINE__); */
		return do_add_ioctl(cmd, "tunl0", p.name, &p);
	case IPPROTO_GRE:
		return do_add_ioctl(cmd, "gre0", p.name, &p);
	case IPPROTO_IPV6:
		return do_add_ioctl(cmd, "sit0", p.name, &p);
	default:
		bb_error_msg_and_die("can't determine tunnel mode (ipip, gre or sit)");
	}
}

/* Return value becomes exitcode. It's okay to not return at all */
static int do_del(char **argv)
{
	struct ip_tunnel_parm p;

	parse_args(argv, SIOCDELTUNNEL, &p);

	switch (p.iph.protocol) {
	case IPPROTO_IPIP:
		return do_del_ioctl("tunl0", p.name, &p);
	case IPPROTO_GRE:
		return do_del_ioctl("gre0", p.name, &p);
	case IPPROTO_IPV6:
		return do_del_ioctl("sit0", p.name, &p);
	default:
		return do_del_ioctl(p.name, p.name, &p);
	}
}

static void print_tunnel(struct ip_tunnel_parm *p)
{
	char s1[256];
	char s2[256];
	char s3[64];
	char s4[64];

	format_host(AF_INET, 4, &p->iph.daddr, s1, sizeof(s1));
	format_host(AF_INET, 4, &p->iph.saddr, s2, sizeof(s2));
	inet_ntop(AF_INET, &p->i_key, s3, sizeof(s3));
	inet_ntop(AF_INET, &p->o_key, s4, sizeof(s4));

	printf("%s: %s/ip  remote %s  local %s ",
	       p->name,
	       p->iph.protocol == IPPROTO_IPIP ? "ip" :
	       (p->iph.protocol == IPPROTO_GRE ? "gre" :
		(p->iph.protocol == IPPROTO_IPV6 ? "ipv6" : "unknown")),
	       p->iph.daddr ? s1 : "any", p->iph.saddr ? s2 : "any");
	if (p->link) {
		char *n = do_ioctl_get_ifname(p->link);
		if (n) {
			printf(" dev %s ", n);
			free(n);
		}
	}
	if (p->iph.ttl)
		printf(" ttl %d ", p->iph.ttl);
	else
		printf(" ttl inherit ");
	if (p->iph.tos) {
		SPRINT_BUF(b1);
		printf(" tos");
		if (p->iph.tos & 1)
			printf(" inherit");
		if (p->iph.tos & ~1)
			printf("%c%s ", p->iph.tos & 1 ? '/' : ' ',
			       rtnl_dsfield_n2a(p->iph.tos & ~1, b1));
	}
	if (!(p->iph.frag_off & htons(IP_DF)))
		printf(" nopmtudisc");

	if ((p->i_flags & GRE_KEY) && (p->o_flags & GRE_KEY) && p->o_key == p->i_key)
		printf(" key %s", s3);
	else if ((p->i_flags | p->o_flags) & GRE_KEY) {
		if (p->i_flags & GRE_KEY)
			printf(" ikey %s ", s3);
		if (p->o_flags & GRE_KEY)
			printf(" okey %s ", s4);
	}

	if (p->i_flags & GRE_SEQ)
		printf("%c  Drop packets out of sequence.\n", _SL_);
	if (p->i_flags & GRE_CSUM)
		printf("%c  Checksum in received packet is required.", _SL_);
	if (p->o_flags & GRE_SEQ)
		printf("%c  Sequence packets on output.", _SL_);
	if (p->o_flags & GRE_CSUM)
		printf("%c  Checksum output packets.", _SL_);
}

static void do_tunnels_list(struct ip_tunnel_parm *p)
{
	char name[IFNAMSIZ];
	unsigned long rx_bytes, rx_packets, rx_errs, rx_drops,
		rx_fifo, rx_frame,
		tx_bytes, tx_packets, tx_errs, tx_drops,
		tx_fifo, tx_colls, tx_carrier, rx_multi;
	int type;
	struct ip_tunnel_parm p1;
	char buf[512];
	FILE *fp = fopen_or_warn("/proc/net/dev", "r");

	if (fp == NULL) {
		return;
	}
	/* skip headers */
	fgets(buf, sizeof(buf), fp);
	fgets(buf, sizeof(buf), fp);

	while (fgets(buf, sizeof(buf), fp) != NULL) {
		char *ptr;

		/*buf[sizeof(buf) - 1] = 0; - fgets is safe anyway */
		ptr = strchr(buf, ':');
		if (ptr == NULL ||
		    (*ptr++ = 0, sscanf(buf, "%s", name) != 1)
		) {
			bb_error_msg("wrong format of /proc/net/dev");
			return;
		}
		if (sscanf(ptr, "%lu%lu%lu%lu%lu%lu%lu%*d%lu%lu%lu%lu%lu%lu%lu",
			   &rx_bytes, &rx_packets, &rx_errs, &rx_drops,
			   &rx_fifo, &rx_frame, &rx_multi,
			   &tx_bytes, &tx_packets, &tx_errs, &tx_drops,
			   &tx_fifo, &tx_colls, &tx_carrier) != 14)
			continue;
		if (p->name[0] && strcmp(p->name, name))
			continue;
		type = do_ioctl_get_iftype(name);
		if (type == -1) {
			bb_error_msg("can't get type of [%s]", name);
			continue;
		}
		if (type != ARPHRD_TUNNEL && type != ARPHRD_IPGRE && type != ARPHRD_SIT)
			continue;
		memset(&p1, 0, sizeof(p1));
		if (do_get_ioctl(name, &p1))
			continue;
		if ((p->link && p1.link != p->link) ||
		    (p->name[0] && strcmp(p1.name, p->name)) ||
		    (p->iph.daddr && p1.iph.daddr != p->iph.daddr) ||
		    (p->iph.saddr && p1.iph.saddr != p->iph.saddr) ||
		    (p->i_key && p1.i_key != p->i_key)
		) {
			continue;
		}
		print_tunnel(&p1);
		bb_putchar('\n');
	}
}

/* Return value becomes exitcode. It's okay to not return at all */
static int do_show(char **argv)
{
	int err;
	struct ip_tunnel_parm p;

	parse_args(argv, SIOCGETTUNNEL, &p);

	switch (p.iph.protocol) {
	case IPPROTO_IPIP:
		err = do_get_ioctl(p.name[0] ? p.name : "tunl0", &p);
		break;
	case IPPROTO_GRE:
		err = do_get_ioctl(p.name[0] ? p.name : "gre0", &p);
		break;
	case IPPROTO_IPV6:
		err = do_get_ioctl(p.name[0] ? p.name : "sit0", &p);
		break;
	default:
		do_tunnels_list(&p);
		return 0;
	}
	if (err)
		return -1;

	print_tunnel(&p);
	bb_putchar('\n');
	return 0;
}


/* start of ip6_tunnel */

#define IP6_FLOWINFO_TCLASS     htonl(0x0FF00000)
#define IP6_FLOWINFO_FLOWLABEL  htonl(0x000FFFFF)

#define DEFAULT_TNL_HOP_LIMIT   (64)

int strmatches(const char *cmd, const char *pattern)  // FIXME:: Move this to utils.c
{
        int len = strlen(cmd);
        if (len > strlen(pattern))
                return -1;
        return memcmp(pattern, cmd, len);
}

static void usage6(void)
{
        fprintf(stderr, "Usage: ip -f inet6 tunnel { add | change | del | show } [ NAME ]\n");
        fprintf(stderr, "          [ mode { ipip6 } ]\n");
        fprintf(stderr, "          [ remote ADDR local ADDR ] [ dev PHYS_DEV ]\n");
        fprintf(stderr, "          [ encaplimit ELIM ]\n");
        fprintf(stderr ,"          [ hoplimit TTL ] [ tclass TCLASS ] [ flowlabel FLOWLABEL ]\n");
        fprintf(stderr, "          [ dscp inherit ]\n");
        fprintf(stderr, "\n");
        fprintf(stderr, "Where: NAME      := STRING\n");
        fprintf(stderr, "       ADDR      := IPV6_ADDRESS\n");
        fprintf(stderr, "       ELIM      := { none | 0..255 }(default=%d)\n",
                IPV6_DEFAULT_TNL_ENCAP_LIMIT);
        fprintf(stderr, "       TTL       := 0..255 (default=%d)\n",
                DEFAULT_TNL_HOP_LIMIT);
        fprintf(stderr, "       TOS       := { 0x0..0xff | inherit }\n");
        fprintf(stderr, "       FLOWLABEL := { 0x0..0xfffff | inherit }\n");
        exit(-1);
}

static void ip6_tnl_parm_init(struct ip6_tnl_parm *p, int apply_default)
{
        memset(p, 0, sizeof(*p));
        p->proto = IPPROTO_IPV6;
        if (apply_default) {
                p->hop_limit = DEFAULT_TNL_HOP_LIMIT;
                p->encap_limit = IPV6_DEFAULT_TNL_ENCAP_LIMIT;
        }
}

static int ip6_tnl_parm_match(const struct ip6_tnl_parm *p1,
                              const struct ip6_tnl_parm *p2)
{
        return ((!p1->link || p1->link == p2->link) &&
                (!p1->name[0] || strcmp(p1->name, p2->name) == 0) &&
                (memcmp(&p1->laddr, &in6addr_any, sizeof(p1->laddr)) == 0 ||
                 memcmp(&p1->laddr, &p2->laddr, sizeof(p1->laddr)) == 0) &&
                (memcmp(&p1->raddr, &in6addr_any, sizeof(p1->raddr)) == 0 ||
                 memcmp(&p1->raddr, &p2->raddr, sizeof(p1->raddr)) == 0) &&
                (!p1->proto || !p2->proto || p1->proto == p2->proto) &&
                (!p1->encap_limit || p1->encap_limit == p2->encap_limit) &&
                (!p1->hop_limit || p1->hop_limit == p2->hop_limit) &&
                (!(p1->flowinfo & IP6_FLOWINFO_TCLASS) ||
                 !((p1->flowinfo ^ p2->flowinfo) & IP6_FLOWINFO_TCLASS)) &&
                (!(p1->flowinfo & IP6_FLOWINFO_FLOWLABEL) ||
                 !((p1->flowinfo ^ p2->flowinfo) & IP6_FLOWINFO_FLOWLABEL)) &&
                (!p1->flags || (p1->flags & p2->flags)));
}

static const char *tnl_strproto(__u8 proto)
{
        static char buf[16];

        switch (proto) {
        case IPPROTO_IPIP:
                strcpy(buf, "ip");
                break;
        case IPPROTO_GRE:
                strcpy(buf, "gre");
                break;
        case IPPROTO_IPV6:
                strcpy(buf, "ipv6");
                break;
        case 0:
                strcpy(buf, "any");
                break;
        default:
                strcpy(buf, "unknown");
                break;
        }

        return buf;
}

static void print_tunnel6(struct ip6_tnl_parm *p)
{
        char remote[64];
        char local[64];

        inet_ntop(AF_INET6, &p->raddr, remote, sizeof(remote));
        inet_ntop(AF_INET6, &p->laddr, local, sizeof(local));

        printf("%s: %s/ipv6 remote %s local %s",
               p->name, tnl_strproto(p->proto), remote, local);
        if (p->link) {
                char *n = do_ioctl_get_ifname(p->link);
                if (n) {
                        printf(" dev %s", n);
						free(n);
				}
        }

        if (p->flags & IP6_TNL_F_IGN_ENCAP_LIMIT)
                printf(" encaplimit none");
        else
                printf(" encaplimit %u", p->encap_limit);

        printf(" hoplimit %u", p->hop_limit);

        if (p->flags & IP6_TNL_F_USE_ORIG_TCLASS)
                printf(" tclass inherit");
        else {
                __u32 val = ntohl(p->flowinfo & IP6_FLOWINFO_TCLASS);
                printf(" tclass 0x%02x", (__u8)(val >> 20));
        }

        if (p->flags & IP6_TNL_F_USE_ORIG_FLOWLABEL)
                printf(" flowlabel inherit");
        else
                printf(" flowlabel 0x%05x", ntohl(p->flowinfo & IP6_FLOWINFO_FLOWLABEL));

        printf(" (flowinfo 0x%08x)", ntohl(p->flowinfo));

        if (p->flags & IP6_TNL_F_RCV_DSCP_COPY)
                printf(" dscp inherit");
}

static int do_tunnels_list6(struct ip6_tnl_parm *p)
{
        char buf[512];
        int err = -1;
        FILE *fp = fopen("/proc/net/dev", "r");
        if (fp == NULL) {
                perror("fopen");
                goto end;
        }

        /* skip two lines at the begenning of the file */
        fgets(buf, sizeof(buf), fp);
        fgets(buf, sizeof(buf), fp);

        while (fgets(buf, sizeof(buf), fp) != NULL) {
                char name[IFNAMSIZ];
                int ifindex, type;
                unsigned long rx_bytes, rx_packets, rx_errs, rx_drops,
                        rx_fifo, rx_frame,
                        tx_bytes, tx_packets, tx_errs, tx_drops,
                        tx_fifo, tx_colls, tx_carrier, rx_multi;
                struct ip6_tnl_parm p1;
                char *ptr;
				//char *n;

                buf[sizeof(buf) - 1] = '\0';
                if ((ptr = strchr(buf, ':')) == NULL ||
                    (*ptr++ = 0, sscanf(buf, "%s", name) != 1)) {
                        fprintf(stderr, "Wrong format of /proc/net/dev. Sorry.\n");
                        goto end;
                }
                if (sscanf(ptr, "%ld%ld%ld%ld%ld%ld%ld%*d%ld%ld%ld%ld%ld%ld%ld",
                           &rx_bytes, &rx_packets, &rx_errs, &rx_drops,
                           &rx_fifo, &rx_frame, &rx_multi,
                           &tx_bytes, &tx_packets, &tx_errs, &tx_drops,
                           &tx_fifo, &tx_colls, &tx_carrier) != 14)
                        continue;
                if (p->name[0] && strcmp(p->name, name))
                        continue;
                ifindex = do_ioctl_get_ifindex(name);
                if (ifindex == 0)
                        continue;
                type = do_ioctl_get_iftype(name);
                if (type == -1) {
                        fprintf(stderr, "Failed to get type of [%s]\n", name);
                        continue;
                }
                if (type != ARPHRD_TUNNEL6)
                        continue;
                memset(&p1, 0, sizeof(p1));
                ip6_tnl_parm_init(&p1, 0);
                strcpy(p1.name, name);
                p1.link = do_ioctl_get_ifindex(p1.name);
                if (p1.link == 0)
                        continue;
                if (do_get_ioctl(p1.name, &p1))
                        continue;
                if (!ip6_tnl_parm_match(p, &p1))
                        continue;
                print_tunnel6(&p1);
                printf("\n");
        }
        err = 0;

 end:
        if (fp)
                fclose(fp);
        return err;
}

static int parse_args6(int argc, char **argv, struct ip6_tnl_parm *p)
{
        char medium[IFNAMSIZ];

        memset(medium, 0, sizeof(medium));

        while (*argv) {
                if (strcmp(*argv, "mode") == 0) {
                        NEXT_ARG();
                        if (strcmp(*argv, "ipv6/ipv6") == 0 ||
                            strcmp(*argv, "ip6ip6") == 0)
                                p->proto = IPPROTO_IPV6;
                        else if (strcmp(*argv, "ip/ipv6") == 0 ||
                                 strcmp(*argv, "ipv4/ipv6") == 0 ||
                                 strcmp(*argv, "ipip6") == 0 ||
                                 strcmp(*argv, "ip4ip6") == 0)
                                p->proto = IPPROTO_IPIP;
                        else if (strcmp(*argv, "any/ipv6") == 0 ||
                                 strcmp(*argv, "any") == 0)
                                p->proto = 0;
                        else {
                                fprintf(stderr,"Cannot guess tunnel mode.\n");
                                exit(-1);
                        }
                } else if (strcmp(*argv, "remote") == 0) {
                        inet_prefix raddr;
                        NEXT_ARG();
                        get_prefix(&raddr, *argv, preferred_family);
                        if (raddr.family == AF_UNSPEC)
                                invarg("\"remote\" address family is AF_UNSPEC", *argv);
                        memcpy(&p->raddr, &raddr.data, sizeof(p->raddr));
                } else if (strcmp(*argv, "local") == 0) {
                        inet_prefix laddr;
                        NEXT_ARG();
                        get_prefix(&laddr, *argv, preferred_family);
                        if (laddr.family == AF_UNSPEC)
                                invarg("\"local\" address family is AF_UNSPEC", *argv);
                        memcpy(&p->laddr, &laddr.data, sizeof(p->laddr));
                } else if (strcmp(*argv, "dev") == 0) {
                        NEXT_ARG();
                        strncpy(medium, *argv, IFNAMSIZ - 1);
                } else if (strcmp(*argv, "encaplimit") == 0) {
                        NEXT_ARG();
                        if (strcmp(*argv, "none") == 0) {
                                p->flags |= IP6_TNL_F_IGN_ENCAP_LIMIT;
                        } else {
                                __u8 uval;
                                if (get_u8_base(&uval, *argv, 0) < -1) {
                                        invarg("invalid ELIM", *argv);
								}
                                p->encap_limit = uval;
                        }
                } else if (strcmp(*argv, "hoplimit") == 0 ||
                           strcmp(*argv, "ttl") == 0 ||
                           strcmp(*argv, "hlim") == 0) {
                        __u8 uval;
                        NEXT_ARG();
                        if (get_u8_base(&uval, *argv, 0))
                                invarg("invalid TTL", *argv);
                        p->hop_limit = uval;
                } else if (strcmp(*argv, "tclass") == 0 ||
                           strcmp(*argv, "tc") == 0 ||
                           strcmp(*argv, "tos") == 0 ||
                           strmatches(*argv, "dsfield") == 0) {
                        __u8 uval;
                        NEXT_ARG();
                        if (strcmp(*argv, "inherit") == 0)
                                p->flags |= IP6_TNL_F_USE_ORIG_TCLASS;
                        else {
                                if (get_u8_base(&uval, *argv, 16)) {
                                        invarg("invalid TClass", *argv);
								}
                                p->flowinfo |= htonl((__u32)uval << 20) & IP6_FLOWINFO_TCLASS;
                                p->flags &= ~IP6_TNL_F_USE_ORIG_TCLASS;
                        }
                } else if (strcmp(*argv, "flowlabel") == 0 ||
                           strcmp(*argv, "fl") == 0) {
                        __u32 uval;
                        NEXT_ARG();
                        if (strcmp(*argv, "inherit") == 0)
                                p->flags |= IP6_TNL_F_USE_ORIG_FLOWLABEL;
                        else {
                                if (get_u32_base(&uval, *argv, 16))
                                        invarg("invalid Flowlabel", *argv);
                                if (uval > 0xFFFFF)
                                        invarg("invalid Flowlabel", *argv);
                                p->flowinfo |= htonl(uval) & IP6_FLOWINFO_FLOWLABEL;
                                p->flags &= ~IP6_TNL_F_USE_ORIG_FLOWLABEL;
                        }
                } else if (strcmp(*argv, "dscp") == 0) {
                        NEXT_ARG();
                        if (strcmp(*argv, "inherit") != 0)
                                invarg("not inherit", *argv);
                        p->flags |= IP6_TNL_F_RCV_DSCP_COPY;
                } else {
                        if (strcmp(*argv, "name") == 0) {
                                NEXT_ARG();
                        }
                        if (strmatches(*argv, "help") == 0)
                                usage6();
                        if (p->name[0])
                                duparg2("name", *argv);
                        strncpy(p->name, *argv, IFNAMSIZ - 1);
                }
                argc--; argv++;
        }
        if (medium[0]) {
                p->link = do_ioctl_get_ifindex(medium);
                if (p->link == 0)
                        return -1;
        }
        return 0;
}

static int do_show6(int argc, char **argv)
{
        struct ip6_tnl_parm p;
		struct rtnl_handle rth;

        ll_init_map(&rth);
        ip6_tnl_parm_init(&p, 0);
        p.proto = 0;  /* default to any */

        if (parse_args6(argc, argv, &p) < 0)
                return -1;

        if (!p.name[0])
                do_tunnels_list6(&p);
        else {
                if (do_get_ioctl(p.name, &p))
                        return -1;
                print_tunnel6(&p);
                printf("\n");
        }

        return 0;
}


static int do_del6(int argc, char **argv)
{
        struct ip6_tnl_parm p;

        ip6_tnl_parm_init(&p, 1);

        if (parse_args6(argc, argv, &p) < 0)
                return -1;

        return do_del_ioctl(p.name[0] ? p.name : "ip6tnl0", p.name, &p);
}

static int do_add6(int cmd, int argc, char **argv)
{
    struct ip6_tnl_parm p;

    ip6_tnl_parm_init(&p, 1);

    if (parse_args6(argc, argv, &p) < 0)
        return -1;

    return do_add_ioctl(cmd,
                 cmd == SIOCCHGTUNNEL && p.name[0] ?
                 p.name : "ip6tnl0", p.name, &p);
}

static int do_ip6tunnel(int argc, char **argv)
{
    switch (preferred_family) {
    case AF_UNSPEC:
        preferred_family = AF_INET6;
        break;
    case AF_INET6:
        break;
    default:
        fprintf(stderr, "Unsupported family:%d\n", preferred_family);
        exit(-1);
    }

    if (argc > 0) {
        if (strmatches(*argv, "add") == 0) {
            return do_add6(SIOCADDTUNNEL, argc - 1, argv + 1);
        }
        if (strmatches(*argv, "change") == 0)
            return do_add6(SIOCCHGTUNNEL, argc - 1, argv + 1);
        if (strmatches(*argv, "del") == 0)
            return do_del6(argc - 1, argv + 1);
        if (strmatches(*argv, "show") == 0 ||
            strmatches(*argv, "lst") == 0 ||
            strmatches(*argv, "list") == 0)
            return do_show6(argc - 1, argv + 1);
        if (strmatches(*argv, "help") == 0)
            usage6();
    } else
        return do_show6(0, NULL);

    fprintf(stderr, "Command \"%s\" is unknown, try \"ip -f inet6 tunnel help\".\n", *argv);
    exit(-1);
}


/* end of ip6_tunnel */



/* Return value becomes exitcode. It's okay to not return at all */
int do_iptunnel(int argc, char **argv)
{
	static const char keywords[] ALIGN1 =
		"add\0""change\0""delete\0""show\0""list\0""lst\0";
	enum { ARG_add = 0, ARG_change, ARG_del, ARG_show, ARG_list, ARG_lst };

    switch (preferred_family) {
    case AF_UNSPEC:
        preferred_family = AF_INET;
        break;
    case AF_INET:
        break;
    /*
 	 * This is silly enough but we have no easy way to make it
	 * protocol-independent because of unarranged structure between
	 * IPv4 and IPv6.
	 */
    case AF_INET6:
        return do_ip6tunnel(argc, argv);
    default:
        fprintf(stderr, "Unsupported family:%d\n", preferred_family);
        exit(-1);
    }

	if (*argv) {
		smalluint key = index_in_substrings(keywords, *argv);
		if (key > 5)
			bb_error_msg_and_die(bb_msg_invalid_arg, *argv, applet_name);
		argv++;
		if (key == ARG_add) {
			return do_add(SIOCADDTUNNEL, argv);
		}
		if (key == ARG_change)
			return do_add(SIOCCHGTUNNEL, argv);
		if (key == ARG_del)
			return do_del(argv);
	}
	return do_show(argv);
}
