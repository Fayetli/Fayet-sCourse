#include <iostream>
#include "SDL.h"
#include <string>

SDL_Texture* LoadImage(std::string file, SDL_Renderer *renderer) {
	SDL_Surface* loadedImage = nullptr;
	SDL_Texture* texture = nullptr;
	loadedImage = SDL_LoadBMP(file.c_str());
	if (loadedImage != nullptr) {
		texture = SDL_CreateTextureFromSurface(renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
	}
	else
		std::cout << SDL_GetError() << std::endl;
	return texture;
}

void ApplySurface(int x, int y, SDL_Texture* texture, SDL_Renderer* renderer) {
	SDL_Rect pos;//position on screen
	pos.x = x;
	pos.y = y;				
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);//to use standart size
	SDL_RenderCopy(renderer, texture, NULL, &pos);//copy to renderer
}

int main(int argc, char** argv) {

	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;

	SDL_Init(SDL_INIT_EVERYTHING);//initialization sdl lib

	SDL_Window* window = SDL_CreateWindow("title",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	//create a window, in centre, with name 'title' and atribute 'shown'

	if (window == nullptr) {
		std::cout << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
		return 1;
	}//return error if didn`t create a window
					//toPaintOnWindow								//flags
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
													   //driver index					//http://wiki.libsdl.org/SDL_RendererFlags

	if (renderer == nullptr) {
		std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
		return 1;
	}//return error if didn`t create a renderer

	SDL_Surface* bmp = SDL_LoadBMP("../hello.bmp");

	if (bmp == nullptr) {
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		return 1;
	}//error message

	SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, bmp);//create texture with this bmp image

	SDL_FreeSurface(bmp);//clear memory

	if (tex == nullptr) {
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		return 1;
	}//error message

	SDL_RenderClear(renderer);//clear up renderer
	SDL_RenderCopy(renderer, tex, NULL, NULL);//rendering image to full window screen
	SDL_RenderPresent(renderer);//show new renderer

	SDL_Delay(1500);//pause 1.5 sec
	SDL_DestroyTexture(tex);//clean up memory


	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);//drow renderer color					
	SDL_RenderClear(renderer);//clean up renderer
	SDL_RenderPresent(renderer);//show new renderer

	SDL_Delay(1500);//pause 1.5 sec


	SDL_Texture* texture = LoadImage("../hello.bmp", renderer);

	ApplySurface(100, 100, texture, renderer);
	SDL_RenderPresent(renderer);

	SDL_Delay(1500);
	SDL_DestroyTexture(texture);


	//example #1562(no)
	SDL_Texture* background = nullptr, * image = nullptr;
	background = LoadImage("../background.bmp", renderer);
	image = LoadImage("../image.bmp", renderer);

	SDL_RenderClear(renderer);

	int bW, bH;
	SDL_QueryTexture(background, NULL, NULL, &bW, &bH);//give width and height
	ApplySurface(0, 0, background, renderer);//print 4 times
	ApplySurface(bW, 0, background, renderer);
	ApplySurface(0, bH, background, renderer);
	ApplySurface(bW, bH, background, renderer);

	int iW, iH;
	SDL_QueryTexture(image, NULL, NULL, &iW, &iH);//give width and height
	int x = SCREEN_WIDTH / 2 - iW / 2;//print in the centre
	int y = SCREEN_HEIGHT / 2 - iH / 2;
	ApplySurface(x, y, image, renderer);

	SDL_RenderPresent(renderer);//show
	SDL_Delay(1500);


	SDL_DestroyTexture(background);
	SDL_DestroyTexture(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);//clean up memory

	SDL_Quit();//clean up

	return 0;
}

