// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "ForceMagnitude.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declaration.
class Direction;
class Traction;

class StaticPressure : public DimensionalScalarQuantity<Unit::Pressure> {

public:

  constexpr StaticPressure() noexcept : DimensionalScalarQuantity<Unit::Pressure>() {}

  constexpr StaticPressure(double value, Unit::Pressure unit) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr StaticPressure(const Traction& traction) noexcept;

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

  constexpr void operator+=(const StaticPressure& static_pressure) noexcept {
    value_ += static_pressure.value_;
  }

  constexpr StaticPressure operator-(const StaticPressure& static_pressure) const noexcept {
    return {value_ - static_pressure.value_};
  }

  constexpr void operator-=(const StaticPressure& static_pressure) noexcept {
    value_ -= static_pressure.value_;
  }

  constexpr ForceMagnitude operator*(const Area& area) const noexcept {
    return {value_ * area.value_};
  }

  constexpr Traction operator*(const Direction& direction) const noexcept;

protected:

  constexpr StaticPressure(double value) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value) {}

  friend class Area;
  friend class Direction;
  friend class ForceMagnitude;
  friend class Traction;

};

template <> constexpr bool sort(const StaticPressure& static_pressure_1, const StaticPressure& static_pressure_2) noexcept {
  return static_pressure_1.value() < static_pressure_2.value();
}

constexpr ForceMagnitude Area::operator*(const StaticPressure& static_pressure) const noexcept {
  return {value_ * static_pressure.value_};
}

constexpr StaticPressure ForceMagnitude::operator/(const Area& area) const noexcept {
  return {value_ / area.value_};
}

} // namespace PhQ
