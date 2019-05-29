/*
   File:        PageMainMenu.cpp
  Description: Main menu page
  Program:     BlockOut
  Author:      Jean-Luc PONS

  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
*/

#include "Menu.h"

enum MENU_ITEMS {
  // START_GAME,
  CHOOSE_SETUP,
  HALL_OF_FAME,
  // ONLINE_SCORE,
  OPTIONS,
  // WRITE_SETUP,
  // DEMO,
  PRACTICE,
  CREDITS,
  QUIT,
  NB_ITEMS
};


void PageMainMenu::Prepare(int iParam,void *pParam) {
  nbItem  = NB_ITEMS;
  selItem = 0;
  startWriteTime = 0.0f;
}

void PageMainMenu::Render() {
  mParent->RenderTitle(STR("MAIN MENU"));
  // mParent->RenderText(0,START_GAME,(selItem==START_GAME),STR("Start Game  "));
  // mParent->RenderText(0,CHOOSE_SETUP,(selItem==CHOOSE_SETUP),STR("Choose Setup"));
  mParent->RenderText(0,CHOOSE_SETUP,(selItem==CHOOSE_SETUP),STR("Start Game  "));
  mParent->RenderText(0,HALL_OF_FAME,(selItem==HALL_OF_FAME),STR("Hall of Fame"));
  // mParent->RenderText(0,ONLINE_SCORE,(selItem==ONLINE_SCORE),STR("Online Score"));
  mParent->RenderText(0,OPTIONS,(selItem==OPTIONS),STR("Options     "));
  // mParent->RenderText(0,WRITE_SETUP,(selItem==WRITE_SETUP),STR("Write Setup "));
  // if( startWriteTime!=0.0f ) mParent->RenderText(12,WRITE_SETUP,FALSE,STR("[Done]"));
  // mParent->RenderText(0,DEMO,(selItem==DEMO),STR("Demo        "));
  mParent->RenderText(0,PRACTICE,(selItem==PRACTICE),STR("Practice    "));
  mParent->RenderText(0,CREDITS,(selItem==CREDITS),STR("Credits     "));
  mParent->RenderText(0,QUIT,(selItem==QUIT),STR("Quit        "));
  mParent->RenderText(13,0,FALSE,mParent->GetSetup()->GetName());

}

int PageMainMenu::Process(BYTE *keys,float fTime) {

  int exitValue = 0;

  if( startWriteTime!=0.0f ) {
    if( fTime-startWriteTime>0.5f ) {
      startWriteTime = 0.0f;
    } else {
      return exitValue;
    }
  }

  ProcessDefault(keys,fTime);

  if( keys[SDLK_RETURN] ) {
    switch(selItem) {
      // case START_GAME: // Start game
      //   mParent->ToPage(&mParent->startGamePage);
      //   break;
      case CHOOSE_SETUP: // Choose Setup
       mParent->ToPage(&mParent->chooseSetupPage);
       break;
      case HALL_OF_FAME: // Hall of Fame
        mParent->ToPage(&mParent->hallOfFamePage);
        break;
      // case ONLINE_SCORE: // Hall of Fame [On Line]
      //   mParent->ToPage(&mParent->hallOfFamePageOnLine);
      //   break;
      case OPTIONS: // Options
        // mParent->ToPage(&mParent->optionsPage);
        mParent->ToPage(&mParent->gsOptionsPage);
        break;
      // case WRITE_SETUP: // Write setup
      //   mParent->GetSetup()->WriteSetup();
      //   startWriteTime = fTime;
      //   break;
      // case DEMO: // Demo mode
      //   exitValue = 7;
      //   break;
      case PRACTICE: // Practice mode
        exitValue = 8;
        break;
      case CREDITS: // Credits
        mParent->ToPage(&mParent->creditsPage);
        break;
      case QUIT: // Quit
        exitValue = 100;
        break;
    }
    keys[SDLK_RETURN] = 0;
  }

  // if( keys[SDLK_ESCAPE]) {
  //   exitValue = 100;
  //   keys[SDLK_ESCAPE] = 0;
  //   // keys[SDLK_e] = 0;
  // }

  return exitValue;
}

