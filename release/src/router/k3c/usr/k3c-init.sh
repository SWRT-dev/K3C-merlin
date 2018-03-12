#!/bin/sh 

#fix ipset didnt insmod bug
insmod nfnetlink
insmod ip_set
insmod ip_set_bitmap_ip
insmod /lib/modules/3.10.104/ip_set_bitmap_ipmac.ko
insmod /lib/modules/3.10.104/ip_set_bitmap_port.ko
insmod /lib/modules/3.10.104/ip_set_hash_ip.ko
insmod /lib/modules/3.10.104/ip_set_hash_ipport.ko
insmod /lib/modules/3.10.104/ip_set_hash_ipportip.ko
insmod /lib/modules/3.10.104/ip_set_hash_ipportnet.ko
insmod /lib/modules/3.10.104/ip_set_hash_net.ko
insmod /lib/modules/3.10.104/ip_set_hash_netiface.ko
insmod /lib/modules/3.10.104/ip_set_hash_netport.ko
insmod /lib/modules/3.10.104/ip_set_list_set.ko
insmod /lib/modules/3.10.104/xt_set.ko
