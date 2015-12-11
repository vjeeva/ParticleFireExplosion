#pragma once
#ifndef PARTICLE_H_
#define PARTICLE_H_
#include <stdlib.h>

struct Particle
{
	double v_x;
	double v_y;
	double v_direction;
	double v_speed;
public:
	Particle();
	~Particle();
	void update(int interval);
};

#endif

