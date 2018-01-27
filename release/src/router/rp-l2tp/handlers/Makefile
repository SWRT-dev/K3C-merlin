# Generated automatically from Makefile.in by configure.
# $Id: Makefile.in 3323 2011-09-21 18:45:48Z lly.dev $
# Makefile for LNS handlers
# LIC: GPL

prefix=/usr
exec_prefix=${prefix}
mandir=${prefix}/man
docdir=/usr/doc/l2tp-$(VERSION)
install=/usr/bin/install -c
install_dir=/usr/bin/install -c -d
sbindir=${exec_prefix}/sbin

HANDLERS=sync-pppd.so cmd.so

OBJS=pty.o sync-pppd.o dstring.o
SRCS=$(OBJS:.o=.c)
CFLAGS=-O2 -Wall -DCONFIG_LANTIQ -DDEBUG_NOISY -DDEBUG_RCTEST -pipe -funit-at-a-time -Wno-pointer-sign -mips32r2 -mno-branch-likely -mtune=1004kc -DLINUX30 -DLINUX26 -DLINUX_KERNEL_VERSION=199272 --sysroot=/home/paldier/asuswrt/release/src-lantiq/tools/toolchain-mips_mips32_gcc-4.8-linaro_uClibc-0.9.33.2 -idirafter /home/paldier/asuswrt/release/src-lantiq/router/kernel_header/include  -DRTCONFIG_VPNC -I.. -I../libevent -I. -Wall

all: $(HANDLERS) l2tp-control

l2tp-control: cmd-control.o
	mips-openwrt-linux-uclibc-gcc -o l2tp-control cmd-control.o

cmd-control.o: cmd-control.c
	mips-openwrt-linux-uclibc-gcc $(CFLAGS) -c -o $@ $^

%.o: %.c
	mips-openwrt-linux-uclibc-gcc $(CFLAGS) -fPIC -c -o $@ $<

sync-pppd.so: pty.o sync-pppd.o
	mips-openwrt-linux-uclibc-gcc -shared -o $@ $^

cmd.so: cmd.o dstring.o
	mips-openwrt-linux-uclibc-gcc -shared -o $@ $^

clean:
	rm -f *.so *.o *~
	rm -f l2tp-control

install: all
	-mkdir -p $(RPM_INSTALL_ROOT)$(sbindir)
	-mkdir -p $(RPM_INSTALL_ROOT)$(prefix)/lib/l2tp/plugins
	$(install) -m 755 -s l2tp-control $(RPM_INSTALL_ROOT)$(sbindir)
	$(install) -m 755 $(HANDLERS) $(RPM_INSTALL_ROOT)$(prefix)/lib/l2tp/plugins

distclean: clean
	rm -f Makefile
