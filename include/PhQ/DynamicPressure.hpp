// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

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

  DynamicPressure(double value, Unit::Pressure unit) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr DynamicPressure(const MassDensity& mass_density, const Speed& speed) noexcept : DynamicPressure(0.5 * mass_density.Value() * std::pow(speed.Value(), 2)) {}

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

  DynamicPressure operator+(const DynamicPressure& dynamic_pressure) const noexcept {
    return {value_ + dynamic_pressure.value_};
  }

  TotalPressure operator+(const StaticPressure& static_pressure) const noexcept;

  constexpr void operator+=(const DynamicPressure& dynamic_pressure) noexcept {
    value_ += dynamic_pressure.value_;
  }

  DynamicPressure operator-(const DynamicPressure& dynamic_pressure) const noexcept {
    return {value_ - dynamic_pressure.value_};
  }

  constexpr void operator-=(const DynamicPressure& dynamic_pressure) noexcept {
    value_ -= dynamic_pressure.value_;
  }

private:

  constexpr DynamicPressure(double value) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value) {}

};

constexpr MassDensity::MassDensity(const DynamicPressure& dynamic_pressure, const Speed& speed) noexcept : MassDensity(2.0 * dynamic_pressure.Value() / (speed.Value() * speed.Value())) {}

constexpr Speed::Speed(const DynamicPressure& dynamic_pressure, const MassDensity& mass_density) noexcept : Speed(std::sqrt(2.0 * dynamic_pressure.Value() / mass_density.Value())) {}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::DynamicPressure> {
  size_t operator()(const PhQ::DynamicPressure& dynamic_pressure) const {
    return hash<double>()(dynamic_pressure.Value());
  }
};

} // namespace std
