#pragma once
#include "../physics/physics.h"

void initalizeBall();
void updateBall(float currentTime, float timeStep);
void drawBall();
void moveBallToAngle(float angle);

Body getBall();
float getBallAngularVelocity();
float getProjectileAngularVelocity();
float getProjectileLinearVelocity();