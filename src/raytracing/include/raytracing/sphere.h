#pragma once

#include "raytracing/hittable.h"
#include "raytracing/math/vec3.h"

namespace raytracing {

class sphere : public hittable
{
public:
  sphere() = default;
  sphere(const point3 cen, const double r) : center(cen), radius(r){};

  virtual bool hit(const ray &r,
    const double tmin,
    const double tmax,
    hit_record &rec) const override;

public:
  point3 center;
  double radius;
};

bool sphere::hit(const ray& r, const double t_min, const double t_max, hit_record& rec) const
{
  const vec3 oc = r.origin() - center;
  const auto a = r.direction().length_squared();
  const auto half_b = dot(oc, r.direction());
  const auto c = oc.length_squared() - radius * radius;
  const auto discriminant = half_b * half_b - a * c;

  if (discriminant > 0) {
    const auto root = std::sqrt(discriminant);

    // TODO consolidate cases (duplication)
    // case 1
    auto temp = (-half_b - root) / a;
    if (temp < t_max && temp > t_min) {
      rec.t = temp;
      rec.p = r.at(rec.t);
      const vec3 outward_normal = (rec.p - center) / radius;
      rec.set_face_normal(r, outward_normal);
      return true;
    }

    // case 2
    temp = (-half_b + root) / a;
    if (temp < t_max && temp > t_min) {
      rec.t = temp;
      rec.p = r.at(rec.t);
      const vec3 outward_normal = (rec.p - center) / radius;
      rec.set_face_normal(r, outward_normal);
      return true;
    }
  }

  return false;
}

}// namespace raytracing
