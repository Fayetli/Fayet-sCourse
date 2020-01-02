#include "SDL.h"
#include <string>
#include <iostream>
#include <conio.h>
#include <windows.h>

#include "LoadPicture.h"

using namespace std;


void applyTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y) {
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(renderer, texture, NULL, &pos);
}

int main(int argc, char** argv) {

	const int SCREEN_HEIGHT = 640;
	const int SCREEN_WIDTH = 640;

	int* treeLoopCount = new int(10);
	int* meguminTime = new int(3000);

	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window* window = SDL_CreateWindow("My second window",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	SDL_Renderer* treeRenderer = SDL_CreateRenderer(window, -1, 1);

	SDL_Texture* tree1 = loadImage(treeRenderer, "../Christmas_tree_1.bmp");
	SDL_Texture* tree2 = loadImage(treeRenderer, "../Christmas_tree_2.bmp");
	SDL_Texture* tree3 = loadImage(treeRenderer, "../Christmas_tree_3.bmp");

	while (*treeLoopCount) {
		applyTexture(treeRenderer, tree1);
		SDL_RenderPresent(treeRenderer);
		SDL_Delay(250);

		applyTexture(treeRenderer, tree2);
		SDL_RenderPresent(treeRenderer);
		SDL_Delay(250);

		applyTexture(treeRenderer, tree3);
		SDL_RenderPresent(treeRenderer);
		SDL_Delay(250);

		*treeLoopCount = *treeLoopCount - 1;
	}

	delete treeLoopCount;

	SDL_DestroyTexture(tree1);
	SDL_DestroyTexture(tree2);
	SDL_DestroyTexture(tree3);
	SDL_DestroyRenderer(treeRenderer);

	SDL_Quit();

	window = SDL_CreateWindow("My second window",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
			1375, 685, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 1);

	SDL_Texture* meguminTexture = loadImage(renderer, "../meguminwallpaper.bmp");
	applyTexture(renderer, meguminTexture);
	SDL_RenderPresent(renderer);

	SDL_Delay(*meguminTime);

	delete meguminTime;

	SDL_DestroyTexture(meguminTexture);
	SDL_DestroyRenderer(renderer);
	
	SDL_Quit();

	return 0;
}