#pragma once
#include "SDL.h"

struct cell
{
	int texturetype;
	SDL_Texture* texture;
	SDL_Rect rect;	
};

struct numsTex
{
	SDL_Texture* texture;
	SDL_Texture* textureSelected;
	SDL_Rect rect;
};

