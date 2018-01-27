# Generated automatically from Makefile.in by configure.
# Generated automatically from Makefile.in by configure.
#***********************************************************************
#
# Makefile
#
# Makefile for L2TP code.
#
# Copyright (C) 2002 Roaring Penguin Software Inc.
#
# This software may be distributed under the terms of the GNU General
# Public License, Version 2, or (at your option) any later version.
#
# LIC: GPL
#
# $Id: Makefile.in 3323 2011-09-21 18:45:48Z lly.dev $
#***********************************************************************

VERSION=0.5-rtn

DEFINES=
prefix=/usr
exec_prefix=${prefix}
mandir=${prefix}/man
docdir=/usr/doc/l2tp-$(VERSION)
install=/usr/bin/install -c
install_dir=/usr/bin/install -c -d
sbindir=${exec_prefix}/sbin
sysconfdir=/tmp

OBJS=auth.o debug.o dgram.o main.o md5.o network.o options.o peer.o session.o tunnel.o utils.o
EXTRA_LIBS=libevent/*.o -ldl

SRCS=$(OBJS:.o=.c)
CFLAGS=-O2 -Wall -DCONFIG_LANTIQ -DDEBUG_NOISY -DDEBUG_RCTEST -pipe -funit-at-a-time -Wno-pointer-sign -mips32r2 -mno-branch-likely -mtune=1004kc -DLINUX30 -DLINUX26 -DLINUX_KERNEL_VERSION=199272 --sysroot=/home/paldier/asuswrt/release/src-lantiq/tools/toolchain-mips_mips32_gcc-4.8-linaro_uClibc-0.9.33.2 -idirafter /home/paldier/asuswrt/release/src-lantiq/router/kernel_header/include  -DRTCONFIG_VPNC -I.. -Ilibevent -Wall -Wstrict-prototypes -ansi -pedantic -D_GNU_SOURCE -DVERSION=\"$(VERSION)\" -DPREFIX=\"$(prefix)\" -DSYSCONFDIR=\"$(sysconfdir)\"

TARGETS=l2tpd libl2tp.a handlers

all: $(TARGETS)

libl2tp.a: $(OBJS)
	rm -f $@
	mips-openwrt-linux-uclibc-ar -rc $@ $^
	mips-openwrt-linux-uclibc-ranlib $@ || true

l2tpd: libl2tp.a libevent/libevent.a
	$(MAKE) -C handlers
	mips-openwrt-linux-uclibc-gcc -o l2tpd -rdynamic $(OBJS) $(EXTRA_LIBS)

libevent/libevent.a:
	test -d libevent || ln -s ../libevent .
	$(MAKE) -C libevent

%.o: %.c
	mips-openwrt-linux-uclibc-gcc -c -o $@ $(CFLAGS) $<

depend: .depend

.depend: $(SRCS)
	mips-openwrt-linux-uclibc-gcc -M $(CFLAGS) $^ > .depend

handlers:
	$(MAKE) -C handlers

# Release requires GNU tar!!
release: FORCE
	rm -f rp-l2tp-$(VERSION).tar.gz
	make -C libevent/Doc
	./make-release.sh $(VERSION)
	tar cvhf rp-l2tp-$(VERSION).tar rp-l2tp-$(VERSION)
	gzip -v -9 rp-l2tp-$(VERSION).tar

clean:
	rm -f .depend
	rm -f *.o *.a *~
	rm -f l2tpd
	$(MAKE) -C handlers clean
	test -d libevent && $(MAKE) -C libevent clean

distclean: clean
	rm -f Makefile config.cache
	$(MAKE) -C handlers distclean
	test -d libevent && $(MAKE) -C libevent distclean

-include .depend

install: all
	-mkdir -p $(RPM_INSTALL_ROOT)$(DESTDIR)$(sbindir)
	$(install) -m 755 -s l2tpd $(RPM_INSTALL_ROOT)$(DESTDIR)$(sbindir)
	-mkdir -p $(RPM_INSTALL_ROOT)$(DESTDIR)$(sysconfdir)/l2tp
	$(install) -m 644 l2tp.conf $(RPM_INSTALL_ROOT)$(DESTDIR)$(sysconfdir)/l2tp/l2tp.conf.example
	-mkdir -p $(RPM_INSTALL_ROOT)$(DESTDIR)$(mandir)/man8
	-mkdir -p $(RPM_INSTALL_ROOT)$(DESTDIR)$(mandir)/man5
	$(install) -m 644 man/l2tpd.8 $(RPM_INSTALL_ROOT)$(DESTDIR)$(mandir)/man8
	$(install) -m 644 man/l2tp.conf.5 $(RPM_INSTALL_ROOT)$(DESTDIR)$(mandir)/man5

	$(MAKE) -C handlers install

FORCE:

.PHONY: handlers

.PHONY: FORCE
