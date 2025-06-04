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
#include "Sounds.h"
#include "Logic.h"


#pragma comment(lib, "SDL2_mixer.lib")

using namespace std;

int main(int args, char** argv)
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));

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
	initSounds();
	//

	int m = 7;

	SDL_Surface* icon = IMG_Load("sprites/icon.png");
	SDL_SetWindowIcon(window, icon);

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

	int CurrentTrack = rand() % 3;
	Mix_PlayMusic(tracks[CurrentTrack], 1);

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
		if (!Mix_PlayingMusic()) Mix_PlayMusic(tracks[(CurrentTrack+1)%3], 1);

		// ÃËÀÂÍÎÅ ÌÅÍÞ ///////////////////////////////////////////////////////////////////////////////////////////////////////
		if (state == 0)
		{
			// ÑÍÀ×ÀËÀ ÔÎÍ À ÏÎÒÎÌ ÎÑÒÀËÜÍÎÅ
			SDL_RenderCopy(renderer, BGtexture3, NULL, &WINDOWrect);
			SDL_RenderCopy(renderer, nametexture, NULL, &namerect);

			// ÙÅË×ÊÈ ÏÎ ÊËÀÂÈØÀÌ
			if ((event.type == SDL_KEYDOWN))
			{	
				if (IsFirstCycle && ButCl())
				{
					KeyNavigation = true;
					ArrAddElement1D_Rect(Rects, RectsSize, CTAPTrect);
					ArrAddElement1D_Rect(Rects, RectsSize, muteRect0);
					ArrAddElement1D_Rect(Rects, RectsSize, musicRect0);
					ArrAddElement1D_Rect(Rects, RectsSize, InfinityRect);
					CurrentRect = Rects[0];
					IsFirstCycle = 0;
					goto after0;
				}

				if ((event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w)) GoToClosestRect(Rects, CurrentRect, 0);
				else if ((event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d)) GoToClosestRect(Rects, CurrentRect, 1);
				else if ((event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s)) GoToClosestRect(Rects, CurrentRect, 2);
				else if ((event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a)) GoToClosestRect(Rects, CurrentRect, 3);
				else if ((event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_SPACE))
				{
					if (EqualRects(CurrentRect, CTAPTrect)) CTAPTfunc();
					else if (EqualRects(CurrentRect, muteRect0)) Mutefunc();
					else if (EqualRects(CurrentRect, musicRect0)) Musicfunc();
					else if (EqualRects(CurrentRect, InfinityRect)) InfinityFunc();
				}
			}
		after0:
			// ÙÅË×ÊÈ ÏÎ ÊÍÎÏÊÀÌ
			if (event.type == SDL_MOUSEBUTTONDOWN && (event.button.button == SDL_BUTTON_LEFT))
			{
				// ÑÒÀÐÒ ÊÍÎÏÊÀ
				if (ishit(CTAPTrect, event.button.x, event.button.y)) CTAPTfunc();
				// MUTE ÊÍÎÏÊÀ
				else if (ishit(muteRect0, event.button.x, event.button.y)) Mutefunc();
				// MUSIC ÊÍÎÏÊÀ
				else if (ishit(musicRect0, event.button.x, event.button.y)) Musicfunc();
				// ÈÍÔÈÍÈÒÈ ÊÍÎÏÊÀ
				else if (ishit(InfinityRect, event.button.x, event.button.y)) InfinityFunc();
			}

			// ÀÍÈÌÀÖÈÈ ÍÀÂÅÄÅÍÈß
			
			// ÊÍÎÏÊÀ ÈÍÔÈÍÈÒÈ
			SDL_RenderCopy(renderer, Infinitytexture, NULL, &InfinityRect);
			if (ishit(InfinityRect, mouseX, mouseY)) 
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, ProZR);
				SDL_RenderFillRect(renderer, &InfinityRect);
			}
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
			// ÂÛÄÅËÅÍÈÅ ÎÒ ÊËÀÂÈØ
			if (KeyNavigation)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, ProZR);
				SDL_RenderFillRect(renderer, &CurrentRect);
				SDL_RenderCopy(renderer, selecter_texture, NULL, &CurrentRect);
			}
		}

		// ÌÅÍÞ ÂÛÁÎÐÀ ÓÐÎÂÍß /////////////////////////////////////////////////////////////////////////////////////////////////
		else if (state == 1)
		{
			SDL_RenderCopy(renderer, BGtextureMenu1, NULL, &WINDOWrect);

			drawlevels(ArrNums);

			// ÙÅË×ÊÈ ÏÎ ÊËÀÂÈØÀÌ
			if ((event.type == SDL_KEYDOWN))
			{
				if (IsFirstCycle && ButCl())
				{
					KeyNavigation = true;
					ArrAddElement1D_Rect(Rects, RectsSize, returnRect);
					ArrAddElement1D_Rect(Rects, RectsSize, muteRect0);
					ArrAddElement1D_Rect(Rects, RectsSize, musicRect0);
					for (int i = 0; i < 10; i++) ArrAddElement1D_Rect(Rects, RectsSize, ArrNums[i].rect);
					CurrentRect = Rects[0];
					IsFirstCycle = 0;
					goto after1;
				}

				if ((event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w)) GoToClosestRect(Rects, CurrentRect, 0);
				else if ((event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d)) GoToClosestRect(Rects, CurrentRect, 1);
				else if ((event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s)) GoToClosestRect(Rects, CurrentRect, 2);
				else if ((event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a)) GoToClosestRect(Rects, CurrentRect, 3);
				else if ((event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_SPACE))
				{
					if (EqualRects(CurrentRect, returnRect)) Returnfunc(0);
					else if (EqualRects(CurrentRect, muteRect0)) Mutefunc();
					else if (EqualRects(CurrentRect, musicRect0)) Musicfunc();
					else
					{
						for (int i = 0; i < 10; i++)
						{
							if (EqualRects(CurrentRect, ArrNums[i].rect))
							{
								lvl = i + 1;
								ChangeState(2); 
								RestartLevel();
								PlaySound(click);
							}
						}
					}
				}
			}
		after1:
			// ÙÅË×ÊÈ ÏÎ ÊÍÎÏÊÀÌ

			if (event.type == SDL_MOUSEBUTTONDOWN && (event.button.button == SDL_BUTTON_LEFT))
			{
				if (ishit(returnRect, event.button.x, event.button.y)) Returnfunc(0);
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
				else if (ActionLevels(ArrNums)) { ChangeState(2); RestartLevel(); PlaySound(click); }
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

			// ÂÛÄÅËÅÍÈÅ ÎÒ ÊËÀÂÈØ
			if (KeyNavigation)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, ProZR);
				SDL_RenderFillRect(renderer, &CurrentRect);
				SDL_RenderCopy(renderer, selecter_texture, NULL, &CurrentRect);
			}
		}

		// ÑÀÌÀ ÈÃÐÀ //////////////////////////////////////////////////////////////////////////////////////////////////////////
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

			// ÎÑÍÎÂÍÛÅ ÒÅÊÑÒÓÐÛ
			SDL_RenderCopy(renderer, BGtextureGame1, NULL, &BG2rect);
			SDL_RenderCopy(renderer, level, NULL, &LevelRect);
			if (lvl != 10) SDL_RenderCopy(renderer, *mininums[lvl], NULL, &MiniNumRect);
			else if (lvl == 10) SDL_RenderCopy(renderer, mini10, NULL, &MiniNumRect10);
			SDL_RenderCopy(renderer, frametexture, NULL, &framerect);
			SDL_RenderCopy(renderer, BGframeGame2, NULL, &Windrect);
			drawCrates(Crates);
			//

			// ÀÍÈÌÀÖÈß ÑÂÅÐÊÀÍÈß ÏÎÁÅÄÛ
			if (WIN) 
			{ 
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, Pro3); SDL_RenderFillRect(renderer, &WINDOWrect); 
			}

			// ÎÁÐÀÁÎÒÊÀ ÐÅÆÈÌÀ ÐÀÇÐÀÁÎÒ×ÈÊÀ
			if (DeveloperMode && !WIN)
			{
				SDL_RenderCopy(renderer, cheat_texture, NULL, &cheat_rect);
				if (ishit(cheat_rect, mouseX, mouseY)) { SDL_SetRenderDrawColor(renderer, 255, 255, 255, Pro3); SDL_RenderFillRect(renderer, &cheat_rect); };
			}

			// ÑÒÐÎÈÒÅËÜÍÛÅ ËÅÑÀ
			//int j = 10;
			//if ((event.type == SDL_KEYDOWN))
			//{
			//	if (event.key.keysym.sym == SDLK_DOWN) restart_rect.y += j;
			//	else if (event.key.keysym.sym == SDLK_UP) restart_rect.y -= j;
			//	else if (event.key.keysym.sym == SDLK_RIGHT) restart_rect.x += j;
			//	else if (event.key.keysym.sym == SDLK_LEFT) restart_rect.x -= j;
			//	NeedToChangeConsole = 1;
			//}
			//

			// ÙÅË×ÊÈ ÏÎ ÊËÀÂÈØÀÌ
			if ((event.type == SDL_KEYDOWN))
			{
				if (IsFirstCycle && ButCl())
				{
					KeyNavigation = true;
					ArrAddElement1D_Rect(Rects, RectsSize, returnRect2);
					ArrAddElement1D_Rect(Rects, RectsSize, muteRect2);
					ArrAddElement1D_Rect(Rects, RectsSize, musicRect2);
					ArrAddElement1D_Rect(Rects, RectsSize, restart_rect);
					if (!GamePaused)
					{
						for (int i = 0; i < numWcells; i++)
						{
							for (int j = 0; j < numHcells; j++)
							{
								ArrAddElement1D_Rect(Rects, RectsSize, Crates[i][j].rect);
							}
						}
					}
					if (DeveloperMode && !WIN) ArrAddElement1D_Rect(Rects, RectsSize, cheat_rect);
					if (WIN) ArrAddElement1D_Rect(Rects, RectsSize, next_rect);

					CurrentRect = Rects[0];
					IsFirstCycle = 0;
					goto after2;
				}

				if ((event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w)) GoToClosestRect(Rects, CurrentRect, 0);
				else if ((event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d)) GoToClosestRect(Rects, CurrentRect, 1);
				else if ((event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s)) GoToClosestRect(Rects, CurrentRect, 2);
				else if ((event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a)) GoToClosestRect(Rects, CurrentRect, 3);
				else if ((event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_SPACE))
				{
					if (EqualRects(CurrentRect, returnRect2)) Returnfunc(1);
					else if (EqualRects(CurrentRect, muteRect2)) Mutefunc();
					else if (EqualRects(CurrentRect, musicRect2)) Musicfunc();
					else if (EqualRects(CurrentRect, restart_rect))
					{
						if (WIN)
						{
							ArrDelElement1D_Rect(Rects, RectsSize, next_rect);
							if (DeveloperMode) ArrAddElement1D_Rect(Rects, RectsSize, cheat_rect);
						}
						Restartfunc();
						continue;
					}
					else if (!WIN && EqualRects(CurrentRect, cheat_rect)) { Cheatfunc(); ResetKeyNavig(); }
					else if (WIN && EqualRects(CurrentRect, next_rect)) { Nextfunc(); ResetKeyNavig(); continue; }
					else if (!WIN) ActionBranches(Crates, 0);
				}
			}
		after2:
			// ÙÅË×ÊÈ ÏÎ ÊÍÎÏÊÀÌ
			if (event.type == SDL_MOUSEBUTTONDOWN && (event.button.button == SDL_BUTTON_LEFT))
			{
				// EXECUTING
				if (ishit(returnRect, event.button.x, event.button.y)) Returnfunc(1);
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
				else if (ishit(cheat_rect, event.button.x, event.button.y) && DeveloperMode && !WIN) Cheatfunc();
				else if (ishit(restart_rect, event.button.x, event.button.y)) { Restartfunc(); continue; }
				else if (!GamePaused) ActionBranches(Crates, 1); // ÑÒÎÏ ÇÄÅÑÜ ÅÑËÈ ÈÃÐÀ ÍÀ ÏÀÓÇÅ

				// PAUSED
				else if (ishit(next_rect, event.button.x, event.button.y)) 
				{ 
					Nextfunc();
					ResetKeyNavig();
					continue;
				}
			}
					// ÀÍÈÌÀÖÈÈ ÍÀÂÅÄÅÍÈß

			// ÂÅÒÎ×ÊÈ (Ñ×¨Ò×ÈÊ ÖÂÅÒÎÂ, ÎÁÐÀÁÎÒÊÀ ÏÎÁÅÄÛ)
			if (!GamePaused)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 100);
				CountActiveFlowers(Crates);
				SelectAnimation(Crates);
				if (cnt == CntFlowers) WIN = 1;
				if (WIN)
				{
					lvlcompleted[lvl] = 1;
					PlaySound(winsound);
					GamePaused = 1;
					ResetKeyNavig();
				}
			}

			// ÊÍÎÏÊÀ RESTART
			SDL_RenderCopy(renderer, restart_texture, NULL, &restart_rect);
			if (ishit(restart_rect, mouseX, mouseY)) 
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, ProZR);
				SDL_RenderFillRect(renderer, &restart_rect);
			}
			// ÊÍÎÏÊÀ NEXT
			if (WIN && (1 <= lvl && lvl < 10))
			{
				SDL_RenderCopy(renderer, next_texture, NULL, &next_rect);
				if (ishit(next_rect, mouseX, mouseY))
				{
					SDL_SetRenderDrawColor(renderer, 255, 255, 255, ProZR);
					SDL_RenderFillRect(renderer, &next_rect);
				}
			}
			// ÊÍÎÏÊÀ RETURN
			if (ishit(returnRect2, mouseX, mouseY)) SDL_RenderCopy(renderer, returnSelectedTexture, NULL, &returnRect2);
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

			// ÂÛÄÅËÅÍÈÅ ÎÒ ÊËÀÂÈØ
			if (KeyNavigation)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, ProZR);
				SDL_RenderFillRect(renderer, &CurrentRect);
				SDL_RenderCopy(renderer, selecter_texture, NULL, &CurrentRect);
			}

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
				//cout << "HODI\n";
				//ArrOutput2D_cells(Crates, 4);
				cout << "IsAnimating\n";
				ArrOutput2D_cells(Crates, 5);
				cout << "\n";
				//cout << "x: " << restart_rect.x << "\ny: " << restart_rect.y << "\n";

				NeedToChangeConsole = 0;
			}
			///
		}

		// ÁÅÑÊÎÍÅ×ÍÛÉ ÐÅÆÈÌ //////////////////////////////////////////////////////////////////////////////////////////////////
		else if (state == 3)
		{
			// Ñãåíåðèðîâàòü óðîâåíü
			if (NeedToGenerateLevel)
			{
				CratesClear(Crates);
				GenerateRandomLevel(Crates, 1);
				//èçíà÷àëüíàÿ ïðîâåðêà çàñïàâíèâøèõñÿ âåòîê íà àêòèâàöèþ
				RefreshBranches(Crates);
				NeedToGenerateLevel = 0;
			}
			//
			// ÎÑÍÎÂÍÛÅ ÒÅÊÑÒÓÐÛ
			SDL_RenderCopy(renderer, BGtextureGame2, NULL, &WINDOWrect);
			SDL_RenderCopy(renderer, frametexture, NULL, &framerect);
			SDL_RenderCopy(renderer, BGframeGame3, NULL, &Windrect);
			SDL_RenderCopy(renderer, level, NULL, &LevelRect);

			char txt[4];
			sprintf_s(txt, "%d", (NumOfCompletedInfLevels + 1));
			SDL_Texture* mainnameTexture = get_text_texture(renderer, txt, my_font);
			if (NumOfCompletedInfLevels < 9) SDL_RenderCopy(renderer, mainnameTexture, NULL, &NumRect);
			else if (NumOfCompletedInfLevels >= 9 && NumOfCompletedInfLevels < 99) SDL_RenderCopy(renderer, mainnameTexture, NULL, &NumRect10);
			else SDL_RenderCopy(renderer, mainnameTexture, NULL, &NumRect100);
			SDL_DestroyTexture(mainnameTexture);

			drawCrates(Crates);
			//

			// ÀÍÈÌÀÖÈß ÑÂÅÐÊÀÍÈß ÏÎÁÅÄÛ
			if (WIN)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, Pro3); SDL_RenderFillRect(renderer, &WINDOWrect);
			}

			// ÎÁÐÀÁÎÒÊÀ ÐÅÆÈÌÀ ÐÀÇÐÀÁÎÒ×ÈÊÀ
			if (DeveloperMode && !WIN)
			{
				SDL_RenderCopy(renderer, cheat_texture, NULL, &cheat_rect);
				if (ishit(cheat_rect, mouseX, mouseY)) { SDL_SetRenderDrawColor(renderer, 255, 255, 255, Pro3); SDL_RenderFillRect(renderer, &cheat_rect); };
			}

			// ÙÅË×ÊÈ ÏÎ ÊËÀÂÈØÀÌ
			if ((event.type == SDL_KEYDOWN))
			{
				if (IsFirstCycle && ButCl())
				{
					KeyNavigation = true;
					ArrAddElement1D_Rect(Rects, RectsSize, returnRect2);
					ArrAddElement1D_Rect(Rects, RectsSize, muteRect2);
					ArrAddElement1D_Rect(Rects, RectsSize, musicRect2);
					ArrAddElement1D_Rect(Rects, RectsSize, restart_rect);
					if (!GamePaused)
					{
						for (int i = 0; i < numWcells; i++)
						{
							for (int j = 0; j < numHcells; j++)
							{
								ArrAddElement1D_Rect(Rects, RectsSize, Crates[i][j].rect);
							}
						}
					}
					if (DeveloperMode && !WIN) ArrAddElement1D_Rect(Rects, RectsSize, cheat_rect);
					if (WIN) ArrAddElement1D_Rect(Rects, RectsSize, next_rect);

					CurrentRect = Rects[0];
					IsFirstCycle = 0;
					goto after31;
				}

				if ((event.key.keysym.sym == SDLK_UP || event.key.keysym.sym == SDLK_w)) GoToClosestRect(Rects, CurrentRect, 0);
				else if ((event.key.keysym.sym == SDLK_RIGHT || event.key.keysym.sym == SDLK_d)) GoToClosestRect(Rects, CurrentRect, 1);
				else if ((event.key.keysym.sym == SDLK_DOWN || event.key.keysym.sym == SDLK_s)) GoToClosestRect(Rects, CurrentRect, 2);
				else if ((event.key.keysym.sym == SDLK_LEFT || event.key.keysym.sym == SDLK_a)) GoToClosestRect(Rects, CurrentRect, 3);
				else if ((event.key.keysym.sym == SDLK_RETURN || event.key.keysym.sym == SDLK_SPACE))
				{
					if (EqualRects(CurrentRect, returnRect2)) Returnfunc(0);
					else if (EqualRects(CurrentRect, muteRect2)) Mutefunc();
					else if (EqualRects(CurrentRect, musicRect2)) Musicfunc();
					else if (EqualRects(CurrentRect, restart_rect))
					{
						GamePaused = 0;
						WIN = 0;
						NeedToChangeConsole = 1;
						RandomizeRotates(Crates);
						RefreshBranches(Crates);
						PlaySound(click);
						continue;
					}
					else if (!WIN && EqualRects(CurrentRect, cheat_rect)) { Cheatfunc(); ResetKeyNavig(); }
					else if (WIN && EqualRects(CurrentRect, next_rect))
					{ 
						NextInfinityfunc(); 
						ResetKeyNavig(); 
						IncreaseInfLevels();
						continue; 
					}
					else if (!WIN) ActionBranches(Crates, 0);
				}
			}
		after31:
			// ÙÅË×ÊÈ ÏÎ ÊÍÎÏÊÀÌ
			if (event.type == SDL_MOUSEBUTTONDOWN && (event.button.button == SDL_BUTTON_LEFT))
			{
				// EXECUTING
				if (ishit(returnRect, event.button.x, event.button.y)) Returnfunc(0);
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
				else if (ishit(cheat_rect, event.button.x, event.button.y) && DeveloperMode && !WIN) Cheatfunc();
				else if (ishit(restart_rect, event.button.x, event.button.y)) {
					GamePaused = 0;
					WIN = 0;
					NeedToChangeConsole = 1;
					RandomizeRotates(Crates);
					RefreshBranches(Crates);
					PlaySound(click);
					continue; }
				else if (!GamePaused) ActionBranches(Crates, 1); // ÑÒÎÏ ÇÄÅÑÜ ÅÑËÈ ÈÃÐÀ ÍÀ ÏÀÓÇÅ

				// PAUSED
				else if (ishit(next_rect, event.button.x, event.button.y))
				{
					NextInfinityfunc();
					ResetKeyNavig();
					IncreaseInfLevels();
					continue;
				}
			}


			    // ÀÍÈÌÀÖÈÈ ÍÀÂÅÄÅÍÈß

			// ÂÅÒÎ×ÊÈ (Ñ×¨Ò×ÈÊ ÖÂÅÒÎÂ, ÎÁÐÀÁÎÒÊÀ ÏÎÁÅÄÛ)
			if (!GamePaused)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 100);
				CountActiveFlowers(Crates);
				SelectAnimation(Crates);
				if (cnt == CntFlowers) WIN = 1;
				if (WIN)
				{
					PlaySound(winsound);
					GamePaused = 1;
					ResetKeyNavig();
				}
			}

			// ÊÍÎÏÊÀ RESTART
			SDL_RenderCopy(renderer, restart_texture, NULL, &restart_rect);
			if (ishit(restart_rect, mouseX, mouseY))
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, ProZR);
				SDL_RenderFillRect(renderer, &restart_rect);
			}
			// ÊÍÎÏÊÀ RETURN
			if (ishit(returnRect2, mouseX, mouseY)) SDL_RenderCopy(renderer, returnSelectedTexture, NULL, &returnRect2);
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
			// ÊÍÎÏÊÀ NEXT
			if (WIN)
			{
				SDL_RenderCopy(renderer, next_texture, NULL, &next_rect);
				if (ishit(next_rect, mouseX, mouseY))
				{
					SDL_SetRenderDrawColor(renderer, 255, 255, 255, ProZR);
					SDL_RenderFillRect(renderer, &next_rect);
				}
			}


			// ÂÛÄÅËÅÍÈÅ ÎÒ ÊËÀÂÈØ
			if (KeyNavigation)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, ProZR);
				SDL_RenderFillRect(renderer, &CurrentRect);
				SDL_RenderCopy(renderer, selecter_texture, NULL, &CurrentRect);
			}

			// êîíñîëü
			if (NeedToChangeConsole)
			{
				if (numWcells <= 10)
				{
					system("cls");
					cout << "Óðîâíåé ïðîéäåíî: " << NumOfCompletedInfLevels << "\n";
					cout << "Êîë-âî öâåòîâ: " << CntFlowers << "\n";
					cout << "Àêòèâ  öâåòîâ: " << cnt << "\n\n";
					cout << "TextureType\n";
					ArrOutput2D_cells(Crates);
					cout << "Rotation\n";
					ArrOutput2D_cells(Crates, 2);
					cout << "IsActive\n";
					ArrOutput2D_cells(Crates, 3);
					cout << "IsAnimating\n";
					ArrOutput2D_cells(Crates, 5);
					cout << "\n";
					//cout << "x: " << restart_rect.x << "\ny: " << restart_rect.y << "\n";
				}
				NeedToChangeConsole = 0;
			}
			///
		}

		SDL_RenderPresent(renderer);
	}

	delete[] Rects;

	ArrDelete2D_cell(Crates, numHcells);

	freeSounds();

	SDL_FreeSurface(icon);

	SDL_DestroyTexture(mainnameTexture);

	SDL_DestroyTexture(selecter_texture);

	SDL_DestroyTexture(restart_texture);

	SDL_DestroyTexture(cheat_texture);

	SDL_DestroyTexture(next_texture);

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
	SDL_DestroyTexture(Infinitytexture);
	SDL_DestroyTexture(CTAPTselectedtexture);
	SDL_DestroyTexture(CTAPTtexture);
	SDL_DestroyTexture(cratetexture);
	SDL_DestroyTexture(BGframeGame2);
	SDL_DestroyTexture(BGframeGame3);
	SDL_DestroyTexture(BGtextureMenu1);
	SDL_DestroyTexture(BGtextureGame1);

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	return 0;
}