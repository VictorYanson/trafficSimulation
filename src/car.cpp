#include "car.h"
#include <cmath>

Car::Car(float startingSpeed, float desiredSpeed, float startingAngle, Color color, const Road& road, std::vector<float> laneRadii) 
    : angle(startingAngle)
    , speed(startingSpeed)
    , desiredSpeed(desiredSpeed)
    , acceleration(0.0f)
    , carColor(color)
    , carRadius(25.0f)
    , x(0.0f)
    , y(0.0f)
    , rotation(0.0f)
    , roadRadius(road.radius)
    , laneRadii(laneRadii)
    , currentLane(laneRadii[0])
{
}

void Car::UpdatePosition(const Car& leader) 
{   
    acceleration = CalculateIDM(leader);

    speed += acceleration;
    if (speed < 0) speed = 0;

    angle += speed;

    float centerX = (float)GetScreenWidth() / 2.0f;
    float centerY = (float)GetScreenHeight() / 2.0f;

    // lane switch
    if (currentLane < laneRadii[1]) currentLane += 0.5f;

    x = centerX + currentLane * std::cos(angle);
    y = centerY + currentLane * std::sin(angle);
}

// FIX: roadRadius doesn't accuratly reflect current lane radius
float Car::CalculateGap(const Car& leader) const 
{
    float angleDiff = leader.angle - angle;

    float twoPi = 2.0f * PI;
    float positiveDiff = std::fmod(std::fmod(angleDiff, twoPi) + twoPi, twoPi);

    float centerToCenterArc = roadRadius * positiveDiff;
    
    float bumperToBumper = centerToCenterArc - 150.0f; 

    return (bumperToBumper < 1.0f) ? 1.0f : bumperToBumper;
}

// FIX: roadRadius doesn't accuratly reflect current lane radius
float Car::CalculateIDM(const Car& leader) const
{
    float speedState = speed * (speed - leader.speed);

    float desiredBraking = 1.0f;
    float desiredAccelerating = 1.0f;
    float desiredBehavior = 2 * sqrt(desiredBraking * desiredAccelerating);

    float timeBuffer = 2.0f;
    float minGap = 3.0f;

    float desiredGap = minGap + speed * timeBuffer + speedState / desiredBehavior;
    if (desiredGap < minGap) desiredGap = minGap;

    float currentGap = CalculateGap(leader);

    float interactionTerm = std::pow(desiredGap / currentGap, 2.0f);
    float speedTerm = std::pow(speed / desiredSpeed, 4.0f);

    float maxAcceleration = 0.01f;

    float newAcceleration = maxAcceleration * (1.0f - speedTerm - interactionTerm); 

    return newAcceleration / roadRadius;
}

bool SwitchLane(std::vector<float> laneRadii, const Car& leader, const Car& )
{

}

void Car::Draw() const
{
    float width = 30.0f;
    float height = 75.0f;

    Rectangle rec = { x, y, width, height };
    Vector2 origin = { width / 2.0f, height / 2.0f };

    float rotation = angle * RAD2DEG;

    DrawRectanglePro(rec, origin, rotation, carColor);
}