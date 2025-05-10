#include "Constants.h"

SDL_Window* window = SDL_CreateWindow(u8"Ветки",
	SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
	WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
SDL_Rect Windrect = { WindX, WindY, WindW, WindH };

int numWcells = 5;
int numHcells = 5;

int CRATESIZE = WindW / numWcells;
