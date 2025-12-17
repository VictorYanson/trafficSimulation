#include <raylib.h>
#include "ball.h"
#include "road.h"

int main() 
{
    const Color darkGreen = {20, 68, 125, 25};
    
    constexpr double displayRatio = 0.75;
    constexpr int baseDisplayWidth = 800;

    constexpr double displayScale = 1.4;

    constexpr int screenWidth = static_cast<int>(baseDisplayWidth * displayScale);
    constexpr int screenHeight = static_cast<int>(baseDisplayWidth * displayScale * displayRatio);
    
    Ball ball;
    Road road;
    
    InitWindow(screenWidth, screenHeight, "Traffic Simulation");
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        ball.Update();
        
        BeginDrawing();
            ClearBackground(darkGreen);
            road.Draw();
            ball.Draw();
        EndDrawing();
    }
    
    CloseWindow();
}