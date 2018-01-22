MAKE = make
VERSION = @VERSION@
SRCDIR = .
CC = mips-openwrt-linux-uclibc-gcc
CFLAGS = -I/home/paldier/asuswrt/release/src-lantiq/router/openssl/include -I/home/paldier/asuswrt/release/src-lantiq/router/nt_center/lib -I/home/paldier/asuswrt/release/src-lantiq/router/sqlite -DRTCONFIG_NOTIFICATION_CENTER -Wall -W -DUSE_GNU_STRFTIME -I/home/paldier/asuswrt/release/src-lantiq/router/email-3.1.3 -I/home/paldier/asuswrt/release/src-lantiq/router/email-3.1.3/src -I/home/paldier/asuswrt/release/src-lantiq/router/email-3.1.3/include -I../include -I/home/paldier/asuswrt/release/src-lantiq/router/email-3.1.3/dlib/include -I../dlib/include -DEMAIL_VERSION='"3.1.3"' -DCOMPILE_DATE='"10/31/2010-01:13:35PM_EDT"' -DEMAIL_DIR='"/etc/email"' -DHAVE_CONFIG_H
LDFLAGS = -L/home/paldier/asuswrt/release/src-lantiq/router/openssl -L/home/paldier/asuswrt/release/src-lantiq/router/nt_center/lib -L/home/paldier/asuswrt/release/src-lantiq/router/sqlite/.libs
LIBS =   -lm -lnt -lsqlite3 -lpthread -lcrypto -lssl 
DLIB = ../dlib/libdlib.a

prefix = /usr/local
bindir = ${exec_prefix}/bin
sbindir = ${exec_prefix}/sbin
mandir = ${datarootdir}/man
sysconfdir = /etc
datarootdir = ${prefix}/share

FILES = email.o addr_parse.o addy_book.o conf.o error.o execgpg.o file_io.o \
        message.o mimeutils.o processmail.o progress_bar.o \
	remotesmtp.o sig_file.o smtpcommands.o utils.o

all: $(FILES)
	$(CC) $(CFLAGS) -o email $(FILES) $(OTHER_FILES) $(DLIB) $(LDFLAGS) $(LIBS)

clean:
	rm -f *.o *.d email

clean-all:
	rm -rf Makefile *.o *.d email

