#pragma once
#include "SDL.h"
#include "Structs.h"
#include "ImporterTools.h"
#include "Textures.h"
#include "ArrayTools.h"
#define SPRITES_FOLDER "sprites/"

extern bool DeveloperMode;

extern bool AnimationIsON;

extern int AnimationSpeed;

extern SDL_Window* window;
extern SDL_Renderer* renderer;
extern SDL_Rect Windrect;

extern 	cell** Crates;

extern int numWcells;
extern int numHcells;

extern int CRATESIZE;

extern int mouseX, mouseY;

extern SDL_Event event;

const int M = 10;

const int HEIGHT = 800;
const int WIDTH = 960;

const int WindX = 180;
const int WindY = 130;
const int WindYd = 70;

//const int WindW = WIDTH - WindX * 2;
const int WindH = HEIGHT - WindY - WindYd;
const int WindW = WindH;
// 600x600 размер окна

extern int state;

extern int lvl;

extern bool muteMUTED;
extern bool musicMUTED;

extern bool GamePaused;

extern bool NeedToChangeConsole;

extern bool NeedToRefreshCrates;

extern bool NeedToGenerateLevel;

extern bool KeyNavigation;

extern int LvlSizes[11];

extern int TexturesLvls[10][8][8];

extern int RotatesLvl1[5][5];

extern bool WIN;

extern int CntFlowers;

extern int cnt;

extern int Pro3;

extern bool FP;

extern bool IsFirstCycle;	

extern bool lvlcompleted[11];

extern int ProZR;

extern int RectsSize;
extern SDL_Rect* Rects;
extern SDL_Rect CurrentRect;
extern int CurRectInd;

extern int ArrSpeedOfAnim[6];
// РАЗБРОС ПРИ ПОИСКЕ БЛИЖАЙШЕГО РЕКТА
extern int spread;

extern int InfinityDifficulty;
extern int NumOfCompletedInfLevels;


//extern numsTex ArrNums[10];

// Загрузка музыки
//Mix_Music* fon = Mix_LoadMUS("music1.wav");
// Mix_Chunk * sound = Mix_LoadWAV("boop.wav");

// запуск //музыки
//Mix_PlayMusic(fon, -1);
// Mix_PlayChannel(-1, sound, 0);

