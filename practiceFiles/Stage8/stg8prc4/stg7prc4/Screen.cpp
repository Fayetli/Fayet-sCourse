#include "Screen.h"
#include <iomanip>

namespace aye {

	Screen::Screen():window(NULL), renderer(NULL),
		texture(NULL), buffer1(NULL), buffer2(NULL) {

	}
	void Screen::blurBox() {
		Uint32* temp = buffer1;
		buffer1 = buffer2;
		buffer2 = temp;

		for (int y = 0; y < SCREEN_HEIGHT; y++) {
			for (int x = 0; x < SCREEN_WIDTH; x++) {
				int redTotal = NULL;
				int greenTotal = NULL;
				int blueTotal = NULL;
				for (int row = -1; row <= 1; row++) {
					for (int col = -1; col <= 1; col++) {
						int currentX = x + col;
						int currentY = y + row;
						if (currentX >= 0 && currentX < SCREEN_WIDTH) {
							if (currentY >= 0 && currentY < SCREEN_HEIGHT) {
								Uint32 color = buffer2[currentY * SCREEN_WIDTH + currentX];
								Uint8 red = color >> 24;
								Uint8 green = color >> 16;
								Uint8 blue = color >> 8;
								redTotal += red;
								greenTotal += green;
								blueTotal += blue;
							}
						}
					}
				}
				Uint8 red = redTotal / 9;
				Uint8 green = greenTotal / 9;
				Uint8 blue = blueTotal / 9;
				setPixel(x, y, red, green, blue);
			}
		}
	}
	bool Screen::init() {
		if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
			return false;

		window = SDL_CreateWindow("To-LoveRu",
			SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		if (window == NULL)
			return false;

		renderer = SDL_CreateRenderer(window, -1, 1);

		if (renderer == NULL) {
			SDL_DestroyWindow(window);
			SDL_Quit();
			return false;
		}

		texture = SDL_CreateTexture(renderer,
			SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC,
			SCREEN_WIDTH, SCREEN_HEIGHT);

		if (texture == NULL) {
			SDL_DestroyWindow(window);
			SDL_DestroyRenderer(renderer);
			SDL_Quit();
			return false;
		}

		buffer1 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
		buffer2 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

		memset(buffer1, NULL, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));
		memset(buffer2, NULL, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(Uint32));

		SDL_UpdateTexture(texture, NULL, buffer1, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);

		return true;
	}
	bool Screen::processEvents() {
		SDL_Event event;

		while (SDL_PollEvent(&event)) {

			if (event.type == SDL_QUIT)
				return false;

		}
		return true;
	}
	void Screen::update() {
		SDL_UpdateTexture(texture, NULL, buffer1, SCREEN_WIDTH * sizeof(Uint32));
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}
	void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
		
		if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT) return;

		Uint32 color = 0;

		color += red;
		color <<= 8;
		color += green;
		color <<= 8;
		color += blue;
		color <<= 8;
		color += 0xFF;

		buffer1[y * SCREEN_WIDTH + x] = color;
	}
	void Screen::close() {

		delete[] buffer2;
		delete[] buffer1;
		SDL_DestroyWindow(window);
		SDL_DestroyRenderer(renderer);
		SDL_DestroyTexture(texture);
		SDL_Quit();
	}


}