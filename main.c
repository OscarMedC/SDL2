#include <stdio.h>
#include <SDL.h>

int main(int argc, char* argv[]) {

	SDL_Window* testWindow = NULL;		// Deklarera en pekare 

	SDL_Init(SDL_INIT_VIDEO);			// Initierar SDL2

	testWindow = SDL_CreateWindow(
		"A Small Cute Window",		// Fönsternamn
		SDL_WINDOWPOS_UNDEFINED,		// Initiel x position	
		SDL_WINDOWPOS_UNDEFINED,		// Initiel y position
		640,							// Bredd, i pixlar
		480,							// Höjd, i pixlar
		SDL_WINDOW_OPENGL				// Flaggningar - se appendix a
	);

	// Kollar om fönstret kunde skapas
	if (testWindow == NULL) {
		// Ifall det inte gick att skapa fönstret
		printf("Kunde inte skapa fönstret: %s\n", SDL_GetError());
		return 1;
	}

	// Fönstret är nu öppet: kan länga in programloop här

	SDL_Delay(3000);	//Pausa körningen i 3000 millisekunder, t.ex.

	// Stängar och "förstör" fönstret
	SDL_DestroyWindow(testWindow);

	// Städar upp
	SDL_Quit();
	return 0;
	



	return 0;
}