#include "flywheel.h"
#include "../definitions/color.h"
#include "../definitions/units.h"
#include "../definitions/dimensions.h"
#include "../graphics/graphics.h"
#include "../graphics/renderer.h"
#include "controller.h"
#include <stdint.h>

Body flywheel;

void initializeFlywheel()
{
    flywheel = createCircularBody(3 inch);
    flywheel.pos.x = getGraphicsWindowWidth() / 2.0f;
    flywheel.pos.y = getGraphicsWindowHeight() / 2.0f;
    flywheel.angularVelocity = -RPM_TO_RADS_PER_SEC(4000.0f);
}

void updateFlywheel(float deltaTime)
{
    flywheel.angle = flywheel.angularVelocity * getCurrentTime();
    
    // no need to update body since the angle is more accuratly handled by using current time
    //updateBody(&flywheel, deltaTime);
}

void drawFlywheel()
{
    drawBody(flywheel, RED);

    setGraphicsColor(WHITE);
    fillCircle(1.5 inch);

    setGraphicsColor(GREY);
    fillCircle(0.5 inch);

    drawCircleOrientationLine(flywheel);
}

void drawFlywheelTrack()
{
    setGraphicsPosition(flywheel.pos.x, flywheel.pos.y);

    setGraphicsColor(WHITE);
    for(uint16_t i = 0; i < 40; i++)
        drawArc(TRACK_RADIUS + (i / 4.0f), 135, 225);
}

Body getFlywheel()
{
    return flywheel;
}

float getFlywheelAngularVelocity()
{
    return flywheel.angularVelocity;
}

