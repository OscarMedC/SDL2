#include "functions.h"


void renderRandomColours(SDL_Renderer* renderer) {
	time_t t;
	srand((unsigned)time(&t));

	Uint8 r = rand() % 255;
	Uint8 g = rand() % 255;
	Uint8 b = rand() % 255;

	SDL_SetRenderDrawColor(renderer, r, g, b, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(1500);
}

