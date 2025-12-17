#include <raylib.h>
#include "road.h"
#include "car.h"

int main() 
{
    const Color darkGreen = {20, 68, 125, 25};
    
    constexpr double displayRatio = 0.75;
    constexpr int baseDisplayWidth = 800;

    constexpr double displayScale = 1.4;

    constexpr int screenWidth = static_cast<int>(baseDisplayWidth * displayScale);
    constexpr int screenHeight = static_cast<int>(baseDisplayWidth * displayScale * displayRatio);
    
    Road road;
    Car car;
    
    InitWindow(screenWidth, screenHeight, "Traffic Simulation");
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        car.Update(road);
        
        BeginDrawing();
            ClearBackground(darkGreen);
            road.Draw();
            car.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}