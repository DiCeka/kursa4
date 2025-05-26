#pragma once
#include <iostream>
#include "Structs.h"
#include "Constants.h"
#include "SDL.h"
#include "SDL_mixer.h"
#include "Textures.h"
#include "Sounds.h"
#include "Logic.h"
using namespace std;

void initCrates(cell** Crates, int lvl);

void drawCrates(cell** Crates);

bool ishit(SDL_Rect rect, int x, int y);

void drawlevels(numsTex* Arr);

bool ActionLevels(numsTex* Arr);

void ActionBranches(cell** Crates, bool click);

void Rotate(bool Arr[4]);

bool CheckActiveBranches(cell** Crates, int i, int j);

void ActivationFromRoot(cell** Crates, int i, int j, int dir);

void RefreshBranches(cell** Crates);

void TurnOffAllBranches(cell** Crates);	

bool CheckAround(cell** Crates, int i, int j);

bool CheckUp(cell** Crates, int i, int j);
bool CheckRight(cell** Crates, int i, int j);
bool CheckDown(cell** Crates, int i, int j);
bool CheckLeft(cell** Crates, int i, int j);

void ActivateAll(cell** Crates);

void CountActiveFlowers(cell** Crates);

void SelectAnimation(cell** Crates);