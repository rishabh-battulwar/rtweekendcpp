#pragma once

#include "raytracing/hittable.h"

#include <memory>
#include <vector>

namespace raytracing {

class hittable_list : public hittable
{
public:
  hittable_list() = default;
  hittable_list(std::shared_ptr<hittable> object) { add(object); }

  void clear() { objects.clear(); }
  void add(std::shared_ptr<hittable> object) { objects.push_back(object); }

  virtual bool hit(const ray &r,
    const double t_min,
    const double t_max,
    hit_record &rec) const override;

public:
  std::vector<std::shared_ptr<hittable>> objects;
};

bool hittable_list::hit(const ray &r,
  const double t_min,
  const double t_max,
  hit_record &rec) const
{
  hit_record temp_rec;
  bool hit_anything = false;
  auto closest_so_far = t_max;

  for (const auto &object : objects) {
    if (object->hit(r, t_min, closest_so_far, temp_rec)) {
      hit_anything = true;
      closest_so_far = temp_rec.t;
      rec = temp_rec;
    }
  }

  return hit_anything;
}


}// namespace raytracing
