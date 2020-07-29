#pragma once

#include <cmath>
#include <cstdlib>
#include <limits>
#include <memory>
#include <random>

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

// Random number generator
inline double random_double() {
    static std::uniform_real_distribution<double> distribution(0.0, 1.0);
    static std::mt19937 generator;
    return distribution(generator);
}

constexpr inline double clamp(const double x, const double min, const double max) {
    if (x < min) return min;
    if (x > max) return max;
    return x;
}
    
} // namespace raytracing
