// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_VECTOR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_VECTOR_HPP

#include <array>
#include <utility>

#include "../Base.hpp"

namespace PhQ {

// Forward declarations for class Vector.
class Angle;
class Direction;

namespace Value {

// Forward declaration for class Vector.
class Dyad;

// Three-dimensional vector value in Cartesian coordinates. Contains three
// components: x, y, and z.
class Vector {
public:
  constexpr Vector() noexcept : x_y_z_() {}

  constexpr Vector(const double x, const double y, const double z) noexcept
    : x_y_z_({x, y, z}) {}

  explicit constexpr Vector(const std::array<double, 3>& x_y_z) noexcept
    : x_y_z_(x_y_z) {}

  explicit constexpr Vector(std::array<double, 3>&& x_y_z) noexcept
    : x_y_z_(std::move(x_y_z)) {}

  constexpr Vector(const double magnitude, const Direction& direction) noexcept;

  static constexpr Vector Zero() noexcept {
    return Vector{
        std::array<double, 3>{0.0, 0.0, 0.0}
    };
  }

  constexpr const std::array<double, 3>& x_y_z() const noexcept {
    return x_y_z_;
  }

  constexpr std::array<double, 3>& mutable_x_y_z() noexcept { return x_y_z_; }

  constexpr void set_x_y_z(const std::array<double, 3>& x_y_z) noexcept {
    x_y_z_ = x_y_z;
  }

  constexpr double x() const noexcept { return x_y_z_[0]; }

  constexpr double& mutable_x() noexcept { return x_y_z_[0]; }

  constexpr void set_x(const double x) noexcept { x_y_z_[0] = x; }

  constexpr double y() const noexcept { return x_y_z_[1]; }

  constexpr double& mutable_y() noexcept { return x_y_z_[1]; }

  constexpr void set_y(const double y) noexcept { x_y_z_[1] = y; }

  constexpr double z() const noexcept { return x_y_z_[2]; }

  constexpr double& mutable_z() noexcept { return x_y_z_[2]; }

  constexpr void set_z(const double z) noexcept { x_y_z_[2] = z; }

  constexpr double MagnitudeSquared() const noexcept {
    return x_y_z_[0] * x_y_z_[0] + x_y_z_[1] * x_y_z_[1]
           + x_y_z_[2] * x_y_z_[2];
  }

  double Magnitude() const noexcept { return std::sqrt(MagnitudeSquared()); }

  PhQ::Direction Direction() const noexcept;

  constexpr double Dot(const Vector& vector) const noexcept {
    return x_y_z_[0] * vector.x_y_z_[0] + x_y_z_[1] * vector.x_y_z_[1]
           + x_y_z_[2] * vector.x_y_z_[2];
  }

  constexpr double Dot(const PhQ::Direction& direction) const noexcept;

  constexpr Vector Cross(const Vector& vector) const noexcept {
    return {x_y_z_[1] * vector.x_y_z_[2] - x_y_z_[2] * vector.x_y_z_[1],
            x_y_z_[2] * vector.x_y_z_[0] - x_y_z_[0] * vector.x_y_z_[2],
            x_y_z_[0] * vector.x_y_z_[1] - x_y_z_[1] * vector.x_y_z_[0]};
  }

  constexpr Vector Cross(const PhQ::Direction& direction) const noexcept;

  constexpr Dyad Dyadic(const Vector& vector) const noexcept;

  constexpr Dyad Dyadic(const PhQ::Direction& direction) const noexcept;

  PhQ::Angle Angle(const Vector& vector) const noexcept;

  PhQ::Angle Angle(const PhQ::Direction& direction) const noexcept;

  std::string Print() const noexcept {
    return "(" + PhQ::Print(x_y_z_[0]) + ", " + PhQ::Print(x_y_z_[1]) + ", "
           + PhQ::Print(x_y_z_[2]) + ")";
  }

  std::string Print(const Precision precision) const noexcept {
    return "(" + PhQ::Print(x_y_z_[0], precision) + ", "
           + PhQ::Print(x_y_z_[1], precision) + ", "
           + PhQ::Print(x_y_z_[2], precision) + ")";
  }

  std::string JSON() const noexcept {
    return "{\"x\":" + PhQ::Print(x_y_z_[0]) + ",\"y\":" + PhQ::Print(x_y_z_[1])
           + ",\"z\":" + PhQ::Print(x_y_z_[2]) + "}";
  }

  std::string XML() const noexcept {
    return "<x>" + PhQ::Print(x_y_z_[0]) + "</x><y>" + PhQ::Print(x_y_z_[1])
           + "</y><z>" + PhQ::Print(x_y_z_[2]) + "</z>";
  }

  std::string YAML() const noexcept {
    return "{x:" + PhQ::Print(x_y_z_[0]) + ",y:" + PhQ::Print(x_y_z_[1])
           + ",z:" + PhQ::Print(x_y_z_[2]) + "}";
  }

  constexpr void operator+=(const Vector& vector) noexcept {
    x_y_z_[0] += vector.x_y_z_[0];
    x_y_z_[1] += vector.x_y_z_[1];
    x_y_z_[2] += vector.x_y_z_[2];
  }

  constexpr void operator-=(const Vector& vector) noexcept {
    x_y_z_[0] -= vector.x_y_z_[0];
    x_y_z_[1] -= vector.x_y_z_[1];
    x_y_z_[2] -= vector.x_y_z_[2];
  }

  constexpr void operator*=(const double real) noexcept {
    x_y_z_[0] *= real;
    x_y_z_[1] *= real;
    x_y_z_[2] *= real;
  }

  constexpr void operator/=(const double real) noexcept {
    x_y_z_[0] /= real;
    x_y_z_[1] /= real;
    x_y_z_[2] /= real;
  }

private:
  std::array<double, 3> x_y_z_;
};

inline constexpr bool operator==(
    const Vector& left, const Vector& right) noexcept {
  return left.x() == right.x() && left.y() == right.y()
         && left.z() == right.z();
}

inline constexpr bool operator!=(
    const Vector& left, const Vector& right) noexcept {
  return left.x() != right.x() || left.y() != right.y()
         || left.z() != right.z();
}

inline constexpr bool operator<(
    const Vector& left, const Vector& right) noexcept {
  if (left.x() != right.x()) {
    return left.x() < right.x();
  }
  if (left.y() != right.y()) {
    return left.y() < right.y();
  }
  return left.z() < right.z();
}

inline constexpr bool operator>(
    const Vector& left, const Vector& right) noexcept {
  if (left.x() != right.x()) {
    return left.x() > right.x();
  }
  if (left.y() != right.y()) {
    return left.y() > right.y();
  }
  return left.z() > right.z();
}

inline constexpr bool operator<=(
    const Vector& left, const Vector& right) noexcept {
  return !(left > right);
}

inline constexpr bool operator>=(
    const Vector& left, const Vector& right) noexcept {
  return !(left < right);
}

inline constexpr Vector operator+(
    const Vector& left, const Vector& right) noexcept {
  return {left.x() + right.x(), left.y() + right.y(), left.z() + right.z()};
}

inline constexpr Vector operator-(
    const Vector& left, const Vector& right) noexcept {
  return {left.x() - right.x(), left.y() - right.y(), left.z() - right.z()};
}

inline constexpr Vector operator*(
    const Vector& vector, const double real) noexcept {
  return {vector.x() * real, vector.y() * real, vector.z() * real};
}

inline constexpr Vector operator*(
    const double real, const Vector& vector) noexcept {
  return {vector * real};
}

inline constexpr Vector operator/(
    const Vector& vector, const double real) noexcept {
  return {vector.x() / real, vector.y() / real, vector.z() / real};
}

inline std::ostream& operator<<(
    std::ostream& stream, const Vector& vector) noexcept {
  stream << vector.Print();
  return stream;
}

}  // namespace Value

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::Value::Vector> {
  inline size_t operator()(const PhQ::Value::Vector& vector) const {
    size_t result = 17;
    result = 31 * result + hash<double>()(vector.x());
    result = 31 * result + hash<double>()(vector.y());
    result = 31 * result + hash<double>()(vector.z());
    return result;
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_VALUE_VECTOR_HPP
