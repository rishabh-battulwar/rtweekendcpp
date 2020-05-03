#include "raytracing/math/vec3.h"

namespace raytracing {

double vec3::length_squared() const
{
  return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

}// namespace raytracing