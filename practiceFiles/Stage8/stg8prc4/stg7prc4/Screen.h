#ifndef SCREEN_H
#define SCREEN_H

#include <SDL.h>
#include <iostream>

namespace aye {

	class Screen
	{
	public:
		const static int SCREEN_WIDTH = 1200;
		const static int SCREEN_HEIGHT = 700;
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
		SDL_Texture* texture;
		Uint32* buffer1;
		Uint32* buffer2;
	public:
		Screen();
		bool init();
		bool processEvents();
		void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
		void close();
		void update();
		void clear();
		void blurBox();
	};

}

#endif