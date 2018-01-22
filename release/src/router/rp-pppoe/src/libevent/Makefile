# Generated automatically from Makefile.in by configure.
# $Id$
#
# Makefile for event-handling library
#
# Copyright 2002 Roaring Penguin Software Inc.
#
# This software may be distributed according to the terms of the GNU
# General Public License, version 2 or (at your option) any later version.
# LIC: GPL

OBJS=event.o event_tcp.o hash.o event_sig.o
SRCS=$(OBJS:.o=.c)
HDRS=event.h event_tcp.h eventpriv.h hash.h
CFLAGS=-g -O2 -DCONFIG_LANTIQ -DDEBUG_NOISY -DDEBUG_RCTEST -pipe -funit-at-a-time -Wno-pointer-sign -mips32r2 -mno-branch-likely -mtune=1004kc -DLINUX30 -DLINUX26 -DLINUX_KERNEL_VERSION=199272 --sysroot=/home/paldier/asuswrt/release/src-lantiq/tools/toolchain-mips_mips32_gcc-4.8-linaro_uClibc-0.9.33.2 -idirafter /home/paldier/asuswrt/release/src-lantiq/router/kernel_header/include -fno-strict-aliasing -Wall -Wstrict-prototypes -I.. $(DEFINES)
AR=ar

all: libevent.a

libevent.a: $(OBJS)
	rm -f libevent.a
	$(AR) -cq libevent.a $(OBJS)
	mips-openwrt-linux-uclibc-ranlib libevent.a

event.o: event.c $(HDRS)
	mips-openwrt-linux-uclibc-gcc $(CFLAGS) -c -o $@ $<

hash.o: hash.c $(HDRS)
	mips-openwrt-linux-uclibc-gcc $(CFLAGS) -c -o $@ $<

event_sig.o: event_sig.c $(HDRS)
	mips-openwrt-linux-uclibc-gcc $(CFLAGS) -c -o $@ $<

event_tcp.o: event_tcp.c $(HDRS)
	mips-openwrt-linux-uclibc-gcc $(CFLAGS) -c -o $@ $<

clean: FORCE
	rm -f *.a *.o *~

FORCE:

.phony: FORCE
