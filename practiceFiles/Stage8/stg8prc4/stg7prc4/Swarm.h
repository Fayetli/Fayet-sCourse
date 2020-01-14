#pragma once
#ifndef SWARM_H
#define SWARM_H

#include "Particle.h"

namespace aye {

	class Swarm
	{
	public:
		const static int PARTICLES_COUNT = 7500;
	private:
		Particle* pParticles;
		int lastTime;
	public:
		Swarm();
		virtual ~Swarm();
		void update(int timed);
		const Particle* const getParticles() { return pParticles; };
	};

}
#endif