#include "functions.h"

int main(int argc, char* argv[]) {

	SDL_Window* testWindow = NULL;		// Deklarera en pekare 

	SDL_Init(SDL_INIT_VIDEO);			// Initierar SDL2

	Uint32 start = 0;					// starttid f�r timer
	int running = 1;					// Timerns start/stopp flagg

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

	int active = 1;
	Uint32 startTime = 0;

	// Programloop
	while (active)
	{
		//F�nga n�sta h�ndelse
		SDL_Event event;
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				break;
			}
			else if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				// Registrerar och skriver ut tiden sedan programmet startade i millisekunder, och den nya tiden om timern "startades" om
				case SDLK_SPACE:
					// Den nuvarande tiden - tiden n�r timer "startades" om e.g. 8000 - 7800 = 200 millisekunder eller 8000 - 0 = 8000 millisekunder
					printf("Time since start %d\nPress Enter to restart timer\n", SDL_GetTicks() - startTime); 
					break;
				// Registrerar vilken tid sen programmets start som klockan ska "startas" om p�
				case SDLK_RETURN:
					startTime = SDL_GetTicks();
					printf("Timer restarted!\n");
					break;
				}
			}
		}
	}

	// St�ngar och "f�rst�r" f�nstret
	SDL_DestroyWindow(testWindow);

	// St�dar upp
	SDL_Quit();
	return 0;

}