include ../common.mak

all:

install:
	install -d $(INSTALLDIR)/sbin
	install -d $(INSTALLDIR)/usr/sbin
	install -d $(INSTALLDIR)/lib
	install -d $(INSTALLDIR)/usr/bin
	install -d $(INSTALLDIR)/lib/upgrade/keep.d
	install -d $(INSTALLDIR)/usr/sbin/ssr
	install -d $(INSTALLDIR)/usr/sbin/pcap-dnsproxy
	install -d $(INSTALLDIR)/usr/lib

# K3C nvram
	install -m 0700 k3cnvram.sh $(INSTALLDIR)/usr/sbin

# K3C update uboot&ubootconfig tool
	install -m 0777 mtd $(INSTALLDIR)/sbin
# K3C SSR and adbyby plus
	install -m 0777 base64 $(INSTALLDIR)/usr/bin
	install -m 0777 ssr-redir $(INSTALLDIR)/usr/bin
	install -m 0700 shadowsocksr-libev-alt $(INSTALLDIR)/lib/upgrade/keep.d
	install -m 0700 usr/ssr/gfw_addr.conf $(INSTALLDIR)/usr/sbin/ssr
	install -m 0700 usr/ssr/gfw_list.conf $(INSTALLDIR)/usr/sbin/ssr
	install -m 0700 usr/ssr/ignore.list $(INSTALLDIR)/usr/sbin/ssr
	install -m 0700 usr/ssr/ignore.user $(INSTALLDIR)/usr/sbin/ssr
	install -m 0777 usr/ssr/ssr_mon.sh $(INSTALLDIR)/usr/sbin/ssr
	install -m 0777 usr/k3c-init.sh $(INSTALLDIR)/usr/sbin
	install -m 0777 usr/k3c_ssr.sh $(INSTALLDIR)/usr/sbin
	install -m 0777 usr/phic_fac $(INSTALLDIR)/usr/sbin
# K3C dns
	install -m 0777 usr/Pcap_DNSProxy $(INSTALLDIR)/usr/sbin
	install -m 0755 usr/pcap-dnsproxy/dnsmasq.conf $(INSTALLDIR)/usr/sbin/pcap-dnsproxy
	install -m 0755 usr/pcap-dnsproxy/Config.conf $(INSTALLDIR)/usr/sbin/pcap-dnsproxy
	install -m 0755 usr/pcap-dnsproxy/Hosts.conf $(INSTALLDIR)/usr/sbin/pcap-dnsproxy
	install -m 0755 usr/pcap-dnsproxy/IPFilter.conf $(INSTALLDIR)/usr/sbin/pcap-dnsproxy
	install -m 0755 usr/pcap-dnsproxy/Routing.txt $(INSTALLDIR)/usr/sbin/pcap-dnsproxy
	install -m 0755 usr/pcap-dnsproxy/WhiteList.txt $(INSTALLDIR)/usr/sbin/pcap-dnsproxy

clean:
