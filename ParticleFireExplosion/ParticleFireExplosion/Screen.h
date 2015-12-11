#pragma once
#ifndef SCREEN_H_
#define SCREEN_H_

#include "SDL.h"
using namespace std;

class Screen
{
public:
	const static int SCREEN_WIDTH = 800;
	const static int SCREEN_HEIGHT = 600;
private:
	SDL_Window *v_window;
	SDL_Renderer *v_renderer;
	SDL_Texture *v_texture;
	Uint32 *v_buffer;
public:
	Screen();
	bool init();
	bool processEvents();
	void close();
	void update();
	void setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
};

#endif