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
		// Поиск индекса ind, на который нужно перейти
		for (int i = 0; i < RectsSize; i++)
		{
			// Нахождение центра сравниваемого ректа(Y)
			int Ci_Y = CenterOfRect(Rects[i]).y;

			if (Ci_Y >= Ccur_Y) continue;
			int dX = abs(CurrentRect.x - Rects[i].x);

			// Допустимый "разброс"
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
		// Поиск индекса ind, на который нужно перейти
		for (int i = 0; i < RectsSize; i++)
		{
			// Нахождение центра сравниваемого ректа
			int Ci_X = CenterOfRect(Rects[i]).x;

			if (Ci_X <= Ccur_X) continue; // отсеим те, что вообще с другого направления

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
		// Поиск индекса ind, на который нужно перейти
		for (int i = 0; i < RectsSize; i++)
		{
			// Нахождение центра сравниваемого ректа(Y)
			int Ci_Y = CenterOfRect(Rects[i]).y;

			if (Ci_Y <= Ccur_Y) continue;
			int dX = abs(CurrentRect.x - Rects[i].x);
			// Допустимый "разброс"
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
		// Поиск индекса ind, на который нужно перейти
		for (int i = 0; i < RectsSize; i++)
		{
			// Нахождение центра сравниваемого ректа
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
void NextInfinityfunc()
{
	Restartfunc();
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

void CratesClear(cell** Crates)
{
	//numHcells = numWcells = 3+(rand()%6);
	numHcells = numWcells = 3 + InfinityDifficulty;
	CRATESIZE = WindW / numWcells;
	for (int i = 0; i < numWcells; i++)
	{
		for (int j = 0; j < numHcells; j++)
		{
			Crates[i][j].IsActive = 0;
			Crates[i][j].IsAnimating = 0;
			Crates[i][j].rect = { WindX + j * CRATESIZE, WindY + i * CRATESIZE, CRATESIZE, CRATESIZE };
			Crates[i][j].rotation = 0;
			Crates[i][j].texture = 0;
			Crates[i][j].texturetype = 0;
			for (int k = 0; k < 4; k++) Crates[i][j].ways[k] = 0;
			SetTexturesAndWays(Crates[i][j]);
		}
	}
}

void SpawnNextBranch(cell** Crates, int H, int W, int dir)
{
	// Находим координаты нашей ветки
	int h = H, w = W;
	switch (dir)
	{
	case 0: { h--; break; }
	case 1: { w++; break; }
	case 2: { h++; break; }
	case 3: { w--; break; }
	}


	//         ПРОВЕРЯЕМ СВОБОДНОСТЬ СТОРОН:
	
	// ОТБИРАЕМ ВОЗМОЖНЫЕ СТОРОНЫ
	int sSid = 0;
	int* Sides = ArrCreate1D_int(sSid);

	for (int i = 0; i < 4; i++)
	{
		if (i == (dir + 2) % 4) continue; // Мы отсюда пришли
		if (IsClearInDir(Crates, h, w, i)) ArrAddElement1D_int(Sides, sSid, i);
	}

	if (sSid)
	{
		int ind = rand() % sSid;
		switch (Sides[ind])
		{
		case 0:
		{
			switch (dir)
			{
			case 0: 
			{
				Crates[h][w].texturetype = 1;
				Crates[h][w].rotation = 0;
				SetTexturesAndWays(Crates[h][w]);
				SpawnNextBranch(Crates, h, w, Sides[ind]);
				break;
			}
			case 1:
			{
				Crates[h][w].texturetype = 2;
				Crates[h][w].rotation = 180;
				SetTexturesAndWays(Crates[h][w]);
				SpawnNextBranch(Crates, h, w, Sides[ind]);
				break;
			}
			case 2:
			{
				cout << "ОШИБКА!!!! ПОПЫТКА ЗАСПАВНИТЬ ТАМ, ОТКУДА ПРИШЛИ!!!!!!!!\n";
				break;
			}
			case 3:
			{
				Crates[h][w].texturetype = 2;
				Crates[h][w].rotation = 270;
				SetTexturesAndWays(Crates[h][w]);
				SpawnNextBranch(Crates, h, w, Sides[ind]);
				break;
			}
			}
			break;
		}
		case 1:
		{
			switch (dir)
			{
			case 0: // Корень снизу
			{
				Crates[h][w].texturetype = 2;
				Crates[h][w].rotation = 0;
				SetTexturesAndWays(Crates[h][w]);
				SpawnNextBranch(Crates, h, w, Sides[ind]);
				break;
			}
			case 1: // Корень слева
			{
				Crates[h][w].texturetype = 1;
				Crates[h][w].rotation = 90;
				SetTexturesAndWays(Crates[h][w]);
				SpawnNextBranch(Crates, h, w, Sides[ind]);
				break;
			}
			case 2: // Корень сверху
			{
				Crates[h][w].texturetype = 2;
				Crates[h][w].rotation = 270;
				SetTexturesAndWays(Crates[h][w]);
				SpawnNextBranch(Crates, h, w, Sides[ind]);
				break;
			}
			case 3: // Корень справа
			{
				cout << "ОШИБКА!!!! ПОПЫТКА ЗАСПАВНИТЬ ТАМ, ОТКУДА ПРИШЛИ!!!!!!!!\n";
				break;
			}
			}
			break;
		}
		case 2:
		{
			switch (dir)
			{
			case 0:
			{
				cout << "ОШИБКА!!!! ПОПЫТКА ЗАСПАВНИТЬ ТАМ, ОТКУДА ПРИШЛИ!!!!!!!!\n";
				break;
			}
			case 1:
			{
				Crates[h][w].texturetype = 2;
				Crates[h][w].rotation = 90;
				SetTexturesAndWays(Crates[h][w]);
				SpawnNextBranch(Crates, h, w, Sides[ind]);
				break;
			}
			case 2:
			{
				Crates[h][w].texturetype = 1;
				Crates[h][w].rotation = 0;
				SetTexturesAndWays(Crates[h][w]);
				SpawnNextBranch(Crates, h, w, Sides[ind]);
				break;
			}
			case 3:
			{
				Crates[h][w].texturetype = 2;
				Crates[h][w].rotation = 0;
				SetTexturesAndWays(Crates[h][w]);
				SpawnNextBranch(Crates, h, w, Sides[ind]);
				break;
			}
			}
			break;
		}
		case 3:
		{
			switch (dir)
			{
			case 0:
			{
				Crates[h][w].texturetype = 2;
				Crates[h][w].rotation = 90;
				SetTexturesAndWays(Crates[h][w]);
				SpawnNextBranch(Crates, h, w, Sides[ind]);
				break;
			}
			case 1:
			{
				cout << "ОШИБКА!!!! ПОПЫТКА ЗАСПАВНИТЬ ТАМ, ОТКУДА ПРИШЛИ!!!!!!!!\n";
				break;
			}
			case 2:
			{
				Crates[h][w].texturetype = 2;
				Crates[h][w].rotation = 180;
				SetTexturesAndWays(Crates[h][w]);
				SpawnNextBranch(Crates, h, w, Sides[ind]);
				break;
			}
			case 3:
			{
				Crates[h][w].texturetype = 1;
				Crates[h][w].rotation = 90;
				SetTexturesAndWays(Crates[h][w]);
				SpawnNextBranch(Crates, h, w, Sides[ind]);
				break;
			}
			}
			break;
		}
		}
	}
	else // ЕСЛИ ВЫХОДА НЕТ ТО СПАВН ЦВЕТКА
	{
		Crates[h][w].texturetype = 5;
		Crates[h][w].rotation = dir*90;
		SetTexturesAndWays(Crates[h][w]);
	}

	delete[] Sides;
}

bool IsClearInDir(cell** Crates, int H, int W, int dir)
{
	bool Clear = 1;
	switch (dir)
	{
	case 0:
	{
		if ((H - 1) < 0) Clear = 0;
		else if (Crates[H-1][W].texturetype != 0) Clear = 0;
		break;
	}
	case 1:
	{
		if ((W + 1) == numWcells) Clear = 0;
		else if (Crates[H][W+1].texturetype != 0) Clear = 0;
		break;
	}
	case 2:
	{
		if ((H+1) == numHcells) Clear = 0;
		else if (Crates[H+1][W].texturetype != 0) Clear = 0;
		break;
	}
	case 3:
	{
		if ((W - 1) < 0) Clear = 0;
		else if (Crates[H][W - 1].texturetype != 0) Clear = 0;
		break;
	}
	}

	return Clear;
}

bool IsFieldFilled(cell** Crates)
{
	for (int i = 0; i < numWcells; i++)
	{
		for (int j = 0; j < numHcells; j++)
		{
			if (Crates[i][j].texturetype == 0) return 0;
		}
	}
	return 1;
}

int CountWays(cell cel)
{
	cnt = 0;
	for (int i = 0; i < 4; i++) if (cel.ways[i]) cnt++;

	return cnt;
}

int SearchOneWay(cell cel)
{
	for (int i = 0; i < 4; i++) if (cel.ways[i]) return i;
}

void RandomizeRotates(cell** Crates)
{
	for (int i = 0; i < numWcells; i++)
	{
		for (int j = 0; j < numHcells; j++)
		{
			int r = (rand() % 4);
			Crates[i][j].rotation = (Crates[i][j].rotation + r * 90) % 360;
			for (int k = 0; k < r; k++) Rotate(Crates[i][j].ways);
		}
	}
}