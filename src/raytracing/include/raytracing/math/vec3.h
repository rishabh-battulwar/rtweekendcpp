#pragma once

#include <array>
#include <cmath>
#include <ostream>

namespace raytracing {


class vec3
{
private:
  constexpr static double k256 = 255.999;

public:
  std::array<double, 3> e{};

  constexpr vec3() = default;
  constexpr vec3(double e0, double e1, double e2) : e{ e0, e1, e2 } {};

  constexpr double x() const { return e[0]; }
  constexpr double y() const { return e[1]; }
  constexpr double z() const { return e[2]; }

  constexpr vec3 operator-() { return { -e[0], -e[1], -e[2] }; }
  constexpr double operator[](size_t idx) const { return e.at(idx); }
  constexpr double &operator[](size_t idx) { return e.at(idx); }

  constexpr vec3 &operator+=(const vec3 &v)
  {
    e[0] += v.e[0];
    e[1] += v.e[1];
    e[2] += v.e[2];
    return *this;
  }

  constexpr vec3 &operator*=(const double t)
  {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
  }

  constexpr vec3 &operator/=(const double t) { return *this *= 1 / t; }

  // TO-DO: std::sqrt is holding me from making this constexpr. There are plenty
  // of constexpr sqrt implementations out on the web. Include one here.
  double length() const { return std::sqrt(length_squared()); }

  constexpr double length_squared() const
  {
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
  }

  std::array<uint8_t, 3> to_uchar() const
  {
    return { static_cast<uint8_t>(k256 * e[0]),
      static_cast<uint8_t>(k256 * e[1]),
      static_cast<uint8_t>(k256 * e[2]) };
  }
};

// Type aliases for vec3
using point3 = vec3;// 3D point
using color = vec3;// RGB color

// 3.2 vec3 Utility Functions

inline std::ostream &operator<<(std::ostream &out, const vec3 &v)
{
  return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

constexpr inline vec3 operator+(const vec3 &u, const vec3 &v)
{
  return { u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2] };
}

constexpr inline vec3 operator-(const vec3 &u, const vec3 &v)
{
  return { u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2] };
}

constexpr inline vec3 operator*(const vec3 &u, const vec3 &v)
{
  return { u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2] };
}

constexpr inline vec3 operator*(double t, const vec3 &v)
{
  return { t * v.e[0], t * v.e[1], t * v.e[2] };
}

constexpr inline vec3 operator*(const vec3 &v, double t) { return t * v; }

constexpr inline vec3 operator/(vec3 v, double t) { return (1 / t) * v; }

constexpr inline double dot(const vec3 &u, const vec3 &v)
{
  return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

constexpr inline vec3 cross(const vec3 &u, const vec3 &v)
{
  return { u.e[1] * v.e[2] - u.e[2] * v.e[1],
    u.e[2] * v.e[0] - u.e[0] * v.e[2],
    u.e[0] * v.e[1] - u.e[1] * v.e[0] };
}

constexpr inline vec3 unit_vector(vec3 v) { return v / v.length(); }

}// namespace raytracing