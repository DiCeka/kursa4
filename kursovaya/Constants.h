#pragma once
#include "SDL.h"
#include "Structs.h"
#include "ImporterTools.h"

#define SPRITES_FOLDER "sprites/"

const int M = 10;

const int HEIGHT = 800;
const int WIDTH = 960;

const int WindX = 180;
const int WindY = 125;
const int WindYd = 75;

//const int WindW = WIDTH - WindX * 2;
const int WindH = HEIGHT - WindY - WindYd;
const int WindW = WindH;
// 600x600 размер окна

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Rect Windrect;


extern int numWcells;
extern int numHcells;

const SDL_Rect WINDOWrect = { 0, 0, WIDTH, HEIGHT};
const SDL_Rect BG2rect = { -250, 0, 1334, HEIGHT };

//const int CRATESIZE = WindW / numWcells;
extern int CRATESIZE;

const SDL_Rect MainText = {75, 200, WIDTH - WindX*2, 170};

extern int mouseX, mouseY;

extern SDL_Event event;

extern int state;

extern int lvl;

extern bool muteMUTED;
extern bool musicMUTED;

extern bool NeedToChangeConsole;

extern bool NeedToRefreshCrates;

extern int TexturesLvl1[5][5];

extern int RotatesLvl1[5][5];



//extern numsTex ArrNums[10];

// «агрузка музыки
//Mix_Music* fon = Mix_LoadMUS("music1.wav");
// Mix_Chunk * sound = Mix_LoadWAV("boop.wav");

// запуск //музыки
//Mix_PlayMusic(fon, -1);
// Mix_PlayChannel(-1, sound, 0);

