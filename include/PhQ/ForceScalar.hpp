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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_FORCE_SCALAR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_FORCE_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "Area.hpp"
#include "DimensionalScalar.hpp"
#include "Unit/Force.hpp"

namespace PhQ {

// Forward declarations for class ForceScalar.
class Direction;
class Force;
class StaticPressure;

// Scalar force component or magnitude of a force vector.
class ForceScalar : public DimensionalScalar<Unit::Force> {
public:
  // Default constructor. Constructs a scalar force with an uninitialized value.
  ForceScalar() = default;

  // Constructor. Constructs a scalar force with a given value expressed in a given force unit.
  ForceScalar(const double value, const Unit::Force unit)
    : DimensionalScalar<Unit::Force>(value, unit) {}

  // Constructor. Constructs a scalar force from a given static pressure and area using the
  // definition of pressure.
  constexpr ForceScalar(const StaticPressure& static_pressure, const Area& area);

  // Destructor. Destroys this scalar force.
  ~ForceScalar() noexcept = default;

  // Copy constructor. Constructs a scalar force by copying another one.
  constexpr ForceScalar(const ForceScalar& other) = default;

  // Move constructor. Constructs a scalar force by moving another one.
  constexpr ForceScalar(ForceScalar&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar force by copying another one.
  constexpr ForceScalar& operator=(const ForceScalar& other) = default;

  // Move assignment operator. Assigns this scalar force by moving another one.
  constexpr ForceScalar& operator=(ForceScalar&& other) noexcept = default;

  // Statically creates a scalar force of zero.
  static constexpr ForceScalar Zero() {
    return ForceScalar{0.0};
  }

  // Statically creates a scalar force with a given value expressed in a given force unit.
  template <Unit::Force Unit>
  static constexpr ForceScalar Create(const double value) {
    return ForceScalar{StaticConvertCopy<Unit::Force, Unit, Standard<Unit::Force>>(value)};
  }

  constexpr ForceScalar operator+(const ForceScalar& force_scalar) const {
    return ForceScalar{value_ + force_scalar.value_};
  }

  constexpr ForceScalar operator-(const ForceScalar& force_scalar) const {
    return ForceScalar{value_ - force_scalar.value_};
  }

  constexpr ForceScalar operator*(const double number) const {
    return ForceScalar{value_ * number};
  }

  constexpr Force operator*(const Direction& direction) const;

  constexpr ForceScalar operator/(const double number) const {
    return ForceScalar{value_ / number};
  }

  constexpr StaticPressure operator/(const Area& area) const;

  constexpr double operator/(const ForceScalar& force_scalar) const noexcept {
    return value_ / force_scalar.value_;
  }

  constexpr void operator+=(const ForceScalar& force_scalar) noexcept {
    value_ += force_scalar.value_;
  }

  constexpr void operator-=(const ForceScalar& force_scalar) noexcept {
    value_ -= force_scalar.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a scalar force with a given value expressed in the standard force
  // unit.
  explicit constexpr ForceScalar(const double value) : DimensionalScalar<Unit::Force>(value) {}

  friend class Force;
};

inline constexpr bool operator==(const ForceScalar& left, const ForceScalar& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const ForceScalar& left, const ForceScalar& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const ForceScalar& left, const ForceScalar& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const ForceScalar& left, const ForceScalar& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const ForceScalar& left, const ForceScalar& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const ForceScalar& left, const ForceScalar& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const ForceScalar& force_scalar) {
  stream << force_scalar.Print();
  return stream;
}

inline constexpr ForceScalar operator*(const double number, const ForceScalar& force_scalar) {
  return force_scalar * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ForceScalar> {
  inline size_t operator()(const PhQ::ForceScalar& force_scalar) const {
    return hash<double>()(force_scalar.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_FORCE_SCALAR_HPP
