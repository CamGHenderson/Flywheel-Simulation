#pragma once
#include "../physics/physics.h"

typedef struct
{
    Body b;
    float time;
} KeyFrame;

KeyFrame createKeyframe();
void interpolateFrame(Body* dstBody, KeyFrame f1, KeyFrame f2, float time);