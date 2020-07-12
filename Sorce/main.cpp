#define SDL_MAIN_HANDLED

#include "SDL2/SDL.h"
#include <iostream>
#include "Game.h"

int main()
{
    if(!SDL_Init(SDL_INIT_EVERYTHING)){
        Game g;
    }
    return 0;
}