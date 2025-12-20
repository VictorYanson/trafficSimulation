#include "road.h"
#include <raylib.h>
#include <string>
#include <vector>

#pragma once

class Car
{
public:
    Car(float startingSpeed, float desiredSpeed, float startingAngle, Color color, const Road& road, std::vector<float> laneRadii);
    void UpdatePosition(const Car& leader);
    bool ChangeLane(std::vector<float> laneRadii);
    void Draw() const;
    float angle;
    float speed;
    float desiredSpeed;

private:
    float CalculateGap(const Car& leader) const;
    float CalculateIDM(const Car& leader) const;
    Color carColor;
    float carRadius;
    float x;
    float y;
    float rotation;
    float roadRadius;
    std::vector<float> laneRadii;
};