#include "stdafx.h"
#include "Swarm.h"


Swarm::Swarm(): lastTime(0)
{
	v_pParticles = new Particle[NUMPARTICLES];
}


Swarm::~Swarm()
{
	delete[] v_pParticles;
}

void Swarm::update(int elapsed)
{	
	int interval = elapsed - lastTime;
	for (int i = 0; i < Swarm::NUMPARTICLES; i++) {
		v_pParticles[i].update(interval);
	}
	lastTime = elapsed;
}
