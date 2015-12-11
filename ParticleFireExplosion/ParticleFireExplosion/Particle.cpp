#include "stdafx.h"
#include "Particle.h"
#include <stdlib.h>
#include <math.h>


Particle::Particle(): v_x(0), v_y(0)
{
	v_direction = (2 * 3.14 * rand()) / RAND_MAX;
	v_speed = (0.0001 * rand()) / RAND_MAX;
}


Particle::~Particle()
{
}

void Particle::update(int interval) 
{
	double xspeed = v_speed * cos(v_direction);
	double yspeed = v_speed * sin(v_direction);

	v_x += xspeed * interval;
	v_y += yspeed * interval;
}
