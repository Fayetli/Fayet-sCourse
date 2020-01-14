#include "Swarm.h"

namespace aye {
	Swarm::Swarm():lastTime(NULL) {
		pParticles = new Particle[PARTICLES_COUNT];
	}
	Swarm::~Swarm() {
		delete[] pParticles;
	}
	void Swarm::update(int timed) {

		int interval = timed - lastTime;


		for (int i = 0; i < Swarm::PARTICLES_COUNT; i++) {
			pParticles[i].update(interval);
		}

		lastTime = timed;
	}

}