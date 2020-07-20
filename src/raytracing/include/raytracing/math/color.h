#pragma once

#include "raytracing/math/vec3.h"

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

}// namespace raytracing