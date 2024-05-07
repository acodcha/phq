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

#ifndef PHQ_TEMPERATURE_GRADIENT_SCALAR_HPP
#define PHQ_TEMPERATURE_GRADIENT_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Length.hpp"
#include "TemperatureDifference.hpp"
#include "Unit/TemperatureGradient.hpp"

namespace PhQ {

// Forward declarations for class ScalarTemperatureGradient.
class Direction;
class TemperatureGradient;

// Scalar temperature gradient component or magnitude of a temperature gradient vector. See also
// PhQ::TemperatureGradient.
class ScalarTemperatureGradient : public DimensionalScalar<Unit::TemperatureGradient, double> {
public:
  // Default constructor. Constructs a scalar temperature gradient with an uninitialized value.
  ScalarTemperatureGradient() = default;

  // Constructor. Constructs a scalar temperature gradient with a given value expressed in a given
  // temperature gradient unit.
  ScalarTemperatureGradient(const double value, const Unit::TemperatureGradient unit)
    : DimensionalScalar<Unit::TemperatureGradient>(value, unit) {}

  // Constructor. Constructs a scalar temperature gradient from a given temperature difference and
  // length using the definition of temperature gradient.
  constexpr ScalarTemperatureGradient(
      const TemperatureDifference& temperature_difference, const Length& length)
    : DimensionalScalar<Unit::TemperatureGradient>(
        temperature_difference.Value() / length.Value()) {}

  // Destructor. Destroys this scalar temperature gradient.
  ~ScalarTemperatureGradient() noexcept = default;

  // Copy constructor. Constructs a scalar temperature gradient by copying another one.
  constexpr ScalarTemperatureGradient(const ScalarTemperatureGradient& other) = default;

  // Move constructor. Constructs a scalar temperature gradient by moving another one.
  constexpr ScalarTemperatureGradient(ScalarTemperatureGradient&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar temperature gradient by copying another one.
  constexpr ScalarTemperatureGradient& operator=(const ScalarTemperatureGradient& other) = default;

  // Move assignment operator. Assigns this scalar temperature gradient by moving another one.
  constexpr ScalarTemperatureGradient& operator=(
      ScalarTemperatureGradient&& other) noexcept = default;

  // Statically creates a scalar temperature gradient of zero.
  static constexpr ScalarTemperatureGradient Zero() {
    return ScalarTemperatureGradient{0.0};
  }

  // Statically creates a scalar temperature gradient with a given value expressed in a given
  // temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr ScalarTemperatureGradient Create(const double value) {
    return ScalarTemperatureGradient{
        StaticConvertCopy<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            value)};
  }

  constexpr ScalarTemperatureGradient operator+(
      const ScalarTemperatureGradient& scalar_temperature_gradient) const {
    return ScalarTemperatureGradient{value + scalar_temperature_gradient.value};
  }

  constexpr ScalarTemperatureGradient operator-(
      const ScalarTemperatureGradient& scalar_temperature_gradient) const {
    return ScalarTemperatureGradient{value - scalar_temperature_gradient.value};
  }

  constexpr ScalarTemperatureGradient operator*(const double number) const {
    return ScalarTemperatureGradient{value * number};
  }

  constexpr TemperatureDifference operator*(const Length& length) const {
    return {*this, length};
  }

  constexpr TemperatureGradient operator*(const Direction& direction) const;

  constexpr ScalarTemperatureGradient operator/(const double number) const {
    return ScalarTemperatureGradient{value / number};
  }

  constexpr double operator/(
      const ScalarTemperatureGradient& scalar_temperature_gradient) const noexcept {
    return value / scalar_temperature_gradient.value;
  }

  constexpr void operator+=(const ScalarTemperatureGradient& scalar_temperature_gradient) noexcept {
    value += scalar_temperature_gradient.value;
  }

  constexpr void operator-=(const ScalarTemperatureGradient& scalar_temperature_gradient) noexcept {
    value -= scalar_temperature_gradient.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a scalar temperature gradient with a given value expressed in the
  // standard temperature gradient unit.
  explicit constexpr ScalarTemperatureGradient(const double value)
    : DimensionalScalar<Unit::TemperatureGradient>(value) {}

  friend class TemperatureGradient;
};

inline constexpr bool operator==(
    const ScalarTemperatureGradient& left, const ScalarTemperatureGradient& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const ScalarTemperatureGradient& left, const ScalarTemperatureGradient& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const ScalarTemperatureGradient& left, const ScalarTemperatureGradient& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const ScalarTemperatureGradient& left, const ScalarTemperatureGradient& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const ScalarTemperatureGradient& left, const ScalarTemperatureGradient& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const ScalarTemperatureGradient& left, const ScalarTemperatureGradient& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const ScalarTemperatureGradient& scalar_temperature_gradient) {
  stream << scalar_temperature_gradient.Print();
  return stream;
}

inline constexpr ScalarTemperatureGradient operator*(
    const double number, const ScalarTemperatureGradient& scalar_temperature_gradient) {
  return scalar_temperature_gradient * number;
}

inline constexpr TemperatureDifference::TemperatureDifference(
    const ScalarTemperatureGradient& scalar_temperature_gradient, const Length& length)
  : TemperatureDifference(scalar_temperature_gradient.Value() * length.Value()) {}

inline constexpr ScalarTemperatureGradient TemperatureDifference::operator/(
    const Length& length) const {
  return {*this, length};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ScalarTemperatureGradient> {
  inline size_t operator()(
      const PhQ::ScalarTemperatureGradient& scalar_temperature_gradient) const {
    return hash<double>()(scalar_temperature_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_TEMPERATURE_GRADIENT_SCALAR_HPP
