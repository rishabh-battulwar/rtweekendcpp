#pragma once

#include "raytracing/rtweekend.h"

namespace raytracing {
class camera
{
private:
  constexpr static auto aspect_ratio = 16.0 / 9.0;
  constexpr static auto viewport_height = 2.0;
  constexpr static auto viewport_width = aspect_ratio * viewport_height;
  constexpr static auto focal_length = 1.0;

  point3 origin;
  vec3 horizontal;
  vec3 vertical;
  point3 lower_left_corner;

public:
  camera()
    : origin(0, 0, 0), horizontal(viewport_width, 0.0, 0.0),
      vertical(0.0, viewport_height, 0.0)
  {
    lower_left_corner =
      origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);
  }

  ray get_ray(double u, double v) const
  {
    return ray(
      origin, lower_left_corner + u * horizontal + v * vertical - origin);
  }
};
}// namespace raytracing