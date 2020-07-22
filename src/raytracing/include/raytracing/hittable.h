#pragma once

#include "raytracing/math/ray.h"

namespace raytracing {

struct hit_record
{
  point3 p;
  vec3 normal;
  double t;
  bool front_face;

  inline void set_face_normal(const ray& r, const vec3& outward_normal) {
      front_face = dot(r.direction(), outward_normal) < 0;
      normal = front_face ? outward_normal : -1.0 * outward_normal;
  }
};

class hittable
{
public:
    virtual ~hittable() {};

  // TODO Use optional for hit_record return value
  virtual bool hit(const ray &r,
    const double t_min,
    const double t_max,
    hit_record &rec) const = 0;
};


}// namespace raytracing