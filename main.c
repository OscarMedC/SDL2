#include <stdio.h>
#include <SDL.h>

int main(int argc, char* argv[]) {

	SDL_Window* testWindow = NULL;		// Deklarera en pekare 

	SDL_Init(SDL_INIT_VIDEO);			// Initierar SDL2

	Uint32 flags = SDL_WINDOW_OPENGL | SDL_WINDOW_MAXIMIZED;

	testWindow = SDL_CreateWindow(
		"A Small Cute Window",			// F�nsternamn
		SDL_WINDOWPOS_UNDEFINED,		// Initiel x position	
		SDL_WINDOWPOS_UNDEFINED,		// Initiel y position
		640,							// Bredd, i pixlar
		480,							// H�jd, i pixlar
		SDL_WINDOW_OPENGL 				// Flaggningar - se Bilaga A	
	);

	// Startar rendering
	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer(testWindow, -1, SDL_RENDERER_ACCELERATED);

	// Kollar om f�nstret kunde skapas
	if (testWindow == NULL) {
		// Ifall det inte gick att skapa f�nstret
		printf("Kunde inte skapa f�nstret: %s\n", SDL_GetError());
		return 1;
	}

	int active = 0;

	// Programloop

	while (active <= 5) {
		// Ritar sk�rmen r�d
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);

		SDL_Delay(2000);

		// Ritar sk�rmen gr�n
		SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);

		SDL_Delay(2000);

		//Ritar sk�rmen bl�
		SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);

		SDL_Delay(2000);

		printf("Round: %d\n", active);
		active++;
	}

	// St�ngar och "f�rst�r" f�nstret
	SDL_DestroyWindow(testWindow);

	// St�dar upp
	SDL_Quit();
	return 0;

}