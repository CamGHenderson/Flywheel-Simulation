#pragma once

#include <stdint.h>
#include <stdbool.h>

void initializeInput();
void updateKey(uint64_t rawKeycode, bool state);
bool isRightPressed();
bool isLeftPressed();
bool isUpPressed();
bool isDownPressed();