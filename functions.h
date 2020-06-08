#ifndef FUNCTIONS_h
#define FUNCTIONS_h

#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>

enum KeyPresses {
	KEY_PRESS_UP,
	KEY_PRESS_DOWN,
	KEY_PRESS_LEFT,
	KEY_PRESS_RIGHT
};

void renderRandomColours(SDL_Renderer* renderer);
void renderRedColour(SDL_Renderer* renderer);
void renderGreenColour(SDL_Renderer* renderer);
void renderBlueColour(SDL_Renderer* renderer);

#endif
