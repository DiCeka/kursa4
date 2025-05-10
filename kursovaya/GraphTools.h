#pragma once
#include "Structs.h"
#include "Constants.h"

void initCrates(cell** Crates, SDL_Texture* CrateTexture, int numW, int numH);

void drawCrates(SDL_Renderer*& renderer, cell** Crates, int numW, int numH);


bool ishit(SDL_Rect rect, int x, int y);