#ifndef BROADPHASE_H
#define BROADPHASE_H

#include "AABB.h"
#include "SAP.h"

// Broad-phase collision detection
std::vector<std::pair<int, int>> broadPhase(const std::vector<AABB>& aabbs);

#endif // BROADPHASE_H
