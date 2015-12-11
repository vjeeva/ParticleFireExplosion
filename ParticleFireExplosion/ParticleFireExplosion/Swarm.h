#pragma once
#ifndef SWARv_H_
#define SWARv_H_
#include "Particle.h"

class Swarm
{
public:
	const static int NUMPARTICLES = 1000;
private:
	Particle * v_pParticles;
public:
	Swarm();
	~Swarm();
	void update();
	const Particle * const getParticles() { return v_pParticles; };
};

#endif

