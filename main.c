#include "functions.h"

int main(int argc, char* argv[]) {

	SDL_Window* testWindow = NULL;		// Deklarera en pekare 

	SDL_Init(SDL_INIT_VIDEO);			// Initierar SDL2

	int active = 1;					

	Uint32 flags = SDL_WINDOW_OPENGL | SDL_WINDOW_MAXIMIZED;

	testWindow = SDL_CreateWindow(
		"A Small Cute Window",			// F�nsternamn
		SDL_WINDOWPOS_UNDEFINED,		// Initiel x position	
		SDL_WINDOWPOS_UNDEFINED,		// Initiel y position
		640,							// Bredd, i pixlar
		480,							// H�jd, i pixlar
		SDL_WINDOW_OPENGL 				// Flaggningar - se Bilaga A	
	);

	// Kollar om f�nstret kunde skapas
	if (testWindow == NULL) {
		// Ifall det inte gick att skapa f�nstret
		printf("Kunde inte skapa f�nstret: %s\n", SDL_GetError());
		return 1;
	}

	// Ytan som f�nstret inneh�ller
	SDL_Surface* screenSurface = NULL;
	// Bilden vi vill ladda och vissa p� sk�rme
	SDL_Surface* helloWorld = NULL;

	// Vi vill visa bilden inuti f�nstret och f�r att kunna g�ra det m�ste vi f� bilden inuti f�nstret. SDL_GetWindowSurface h�mtar ytan som finns i f�nstret.
	screenSurface = SDL_GetWindowSurface(testWindow);
	// Laddar bilden som vi vill visa med SDL_LoadBMP, funktionen tar in en address till en .BMP fil
	helloWorld = SDL_LoadBMP("Assets/helloworld.bmp");

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
					// "Blitting" tar en k�ll-yta och trycker en kopia p� m�l-ytan, f�rsta argumentet i SDL_BlitSurface �r k�ll-ytan och det tredje �r m�l-ytan.
					SDL_BlitSurface(helloWorld, NULL, screenSurface, NULL); 
					/*Uppdaterar sk�rmen. N�r du ritar till sk�rmen s� ritar du oftast inte till den sk�rm du "ser".
					De flesta renderingssystem som finns �r "double-buffered". Dessa tv� buffrarna �r front och back.
					N�r man anropar ritningssanrop som SD�_BlitSurface, s� ritar man ofta still back-buffern. Det du ser p� sk�rmen kallas f�r front-buffern.
					Hade vi bara haft en front-buffer s� hade vi sett bilden samtidigt som saker ritas till den, vilket betyder att vi hade kollat p� of�rdiga bilder.
					S� det vi g�r �r att vi ritar allt till en back-buffer och sen n�r vi �r klara s� byter vi med front-buffer s� att vi kan se den f�rdiga bilden.
					
					Detta betyder ocks� att man inte anropar SDL_UpdateWindowSruface efter varje blit, bara efter alla blits f�r den nuvarande sk�rmen �r klara.*/
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