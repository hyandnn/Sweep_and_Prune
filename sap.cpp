#include "SAP.h"
#include <algorithm>

std::vector<std::pair<int, int>> sweepAndPrune(const std::vector<AABB>& aabbs, int axis) {
    struct SAPPoint {
        float value;
        int id;
        bool isMax;
    };

    std::vector<SAPPoint> points;
    std::vector<std::pair<int, int>> collisionPairs;

    // Create SAP points
    for (const auto& aabb : aabbs) {
        points.push_back({ aabb.min[axis], aabb.id, false }); // Min point
        points.push_back({ aabb.max[axis], aabb.id, true });  // Max point
    }

    // Sort points along the specified axis
    std::sort(points.begin(), points.end(), [](const SAPPoint& a, const SAPPoint& b) {
        return a.value < b.value;
        });

    // Active list for overlapping AABBs
    std::vector<int> activeList;

    // Sweep and prune
    for (const auto& point : points) {
        if (!point.isMax) {
            for (int activeID : activeList) {
                if (isFullyOverlapping(aabbs[activeID], aabbs[point.id])) {
                    collisionPairs.emplace_back(activeID, point.id);
                }
            }
            activeList.push_back(point.id);
        }
        else {
            activeList.erase(std::remove(activeList.begin(), activeList.end(), point.id), activeList.end());
        }
    }

    return collisionPairs;
}
