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

void drawlevels(numsTex Arr, numsTex ArrS)
{
	int mouseX, mouseY;
	SDL_GetMouseState(&mouseX, &mouseY);
	//if (ishit(returnRect, mouseX, mouseY)) SDL_RenderCopy(renderer, returnSelectedTexture, NULL, &returnRect);
	for (int i = 0; i < 10; i++)
	{
		// сделай отрисовку всех кнопок выбора уровней, с анимацией наведения и переходами на уровни
	}
}


int main(int args, char** argv)
{
	setlocale(LC_ALL, "ru");

	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(0);


	Mix_Init(0);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);

	// шрифт
	TTF_Init();
	TTF_Font* my_font = TTF_OpenFont("RuneScape-ENA.ttf", 100);
	char txt[15] = "CTAPT";
	SDL_Texture * mainnameTexture = get_text_texture(renderer, txt, my_font);
	//
	// Загрузка звуков
	Mix_Chunk* click = Mix_LoadWAV("click.wav");
	//

	cell** Crates = ArrCreate2D_cell(numHcells, numWcells);


	int m = 7;

	SDL_Texture** ArrTexture = (SDL_Texture**)malloc(0 * sizeof(int));

	// загрузка текстур
	SDL_Texture* BGtextureGame1 = createTexture("fon2.bmp");
	SDL_Texture* BGtextureMenu1 = createTexture("fon3.bmp");
	SDL_Texture* cratetexture = createTexture("crate.bmp");
	SDL_Texture* nametexture = createTexture("BRANCHES.bmp");
	SDL_Rect namerect = { 160, 200, 70 * M, 16 * M };
	SDL_Texture* CTAPTtexture = createTexture("CTAPT.bmp");
	SDL_Texture* CTAPTselectedtexture = createTexture("CTAPTselected.bmp");
	SDL_Rect CTAPTrect = {26*M, 20*M+ 20*M, 50*M, 16*M};
	SDL_Texture* frametexture = createTexture("frame68.bmp", true);
	SDL_Rect framerect = {140, 85, 68*M, 68*M};
	SDL_Texture* BGtexture3 = createTexture("bg3.bmp", true);
	SDL_Texture* returnTexture = createTexture("return.bmp", true);
	SDL_Texture* returnSelectedTexture = createTexture("returnSelected.bmp", true);
	SDL_Rect returnRect = {50, 50, 16*M, 16*M};

	SDL_Texture* br1na = createTexture("br1na.bmp");
	SDL_Texture* br1ya = createTexture("br1ya.bmp");
	SDL_Texture* br2na = createTexture("br2na.bmp");
	SDL_Texture* br2ya = createTexture("br2ya.bmp");
	SDL_Texture* br3na = createTexture("br3na.bmp");
	SDL_Texture* br3ya = createTexture("br3ya.bmp");
	SDL_Texture* br4na = createTexture("br4na.bmp");
	SDL_Texture* br4ya = createTexture("br4ya.bmp");
	SDL_Texture* brRoot = createTexture("brRoot.bmp");
	SDL_Texture* brFlowerOpened = createTexture("brFlowerOpened.bmp");
	SDL_Texture* brFlowerClosed = createTexture("brFlowerClosed.bmp");

	SDL_Texture* _0 = createTexture("0.bmp");
	SDL_Texture* _0s = createTexture("0s.bmp");
	SDL_Texture* _1  = createTexture("1.bmp");
	SDL_Texture* _1s = createTexture("1s.bmp");
	SDL_Texture* _2  = createTexture("2.bmp");
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


	numsTex ArrNums[10];
	for (int i = 0; i < 10; i++)
	{
		ArrNums[i].rect.w = 16 * M;
		ArrNums[i].rect.h = 16 * M;
		ArrNums[i].rect.x = 50 + 16 * M * i;
		if (i < 5) ArrNums[i].rect.y = 50 + 16 * M * i + 16 * M;
		else ArrNums[i].rect.y = 50 + 16 * M * i + 16 * M * 2;

		switch (i)
		{
		case 0: ArrNums[i].texture = _1; break;
		case 1: ArrNums[i].texture = _2; break;
		case 2: ArrNums[i].texture = _3; break;
		case 3: ArrNums[i].texture = _4; break;
		case 4: ArrNums[i].texture = _5; break;
		case 5: ArrNums[i].texture = _6; break;
		case 6: ArrNums[i].texture = _7; break;
		case 7: ArrNums[i].texture = _8; break;
		case 8: ArrNums[i].texture = _9; break;
		case 9: ArrNums[i].texture = _0; break;
		}
	}

	numsTex ArrNumsS[10];
	for (int i = 0; i < 10; i++)
	{
		ArrNumsS[i].rect.w = 16 * M;
		ArrNumsS[i].rect.h = 16 * M;
		ArrNumsS[i].rect.x = 50 + 16 * M * i;
		if (i < 5) ArrNumsS[i].rect.y = 50 + 16 * M * i + 16 * M;
		else ArrNumsS[i].rect.y = 50 + 16 * M * i + 16 * M * 2;

		switch (i)
		{
		case 0: ArrNumsS[i].texture = _1s; break;
		case 1: ArrNumsS[i].texture = _2s; break;
		case 2: ArrNumsS[i].texture = _3s; break;
		case 3: ArrNumsS[i].texture = _4s; break;
		case 4: ArrNumsS[i].texture = _5s; break;
		case 5: ArrNumsS[i].texture = _6s; break;
		case 6: ArrNumsS[i].texture = _7s; break;
		case 7: ArrNumsS[i].texture = _8s; break;
		case 8: ArrNumsS[i].texture = _9s; break;
		case 9: ArrNumsS[i].texture = _0s; break;
		}
	}

	//

	initCrates(Crates, br4ya, numWcells, numHcells);

	SDL_Event event;

	int state = 0;
	int lvl = 0;

	bool IS_EXECUTE = true;
	while (IS_EXECUTE)
	{
		if (SDL_PollEvent(&event)) if (event.type == SDL_QUIT) { IS_EXECUTE = false; break; }

		// ГЛАВНОЕ МЕНЮ
		if (state == 0)
		{

			if (event.type == SDL_MOUSEBUTTONDOWN && (event.button.button == SDL_BUTTON_LEFT))
			{
				if (ishit(CTAPTrect, event.button.x, event.button.y))
				{
					Mix_PlayChannel(-1, click, 0);
					state = 1;
				}
			}
			else if ((event.type == SDL_KEYDOWN))
			{
				if (event.key.keysym.sym == SDLK_UP) state = 0;
				if (event.key.keysym.sym == SDLK_DOWN) state = 0;
				
			}
			 

			// СНАЧАЛА ФОН А ПОТОМ ОСТАЛЬНОЕ
			SDL_RenderCopy(renderer, BGtexture3, NULL, &BG3rect);

			SDL_RenderCopy(renderer, nametexture, NULL, &namerect);

			int mouseX, mouseY;
			SDL_GetMouseState(&mouseX, &mouseY);
			if (ishit(CTAPTrect, mouseX, mouseY)) SDL_RenderCopy(renderer, CTAPTselectedtexture, NULL, &CTAPTrect);
			else SDL_RenderCopy(renderer, CTAPTtexture, NULL, &CTAPTrect);

			//SDL_RenderCopy(renderer, mainnameTexture, NULL, &MainText);

		}

		// МЕНЮ ВЫБОРА УРОВНЯ
		else if (state == 1)
		{
			SDL_RenderCopy(renderer, BGtextureMenu1, NULL, &BG3rect);

			SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect);

			if (event.type == SDL_MOUSEBUTTONDOWN && (event.button.button == SDL_BUTTON_LEFT))
			{
				if (ishit(returnRect, event.button.x, event.button.y)) { Mix_PlayChannel(-1, click, 0); state = 0; }
			}

			int mouseX, mouseY;
			SDL_GetMouseState(&mouseX, &mouseY);
			if (ishit(returnRect, mouseX, mouseY)) SDL_RenderCopy(renderer, returnSelectedTexture, NULL, &returnRect);
			//else SDL_RenderCopy(renderer, returnTexture, NULL, &returnRect);


		}

		// САМА ИГРА
		else if (state == 2)
		{
			// консоль
			ArrOutput2D_cells(Crates, numHcells, numWcells);
			cout << "\n";
			///

			SDL_RenderCopy(renderer, BGtextureGame1, NULL, &BG2rect);

			SDL_SetRenderDrawColor(renderer, 0, 255, 0, 0);
			SDL_RenderDrawRect(renderer, &Windrect);

			SDL_RenderCopy(renderer, frametexture, NULL, &framerect);

			// рисовка всего
			drawCrates(renderer, Crates, numWcells, numHcells);

			SDL_Delay(20);
			system("cls");
		}

		SDL_RenderPresent(renderer);
	}

	ArrDelete2D_cell(Crates, numHcells);

	
	SDL_DestroyTexture(mainnameTexture);

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