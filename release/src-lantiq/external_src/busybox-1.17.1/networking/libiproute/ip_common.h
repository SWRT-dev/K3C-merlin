/* vi: set sw=4 ts=4: */
#ifndef IP_COMMON_H
#define IP_COMMON_H 1

#include "libbb.h"
#include <asm/types.h>
#include <linux/netlink.h>
#include <linux/rtnetlink.h>
#if !defined IFA_RTA
#include <linux/if_addr.h>
#endif
#if !defined IFLA_RTA
#include <linux/if_link.h>
#endif

PUSH_AND_SET_FUNCTION_VISIBILITY_TO_HIDDEN

extern char **ip_parse_common_args(int *argc, char **argv);
extern int print_neigh(const struct sockaddr_nl *who, struct nlmsghdr *n, void *arg);
extern int ipaddr_list_or_flush(char **argv, int flush);
extern int iproute_monitor(char **argv);
extern void iplink_usage(void) NORETURN;
extern void ipneigh_reset_filter(void);

extern int do_ipaddr(int argc, char **argv);
extern int do_iproute(int argc, char **argv);
extern int do_iprule(int argc, char **argv);
extern int do_ipneigh(int argc, char **argv);
extern int do_iptunnel(int argc, char **argv);
extern int do_iplink(char **argv);
extern int do_ipmonitor(char **argv);
extern int do_multiaddr(char **argv);
extern int do_multiroute(char **argv);

POP_SAVED_FUNCTION_VISIBILITY

#endif
