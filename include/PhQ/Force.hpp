// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_FORCE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_FORCE_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalVector.hpp"
#include "Direction.hpp"
#include "ForceScalar.hpp"
#include "Unit/Force.hpp"
#include "Vector.hpp"

namespace PhQ {

// Forward declaration for class Force.
class Traction;

// Force vector.
class Force : public DimensionalVector<Unit::Force> {
public:
  // Default constructor. Constructs a force vector with an uninitialized value.
  Force() = default;

  // Constructor. Constructs a force vector with a given value expressed in a given force unit.
  Force(const Vector& value, const Unit::Force unit)
    : DimensionalVector<Unit::Force>(value, unit) {}

  // Constructor. Constructs a force vector from a given scalar force magnitude and direction.
  constexpr Force(const ForceScalar& force_scalar, const Direction& direction)
    : Force(force_scalar.Value() * direction.Value()) {}

  // Constructor. Constructs a force vector from a given traction and area using the definition of
  // traction.
  constexpr Force(const Traction& traction, const Area& area);

  // Destructor. Destroys this force vector.
  ~Force() noexcept = default;

  // Copy constructor. Constructs a force vector by copying another one.
  constexpr Force(const Force& other) = default;

  // Move constructor. Constructs a force vector by moving another one.
  constexpr Force(Force&& other) noexcept = default;

  // Copy assignment operator. Assigns this force vector by copying another one.
  constexpr Force& operator=(const Force& other) = default;

  // Move assignment operator. Assigns this force vector by moving another one.
  constexpr Force& operator=(Force&& other) noexcept = default;

  // Statically creates a force vector of zero.
  static constexpr Force Zero() {
    return Force{Vector::Zero()};
  }

  // Statically creates a force vector from the given x, y, and z Cartesian components expressed in
  // a given force unit.
  template <Unit::Force Unit>
  static constexpr Force Create(const double x, const double y, const double z) {
    return Force{StaticConvertCopy<Unit::Force, Unit, Standard<Unit::Force>>(Vector{x, y, z})};
  }

  // Statically creates a force vector from the given x, y, and z Cartesian components expressed in
  // a given force unit.
  template <Unit::Force Unit>
  static constexpr Force Create(const std::array<double, 3>& x_y_z) {
    return Force{StaticConvertCopy<Unit::Force, Unit, Standard<Unit::Force>>(Vector{x_y_z})};
  }

  // Statically creates a force vector with a given value expressed in a given force unit.
  template <Unit::Force Unit>
  static constexpr Force Create(const Vector& value) {
    return Force{StaticConvertCopy<Unit::Force, Unit, Standard<Unit::Force>>(value)};
  }

  // Returns the magnitude of this force vector.
  [[nodiscard]] ForceScalar Magnitude() const {
    return ForceScalar{value_.Magnitude()};
  }

  // Returns the angle between this force vector and another one.
  [[nodiscard]] PhQ::Angle Angle(const Force& force) const {
    return {*this, force};
  }

  constexpr Force operator+(const Force& force) const {
    return Force{value_ + force.value_};
  }

  constexpr Force operator-(const Force& force) const {
    return Force{value_ - force.value_};
  }

  constexpr Force operator*(const double number) const {
    return Force{value_ * number};
  }

  constexpr Force operator/(const double number) const {
    return Force{value_ / number};
  }

  constexpr Traction operator/(const Area& area) const;

  constexpr void operator+=(const Force& force) noexcept {
    value_ += force.value_;
  }

  constexpr void operator-=(const Force& force) noexcept {
    value_ -= force.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a force vector with a given value expressed in the standard force unit.
  explicit constexpr Force(const Vector& value) : DimensionalVector<Unit::Force>(value) {}
};

inline constexpr bool operator==(const Force& left, const Force& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Force& left, const Force& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Force& left, const Force& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Force& left, const Force& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Force& left, const Force& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Force& left, const Force& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Force& force) {
  stream << force.Print();
  return stream;
}

inline constexpr Force operator*(const double number, const Force& force) {
  return force * number;
}

inline Direction::Direction(const Force& force) : Direction(force.Value()) {}

inline Angle::Angle(const Force& force1, const Force& force2)
  : Angle(force1.Value(), force2.Value()) {}

inline constexpr Force Direction::operator*(const ForceScalar& force_scalar) const {
  return {force_scalar, *this};
}

inline constexpr Force ForceScalar::operator*(const Direction& direction) const {
  return {*this, direction};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Force> {
  inline size_t operator()(const PhQ::Force& force) const {
    return hash<PhQ::Vector>()(force.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_FORCE_HPP
