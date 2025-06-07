#include "telemetry.h"

#include "../definitions/color.h"
#include "../definitions/units.h"
#include "../graphics/graphics.h"
#include "../physics/physics.h"
#include "controller.h"
#include "flywheel.h"
#include "ball.h"

#include <stdio.h>
#include <math.h>

#define FLYWHEEL getFlywheel()
#define BALL getBall()

Vec2f ballInitialPos; 
uint16_t messageCount;

void initializeTelemetry()
{
    ballInitialPos = getBall().pos;
}

void drawCentroidMarker(Body b)
{
    setGraphicsPosition(VEC_XY(b));
    setGraphicsColor(ORANGE);
    fillCircle(10.0f);
}

void drawLineBetweenCenters(Body b1, Body b2)
{
    setGraphicsColor(BLUE);
    setGraphicsPosition(VEC_XY(b1));
    drawLine(SUB_POS(b2, b1));
}

void drawLineBetweenVectors(Vec2f v1,  Vec2f v2)
{
    setGraphicsColor(BLUE);
    setGraphicsPosition(v1.x, v1.y);
    drawLine(SUB_VEC(v2, v1));
}

void drawAngleArc()
{
    float a1 = RADS_TO_DEG(atan2f(SUB_VEC(ballInitialPos, FLYWHEEL.pos))) + 1.0f;
    float a2 = 90.0f -RADS_TO_DEG(atan2f(SUB_VEC(BALL.pos, FLYWHEEL.pos)));

    setGraphicsColor(BLUE);
    setGraphicsPosition(VEC_XY(FLYWHEEL));
    drawArc(2 inch, a2, a1);
}

void drawLabel(const char* msg)
{
    setGraphicsPosition(20.0f, 20.0f + (messageCount * 30.0f));
    drawString(msg);
    messageCount++;
}

void drawDataMessage(char* message, float data, char* unit)
{
    char msgBuffer[100];
    float flywheelRPM = fabsf(RADS_PER_SEC_TO_RPM(getFlywheelAngularVelocity()));
    sprintf(msgBuffer, "%s%g%s", message, data, unit);
    setGraphicsPosition(20.0f, 20.0f + (messageCount * 30.0f));
    drawString(msgBuffer);
    messageCount++;
}

void drawMessages()
{   
    messageCount = 0;

    setGraphicsColor(PURPLE);
    drawDataMessage("Current Time ", getCurrentTime(), " sec");
    drawDataMessage("Time Scale ", getTimeScale(), "X");

    setGraphicsColor(YELLOW);
    drawLabel("Fuck you!");

    setGraphicsColor(RED);
    drawDataMessage("Flywheel ", fabsf(RADS_PER_SEC_TO_RPM(getFlywheelAngularVelocity())), " RPM");
    
    setGraphicsColor(GREEN);
    drawDataMessage("Ball ", fabsf(RADS_PER_SEC_TO_RPM(getBallAngularVelocity())), " RPM");
    drawDataMessage("Projectile ", fabsf(getProjectileLinearVelocity()), "in/s");
    drawDataMessage("Projectile ", fabsf(RADS_PER_SEC_TO_RPM(getProjectileAngularVelocity())), " RPM");
}

void drawProjectileAngleDimension()
{
    drawLineBetweenCenters(FLYWHEEL, BALL);
    drawLineBetweenVectors(FLYWHEEL.pos, ballInitialPos);
    //drawAngleArc();
}

void drawTelemetry()
{
    drawProjectileAngleDimension();

    drawCentroidMarker(FLYWHEEL);
    drawCentroidMarker(BALL);

    drawMessages();
}

