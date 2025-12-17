#include "car.h"
#include <cmath>
#include <raylib.h>

Car::Car() 
    : speed(0.05f)
    , carRadius(25.0f)
    , angle(0.0f)
    , x(0)
    , y(0)
{
}

void Car::Update(const Road& road) 
{
    angle += speed;
    int roadRadius = (float)road.radius;

    float centerX = (float)GetScreenWidth() / 2.0f;
    float centerY = (float)GetScreenHeight() / 2.0f;

    x = centerX + roadRadius * std::cos(angle);
    y = centerY + roadRadius * std::sin(angle);
}

void Car::Draw() const
{
    DrawCircle(x, y, carRadius, RED);
}