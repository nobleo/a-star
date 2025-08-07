#include <iostream>
#include "source/AStar.hpp"

int main()
{
    AStar::Generator generator;
    generator.setWorldSize({25, 25});
    generator.setHeuristic(AStar::Heuristic::euclidean);
    generator.setDiagonalMovement(true);

    std::cout << "Generate path ... \n";
    auto path = generator.findPath({0, 0}, {20, 20});

    for(auto& coordinate : path) {
        std::cout << coordinate.x << " " << coordinate.y << "\n";
    }

    // Demonstrate pathfinding for a custom shape: {true, false, true}
    std::cout << "\nGenerate path for shape {true, false, true} ...\n";
    AStar::ObjectShape customShape = {{true, false, true}};
    auto customPath = generator.findPath({0, 0}, {20, 20}, customShape);
    for(auto& coordinate : customPath) {
        std::cout << coordinate.x << " " << coordinate.y << "\n";
    }
}