#
# Blockout 2 for the RetroFW
#
# pingflood; 2020
#

CHAINPREFIX:=/opt/mipsel-linux-uclibc
CROSS_COMPILE:=$(CHAINPREFIX)/usr/bin/mipsel-linux-

AR := $(CROSS_COMPILE)ar
CC := $(CROSS_COMPILE)gcc
CXX := $(CROSS_COMPILE)g++
STRIP := $(CROSS_COMPILE)strip
RANLIB := $(CROSS_COMPILE)ranlib

SYSROOT := $(CHAINPREFIX)/usr/mipsel-buildroot-linux-uclibc/sysroot

export CHAINPREFIX CROSS_COMPILE AR CC CXX STRIP RANLIB SYSROOT

all:
	make -C src/VTinyGL/
	make -C src/ImageLib/src/
	make -C src/

clean:
	make clean -C src/ImageLib/src/
	make clean -C src/VTinyGL/
	make clean -C src/
	rm -f blockout2/blockout2.dge blockout2/blockout2.ipk

opk: all
	mksquashfs \
	blockout2/default.retrofw.desktop \
	blockout2/images \
	blockout2/sounds \
	blockout2/blockout2.dge \
	blockout2/blockout2.png \
	blockout2/blockout2.opk \
	-all-root -noappend -no-exports -no-xattrs
# 	blockout2/default.gcw0.desktop \
