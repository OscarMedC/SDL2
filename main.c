#include "functions.h"

int main(int argc, char* argv[]) {

	SDL_Window* testWindow = NULL;		// Deklarera en pekare 

	SDL_Init(SDL_INIT_VIDEO);			// Initierar SDL2

	Uint32 start = 0;					// starttid för timer
	int running = 1;					// Timerns start/stopp flagg

	Uint32 flags = SDL_WINDOW_OPENGL | SDL_WINDOW_MAXIMIZED;

	testWindow = SDL_CreateWindow(
		"A Small Cute Window",			// Fönsternamn
		SDL_WINDOWPOS_UNDEFINED,		// Initiel x position	
		SDL_WINDOWPOS_UNDEFINED,		// Initiel y position
		640,							// Bredd, i pixlar
		480,							// Höjd, i pixlar
		SDL_WINDOW_OPENGL 				// Flaggningar - se Bilaga A	
	);

	// Startar rendering
	SDL_Renderer* renderer = NULL;
	renderer = SDL_CreateRenderer(testWindow, -1, SDL_RENDERER_ACCELERATED);

	// Kollar om fönstret kunde skapas
	if (testWindow == NULL) {
		// Ifall det inte gick att skapa fönstret
		printf("Kunde inte skapa fönstret: %s\n", SDL_GetError());
		return 1;
	}

	int active = 1;
	Uint32 startTime = 0;

	// Programloop
	while (active)
	{
		//Fånga nästa händelse
		SDL_Event event;
		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				break;
			}
			else if (event.type == SDL_KEYDOWN) {
				switch (event.key.keysym.sym) {
				// Registrerar och skriver ut tiden sedan programmet startade i millisekunder, och den nya tiden om timern "startades" om
				case SDLK_SPACE:
					// Den nuvarande tiden - tiden när timer "startades" om e.g. 8000 - 7800 = 200 millisekunder eller 8000 - 0 = 8000 millisekunder
					printf("Time since start %d\nPress Enter to restart timer\n", SDL_GetTicks() - startTime); 
					break;
				// Registrerar vilken tid sen programmets start som klockan ska "startas" om på
				case SDLK_RETURN:
					startTime = SDL_GetTicks();
					printf("Timer restarted!\n");
					break;
				}
			}
		}
	}

	// Stängar och "förstör" fönstret
	SDL_DestroyWindow(testWindow);

	// Städar upp
	SDL_Quit();
	return 0;

}