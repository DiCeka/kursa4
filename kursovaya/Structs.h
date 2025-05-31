#pragma once
#include "SDL.h"

struct cell
{
	int texturetype;
	SDL_Texture* texture;
	SDL_Rect rect;
	int rotation;
	bool IsActive;
	int IsAnimating;
	bool ways[4] = {0};
};

struct numsTex
{
	SDL_Texture* texture;
	SDL_Texture* textureSelected;
	SDL_Rect rect;
};

