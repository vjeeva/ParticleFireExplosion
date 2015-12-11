#pragma once
#ifndef PARTICLE_H_
#define PARTICLE_H_
#include <stdlib.h>

struct Particle
{
	double v_x;
	double v_y;
	double xspeed;
	double yspeed;
public:
	Particle();
	~Particle();
	void update();
};

#endif

