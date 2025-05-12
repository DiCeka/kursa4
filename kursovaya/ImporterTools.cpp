#pragma once
#include "ImporterTools.h"
#include "Constants.h"
#include <string>

SDL_Texture* createTexture(const char* name, bool delBG)
{
	char fullname[100] = "";

	strcat_s(fullname, SPRITES_FOLDER); // ссылка на папку с текстурами
	strcat_s(fullname, name); // название файла
	
	SDL_Surface* Image = IMG_Load(fullname);
	if (delBG) SDL_SetColorKey(Image, SDL_TRUE, SDL_MapRGB(Image->format, 255, 255, 255));
	SDL_Texture* Texture = SDL_CreateTextureFromSurface(renderer, Image);
	SDL_FreeSurface(Image);

	return Texture;
}

SDL_Texture* get_text_texture(SDL_Renderer*& renderer, char* text, TTF_Font* font)
{
	SDL_Surface* textSurface = NULL;
	SDL_Color fore_color = { 0,0,0 };
	SDL_Color back_color = { 255,255,255 };
	textSurface = TTF_RenderText_Shaded(font, text, fore_color, back_color); // генерирует поверхность с текстом
	SDL_SetColorKey(textSurface, SDL_TRUE, SDL_MapRGB(textSurface->format, 255, 255, 255));
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface); // копирует поверхность в текстуру
	SDL_FreeSurface(textSurface);
	return texture;
}