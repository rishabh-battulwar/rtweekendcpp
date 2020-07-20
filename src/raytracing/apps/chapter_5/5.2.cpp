#include "raytracing/math/color.h"
#include "raytracing/math/ray.h"

#include <iostream>

using namespace raytracing;

namespace {

/**
 * @brief
 *
 * t^2 \mathbf{b} \cdot \mathbf{b}
     + 2t \mathbf{b} \cdot (\mathbf{A}-\mathbf{C})
     + (\mathbf{A}-\mathbf{C}) \cdot (\mathbf{A}-\mathbf{C}) - r^2 = 0
 *
 * @param center
 * @param radius
 * @param r
 * @return true
 * @return false
 */
constexpr bool hit_sphere(const point3 &center, const double radius, const ray &r)
{
  const vec3 oc = r.origin() - center;
  const auto a = dot(r.direction(), r.direction());
  const auto b = 2.0 * dot(oc, r.direction());
  const auto c = dot(oc, oc) - (radius * radius);
  const auto discriminant = b * b - 4 * a * c;
  return (discriminant > 0);
}

color ray_color(const ray &r)
{
  if (hit_sphere(point3(0, 0, -1), 0.5, r)) { return color(1, 0, 0); }

  const vec3 unit_direction = unit_vector(r.direction());
  const auto t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}

}// namespace

int main()
{
  constexpr auto aspect_ratio = 16.0 / 9.0;
  constexpr int image_width = 384;
  constexpr int image_height = static_cast<int>(image_width / aspect_ratio);

  std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

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

  for (int j = image_height - 1; j >= 0; --j) {
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < image_width; ++i) {
      const auto u = double(i) / (image_width - 1);
      const auto v = double(j) / (image_height - 1);
      const ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
      const color pixel_color = ray_color(r);
      write_color(std::cout, pixel_color);
    }
  }

  std::cerr << "\nDone.\n";
}