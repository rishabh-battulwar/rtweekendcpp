#pragma once

#include "raytracing/math/vec3.h"

namespace raytracing {

class ray
{
public:
  vec3 orig;
  vec3 dir;

public:
  constexpr ray() = default;
  constexpr ray(const vec3 &origin, const vec3 &direction) : orig(origin), dir(direction)
  {}

  constexpr vec3 origin() const { return orig; }
  constexpr vec3 direction() const { return dir; }

  constexpr vec3 at(const double t) const { return orig + t * dir; }
};

}// namespace raytracing
