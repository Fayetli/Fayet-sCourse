#include "Particle.h"
#include "Screen.h"
#include <cmath>

namespace aye {

	Particle::Particle() {
		
		init();

		/*x = ((2.0 * rand()) / RAND_MAX) - 1;
		y = ((2.0 * rand()) / RAND_MAX) - 1;
		
		xspeed = 0.0003 * ((2.0 * rand()) / RAND_MAX - 1);
		yspeed = 0.0003 * ((2.0 * rand()) / RAND_MAX - 1);*/
 	}
	void Particle::init() {
		x = NULL;
		y = NULL;

		direction = (2 * M_PI * rand()) / RAND_MAX;
		speed = (0.02 * rand()) / RAND_MAX;
		speed *= speed;
	}
	Particle::~Particle() {

	}
	void Particle::update(int interval) {
		
		direction += interval * 0.001;

		xspeed = speed * cos(direction);
		yspeed = speed * sin(direction);

		x += interval*xspeed;
		y += interval*yspeed;

		if (x < -1 || x > 1 || y < -1 || y > 1) {
			speed = -speed;
			//init();
		}

		if (rand() < RAND_MAX / 100) {
			init();
		}
		/*x += xspeed;
		y += yspeed;*/

		/*if (x < -1 || x >= 1.0)
			xspeed = -xspeed;
		if (y < -1 || y >= 1.0)
			yspeed = -yspeed;*/
	}
}