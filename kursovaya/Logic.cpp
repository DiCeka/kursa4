#include "Logic.h"

void PlaySound(Mix_Chunk* sound, int volume)
{
	if (!muteMUTED)
	{
		//if (volume != 128)
		//{
		//	Mix_VolumeChunk(sound, volume);
		//	Mix_PlayChannel(-1, sound, 0);
		//	Mix_VolumeChunk(sound, 128);
		//}
		//else
			Mix_PlayChannel(-1, sound, 0);
	}
}

void ChangeState(int _state_)
{
	KeyNavigation = 0;
	IsFirstCycle = 1;
	ArrClear1D_Rect(Rects, RectsSize);
	state = _state_;
}

void ResetKeyNavig()
{
	KeyNavigation = 0;
	IsFirstCycle = 1;
	ArrClear1D_Rect(Rects, RectsSize);
}

void NeedTo_()
{
	NeedToChangeConsole = 1;
	NeedToRefreshCrates = 1;
}

void RestartLevel()
{
	GamePaused = 0;
	WIN = 0;
	NeedToGenerateLevel = 1;
	NeedToRefreshCrates = 1;
	NeedToChangeConsole = 1;
}

void GoToClosestRect(SDL_Rect* Rects, SDL_Rect& CurrentRect, int dir)
{
	int min_dY = 10000, min_dX = 10000, ind = -1, indZ = -1;
	int Ccur_X = CenterOfRect(CurrentRect).x;
	int Ccur_Y = CenterOfRect(CurrentRect).y;
	bool inSpreadFound = false;
	switch (dir)
	{
	case 0:
	{
		// ѕоиск индекса ind, на который нужно перейти
		for (int i = 0; i < RectsSize; i++)
		{
			// Ќахождение центра сравниваемого ректа(Y)
			int Ci_Y = CenterOfRect(Rects[i]).y;

			if (Ci_Y >= Ccur_Y) continue;
			int dX = abs(CurrentRect.x - Rects[i].x);

			// ƒопустимый "разброс"
			if (dX <= spread)
			{
				if (ind == -1 || DistanceBetwRects(CurrentRect, Rects[i]) < DistanceBetwRects(CurrentRect, Rects[ind])) ind = i;
				inSpreadFound = 1;
			}
			if (dX < min_dX) { min_dX = dX; indZ = i; }
			else if (dX == min_dX)
			{
				if (CenterOfRect(Rects[ind]).y < Ci_Y) indZ = i;
			}
		}

		break;
	}
	case 1:
	{
		// ѕоиск индекса ind, на который нужно перейти
		for (int i = 0; i < RectsSize; i++)
		{
			// Ќахождение центра сравниваемого ректа
			int Ci_X = CenterOfRect(Rects[i]).x;

			if (Ci_X <= Ccur_X) continue; // отсеим те, что вообще с другого направлени€

			int dY = abs(CurrentRect.y - Rects[i].y);

			if (dY <= spread)
			{
				if (ind == -1 || DistanceBetwRects(CurrentRect, Rects[i]) < DistanceBetwRects(CurrentRect, Rects[ind])) ind = i;
				inSpreadFound = 1;
			}
			if (dY < min_dY) { min_dY = dY; indZ = i; }
			else if (dY == min_dY)
			{
				if (CenterOfRect(Rects[ind]).x > Ci_X) indZ = i;
			}
		}
		break;
	}
	case 2:
	{
		// ѕоиск индекса ind, на который нужно перейти
		for (int i = 0; i < RectsSize; i++)
		{
			// Ќахождение центра сравниваемого ректа(Y)
			int Ci_Y = CenterOfRect(Rects[i]).y;

			if (Ci_Y <= Ccur_Y) continue;
			int dX = abs(CurrentRect.x - Rects[i].x);
			// ƒопустимый "разброс"
			int sprd = spread;
			if (state == 0) sprd = 320;
			if (dX <= sprd)
			{
				if (ind == -1 || DistanceBetwRects(CurrentRect, Rects[i]) < DistanceBetwRects(CurrentRect, Rects[ind])) ind = i;
				inSpreadFound = 1;
			}
			if (dX < min_dX) { min_dX = dX; indZ = i; }
			else if (dX == min_dX)
			{
				if (CenterOfRect(Rects[ind]).y > Ci_Y) indZ = i;
			}
		}
		break;
	}
	case 3:
	{
		// ѕоиск индекса ind, на который нужно перейти
		for (int i = 0; i < RectsSize; i++)
		{
			// Ќахождение центра сравниваемого ректа
			int Ci_X = CenterOfRect(Rects[i]).x;

			if (Ci_X >= Ccur_X) continue;
			int dY = abs(CurrentRect.y - Rects[i].y);
			if (dY <= spread)
			{
				if (ind == -1 || DistanceBetwRects(CurrentRect, Rects[i]) < DistanceBetwRects(CurrentRect, Rects[ind])) ind = i;
				inSpreadFound = 1;
			}
			if (dY < min_dY) { min_dY = dY; indZ = i; }
			else if (dY == min_dY)
			{
				if (CenterOfRect(Rects[ind]).x < Ci_X) indZ = i;
			}
		}
		break;
	}
	}
	if (inSpreadFound) { CurrentRect = Rects[ind]; PlaySound(whoosh); }
	else if (!inSpreadFound && indZ != -1) { CurrentRect = Rects[indZ]; PlaySound(whoosh); }
}

double DistanceBetwRects(SDL_Rect Rect1, SDL_Rect Rect2)
{
	SDL_Point center1 = CenterOfRect(Rect1);
	SDL_Point center2 = CenterOfRect(Rect2);

	return sqrt( pow( center2.x - center1.x, 2) + pow( center2.y - center1.y, 2) );
}

SDL_Point CenterOfRect(SDL_Rect rect)
{
	return { rect.x + rect.w / 2 , rect.y + rect.h / 2 };
}

bool EqualRects(SDL_Rect rect1, SDL_Rect rect2)
{
	bool f = 1;
	if (rect1.x != rect2.x || rect1.y != rect2.y)  f = 0;
	else if (rect1.w != rect2.w || rect1.h != rect2.h) f = 0;

	return f;
}

void CTAPTfunc()
{
	PlaySound(click);
	ChangeState(1);
}
void Mutefunc()
{
	muteMUTED = !muteMUTED;
}
void Musicfunc()
{
	musicMUTED = !musicMUTED;
	if (musicMUTED) Mix_VolumeMusic(0);
	else Mix_VolumeMusic(128);
}
void Returnfunc(int _state_)
{
	ChangeState(_state_); 
	PlaySound(click);
	WIN = 0;
	system("cls");
}
void Restartfunc()
{
	PlaySound(click);
	RestartLevel();
}
void Cheatfunc()
{
	PlaySound(click);
	ActivateAll(Crates);
	NeedToRefreshCrates = 1;
	NeedToChangeConsole = 1;
	drawCrates(Crates);
}
void Nextfunc()
{
	if (WIN && (1 <= lvl && lvl < 10))
	{
		PlaySound(click);
		lvl++;
		RestartLevel();
	}
}

void InfinityFunc()
{
	PlaySound(click);
	RestartLevel();
	ChangeState(3);
}

bool ButCl()
{
	if (event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w || \
		event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d || (event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s) || \
		event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a ) return 1;
	return 0;
}