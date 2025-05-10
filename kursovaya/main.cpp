#include "Constants.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "SDL_mixer.h"
#include "SDL_ttf.h"
#include <string>
#include "ImporterTools.h"
#include "Structs.h"
#include "ArrayTools.h"
#include "GraphTools.h"


#pragma comment(lib, "SDL2_mixer.lib")

using namespace std;

bool ActionLevels(numsTex* Arr)
{
	for (int i = 0; i < 10; i++)
	{
		if (ishit(Arr[i].rect, event.button.x, event.button.y)) { lvl = i + 1; return 1; }
	}
	return 0;
}

// çàãðóçêà òåêñòóð
//
SDL_Texture* BGtextureGame1 = createTexture("fon2.bmp");
SDL_Texture* BGtextureMenu1 = createTexture("fon3.bmp");
SDL_Texture* cratetexture = createTexture("crate.bmp");
SDL_Texture* nametexture = createTexture("BRANCHES.bmp");
SDL_Rect namerect = { 160, 200, 70 * M, 16 * M };
SDL_Texture* CTAPTtexture = createTexture("CTAPT.bmp");
SDL_Texture* CTAPTselectedtexture = createTexture("CTAPTselected.bmp");
SDL_Rect CTAPTrect = { 26 * M, 20 * M + 20 * M, 50 * M, 16 * M };
SDL_Texture* frametexture = createTexture("frame68.bmp", true);
SDL_Rect framerect = { 140, 85, 68 * M, 68 * M };
SDL_Texture* BGtexture3 = createTexture("bg3.bmp", true);
SDL_Texture* returnTexture = createTexture("return.bmp", true);
SDL_Texture* returnSelectedTexture = createTexture("returnSelected.bmp", true);
SDL_Rect returnRect = { 30, 30, 16 * M, 16 * M };
//
SDL_Texture* br1na = createTexture("br1na.bmp", 1);
SDL_Texture* br1ya = createTexture("br1ya.bmp", 1);
SDL_Texture* br2na = createTexture("br2na.bmp", 1);
SDL_Texture* br2ya = createTexture("br2ya.bmp", 1);
SDL_Texture* br3na = createTexture("br3na.bmp", 1);
SDL_Texture* br3ya = createTexture("br3ya.bmp", 1);
SDL_Texture* br4na = createTexture("br4na.bmp", 1);
SDL_Texture* br4ya = createTexture("br4ya.bmp", 1);
SDL_Texture* brRoot = createTexture("brRoot.bmp", 1);
SDL_Texture* brFlowerOpened = createTexture("brFlowerOpened.bmp", 1);
SDL_Texture* brFlowerClosed = createTexture("brFlowerClosed.bmp", 1);
//
SDL_Texture* _0 = createTexture("0.bmp");
SDL_Texture* _0s = createTexture("0s.bmp");
SDL_Texture* _1 = createTexture("1.bmp");
SDL_Texture* _1s = createTexture("1s.bmp");
SDL_Texture* _2 = createTexture("2.bmp");
SDL_Texture* _2s = createTexture("2s.bmp");
SDL_Texture* _3 = createTexture("3.bmp");
SDL_Texture* _3s = createTexture("3s.bmp");
SDL_Texture* _4 = createTexture("4.bmp");
SDL_Texture* _4s = createTexture("4s.bmp");
SDL_Texture* _5 = createTexture("5.bmp");
SDL_Texture* _5s = createTexture("5s.bmp");
SDL_Texture* _6 = createTexture("6.bmp");
SDL_Texture* _6s = createTexture("6s.bmp");
SDL_Texture* _7 = createTexture("7.bmp");
SDL_Texture* _7s = createTexture("7s.bmp");
SDL_Texture* _8 = createTexture("8.bmp");
SDL_Texture* _8s = createTexture("8s.bmp");
SDL_Texture* _9 = createTexture("9.bmp");
SDL_Texture* _9s = createTexture("9s.bmp");
//
SDL_Texture* mute = createTexture("mute.bmp");
SDL_Texture* muteSelected = createTexture("muteSelected.bmp");
SDL_Texture* muteMuted = createTexture("muteMuted.bmp");
SDL_Texture* muteMutedSelected = createTexture("muteMutedSelected.bmp");
SDL_Rect muteRect0 = { WIDTH - 160 - 30, 30, 16 * M, 16 * M };
//
SDL_Texture* music = createTexture("music.png");
SDL_Texture* musicSelected = createTexture("musicSelected.png");
SDL_Texture* musicMuted = createTexture("musicMuted.png");
SDL_Texture* musicMutedSelected = createTexture("musicMutedSelected.png");
SDL_Rect musicRect0 = { WIDTH - 160 * 2 - 30 * 2, 30, 16 * M, 16 * M };

int main(int args, char** argv)
{
	setlocale(LC_ALL, "ru");

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_PNG);

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);

	Mix_Init(0);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);

	// øðèôò
	TTF_Init();
	TTF_Font* my_font = TTF_OpenFont("RuneScape-ENA.ttf", 100);
	char txt[15] = "CTAPT";
	SDL_Texture * mainnameTexture = get_text_texture(renderer, txt, my_font);
	//
	// Çàãðóçêà çâóêîâ
	Mix_Music* fon = Mix_LoadMUS("Swimming.wav");
	Mix_Chunk* click = Mix_LoadWAV("click.wav");
	//

	cell** Crates = ArrCreate2D_cell(numHcells, numWcells);



	int m = 7;

	SDL_Texture** ArrTexture = (SDL_Texture**)malloc(0 * sizeof(int));

	numsTex ArrNums[10];
	int X = 70 - 160;
	for (int i = 0; i < 10; i++)
	{
		X += 16 * M;
		if (X > 800) X = 50;
		ArrNums[i].rect.w = 16 * M;
		ArrNums[i].rect.h = 16 * M;
		ArrNums[i].rect.x = X;
		if (i < 5) ArrNums[i].rect.y = 50 + 16 * M * 1.5;
		else ArrNums[i].rect.y = 50 + 16 * M * 2.5 + M;

		switch (i)
		{
		case 0: { ArrNums[i].texture = _1; ArrNums[i].textureSelected = _1s; break; }
		case 1: { ArrNums[i].texture = _2; ArrNums[i].textureSelected = _2s; break; }
		case 2: { ArrNums[i].texture = _3; ArrNums[i].textureSelected = _3s; break; }
		case 3: { ArrNums[i].texture = _4; ArrNums[i].textureSelected = _4s; break; }
		case 4: { ArrNums[i].texture = _5; ArrNums[i].textureSelected = _5s; break; }
		case 5: { ArrNums[i].texture = _6; ArrNums[i].textureSelected = _6s; break; }
		case 6: { ArrNums[i].texture = _7; ArrNums[i].textureSelected = _7s; break; }
		case 7: { ArrNums[i].texture = _8; ArrNums[i].textureSelected = _8s; break; }
		case 8: { ArrNums[i].texture = _9; ArrNums[i].textureSelected = _9s; break; }
		case 9: { ArrNums[i].texture = _0; ArrNums[i].textureSelected = _0s; break; }
		}
		X += 10;
	}

	//

	initCrates(Crates, br4ya, numWcells, numHcells);




	
	Mix_PlayMusic(fon, -1);

	bool IS_EXECUTE = true;
	while (IS_EXECUTE)
	{
		if (SDL_PollEvent(&event)) if (event.type == SDL_QUIT) { IS_EXECUTE = false; break; }

		SDL_GetMouseState(&mouseX, &mouseY);

		// ÃËÀÂÍÎÅ ÌÅÍÞ
		if (state == 0)
		{

			// ÑÍÀ×ÀËÀ ÔÎÍ À ÏÎÒÎÌ ÎÑÒÀËÜÍÎÅ
			SDL_RenderCopy(renderer, BGtexture3, NULL, &WINDOWrect);

			SDL_RenderCopy(renderer, nametexture, NULL, &namerect);

			// ÙÅË×ÊÈ ÏÎ ÊÍÎÏÊÀÌ

			if (event.type == SDL_MOUSEBUTTONDOWN && (event.button.button == SDL_BUTTON_LEFT))
			{
				// ÑÒÀÐÒ ÊÍÎÏÊÀ
				if (ishit(CTAPTrect, event.button.x, event.button.y))
				{
					PlaySound(click, muteMUTED);
					state = 1;
				}
				// MUTE ÊÍÎÏÊÀ
				else if (ishit(muteRect0, event.button.x, event.button.y))
				{
					muteMUTED = !muteMUTED;
				}
				// MUSIC ÊÍÎÏÊÀ
				else if (ishit(musicRect0, event.button.x, event.button.y))
				{
					musicMUTED = !musicMUTED;
					if (musicMUTED) Mix_PauseMusic();
					else Mix_ResumeMusic();
				}
			}
			else if ((event.type == SDL_KEYDOWN))
			{
				if (event.key.keysym.sym == SDLK_UP) state = 0;
				if (event.key.keysym.sym == SDLK_DOWN) state = 0;
				
			}

			// ÀÍÈÌÀÖÈÈ ÍÀÂÅÄÅÍÈß

			// ÊÍÎÏÊÀ ÑÒÀÐÒ
			if (ishit(CTAPTrect, mouseX, mouseY)) SDL_RenderCopy(renderer, CTAPTselectedtexture, NULL, &CTAPTrect);
			else SDL_RenderCopy(renderer, CTAPTtexture, NULL, &CTAPTrect);
			// ÊÍÎÏÊÀ ÌÜÞÒ
			if (!muteMUTED)
			{
				if (ishit(muteRect0, mouseX, mouseY)) SDL_RenderCopy(renderer, muteSelected, NULL, &muteRect0);
				else SDL_RenderCopy(renderer, mute, NULL, &muteRect0);
			}
			else
			{
				if (ishit(muteRect0, mouseX, mouseY)) SDL_RenderCopy(renderer, muteMutedSelected, NULL, &muteRect0);
				else SDL_RenderCopy(renderer, muteMuted, NULL, &muteRect0);
			}
			// ÊÍÎÏÊÀ MUSIC
			if (!musicMUTED)
			{
				if (ishit(musicRect0, mouseX, mouseY)) SDL_RenderCopy(renderer, musicSelected, NULL, &musicRect0);
				else SDL_RenderCopy(renderer, music, NULL, &musicRect0);
			}
			else
			{
				if (ishit(musicRect0, mouseX, mouseY)) SDL_RenderCopy(renderer, musicMutedSelected, NULL, &musicRect0);
				else SDL_RenderCopy(renderer, musicMuted, NULL, &musicRect0);
			}
			
			//SDL_RenderCopy(renderer, mainnameTexture, NULL, &MainText);

		}

		// ÌÅÍÞ ÂÛÁÎÐÀ ÓÐÎÂÍß
		else if (state == 1)
		{
			SDL_RenderCopy(renderer, BGtextureMenu1, NULL, &WINDOWrect);

			drawlevels(ArrNums);

			// ÙÅË×ÊÈ ÏÎ ÊÍÎÏÊÀÌ

			if (event.type == SDL_MOUSEBUTTONDOWN && (event.button.button == SDL_BUTTON_LEFT))
			{
				if (ishit(returnRect, event.button.x, event.button.y)) { PlaySound(click, muteMUTED); state = 0; }
				else if (ishit(muteRect0, event.button.x, event.button.y))
				{
					muteMUTED = !muteMUTED;
				}
				else if (ishit(musicRect0, event.button.x, event.button.y))
				{
					musicMUTED = !musicMUTED;
					if (musicMUTED) Mix_PauseMusic();
					else Mix_ResumeMusic();
				}
				else if (ActionLevels(ArrNums)) { PlaySound(click, muteMUTED);  state = 2; }
			}


			// ÀÍÈÌÀÖÈÈ ÍÀÂÅÄÅÍÈß
			
			// ÊÍÎÏÊÀ RETURN
			if (ishit(returnRect, mouseX, mouseY)) SDL_RenderCopy(renderer, returnSelectedTexture, NULL, &returnRect);
			else SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect);
			// ÊÍÎÏÊÀ MUTE
			if (!muteMUTED)
			{
				if (ishit(muteRect0, mouseX, mouseY)) SDL_RenderCopy(renderer, muteSelected, NULL, &muteRect0);
				else SDL_RenderCopy(renderer, mute, NULL, &muteRect0);
			}
			else
			{
				if (ishit(muteRect0, mouseX, mouseY)) SDL_RenderCopy(renderer, muteMutedSelected, NULL, &muteRect0);
				else SDL_RenderCopy(renderer, muteMuted, NULL, &muteRect0);
			}
			// ÊÍÎÏÊÀ MUSIC
			if (!musicMUTED)
			{
				if (ishit(musicRect0, mouseX, mouseY)) SDL_RenderCopy(renderer, musicSelected, NULL, &musicRect0);
				else SDL_RenderCopy(renderer, music, NULL, &musicRect0);
			}
			else
			{
				if (ishit(musicRect0, mouseX, mouseY)) SDL_RenderCopy(renderer, musicMutedSelected, NULL, &musicRect0);
				else SDL_RenderCopy(renderer, musicMuted, NULL, &musicRect0);
			}
		}

		// ÑÀÌÀ ÈÃÐÀ
		else if (state == 2)
		{
			// êîíñîëü
			ArrOutput2D_cells(Crates, numHcells, numWcells);
			cout << "\n";
			SDL_Delay(16);
			system("cls");
			///

			SDL_RenderCopy(renderer, BGtextureGame1, NULL, &BG2rect);

			SDL_RenderCopy(renderer, frametexture, NULL, &framerect);

			SDL_RenderCopy(renderer, BGtexture3, NULL, &Windrect);


			// ðèñîâêà âñåãî
			drawCrates(renderer, Crates, numWcells, numHcells);

			// ÙÅË×ÊÈ ÏÎ ÊÍÎÏÊÀÌ

			if (event.type == SDL_MOUSEBUTTONDOWN && (event.button.button == SDL_BUTTON_LEFT))
			{
				if (ishit(returnRect, event.button.x, event.button.y)) { PlaySound(click, muteMUTED); state = 1; }
				else if (ishit(muteRect0, event.button.x, event.button.y))
				{
					muteMUTED = !muteMUTED;
				}
				else if (ishit(musicRect0, event.button.x, event.button.y))
				{
					musicMUTED = !musicMUTED;
					if (musicMUTED) Mix_PauseMusic();
					else Mix_ResumeMusic();
				}
			}

			// ÀÍÈÌÀÖÈÈ ÍÀÂÅÄÅÍÈß

			// ÊÍÎÏÊÀ RETURN
			if (ishit(returnRect, mouseX, mouseY)) SDL_RenderCopy(renderer, returnSelectedTexture, NULL, &returnRect);
			else SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect);
			// ÊÍÎÏÊÀ MUTE
			if (!muteMUTED)
			{
				if (ishit(muteRect0, mouseX, mouseY)) SDL_RenderCopy(renderer, muteSelected, NULL, &muteRect0);
				else SDL_RenderCopy(renderer, mute, NULL, &muteRect0);
			}
			else
			{
				if (ishit(muteRect0, mouseX, mouseY)) SDL_RenderCopy(renderer, muteMutedSelected, NULL, &muteRect0);
				else SDL_RenderCopy(renderer, muteMuted, NULL, &muteRect0);
			}
			// ÊÍÎÏÊÀ MUSIC
			if (!musicMUTED)
			{
				if (ishit(musicRect0, mouseX, mouseY)) SDL_RenderCopy(renderer, musicSelected, NULL, &musicRect0);
				else SDL_RenderCopy(renderer, music, NULL, &musicRect0);
			}
			else
			{
				if (ishit(musicRect0, mouseX, mouseY)) SDL_RenderCopy(renderer, musicMutedSelected, NULL, &musicRect0);
				else SDL_RenderCopy(renderer, musicMuted, NULL, &musicRect0);
			}
		}

		SDL_RenderPresent(renderer);
	}

	ArrDelete2D_cell(Crates, numHcells);

	
	SDL_DestroyTexture(mainnameTexture);

	SDL_DestroyTexture(music);
	SDL_DestroyTexture(musicSelected);
	SDL_DestroyTexture(musicMuted);
	SDL_DestroyTexture(musicMutedSelected);

	SDL_DestroyTexture(mute);
	SDL_DestroyTexture(muteSelected);
	SDL_DestroyTexture(muteMuted);
	SDL_DestroyTexture(muteMutedSelected);

	SDL_DestroyTexture(_0);
	SDL_DestroyTexture(_0s);
	SDL_DestroyTexture(_1);
	SDL_DestroyTexture(_1s);
	SDL_DestroyTexture(_2);
	SDL_DestroyTexture(_2s);
	SDL_DestroyTexture(_3);
	SDL_DestroyTexture(_3s);
	SDL_DestroyTexture(_4);
	SDL_DestroyTexture(_4s);
	SDL_DestroyTexture(_5);
	SDL_DestroyTexture(_5s);
	SDL_DestroyTexture(_6);
	SDL_DestroyTexture(_6s);
	SDL_DestroyTexture(_7);
	SDL_DestroyTexture(_7s);
	SDL_DestroyTexture(_8);
	SDL_DestroyTexture(_8s);
	SDL_DestroyTexture(_9);
	SDL_DestroyTexture(_9s);

	SDL_DestroyTexture(br1na);
	SDL_DestroyTexture(br1ya);
	SDL_DestroyTexture(br2na);
	SDL_DestroyTexture(br2ya);
	SDL_DestroyTexture(br3na);
	SDL_DestroyTexture(br3ya);
	SDL_DestroyTexture(br4na);
	SDL_DestroyTexture(br4ya);
	SDL_DestroyTexture(brRoot);
	SDL_DestroyTexture(brFlowerOpened);
	SDL_DestroyTexture(brFlowerClosed);

	SDL_DestroyTexture(returnSelectedTexture);
	SDL_DestroyTexture(returnTexture);
	SDL_DestroyTexture(BGtexture3);
	SDL_DestroyTexture(frametexture);
	SDL_DestroyTexture(CTAPTselectedtexture);
	SDL_DestroyTexture(CTAPTtexture);
	SDL_DestroyTexture(cratetexture);
	SDL_DestroyTexture(BGtextureMenu1);
	SDL_DestroyTexture(BGtextureGame1);

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}