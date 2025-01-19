#include "AABB.h"

bool isOverlapping(const AABB& a, const AABB& b, int axis) {
    return a.min[axis] <= b.max[axis] && a.max[axis] >= b.min[axis];
}

bool isFullyOverlapping(const AABB& a, const AABB& b) {
    return isOverlapping(a, b, 0) && isOverlapping(a, b, 1) && isOverlapping(a, b, 2);
}
