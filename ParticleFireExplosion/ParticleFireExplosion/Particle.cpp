#include "stdafx.h"
#include "Particle.h"
#include <stdlib.h>


Particle::Particle()
{
	v_x = (2.0 * rand() / RAND_MAX) - 1; //-1 to 1
	v_y = (2.0 * rand() / RAND_MAX) - 1; //-1 to 1
	xspeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
	yspeed = 0.001 * (((2.0 * rand()) / RAND_MAX) - 1);
}


Particle::~Particle()
{
}

void Particle::update() 
{
	v_x += xspeed;
	v_y += yspeed;

	if (v_x <= -1.0 || v_x >= 1.0) {
		xspeed = -xspeed;
	}
	if (v_y <= -1.0 || v_y >= 1.0) {
		yspeed = -yspeed;
	}
}
