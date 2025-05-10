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

//void LvlsArrInit()
//{
//	int X = 70 - 160;
//	for (int i = 0; i < 10; i++)
//	{
//		X += 16 * M;
//		if (X > 800) X = 50;
//		ArrNums[i].rect.w = 16 * M;
//		ArrNums[i].rect.h = 16 * M;
//		ArrNums[i].rect.x = X;
//		if (i < 5) ArrNums[i].rect.y = 50 + 16 * M * 1.5;
//		else ArrNums[i].rect.y = 50 + 16 * M * 2.5 + M;
//
//		switch (i)
//		{
//		case 0: { ArrNums[i].texture = _1; ArrNums[i].textureSelected = _1s; break; }
//		case 1: { ArrNums[i].texture = _2; ArrNums[i].textureSelected = _2s; break; }
//		case 2: { ArrNums[i].texture = _3; ArrNums[i].textureSelected = _3s; break; }
//		case 3: { ArrNums[i].texture = _4; ArrNums[i].textureSelected = _4s; break; }
//		case 4: { ArrNums[i].texture = _5; ArrNums[i].textureSelected = _5s; break; }
//		case 5: { ArrNums[i].texture = _6; ArrNums[i].textureSelected = _6s; break; }
//		case 6: { ArrNums[i].texture = _7; ArrNums[i].textureSelected = _7s; break; }
//		case 7: { ArrNums[i].texture = _8; ArrNums[i].textureSelected = _8s; break; }
//		case 8: { ArrNums[i].texture = _9; ArrNums[i].textureSelected = _9s; break; }
//		case 9: { ArrNums[i].texture = _0; ArrNums[i].textureSelected = _0s; break; }
//		}
//		X += 10;
//	}
//}
//numsTex ArrNums[10];

