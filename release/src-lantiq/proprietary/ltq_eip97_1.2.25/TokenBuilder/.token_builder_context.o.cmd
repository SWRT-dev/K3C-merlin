cmd_drivers/crypto/lantiq_eip97/Sources/TokenBuilder/token_builder_context.o := mips-openwrt-linux-uclibc-gcc -Wp,-MD,drivers/crypto/lantiq_eip97/Sources/TokenBuilder/.token_builder_context.o.d  -nostdinc -isystem /home/paldier/asuswrt/release/src-lantiq/tools/toolchain-mips_mips32_gcc-4.8-linaro_uClibc-0.9.33.2/bin/../lib/gcc/mips-openwrt-linux-uclibc/4.8.3/include -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include -Iarch/mips/include/generated  -Iinclude -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/uapi -Iarch/mips/include/generated/uapi -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/include/uapi -Iinclude/generated/uapi -include /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/include/linux/kconfig.h -D__KERNEL__ -DVMLINUX_LOAD_ADDRESS=0xffffffff60020000 -DDATAOFFSET=0 -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -std=gnu89 -O2 -fno-reorder-blocks -fno-tree-ch -mno-check-zero-division -mabi=32 -G 0 -mno-abicalls -fno-pic -pipe -mno-branch-likely -msoft-float -ffreestanding -march=mips32r2 -Wa,-mips32r2 -Wa,--trap -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-lantiq -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-lantiq/grx500 -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-generic -Wframe-larger-than=1024 -fno-stack-protector -Wno-unused-but-set-variable -fomit-frame-pointer -fno-var-tracking-assignments -g -femit-struct-debug-baseonly -fno-var-tracking -fno-inline-functions-called-once -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO -Idrivers/crypto/lantiq_eip97/Sources/incl -Idrivers/crypto/lantiq_eip97/Sources/DriverFramework -Idrivers/crypto/lantiq_eip97/Sources/EIP201 -Idrivers/crypto/lantiq_eip97/Sources/EIP97/GlobalControl -Idrivers/crypto/lantiq_eip97/Sources/EIP97/RingControl -Idrivers/crypto/lantiq_eip97/Sources/RingHelper -Idrivers/crypto/lantiq_eip97/Sources/SABuilder -Idrivers/crypto/lantiq_eip97/Sources/TokenBuilder -Idrivers/crypto/lantiq_eip97/Sources/Log   -ffunction-sections -fdata-sections  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(token_builder_context)"  -D"KBUILD_MODNAME=KBUILD_STR(ltq_crypto)" -c -o drivers/crypto/lantiq_eip97/Sources/TokenBuilder/token_builder_context.o drivers/crypto/lantiq_eip97/Sources/TokenBuilder/token_builder_context.c

source_drivers/crypto/lantiq_eip97/Sources/TokenBuilder/token_builder_context.o := drivers/crypto/lantiq_eip97/Sources/TokenBuilder/token_builder_context.c

deps_drivers/crypto/lantiq_eip97/Sources/TokenBuilder/token_builder_context.o := \
  drivers/crypto/lantiq_eip97/Sources/TokenBuilder/token_builder.h \
  drivers/crypto/lantiq_eip97/Sources/SABuilder/sa_builder_params.h \
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
  drivers/crypto/lantiq_eip97/Sources/TokenBuilder/c_token_builder.h \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_token_builder.h \
  drivers/crypto/lantiq_eip97/Sources/Log/log.h \
  drivers/crypto/lantiq_eip97/Sources/Log/log_impl.h \
  include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
  /home/paldier/asuswrt/release/src-lantiq/tools/toolchain-mips_mips32_gcc-4.8-linaro_uClibc-0.9.33.2/lib/gcc/mips-openwrt-linux-uclibc/4.8.3/include/stdarg.h \
  include/linux/linkage.h \
  include/linux/stringify.h \
  include/linux/export.h \
    $(wildcard include/config/have/underscore/symbol/prefix.h) \
    $(wildcard include/config/modules.h) \
    $(wildcard include/config/modversions.h) \
    $(wildcard include/config/unused/symbols.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/linkage.h \
  include/linux/bitops.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/bitops.h \
    $(wildcard include/config/cpu/mipsr2.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/barrier.h \
    $(wildcard include/config/cpu/has/sync.h) \
    $(wildcard include/config/cpu/cavium/octeon.h) \
    $(wildcard include/config/sgi/ip28.h) \
    $(wildcard include/config/cpu/has/wb.h) \
    $(wildcard include/config/weak/ordering.h) \
    $(wildcard include/config/smp.h) \
    $(wildcard include/config/weak/reordering/beyond/llsc.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/addrspace.h \
    $(wildcard include/config/cpu/r8000.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-lantiq/spaces.h \
    $(wildcard include/config/eva.h) \
    $(wildcard include/config/eva/2gb.h) \
    $(wildcard include/config/eva/1gb.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-generic/spaces.h \
    $(wildcard include/config/32bit.h) \
    $(wildcard include/config/kvm/guest.h) \
    $(wildcard include/config/dma/noncoherent.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/include/uapi/linux/const.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/uapi/asm/byteorder.h \
  include/linux/byteorder/big_endian.h \
  include/uapi/linux/byteorder/big_endian.h \
  include/linux/swab.h \
  include/uapi/linux/swab.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/uapi/asm/swab.h \
  include/linux/byteorder/generic.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/cpu-features.h \
    $(wildcard include/config/sys/supports/micromips.h) \
    $(wildcard include/config/cpu/mipsr2/irq/vi.h) \
    $(wildcard include/config/cpu/mipsr2/irq/ei.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/cpu.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/cpu-info.h \
    $(wildcard include/config/mips/mt/smp.h) \
    $(wildcard include/config/mips/mt/smtc.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/cache.h \
    $(wildcard include/config/mips/l1/cache/shift.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-generic/kmalloc.h \
    $(wildcard include/config/dma/coherent.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-lantiq/grx500/cpu-feature-overrides.h \
    $(wildcard include/config/soc/grx500.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/war.h \
    $(wildcard include/config/cpu/r4000/workarounds.h) \
    $(wildcard include/config/cpu/r4400/workarounds.h) \
    $(wildcard include/config/cpu/daddi/workarounds.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-lantiq/war.h \
  include/asm-generic/bitops/non-atomic.h \
  include/asm-generic/bitops/fls64.h \
  include/asm-generic/bitops/ffz.h \
  include/asm-generic/bitops/find.h \
    $(wildcard include/config/generic/find/first/bit.h) \
  include/asm-generic/bitops/sched.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/arch_hweight.h \
  include/asm-generic/bitops/arch_hweight.h \
  include/asm-generic/bitops/const_hweight.h \
  include/asm-generic/bitops/le.h \
  include/asm-generic/bitops/ext2-atomic.h \
  include/linux/log2.h \
    $(wildcard include/config/arch/has/ilog2/u32.h) \
    $(wildcard include/config/arch/has/ilog2/u64.h) \
  include/linux/typecheck.h \
  include/linux/printk.h \
    $(wildcard include/config/early/printk.h) \
    $(wildcard include/config/printk.h) \
    $(wildcard include/config/dynamic/debug.h) \
  include/linux/init.h \
    $(wildcard include/config/ltq/ipqos/ebt/opt.h) \
    $(wildcard include/config/ltq/ipqos/ipt/nf/opt.h) \
    $(wildcard include/config/ltq/sys/opt.h) \
    $(wildcard include/config/broken/rodata.h) \
  include/linux/kern_levels.h \
  include/linux/dynamic_debug.h \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  include/uapi/linux/string.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/string.h \
    $(wildcard include/config/cpu/r3000.h) \
  include/linux/errno.h \
  include/uapi/linux/errno.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/errno.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/uapi/asm/errno.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/include/uapi/asm-generic/errno-base.h \
  include/uapi/linux/kernel.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/include/uapi/linux/sysinfo.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/div64.h \
  include/asm-generic/div64.h \
  drivers/crypto/lantiq_eip97/Sources/SABuilder/sa_builder_params_ipsec.h \
  drivers/crypto/lantiq_eip97/Sources/SABuilder/sa_builder_params.h \
  drivers/crypto/lantiq_eip97/Sources/TokenBuilder/token_builder_internal.h \
  drivers/crypto/lantiq_eip97/Sources/SABuilder/sa_builder_params_basic.h \

drivers/crypto/lantiq_eip97/Sources/TokenBuilder/token_builder_context.o: $(deps_drivers/crypto/lantiq_eip97/Sources/TokenBuilder/token_builder_context.o)

$(deps_drivers/crypto/lantiq_eip97/Sources/TokenBuilder/token_builder_context.o):
