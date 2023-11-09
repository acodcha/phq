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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_GRADIENT_MAGNITUDE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_GRADIENT_MAGNITUDE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalarQuantity.hpp"
#include "Length.hpp"
#include "TemperatureDifference.hpp"
#include "Unit/TemperatureGradient.hpp"

namespace PhQ {

// Forward declarations for class TemperatureGradientMagnitude.
class Direction;
class TemperatureGradient;

// Temperature gradient scalar. Magnitude of a temperature gradient vector.
class TemperatureGradientMagnitude : public DimensionalScalarQuantity<Unit::TemperatureGradient> {
public:
  // Default constructor. Constructs a temperature gradient magnitude with an uninitialized value.
  TemperatureGradientMagnitude() = default;

  // Constructor. Constructs a temperature gradient magnitude with a given value expressed in a
  // given temperature gradient unit.
  TemperatureGradientMagnitude(const double value, const Unit::TemperatureGradient unit)
    : DimensionalScalarQuantity<Unit::TemperatureGradient>(value, unit) {}

  // Constructor. Constructs a temperature gradient magnitude from a given temperature gradient
  // vector.
  explicit TemperatureGradientMagnitude(const TemperatureGradient& temperature_gradient);

  // Constructor. Constructs a temperature gradient magnitude from a given temperature difference
  // and length using the definition of temperature gradient.
  constexpr TemperatureGradientMagnitude(
      const TemperatureDifference& temperature_difference, const Length& length)
    : DimensionalScalarQuantity<Unit::TemperatureGradient>(
        temperature_difference.Value() / length.Value()) {}

  // Destructor. Destroys this temperature gradient magnitude.
  ~TemperatureGradientMagnitude() noexcept = default;

  // Copy constructor. Constructs a temperature gradient magnitude by copying another one.
  constexpr TemperatureGradientMagnitude(const TemperatureGradientMagnitude& other) = default;

  // Move constructor. Constructs a temperature gradient magnitude by moving another one.
  constexpr TemperatureGradientMagnitude(TemperatureGradientMagnitude&& other) noexcept = default;

  // Copy assignment operator. Assigns this temperature gradient magnitude by copying another one.
  constexpr TemperatureGradientMagnitude& operator=(
      const TemperatureGradientMagnitude& other) = default;

  // Move assignment operator. Assigns this temperature gradient magnitude by moving another one.
  constexpr TemperatureGradientMagnitude& operator=(
      TemperatureGradientMagnitude&& other) noexcept = default;

  // Statically creates a temperature gradient magnitude of zero.
  static constexpr TemperatureGradientMagnitude Zero() {
    return TemperatureGradientMagnitude{0.0};
  }

  // Statically creates a temperature gradient magnitude with a given value expressed in a given
  // temperature gradient unit.
  template <Unit::TemperatureGradient Unit>
  static constexpr TemperatureGradientMagnitude Create(const double value) {
    return TemperatureGradientMagnitude{
        StaticConvertCopy<Unit::TemperatureGradient, Unit, Standard<Unit::TemperatureGradient>>(
            value)};
  }

  constexpr TemperatureGradientMagnitude operator+(
      const TemperatureGradientMagnitude& temperature_gradient_magnitude) const {
    return TemperatureGradientMagnitude{value_ + temperature_gradient_magnitude.value_};
  }

  constexpr TemperatureGradientMagnitude operator-(
      const TemperatureGradientMagnitude& temperature_gradient_magnitude) const {
    return TemperatureGradientMagnitude{value_ - temperature_gradient_magnitude.value_};
  }

  constexpr TemperatureGradientMagnitude operator*(const double number) const {
    return TemperatureGradientMagnitude{value_ * number};
  }

  constexpr TemperatureDifference operator*(const Length& length) const {
    return {*this, length};
  }

  constexpr TemperatureGradient operator*(const Direction& direction) const;

  constexpr TemperatureGradientMagnitude operator/(const double number) const {
    return TemperatureGradientMagnitude{value_ / number};
  }

  constexpr double operator/(
      const TemperatureGradientMagnitude& temperature_gradient_magnitude) const noexcept {
    return value_ / temperature_gradient_magnitude.value_;
  }

  constexpr void operator+=(
      const TemperatureGradientMagnitude& temperature_gradient_magnitude) noexcept {
    value_ += temperature_gradient_magnitude.value_;
  }

  constexpr void operator-=(
      const TemperatureGradientMagnitude& temperature_gradient_magnitude) noexcept {
    value_ -= temperature_gradient_magnitude.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a temperature gradient magnitude with a given value expressed in the
  // standard temperature gradient unit.
  explicit constexpr TemperatureGradientMagnitude(const double value)
    : DimensionalScalarQuantity<Unit::TemperatureGradient>(value) {}
};

inline constexpr bool operator==(
    const TemperatureGradientMagnitude& left, const TemperatureGradientMagnitude& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const TemperatureGradientMagnitude& left, const TemperatureGradientMagnitude& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const TemperatureGradientMagnitude& left, const TemperatureGradientMagnitude& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const TemperatureGradientMagnitude& left, const TemperatureGradientMagnitude& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const TemperatureGradientMagnitude& left, const TemperatureGradientMagnitude& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const TemperatureGradientMagnitude& left, const TemperatureGradientMagnitude& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const TemperatureGradientMagnitude& temperature_gradient_magnitude) {
  stream << temperature_gradient_magnitude.Print();
  return stream;
}

inline constexpr TemperatureGradientMagnitude operator*(
    const double number, const TemperatureGradientMagnitude& temperature_gradient_magnitude) {
  return temperature_gradient_magnitude * number;
}

inline constexpr TemperatureDifference::TemperatureDifference(
    const TemperatureGradientMagnitude& temperature_gradient_magnitude, const Length& length)
  : TemperatureDifference(temperature_gradient_magnitude.Value() * length.Value()) {}

inline constexpr TemperatureGradientMagnitude TemperatureDifference::operator/(
    const Length& length) const {
  return {*this, length};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::TemperatureGradientMagnitude> {
  inline size_t operator()(
      const PhQ::TemperatureGradientMagnitude& temperature_gradient_magnitude) const {
    return hash<double>()(temperature_gradient_magnitude.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_GRADIENT_MAGNITUDE_HPP
