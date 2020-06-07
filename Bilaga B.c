#include "SDL.h"

int main(int argc, char* argv[])
{
    SDL_Window* window;
    SDL_Renderer* renderer;

    /* Initierar SDL */
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return 1;

    /* Skapar fönstret där vi kommer rita. */
    window = SDL_CreateWindow("SDL_RenderClear",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        512, 512,
        0);

    /* Vi måste kalla SDL_CreateRenderer för att ritningsanropen ska ha en effekt på detta fönster. */
    renderer = SDL_CreateRenderer(window, -1, 0);

    /* Bestäm färgen som ska ritas. Här är den röd. */
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    /* Ritar hela skärmen röd. */
    SDL_RenderClear(renderer);

    /* Hittils så va allt ritat "Behind the scenes".
       Detta kommer vissa det nya röda inhållet i fönstret. */
    SDL_RenderPresent(renderer);

    /* Ger oss tid att se fönstret. */
    SDL_Delay(5000);

    /* Glöm inte att städa upp :) */
    SDL_Quit();
    return 0;
}
