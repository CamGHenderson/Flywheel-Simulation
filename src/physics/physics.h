#pragma once
#include <math.h>

#define PI 3.14159265358979323846264338

#define RADS_TO_DEG(r) (r * 180.0f) / PI
#define DEG_TO_RADS(r) (r * PI) / 180.0f

#define RPM_TO_RADS_PER_SEC(rpm) (rpm * 2 * PI) / 60.0f
#define RADS_PER_SEC_TO_RPM(rpm) (rpm * 60.0f) / (2.0f * PI)

#define RADIUS(b) b.d1 / 2.0f
#define DIAMETER(b) b.d1

#define VEC_XY(b) b.pos.x, b.pos.y
#define SUB_VEC(v1, v2) (v1.x - v2.x), (v1.y - v2.y)
#define SUB_POS(b1, b2) (b1.pos.x - b2.pos.x), (b1.pos.y - b2.pos.y)

typedef struct
{
    float x;
    float y;
} Vec2f;

typedef enum
{
    NONE,
    CIRCLE,
    RECTANGLE,
    SQUARE,
} BodyType;

typedef struct
{
    BodyType type;
    Vec2f pos;
    Vec2f velocity;
    float angle;
    float angularVelocity;
    float d1;
    float d2;
} Body;

Vec2f createVec2f();
Body createBody();
Body createCircularBody(float diameter);
void updateBody(Body* body, float deltaTime);
void setMagnitude(Vec2f* v, float m);