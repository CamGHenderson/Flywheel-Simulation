#pragma once
#include <stdint.h>
#include <stdbool.h>

void initializeGraphics();
bool isGraphicsWindowOpen();
void freeGraphics();

void prepareGraphics();
void updateGraphics();

void setGraphicsColor(uint8_t r, uint8_t g, uint8_t b);
void drawRectangle(float x, float y, float width, float height);
void drawLine(float x1, float y1, float x2, float y2);
void drawString(float x, float y, const char* string);