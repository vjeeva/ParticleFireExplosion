#include "stdafx.h"
#include "Particle.h"
#include <stdlib.h>


Particle::Particle()
{
	v_x = (2.0 * rand() / RAND_MAX) - 1; //-1 to 1
	v_y = (2.0 * rand() / RAND_MAX) - 1; //-1 to 1

}


Particle::~Particle()
{
}
