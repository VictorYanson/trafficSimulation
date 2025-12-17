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
    Car car1(0.02f, 0.0f);
    Car car2(0.02f, 1.0f);
    
    InitWindow(screenWidth, screenHeight, "Traffic Simulation");
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        car1.Update(road);
        car2.Update(road);
        
        BeginDrawing();
            ClearBackground(darkGreen);
            road.Draw();
            car1.Draw();
            car2.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}