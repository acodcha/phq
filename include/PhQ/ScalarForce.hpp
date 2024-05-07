// Copyright 2020-2024 Alexandre Coderre-Chabot
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

#ifndef PHQ_FORCE_SCALAR_HPP
#define PHQ_FORCE_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "Area.hpp"
#include "DimensionalScalar.hpp"
#include "Unit/Force.hpp"

namespace PhQ {

// Forward declarations for class ScalarForce.
class Direction;
class Force;
class StaticPressure;

// Scalar force component or magnitude of a force vector. See also PhQ::Force.
class ScalarForce : public DimensionalScalar<Unit::Force, double> {
public:
  // Default constructor. Constructs a scalar force with an uninitialized value.
  ScalarForce() = default;

  // Constructor. Constructs a scalar force with a given value expressed in a given force unit.
  ScalarForce(const double value, const Unit::Force unit)
    : DimensionalScalar<Unit::Force>(value, unit) {}

  // Constructor. Constructs a scalar force from a given static pressure and area using the
  // definition of pressure.
  constexpr ScalarForce(const StaticPressure& static_pressure, const Area& area);

  // Destructor. Destroys this scalar force.
  ~ScalarForce() noexcept = default;

  // Copy constructor. Constructs a scalar force by copying another one.
  constexpr ScalarForce(const ScalarForce& other) = default;

  // Move constructor. Constructs a scalar force by moving another one.
  constexpr ScalarForce(ScalarForce&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar force by copying another one.
  constexpr ScalarForce& operator=(const ScalarForce& other) = default;

  // Move assignment operator. Assigns this scalar force by moving another one.
  constexpr ScalarForce& operator=(ScalarForce&& other) noexcept = default;

  // Statically creates a scalar force of zero.
  static constexpr ScalarForce Zero() {
    return ScalarForce{0.0};
  }

  // Statically creates a scalar force with a given value expressed in a given force unit.
  template <Unit::Force Unit>
  static constexpr ScalarForce Create(const double value) {
    return ScalarForce{StaticConvertCopy<Unit::Force, Unit, Standard<Unit::Force>>(value)};
  }

  constexpr ScalarForce operator+(const ScalarForce& scalar_force) const {
    return ScalarForce{value + scalar_force.value};
  }

  constexpr ScalarForce operator-(const ScalarForce& scalar_force) const {
    return ScalarForce{value - scalar_force.value};
  }

  constexpr ScalarForce operator*(const double number) const {
    return ScalarForce{value * number};
  }

  constexpr Force operator*(const Direction& direction) const;

  constexpr ScalarForce operator/(const double number) const {
    return ScalarForce{value / number};
  }

  constexpr StaticPressure operator/(const Area& area) const;

  constexpr double operator/(const ScalarForce& scalar_force) const noexcept {
    return value / scalar_force.value;
  }

  constexpr void operator+=(const ScalarForce& scalar_force) noexcept {
    value += scalar_force.value;
  }

  constexpr void operator-=(const ScalarForce& scalar_force) noexcept {
    value -= scalar_force.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a scalar force with a given value expressed in the standard force
  // unit.
  explicit constexpr ScalarForce(const double value) : DimensionalScalar<Unit::Force>(value) {}

  friend class Force;
};

inline constexpr bool operator==(const ScalarForce& left, const ScalarForce& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const ScalarForce& left, const ScalarForce& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const ScalarForce& left, const ScalarForce& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const ScalarForce& left, const ScalarForce& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const ScalarForce& left, const ScalarForce& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const ScalarForce& left, const ScalarForce& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const ScalarForce& scalar_force) {
  stream << scalar_force.Print();
  return stream;
}

inline constexpr ScalarForce operator*(const double number, const ScalarForce& scalar_force) {
  return scalar_force * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ScalarForce> {
  inline size_t operator()(const PhQ::ScalarForce& scalar_force) const {
    return hash<double>()(scalar_force.Value());
  }
};

}  // namespace std

#endif  // PHQ_FORCE_SCALAR_HPP
