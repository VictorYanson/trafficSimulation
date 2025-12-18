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
    float CalculateGap(const Car& leader, const Road& road) const;
    float angle;

private:
    float speed;
    Color carColor;
    float carRadius;
    float x;
    float y;
    float rotation;
};