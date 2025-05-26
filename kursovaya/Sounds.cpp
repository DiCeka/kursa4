#pragma once
#include "Sounds.h"


Mix_Chunk* whooshes[6] = { nullptr };
Mix_Music* tracks[3] = { nullptr };
Mix_Chunk* click = nullptr;
Mix_Music* fon1 = nullptr;
Mix_Music* fon2 = nullptr;
Mix_Music* fon3 = nullptr;
Mix_Chunk* winsound = nullptr;
Mix_Chunk* whoosh = nullptr;

void initSounds()
{
	click = Mix_LoadWAV("click.wav");
	fon1 = Mix_LoadMUS("Swimming.wav");
	fon2 = Mix_LoadMUS("Lluvia.wav");
	fon3 = Mix_LoadMUS("Gymnopedie.wav");
	whoosh = Mix_LoadWAV("whoosh.wav");
	tracks[0] = fon1;
	tracks[1] = fon2;
	tracks[2] = fon3;

	winsound = Mix_LoadWAV("winsound.wav");

	const char* filenames[6] = {
	"whoosh1.wav",
	"whoosh2.wav",
	"whoosh3.wav",
	"whoosh4.wav",
	"whoosh5.wav",
	"whoosh6.wav"
	};

	for (int i = 0; i < 6; ++i)
		whooshes[i] = Mix_LoadWAV(filenames[i]);
}

void freeSounds() 
{
	Mix_FreeChunk(click);
	Mix_FreeChunk(winsound);
	Mix_FreeChunk(whoosh);
	Mix_FreeMusic(fon1);
	Mix_FreeMusic(fon2);
	Mix_FreeMusic(fon3);


	for (int i = 0; i < 6; ++i) {
		Mix_FreeChunk(whooshes[i]);
		//whooshes[i] = nullptr;
	}
}