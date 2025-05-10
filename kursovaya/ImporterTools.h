#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"


SDL_Texture* createTexture(const char* name, bool delBG = false);

SDL_Texture* get_text_texture(SDL_Renderer*& renderer, char* text, TTF_Font* font);