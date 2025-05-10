#include "GraphTools.h"



void initCrates(cell** Crates, SDL_Texture* texture, int numW, int numH)
{
	for (int i = 0; i < numW; i++)
	{
		for (int j = 0; j < numH; j++)
		{
			Crates[i][j].rect = {WindX + j * CRATESIZE, WindY + i * CRATESIZE, CRATESIZE, CRATESIZE};
			Crates[i][j].texture = texture;
			Crates[i][j].texturetype = 0;
		}
	}
}

void drawCrates(SDL_Renderer*& renderer, cell** Crates, int numW, int numH)
{
	for (int i = 0; i < numW; i++)
	{
		for (int j = 0; j < numH; j++)
		{
			SDL_RenderCopy(renderer, Crates[i][j].texture, NULL, &Crates[i][j].rect);
		}
	}
}

bool ishit(SDL_Rect rect, int x, int y)
{
	if (rect.x <= x && x <= (rect.x + rect.w))
		if (rect.y <= y && y <= (rect.y + rect.h))
			return true;
	return false;
}
