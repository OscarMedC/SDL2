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

	// Ytan som fönstret innehåller
	SDL_Surface* screenSurface = NULL;
	// Bilden vi vill ladda och vissa på skärme
	SDL_Surface* helloWorld = NULL;

	// Vi vill visa bilden inuti fönstret och för att kunna göra det måste vi få bilden inuti fönstret. SDL_GetWindowSurface hämtar ytan som finns i fönstret.
	screenSurface = SDL_GetWindowSurface(testWindow);
	// Laddar bilden som vi vill visa med SDL_LoadBMP, funktionen tar in en address till en .BMP fil
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
					// "Blitting" tar en käll-yta och trycker en kopia på mål-ytan, första argumentet i SDL_BlitSurface är käll-ytan och det tredje är mål-ytan.
					SDL_BlitSurface(helloWorld, NULL, screenSurface, NULL); 
					/*Uppdaterar skärmen. När du ritar till skärmen så ritar du oftast inte till den skärm du "ser".
					De flesta renderingssystem som finns är "double-buffered". Dessa två buffrarna är front och back.
					När man anropar ritningssanrop som SDÖ_BlitSurface, så ritar man ofta still back-buffern. Det du ser på skärmen kallas för front-buffern.
					Hade vi bara haft en front-buffer så hade vi sett bilden samtidigt som saker ritas till den, vilket betyder att vi hade kollat på ofärdiga bilder.
					Så det vi gör är att vi ritar allt till en back-buffer och sen när vi är klara så byter vi med front-buffer så att vi kan se den färdiga bilden.
					
					Detta betyder också att man inte anropar SDL_UpdateWindowSruface efter varje blit, bara efter alla blits för den nuvarande skärmen är klara.*/
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