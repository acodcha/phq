// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "MassDensity.hpp"
#include "Speed.hpp"
#include "StaticPressure.hpp"

namespace PhQ {

// Forward declaration.
class DynamicKinematicPressure;

class DynamicPressure : public DimensionalScalarQuantity<Unit::Pressure> {

public:

  constexpr DynamicPressure() noexcept : DimensionalScalarQuantity<Unit::Pressure>() {}

  constexpr DynamicPressure(double value, Unit::Pressure unit) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr DynamicPressure(const MassDensity& mass_density, const Speed& speed) noexcept : DynamicPressure(0.5 * mass_density.value() * std::pow(speed.value(), 2)) {}

  constexpr DynamicPressure(const TotalPressure& total_pressure, const StaticPressure& static_pressure) noexcept;

  constexpr DynamicPressure(const DynamicKinematicPressure& dynamic_kinematic_pressure, const MassDensity& mass_density) noexcept;

  constexpr bool operator==(const DynamicPressure& dynamic_pressure) const noexcept {
    return value_ == dynamic_pressure.value_;
  }

  constexpr bool operator!=(const DynamicPressure& dynamic_pressure) const noexcept {
    return value_ != dynamic_pressure.value_;
  }

  constexpr bool operator<(const DynamicPressure& dynamic_pressure) const noexcept {
    return value_ < dynamic_pressure.value_;
  }

  constexpr bool operator<=(const DynamicPressure& dynamic_pressure) const noexcept {
    return value_ <= dynamic_pressure.value_;
  }

  constexpr bool operator>(const DynamicPressure& dynamic_pressure) const noexcept {
    return value_ > dynamic_pressure.value_;
  }

  constexpr bool operator>=(const DynamicPressure& dynamic_pressure) const noexcept {
    return value_ >= dynamic_pressure.value_;
  }

  constexpr DynamicPressure operator+(const DynamicPressure& dynamic_pressure) const noexcept {
    return {value_ + dynamic_pressure.value_};
  }

  constexpr TotalPressure operator+(const StaticPressure& static_pressure) const noexcept;

  constexpr void operator+=(const DynamicPressure& dynamic_pressure) noexcept {
    value_ += dynamic_pressure.value_;
  }

  constexpr DynamicPressure operator-(const DynamicPressure& dynamic_pressure) const noexcept {
    return {value_ - dynamic_pressure.value_};
  }

  constexpr void operator-=(const DynamicPressure& dynamic_pressure) noexcept {
    value_ -= dynamic_pressure.value_;
  }

protected:

  constexpr DynamicPressure(double value) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value) {}

};

template <> constexpr bool sort(const DynamicPressure& dynamic_pressure_1, const DynamicPressure& dynamic_pressure_2) noexcept {
  return sort(dynamic_pressure_1.value(), dynamic_pressure_2.value());
}

constexpr MassDensity::MassDensity(const DynamicPressure& dynamic_pressure, const Speed& speed) noexcept : MassDensity(2.0 * dynamic_pressure.value() / std::pow(speed.value(), 2)) {}

constexpr Speed::Speed(const DynamicPressure& dynamic_pressure, const MassDensity& mass_density) noexcept : Speed(std::sqrt(2.0 * dynamic_pressure.value() / mass_density.value())) {}

} // namespace PhQ
