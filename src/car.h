#pragma once
#include "road.h"

class Car
{
public:
    Car(float startingSpeed, float startingAngle);
    void Update(const Road& road);
    void Draw() const;

private:
    float speed;
    float angle;
    float carRadius;
    int x;
    int y;
};