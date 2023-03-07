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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_GRADIENT_MAGNITUDE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_GRADIENT_MAGNITUDE_HPP

#include "Length.hpp"
#include "Temperature.hpp"
#include "Unit/TemperatureGradient.hpp"

namespace PhQ {

// Forward declarations for class TemperatureGradientMagnitude.
class Direction;
class TemperatureGradient;

class TemperatureGradientMagnitude
    : public DimensionalScalarQuantity<Unit::TemperatureGradient> {
public:
  constexpr TemperatureGradientMagnitude() noexcept
      : DimensionalScalarQuantity<Unit::TemperatureGradient>() {}

  TemperatureGradientMagnitude(const double value,
                               const Unit::TemperatureGradient unit) noexcept
      : DimensionalScalarQuantity<Unit::TemperatureGradient>(value, unit) {}

  TemperatureGradientMagnitude(
      const TemperatureGradient& temperature_gradient) noexcept;

  constexpr TemperatureGradientMagnitude(
      const TemperatureDifference& temperature_difference,
      const Length& length) noexcept
      : DimensionalScalarQuantity<Unit::TemperatureGradient>(
            temperature_difference.Value() / length.Value()) {}

  inline TemperatureGradientMagnitude operator+(
      const TemperatureGradientMagnitude& temperature_gradient_magnitude)
      const noexcept {
    return TemperatureGradientMagnitude{value_ +
                                        temperature_gradient_magnitude.value_};
  }

  inline TemperatureGradientMagnitude operator-(
      const TemperatureGradientMagnitude& temperature_gradient_magnitude)
      const noexcept {
    return TemperatureGradientMagnitude{value_ -
                                        temperature_gradient_magnitude.value_};
  }

  inline TemperatureGradientMagnitude operator*(
      const double number) const noexcept {
    return TemperatureGradientMagnitude{value_ * number};
  }

  inline TemperatureDifference operator*(const Length& length) const noexcept {
    return {*this, length};
  }

  inline TemperatureGradient operator*(
      const Direction& direction) const noexcept;

  inline TemperatureGradientMagnitude operator/(
      const double number) const noexcept {
    return TemperatureGradientMagnitude{value_ / number};
  }

  inline constexpr void operator+=(
      const TemperatureGradientMagnitude&
          temperature_gradient_magnitude) noexcept {
    value_ += temperature_gradient_magnitude.value_;
  }

  inline constexpr void operator-=(
      const TemperatureGradientMagnitude&
          temperature_gradient_magnitude) noexcept {
    value_ -= temperature_gradient_magnitude.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr TemperatureGradientMagnitude(const double value) noexcept
      : DimensionalScalarQuantity<Unit::TemperatureGradient>(value) {}
};

inline constexpr bool operator==(
    const TemperatureGradientMagnitude& left,
    const TemperatureGradientMagnitude& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const TemperatureGradientMagnitude& left,
    const TemperatureGradientMagnitude& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const TemperatureGradientMagnitude& left,
    const TemperatureGradientMagnitude& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const TemperatureGradientMagnitude& left,
    const TemperatureGradientMagnitude& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const TemperatureGradientMagnitude& left,
    const TemperatureGradientMagnitude& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const TemperatureGradientMagnitude& left,
    const TemperatureGradientMagnitude& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const TemperatureGradientMagnitude&
                                    temperature_gradient_magnitude) noexcept {
  stream << temperature_gradient_magnitude.Print();
  return stream;
}

inline TemperatureGradientMagnitude operator*(
    const double number, const TemperatureGradientMagnitude&
                             temperature_gradient_magnitude) noexcept {
  return temperature_gradient_magnitude * number;
}

inline constexpr TemperatureDifference::TemperatureDifference(
    const TemperatureGradientMagnitude& temperature_gradient_magnitude,
    const Length& length) noexcept
    : TemperatureDifference(temperature_gradient_magnitude.Value() *
                            length.Value()) {}

inline TemperatureGradientMagnitude TemperatureDifference::operator/(
    const Length& length) const noexcept {
  return {*this, length};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::TemperatureGradientMagnitude> {
  size_t operator()(const PhQ::TemperatureGradientMagnitude&
                        temperature_gradient_magnitude) const {
    return hash<double>()(temperature_gradient_magnitude.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_TEMPERATURE_GRADIENT_MAGNITUDE_HPP
