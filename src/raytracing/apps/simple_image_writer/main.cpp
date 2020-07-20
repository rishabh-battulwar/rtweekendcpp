#include <iostream>
#include <vector>

#include "raytracing/math/color.h"
#include "raytracing/math/vec3.h"

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

auto main() -> int
{
  constexpr int image_width = 200;
  constexpr int image_height = 100;
  constexpr int image_channels = 3;

  std::vector<uint8_t> img(image_width * image_height * image_channels, 0);

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

  size_t index = 0;
  for (int j = image_height - 1; j >= 0; --j) {
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < image_width; ++i) {
      auto r = double(i) / image_width;
      auto g = double(j) / image_height;
      auto b = 0.25;

      raytracing::vec3 v(r, g, b);
      raytracing::write_color(std::cout, v);

      auto uchar_color = v.to_uchar();
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