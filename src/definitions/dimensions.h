#pragma once
#include "../simulation/flywheel.h"
#include "../simulation/ball.h"

#define PATH_RADIUS (RADIUS(getFlywheel()) + RADIUS(getBall()))
#define TRACK_RADIUS (RADIUS(getFlywheel()) + DIAMETER(getBall()))