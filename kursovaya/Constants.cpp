#pragma once
#include "Constants.h"

SDL_Window* window = SDL_CreateWindow(u8"Ветки",
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1,
	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

SDL_Rect Windrect = { WindX, WindY, WindW, WindH };

int numWcells = 5;
int numHcells = 5;

int CRATESIZE = WindW / numWcells;

int mouseX = 0, mouseY = 0;

SDL_Event event = { 0 };

int state = 0;

int lvl = 0;


bool muteMUTED = false;
bool musicMUTED = false;

bool NeedToChangeConsole = true;

bool NeedToRefreshCrates = true;

int TexturesLvl1[5][5] = {
	{5, 5, 3, 1, 5},
	{1, 0, 2, 2, 0},
	{1, 0, 0, 3, 5},
	{3, 3, 1, 2, 0},
	{6, 2, 1, 1, 5}
};

//int TexturesLvl1[5][5] = {
//	{2, 2, 2, 2, 6},
//	{1, 1, 1, 1, 1},
//	{1, 1, 1, 1, 1},
//	{1, 1, 1, 1, 1},
//	{5, 2, 2, 2, 2}
//};

int RotatesLvl1[5][5] = {
	{0, 3, 1, 1, 1},
	{0, 0, 3, 1, 0},
	{0, 0, 0, 0, 1},
	{3, 1, 1, 2, 0},
	{1, 0, 0, 0, 0}
};


