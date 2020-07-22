#pragma once

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>

// common headers
#include "raytracing/math/ray.h"
#include "raytracing/math/vec3.h"

namespace raytracing
{


// Constants

constexpr double infinity = std::numeric_limits<double>::infinity();
const double pi = 3.1415926535897932385;

// Utility Functions

inline double degrees_to_radians(const double degrees) {
    return degrees * pi / 180.0;
}
    
} // namespace raytracing
