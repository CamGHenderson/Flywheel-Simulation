#pragma once
#include "../physics/physics.h"

void initializeFlywheel();
void updateFlywheel(float deltaTime);
void drawFlywheel();
void drawFlywheelTrack();

Body getFlywheel();
float getFlywheelAngularVelocity();