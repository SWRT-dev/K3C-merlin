cmd_drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_lkm.o := mips-openwrt-linux-uclibc-gcc -Wp,-MD,drivers/crypto/lantiq_eip97/Sources/DriverFramework/.dmares_lkm.o.d  -nostdinc -isystem /home/paldier/asuswrt/release/src-lantiq/tools/toolchain-mips_mips32_gcc-4.8-linaro_uClibc-0.9.33.2/bin/../lib/gcc/mips-openwrt-linux-uclibc/4.8.3/include -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include -Iarch/mips/include/generated  -Iinclude -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/uapi -Iarch/mips/include/generated/uapi -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/include/uapi -Iinclude/generated/uapi -include /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/include/linux/kconfig.h -D__KERNEL__ -DVMLINUX_LOAD_ADDRESS=0xffffffff60020000 -DDATAOFFSET=0 -Wall -Wundef -Wstrict-prototypes -Wno-trigraphs -fno-strict-aliasing -fno-common -Werror-implicit-function-declaration -Wno-format-security -fno-delete-null-pointer-checks -std=gnu89 -O2 -fno-reorder-blocks -fno-tree-ch -mno-check-zero-division -mabi=32 -G 0 -mno-abicalls -fno-pic -pipe -mno-branch-likely -msoft-float -ffreestanding -march=mips32r2 -Wa,-mips32r2 -Wa,--trap -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-lantiq -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-lantiq/grx500 -I/home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-generic -Wframe-larger-than=1024 -fno-stack-protector -Wno-unused-but-set-variable -fomit-frame-pointer -fno-var-tracking-assignments -g -femit-struct-debug-baseonly -fno-var-tracking -fno-inline-functions-called-once -Wdeclaration-after-statement -Wno-pointer-sign -fno-strict-overflow -fconserve-stack -DCC_HAVE_ASM_GOTO -Idrivers/crypto/lantiq_eip97/Sources/incl -Idrivers/crypto/lantiq_eip97/Sources/DriverFramework -Idrivers/crypto/lantiq_eip97/Sources/EIP201 -Idrivers/crypto/lantiq_eip97/Sources/EIP97/GlobalControl -Idrivers/crypto/lantiq_eip97/Sources/EIP97/RingControl -Idrivers/crypto/lantiq_eip97/Sources/RingHelper -Idrivers/crypto/lantiq_eip97/Sources/SABuilder -Idrivers/crypto/lantiq_eip97/Sources/TokenBuilder -Idrivers/crypto/lantiq_eip97/Sources/Log   -ffunction-sections -fdata-sections  -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(dmares_lkm)"  -D"KBUILD_MODNAME=KBUILD_STR(ltq_crypto)" -c -o drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_lkm.o drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_lkm.c

source_drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_lkm.o := drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_lkm.c

deps_drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_lkm.o := \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_mgmt.h \
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
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_types.h \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_record.h \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_adapter.h \
    $(wildcard include/config/cachelinesize.h) \
    $(wildcard include/config/masterlatencytimer.h) \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_driver.h \
    $(wildcard include/config/cnn.h) \
    $(wildcard include/config/ltq/crypto/max/ring/used.h) \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_systemtestconfig.h \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_driver_ext.h \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_driver_ext2.h \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_adapter_ext.h \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_buf.h \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_rw.h \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_hwpal.h \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/clib.h \
  include/linux/string.h \
    $(wildcard include/config/binary/printf.h) \
  /home/paldier/asuswrt/release/src-lantiq/tools/toolchain-mips_mips32_gcc-4.8-linaro_uClibc-0.9.33.2/lib/gcc/mips-openwrt-linux-uclibc/4.8.3/include/stdarg.h \
  include/uapi/linux/string.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/string.h \
    $(wildcard include/config/32bit.h) \
    $(wildcard include/config/cpu/r3000.h) \
  drivers/crypto/lantiq_eip97/Sources/incl/c_dmares_lkm.h \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_hwpal_lkm.h \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_hwpal.h \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_adapter.h \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_hwpal_ext.h \
  drivers/crypto/lantiq_eip97/Sources/incl/cs_hwpal_ext2.h \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_gen.h \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/device_swap.h \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/device_mgmt.h \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/device_types.h \
  drivers/crypto/lantiq_eip97/Sources/Log/log.h \
  drivers/crypto/lantiq_eip97/Sources/DriverFramework/basic_defs.h \
  drivers/crypto/lantiq_eip97/Sources/Log/log_impl.h \
  include/linux/kernel.h \
    $(wildcard include/config/preempt/voluntary.h) \
    $(wildcard include/config/debug/atomic/sleep.h) \
    $(wildcard include/config/prove/locking.h) \
    $(wildcard include/config/ring/buffer.h) \
    $(wildcard include/config/tracing.h) \
    $(wildcard include/config/ftrace/mcount/record.h) \
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
  include/linux/errno.h \
  include/uapi/linux/errno.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/errno.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/uapi/asm/errno.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/include/uapi/asm-generic/errno-base.h \
  include/uapi/linux/kernel.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/include/uapi/linux/sysinfo.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/div64.h \
  include/asm-generic/div64.h \
  include/linux/slab.h \
    $(wildcard include/config/slab/debug.h) \
    $(wildcard include/config/debug/objects.h) \
    $(wildcard include/config/kmemcheck.h) \
    $(wildcard include/config/failslab.h) \
    $(wildcard include/config/slob.h) \
    $(wildcard include/config/slab.h) \
    $(wildcard include/config/zone/dma.h) \
    $(wildcard include/config/slub.h) \
    $(wildcard include/config/numa.h) \
    $(wildcard include/config/debug/slab.h) \
  include/linux/gfp.h \
    $(wildcard include/config/highmem.h) \
    $(wildcard include/config/zone/dma32.h) \
    $(wildcard include/config/pm/sleep.h) \
    $(wildcard include/config/cma.h) \
  include/linux/mmzone.h \
    $(wildcard include/config/force/max/zoneorder.h) \
    $(wildcard include/config/memory/isolation.h) \
    $(wildcard include/config/memcg.h) \
    $(wildcard include/config/compaction.h) \
    $(wildcard include/config/memory/hotplug.h) \
    $(wildcard include/config/sparsemem.h) \
    $(wildcard include/config/have/memblock/node/map.h) \
    $(wildcard include/config/discontigmem.h) \
    $(wildcard include/config/flat/node/mem/map.h) \
    $(wildcard include/config/no/bootmem.h) \
    $(wildcard include/config/numa/balancing.h) \
    $(wildcard include/config/have/memory/present.h) \
    $(wildcard include/config/have/memoryless/nodes.h) \
    $(wildcard include/config/need/node/memmap/size.h) \
    $(wildcard include/config/need/multiple/nodes.h) \
    $(wildcard include/config/have/arch/early/pfn/to/nid.h) \
    $(wildcard include/config/flatmem.h) \
    $(wildcard include/config/sparsemem/extreme.h) \
    $(wildcard include/config/have/arch/pfn/valid.h) \
    $(wildcard include/config/nodes/span/other/nodes.h) \
    $(wildcard include/config/holes/in/zone.h) \
    $(wildcard include/config/arch/has/holes/memorymodel.h) \
  include/linux/spinlock.h \
    $(wildcard include/config/debug/spinlock.h) \
    $(wildcard include/config/generic/lockbreak.h) \
    $(wildcard include/config/preempt.h) \
    $(wildcard include/config/debug/lock/alloc.h) \
  include/linux/preempt.h \
    $(wildcard include/config/debug/preempt.h) \
    $(wildcard include/config/preempt/tracer.h) \
    $(wildcard include/config/context/tracking.h) \
    $(wildcard include/config/preempt/count.h) \
    $(wildcard include/config/preempt/notifiers.h) \
  include/linux/thread_info.h \
    $(wildcard include/config/compat.h) \
    $(wildcard include/config/debug/stack/usage.h) \
  include/linux/bug.h \
    $(wildcard include/config/generic/bug.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/bug.h \
    $(wildcard include/config/bug.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/break.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/uapi/asm/break.h \
  include/asm-generic/bug.h \
    $(wildcard include/config/generic/bug/relative/pointers.h) \
    $(wildcard include/config/debug/bugverbose.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/thread_info.h \
    $(wildcard include/config/page/size/4kb.h) \
    $(wildcard include/config/page/size/8kb.h) \
    $(wildcard include/config/page/size/16kb.h) \
    $(wildcard include/config/page/size/32kb.h) \
    $(wildcard include/config/page/size/64kb.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/processor.h \
    $(wildcard include/config/cavium/octeon/cvmseg/size.h) \
    $(wildcard include/config/mips/mt/fpaff.h) \
    $(wildcard include/config/cpu/has/prefetch.h) \
  include/linux/cpumask.h \
    $(wildcard include/config/cpumask/offstack.h) \
    $(wildcard include/config/hotplug/cpu.h) \
    $(wildcard include/config/debug/per/cpu/maps.h) \
    $(wildcard include/config/disable/obsolete/cpumask/functions.h) \
  include/linux/threads.h \
    $(wildcard include/config/nr/cpus.h) \
    $(wildcard include/config/base/small.h) \
  include/linux/bitmap.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/uapi/asm/cachectl.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mipsregs.h \
    $(wildcard include/config/cpu/vr41xx.h) \
    $(wildcard include/config/mips/huge/tlb/support.h) \
    $(wildcard include/config/cpu/micromips.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/hazards.h \
    $(wildcard include/config/cpu/mipsr1.h) \
    $(wildcard include/config/mips/alchemy.h) \
    $(wildcard include/config/cpu/bmips.h) \
    $(wildcard include/config/cpu/loongson2.h) \
    $(wildcard include/config/cpu/r10000.h) \
    $(wildcard include/config/cpu/r5500.h) \
    $(wildcard include/config/cpu/xlr.h) \
    $(wildcard include/config/cpu/sb1.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/prefetch.h \
  include/linux/list.h \
    $(wildcard include/config/debug/list.h) \
    $(wildcard include/config/ltq/list/prefetch.h) \
  include/linux/poison.h \
    $(wildcard include/config/illegal/pointer/value.h) \
  include/linux/irqflags.h \
    $(wildcard include/config/trace/irqflags.h) \
    $(wildcard include/config/irqsoff/tracer.h) \
    $(wildcard include/config/trace/irqflags/support.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/irqflags.h \
    $(wildcard include/config/irq/cpu.h) \
  include/linux/bottom_half.h \
  include/linux/spinlock_types.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/spinlock_types.h \
  include/linux/lockdep.h \
    $(wildcard include/config/lockdep.h) \
    $(wildcard include/config/lock/stat.h) \
    $(wildcard include/config/prove/rcu.h) \
  include/linux/rwlock_types.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/spinlock.h \
  include/linux/rwlock.h \
  include/linux/spinlock_api_smp.h \
    $(wildcard include/config/inline/spin/lock.h) \
    $(wildcard include/config/inline/spin/lock/bh.h) \
    $(wildcard include/config/inline/spin/lock/irq.h) \
    $(wildcard include/config/inline/spin/lock/irqsave.h) \
    $(wildcard include/config/inline/spin/trylock.h) \
    $(wildcard include/config/inline/spin/trylock/bh.h) \
    $(wildcard include/config/uninline/spin/unlock.h) \
    $(wildcard include/config/inline/spin/unlock/bh.h) \
    $(wildcard include/config/inline/spin/unlock/irq.h) \
    $(wildcard include/config/inline/spin/unlock/irqrestore.h) \
  include/linux/rwlock_api_smp.h \
    $(wildcard include/config/inline/read/lock.h) \
    $(wildcard include/config/inline/write/lock.h) \
    $(wildcard include/config/inline/read/lock/bh.h) \
    $(wildcard include/config/inline/write/lock/bh.h) \
    $(wildcard include/config/inline/read/lock/irq.h) \
    $(wildcard include/config/inline/write/lock/irq.h) \
    $(wildcard include/config/inline/read/lock/irqsave.h) \
    $(wildcard include/config/inline/write/lock/irqsave.h) \
    $(wildcard include/config/inline/read/trylock.h) \
    $(wildcard include/config/inline/write/trylock.h) \
    $(wildcard include/config/inline/read/unlock.h) \
    $(wildcard include/config/inline/write/unlock.h) \
    $(wildcard include/config/inline/read/unlock/bh.h) \
    $(wildcard include/config/inline/write/unlock/bh.h) \
    $(wildcard include/config/inline/read/unlock/irq.h) \
    $(wildcard include/config/inline/write/unlock/irq.h) \
    $(wildcard include/config/inline/read/unlock/irqrestore.h) \
    $(wildcard include/config/inline/write/unlock/irqrestore.h) \
  include/linux/atomic.h \
    $(wildcard include/config/arch/has/atomic/or.h) \
    $(wildcard include/config/generic/atomic64.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/atomic.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/cmpxchg.h \
  include/asm-generic/cmpxchg-local.h \
  include/asm-generic/atomic-long.h \
  include/asm-generic/atomic64.h \
  include/linux/wait.h \
  arch/mips/include/generated/asm/current.h \
  include/asm-generic/current.h \
  include/uapi/linux/wait.h \
  include/linux/cache.h \
    $(wildcard include/config/arch/has/cache/line/size.h) \
  include/linux/numa.h \
    $(wildcard include/config/nodes/shift.h) \
  include/linux/seqlock.h \
  include/linux/nodemask.h \
    $(wildcard include/config/movable/node.h) \
  include/linux/pageblock-flags.h \
    $(wildcard include/config/hugetlb/page.h) \
    $(wildcard include/config/hugetlb/page/size/variable.h) \
  include/linux/page-flags-layout.h \
    $(wildcard include/config/sparsemem/vmemmap.h) \
  include/generated/bounds.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/page.h \
    $(wildcard include/config/cpu/mips32.h) \
  include/linux/pfn.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/io.h \
    $(wildcard include/config/pci.h) \
  include/asm-generic/iomap.h \
    $(wildcard include/config/has/ioport.h) \
    $(wildcard include/config/generic/iomap.h) \
  include/asm-generic/pci_iomap.h \
    $(wildcard include/config/no/generic/pci/ioport/map.h) \
    $(wildcard include/config/generic/pci/iomap.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/pgtable-bits.h \
    $(wildcard include/config/cpu/tx39xx.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-lantiq/ioremap.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-generic/mangle-port.h \
    $(wildcard include/config/swap/io/space.h) \
  include/asm-generic/memory_model.h \
  include/asm-generic/getorder.h \
  include/linux/memory_hotplug.h \
    $(wildcard include/config/memory/hotremove.h) \
    $(wildcard include/config/have/arch/nodedata/extension.h) \
    $(wildcard include/config/have/bootmem/info/node.h) \
  include/linux/notifier.h \
  include/linux/mutex.h \
    $(wildcard include/config/debug/mutexes.h) \
    $(wildcard include/config/mutex/spin/on/owner.h) \
    $(wildcard include/config/have/arch/mutex/cpu/relax.h) \
  include/linux/rwsem.h \
    $(wildcard include/config/rwsem/generic/spinlock.h) \
  include/linux/rwsem-spinlock.h \
  include/linux/srcu.h \
  include/linux/rcupdate.h \
    $(wildcard include/config/rcu/torture/test.h) \
    $(wildcard include/config/tree/rcu.h) \
    $(wildcard include/config/tree/preempt/rcu.h) \
    $(wildcard include/config/rcu/trace.h) \
    $(wildcard include/config/preempt/rcu.h) \
    $(wildcard include/config/rcu/user/qs.h) \
    $(wildcard include/config/tiny/rcu.h) \
    $(wildcard include/config/tiny/preempt/rcu.h) \
    $(wildcard include/config/debug/objects/rcu/head.h) \
    $(wildcard include/config/rcu/nocb/cpu.h) \
  include/linux/completion.h \
  include/linux/debugobjects.h \
    $(wildcard include/config/debug/objects/free.h) \
  include/linux/rcutree.h \
  include/linux/workqueue.h \
    $(wildcard include/config/debug/objects/work.h) \
    $(wildcard include/config/freezer.h) \
    $(wildcard include/config/sysfs.h) \
  include/linux/timer.h \
    $(wildcard include/config/timer/stats.h) \
    $(wildcard include/config/debug/objects/timers.h) \
  include/linux/ktime.h \
    $(wildcard include/config/ktime/scalar.h) \
  include/linux/time.h \
    $(wildcard include/config/arch/uses/gettimeoffset.h) \
  include/linux/math64.h \
  include/uapi/linux/time.h \
  include/linux/jiffies.h \
  include/linux/timex.h \
  include/uapi/linux/timex.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/include/uapi/linux/param.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/uapi/asm/param.h \
  include/asm-generic/param.h \
    $(wildcard include/config/hz.h) \
  include/uapi/asm-generic/param.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/timex.h \
  include/linux/topology.h \
    $(wildcard include/config/sched/smt.h) \
    $(wildcard include/config/sched/mc.h) \
    $(wildcard include/config/sched/book.h) \
    $(wildcard include/config/use/percpu/numa/node/id.h) \
  include/linux/smp.h \
    $(wildcard include/config/use/generic/smp/helpers.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/smp.h \
    $(wildcard include/config/kexec.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/smp-ops.h \
    $(wildcard include/config/smp/up.h) \
    $(wildcard include/config/mips/cmp.h) \
    $(wildcard include/config/mips/cps.h) \
  arch/mips/include/generated/asm/percpu.h \
  include/asm-generic/percpu.h \
    $(wildcard include/config/have/setup/per/cpu/area.h) \
  include/linux/percpu-defs.h \
    $(wildcard include/config/debug/force/weak/per/cpu.h) \
  include/linux/percpu.h \
    $(wildcard include/config/need/per/cpu/embed/first/chunk.h) \
    $(wildcard include/config/need/per/cpu/page/first/chunk.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/topology.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-generic/topology.h \
  include/asm-generic/topology.h \
  include/linux/mmdebug.h \
    $(wildcard include/config/debug/vm.h) \
    $(wildcard include/config/debug/virtual.h) \
  include/linux/slab_def.h \
    $(wildcard include/config/memcg/kmem.h) \
  include/linux/dma-mapping.h \
    $(wildcard include/config/has/dma.h) \
    $(wildcard include/config/arch/has/dma/set/coherent/mask.h) \
    $(wildcard include/config/have/dma/attrs.h) \
    $(wildcard include/config/need/dma/map/state.h) \
  include/linux/device.h \
    $(wildcard include/config/debug/devres.h) \
    $(wildcard include/config/acpi.h) \
    $(wildcard include/config/pinctrl.h) \
    $(wildcard include/config/devtmpfs.h) \
    $(wildcard include/config/sysfs/deprecated.h) \
  include/linux/ioport.h \
  include/linux/kobject.h \
  include/linux/sysfs.h \
  include/linux/kobject_ns.h \
  include/linux/kref.h \
  include/linux/klist.h \
  include/linux/pinctrl/devinfo.h \
  include/linux/pinctrl/consumer.h \
    $(wildcard include/config/pinconf.h) \
  include/linux/err.h \
  include/linux/seq_file.h \
    $(wildcard include/config/user/ns.h) \
  include/linux/pinctrl/pinctrl-state.h \
  include/linux/pm.h \
    $(wildcard include/config/vt/console/sleep.h) \
    $(wildcard include/config/pm.h) \
    $(wildcard include/config/pm/runtime.h) \
    $(wildcard include/config/pm/clk.h) \
    $(wildcard include/config/pm/generic/domains.h) \
  include/linux/ratelimit.h \
  include/linux/uidgid.h \
    $(wildcard include/config/uidgid/strict/type/checks.h) \
  include/linux/highuid.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/device.h \
  include/linux/pm_wakeup.h \
  include/linux/dma-attrs.h \
  include/linux/dma-direction.h \
  include/linux/scatterlist.h \
    $(wildcard include/config/debug/sg.h) \
  include/linux/mm.h \
    $(wildcard include/config/sysctl.h) \
    $(wildcard include/config/mmu.h) \
    $(wildcard include/config/x86.h) \
    $(wildcard include/config/ppc.h) \
    $(wildcard include/config/parisc.h) \
    $(wildcard include/config/metag.h) \
    $(wildcard include/config/ia64.h) \
    $(wildcard include/config/stack/growsup.h) \
    $(wildcard include/config/transparent/hugepage.h) \
    $(wildcard include/config/ksm.h) \
    $(wildcard include/config/debug/vm/rb.h) \
    $(wildcard include/config/arch/uses/numa/prot/none.h) \
    $(wildcard include/config/proc/fs.h) \
    $(wildcard include/config/debug/pagealloc.h) \
    $(wildcard include/config/hibernation.h) \
    $(wildcard include/config/hugetlbfs.h) \
  include/linux/rbtree.h \
  include/linux/debug_locks.h \
    $(wildcard include/config/debug/locking/api/selftests.h) \
  include/linux/mm_types.h \
    $(wildcard include/config/split/ptlock/cpus.h) \
    $(wildcard include/config/have/cmpxchg/double.h) \
    $(wildcard include/config/have/aligned/struct/page.h) \
    $(wildcard include/config/want/page/debug/flags.h) \
    $(wildcard include/config/aio.h) \
    $(wildcard include/config/mm/owner.h) \
    $(wildcard include/config/mmu/notifier.h) \
  include/linux/auxvec.h \
  include/uapi/linux/auxvec.h \
  arch/mips/include/generated/uapi/asm/auxvec.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/include/uapi/asm-generic/auxvec.h \
  include/linux/page-debug-flags.h \
    $(wildcard include/config/page/poisoning.h) \
    $(wildcard include/config/page/guard.h) \
    $(wildcard include/config/page/debug/something/else.h) \
  include/linux/uprobes.h \
    $(wildcard include/config/arch/supports/uprobes.h) \
    $(wildcard include/config/uprobes.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mmu.h \
  include/linux/range.h \
  include/linux/bit_spinlock.h \
  include/linux/shrinker.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/pgtable.h \
    $(wildcard include/config/cpu/supports/uncached/accelerated.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/pgtable-32.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/fixmap.h \
    $(wildcard include/config/eva/3gb.h) \
  include/asm-generic/pgtable-nopmd.h \
  include/asm-generic/pgtable-nopud.h \
  include/asm-generic/pgtable.h \
  include/linux/page-flags.h \
    $(wildcard include/config/pageflags/extended.h) \
    $(wildcard include/config/arch/uses/pg/uncached.h) \
    $(wildcard include/config/memory/failure.h) \
    $(wildcard include/config/swap.h) \
  include/linux/huge_mm.h \
  include/linux/vmstat.h \
    $(wildcard include/config/vm/event/counters.h) \
  include/linux/vm_event_item.h \
    $(wildcard include/config/migration.h) \
  arch/mips/include/generated/asm/scatterlist.h \
  include/asm-generic/scatterlist.h \
    $(wildcard include/config/need/sg/dma/length.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/dma-mapping.h \
    $(wildcard include/config/sgi/ip27.h) \
    $(wildcard include/config/sys/has/dma/ops.h) \
    $(wildcard include/config/sys/has/cpu/r10000.h) \
  include/linux/kmemcheck.h \
  include/linux/dma-debug.h \
    $(wildcard include/config/dma/api/debug.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/dma-coherence.h \
    $(wildcard include/config/dma/maybe/coherent.h) \
  include/asm-generic/dma-coherent.h \
    $(wildcard include/config/have/generic/dma/coherent.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-generic/dma-coherence.h \
  include/linux/hardirq.h \
    $(wildcard include/config/generic/hardirqs.h) \
  include/linux/ftrace_irq.h \
    $(wildcard include/config/ftrace/nmi/enter.h) \
  include/linux/vtime.h \
    $(wildcard include/config/virt/cpu/accounting.h) \
    $(wildcard include/config/virt/cpu/accounting/native.h) \
    $(wildcard include/config/virt/cpu/accounting/gen.h) \
    $(wildcard include/config/irq/time/accounting.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/hardirq.h \
  include/asm-generic/hardirq.h \
  include/linux/irq_cpustat.h \
  include/linux/irq.h \
    $(wildcard include/config/generic/pending/irq.h) \
    $(wildcard include/config/hardirqs/sw/resend.h) \
  include/linux/irqreturn.h \
  include/linux/irqnr.h \
  include/uapi/linux/irqnr.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/irq.h \
    $(wildcard include/config/i8259.h) \
    $(wildcard include/config/mips/mt/smtc/irqaff.h) \
    $(wildcard include/config/mips/mt/smtc/im/backstop.h) \
  include/linux/irqdomain.h \
    $(wildcard include/config/irq/domain.h) \
    $(wildcard include/config/of/irq.h) \
  include/linux/radix-tree.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mipsmtregs.h \
    $(wildcard include/config/ltq/vpe/cache/split.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-lantiq/grx500/irq.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/mach-generic/irq.h \
    $(wildcard include/config/irq/cpu/rm7k.h) \
    $(wildcard include/config/irq/gic.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/ptrace.h \
    $(wildcard include/config/cpu/has/smartmips.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/isadep.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/uapi/asm/ptrace.h \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/irq_regs.h \
  include/linux/irqdesc.h \
    $(wildcard include/config/irq/preflow/fasteoi.h) \
    $(wildcard include/config/sparse/irq.h) \
  /home/paldier/asuswrt/release/src-lantiq/linux/linux-3.10.104/arch/mips/include/asm/hw_irq.h \
  include/linux/io.h \

drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_lkm.o: $(deps_drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_lkm.o)

$(deps_drivers/crypto/lantiq_eip97/Sources/DriverFramework/dmares_lkm.o):
