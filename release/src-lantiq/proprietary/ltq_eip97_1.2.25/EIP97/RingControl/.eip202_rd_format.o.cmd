cmd_drivers/crypto/lantiq_eip97/Sources/EIP97/RingControl/eip202_rd_format.o := mips-openwrt-linux-uclibc-gcc -Wp,-MD,drivers/crypto/lantiq_eip97/Sources/EIP97/RingControl/.eip202_rd_format.o.d  -nostdinc -isystem /home/paldier/asuswrt/release/src-lantiq/tools/toolchain-mips_mips32_gcc-4.8-linaro_uClibc-0.9.33.2/bin/../lib/gcc/mips-openwrt-linux-uclibc/4.8.3/include -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include -Iarch/mips/include/generated  -Iinclude -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/uapi -Iarch/mips/include/generated/uapi -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/include/uapi -Iinclude/generated/uapi -include /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/include/linux/kconfig.h -D__KERNEL__ -DVMLINUX_LOAD_ADDRESS=0xffffffff60020000 -DDATAOFFSET=0 -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -std=gnu89 -O2 -fno-reorder-blocks -fno-tree-ch -mno-check-zero-division -mabi=32 -G 0 -mno-abicalls -fno-pic -pipe -mno-branch-likely -msoft-float -ffreestanding -march=mips32r2 -Wa,-mips32r2 -Wa,--trap -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-lantiq -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-lantiq/grx500 -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-generic -Wframe-larger-than=1024 -fno-stack-protector -Wno-unused-but-set-variable -fomit-frame-pointer -fno-var-tracking-assignments -g -femit-struct-debug-baseonly -fno-var-tracking -fno-inline-functions-called-once -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO -Idrivers/crypto/lantiq_eip97/Sources/incl -Idrivers/crypto/lantiq_eip97/Sources/DriverFramework -Idrivers/crypto/lantiq_eip97/Sources/EIP201 -Idrivers/crypto/lantiq_eip97/Sources/EIP97/GlobalControl -Idrivers/crypto/lantiq_eip97/Sources/EIP97/RingControl -Idrivers/crypto/lantiq_eip97/Sources/RingHelper -Idrivers/crypto/lantiq_eip97/Sources/SABuilder -Idrivers/crypto/lantiq_eip97/Sources/TokenBuilder -Idrivers/crypto/lantiq_eip97/Sources/Log   -ffunction-sections -fdata-sections  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(eip202_rd_format)"  -D"KBUILD_MODNAME=KBUILD_STR(ltq_crypto)" -c -o drivers/crypto/lantiq_eip97/Sources/EIP97/RingControl/eip202_rd_format.o drivers/crypto/lantiq_eip97/Sources/EIP97/RingControl/eip202_rd_format.c

source_drivers/crypto/lantiq_eip97/Sources/EIP97/RingControl/eip202_rd_format.o := drivers/crypto/lantiq_eip97/Sources/EIP97/RingControl/eip202_rd_format.c

deps_drivers/crypto/lantiq_eip97/Sources/EIP97/RingControl/eip202_rd_format.o := \
  drivers/crypto/lantiq_eip97/Sources/EIP97/RingControl/eip202_rd_format.h \
  drivers/crypto/lantiq_eip97/Sources/EIP97/RingControl/eip202_rdr.h \
  drivers/crypto/lantiq_eip97/Sources/EIP97/RingControl/c_eip202_ring.h \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_eip202_ring.h \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_driver.h \
    $(wildcard include/config/cnn.h) \
    $(wildcard include/config/ltq/crypto/max/ring/used.h) \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_systemtestconfig.h \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_driver_ext.h \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_driver_ext2.h \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/basic_defs.h \
  include/linux/types.h \
    $(wildcard include/config/have/uid16.h) \
    $(wildcard include/config/uid16.h) \
    $(wildcard include/config/lbdaf.h) \
    $(wildcard include/config/arch/dma/addr/t/64bit.h) \
    $(wildcard include/config/phys/addr/t/64bit.h) \
    $(wildcard include/config/64bit.h) \
  include/uapi/linux/types.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/types.h \
    $(wildcard include/config/64bit/phys/addr.h) \
  include/asm-generic/int-ll64.h \
  include/uapi/asm-generic/int-ll64.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/uapi/asm/bitsperlong.h \
  include/asm-generic/bitsperlong.h \
  include/uapi/asm-generic/bitsperlong.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/uapi/asm/types.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/include/uapi/linux/posix_types.h \
  include/linux/stddef.h \
  include/uapi/linux/stddef.h \
  include/linux/compiler.h \
    $(wildcard include/config/sparse/rcu/pointer.h) \
    $(wildcard include/config/trace/branch/profiling.h) \
    $(wildcard include/config/profile/all/branches.h) \
    $(wildcard include/config/enable/must/check.h) \
    $(wildcard include/config/enable/warn/deprecated.h) \
    $(wildcard include/config/kprobes.h) \
  include/linux/compiler-gcc.h \
    $(wildcard include/config/arch/supports/optimized/inlining.h) \
    $(wildcard include/config/optimize/inlining.h) \
    $(wildcard include/config/gcov/kernel.h) \
    $(wildcard include/config/arch/use/builtin/bswap.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/uapi/asm/posix_types.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/uapi/asm/sgidefs.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/include/uapi/asm-generic/posix_types.h \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/device_types.h \
  drivers/crypto/lantiq_eip97/Sources/EIP97/RingControl/eip202_ring_types.h \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_types.h \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/basic_defs.h \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_record.h \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_adapter.h \
    $(wildcard include/config/cachelinesize.h) \
    $(wildcard include/config/masterlatencytimer.h) \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_adapter_ext.h \
  drivers/crypto/lantiq_eip97/Sources/EIP97/RingControl/eip202_ring_internal.h \
  drivers/crypto/lantiq_eip97/Sources/RingHelper/ringhelper.h \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_rw.h \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_types.h \

drivers/crypto/lantiq_eip97/Sources/EIP97/RingControl/eip202_rd_format.o: $(deps_drivers/crypto/lantiq_eip97/Sources/EIP97/RingControl/eip202_rd_format.o)

$(deps_drivers/crypto/lantiq_eip97/Sources/EIP97/RingControl/eip202_rd_format.o):
