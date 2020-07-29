#pragma once

#include "raytracing/rtweekend.h"

#include <iostream>

namespace raytracing {

void write_color(std::ostream &out, color pixel_color)
{
  constexpr double k256 = 255.999;
  // Write the translated [0,255] value of each color component.
  out << static_cast<int>(k256 * pixel_color.x()) << ' '
      << static_cast<int>(k256 * pixel_color.y()) << ' '
      << static_cast<int>(k256 * pixel_color.z()) << '\n';
}

void write_color(std::ostream &out, const color pixel_color, const int samples_per_pixel)
{
  constexpr double k256 = 256.0;

  const auto scale = 1.0 / samples_per_pixel;

  const auto r = pixel_color.x() * scale;
  const auto g = pixel_color.y() * scale;
  const auto b = pixel_color.z() * scale;

  // Write the translated [0,255] value of each color component.
  out << static_cast<int>(k256 * clamp(r, 0.0, 0.999)) << ' '
      << static_cast<int>(k256 * clamp(g, 0.0, 0.999)) << ' '
      << static_cast<int>(k256 * clamp(b, 0.0, 0.999)) << '\n';
}

}// namespace raytracing