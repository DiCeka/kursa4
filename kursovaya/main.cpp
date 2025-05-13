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
#include "Textures.h"


#pragma comment(lib, "SDL2_mixer.lib")

using namespace std;

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
	Mix_Chunk* winsound = Mix_LoadWAV("winsound.wav");
	//

	cell** Crates = ArrCreate2D_cell();



	


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


	
	Mix_PlayMusic(fon, -1);

	bool IS_EXECUTE = true;
	while (IS_EXECUTE)
	{
		if (SDL_PollEvent(&event)) if (event.type == SDL_QUIT) { IS_EXECUTE = false; break; }

		SDL_GetMouseState(&mouseX, &mouseY);
		if (WIN)
		{
			if (FP)
				Pro3++;
			else Pro3--;
			if (Pro3 == 200) FP = 0;
			else if (Pro3 == 100) FP = 1;
		}

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
					PlaySound(click);
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
				if (ishit(returnRect, event.button.x, event.button.y)) { PlaySound(click); state = 0; }
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
				else if (ActionLevels(ArrNums)) { PlaySound(click); GamePaused = 0; NeedToGenerateLevel = 1;  state = 2; }
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
			// Ñãåíåðèðîâàòü óðîâåíü
			if (NeedToGenerateLevel)
			{
				initCrates(Crates, lvl);
				//èçíà÷àëüíàÿ ïðîâåðêà çàñïàâíåâøèõñÿ âåòîê íà àêòèâàöèþ
				RefreshBranches(Crates);
				NeedToGenerateLevel = 0;
			}
			//

			// êîíñîëü
			if (NeedToChangeConsole)
			{
				system("cls");
				cout << "level: " << lvl << "\n\n";
				cout << "Êîë-âî öâåòîâ: " << CntFlowers << "\n";
				cout << "Àêòèâ  öâåòîâ: " << cnt << "\n\n";
				cout << "TextureType\n";
				ArrOutput2D_cells(Crates);
				cout << "Rotation\n";
				ArrOutput2D_cells(Crates, 2);
				cout << "IsActive\n";
				ArrOutput2D_cells(Crates, 3);
				cout << "\n";
				ArrOutput2D_cells(Crates, 4);
				cout << "\n";
				//for (int i = 0; i < 4; i++)
				//{
				//	cout << Crates[2][2].ways[i] << " ";
				//}
				//cout << "\n";
				//for (int i = 0; i < 4; i++)
				//{
				//	cout << Crates[2][2].ways[i] << " ";
				//}
				//cout << "\n\n";

				NeedToChangeConsole = 0;
			}
			///

			SDL_RenderCopy(renderer, BGtextureGame1, NULL, &BG2rect);
			SDL_RenderCopy(renderer, level, NULL, &LevelRect);
			if (lvl != 10) SDL_RenderCopy(renderer, *mininums[lvl], NULL, &MiniNumRect);
			else if (lvl == 10) SDL_RenderCopy(renderer, mini10, NULL, &MiniNumRect10);
			SDL_RenderCopy(renderer, frametexture, NULL, &framerect);
			SDL_RenderCopy(renderer, BGtexture3, NULL, &Windrect);

			drawCrates(Crates);

			if (WIN) { SDL_SetRenderDrawColor(renderer, 255, 255, 255, Pro3); SDL_RenderFillRect(renderer, &WINDOWrect); }
			// ÙÅË×ÊÈ ÏÎ ÊÍÎÏÊÀÌ


			if (event.type == SDL_MOUSEBUTTONDOWN && (event.button.button == SDL_BUTTON_LEFT))
			{
				if (ishit(returnRect, event.button.x, event.button.y)) { PlaySound(click); WIN = 0; state = 1; system("cls"); }
				else if (ishit(muteRect2, event.button.x, event.button.y))
				{
					muteMUTED = !muteMUTED;
				}
				else if (ishit(musicRect2, event.button.x, event.button.y))
				{
					musicMUTED = !musicMUTED;
					if (musicMUTED) Mix_PauseMusic();
					else Mix_ResumeMusic();
				}
				else if (!GamePaused) ActionBranches(Crates);
			}


			// ÀÍÈÌÀÖÈÈ ÍÀÂÅÄÅÍÈß

				// ÂÅÒÎ×ÊÈ
			if (!GamePaused)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, Pro3);
				cnt = 0;
				for (int i = 0; i < numWcells; i++)
				{
					for (int j = 0; j < numHcells; j++)
					{
						if (Crates[i][j].texturetype == 5 && Crates[i][j].IsActive) cnt++;
						if (ishit(Crates[i][j].rect, mouseX, mouseY))
						{
							SDL_RenderFillRect(renderer, &Crates[i][j].rect); break;
						}
					}
				}
				if (cnt == CntFlowers) WIN = 1;
				if (WIN)
				{
					lvlcompleted[lvl] = 1;
					PlaySound(winsound);
					GamePaused = 1;
				}
			}
		



			// ÊÍÎÏÊÀ RETURN
			if (ishit(returnRect, mouseX, mouseY)) SDL_RenderCopy(renderer, returnSelectedTexture, NULL, &returnRect2);
			else SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect2);
			// ÊÍÎÏÊÀ MUTE
			if (!muteMUTED)
			{
				if (ishit(muteRect2, mouseX, mouseY)) SDL_RenderCopy(renderer, muteSelected, NULL, &muteRect2);
				else SDL_RenderCopy(renderer, mute, NULL, &muteRect2);
			}
			else
			{
				if (ishit(muteRect2, mouseX, mouseY)) SDL_RenderCopy(renderer, muteMutedSelected, NULL, &muteRect2);
				else SDL_RenderCopy(renderer, muteMuted, NULL, &muteRect2);
			}
			// ÊÍÎÏÊÀ MUSIC
			if (!musicMUTED)
			{
				if (ishit(musicRect2, mouseX, mouseY)) SDL_RenderCopy(renderer, musicSelected, NULL, &musicRect2);
				else SDL_RenderCopy(renderer, music, NULL, &musicRect2);
			}
			else
			{
				if (ishit(musicRect2, mouseX, mouseY)) SDL_RenderCopy(renderer, musicMutedSelected, NULL, &musicRect2);
				else SDL_RenderCopy(renderer, musicMuted, NULL, &musicRect2);
			}
		}

		SDL_RenderPresent(renderer);
	}

	ArrDelete2D_cell(Crates, numHcells);

	
	Mix_FreeChunk(click);
	Mix_FreeChunk(winsound);
	Mix_FreeMusic(fon);

	SDL_DestroyTexture(mainnameTexture);

	SDL_DestroyTexture(level);
	SDL_DestroyTexture(mini1);
	SDL_DestroyTexture(mini2);
	SDL_DestroyTexture(mini3);
	SDL_DestroyTexture(mini4);
	SDL_DestroyTexture(mini5);
	SDL_DestroyTexture(mini6);
	SDL_DestroyTexture(mini7);
	SDL_DestroyTexture(mini8);
	SDL_DestroyTexture(mini9);
	SDL_DestroyTexture(mini10);

	SDL_DestroyTexture(none);

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
	SDL_DestroyTexture(brFlower);
	SDL_DestroyTexture(brFlowerna);

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