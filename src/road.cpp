#include "road.h"
#include <raylib.h>

Road::Road()
    : radius(300)
    , width(100)
{
}

void Road::Draw() const
{
    Vector2 center = { (float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2 };

    float carPath = width / 2.0f;

    float inner = radius - carPath;
    float outer = radius + carPath;

    // main road surface
    DrawRing(center, inner, outer, 0, 360, 0, GRAY);

    float lineInner = radius - 2.5f;
    float lineOuter = radius + 2.5f;

    // road lane line
    DrawRing(center, lineInner, lineOuter, 0, 360, 0, {189, 189, 189, 255});
}