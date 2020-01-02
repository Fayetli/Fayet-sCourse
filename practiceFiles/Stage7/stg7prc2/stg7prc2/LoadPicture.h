#pragma once
#include <string>
#include <SDL.h>
#include <iostream>

using namespace std;

SDL_Texture* loadImage(SDL_Renderer* renderer, string file) {
	SDL_Surface* surface = nullptr;
	surface = SDL_LoadBMP(file.c_str());
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
	if (surface != nullptr) {
		texture = SDL_CreateTextureFromSurface(renderer, surface);
		SDL_FreeSurface(surface);
	}
	else
		cout << SDL_GetError() << endl;
	return texture;
}

void applyTexture(SDL_Renderer* renderer, SDL_Texture* texture) {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
}
