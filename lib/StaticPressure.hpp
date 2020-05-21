// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "ForceMagnitude.hpp"
#include "PressureDifference.hpp"

namespace PhQ {

// Forward declarations.
class Direction;
class DynamicPressure;
class Stress;
class TotalPressure;
class Traction;

class StaticPressure : public DimensionalScalarQuantity<Unit::Pressure> {

public:

  constexpr StaticPressure() noexcept : DimensionalScalarQuantity<Unit::Pressure>() {}

  constexpr StaticPressure(double value, Unit::Pressure unit) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr StaticPressure(const ForceMagnitude& force_magnitude, const Area& area) noexcept : StaticPressure(force_magnitude.value() / area.value()) {}

  constexpr StaticPressure(const Traction& traction) noexcept;

  constexpr StaticPressure(const TotalPressure& total_pressure, const DynamicPressure& dynamic_pressure) noexcept;

  constexpr Stress stress() const noexcept;

  constexpr bool operator==(const StaticPressure& static_pressure) const noexcept {
    return value_ == static_pressure.value_;
  }

  constexpr bool operator!=(const StaticPressure& static_pressure) const noexcept {
    return value_ != static_pressure.value_;
  }

  constexpr bool operator<(const StaticPressure& static_pressure) const noexcept {
    return value_ < static_pressure.value_;
  }

  constexpr bool operator<=(const StaticPressure& static_pressure) const noexcept {
    return value_ <= static_pressure.value_;
  }

  constexpr bool operator>(const StaticPressure& static_pressure) const noexcept {
    return value_ > static_pressure.value_;
  }

  constexpr bool operator>=(const StaticPressure& static_pressure) const noexcept {
    return value_ >= static_pressure.value_;
  }

  constexpr StaticPressure operator+(const StaticPressure& static_pressure) const noexcept {
    return {value_ + static_pressure.value_};
  }

  constexpr StaticPressure operator+(const PressureDifference& pressure_difference) const noexcept {
    return {value_ + pressure_difference.value()};
  }

  constexpr TotalPressure operator+(const DynamicPressure& dynamic_pressure) const noexcept;

  constexpr void operator+=(const StaticPressure& static_pressure) noexcept {
    value_ += static_pressure.value_;
  }

  constexpr void operator+=(const PressureDifference& pressure_difference) noexcept {
    value_ += pressure_difference.value();
  }

  constexpr PressureDifference operator-(const StaticPressure& static_pressure) const noexcept {
    return {value_ - static_pressure.value_};
  }

  constexpr StaticPressure operator-(const PressureDifference& pressure_difference) const noexcept {
    return {value_ - pressure_difference.value()};
  }

  constexpr void operator-=(const StaticPressure& static_pressure) noexcept {
    value_ -= static_pressure.value_;
  }

  constexpr void operator-=(const PressureDifference& pressure_difference) noexcept {
    value_ -= pressure_difference.value();
  }

  constexpr ForceMagnitude operator*(const Area& area) const noexcept {
    return {*this, area};
  }

  constexpr Traction operator*(const Direction& direction) const noexcept;

protected:

  constexpr StaticPressure(double value) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value) {}

  friend class PressureDifference;

};

template <> constexpr bool sort(const StaticPressure& static_pressure_1, const StaticPressure& static_pressure_2) noexcept {
  return sort(static_pressure_1.value(), static_pressure_2.value());
}

constexpr Area::Area(const StaticPressure& static_pressure, const ForceMagnitude& force_magnitude) noexcept : Area(force_magnitude.value() / static_pressure.value()) {}

constexpr ForceMagnitude::ForceMagnitude(const StaticPressure& static_pressure, const Area& area) noexcept : ForceMagnitude(static_pressure.value() * area.value()) {}

constexpr ForceMagnitude Area::operator*(const StaticPressure& static_pressure) const noexcept {
  return {static_pressure, *this};
}

constexpr StaticPressure ForceMagnitude::operator/(const Area& area) const noexcept {
  return {*this, area};
}

constexpr StaticPressure PressureDifference::operator+(const StaticPressure& static_pressure) const noexcept {
  return {value_ + static_pressure.value()};
}

constexpr StaticPressure PressureDifference::operator-(const StaticPressure& static_pressure) const noexcept {
  return {value_ - static_pressure.value()};
}

} // namespace PhQ
