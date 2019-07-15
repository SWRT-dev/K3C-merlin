# build/os-auto.mak.  Generated from os-auto.mak.in by configure.

export OS_CFLAGS   := $(CC_DEF)PJ_AUTOCONF=1 -I/home/paldier/asuswrt/release/src-lantiq/router/openssl/include  -g -O2 -fPIC -DROUTER=1  -DPJ_IS_BIG_ENDIAN=1 -DPJ_IS_LITTLE_ENDIAN=0

export OS_CXXFLAGS := $(CC_DEF)PJ_AUTOCONF=1 -I/home/paldier/asuswrt/release/src-lantiq/router/openssl/include  -g -O2 -fPIC -DROUTER=1  

export OS_LDFLAGS  := -L/home/paldier/asuswrt/release/src-lantiq/router/openssl    -L/home/paldier/asuswrt/release/src-lantiq/tools/toolchain-mips_mips32_gcc-4.8-linaro_uClibc-0.9.33.2/lib  -ldl -lc -lgcc_s -lm -lnsl -lrt -lpthread  -lssl -lcrypto -lpthread    -lstdc++ -lcrypto -lssl

export OS_SOURCES  := 


