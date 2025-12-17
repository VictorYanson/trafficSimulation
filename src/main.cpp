#include <raylib.h>
#include <vector>
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

    std::vector<Car> Cars;
    Cars.push_back(Car(0.02f, 0.0f, GREEN));
    Cars.push_back(Car(0.02f, 1.57f, BLUE));
    Cars.push_back(Car(0.02f, 3.14f, RED));

    InitWindow(screenWidth, screenHeight, "Traffic Simulation");
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        for (Car& car : Cars) 
        {
            car.Update(road);
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