cmd_libbb/perror_nomsg_and_die.o := i686-linux-gnu-gcc -Wp,-MD,libbb/.perror_nomsg_and_die.o.d  -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -DBB_VER='"1.34.1"' -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wunused-function -Wunused-value -Wmissing-prototypes -Wmissing-declarations -Wno-format-security -Wdeclaration-after-statement -Wold-style-definition -finline-limit=0 -fno-builtin-strlen -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -static-libgcc -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin-printf -Os    -DKBUILD_BASENAME='"perror_nomsg_and_die"'  -DKBUILD_MODNAME='"perror_nomsg_and_die"' -c -o libbb/perror_nomsg_and_die.o libbb/perror_nomsg_and_die.c

deps_libbb/perror_nomsg_and_die.o := \
  libbb/perror_nomsg_and_die.c \
  /usr/i686-linux-gnu/include/stdc-predef.h \
  include/platform.h \
    $(wildcard include/config/werror.h) \
    $(wildcard include/config/big/endian.h) \
    $(wildcard include/config/little/endian.h) \
    $(wildcard include/config/nommu.h) \
  /usr/lib/gcc-cross/i686-linux-gnu/11/include/limits.h \
  /usr/lib/gcc-cross/i686-linux-gnu/11/include/syslimits.h \
  /usr/i686-linux-gnu/include/limits.h \
  /usr/i686-linux-gnu/include/bits/libc-header-start.h \
  /usr/i686-linux-gnu/include/features.h \
  /usr/i686-linux-gnu/include/features-time64.h \
  /usr/i686-linux-gnu/include/bits/wordsize.h \
  /usr/i686-linux-gnu/include/bits/timesize.h \
  /usr/i686-linux-gnu/include/sys/cdefs.h \
  /usr/i686-linux-gnu/include/bits/long-double.h \
  /usr/i686-linux-gnu/include/gnu/stubs.h \
  /usr/i686-linux-gnu/include/gnu/stubs-32.h \
  /usr/i686-linux-gnu/include/bits/posix1_lim.h \
  /usr/i686-linux-gnu/include/bits/local_lim.h \
  /usr/i686-linux-gnu/include/linux/limits.h \
  /usr/i686-linux-gnu/include/bits/pthread_stack_min-dynamic.h \
  /usr/i686-linux-gnu/include/bits/posix2_lim.h \
  /usr/i686-linux-gnu/include/bits/xopen_lim.h \
  /usr/i686-linux-gnu/include/bits/uio_lim.h \
  /usr/i686-linux-gnu/include/byteswap.h \
  /usr/i686-linux-gnu/include/bits/byteswap.h \
  /usr/i686-linux-gnu/include/bits/types.h \
  /usr/i686-linux-gnu/include/bits/typesizes.h \
  /usr/i686-linux-gnu/include/bits/time64.h \
  /usr/i686-linux-gnu/include/endian.h \
  /usr/i686-linux-gnu/include/bits/endian.h \
  /usr/i686-linux-gnu/include/bits/endianness.h \
  /usr/i686-linux-gnu/include/bits/uintn-identity.h \
  /usr/lib/gcc-cross/i686-linux-gnu/11/include/stdint.h \
  /usr/i686-linux-gnu/include/stdint.h \
  /usr/i686-linux-gnu/include/bits/wchar.h \
  /usr/i686-linux-gnu/include/bits/stdint-intn.h \
  /usr/i686-linux-gnu/include/bits/stdint-uintn.h \
  /usr/lib/gcc-cross/i686-linux-gnu/11/include/stdbool.h \
  /usr/i686-linux-gnu/include/unistd.h \
  /usr/i686-linux-gnu/include/bits/posix_opt.h \
  /usr/i686-linux-gnu/include/bits/environments.h \
  /usr/lib/gcc-cross/i686-linux-gnu/11/include/stddef.h \
  /usr/i686-linux-gnu/include/bits/confname.h \
  /usr/i686-linux-gnu/include/bits/getopt_posix.h \
  /usr/i686-linux-gnu/include/bits/getopt_core.h \
  /usr/i686-linux-gnu/include/bits/unistd.h \
  /usr/i686-linux-gnu/include/bits/unistd_ext.h \
  /usr/i686-linux-gnu/include/linux/close_range.h \

libbb/perror_nomsg_and_die.o: $(deps_libbb/perror_nomsg_and_die.o)

$(deps_libbb/perror_nomsg_and_die.o):
