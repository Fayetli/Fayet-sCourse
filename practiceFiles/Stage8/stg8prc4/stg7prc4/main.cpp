#include "SDL.h"
#include "Screen.h"
#include "Swarm.h"
#include "Particle.h"

#include <cmath>
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;
using namespace aye;

int main(int argc, char** argv) {
	
	srand(time(NULL));

	Screen screen;
	
	if (screen.init() == false) {
		return 1;
	}

	Swarm swarm;
	
	while (true) {

		int timed = SDL_GetTicks();

		screen.blurBox();
		swarm.update(timed);

		unsigned char green = (1 + sin(timed * 0.0005)) * 128;
		unsigned char red   = (1 + sin(timed * 0.0010)) * 128;
		unsigned char blue  = (1 + sin(timed * 0.0015)) * 128;

		const Particle* const pParticles = swarm.getParticles();

		/*for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				//if(!(x % 10 ==0 || y % 10 ==0))
				screen.setPixel(x, y, 255 - red, 255 - green, 255 - blue);
			}
		}*/

		for (int i = 0; i < Swarm::PARTICLES_COUNT; i++) {
			Particle particle = pParticles[i];

			int x = (particle.x + 1)*Screen::SCREEN_WIDTH/2;
			int y = particle.y*Screen::SCREEN_WIDTH/2 + Screen::SCREEN_HEIGHT/2;
			screen.setPixel(x, y, red, green, blue);
		}

		screen.update();

		if (screen.processEvents() == false)
			break;

		
	}

	screen.close();
	
	return 0;
}