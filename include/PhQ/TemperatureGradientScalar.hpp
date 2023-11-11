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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_GRADIENT_SCALAR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_GRADIENT_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Length.hpp"
#include "TemperatureDifference.hpp"
#include "Unit/TemperatureGradient.hpp"

namespace PhQ {

// Forward declarations for class TemperatureGradientScalar.
class Direction;
class TemperatureGradient;

// Scalar temperature gradient component or magnitude of a temperature gradient vector.
class TemperatureGradientScalar : public DimensionalScalar<Unit::TemperatureGradient> {
public:
  // Default constructor. Constructs a scalar temperature gradient with an uninitialized value.
  TemperatureGradientScalar() = default;

  // Constructor. Constructs a scalar temperature gradient with a given value expressed in a given
  // temperature gradient unit.
  TemperatureGradientScalar(const double value, const Unit::TemperatureGradient unit)
    : DimensionalScalar<Unit::TemperatureGradient>(value, unit) {}

  // Constructor. Constructs a scalar temperature gradient from the magnitude of a given temperature
  // gradient vector.
  explicit TemperatureGradientScalar(const TemperatureGradient& temperature_gradient);

  // Constructor. Constructs a scalar temperature gradient from a given temperature difference and
  // length using the definition of temperature gradient.
  constexpr TemperatureGradientScalar(
      const TemperatureDifference& temperature_difference, const Length& length)
    : DimensionalScalar<Unit::TemperatureGradient>(
        temperature_difference.Value() / length.Value()) {}

  // Destructor. Destroys this scalar temperature gradient.
  ~TemperatureGradientScalar() noexcept = default;

  // Copy constructor. Constructs a scalar temperature gradient by copying another one.
  constexpr TemperatureGradientScalar(const TemperatureGradientScalar& other) = default;

  // Move constructor. Constructs a scalar temperature gradient by moving another one.
  constexpr TemperatureGradientScalar(TemperatureGradientScalar&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar temperature gradient by copying another one.
  constexpr TemperatureGradientScalar& operator=(const TemperatureGradientScalar& other) = default;

  // Move assignment operator. Assigns this scalar temperature gradient by moving another one.
  constexpr TemperatureGradientScalar& operator=(
      TemperatureGradientScalar&& other) noexcept = default;

  // Statically creates a scalar temperature gradient of zero.
  static constexpr TemperatureGradientScalar Zero() {
    return TemperatureGradientScalar{0.0};
  }

  // Statically creates a scalar temperature gradient with a given value expressed in a given
  // temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr TemperatureGradientScalar Create(const double value) {
    return TemperatureGradientScalar{
        StaticConvertCopy<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            value)};
  }

  constexpr TemperatureGradientScalar operator+(
      const TemperatureGradientScalar& temperature_gradient_scalar) const {
    return TemperatureGradientScalar{value_ + temperature_gradient_scalar.value_};
  }

  constexpr TemperatureGradientScalar operator-(
      const TemperatureGradientScalar& temperature_gradient_scalar) const {
    return TemperatureGradientScalar{value_ - temperature_gradient_scalar.value_};
  }

  constexpr TemperatureGradientScalar operator*(const double number) const {
    return TemperatureGradientScalar{value_ * number};
  }

  constexpr TemperatureDifference operator*(const Length& length) const {
    return {*this, length};
  }

  constexpr TemperatureGradient operator*(const Direction& direction) const;

  constexpr TemperatureGradientScalar operator/(const double number) const {
    return TemperatureGradientScalar{value_ / number};
  }

  constexpr double operator/(
      const TemperatureGradientScalar& temperature_gradient_scalar) const noexcept {
    return value_ / temperature_gradient_scalar.value_;
  }

  constexpr void operator+=(const TemperatureGradientScalar& temperature_gradient_scalar) noexcept {
    value_ += temperature_gradient_scalar.value_;
  }

  constexpr void operator-=(const TemperatureGradientScalar& temperature_gradient_scalar) noexcept {
    value_ -= temperature_gradient_scalar.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a scalar temperature gradient with a given value expressed in the
  // standard temperature gradient unit.
  explicit constexpr TemperatureGradientScalar(const double value)
    : DimensionalScalar<Unit::TemperatureGradient>(value) {}
};

inline constexpr bool operator==(
    const TemperatureGradientScalar& left, const TemperatureGradientScalar& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const TemperatureGradientScalar& left, const TemperatureGradientScalar& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const TemperatureGradientScalar& left, const TemperatureGradientScalar& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const TemperatureGradientScalar& left, const TemperatureGradientScalar& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const TemperatureGradientScalar& left, const TemperatureGradientScalar& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const TemperatureGradientScalar& left, const TemperatureGradientScalar& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const TemperatureGradientScalar& temperature_gradient_scalar) {
  stream << temperature_gradient_scalar.Print();
  return stream;
}

inline constexpr TemperatureGradientScalar operator*(
    const double number, const TemperatureGradientScalar& temperature_gradient_scalar) {
  return temperature_gradient_scalar * number;
}

inline constexpr TemperatureDifference::TemperatureDifference(
    const TemperatureGradientScalar& temperature_gradient_scalar, const Length& length)
  : TemperatureDifference(temperature_gradient_scalar.Value() * length.Value()) {}

inline constexpr TemperatureGradientScalar TemperatureDifference::operator/(
    const Length& length) const {
  return {*this, length};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::TemperatureGradientScalar> {
  inline size_t operator()(
      const PhQ::TemperatureGradientScalar& temperature_gradient_scalar) const {
    return hash<double>()(temperature_gradient_scalar.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_GRADIENT_SCALAR_HPP
