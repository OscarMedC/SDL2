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

static const int SCREEN_HEIGHT = 480;
static const int SCREEN_WIDTH = 640;
static const int TRUE = 1;
static const int FALSE = 0;

void renderRandomColours(SDL_Renderer* renderer);
void renderRedColour(SDL_Renderer* renderer);
void renderGreenColour(SDL_Renderer* renderer);
void renderBlueColour(SDL_Renderer* renderer);
int init(SDL_Window* window, SDL_Surface* surface);
void loadImageHelloWorld(SDL_Window* window, SDL_Surface* surface);
void loadImageHelloTworld(SDL_Window* window);

#endif
