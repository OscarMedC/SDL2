#include "functions.h"

int main(int argc, char* argv[]) {

	SDL_Window* testWindow = NULL;		// Deklarera en pekare 

	SDL_Init(SDL_INIT_VIDEO);			// Initierar SDL2

	int active = 1;					

	Uint32 flags = SDL_WINDOW_OPENGL | SDL_WINDOW_MAXIMIZED;

	testWindow = SDL_CreateWindow(
		"A Small Cute Window",			// Fönsternamn
		SDL_WINDOWPOS_UNDEFINED,		// Initiel x position	
		SDL_WINDOWPOS_UNDEFINED,		// Initiel y position
		640,							// Bredd, i pixlar
		480,							// Höjd, i pixlar
		SDL_WINDOW_OPENGL 				// Flaggningar - se Bilaga A	
	);

	// Kollar om fönstret kunde skapas
	if (testWindow == NULL) {
		// Ifall det inte gick att skapa fönstret
		printf("Kunde inte skapa fönstret: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Surface* screenSurface = NULL;
	SDL_Surface* helloWorld = NULL;

	screenSurface = SDL_GetWindowSurface(testWindow);
	helloWorld = SDL_LoadBMP("Assets/helloworld.bmp");

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
				case SDLK_SPACE:
					SDL_BlitSurface(helloWorld, NULL, screenSurface, NULL);
					SDL_UpdateWindowSurface(testWindow);
					break;
				case SDLK_RETURN:
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