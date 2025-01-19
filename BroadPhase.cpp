#include "BroadPhase.h"
#include <algorithm>  // Include for std::sort and std::unique

std::vector<std::pair<int, int>> broadPhase(const std::vector<AABB>& aabbs) {
    std::vector<std::pair<int, int>> collisionPairs;

    // Run SAP on each axis
    for (int axis = 0; axis < 3; ++axis) {
        auto pairs = sweepAndPrune(aabbs, axis);

        // Add pairs to final result
        collisionPairs.insert(collisionPairs.end(), pairs.begin(), pairs.end());
    }

    // Remove duplicate pairs
    std::sort(collisionPairs.begin(), collisionPairs.end());
    collisionPairs.erase(std::unique(collisionPairs.begin(), collisionPairs.end()), collisionPairs.end());

    return collisionPairs;
}
