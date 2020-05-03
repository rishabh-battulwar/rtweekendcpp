#pragma once

#include "raytracing/math/vec3.h"

namespace raytracing {

class ray
{
public:
  vec3 orig;
  vec3 dir;

public:
  ray() = default;
  ray(const vec3 &origin, const vec3 &direction) : orig(origin), dir(direction)
  {}

  vec3 origin() const { return orig; }
  vec3 direction() const { return dir; }

  vec3 at(double t) const { return orig + t * dir; }
}

}// namespace raytracing
