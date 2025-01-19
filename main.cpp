#include <iostream>
#include "BroadPhase.h"

int main() {
    std::vector<AABB> aabbs = {
        {{0.0f, 0.0f, 0.0f}, {1.0f, 1.0f, 1.0f}, 0},
        {{0.5f, 0.5f, 0.5f}, {1.5f, 1.5f, 1.5f}, 1},
        {{2.0f, 2.0f, 2.0f}, {3.0f, 3.0f, 3.0f}, 2},
        {{1.2f, 1.2f, 1.2f}, {2.2f, 2.2f, 2.2f}, 3},
    };

    auto collisionPairs = broadPhase(aabbs);

    std::cout << "Potential Collision Pairs:\n";
    for (const auto& pair : collisionPairs) {
        std::cout << "AABB " << pair.first << " - AABB " << pair.second << "\n";
    }

    return 0;
}
