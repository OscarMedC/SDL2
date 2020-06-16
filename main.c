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
		//Fånga nästa händelse
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

	// Stänger och "förstör" fönstret
	SDL_DestroyWindow(testWindow);

	// Städar upp
	SDL_Quit();
	return 0;

}