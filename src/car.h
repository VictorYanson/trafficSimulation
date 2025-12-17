#include "road.h"
#include <raylib.h>
#include <string>

#pragma once

class Car
{
public:
    Car(float startingSpeed, float startingAngle, Color color);
    void Update(const Road& road);
    void Draw() const;

private:
    float speed;
    float angle;
    Color carColor;
    float carRadius;
    float x;
    float y;
    float rotation;
};