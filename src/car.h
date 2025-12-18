#include "road.h"
#include <raylib.h>
#include <string>

#pragma once

class Car
{
public:
    Car(float startingSpeed, float desiredSpeed, float startingAngle, Color color, const Road& road);
    void UpdatePosition(const Car& leader);
    void Draw() const;
    float CalculateGap(const Car& leader) const;
    float CalculateIDM(const Car& leader) const;
    float angle;
    float speed;
    float desiredSpeed;

private:
    Color carColor;
    float carRadius;
    float x;
    float y;
    float rotation;
    float roadRadius;
};