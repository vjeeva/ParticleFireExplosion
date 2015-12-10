// ParticleFireExplosion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SDL.h>
#include <math.h>
#include "Screen.h"
using namespace std;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main(int argc, char *argv[])
{
	Screen screen;
	if (!screen.init()) {
		cout << "Error initializing SDL." << endl;
	}

	int max = 0;

	while (true) {
		//Update particles
		int elapsed = SDL_GetTicks();
		unsigned char red = (unsigned char)((1 + sin(elapsed*0.0001)) * 128);
		unsigned char green = (unsigned char)((1 + sin(elapsed*0.0002)) * 128);
		unsigned char blue = (unsigned char)((1 + sin(elapsed*0.0003)) * 128);

		if (green > max) max = green;

		//Draw particles
		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, red, green, blue);
			}
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
