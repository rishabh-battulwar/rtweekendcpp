#include <iostream>
#include <vector>

#include "raytracing/math/ray.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

namespace {
vec3 ray_color(const ray& r) {
  vec3 unit_direction = unit_vector(r.direction);
  auto t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * vec3(1.0, 1.0, 1.0) + t * vec3(0.5, 0.7, 1.0);
}
}

auto main() -> int
{
  constexpr int image_width = 200;
  constexpr int image_height = 100;
  constexpr int image_channels = 3;

  std::vector<uint8_t> img(image_width * image_height * image_channels, 0);

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  constexpr vec3 lower_left_corner(-2.0, -1.0, -1.0);
  constexpr vec3 horizontal(4.0, 0.0, 0.0);
  constexpr vec3 vertical(0.0, 2.0, 0.0);
  constexpr vec3 origin(0.0, 0.0, 0.0);
  size_t index = 0;
  for (int j = image_height - 1; j >= 0; --j) {
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < image_width; ++i) {
      auto u = static_cast<double>(i) / image_width;
      auto v = static_cast<double>(j) / image_height;
      const ray r(origin, lower_left_corner + u * horizontal + v * vertical);
      const vec3 color = ray_color(r);
      color.write_color(std::cout);
      auto uchar_color = color.to_uchar();
      img[index++] = static_cast<uint8_t>(uchar_color[0]);
      img[index++] = static_cast<uint8_t>(uchar_color[1]);
      img[index++] = static_cast<uint8_t>(uchar_color[2]);
    }
  }

  stbi_write_png("image.png",
    image_width,
    image_height,
    image_channels,
    img.data(),
    image_width * image_channels);

  std::cerr << "\nDone.\n";
}