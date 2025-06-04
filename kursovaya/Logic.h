#pragma once
#include "Constants.h"
#include "ArrayTools.h"
#include "Sounds.h"
#include "GraphTools.h"

void PlaySound(Mix_Chunk* sound, int volume = 128);

void ChangeState(int _state_);

void ResetKeyNavig();

void NeedTo_();

void RestartLevel();

void GoToClosestRect(SDL_Rect* Rects, SDL_Rect &CurrentRect, int dir);

double DistanceBetwRects(SDL_Rect Rect1, SDL_Rect Rect2);

SDL_Point CenterOfRect(SDL_Rect rect);

bool EqualRects(SDL_Rect rect1, SDL_Rect rect2);

// ФУНКЦИОНАЛ КНОПОК:

void CTAPTfunc();
void Mutefunc();
void Musicfunc();
void Returnfunc(int _state_);
void Restartfunc();
void Cheatfunc();
void Nextfunc();
void NextInfinityfunc();

void InfinityFunc();
// от buttonCLick, функция которая проверяет, нажата ли какая-либо из работающих клавиш
bool ButCl();

void CratesClear(cell** Crates);

void SpawnNextBranch(cell** Crates, int H, int W, int dir);

bool IsClearInDir(cell** Crates, int H, int W, int dir);

bool IsFieldFilled(cell** Crates);

int CountWays(cell cel);

int SearchOneWay(cell cel);

void RandomizeRotates(cell** Crates);

void IncreaseInfLevels();