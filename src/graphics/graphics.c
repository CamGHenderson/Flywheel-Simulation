#include "graphics.h"

#include <stdio.h>
#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfxPrimitives.h>

#define WINDOW_WIDTH 920
#define WINDOW_HEIGHT 720

SDL_Window* window;
SDL_Renderer* renderer;
TTF_Font* font;

float gX;
float gY;
float gAngle;

float offsetX;
float offsetY;

uint8_t gR = 0;
uint8_t gG = 0;
uint8_t gB = 0;

void initializeGraphics()
{
    if(SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("%s\n", "SDL video failed to initialize.");
        exit(0);
    }

    window = SDL_CreateWindow("Flywheel Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                            WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

    if(!window)
    {
        printf("%s %s\n", "Failed to create window. ", SDL_GetError());
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

    font = TTF_OpenFont("res/fonts/Courier_Prime/CourierPrime-Regular.ttf", 20);
    if(!font)
    {
        printf("%s\n", "Failed to load font");
        exit(0);
    }

    gX = 0.0f;
    gY = 0.0f;
    gAngle = 0.0f;

    offsetX = 0.0f;
    offsetY = 0.0f;
}

void freeGraphics()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void prepareGraphics()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void updateGraphics()
{
    SDL_RenderPresent(renderer);
}

void setGraphicsColor(uint8_t r, uint8_t g, uint8_t b)
{
    SDL_SetRenderDrawColor(renderer, r, g, b, 255);

    gR = r;
    gG = g;
    gB = b;
}

void setGraphicsPosition(float x, float y)
{
    gX = x;
    gY = y;
}

void setGraphicsViewOffset(float x, float y)
{
    offsetX = x;
    offsetY = y;
}

void setGraphicsRotation(float angle)
{
    gAngle = angle;
}

void fillRectangle(float width, float height)
{

}

void fillCircle(float diameter)
{
    filledCircleRGBA(renderer, CARTESIAN_TO_WINDOW_COORDS(gX, gY), diameter / 2.0f, gR, gG, gB, 255);
}

void drawRectangle(float width, float height)
{

}

void drawCircle(float diameter)
{
    aacircleRGBA(renderer, CARTESIAN_TO_WINDOW_COORDS(gX, gY), diameter / 2.0f, gR, gG, gB, 255);
}

void drawLine(float x, float y)
{
    aalineRGBA(renderer, CARTESIAN_TO_WINDOW_COORDS(gX, gY), CARTESIAN_TO_WINDOW_COORDS(gX + x, gY - y), gR, gG, gB, 255);
}

void drawArc(float radius, float startAngle, float endAngle)
{
    arcRGBA(renderer, CARTESIAN_TO_WINDOW_COORDS(gX, gY), radius, startAngle, endAngle, gR, gG, gB, 255);
}

void drawString(const char* string)
{
    SDL_Color c;
    c.r = gR;
    c.g = gG;
    c.b = gB;

    SDL_Surface* surface = TTF_RenderText_Solid(font, string, c);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect area;
    area.x = gX;
    area.y = CARTESIAN_Y_TO_WINDOW_Y(gY);
    area.w = (*surface).w;
    area.h = (*surface).h;

    SDL_RenderCopy(renderer, texture, NULL, &area);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

uint16_t getGraphicsWindowWidth()
{
    return WINDOW_WIDTH;
}

uint16_t getGraphicsWindowHeight()
{
    return WINDOW_HEIGHT;
}