#include <vector>

#pragma once

class Road
{
public:
    Road();
    void Draw() const;
    std::vector<float> GetLaneRadii(float laneAmount) const;
    float radius;

private:
    float width;
};