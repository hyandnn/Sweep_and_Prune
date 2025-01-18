#include "sap.h"
#include <algorithm>

// Comparison function for sorting SAPPoint based on value
bool compareSAPPoints(const SAPPoint& a, const SAPPoint& b) {
    return a.value < b.value; // Sort in ascending order
}

// Implementation of the Sweep and Prune (SAP) algorithm
std::vector<std::pair<int, int>> sweepAndPrune(const std::vector<AABB>& aabbs, int axis) {
    std::vector<SAPPoint> points;
    std::vector<std::pair<int, int>> collisionPairs;

    // Step 1: Create SAP points
    for (const auto& aabb : aabbs) {
        points.push_back({ aabb.min[axis], aabb.id, false }); // Minimum point
        points.push_back({ aabb.max[axis], aabb.id, true });  // Maximum point
    }

    // Step 2: Sort points along the specified axis
    std::sort(points.begin(), points.end(), compareSAPPoints);

    // Step 3: Initialize the active list
    std::vector<int> activeList;

    // Step 4: Process the sorted points
    for (const auto& point : points) {
        if (!point.isMax) {
            // For minimum points: Check for overlap with active AABBs
            for (int activeID : activeList) {
                const AABB& aabb1 = aabbs[activeID];
                const AABB& aabb2 = aabbs[point.id];

                // Check overlap on the other two axes
                if (aabb1.min[(axis + 1) % 3] <= aabb2.max[(axis + 1) % 3] &&
                    aabb1.max[(axis + 1) % 3] >= aabb2.min[(axis + 1) % 3] &&
                    aabb1.min[(axis + 2) % 3] <= aabb2.max[(axis + 2) % 3] &&
                    aabb1.max[(axis + 2) % 3] >= aabb2.min[(axis + 2) % 3]) {
                    collisionPairs.emplace_back(activeID, point.id);
                }
            }
            // Add the current point to the active list
            activeList.push_back(point.id);
        }
        else {
            // For maximum points: Remove the corresponding minimum point from the active list
            activeList.erase(std::remove(activeList.begin(), activeList.end(), point.id), activeList.end());
        }
    }

    return collisionPairs;
}
