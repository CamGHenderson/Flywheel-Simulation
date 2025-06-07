#include "physics.h"
#include <stdint.h>

#define BODY_POS (*body).pos

Vec2f createVec2f()
{
    Vec2f v;
    v.x = 0.0f;
    v.y = 0.0f;
    return v;
}

Body createBody()
{
    Body b;
    b.type = NONE;
    b.pos = createVec2f();
    b.angle = 0.0f;
    return b;
}

Body createCircularBody(float diameter)
{
    Body b = createBody();
    b.type = CIRCLE;
    b.d1 = diameter;
    return b;
}

void updateBody(Body* body, float deltaTime)
{
    BODY_POS.x += (*body).velocity.x * deltaTime;
    BODY_POS.y += (*body).velocity.y * deltaTime;
    (*body).angle += (*body).angularVelocity * deltaTime;        
}

void setMagnitude(Vec2f* v, float m)
{
    float angle = atan2f((*v).y, (*v).x);
    (*v).x = cosf(angle) * m;
    (*v).y = sinf(angle) * m;
}