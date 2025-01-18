#include <iostream>
#include "sap.h"

int main() {
    // Step 1: Create test data
    std::vector<AABB> aabbs = {
        {{0.0, 0.0, 0.0}, {1.0, 1.0, 1.0}, 0}, // AABB 0
        {{0.5, 0.5, 0.5}, {1.5, 1.5, 1.5}, 1}, // AABB 1
        {{2.0, 2.0, 2.0}, {3.0, 3.0, 3.0}, 2}, // AABB 2
        {{1.2, 1.2, 1.2}, {2.2, 2.2, 2.2}, 3}, // AABB 3
    };

    // Step 2: Run the SAP algorithm (along the x-axis)
    std::vector<std::pair<int, int>> collisionPairs = sweepAndPrune(aabbs, 0);

    // Step 3: Output the results
    std::cout << "Potential Collision Pairs:" << std::endl;
    for (const auto& pair : collisionPairs) {
        std::cout << "AABB " << pair.first << " - AABB " << pair.second << std::endl;
    }

    return 0;
}
