#include "car.h"
#include <cmath>
#include <raylib.h>

Car::Car(float startingSpeed, float startingAngle, Color color) 
    : speed(startingSpeed)
    , angle(startingAngle)
    , carColor(color)
    , carRadius(25.0f)
    , x(0.0f)
    , y(0.0f)
    , rotation(0.0f)
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
    float width = 50.0f;
    float height = 100.0f;

    Rectangle rec = { x, y, width, height };
    Vector2 origin = { width / 2.0f, height / 2.0f };

    float rotation = angle * RAD2DEG;

    DrawRectanglePro(rec, origin, rotation, carColor);
}