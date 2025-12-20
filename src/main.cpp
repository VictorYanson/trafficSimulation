#include <raylib.h>
#include <vector>
#include <iostream>
#include "road.h"
#include "car.h"

int main() 
{
    const Color darkGreen = {20, 160, 133, 255};
    
    constexpr double displayRatio = 0.75;
    constexpr int baseDisplayWidth = 800;

    constexpr double displayScale = 1.25;

    constexpr int screenWidth = static_cast<int>(baseDisplayWidth * displayScale);
    constexpr int screenHeight = static_cast<int>(baseDisplayWidth * displayScale * displayRatio);
    
    Road road;
    std::vector<float> lanes = road.GetLaneRadii(2.0f);

    std::vector<Car> Cars;
    Cars.push_back(Car(0.025f, 0.04f, 0.0f, GREEN, road, lanes));
    Cars.push_back(Car(0.02f, 0.03f, 1.57f, RED, road, lanes));
    Cars.push_back(Car(0.02f, 0.04f, 3.14f, BLUE, road, lanes));
    Cars.push_back(Car(0.02f, 0.04f, 4.28f, YELLOW, road, lanes));

    InitWindow(screenWidth, screenHeight, "Traffic Simulation");
    SetTargetFPS(60);
    
    // main loop
    while (!WindowShouldClose())
    {
        for (size_t i = 0; i < Cars.size(); i++) 
        {
            const Car& leader = Cars[(i + 1) % Cars.size()];
            Cars[i].UpdatePosition(leader);
        }
        
        BeginDrawing();
            ClearBackground(darkGreen);
            road.Draw();
            
            for (const Car& car : Cars) 
            {
                car.Draw();
            }
        EndDrawing();
    }
    
    CloseWindow();
}