#include "functions.h"

int main(int argc, char* argv[]) {

	SDL_Window* testWindow = NULL;		// Deklarera en pekare 
	SDL_Surface* screenSurface = NULL;
	SDL_Surface* helloWorld = NULL;

	init(testWindow, screenSurface); // Initierar SDL2

	int active = 1;		

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
				case SDLK_SPACE:
					loadImageHelloWorld(testWindow, screenSurface);
					SDL_UpdateWindowSurface(testWindow);
					break;
				case SDLK_RETURN:
					break;
				}
			}
		}
	}

	// St�nger och "f�rst�r" f�nstret
	SDL_DestroyWindow(testWindow);

	// St�dar upp
	SDL_Quit();
	return 0;

}