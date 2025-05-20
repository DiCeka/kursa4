#pragma once
#include "Textures.h"

// загрузка текстур
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
SDL_Rect framerect = { 140, 90, 68 * M, 68 * M };
SDL_Texture* BGtexture3 = createTexture("bg3.bmp", true);
SDL_Texture* returnTexture = createTexture("return.bmp", true);
SDL_Texture* returnSelectedTexture = createTexture("returnSelected.bmp", true);
SDL_Rect returnRect = { 30, 30, 16 * M, 16 * M };
SDL_Rect returnRect2 = { 10, 10, 16 * M, 16 * M };
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
SDL_Texture* brFlower = createTexture("brFlower.bmp", 1);
SDL_Texture* brFlowerna = createTexture("brFlowerna.bmp", 1);
//
SDL_Texture* _0 = createTexture("0.png");
SDL_Texture* _0s = createTexture("0s.png");
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
SDL_Rect muteRect2 = { WIDTH - 160 - 10, 10 + 160 + 10, 16 * M, 16 * M };
//
SDL_Texture* music = createTexture("music.png");
SDL_Texture* musicSelected = createTexture("musicSelected.png");
SDL_Texture* musicMuted = createTexture("musicMuted.png");
SDL_Texture* musicMutedSelected = createTexture("musicMutedSelected.png");
SDL_Rect musicRect0 = { WIDTH - 160 * 2 - 30 * 2, 30, 16 * M, 16 * M };
SDL_Rect musicRect2 = { WIDTH - 160 - 10, 10, 16 * M, 16 * M };
//
SDL_Rect LevelRect = {Windrect.x+Windrect.w/2 - (35*M/2-5), 20, 35*M, 8*M};
SDL_Rect MiniNumRect = {LevelRect.x + 270, 4*M, 3*M, 5*M};
SDL_Rect MiniNumRect10 = { LevelRect.x + 260, 4*M, 6 * M, 5 * M };

SDL_Texture* level = createTexture("level35x8.png");
SDL_Texture* mini1 = createTexture("1n.png");
SDL_Texture* mini2 = createTexture("2n.png");
SDL_Texture* mini3 = createTexture("3n.png");
SDL_Texture* mini4 = createTexture("4n.png");
SDL_Texture* mini5 = createTexture("5n.png");
SDL_Texture* mini6 = createTexture("6n.png");
SDL_Texture* mini7 = createTexture("7n.png");
SDL_Texture* mini8 = createTexture("8n.png");
SDL_Texture* mini9 = createTexture("9n.png");
SDL_Texture* mini10 = createTexture("10n.png");

SDL_Texture* none = createTexture("none.png", true);

SDL_Texture* next_texture = createTexture("next.png");
SDL_Rect next_rect = {790, 550, 16*M, 16*M};

SDL_Texture* cheat_texture = createTexture("cheat.png");
SDL_Rect cheat_rect = {10, 550, 16*M, 16*M};

SDL_Texture* restart_texture = createTexture("restart.png");
SDL_Rect restart_rect = { 10, 180, 16 * M, 16 * M };

SDL_Texture* selecter_texture = createTexture("selecter.png");