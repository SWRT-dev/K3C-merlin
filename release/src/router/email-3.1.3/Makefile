MAKE = make
VERSION = 3.1.3
SRCDIR = src/
DESTDIR = 
CC = mips-openwrt-linux-uclibc-gcc
CFLAGS = -I/home/paldier/asuswrt/release/src-lantiq/router/openssl/include -I/home/paldier/asuswrt/release/src-lantiq/router/nt_center/lib -I/home/paldier/asuswrt/release/src-lantiq/router/sqlite -DRTCONFIG_NOTIFICATION_CENTER -Wall -W -DUSE_GNU_STRFTIME -I/home/paldier/asuswrt/release/src-lantiq/router/email-3.1.3 -I/home/paldier/asuswrt/release/src-lantiq/router/email-3.1.3/src -I/home/paldier/asuswrt/release/src-lantiq/router/email-3.1.3/include -I../include -I/home/paldier/asuswrt/release/src-lantiq/router/email-3.1.3/dlib/include -I../dlib/include -DEMAIL_VERSION='"3.1.3"' -DCOMPILE_DATE='"10/31/2010-01:13:35PM_EDT"' -DEMAIL_DIR='"/etc/email"' -DHAVE_CONFIG_H
LDFLAGS = -L/home/paldier/asuswrt/release/src-lantiq/router/openssl -L/home/paldier/asuswrt/release/src-lantiq/router/nt_center/lib -L/home/paldier/asuswrt/release/src-lantiq/router/sqlite/.libs
LIBS =   -lm -lnt -lsqlite3 -lpthread -lcrypto -lssl 
DLIB = dlib/

prefix = /usr/local
exec_prefix = ${prefix}
bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
mandir = ${datarootdir}/man
docdir = ${datarootdir}/doc/${PACKAGE_TARNAME}
sysconfdir = /etc
datarootdir = ${prefix}/share

bin_suffix = 

.PHONY: all clean-all clean distclean install uninstall

all:
	cd $(DLIB) && $(MAKE)
	cd $(SRCDIR) && $(MAKE)

install:
	./install.sh --bindir "$(DESTDIR)$(bindir)" --sysconfdir "$(DESTDIR)$(sysconfdir)" \
		--mandir "$(DESTDIR)$(mandir)" --binext "$(bin_suffix)" --version "$(VERSION)" \
        --docdir "$(DESTDIR)$(docdir)"

distclean:
	cd $(SRCDIR) && $(MAKE) clean-all
	rm -rf Makefile config.status VERSION email.help email.1

clean:
	cd $(SRCDIR) && $(MAKE) clean
	cd $(DLIB) && $(MAKE) clean

clean-all:
	cd $(SRCDIR) && $(MAKE) clean-all
	rm -rf autom4* Makefile config.status VERSION email.help email.1 configure \
    config.log configure.in

uninstall:
	./uninstall.sh --bindir "$(DEST_DIR)$(bindir)" --sysconfdir "$(DEST_DIR)$(sysconfdir)" \
	    --mandir "$(DEST_DIR)$(mandir)" --docdir "$(DEST_DIR)$(docdir)" --version "$(VERSION)"


