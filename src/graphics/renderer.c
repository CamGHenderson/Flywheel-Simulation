#include "renderer.h"
#include "graphics.h"
#include "../definitions/color.h"

void drawBody(Body body, uint8_t r, uint8_t g, uint8_t b)
{
    switch(body.type)
    {
        case CIRCLE:
            setGraphicsColor(r, g, b);
            setGraphicsPosition(VEC_XY(body));
            fillCircle(DIAMETER(body));
            break;
    }
}

void drawCircleOrientationLine(Body body)
{
    setGraphicsColor(PURPLE);
    setGraphicsPosition(VEC_XY(body));
    drawLine(RADIUS(body) * cos(body.angle), RADIUS(body) * sin(body.angle));
}