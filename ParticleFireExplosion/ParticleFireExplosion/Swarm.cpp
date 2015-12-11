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

void Swarm::update()
{
	for (int i = 0; i < Swarm::NUMPARTICLES; i++) {
		v_pParticles[i].update();
	}
}
