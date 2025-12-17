#pragma once
#include "road.h"

class Car
{
public:
    Car();
    void Update(const Road& road);
    void Draw() const;

private:
    float speed;
    float carRadius;
    float angle;
    int x;
    int y;
};