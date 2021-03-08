#---------------------------------------------------------------------
# Makefile for ImageLib
#
# Note: Sorry to not have libtoolized this project but i don't have
#       enough time to do that.

#
#---------------------------------------------------------------------
# All source files needed for the library
#
CHAINPREFIX ?= /opt/miyoo
CROSS_COMPILE ?= $(CHAINPREFIX)/usr/bin/arm-linux-


AR ?= $(CROSS_COMPILE)ar

OBJ = CImage.o png/hpng.o png/png/png.o  \
	png/png/pngerror.o  png/png/pnggccrd.o  png/png/pngget.o  png/png/pngmem.o  png/png/pngpread.o  png/png/pngread.o  png/png/pngrio.o  png/png/pngrtran.o  \
	png/png/pngrutil.o  png/png/pngset.o  png/png/pngtrans.o  png/png/pngvcrd.o  png/png/pngwio.o  png/png/pngwrite.o  png/png/pngwtran.o  png/png/pngwutil.o \
	png/zlib/adler32.o  png/zlib/compress.o  png/zlib/crc32.o  png/zlib/deflate.o  png/zlib/gzio.o  png/zlib/infback.o  png/zlib/inffast.o  png/zlib/inflate.o \
	png/zlib/inftrees.o  png/zlib/trees.o  png/zlib/uncompr.o  png/zlib/zutil.o

#--------------------------------------------------------------------

all: $(OBJ)
	@echo Making library...
	@rm -f libimagelib.a
	$(AR) -rv libimagelib.a $(OBJ)

clean:
	@echo Cleaning...
	@rm -f *.o
	@rm -f gif/*.o
	@rm -f jpg/*.o
	@rm -f png/*.o
	@rm -f png/png/*.o
	@rm -f png/zlib/*.o
