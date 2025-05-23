#include "graphics.h"

#include <stdio.h>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

SDL_Window* window;
SDL_Renderer* renderer;
TTF_Font* font;

void initializeGraphics()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("%s\n", "SDL video failed to initialize.");
        exit(0);
    }

    window = SDL_CreateWindow("Application", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                            800, 600, SDL_WINDOW_SHOWN);

    if(!window)
    {
        printf("%s\n", "Failed to create window.");
        exit(0);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    if(!renderer)
    {
        printf("%s\n", "Failed to create renderer");
        exit(0);
    }

    if(TTF_Init() == -1)
    {
        printf("%s\n", "Failed to initialize sdl font library");
        exit(0);
    }

    font = TTF_OpenFont("res/fonts/Courier_Prime/CourierPrime-Regular.ttf", 24);
    if(!font)
    {
        printf("%s\n", "Failed to load font");
        exit(0);
    }
}

bool isGraphicsWindowOpen()
{
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        if(event.type == SDL_QUIT)
            return false;
    }

    return true;
}

void freeGraphics()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

void prepareGraphics()
{
    setGraphicsColor(0, 0, 0);
    SDL_RenderClear(renderer);
}

void updateGraphics()
{
    SDL_RenderPresent(renderer);
}

void setGraphicsColor(uint8_t r, uint8_t g, uint8_t b)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);
}

void drawRectangle(float x, float y, float width, float height)
{
    SDL_Rect r = {x, y, width, height};
    SDL_RenderFillRect(renderer, &r);
}

void drawLine(float x1, float y1, float x2, float y2)
{
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}

void drawString(float x, float y, const char* string)
{
    SDL_Color c;
    SDL_GetRenderDrawColor(renderer, &c.r, &c.g, &c.b, &c.a);
    SDL_Surface* s = TTF_RenderText_Solid(font, string, c);
    SDL_Texture* t = SDL_CreateTextureFromSurface(renderer, s);

    SDL_RenderCopy(renderer, t, NULL, NULL);

    SDL_DestroyTexture(t);
    SDL_FreeSurface(s);
}