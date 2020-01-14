#pragma once
#ifndef PARTICLE_H
#define PARTICLE_H

#include <cstdlib>

namespace aye {

	struct Particle
	{
		double x;
		double y;
		double xspeed;
		double yspeed;
		double speed;
		double direction;
	private:
		void init();
	public:
		Particle();
		virtual ~Particle();
		void update(int interval);
	};

}
#endif // ! PARTICLE_H
