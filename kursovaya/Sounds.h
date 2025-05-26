#pragma once
#include "SDL.h"
#include "Constants.h"
#include "SDL_mixer.h"

extern Mix_Chunk* whooshes[6];
extern Mix_Music* tracks[3];
extern Mix_Chunk* click;
extern Mix_Music* fon1;
extern Mix_Music* fon2;
extern Mix_Music* fon3;
extern Mix_Chunk* winsound;
extern Mix_Chunk* whoosh;

void initSounds();
void freeSounds();
