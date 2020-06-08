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
void renderChosenColour(SDL_Renderer* renderer) {

	int choice = 0;
	printf("What color do you want to display, input 1 for red, 2 for blue and 3 for green: \n");
	scanf_s("%d", &choice);

	if (choice == 1) {
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	}
	else if (choice == 2) {
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	}
	else if (choice == 3) {
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	}

	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	SDL_Delay(1500);
}
