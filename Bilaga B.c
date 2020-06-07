#include "SDL.h"

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;

    /* Initierar SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return 1;

    /* Skapar f�nstret d�r vi kommer rita. */
    window = SDL_CreateWindow("SDL_RenderClear",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        512, 512,
        0);

    /* Vi m�ste kalla SDL_CreateRenderer f�r att ritningsanropen ska ha en effekt p� detta f�nster. */
    renderer = SDL_CreateRenderer(window, -1, 0);

    /* Best�m f�rgen som ska ritas. H�r �r den r�d. */
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    /* Ritar hela sk�rmen r�d. */
    SDL_RenderClear(renderer);

    /* Hittils s� va allt ritat "Behind the scenes".
       Detta kommer vissa det nya r�da inh�llet i f�nstret. */
    SDL_RenderPresent(renderer);

    /* Ger oss tid att se f�nstret. */
    SDL_Delay(5000);

    /* Gl�m inte att st�da upp :) */
    SDL_Quit();
    return 0;
}
