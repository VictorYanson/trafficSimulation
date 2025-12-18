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

    constexpr double displayScale = 1.4;

    constexpr int screenWidth = static_cast<int>(baseDisplayWidth * displayScale);
    constexpr int screenHeight = static_cast<int>(baseDisplayWidth * displayScale * displayRatio);
    
    Road road;

    std::vector<Car> Cars;
    Cars.push_back(Car(0.025f, 0.0f, GREEN));
    Cars.push_back(Car(0.02f, 3.14f, RED));
    // Cars.push_back(Car(0.02f, 1.57f, BROWN));

    InitWindow(screenWidth, screenHeight, "Traffic Simulation");
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        for (size_t i = 0; i < Cars.size(); i++) {
            Cars[i].Update(road);

            // const Car& leader = Cars[(i + 1) % Cars.size()];
            // const int arcLength = Cars[i].CalculateGap(leader, road);

            // std::cout << "Gap to leader: " << arcLength << std::endl;
        }

        if (!Cars.empty()) {
            size_t i = 0;
            const Car& currentCar = Cars[i];
            const Car& leader = Cars[(i + 1) % Cars.size()];
            
            float arcLength = currentCar.CalculateGap(leader, road);
            
            std::cout << "Gap to leader: " << arcLength << std::endl;
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