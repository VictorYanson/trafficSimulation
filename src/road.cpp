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

    DrawRing(center, inner, outer, 0, 360, 0, GRAY);
}