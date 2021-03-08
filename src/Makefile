#---------------------------------------------------------------------
# Makefile for BlockOut
#
# ubuntu 12.04 LTS needed packages.
#
#  libgl1-mesa-swx11-dev
#  libglu1-mesa-dev
#  libxext-dev
#  libsdl1.2-dev
#  libsdl-mixer1.2-dev
#
#---------------------------------------------------------------------
# All source files needed for the application
#
CHAINPREFIX=/opt/miyoo
CROSS_COMPILE=$(CHAINPREFIX)/usr/bin/arm-linux-

AR ?= $(CROSS_COMPILE)ar
CC ?= $(CROSS_COMPILE)gcc
CXX ?= $(CROSS_COMPILE)g++
STRIP ?= $(CROSS_COMPILE)strip

SYSROOT		= $(shell $(CC) --print-sysroot)
SDL_CFLAGS  ?= $(shell $(SYSROOT)/usr/bin/sdl-config --cflags)
SDL_LIBS    ?= $(shell $(SYSROOT)/usr/bin/sdl-config --libs)

SRC = 	BlockOut.cpp         PageChooseSetup.cpp       PageStartGame.cpp \
	EditControl.cpp      PageControls.cpp          Pit.cpp \
	Game.cpp             PageCredits.cpp           PolyCube.cpp \
	Http.cpp             PageHallOfFame.cpp        SetupManager.cpp \
	InitPolyCube.cpp     PageHallOfFameOnLine.cpp  SoundManager.cpp \
	Menu.cpp             PageHttp.cpp              Sprites.cpp \
	MenuGraphics.cpp     PageMainMenu.cpp          Utils.cpp \
	MenuGrid.cpp         PageOptions.cpp           PageChangeSetup.cpp  \
	PageScoreDetails.cpp PageGSOptions.cpp         BotPlayer.cpp \
	BotPlayerAI.cpp      BotMatrix.cpp \
	GLApp/GLApp.cpp  GLApp/GLFont.cpp  GLApp/GLMatrix.cpp  GLApp/GLSprite.cpp

OBJ=    BlockOut.o         PageChooseSetup.o       PageStartGame.o \
	EditControl.o      PageControls.o          Pit.o \
	Game.o             PageCredits.o           PolyCube.o \
	Http.o             PageHallOfFame.o        SetupManager.o \
	InitPolyCube.o     PageHallOfFameOnLine.o  SoundManager.o \
	Menu.o             PageHttp.o              Sprites.o \
	MenuGraphics.o     PageMainMenu.o          Utils.o \
	MenuGrid.o         PageOptions.o           PageChangeSetup.o  \
	PageScoreDetails.o PageGSOptions.o         BotPlayer.o \
	BotPlayerAI.o      BotMatrix.o \
	GLApp/GLApp.o  GLApp/GLFont.o  GLApp/GLMatrix.o  GLApp/GLSprite.o

#---------------------------------------------------------------------

CXXFLAGS = $(SDL_CFLAGS) -O2 -DRS97 -fdata-sections -ffunction-sections -fno-rtti -fno-exceptions -fno-math-errno -fno-threadsafe-statics -Dlinux -DTINYSDGL -c -IImageLib/src -I.
LFLAGS   = $(SDL_LIBS) -lSDL_mixer ImageLib/src/libimagelib.a VTinyGL/tinygles.a -lpthread -lm -ldl -Wl,--as-needed -Wl,--gc-sections -flto -lz -lpng

#--------------------------------------------------------------------

all: $(OBJ)
	@echo Linking...
	$(CXX) $(OBJ) $(LFLAGS) -o ../blockout2/blockout2.dge
	@echo Linking OK...

clean:
	@echo Cleaning...
	@rm -f *.o
	@rm -f GLApp/*.o
