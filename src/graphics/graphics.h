#pragma once
#include <stdint.h>
#include <stdbool.h>

#define CARTESIAN_Y_TO_WINDOW_Y(y) (getGraphicsWindowHeight() - y)
#define CARTESIAN_TO_WINDOW_COORDS(x, y) x, (CARTESIAN_Y_TO_WINDOW_Y(y))

void initializeGraphics();
void freeGraphics();

void prepareGraphics();
void updateGraphics();

void setGraphicsColor(uint8_t r, uint8_t g, uint8_t b);
void setGraphicsPosition(float x, float y);
void setGraphicsViewOffset(float x, float y);

void fillRectangle(float width, float height);
void fillCircle(float diameter);
void drawRectangle(float width, float height);
void drawCircle(float diameter);
void drawLine(float x, float y);
void drawArc(float radius, float startAngle, float endAngle);
void drawString(const char* string);

uint16_t getGraphicsWindowWidth();
uint16_t getGraphicsWindowHeight();