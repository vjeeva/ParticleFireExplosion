// ParticleFireExplosion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <SDL.h>
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

	while (true) {
		//Update particles

		//Draw particles
		for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) {
			for (int x = 0; x < Screen::SCREEN_WIDTH; x++) {
				screen.setPixel(x, y, 128, 0, 255);
			}
		}

		screen.setPixel(400, 300, 255, 255, 255);

		//Draw the screen
		screen.update();

		//Check for messages/events
		if (!screen.processEvents()) {
			break;
		}
	}

	return 0;
}
