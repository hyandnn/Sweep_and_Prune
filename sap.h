#ifndef SAP_H
#define SAP_H

#include <vector>
#include "AABB.h"

// Run the Sweep and Prune algorithm on the specified axis
std::vector<std::pair<int, int>> sweepAndPrune(const std::vector<AABB>& aabbs, int axis);

#endif // SAP_H
