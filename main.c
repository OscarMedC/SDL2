#include <stdio.h>
#include <SDL.h>

int main(int argc, char* argv[]) {

	SDL_Window* testWindow = NULL;		// Deklarera en pekare 

	SDL_Init(SDL_INIT_VIDEO);			// Initierar SDL2

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

	// Ändrar renderingsfärgen till RÖD (Bakgrunden kommer renderas i denna färg)
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

	// Rensar renderingsmålet med vald renderingsfärg
	SDL_RenderClear(renderer);

	// Kollar om fönstret kunde skapas
	if (testWindow == NULL) {
		// Ifall det inte gick att skapa fönstret
		printf("Kunde inte skapa fönstret: %s\n", SDL_GetError());
		return 1;
	}

	// Fönstret är nu öppet: kan länga in programloop här

	// Uppdaterar skärmen med ? 
	SDL_RenderPresent(renderer);

	// Pausa körningen i 3000 millisekunder, t.ex.
	SDL_Delay(3000);	

	// Stängar och "förstör" fönstret
	SDL_DestroyWindow(testWindow);

	// Städar upp
	SDL_Quit();
	return 0;

}