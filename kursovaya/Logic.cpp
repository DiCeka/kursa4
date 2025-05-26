#include "Logic.h"

void PlaySound(Mix_Chunk* sound)
{
	if (!muteMUTED) Mix_PlayChannel(-1, sound, 0);
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
	PlaySound(whooshes[0]);
	int min_dY = 10000, min_dX = 10000, ind = -1, indZ = -1;
	int Ccur_X = CenterOfRect(CurrentRect).x;
	int Ccur_Y = CenterOfRect(CurrentRect).y;
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
			if (dX <= 75)
			{
				if (DistanceBetwRects(CurrentRect, Rects[i]) < DistanceBetwRects(CurrentRect, Rects[ind])) ind = i;
			}
			if (dX < min_dX) { min_dY = dX; indZ = i; }
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

			if (dY <= 70)
			{
				if (DistanceBetwRects(CurrentRect, Rects[i]) < DistanceBetwRects(CurrentRect, Rects[ind])) ind = i;
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
			if (dX <= 75) 
			{
				if (DistanceBetwRects(CurrentRect, Rects[i]) < DistanceBetwRects(CurrentRect, Rects[ind])) ind = i;
			}
			if (dX < min_dX) { min_dY = dX; indZ = i; }
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
			if (dY <= 70)
			{
				if (DistanceBetwRects(CurrentRect, Rects[i]) < DistanceBetwRects(CurrentRect, Rects[ind])) ind = i;
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
	if (ind > -1) CurrentRect = Rects[ind];
	else if(ind == -1 && indZ != -1) CurrentRect = Rects[indZ];
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
void Returnfunc()
{
	ChangeState(state-1); 
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