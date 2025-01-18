#ifndef SAP_H
#define SAP_H

#include <vector>

// Structure defining an Axis-Aligned Bounding Box (AABB)
struct AABB {
    float min[3]; // Minimum coordinates (x, y, z)
    float max[3]; // Maximum coordinates (x, y, z)
    int id;       // Unique identifier for the AABB
};

// Structure defining a point for SAP sorting
struct SAPPoint {
    float value;  // Coordinate value (projected onto an axis)
    int id;       // Identifier of the corresponding AABB
    bool isMax;   // Indicates whether this is the maximum point
};

// SAP algorithm: Takes a list of AABBs and an axis, returns potential collision pairs
std::vector<std::pair<int, int>> sweepAndPrune(const std::vector<AABB>& aabbs, int axis);

#endif // SAP_H
