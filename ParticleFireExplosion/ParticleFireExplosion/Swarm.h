#pragma once
#ifndef SWARv_H_
#define SWARv_H_
#include "Particle.h"

class Swarm
{
public:
	const static int NUMPARTICLES = 5000;
private:
	Particle * v_pParticles;
	int lastTime;
public:
	Swarm();
	~Swarm();
	void update(int elapsed);
	const Particle * const getParticles() { return v_pParticles; };
};

#endif

