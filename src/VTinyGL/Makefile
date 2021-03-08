CHAINPREFIX ?= /opt/miyoo
CROSS_COMPILE ?= $(CHAINPREFIX)/usr/bin/arm-linux-

AR ?= $(CROSS_COMPILE)ar
CC ?= $(CROSS_COMPILE)gcc
CXX ?= $(CROSS_COMPILE)g++
STRIP ?= $(CROSS_COMPILE)strip
RANLIB ?= $(CROSS_COMPILE)ranlib

SYSROOT		= $(shell $(CC) --print-sysroot)
SDL_CFLAGS  ?= $(shell $(SYSROOT)/usr/bin/sdl-config --cflags)
SDL_LIBS    ?= $(shell $(SYSROOT)/usr/bin/sdl-config --libs)

CFLAGS = -O2 -std=gnu99 -Iutil -Isrc -Iinclude $(SDL_CFLAGS)
CXXFLAGS = $(CFLAGS)
OUTPUT = tinygles.a

OBJS = ./src/api.o  ./src/get.o     ./src/list.o      ./src/vertex.o   ./src/zline.o ./src/vgl.o \
	./src/arrays.o  ./src/glx.o         ./src/matrix.o       ./src/oscontext.o  ./src/zmath.o \
	./src/clear.o   ./src/image_util.o  ./src/memory.o       ./src/select.o     ./src/ztriangle.o \
	./src/clip.o    ./src/init.o        ./src/misc.o         ./src/specbuf.o    ./src/zbuffer.o \
	./src/error.o   ./src/light.o       ./src/msghandling.o  ./src/texture.o    ./src/zdither.o ./src/blend.o

all: ${OUTPUT} toar

${OUTPUT}:${OBJS}
	${CC} -c -o ${OUTPUT} ${OBJS} ${CFLAGS}

toar:
	$(AR) cr ${OUTPUT} ${OBJS}
	$(RANLIB) ${OUTPUT}

clean:
	rm  ${OBJS}  ${OUTPUT}
