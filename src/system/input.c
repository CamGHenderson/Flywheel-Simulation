#include "input.h"
#include <SDL2/SDL.h>

#define NUMBER_OF_KEYCODES 200

#define RIGHT_KEY getKeyCode(1073741903)
#define LEFT_KEY getKeyCode(1073741904)
#define UP_KEY 152
#define DOWN_KEY 151

bool keys[NUMBER_OF_KEYCODES];

void initializeInput()
{
    for(uint16_t i = 0; i < NUMBER_OF_KEYCODES; i++)
    {
        keys[i] = false;
    }
}

uint16_t getKeyCode(uint64_t key)
{
    if(key > 127)
        return (key - 1073741881) + 127;

    return key;
}

void updateKey(uint64_t rawKeycode, bool state)
{
    keys[getKeyCode(rawKeycode)] = state;
    //printf("%i\n", getKeyCode(rawKeycode));
}

bool isRightPressed()
{
    return keys[RIGHT_KEY];
}

bool isLeftPressed()
{
    return keys[LEFT_KEY];
}

bool isUpPressed()
{
    return keys[UP_KEY];
}

bool isDownPressed()
{
    return keys[DOWN_KEY];
}