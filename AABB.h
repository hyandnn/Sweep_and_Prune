#ifndef AABB_H
#define AABB_H

#include <vector>

struct AABB {
    float min[3]; // Minimum coordinates (x, y, z)
    float max[3]; // Maximum coordinates (x, y, z)
    int id;       // Unique identifier
};

// Check if two AABBs overlap on the specified axis
bool isOverlapping(const AABB& a, const AABB& b, int axis);

// Check if two AABBs overlap on all axes
bool isFullyOverlapping(const AABB& a, const AABB& b);

#endif // AABB_H
