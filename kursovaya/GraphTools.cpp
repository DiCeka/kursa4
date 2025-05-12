#pragma once
#include "GraphTools.h"



void initCrates(cell** Crates)
{

	for (int i = 0; i < numWcells; i++)
	{
		for (int j = 0; j < numHcells; j++)
		{

			Crates[i][j].rect = {WindX + j * CRATESIZE, WindY + i * CRATESIZE, CRATESIZE, CRATESIZE};
			Crates[i][j].texturetype = TexturesLvl1[i][j];
			Crates[i][j].IsActive = 0;
			for (int k = 0; k < 4; k++)
				Crates[i][j].ways[k] = 0;
			switch (Crates[i][j].texturetype)
			{
			case 0: Crates[i][j].texture = none; break;
			case 1: 
			{ 
				Crates[i][j].texture = br1na; 
				Crates[i][j].ways[0] = 1;
				Crates[i][j].ways[2] = 1;
				break; 
			}
			case 2: 
			{ 
				Crates[i][j].texture = br2na; 
				Crates[i][j].ways[1] = 1;
				Crates[i][j].ways[2] = 1;
				break; 
			}
			case 3: 
			{ 
				Crates[i][j].texture = br3na; 
				Crates[i][j].ways[0] = 1;
				Crates[i][j].ways[1] = 1;
				Crates[i][j].ways[2] = true;
				break; 
			}
			case 4: 
			{
				Crates[i][j].texture = br4na; 
				Crates[i][j].ways[0] = 1;
				Crates[i][j].ways[1] = 1;
				Crates[i][j].ways[2] = 1;
				Crates[i][j].ways[3] = 1;
				break;
			}
			case 5: 
			{ 
				Crates[i][j].texture = brFlowerna; 
				Crates[i][j].ways[2] = 1;
				break; 
			}
			case 6: 
			{ 
				Crates[i][j].texture = brRoot; 
				Crates[i][j].IsActive = 1; 
				Crates[i][j].ways[2] = 1;
				break; }
			}
			Crates[i][j].rotation = RotatesLvl1[i][j];
			for (int h = 0; h < Crates[i][j].rotation; h++) Rotate(Crates[i][j].ways);
		}
	}
}

void drawCrates(cell** Crates)
{
	if (NeedToRefreshCrates)
	{
		for (int i = 0; i < numWcells; i++)
		{
			for (int j = 0; j < numHcells; j++)
			{
				switch (Crates[i][j].texturetype)
				{
				case 0: break;
				case 1:
				{
					if (Crates[i][j].IsActive) Crates[i][j].texture = br1ya;
					else Crates[i][j].texture = br1na;
					break;
				}
				case 2:
				{
					if (Crates[i][j].IsActive) Crates[i][j].texture = br2ya;
					else Crates[i][j].texture = br2na;
					break;
				}
				case 3:
				{
					if (Crates[i][j].IsActive) Crates[i][j].texture = br3ya;
					else Crates[i][j].texture = br3na;
					break;
				}
				case 4:
				{
					if (Crates[i][j].IsActive) Crates[i][j].texture = br4ya;
					else Crates[i][j].texture = br4na;
					break;
				}
				case 5:
				{
					if (Crates[i][j].IsActive) Crates[i][j].texture = brFlower;
					else Crates[i][j].texture = brFlowerna;
					break;
				}
				case 6: Crates[i][j].texture = brRoot; break;
				}
			}
		}
	}
	NeedToRefreshCrates = 0;

	for (int i = 0; i < numWcells; i++)
	{
		for (int j = 0; j < numHcells; j++)
		{
			SDL_RenderCopyEx(renderer, Crates[i][j].texture, NULL, &Crates[i][j].rect, Crates[i][j].rotation * 90, NULL, SDL_FLIP_NONE);
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

void PlaySound(Mix_Chunk* sound, bool MUTED)
{
	if (!MUTED) Mix_PlayChannel(-1, sound, 0);
}

void drawlevels(numsTex* Arr)
{
	//if (ishit(returnRect, mouseX, mouseY)) SDL_RenderCopy(renderer, returnSelectedTexture, NULL, &returnRect);
	for (int i = 0; i < 10; i++)
	{
		if (ishit(Arr[i].rect, mouseX, mouseY)) SDL_RenderCopy(renderer, Arr[i].textureSelected, NULL, &Arr[i].rect);
		else SDL_RenderCopy(renderer, Arr[i].texture, NULL, &Arr[i].rect);
	}
}

bool ActionLevels(numsTex* Arr)
{
	for (int i = 0; i < 10; i++)
	{
		if (ishit(Arr[i].rect, event.button.x, event.button.y)) { lvl = i + 1; return 1; }
	}
	return 0;
}

void ActionBranches(cell** Crates)
{
	for (int i = 0; i < numWcells; i++)
	{
		for (int j = 0; j < numHcells; j++)
		{
			if (ishit(Crates[i][j].rect, event.button.x, event.button.y))
			{
				Crates[i][j].rotation = (Crates[i][j].rotation+1)%4;
				Rotate(Crates[i][j].ways);


				TurnOffAllBranches(Crates);

				for (int ii = 0; ii < numWcells; ii++)
				{
					for (int jj = 0; jj < numHcells; jj++)
					{
						if (Crates[ii][jj].texturetype == 6) ActivationFromRoot(Crates, ii, jj, (Crates[ii][jj].rotation+2)%4);
					}
				}
			}
			

			//if (CheckActiveBranches(Crates, i, j)) Crates[i][j].IsActive = 1;
			//else Crates[i][j].IsActive = 0;
			NeedTo_();
		}
	}
}

void RefreshBranches(cell** Crates)
{
	for (int i = 0; i < numWcells; i++)
	{
		for (int j = 0; j < numHcells; j++)
		{
			TurnOffAllBranches(Crates);
			for (int ii = 0; ii < numWcells; ii++)
			{
				for (int jj = 0; jj < numHcells; jj++)
				{
					if (Crates[ii][jj].texturetype == 6) ActivationFromRoot(Crates, ii, jj, (Crates[ii][jj].rotation + 2) % 4);
				}
			}
			NeedTo_();
		}
	}
}

void TurnOffAllBranches(cell** Crates)
{
	for (int i = 0; i < numWcells; i++)
	{
		for (int j = 0; j < numHcells; j++)
		{
			if (Crates[i][j].texturetype == 0) continue;
			if (Crates[i][j].texturetype == 6) continue;
			Crates[i][j].IsActive = 0;
		}
	}
}

void Rotate(bool Arr[4])
{
	bool d = Arr[3];
	for (int i = 3; i > 0; i--)
	{
		Arr[i] = Arr[i - 1];
	}
	Arr[0] = d;
}

void NeedTo_()
{
	NeedToChangeConsole = 1; 
	NeedToRefreshCrates = 1;
}

bool CheckActiveBranches(cell** Crates, int i, int j)
{
	bool NeedToActive = false;

	if (Crates[i][j].texturetype == 0) return false; // Пустота
	if (Crates[i][j].texturetype == 6) return true; // Корень

	if (i != 0)
	{
		if (Crates[i][j].ways[0] == 1 && Crates[i - 1][j].ways[2] == 1 && Crates[i - 1][j].IsActive == 1)
		{
			return true;
		}
	}
	if (j != numWcells - 1)
	{
		if (Crates[i][j].ways[1] == 1 && Crates[i][j + 1].ways[3] == 1 && Crates[i][j + 1].IsActive)
		{
			return true;
		}
	}
	if (i != numHcells - 1)
	{
		if (Crates[i][j].ways[2] == 1 && Crates[i + 1][j].ways[0] == 1 && Crates[i + 1][j].IsActive == 1)
		{
			return true;
		}
	}
	if (j != 0)
	{
		if (Crates[i][j].ways[3] == 1 && Crates[i][j - 1].ways[1] == 1 && Crates[i][j - 1].IsActive == 1)
		{
			return true;
		}
	}
	return false;
}

void ActivationFromRoot(cell** Crates, int i, int j, int dir)
{
	switch (dir)
	{
	case 0:
	{
		if (CheckUp(Crates, i, j))
		{
			Crates[i - 1][j].IsActive = 1;
			for (int k = 0; k < 4; k++)
			{
				if (k == 2) continue; // 2(нижний) проверять не надо. Мы пришли отсюда
				if (Crates[i - 1][j].ways[k]) ActivationFromRoot(Crates, i - 1, j, k);
			}
		}
		break;
	}
	case 1:
	{
		if (CheckRight(Crates, i, j))
		{
			Crates[i][j + 1].IsActive = 1;
			for (int k = 0; k < 4; k++)
			{
				if (k == 3) continue;
				if (Crates[i][j + 1].ways[k]) ActivationFromRoot(Crates, i, j + 1, k);
			}
		}
		break;
	}
	case 2:
	{
		if (CheckDown(Crates, i, j))
		{
			Crates[i + 1][j].IsActive = 1;
			for (int k = 0; k < 4; k++)
			{
				if (k == 0) continue;
				if (Crates[i + 1][j].ways[k]) ActivationFromRoot(Crates, i + 1, j, k);
			}
		}
		break;
	}
	case 3:
	{
		if (CheckLeft(Crates, i, j))
		{
			Crates[i][j - 1].IsActive = 1;
			for (int k = 0; k < 4; k++)
			{
				if (k == 1) continue;
				if (Crates[i][j - 1].ways[k]) ActivationFromRoot(Crates, i, j - 1, k);
			}
		}
		break;
	}
	}
}

bool CheckAround(cell** Crates, int i, int j)
{
	if (Crates[i][j].texturetype == 0) return false;


	if (CheckUp(Crates, i, j)) return true;
	if (CheckRight(Crates, i, j)) return true;
	if (CheckDown(Crates, i, j)) return true;
	if (CheckLeft(Crates, i, j)) return true;

	return false;
}

bool CheckUp(cell** Crates, int i, int j)
{
	if (i != 0)
	{
		if (Crates[i][j].ways[0])
		{
			if (Crates[i - 1][j].ways[2]) return true;
		}
	}
	return false;
}
bool CheckRight(cell** Crates, int i, int j)
{
	if (j != numWcells - 1)
	{
		if (Crates[i][j].ways[1])
		{
			if (Crates[i][j + 1].ways[3]) return true;
		}
	}
	return false;
}
bool CheckDown(cell** Crates, int i, int j)
{
	if (i != numHcells - 1)
	{
		if (Crates[i][j].ways[2])
		{
			if (Crates[i + 1][j].ways[0]) return true;
		}
	}
	return false;
}
bool CheckLeft(cell** Crates, int i, int j)
{
	if (j != 0)
	{
		if (Crates[i][j].ways[3])
		{
			if (Crates[i][j - 1].ways[1]) return true;
		}
	}
	return false;
}