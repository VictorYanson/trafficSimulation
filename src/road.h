#include <vector>

#pragma once

class Road
{
public:
    Road();
    void Draw() const;
    std::vector<float> GetLaneRadii(int laneAmountInt) const;
    float radius;

private:
    float width;
};