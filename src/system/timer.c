#include "Timer.h"
#include <stdint.h>
#include <time.h>
#include <math.h>

int64_t lastTime;
struct timespec timeBuffer;
float deltaTime;

int64_t internalGetCurrentTime()
{
    clock_gettime(CLOCK_MONOTONIC, &timeBuffer);
    return timeBuffer.tv_nsec + (int64_t)(timeBuffer.tv_sec * (int64_t)pow(10L, 9));
}

void initializeTimer()
{
    deltaTime = 0.0f;
    lastTime = internalGetCurrentTime();
}

void updateTimer()
{
    deltaTime = (internalGetCurrentTime() - lastTime) / (long double)pow(10, 9);
    lastTime = internalGetCurrentTime();
}

float getDeltaTime()
{
    return deltaTime;
}