/* vi: set sw=4 ts=4: */
/*
 * Rewrite by Russ Dill <Russ.Dill@asu.edu> July 2001
 *
 * Licensed under GPLv2, see file LICENSE in this tarball for details.
 */
#include "common.h"

#if defined ENABLE_FEATURE_DHCP_USER_CLASS || ENABLE_FEATURE_DEVM_DEVICE_ASSOCIATION
#include <dlfcn.h>
#endif

#if defined CONFIG_UDHCP_DEBUG && CONFIG_UDHCP_DEBUG >= 1
unsigned dhcp_verbose;
#endif

#if defined CONFIG_FEATURE_UDHCPD_BOOTP
uint8_t state[1];
#endif


const uint8_t MAC_BCAST_ADDR[6] ALIGN2 = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff
};

/* Supported options are easily added here.
 * See RFC2132 for more options.
 * OPTION_REQ: these options are requested by udhcpc (unless -o).
 */
const struct dhcp_optflag dhcp_optflags[] = {
	/* flags                                    code */
	{ OPTION_IP                   | OPTION_REQ, 0x01 }, /* DHCP_SUBNET        */
	{ OPTION_S32                              , 0x02 }, /* DHCP_TIME_OFFSET   */
	{ OPTION_IP | OPTION_LIST     | OPTION_REQ, 0x03 }, /* DHCP_ROUTER        */
//	{ OPTION_IP | OPTION_LIST                 , 0x04 }, /* DHCP_TIME_SERVER   */
//	{ OPTION_IP | OPTION_LIST                 , 0x05 }, /* DHCP_NAME_SERVER   */
	{ OPTION_IP | OPTION_LIST     | OPTION_REQ, 0x06 }, /* DHCP_DNS_SERVER    */
//	{ OPTION_IP | OPTION_LIST                 , 0x07 }, /* DHCP_LOG_SERVER    */
//	{ OPTION_IP | OPTION_LIST                 , 0x08 }, /* DHCP_COOKIE_SERVER */
	{ OPTION_IP | OPTION_LIST                 , 0x09 }, /* DHCP_LPR_SERVER    */
	{ OPTION_STRING               | OPTION_REQ, 0x0c }, /* DHCP_HOST_NAME     */
	{ OPTION_U16                              , 0x0d }, /* DHCP_BOOT_SIZE     */
	{ OPTION_STRING               | OPTION_REQ, 0x0f }, /* DHCP_DOMAIN_NAME   */
	{ OPTION_IP                               , 0x10 }, /* DHCP_SWAP_SERVER   */
	{ OPTION_STRING                           , 0x11 }, /* DHCP_ROOT_PATH     */
	{ OPTION_U8                               , 0x17 }, /* DHCP_IP_TTL        */
	{ OPTION_U16                              , 0x1a }, /* DHCP_MTU           */
	{ OPTION_IP                   | OPTION_REQ, 0x1c }, /* DHCP_BROADCAST     */
	{ OPTION_STRING                           , 0x28 }, /* DHCP_NIS_DOMAIN    */
	{ OPTION_IP | OPTION_LIST                 , 0x29 }, /* DHCP_NIS_SERVER    */
	{ OPTION_IP | OPTION_LIST     | OPTION_REQ, 0x2a }, /* DHCP_NTP_SERVER    */
	{ OPTION_IP | OPTION_LIST                 , 0x2c }, /* DHCP_WINS_SERVER   */
	{ OPTION_U32                              , 0x33 }, /* DHCP_LEASE_TIME    */
	{ OPTION_IP                               , 0x36 }, /* DHCP_SERVER_ID     */
	{ OPTION_STRING                           , 0x38 }, /* DHCP_ERR_MESSAGE   */
//TODO: must be combined with 'sname' and 'file' handling:
	{ OPTION_STRING                           , 0x42 }, /* DHCP_TFTP_SERVER_NAME */
	{ OPTION_STRING                           , 0x43 }, /* DHCP_BOOT_FILE     */
//TODO: not a string, but a set of LASCII strings:
#if ENABLE_FEATURE_DHCP_USER_CLASS
	{ OPTION_STRING                           , 0x4D }, /* DHCP_USER_CLASS    */
#else
//	{ OPTION_STRING                           , 0x4D }, /* DHCP_USER_CLASS    */
#endif
#if ENABLE_FEATURE_UDHCP_RFC3397
	{ OPTION_DNS_STRING | OPTION_LIST         , 0x77 }, /* DHCP_DOMAIN_SEARCH */
	{ OPTION_SIP_SERVERS                      , 0x78 }, /* DHCP_SIP_SERVERS   */
#endif
	{ OPTION_STATIC_ROUTES                    , 0x79 }, /* DHCP_STATIC_ROUTES */
#if ENABLE_FEATURE_UDHCP_RFC5969
	{ OPTION_6RD                              , 0xd4 }, /* DHCP_6RD           */
	{ OPTION_6RD                              , 0x96 }, /* DHCP_COMCAST_6RD   */
#endif
	{ OPTION_STRING                           , 0xfc }, /* DHCP_WPAD          */

	/* Options below have no match in dhcp_option_strings[],
	 * are not passed to dhcpc scripts, and cannot be specified
	 * with "option XXX YYY" syntax in dhcpd config file.
	 * These entries are only used internally by udhcp[cd]
	 * to correctly encode options into packets.
	 */

	{ OPTION_IP                               , 0x32 }, /* DHCP_REQUESTED_IP  */
	{ OPTION_U8                               , 0x35 }, /* DHCP_MESSAGE_TYPE  */
	{ OPTION_U16                              , 0x39 }, /* DHCP_MAX_SIZE      */
	{ OPTION_STRING                           , 0x3c }, /* DHCP_VENDOR        */
//FIXME: handling of this option is not exactly correct:
	{ OPTION_STRING                           , 0x3d }, /* DHCP_CLIENT_ID     */
	{ 0, 0 } /* zeroed terminating entry */
};

/* Used for converting options from incoming packets to env variables
 * for udhcpc stript, and for setting options for udhcpd via
 * "opt OPTION_NAME OPTION_VALUE" directives in udhcpd.conf file.
 */
/* Must match dhcp_optflags[] order */
const char dhcp_option_strings[] ALIGN1 =
	"subnet" "\0"      /* DHCP_SUBNET         */
	"timezone" "\0"    /* DHCP_TIME_OFFSET    */
	"router" "\0"      /* DHCP_ROUTER         */
//	"timesrv" "\0"     /* DHCP_TIME_SERVER    */
//	"namesrv" "\0"     /* DHCP_NAME_SERVER    */
	"dns" "\0"         /* DHCP_DNS_SERVER     */
//	"logsrv" "\0"      /* DHCP_LOG_SERVER     */
//	"cookiesrv" "\0"   /* DHCP_COOKIE_SERVER  */
	"lprsrv" "\0"      /* DHCP_LPR_SERVER     */
	"hostname" "\0"    /* DHCP_HOST_NAME      */
	"bootsize" "\0"    /* DHCP_BOOT_SIZE      */
	"domain" "\0"      /* DHCP_DOMAIN_NAME    */
	"swapsrv" "\0"     /* DHCP_SWAP_SERVER    */
	"rootpath" "\0"    /* DHCP_ROOT_PATH      */
	"ipttl" "\0"       /* DHCP_IP_TTL         */
	"mtu" "\0"         /* DHCP_MTU            */
	"broadcast" "\0"   /* DHCP_BROADCAST      */
	"nisdomain" "\0"   /* DHCP_NIS_DOMAIN     */
	"nissrv" "\0"      /* DHCP_NIS_SERVER     */
	"ntpsrv" "\0"      /* DHCP_NTP_SERVER     */
	"wins" "\0"        /* DHCP_WINS_SERVER    */
	"lease" "\0"       /* DHCP_LEASE_TIME     */
	"serverid" "\0"    /* DHCP_SERVER_ID      */
	"message" "\0"     /* DHCP_ERR_MESSAGE    */
	"tftp" "\0"        /* DHCP_TFTP_SERVER_NAME */
	"bootfile" "\0"    /* DHCP_BOOT_FILE      */
#if ENABLE_FEATURE_DHCP_USER_CLASS
	"userclass" "\0"   /* DHCP_USER_CLASS     */
#else
//	"userclass" "\0"   /* DHCP_USER_CLASS     */
#endif
#if ENABLE_FEATURE_UDHCP_RFC3397
	"search" "\0"      /* DHCP_DOMAIN_SEARCH  */
// doesn't work in udhcpd.conf since OPTION_SIP_SERVERS
// is not handled yet by "string->option" conversion code:
	"sipsrv" "\0"      /* DHCP_SIP_SERVERS    */
#endif
// doesn't work in udhcpd.conf since OPTION_STATIC_ROUTES
// is not handled yet by "string->option" conversion code:
	"staticroutes" "\0"/* DHCP_STATIC_ROUTES  */
#if ENABLE_FEATURE_UDHCP_RFC5969
	"sixrd" "\0"         /* DHCP_6RD            */
	"comcast6rd" "\0"  /* DHCP_COMCAST_6RD    */
#endif
	"wpad" "\0"        /* DHCP_WPAD           */
#if ENABLE_FEATURE_DHCP_USER_CLASS
	"requestip" "\0"	/* DHCP_REQUEST_IP	*/
	"message" "\0"		/* DHCP_MESSAGE		*/
	"maxsize" "\0"		/* DHCP_MAXSIZE		*/
	"vendorclass" "\0"	/* DHCP_VENDOR		*/
	"clientid" "\0"		/* DHCP_CLIENTID	*/
#endif
	;

/* Lengths of the option types in binary form.
 * Used by:
 * udhcp_str2optset: to determine how many bytes to allocate.
 * xmalloc_optname_optval: to estimate string length
 * from binary option length: (option[LEN] / dhcp_option_lengths[opt_type])
 * is the number of elements, multiply in by one element's string width
 * (len_of_option_as_string[opt_type]) and you know how wide string you need.
 */
const uint8_t dhcp_option_lengths[] ALIGN1 = {
	[OPTION_IP] =      4,
	[OPTION_IP_PAIR] = 8,
//	[OPTION_BOOLEAN] = 1,
	[OPTION_STRING] =  1,  /* ignored by udhcp_str2optset */
#if ENABLE_FEATURE_UDHCP_RFC3397
	[OPTION_DNS_STRING] = 1,  /* ignored by both udhcp_str2optset and xmalloc_optname_optval */
	[OPTION_SIP_SERVERS] = 1,
#endif
	[OPTION_U8] =      1,
	[OPTION_U16] =     2,
//	[OPTION_S16] =     2,
	[OPTION_U32] =     4,
	[OPTION_S32] =     4,
	/* Just like OPTION_STRING, we use minimum length here */
	[OPTION_STATIC_ROUTES] = 5,
#if ENABLE_FEATURE_UDHCP_RFC5969
	[OPTION_6RD] =    22,
#endif
};


#if defined CONFIG_UDHCP_DEBUG && CONFIG_UDHCP_DEBUG >= 2
static void log_option(const char *pfx, const uint8_t *opt)
{
	if (dhcp_verbose >= 2) {
		char buf[256 * 2 + 2];
		*bin2hex(buf, (void*) (opt + OPT_DATA), opt[OPT_LEN]) = '\0';
		bb_info_msg("%s: 0x%02x %s", pfx, opt[OPT_CODE], buf);
	}
}
#else
# define log_option(pfx, opt) ((void)0)
#endif

unsigned FAST_FUNC udhcp_option_idx(const char *name)
{
	int n = index_in_strings(dhcp_option_strings, name);
	if (n >= 0)
		return n;

	{
		char buf[sizeof(dhcp_option_strings)];
		char *d = buf;
		const char *s = dhcp_option_strings;
		while (s < dhcp_option_strings + sizeof(dhcp_option_strings) - 2) {
			*d++ = (*s == '\0' ? ' ' : *s);
			s++;
		}
		*d = '\0';
		bb_error_msg_and_die("unknown option '%s', known options: %s", name, buf);
	}
}

/* Get an option with bounds checking (warning, result is not aligned) */
uint8_t* FAST_FUNC udhcp_get_option(struct dhcp_packet *packet, int code)
{
	uint8_t *optionptr;
	int len;
	int rem;
	int overload = 0;
	enum {
		FILE_FIELD101  = FILE_FIELD  * 0x101,
		SNAME_FIELD101 = SNAME_FIELD * 0x101,
	};
#if defined CONFIG_FEATURE_UDHCPD_BOOTP
if (packet->cookie == htonl(DHCP_MAGIC)) {
#endif
	/* option bytes: [code][len][data1][data2]..[dataLEN] */
	optionptr = packet->options;
	rem = sizeof(packet->options);
	while (1) {
		if (rem <= 0) {
			bb_error_msg("bad packet, malformed option field");
			return NULL;
		}
		if (optionptr[OPT_CODE] == DHCP_PADDING) {
			rem--;
			optionptr++;
			continue;
		}
		if (optionptr[OPT_CODE] == DHCP_END) {
			if ((overload & FILE_FIELD101) == FILE_FIELD) {
				/* can use packet->file, and didn't look at it yet */
				overload |= FILE_FIELD101; /* "we looked at it" */
				optionptr = packet->file;
				rem = sizeof(packet->file);
				continue;
			}
			if ((overload & SNAME_FIELD101) == SNAME_FIELD) {
				/* can use packet->sname, and didn't look at it yet */
				overload |= SNAME_FIELD101; /* "we looked at it" */
				optionptr = packet->sname;
				rem = sizeof(packet->sname);
				continue;
			}
			break;
		}
		len = 2 + optionptr[OPT_LEN];
		rem -= len;
		if (rem < 0)
			continue; /* complain and return NULL */

		if (optionptr[OPT_CODE] == code) {
			log_option("Option found", optionptr);
			return optionptr + OPT_DATA;
		}

		if (optionptr[OPT_CODE] == DHCP_OPTION_OVERLOAD) {
			overload |= optionptr[OPT_DATA];
			/* fall through */
		}
		optionptr += len;
	}
#if defined CONFIG_FEATURE_UDHCPD_BOOTP
	}
	if (code == DHCP_MESSAGE_TYPE && packet->cookie != htonl(DHCP_MAGIC)) {
		state[0] = BOOTREQUEST;
		return state;
	}
#endif

	/* log3 because udhcpc uses it a lot - very noisy */
	log3("Option 0x%02x not found", code);
	return NULL;
}

/* Return the position of the 'end' option (no bounds checking) */
int FAST_FUNC udhcp_end_option(uint8_t *optionptr)
{
	int i = 0;

	while (optionptr[i] != DHCP_END) {
		if (optionptr[i] != DHCP_PADDING)
			i += optionptr[i + OPT_LEN] + OPT_DATA-1;
		i++;
	}
	return i;
}

/* Add an option (supplied in binary form) to the options.
 * Option format: [code][len][data1][data2]..[dataLEN]
 */
void FAST_FUNC udhcp_add_binary_option(struct dhcp_packet *packet, uint8_t *addopt)
{
	unsigned len;
	uint8_t *optionptr = packet->options;
	unsigned end = udhcp_end_option(optionptr);

	len = OPT_DATA + addopt[OPT_LEN];
	/* end position + (option code/length + addopt length) + end option */
	if (end + len + 1 >= DHCP_OPTIONS_BUFSIZE) {
//TODO: learn how to use overflow option if we exhaust packet->options[]
		bb_error_msg("option 0x%02x did not fit into the packet",
				addopt[OPT_CODE]);
		return;
	}
	log_option("Adding option", addopt);
	memcpy(optionptr + end, addopt, len);
	optionptr[end + len] = DHCP_END;
}

/* Add an one to four byte option to a packet */
void FAST_FUNC udhcp_add_simple_option(struct dhcp_packet *packet, uint8_t code, uint32_t data)
{
	const struct dhcp_optflag *dh;

	for (dh = dhcp_optflags; dh->code; dh++) {
		if (dh->code == code) {
			uint8_t option[6], len;

			option[OPT_CODE] = code;
			len = dhcp_option_lengths[dh->flags & OPTION_TYPE_MASK];
			option[OPT_LEN] = len;
			if (BB_BIG_ENDIAN)
				data <<= 8 * (4 - len);
			/* Assignment is unaligned! */
			move_to_unaligned32(&option[OPT_DATA], data);
			udhcp_add_binary_option(packet, option);
			return;
		}
	}

	bb_error_msg("can't add option 0x%02x", code);
}

/* Find option 'code' in opt_list */
struct option_set* FAST_FUNC udhcp_find_option(struct option_set *opt_list, uint8_t code)
{
	while (opt_list && opt_list->data[OPT_CODE] < code)
		opt_list = opt_list->next;

	if (opt_list && opt_list->data[OPT_CODE] == code)
		return opt_list;
	return NULL;
}

/* Parse string to IP in network order */
int FAST_FUNC udhcp_str2nip(const char *str, void *arg)
{
	len_and_sockaddr *lsa;

	lsa = host_and_af2sockaddr(str, 0, AF_INET);
	if (!lsa)
		return 0;
	*(uint32_t*)arg = lsa->u.sin.sin_addr.s_addr;
	free(lsa);
	return 1;
}

/* udhcp_str2optset:
 * Parse string option representation to binary form and add it to opt_list.
 * Called to parse "udhcpc -x OPTNAME:OPTVAL"
 * and to parse udhcpd.conf's "opt OPTNAME OPTVAL" directives.
 */
/* helper for the helper */
static char *allocate_tempopt_if_needed(
		const struct dhcp_optflag *optflag,
		char *buffer,
		int *length_p)
{
	char *allocated = NULL;
	if ((optflag->flags & OPTION_TYPE_MASK) == OPTION_BIN) {
		const char *end;
		allocated = xstrdup(buffer); /* more than enough */
		end = hex2bin(allocated, buffer, 255);
		if (errno)
			bb_error_msg_and_die("malformed hex string '%s'", buffer);
		*length_p = end - allocated;
	}
	return allocated;
}
/* helper: add an option to the opt_list */
static NOINLINE void attach_option(
		struct option_set **opt_list,
		const struct dhcp_optflag *optflag,
		char *buffer,
		int length)
{
	struct option_set *existing, *new, **curr;
	char *allocated = NULL;

	existing = udhcp_find_option(*opt_list, optflag->code);
	if (!existing) {
		log2("Attaching option %02x to list", optflag->code);
		allocated = allocate_tempopt_if_needed(optflag, buffer, &length);
#if ENABLE_FEATURE_UDHCP_RFC3397
		if ((optflag->flags & OPTION_TYPE_MASK) == OPTION_DNS_STRING) {
			/* reuse buffer and length for RFC1035-formatted string */
			allocated = buffer = (char *)dname_enc(NULL, 0, buffer, &length);
		}
#endif
		/* make a new option */
		new = xmalloc(sizeof(*new));
		new->data = xmalloc(length + OPT_DATA);
		new->data[OPT_CODE] = optflag->code;
		new->data[OPT_LEN] = length;
		memcpy(new->data + OPT_DATA, buffer, length);

		curr = opt_list;
		while (*curr && (*curr)->data[OPT_CODE] < optflag->code)
			curr = &(*curr)->next;

		new->next = *curr;
		*curr = new;
		goto ret;
	}

	if (optflag->flags & OPTION_LIST) {
		unsigned old_len;

		/* add it to an existing option */
		log2("Attaching option %02x to existing member of list", optflag->code);
		allocated = allocate_tempopt_if_needed(optflag, buffer, &length);
		old_len = existing->data[OPT_LEN];
#if ENABLE_FEATURE_UDHCP_RFC3397
		if ((optflag->flags & OPTION_TYPE_MASK) == OPTION_DNS_STRING) {
			/* reuse buffer and length for RFC1035-formatted string */
			allocated = buffer = (char *)dname_enc(existing->data + OPT_DATA, old_len, buffer, &length);
		}
#endif
		if (old_len + length < 255) {
			/* actually 255 is ok too, but adding a space can overlow it */

			existing->data = xrealloc(existing->data, OPT_DATA + 1 + old_len + length);
			if ((optflag->flags & OPTION_TYPE_MASK) == OPTION_STRING) {
				/* add space separator between STRING options in a list */
				existing->data[OPT_DATA + old_len] = ' ';
				old_len++;
			}
			memcpy(existing->data + OPT_DATA + old_len, buffer, length);
			existing->data[OPT_LEN] = old_len + length;
		} /* else, ignore the data, we could put this in a second option in the future */
	} /* else, ignore the new data */

 ret:
	free(allocated);
}

int FAST_FUNC udhcp_str2optset(const char *const_str, void *arg)
{
	struct option_set **opt_list = arg;
	char *opt, *val, *endptr;
	char *str;
	const struct dhcp_optflag *optflag;
	struct dhcp_optflag bin_optflag;
	unsigned optcode;
	int retval, length;
	char buffer[8] ALIGNED(4);
	uint16_t *result_u16 = (uint16_t *) buffer;
	uint32_t *result_u32 = (uint32_t *) buffer;

	/* Cheat, the only *const* str possible is "" */
	str = (char *) const_str;
	opt = strtok(str, " \t=");
	if (!opt)
		return 0;

	optcode = bb_strtou(opt, NULL, 0);
	if (!errno && optcode < 255) {
		/* Raw (numeric) option code */
		bin_optflag.flags = OPTION_BIN;
		bin_optflag.code = optcode;
		optflag = &bin_optflag;
	} else {
		optflag = &dhcp_optflags[udhcp_option_idx(opt)];
	}

	retval = 0;
	do {
		val = strtok(NULL, ", \t");
		if (!val)
			break;
		length = dhcp_option_lengths[optflag->flags & OPTION_TYPE_MASK];
		retval = 0;
		opt = buffer; /* new meaning for variable opt */
		switch (optflag->flags & OPTION_TYPE_MASK) {
		case OPTION_IP:
			retval = udhcp_str2nip(val, buffer);
			break;
		case OPTION_IP_PAIR:
			retval = udhcp_str2nip(val, buffer);
			val = strtok(NULL, ", \t/-");
			if (!val)
				retval = 0;
			if (retval)
				retval = udhcp_str2nip(val, buffer + 4);
			break;
		case OPTION_STRING:
#if ENABLE_FEATURE_UDHCP_RFC3397
		case OPTION_DNS_STRING:
#endif
			length = strnlen(val, 254);
			if (length > 0) {
				opt = val;
				retval = 1;
			}
			break;
//		case OPTION_BOOLEAN: {
//			static const char no_yes[] ALIGN1 = "no\0yes\0";
//			buffer[0] = retval = index_in_strings(no_yes, val);
//			retval++; /* 0 - bad; 1: "no" 2: "yes" */
//			break;
//		}
		case OPTION_U8:
			buffer[0] = strtoul(val, &endptr, 0);
			retval = (endptr[0] == '\0');
			break;
		/* htonX are macros in older libc's, using temp var
		 * in code below for safety */
		/* TODO: use bb_strtoX? */
		case OPTION_U16: {
			unsigned long tmp = strtoul(val, &endptr, 0);
			*result_u16 = htons(tmp);
			retval = (endptr[0] == '\0' /*&& tmp < 0x10000*/);
			break;
		}
//		case OPTION_S16: {
//			long tmp = strtol(val, &endptr, 0);
//			*result_u16 = htons(tmp);
//			retval = (endptr[0] == '\0');
//			break;
//		}
		case OPTION_U32: {
			unsigned long tmp = strtoul(val, &endptr, 0);
			*result_u32 = htonl(tmp);
			retval = (endptr[0] == '\0');
			break;
		}
		case OPTION_S32: {
			long tmp = strtol(val, &endptr, 0);
			*result_u32 = htonl(tmp);
			retval = (endptr[0] == '\0');
			break;
		}
		case OPTION_BIN: /* handled in attach_option() */
			opt = val;
			retval = 1;
		default:
			break;
		}
		if (retval)
			attach_option(opt_list, optflag, opt, length);
	} while (retval && optflag->flags & OPTION_LIST);

	return retval;
}

#if ENABLE_FEATURE_DHCP_USER_CLASS
/* same as udhcp_str2optset except for creation of linked list node in server via create_node()*/
/* Need a way to re-use udhcp_str2optset as it is... */

int FAST_FUNC udhcp_str2optset_server(const char *const_str, void *arg)
{
	struct option_set **opt_list = arg;
	char *opt, *val, *endptr;
	char *str;
	const struct dhcp_optflag *optflag;
	struct dhcp_optflag bin_optflag;
	unsigned optcode;
	int retval, length;
	char buffer[8] ALIGNED(4);
	uint16_t *result_u16 = (uint16_t *) buffer;
	uint32_t *result_u32 = (uint32_t *) buffer;

	/* Cheat, the only *const* str possible is "" */
	str = (char *) const_str;
	opt = strtok(str, " \t=");
	if (!opt)
		return 0;

	optcode = bb_strtou(opt, NULL, 0);
	if (!errno && optcode < 255) {
		/* Raw (numeric) option code */
		bin_optflag.flags = OPTION_BIN;
		bin_optflag.code = optcode;
		optflag = &bin_optflag;
	} else {
		optflag = &dhcp_optflags[udhcp_option_idx(opt)];
#if ENABLE_FEATURE_DHCP_USER_CLASS
		switch (optflag->code) {
		case DHCP_USER_CLASS:
		case DHCP_VENDOR:
		case DHCP_CLIENT_ID:
			create_node(optflag->code,opt_list);
			break;
		default:
			break;
		}
#endif
	}

	retval = 0;
	do {
		val = strtok(NULL, ", \t");
		if (!val)
			break;
		length = dhcp_option_lengths[optflag->flags & OPTION_TYPE_MASK];
		retval = 0;
		opt = buffer; /* new meaning for variable opt */
		switch (optflag->flags & OPTION_TYPE_MASK) {
		case OPTION_IP:
			retval = udhcp_str2nip(val, buffer);
			break;
		case OPTION_IP_PAIR:
			retval = udhcp_str2nip(val, buffer);
			val = strtok(NULL, ", \t/-");
			if (!val)
				retval = 0;
			if (retval)
				retval = udhcp_str2nip(val, buffer + 4);
			break;
		case OPTION_STRING:
#if ENABLE_FEATURE_UDHCP_RFC3397
		case OPTION_DNS_STRING:
#endif
			length = strnlen(val, 254);
			if (length > 0) {
				opt = val;
				retval = 1;
			}
			break;
//		case OPTION_BOOLEAN: {
//			static const char no_yes[] ALIGN1 = "no\0yes\0";
//			buffer[0] = retval = index_in_strings(no_yes, val);
//			retval++; /* 0 - bad; 1: "no" 2: "yes" */
//			break;
//		}
		case OPTION_U8:
			buffer[0] = strtoul(val, &endptr, 0);
			retval = (endptr[0] == '\0');
			break;
		/* htonX are macros in older libc's, using temp var
		 * in code below for safety */
		/* TODO: use bb_strtoX? */
		case OPTION_U16: {
			unsigned long tmp = strtoul(val, &endptr, 0);
			*result_u16 = htons(tmp);
			retval = (endptr[0] == '\0' /*&& tmp < 0x10000*/);
			break;
		}
//		case OPTION_S16: {
//			long tmp = strtol(val, &endptr, 0);
//			*result_u16 = htons(tmp);
//			retval = (endptr[0] == '\0');
//			break;
//		}
		case OPTION_U32: {
			unsigned long tmp = strtoul(val, &endptr, 0);
			*result_u32 = htonl(tmp);
			retval = (endptr[0] == '\0');
			break;
		}
		case OPTION_S32: {
			long tmp = strtol(val, &endptr, 0);
			*result_u32 = htonl(tmp);
			retval = (endptr[0] == '\0');
			break;
		}
		case OPTION_BIN: /* handled in attach_option() */
			opt = val;
			retval = 1;
		default:
			break;
		}
		if (retval)
			attach_option(opt_list, optflag, opt, length);
	} while (retval && optflag->flags & OPTION_LIST);

	return retval;
}
#endif

#if ENABLE_FEATURE_DHCP_TR111_DEVICE_ASSOCIATION
/*

This function takes pointer to the first enterprise no of the vendor specific options

    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |  option-code  |  option-len   |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |      enterprise-number1       |
   |                               |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |   data-len1   |               |
   +-+-+-+-+-+-+-+-+ option-data1  |
   /                               /
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ ----
   |      enterprise-number2       |   ^
   |                               |   |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+   |
   |   data-len2   |               | optional
   +-+-+-+-+-+-+-+-+ option-data2  |   |
   /                               /   |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+   |
   ~            ...                ~   V
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+ ----

And then returns the pointer to Vendor specific info for the specified Enterprise number.
If the info relatedd to enterprise no is not present, then NULL is returned.


pVSO : ponter to the first enterprise no field below the VSI.
iEnterpriseNo : is the enterprise no of interest
option_len : is the length of the buffer pointer to by pVSO as mentioned in the option-len of VSI.

*/

uint8_t *get_vsi_option(uint8_t *pVSO, uint32_t iEnterpriseNo, uint8_t option_len)
{
	int i, length;
	uint8_t *optionptr=NULL;
	uint32_t *pEntNo = NULL;
	int done=0;

	return pVSO;

	log1( " GET_VSI_OPTION  called\n");
	optionptr = pVSO;
	i = 0;
	length = option_len;
	while (!done) {
		if (i >= length) {
			log1("bogus packet, option fields too long.");
			return NULL;
		}

		pEntNo = (uint32_t *)(optionptr +i);

		if (*pEntNo == iEnterpriseNo) {
			if (i + OPT_VSI_ENTPNO_LEN + optionptr[i + OPT_VSI_ENTPNO_LEN] >= length) {
				log1("bogus packet, option fields too long.");
				return NULL;
			}
			return optionptr + i + OPT_VSI_ENTPNO_LEN;
		}else{
			i += OPT_VSI_ENTPNO_LEN + optionptr[i + OPT_VSI_ENTPNO_LEN];

		}
	}
	log1( " GET_VSI_OPTION  over\n");
	return NULL;
}

/*
This function takes pointer to Vendor Specific info below the identified enterprise no.

   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |   data-len1   |               |
   +-+-+-+-+-+-+-+-+ option-data   |
   /                               /
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

Where option-data is a collection of sub-options each with the format

   0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |  subopt-code  |  subopt-len   |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   /        sub-option-data        /
   /                               /
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

And fills the string in the form
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-
   / sub-option-data1\0suboption-data2\0suboption-data3\0 /
   /                               						  /
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-++-+-+-+-+-+-+-+-+-+-+-+


RETURN VALUES :
	SUCCESS 	string length for output
	FAILURE		-1

*/


int form_vsi_string(uint8_t *pVSD,char *string)
{
	int i;
	uint8_t *optionptr=NULL;
	uint8_t data_len, option_len;
	uint8_t string_len = 0;

	optionptr = pVSD;
	data_len = optionptr[0];
	optionptr++;
	i = 0;

	log1( " FORM_VSI_STRING called\n");
	while ( i < data_len)
	{
#ifdef CONFIG_FEATURE_DEVM_DEVICE
		if(( optionptr[i + SUBOPT_CODE] < 0x04) || ( optionptr[i + SUBOPT_CODE] > 0x06)){
			log1("bogus packet, invalid sub-option code from device");
			return -1; //failure
		}
#else
		if(( optionptr[i + SUBOPT_CODE] < 0x01) || ( optionptr[i + SUBOPT_CODE] > 0x03)){
			log1("bogus packet, invalid sub-option code from device");
			return -1; //failure
		}
#endif

		option_len = optionptr[i + SUBOPT_LEN];

		if( i + 1 +  option_len > data_len) {
				log1("bogus packet, option fields too long.");
				return -1 ; // failure
		}

		log1( " FORM_VSI_STRING : copying option to be sent\n");
		memcpy(string+ string_len,optionptr + i + SUBOPT_DATA, option_len);

		i += 1 + 1 + option_len; // move the offset to next VSD
		string_len = string_len + option_len;	// update the total string size
		*(string + string_len)= '\0'; //add a null in the end of thie string
		string_len++;
	}


	log1( " FORM_VSI_STRING done\n");
	return string_len-1; //success
}
#endif

/******************************************************************
This function posts a message with appropriats options and
null string when the entry for Gateway or Device is to be removed
Function used by :
DEVICE to write empty string for gateway, ipaddr = 0
GATEWAY to delete the ipaddr of a device whose lease has expired
*******************************************************************/
int writenullmsg(uint32_t iIpaddr){
	int iRetrn = 0;
#if CONFIG_PACKAGE_LTQ_DEVM
	iRetrn = writemsg( TR69_FIFO, NULL, 2,iIpaddr, IFX_IPC_APP_ID_DHCPD);
#endif
	return iRetrn;
}






#if CONFIG_PACKAGE_LTQ_DEVM
/************************************************************
This function writes a message to file.
The structure of the message is

   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |   data-len    |               |
   +-+-+-+-+-+-+-+-+      data     |
   /                               /
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


************************************************************/

/********************************************************************************************
The operation defined are :
 1	Add	Add the information in the table (requires add object and write of parameters
 2	Del 	GATEWAY :Delete the information from the table (required delete of object)
		DEVICE : Clear GatewayInfo

The operation to be done is also reflected in the Reserved field of the message
The data of the message sent is only needed in ADD
For a delete or write only the ipaddr matters
********************************************************************************************/
int writemsg(char *file, uint8_t *msg, uint8_t operation, uint32_t ipaddr, uint8_t inFrom)
{
	int iFd, iRet;
	x_IFX_IPC_Msg xMsg = {0};
	char string[380] = {'\0'};
	uint16_t string_len = 0;

	log1( " WRITEMSG CALLED\n");
	memset(&xMsg, 0, sizeof(x_IFX_IPC_Msg));
#if 0
	if((operation == 1)&&(msg == NULL))
		return -1; //error
#endif

	xMsg.xHdr.ucFrom = inFrom;
	xMsg.xHdr.ucTo = operation;
	xMsg.xHdr.uiReserved = htonl(ipaddr);

#ifndef CONFIG_FEATURE_DHCP_TR69_HOSTS_OBJ
	// data is meaningful only in add
	if(operation == 1)
	{
		log1( " WRITEMSG : FORM STRING TO BE POSTED \n");

		if(inFrom == IFX_IPC_APP_ID_DHCPD){
			string_len =  form_vsi_string(msg+4, string);
		}
		else{
			string_len = strlen(msg);
			memcpy(string, (void *)msg+2, (string_len-2));
			string[(string_len-3)]='\0';
			string_len=strlen(string);
		}
		if(string_len < 0){
			log1( "Failure in forminmg string data");
			return -1;
		}

		xMsg.xHdr.unMsgSize =  htons(string_len);
		memcpy(xMsg.acMsg, (void *)string, string_len);
	}
#else
	// data is meaningful only in add
	if((operation == 1) && (inFrom == IFX_IPC_APP_ID_DHCPD))
	{
		log1( " WRITEMSG : FORM STRING TO BE POSTED \n");
		if(msg != NULL)
		{
			string_len =  form_vsi_string(msg+4, string);
			if(string_len < 0)
			{
				log1( "Failure in forminmg string data");
				return -1;
			}
			xMsg.xHdr.unMsgSize =  htons(string_len);
			memcpy(xMsg.acMsg, (void *)string, string_len);
		}
	}
#endif

	iFd = open(file,O_WRONLY | O_NONBLOCK);
	log1( " WRITEMSG : FIFO OPENED WITH FD : %d \n", iFd);
	if(iFd > -1 ){  	//now post this msg to TR69 stack
		iRet = write( iFd,(void *)&xMsg, string_len + IFX_IPC_HDR_SIZE);
		close(iFd);
		if(iRet <=0){
			log1( "Failure in writing data");
			return -1;
		}
		log1( " WRITEMSG DONE \n");
	}
	return iRet;
}
#endif

#if ENABLE_FEATURE_DHCP_TR111_DEVICE_ASSOCIATION
/* This function initializes the variables to be used in TR-111 option 125
*/
char subopt1[IFX_DEVM_DHCP_PARAM_SIZE];
char subopt2[IFX_DEVM_DHCP_PARAM_SIZE];
char subopt3[IFX_DEVM_DHCP_PARAM_SIZE];
char subopt4[IFX_DEVM_DHCP_PARAM_SIZE];
char subopt5[IFX_DEVM_DHCP_PARAM_SIZE];
char subopt6[IFX_DEVM_DHCP_PARAM_SIZE];

void ifx_init_tr111_vars()
{
	char* mac_addr = NULL;
	char*  serial_num = NULL;
	char sValue[IFX_DEVM_DHCP_PARAM_SIZE] = {0};
	void *dlHandle = NULL, *dlHandle2 = NULL;
	int (*func_ptr)(const char *, const char *, char *, char *) = NULL;
	char* (*pupgrade_uAPI)(UPGRADE_OPT, char*) = NULL;
	char *error = NULL;
	char sVal[MAX_FILELINE_LEN]={0};
	int iFD=-1;
	char caBuff[32] = { 0 };
	char *psTmp = NULL;


	dlHandle = dlopen("libifx_common.so",RTLD_LAZY);
	dlHandle2 = dlopen("libltq_utilAPIs.so",RTLD_LAZY);
	if(dlHandle && dlHandle2) {
		*(void **) &func_ptr = dlsym(dlHandle,"ifx_GetCfgData");
		if((error = dlerror()) != NULL) {
			log1( "could not find function ifx_GetCfgData in libifx_common.so\n");
			log1( "dlopen failed !! taking backup values \n");
			goto BACKUP;
		}
		pupgrade_uAPI = dlsym(dlHandle2,"upgrade_uAPI");
		if ((error = dlerror()) != NULL)  {
			log1( "could not find function upgrade_uAPI in libltq_utilAPIs.so\n");
			log1( "dlopen failed !! taking backup values \n");
			goto BACKUP;
		}


		if ( (int)(* func_ptr)(IFX_SYS_CONF, IFX_DEVICE_INFO_SECTION, "device_info_oui", sValue) == 1){

			// frame the OUI from the MAC address - logic picked from IFXAPIs/src/mapi/ifx_api_dev_info.c:130
			memset(sVal, 0x00, sizeof(sVal));
			mac_addr = pupgrade_uAPI(MAC_GET, NULL);
			if(!mac_addr)
			{
				bb_error_msg("unable to retrive mac_address\n");
				return -1;
			}
			strncpy(caBuff, mac_addr, sizeof(caBuff)-1);
			free(mac_addr);
			
			psTmp = strtok(caBuff, ":");
			if(psTmp == NULL)
			{
				bb_error_msg("Unable to parse version /tmp/macget\n");
				return -1;
			}
			strcpy(sVal, psTmp);
			psTmp = strtok(NULL, ":");
			strcat(sVal, psTmp);
			psTmp = strtok(NULL, ":");
			strcat(sVal, psTmp);
			close(iFD);
			if ((strlen(sVal) + 1) > IFX_DEVM_DHCP_PARAM_SIZE)
			{
				goto BACKUP;
			}
			strcpy(sValue, sVal);

#ifdef CONFIG_FEATURE_DEVM_DEVICE 	//  it is a device
			strcpy(subopt1,sValue);
#else	// it is a gateway
			strcpy(subopt4,sValue);
#endif
		}else{
			goto BACKUP;
		}
		
		iFD = -1;
		memset(sVal, '\0', sizeof(sVal));
		memset(caBuff, 0x00, sizeof(caBuff));
		
		serial_num = pupgrade_uAPI(SERNUM_GET, NULL);
		if(!serial_num)
			goto BACKUP;
		
		strncpy(sVal, serial_num, 18);
		free(serial_num);
        if(strlen(sVal)) {
#ifdef CONFIG_FEATURE_DEVM_DEVICE 	//  it is a device
			strcpy(subopt2,sVal);
#else	// it is a gateway
			strcpy(subopt5,sVal);
#endif
		} else {
			goto BACKUP;
		}

		if ( (int)(* func_ptr)(IFX_SYS_CONF, IFX_DEVICE_INFO_SECTION, "device_info_prodclass", sValue) == 1){
#ifdef CONFIG_FEATURE_DEVM_DEVICE 	//  it is a device
			strcpy(subopt3,sValue);
#else	// it is a gateway
			strcpy(subopt6,sValue);
#endif
		}else{
			goto BACKUP;
		}

	}
	else
	{
		log1( "dlopen failed !! taking backup values \n");
BACKUP :
#ifdef CONFIG_FEATURE_DEVM_DEVICE 	//  it is a device
		strcpy(subopt1,"001212");
		strcpy(subopt2,"DMA67");
		strcpy(subopt3,"DEVICE");
#else	// it is a gateway
		strcpy(subopt4,"011111");
		strcpy(subopt5,"112233");
		strcpy(subopt6,"GATEWAY");
#endif

	}

	dlclose(dlHandle);
	dlclose(dlHandle2);
	return;
}
#endif
