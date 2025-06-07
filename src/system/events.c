#include "events.h"
#include <stdbool.h>
#include <SDL2/SDL.h>
#include "input.h"

bool open = true;

bool isWindowOpen()
{
    return open;
}

void updateEvents()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch(event.type)
        {
            case SDL_QUIT:
                open = false;
                break;

            case SDL_KEYDOWN:
                updateKey(event.key.keysym.sym, true);
                break;

            case SDL_KEYUP:
                updateKey(event.key.keysym.sym, false);
                break;
        }
    }
}