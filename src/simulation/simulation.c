#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../system/events.h"
#include "../system/input.h"
#include "../system/timer.h"

#include "../graphics/graphics.h"

#include "controller.h"
#include "telemetry.h"
#include "flywheel.h"
#include "ball.h"

void initializeSubsystems()
{
    initializeFlywheel();
    initalizeBall();
    initializeTelemetry();

    initializeGraphics();
    initializeInput();
    initializeTimer();
}

void updateSubsystems()
{
    updateGraphics();
    updateEvents();
    updateController();

    updateFlywheel(getTimeStep());
    updateBall(getCurrentTime(), getTimeStep());

    updateTimer();
}

void drawSubsystems()
{
    prepareGraphics();
    drawFlywheel();
    drawFlywheelTrack();
    drawBall();
    drawTelemetry();
}

int main()
{
    initializeSubsystems();

    while(isWindowOpen())
    {
        updateSubsystems();
        drawSubsystems();
    }

    freeGraphics();
    
    return 0;
}

