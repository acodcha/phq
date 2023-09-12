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

// Forward declaration for class PhQ::Value::Vector.
class Angle;

// Forward declaration for class PhQ::Value::Vector.
class Direction;

namespace Value {

// Forward declaration for class PhQ::Value::Vector.
class Dyad;

// Three-dimensional vector value in Cartesian coordinates. Contains three
// components: x, y, and z.
class Vector {
public:
  // Constructs a three-dimensional vector value with uninitialized x, y, and z
  // Cartesian components.
  constexpr Vector() noexcept : x_y_z_() {}

  // Constructs a three-dimensional vector value from the given x, y, and z
  // Cartesian components.
  constexpr Vector(const double x, const double y, const double z) noexcept
    : x_y_z_({x, y, z}) {}

  // Constructs a three-dimensional vector value from a given array representing
  // its x, y, and z Cartesian components.
  explicit constexpr Vector(const std::array<double, 3>& x_y_z) noexcept
    : x_y_z_(x_y_z) {}

  // Constructs a three-dimensional vector value by moving a given array
  // representing its x, y, and z Cartesian components.
  explicit constexpr Vector(std::array<double, 3>&& x_y_z) noexcept
    : x_y_z_(std::move(x_y_z)) {}

  // Constructs a three-dimensional vector value given a magnitude and a
  // direction.
  constexpr Vector(const double magnitude, const Direction& direction) noexcept;

  // Returns a three-dimensional vector value with its x, y, and z Cartesian
  // components initialized to zero.
  static constexpr Vector Zero() noexcept {
    return Vector{
        std::array<double, 3>{0.0, 0.0, 0.0}
    };
  }

  // Returns this three-dimensional vector value's x, y, and z Cartesian
  // components as an array.
  constexpr const std::array<double, 3>& x_y_z() const noexcept {
    return x_y_z_;
  }

  // Returns this three-dimensional vector value's x Cartesian component.
  constexpr double x() const noexcept { return x_y_z_[0]; }

  // Returns this three-dimensional vector value's y Cartesian component.
  constexpr double y() const noexcept { return x_y_z_[1]; }

  // Returns this three-dimensional vector value's z Cartesian component.
  constexpr double z() const noexcept { return x_y_z_[2]; }

  // Returns this three-dimensional vector value's x, y, and z Cartesian
  // components as a mutable array.
  constexpr std::array<double, 3>& Mutable_x_y_z() noexcept { return x_y_z_; }

  // Returns this three-dimensional vector value's x Cartesian component as a
  // mutable value.
  constexpr double& Mutable_x() noexcept { return x_y_z_[0]; }

  // Returns this three-dimensional vector value's y Cartesian component as a
  // mutable value.
  constexpr double& Mutable_y() noexcept { return x_y_z_[1]; }

  // Returns this three-dimensional vector value's z Cartesian component as a
  // mutable value.
  constexpr double& Mutable_z() noexcept { return x_y_z_[2]; }

  // Sets this three-dimensional vector value's x, y, and z Cartesian components
  // to the given values.
  constexpr void Set_x_y_z(const std::array<double, 3>& x_y_z) noexcept {
    x_y_z_ = x_y_z;
  }

  // Sets this three-dimensional vector value's x Cartesian component to a given
  // value.
  constexpr void Set_x(const double x) noexcept { x_y_z_[0] = x; }

  // Sets this three-dimensional vector value's y Cartesian component to a given
  // value.
  constexpr void Set_y(const double y) noexcept { x_y_z_[1] = y; }

  // Sets this three-dimensional vector value's z Cartesian component to a given
  // value.
  constexpr void Set_z(const double z) noexcept { x_y_z_[2] = z; }

  // Returns the square of the magnitude of this three-dimensional vector value.
  constexpr double MagnitudeSquared() const noexcept {
    return x_y_z_[0] * x_y_z_[0] + x_y_z_[1] * x_y_z_[1]
           + x_y_z_[2] * x_y_z_[2];
  }

  // Returns the magnitude (also known as the L2 norm) of this three-dimensional
  // vector value.
  double Magnitude() const noexcept { return std::sqrt(MagnitudeSquared()); }

  // Returns the direction of this three-dimensional vector value.
  PhQ::Direction Direction() const noexcept;

  // Returns the dot product (also known as the inner product or scalar product)
  // of this three-dimensional vector value and another given three-dimensional
  // vector value.
  constexpr double Dot(const Vector& vector) const noexcept {
    return x_y_z_[0] * vector.x_y_z_[0] + x_y_z_[1] * vector.x_y_z_[1]
           + x_y_z_[2] * vector.x_y_z_[2];
  }

  // Returns the dot product (also known as the inner product or scalar product)
  // of this three-dimensional vector value and a given direction.
  constexpr double Dot(const PhQ::Direction& direction) const noexcept;

  // Returns the cross product (also known as the vector product) of this
  // three-dimensional vector value and another given three-dimensional vector
  // value.
  constexpr Vector Cross(const Vector& vector) const noexcept {
    return {x_y_z_[1] * vector.x_y_z_[2] - x_y_z_[2] * vector.x_y_z_[1],
            x_y_z_[2] * vector.x_y_z_[0] - x_y_z_[0] * vector.x_y_z_[2],
            x_y_z_[0] * vector.x_y_z_[1] - x_y_z_[1] * vector.x_y_z_[0]};
  }

  // Returns the cross product (also known as the vector product) of this
  // three-dimensional vector value and a given direction.
  constexpr Vector Cross(const PhQ::Direction& direction) const noexcept;

  // Returns the dyadic tensor product (also known as the outer product) of this
  // three-dimensional vector value and another given three-dimensional vector
  // value.
  constexpr Dyad Dyadic(const Vector& vector) const noexcept;

  // Returns the dyadic tensor product (also known as the outer product) of this
  // three-dimensional vector value and a given direction.
  constexpr Dyad Dyadic(const PhQ::Direction& direction) const noexcept;

  // Returns the angle between this three-dimensional vector value and another
  // given three-dimensional vector value.
  PhQ::Angle Angle(const Vector& vector) const noexcept;

  // Returns the angle between this three-dimensional vector value and a given
  // direction.
  PhQ::Angle Angle(const PhQ::Direction& direction) const noexcept;

  // Prints this three-dimensional vector value as a string. Components are
  // printed to double floating point precision.
  std::string Print() const noexcept {
    return "(" + PhQ::Print(x_y_z_[0]) + ", " + PhQ::Print(x_y_z_[1]) + ", "
           + PhQ::Print(x_y_z_[2]) + ")";
  }

  // Prints this three-dimensional vector value as a string. Components are
  // printed to a given floating point precision.
  std::string Print(const Precision precision) const noexcept {
    return "(" + PhQ::Print(x_y_z_[0], precision) + ", "
           + PhQ::Print(x_y_z_[1], precision) + ", "
           + PhQ::Print(x_y_z_[2], precision) + ")";
  }

  // Serializes this three-dimensional vector value as a JSON message.
  std::string JSON() const noexcept {
    return "{\"x\":" + PhQ::Print(x_y_z_[0]) + ",\"y\":" + PhQ::Print(x_y_z_[1])
           + ",\"z\":" + PhQ::Print(x_y_z_[2]) + "}";
  }

  // Serializes this three-dimensional vector value as an XML message.
  std::string XML() const noexcept {
    return "<x>" + PhQ::Print(x_y_z_[0]) + "</x><y>" + PhQ::Print(x_y_z_[1])
           + "</y><z>" + PhQ::Print(x_y_z_[2]) + "</z>";
  }

  // Serializes this three-dimensional vector value as a YAML message.
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
