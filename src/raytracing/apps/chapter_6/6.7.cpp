#include "raytracing/rtweekend.h"
#include "raytracing/color.h"
#include "raytracing/hittable_list.h"
#include "raytracing/sphere.h"

#include <iostream>
#include <memory>

using namespace raytracing;

namespace {

color ray_color(const ray &r, const hittable &world)
{
  hit_record rec;
  if (world.hit(r, 0, infinity, rec)) {
    return 0.5 * (rec.normal + color(1, 1, 1));
  }

  const vec3 unit_direction = unit_vector(r.direction());
  const auto t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

}// namespace

int main()
{

  // Image

  constexpr auto aspect_ratio = 16.0 / 9.0;
  constexpr int image_width = 384;
  constexpr int image_height = static_cast<int>(image_width / aspect_ratio);

  // World

  hittable_list world;
  world.add(std::make_shared<sphere>(point3(0, 0, -1), 0.5));
  world.add(std::make_shared<sphere>(point3(0, -100.5, -1), 100));

  // Camera

  constexpr auto viewport_height = 2.0;
  constexpr auto viewport_width = aspect_ratio * viewport_height;
  constexpr auto focal_length = 1.0;

  constexpr auto origin = point3(0, 0, 0);
  // length vectors of the viewport
  constexpr auto horizontal = vec3(viewport_width, 0, 0);
  constexpr auto vertical = vec3(0, viewport_height, 0);

  // (origin - x_hat - y_hat - z_hat)
  constexpr auto lower_left_corner =
    origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);


  // Render

  std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

  for (int j = image_height - 1; j >= 0; --j) {
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < image_width; ++i) {
      const auto u = double(i) / (image_width - 1);
      const auto v = double(j) / (image_height - 1);
      const ray r(
        origin, lower_left_corner + u * horizontal + v * vertical - origin);
      const color pixel_color = ray_color(r, world);
      write_color(std::cout, pixel_color);
    }
  }

  std::cerr << "\nDone.\n";
}