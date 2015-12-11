#include "stdafx.h"
#include "Particle.h"
#include <stdlib.h>
#include <math.h>


Particle::Particle(): v_x(0), v_y(0)
{
	v_direction = (2 * 3.14 * rand()) / RAND_MAX;
	v_speed = (0.001 * rand()) / RAND_MAX;
}


Particle::~Particle()
{
}

void Particle::update() 
{
	double xspeed = v_speed * cos(v_direction);
	double yspeed = v_speed * sin(v_direction);

	v_x += xspeed;
	v_y += yspeed;
}
