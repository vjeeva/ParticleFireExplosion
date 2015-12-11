#include "stdafx.h"
#include "Screen.h"


Screen::Screen(): v_window(NULL), v_renderer(NULL), v_texture(NULL), v_buffer(NULL)
{

}

bool Screen::init() {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		return false;
	}

	v_window = SDL_CreateWindow("Particle Fire Explosion", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (v_window == NULL) {
		SDL_Quit();
		return false;
	}

	v_renderer = SDL_CreateRenderer(v_window, -1, SDL_RENDERER_PRESENTVSYNC);
	v_texture = SDL_CreateTexture(v_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

	if (v_renderer == NULL) {
		SDL_DestroyWindow(v_window);
		SDL_Quit();
		return false;
	}

	if (v_texture == NULL) {
		SDL_DestroyRenderer(v_renderer);
		SDL_DestroyWindow(v_window);
		SDL_Quit();
		return false;
	}

	v_buffer = new Uint32[SCREEN_WIDTH*SCREEN_HEIGHT];

	memset(v_buffer, 0, SCREEN_WIDTH*SCREEN_HEIGHT*sizeof(Uint32));

	update();

	return true;
}

bool Screen::processEvents() {
	SDL_Event event;

	while (SDL_PollEvent(&event)) {
		if (event.type == SDL_QUIT) {
			return false;
		}
	}
	return true;
}

void Screen::close() {
	delete[] v_buffer;
	SDL_DestroyRenderer(v_renderer);
	SDL_DestroyTexture(v_texture);
	SDL_DestroyWindow(v_window);
	SDL_Quit();
}

void Screen::update() {
	SDL_UpdateTexture(v_texture, NULL, v_buffer, SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(v_renderer);
	SDL_RenderCopy(v_renderer, v_texture, NULL, NULL);
	SDL_RenderPresent(v_renderer);
}

void Screen::setPixel(int x, int y, Uint8 red, Uint8 green, Uint8 blue) {
	
	if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT) {
		return;
	}
	
	Uint32 color = 0;

	color += red;
	color <<= 8;
	color += green;
	color <<= 8;
	color += blue;
	color <<= 8;
	color += 0xFF;

	v_buffer[(y*SCREEN_WIDTH) + x] = color;
}