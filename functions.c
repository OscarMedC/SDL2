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

void renderRedColour(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void renderGreenColour(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

void renderBlueColour(SDL_Renderer* renderer) {
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
}

int init(SDL_Window* window, SDL_Surface* surface){

	// SDL initiering statusflagga
	int success = TRUE;

	// Initierar SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
		success = FALSE;
	}
	else {
		// Uint32 flags = SDL_WINDOW_OPENGL | SDL_WINDOW_MAXIMIZED;
		window = SDL_CreateWindow(
			"A Small Cute Window",			// Fönsternamn
			SDL_WINDOWPOS_UNDEFINED,		// Initiel x position	
			SDL_WINDOWPOS_UNDEFINED,		// Initiel y position
			SCREEN_WIDTH,					// Bredd, i pixlar
			SCREEN_HEIGHT,					// Höjd, i pixlar
			SDL_WINDOW_OPENGL 				// Flaggningar - se Bilaga A	
		);
		// Kollar om fönstret kunde skapas
		if (window == NULL) {
			// Ifall det inte gick att skapa fönstret
			printf("Kunde inte skapa fönstret: %s\n", SDL_GetError());
			success = FALSE;
		}
		else {
			surface = SDL_GetWindowSurface(window);
		}
	}
	return success;
}

void loadImageHelloWorld(SDL_Window* window, SDL_Surface* surface) {

	int success = TRUE;

	// Ytan som fönstret innehåller
	// Bilderna vi vill ladda och vissa på skärmen
	SDL_Surface* helloWorld = NULL;
	// Laddar bilden som vi vill visa med SDL_LoadBMP, funktionen tar in en address till en .BMP fil
	helloWorld = SDL_LoadBMP("Assets/helloworld.bmp");
	SDL_BlitSurface(helloWorld, NULL, surface, NULL);
}

void loadImageHelloTworld(SDL_Window* window) {

	// Ytan som fönstret innehåller
	SDL_Surface* screenSurface = NULL;
	// Bilderna vi vill ladda och vissa på skärmen
	SDL_Surface* helloTworld = NULL;

	// Vi vill visa bilden inuti fönstret och för att kunna göra det måste vi få bilden inuti fönstret. SDL_GetWindowSurface hämtar ytan som finns i fönstret.
	screenSurface = SDL_GetWindowSurface(window);
	// Laddar bilden som vi vill visa med SDL_LoadBMP, funktionen tar in en address till en .BMP fil
	helloTworld = SDL_LoadBMP("Assets/hw.bmp");

	SDL_BlitSurface(helloTworld, NULL, screenSurface, NULL);
	SDL_UpdateWindowSurface(window);
}