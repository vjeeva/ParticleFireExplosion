#include "stdafx.h"
#include "Particle.h"
#include <stdlib.h>
#include <math.h>


Particle::Particle(): v_x(0), v_y(0)
{
	init();
}

void Particle::init()
{
	v_x = 0;
	v_y = 0;

	v_direction = (2 * 3.14 * rand()) / RAND_MAX;
	v_speed = (0.04 * rand()) / RAND_MAX;
	v_speed *= v_speed; //motion tweak
}

Particle::~Particle()
{
}

void Particle::update(int interval) 
{

	v_direction += interval*0.0004; //motion tweak

	double xspeed = v_speed * cos(v_direction);
	double yspeed = v_speed * sin(v_direction);

	v_x += xspeed * interval;
	v_y += yspeed * interval;

	if (v_x < -1 || v_x > 1 || v_y < -1 || v_y > 1) {
		init(); //reset to middle
	}

	if (rand() < RAND_MAX / 100) {
		init();
	}
}
