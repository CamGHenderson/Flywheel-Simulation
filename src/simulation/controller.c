#include "controller.h"

#include "../system/timer.h"
#include "../system/input.h"

#define TIME_SCALE_CHANGE 0.125f

float currentTime = 0.0f;
float timeStep = 0.0f;
float timeScale = 1.0f;

float getTimeStep()
{
    return timeStep;
}

float getTimeScale()
{
    return timeScale;
}

void updateController()
{
    timeStep = 0.0f;

    static bool isUpDown = false;
    if(isUpPressed())
    {
        if(!isUpDown)
        {
            timeScale += TIME_SCALE_CHANGE;
        }
        isUpDown = true;
    }
    else
    {
        isUpDown = false;
    }

    static bool isDownDown = false;
    if(isDownPressed())
    {
        if(!isDownDown && timeScale != 0.0f)
        {
            timeScale -= TIME_SCALE_CHANGE;
        }
        isDownDown = true;
    }
    else
    {
        isDownDown = false;
    }
    
    if(isLeftPressed())
    {
        timeStep = -getDeltaTime() * timeScale;
    }
    
    if(isRightPressed())
    {
        timeStep = getDeltaTime() * timeScale;
    }

    if(currentTime <= 0.0f && timeStep < 0.0f)
    {
        timeStep = 0.0f;
        currentTime = 0.0f;
    }

    currentTime += timeStep;
}

float getCurrentTime()
{
    return currentTime;
}