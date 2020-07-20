#include <iostream>

#include "raytracing/math/color.h"

auto main() -> int
{
  constexpr int image_width = 256;
  constexpr int image_height = 256;
  constexpr double kBlue = 0.25;

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  for (int j = image_height - 1; j >= 0; --j) {
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < image_height; ++i) {
      const raytracing::color pixel_color{
        double(i) / (image_width - 1), double(j) / (image_height - 1), kBlue
      };
      raytracing::write_color(std::cout, pixel_color);
    }
  }
}