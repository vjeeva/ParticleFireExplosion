// ParticleFireExplosion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"
#include "Swarm.h"
#include "Particle.h"
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(int argc, char *argv[])
{
	srand(time(NULL));

	Screen screen;
	if (!screen.init()) {
		cout << "Error initializing SDL." << endl;
	}

	Swarm swarm;

	int max = 0;

	while (true) {
		//Update particles
		int elapsed = SDL_GetTicks();

		screen.clear();
		swarm.update(elapsed);

		unsigned char red = (unsigned char)((1 + sin(elapsed*0.0001)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsed*0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed*0.0003)) * 128);

		const Particle * const pParticles = swarm.getParticles();
		for (int i = 0; i < Swarm::NUMPARTICLES; i++) {
			Particle particle = pParticles[i];

			int x = (particle.v_x + 1) * Screen::SCREEN_WIDTH/2;
			int y = particle.v_y * Screen::SCREEN_WIDTH / 2 + Screen::SCREEN_HEIGHT / 2;

			screen.setPixel(x, y, red, green, blue);
		}

		//Draw the screen
		screen.update();

		//Check for messages/events
		if (!screen.processEvents()) {
			break;
		}
	}

	return 0;
}
