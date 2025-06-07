#include "ball.h"
#include "../definitions/units.h"
#include "../definitions/dimensions.h"
#include "../definitions/color.h"

#include "../graphics/renderer.h"
#include "../graphics/keyframe.h"
#include "../physics/physics.h"

#include "controller.h"
#include "flywheel.h"

#include <stdio.h>

#define FLYWHEEL getFlywheel()

Body ball;

float projectileAngle;
float projectileAngularVelocity;

float timeOfProjectileRelease = 0.0f;
float previousBallAngle = 0.0f;

KeyFrame keyFrames[3];

float computeProjectileAngularVelocity()
{
    return (DIAMETER(FLYWHEEL) * FLYWHEEL.angularVelocity) / ((2.0f * TRACK_RADIUS) + DIAMETER(FLYWHEEL));
}

float computeBallAngularVelocity()
{
    return -(2.0f * projectileAngularVelocity * TRACK_RADIUS) / DIAMETER(ball);
}

void intializeKeyFrames()
{
    projectileAngle = DEG_TO_RADS(225.0f);
    moveBallToAngle(projectileAngle);
    keyFrames[0].b = ball;
    keyFrames[0].time = 0.0f;

    moveBallToAngle(DEG_TO_RADS(135.0f));
    float f2Time = DEG_TO_RADS(225.0f - 135.0f) / ball.angularVelocity;
    keyFrames[1].b = ball;
    keyFrames[1].b.angle = ball.angularVelocity * f2Time;
    keyFrames[1].time = f2Time;

    moveBallToAngle(projectileAngle);
}

void initalizeBall()
{
    ball = createCircularBody(2.5 inch);
    projectileAngularVelocity = computeProjectileAngularVelocity(); 
    ball.angularVelocity = computeBallAngularVelocity(); 

    projectileAngle = DEG_TO_RADS(225.0f);
    moveBallToAngle(projectileAngle);
    //intializeKeyFrames();
}

void updateBall(float currentTime, float timeStep)
{
    if(RADS_TO_DEG(projectileAngle) <= 135.0f)
    {
        if(timeOfProjectileRelease == 0.0f)
        {
            timeOfProjectileRelease = currentTime;
        }

        if(currentTime <= keyFrames[1].time)
        {
            projectileAngle += projectileAngularVelocity * timeStep;
            moveBallToAngle(projectileAngle);
        }

        float mag = -(projectileAngularVelocity * PATH_RADIUS);
        float a = DEG_TO_RADS(45.0f);
        ball.velocity.x = cos(a) * mag;
        ball.velocity.y = sin(a) * mag;
        updateBody(&ball, timeStep);
    }
    else
    {
        //ball.angle = ball.angularVelocity * (getCurrentTime() / keyFrames[1].time);
        //projectileAngle = DEG_TO_RADS(225.0f) + (DEG_TO_RADS(90.0f) * (getCurrentTime() / keyFrames[1].time)); 
        
        projectileAngle += projectileAngularVelocity * getTimeStep();
        moveBallToAngle(projectileAngle);
        updateBody(&ball, timeStep);
    }
}

void drawBall()
{
    drawBody(ball, GREEN);
    drawCircleOrientationLine(ball);
}

void moveBallToAngle(float angle)
{
    ball.pos.x = (cos(angle) * PATH_RADIUS) + FLYWHEEL.pos.x;
    ball.pos.y = (sin(angle) * PATH_RADIUS) + FLYWHEEL.pos.y;
}

Body getBall()
{
    return ball;
}

float getBallAngularVelocity()
{
    return ball.angularVelocity;
}

float getProjectileAngularVelocity()
{
    return projectileAngularVelocity;
}

float getProjectileLinearVelocity()
{
    return projectileAngularVelocity * PATH_RADIUS;
}