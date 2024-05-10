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

// Forward declaration for class PhQ::ScalarForce.
template <typename Number>
class Direction;

// Forward declaration for class PhQ::ScalarForce.
template <typename Number>
class Force;

// Forward declaration for class PhQ::ScalarForce.
template <typename Number>
class StaticPressure;

// Scalar force component or magnitude of a force vector. See also PhQ::Force.
template <typename Number = double>
class ScalarForce : public DimensionalScalar<Unit::Force, Number> {
public:
  // Default constructor. Constructs a scalar force with an uninitialized value.
  ScalarForce() = default;

  // Constructor. Constructs a scalar force with a given value expressed in a given force unit.
  ScalarForce(const Number value, const Unit::Force unit)
    : DimensionalScalar<Unit::Force, Number>(value, unit) {}

  // Constructor. Constructs a scalar force from a given static pressure and area using the
  // definition of pressure.
  constexpr ScalarForce(const StaticPressure<Number>& static_pressure, const Area<Number>& area);

  // Destructor. Destroys this scalar force.
  ~ScalarForce() noexcept = default;

  // Copy constructor. Constructs a scalar force by copying another one.
  constexpr ScalarForce(const ScalarForce<Number>& other) = default;

  // Copy constructor. Constructs a scalar force by copying another one.
  template <typename OtherNumber>
  explicit constexpr ScalarForce(const ScalarForce<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a scalar force by moving another one.
  constexpr ScalarForce(ScalarForce<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar force by copying another one.
  constexpr ScalarForce<Number>& operator=(const ScalarForce<Number>& other) = default;

  // Copy assignment operator. Assigns this scalar force by copying another one.
  template <typename OtherNumber>
  constexpr ScalarForce<Number>& operator=(const ScalarForce<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this scalar force by moving another one.
  constexpr ScalarForce<Number>& operator=(ScalarForce<Number>&& other) noexcept = default;

  // Statically creates a scalar force of zero.
  static constexpr ScalarForce<Number> Zero() {
    return ScalarForce<Number>{static_cast<Number>(0)};
  }

  // Statically creates a scalar force with a given value expressed in a given force unit.
  template <Unit::Force Unit>
  static constexpr ScalarForce<Number> Create(const Number value) {
    return ScalarForce<Number>{StaticConvertCopy<Unit::Force, Unit, Standard<Unit::Force>>(value)};
  }

  constexpr ScalarForce<Number> operator+(const ScalarForce<Number>& scalar_force) const {
    return ScalarForce<Number>{value + scalar_force.value};
  }

  constexpr ScalarForce<Number> operator-(const ScalarForce<Number>& scalar_force) const {
    return ScalarForce<Number>{value - scalar_force.value};
  }

  constexpr ScalarForce<Number> operator*(const Number number) const {
    return ScalarForce<Number>{value * number};
  }

  constexpr Force<Number> operator*(const Direction<Number>& direction) const;

  constexpr ScalarForce<Number> operator/(const Number number) const {
    return ScalarForce<Number>{value / number};
  }

  constexpr StaticPressure<Number> operator/(const Area<Number>& area) const;

  constexpr Number operator/(const ScalarForce<Number>& scalar_force) const noexcept {
    return value / scalar_force.value;
  }

  constexpr void operator+=(const ScalarForce<Number>& scalar_force) noexcept {
    value += scalar_force.value;
  }

  constexpr void operator-=(const ScalarForce<Number>& scalar_force) noexcept {
    value -= scalar_force.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a scalar force with a given value expressed in the standard force
  // unit.
  explicit constexpr ScalarForce(const Number value)
    : DimensionalScalar<Unit::Force, Number>(value) {}

  friend class Force;
};

template <typename Number>
inline constexpr bool operator==(
    const ScalarForce<Number>& left, const ScalarForce<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const ScalarForce<Number>& left, const ScalarForce<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const ScalarForce<Number>& left, const ScalarForce<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const ScalarForce<Number>& left, const ScalarForce<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const ScalarForce<Number>& left, const ScalarForce<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const ScalarForce<Number>& left, const ScalarForce<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const ScalarForce<Number>& scalar_force) {
  stream << scalar_force.Print();
  return stream;
}

template <typename Number>
inline constexpr ScalarForce<Number> operator*(
    const Number number, const ScalarForce<Number>& scalar_force) {
  return scalar_force * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ScalarForce<Number>> {
  inline size_t operator()(const PhQ::ScalarForce<Number>& scalar_force) const {
    return hash<Number>()(scalar_force.Value());
  }
};

}  // namespace std

#endif  // PHQ_FORCE_SCALAR_HPP
