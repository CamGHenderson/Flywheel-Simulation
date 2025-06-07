#include "keyframe.h"

KeyFrame createKeyframe()
{
    KeyFrame frame;
    frame.b = createBody();
    frame.time = 0.0f;
    return frame;
}

void interpolateFrame(Body* dstBody, KeyFrame f1, KeyFrame f2, float time)
{
    //(*dstBody).angle = ();
}