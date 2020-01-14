#include <iostream>
#include "SDL.h"
#include "LoadImage.h"
#include <cstdlib>
#include <ctime>
#define RAND_MAX 320000

int main(int argc, char** argv) {
	const int SCREEN_WIDTH = 800;
	const int SCREEN_HEIGHT = 400;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return 1;
	}

	SDL_Window* window = SDL_CreateWindow("Friendzone",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		return 2;
	}

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 1);

	if (renderer == NULL) {
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}
	SDL_RenderPresent(renderer);

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

	//buffer[30000] = 0xFFFFFFFF;

	/*srand(time(0));
	for (int i = 0; i < SCREEN_HEIGHT * SCREEN_WIDTH; i++) {
		switch(rand() % 5) {
		case 0:
			buffer[i] = 0;
			break;
		case 1:
			buffer[i] = 0xFF00FFFF;
			break;
		case 2:
			buffer[i] = 0xFFFFFF00;
			break;
		case 3:
			buffer[i] = 0xFFFF00FF;
			break;
		case 4:
			buffer[i] = 0x00FFFFFF;
			break;
		}
	}*/
	//buffer[0] = 0xFFFFFFFF;

	SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL, NULL);
	SDL_RenderPresent(renderer);

	SDL_Texture* meg = loadImage(renderer, "../meguminwallpaper.bmp");

	if (meg == NULL) {
		delete[] buffer;
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_Quit();
		return 4;
	}

	SDL_Event event;

	bool quit = false;
	srand(time(NULL));
	while (!quit) {

		switch (rand() % 3) {
		case 0:
			buffer[rand() % (32000) * 10 + rand() % 10] = 0x00FFFFFF;
			break;
		case 1:
			buffer[rand() % (32000) * 10 + rand() % 10] = 0xFFFF00FF;
			break;
		case 2:
			buffer[rand() % (32000) * 10 + rand() % 10] = 0xFF00FFFF;
			break;
		}
		
		

		SDL_UpdateTexture(texture, NULL, buffer, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
		
		



		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT) {
				quit = true;
				break;
			}
			if (event.type == SDL_KEYDOWN) {
				
			}
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				
				applyTexture(renderer, meg);
				SDL_RenderPresent(renderer);

				SDL_Delay(500);
			}
		}
		//SDL_Delay(0.01);
	}

	delete[] buffer;

	SDL_DestroyTexture(meg);
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}