#include "controller.h"

#include "../physics/physics.h"
#include "../system/timer.h"
#include "../system/input.h"
#include "flywheel.h"

#define BASE_ANGULAR_VELOCITY RPM_TO_RADS_PER_SEC(10.0f)

float currentTime = 0.0f;
float timeStep = 0.0f;
float timeScale;
float timeScaleStep;

float getTimeStep()
{
    return timeStep;
}

float getTimeScale()
{
    return timeScale;
}

float computeBaseTimeScale()
{
    float ts = fabsf(BASE_ANGULAR_VELOCITY / getFlywheel().angularVelocity);
    return ts;
}

float computeTimeScaleStep()
{
    float ts = computeBaseTimeScale();
    float upperTs = ts * 10.0f;
    float tss = (upperTs - ts) / 10.0f;
    return tss;
}

void initializeController()
{
    timeScale = computeBaseTimeScale();
    timeScaleStep = computeBaseTimeScale();
}

void updateController()
{
    timeStep = 0.0f;

    static bool isUpDown = false;
    if(isUpPressed())
    {
        if(!isUpDown)
        {
            timeScale += timeScaleStep;
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
            timeScale -= timeScaleStep;
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