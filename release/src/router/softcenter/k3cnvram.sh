#!/bin/sh

echo '#!/bin/sh' > /tmp/nv.sh
echo 'nvram set et0macaddr=`uboot_env --get --name ethaddr`' >> /tmp/nv.sh
echo 'nvram set boardnum=`uboot_env --get --name ethaddr`' >> /tmp/nv.sh
echo 'nvram set lan_hwaddr=`uboot_env --get --name ethaddr`' >> /tmp/nv.sh
echo 'nvram set wl_hwaddr=`uboot_env --get --name ethaddr`' >> /tmp/nv.sh
echo 'nvram set bl_ver=`uboot_env --get --name ver`' >> /tmp/nv.sh
echo 'nvram commit' >> /tmp/nv.sh
chmod +x /tmp/nv.sh
