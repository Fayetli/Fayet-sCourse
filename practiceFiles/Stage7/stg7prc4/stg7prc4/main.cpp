#include "SDL.h"
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 400;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
		return 1;

	SDL_Window* window = SDL_CreateWindow("To-LoveRu",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL)
		return 2;

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 1);

	if (renderer == NULL) {
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}

	SDL_Texture* texture = SDL_CreateTexture(renderer,
		SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
			SCREEN_WIDTH, SCREEN_HEIGHT);

	if (texture == NULL) {
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 4;
	}
	
	Uint32* buffer = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(buffer, NULL, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));

	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	bool quit = false;
	
	SDL_Event event;

	while (!quit) {






		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT)
				quit = true;
			if (event.type == SDL_KEYDOWN) {


			}
			if (event.type == SDL_MOUSEBUTTONDOWN) {



			}
		}
		SDL_Delay(100);
	}


	delete[] buffer;

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyTexture(texture);
	SDL_Quit();
	return 0;
}