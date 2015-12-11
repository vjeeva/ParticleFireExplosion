#include "stdafx.h"
#include "Swarm.h"


Swarm::Swarm()
{
	v_pParticles = new Particle[NUMPARTICLES];
}


Swarm::~Swarm()
{
	delete[] v_pParticles;
}
