// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Angle.hpp"
#include "Direction.hpp"
#include "Quantity/DimensionalVector.hpp"
#include "TemperatureGradientMagnitude.hpp"

namespace PhQ {

class TemperatureGradient : public DimensionalVectorQuantity<Unit::TemperatureGradient> {

public:

  constexpr TemperatureGradient() noexcept : DimensionalVectorQuantity<Unit::TemperatureGradient>() {}

  TemperatureGradient(const Value::Vector& value, Unit::TemperatureGradient unit) noexcept : DimensionalVectorQuantity<Unit::TemperatureGradient>(value, unit) {}

  constexpr TemperatureGradient(const TemperatureGradientMagnitude& temperature_gradient_magnitude, const Direction& direction) noexcept : TemperatureGradient(temperature_gradient_magnitude.Value() * direction.Value()) {}

  TemperatureGradientMagnitude magnitude() const noexcept {
    return {*this};
  }

  Angle angle(const TemperatureGradient& temperature_gradient) const noexcept {
    return {*this, temperature_gradient};
  }

  constexpr bool operator==(const TemperatureGradient& temperature_gradient) const noexcept {
    return value_ == temperature_gradient.value_;
  }

  constexpr bool operator!=(const TemperatureGradient& temperature_gradient) const noexcept {
    return value_ != temperature_gradient.value_;
  }

  TemperatureGradient operator+(const TemperatureGradient& temperature_gradient) const noexcept {
    return {value_ + temperature_gradient.value_};
  }

  constexpr void operator+=(const TemperatureGradient& temperature_gradient) noexcept {
    value_ += temperature_gradient.value_;
  }

  TemperatureGradient operator-(const TemperatureGradient& temperature_gradient) const noexcept {
    return {value_ - temperature_gradient.value_};
  }

  constexpr void operator-=(const TemperatureGradient& temperature_gradient) noexcept {
    value_ -= temperature_gradient.value_;
  }

protected:

  constexpr TemperatureGradient(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::TemperatureGradient>(value) {}

};

Direction::Direction(const TemperatureGradient& temperature_gradient) : Direction(temperature_gradient.Value()) {}

Angle::Angle(const TemperatureGradient& temperature_gradient_1, const TemperatureGradient& temperature_gradient_2) noexcept : Angle(temperature_gradient_1.Value(), temperature_gradient_2.Value()) {}

TemperatureGradientMagnitude::TemperatureGradientMagnitude(const TemperatureGradient& temperature_gradient) noexcept : TemperatureGradientMagnitude(temperature_gradient.Value().Magnitude()) {}

TemperatureGradient Direction::operator*(const TemperatureGradientMagnitude& temperature_gradient_magnitude) const noexcept {
  return {temperature_gradient_magnitude, *this};
}

TemperatureGradient TemperatureGradientMagnitude::operator*(const Direction& direction) const noexcept {
  return {*this, direction};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::TemperatureGradient> {
  size_t operator()(const PhQ::TemperatureGradient& temperature_gradient) const {
    return hash<PhQ::Value::Vector>()(temperature_gradient.Value());
  }
};

} // namespace std
