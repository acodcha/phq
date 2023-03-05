// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "DynamicPressure.hpp"
#include "StaticKinematicPressure.hpp"

namespace PhQ {

// Forward declaration.
class TotalKinematicPressure;

class DynamicKinematicPressure : public DimensionalScalarQuantity<Unit::SpecificEnergy> {

public:

  constexpr DynamicKinematicPressure() noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>() {}

  DynamicKinematicPressure(double value, Unit::SpecificEnergy unit) noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>(value, unit) {}

  constexpr DynamicKinematicPressure(const Speed& speed) noexcept : DynamicKinematicPressure(0.5 * std::pow(speed.Value(), 2)) {}

  constexpr DynamicKinematicPressure(const TotalKinematicPressure& total_kinematic_pressure, const StaticKinematicPressure& static_kinematic_pressure) noexcept;

  constexpr DynamicKinematicPressure(const DynamicPressure& dynamic_pressure, const MassDensity& mass_density) noexcept : DynamicKinematicPressure(dynamic_pressure.Value() / mass_density.Value()) {}

  constexpr bool operator==(const DynamicKinematicPressure& dynamic_kinematic_pressure) const noexcept {
    return value_ == dynamic_kinematic_pressure.value_;
  }

  constexpr bool operator!=(const DynamicKinematicPressure& dynamic_kinematic_pressure) const noexcept {
    return value_ != dynamic_kinematic_pressure.value_;
  }

  constexpr bool operator<(const DynamicKinematicPressure& dynamic_kinematic_pressure) const noexcept {
    return value_ < dynamic_kinematic_pressure.value_;
  }

  constexpr bool operator<=(const DynamicKinematicPressure& dynamic_kinematic_pressure) const noexcept {
    return value_ <= dynamic_kinematic_pressure.value_;
  }

  constexpr bool operator>(const DynamicKinematicPressure& dynamic_kinematic_pressure) const noexcept {
    return value_ > dynamic_kinematic_pressure.value_;
  }

  constexpr bool operator>=(const DynamicKinematicPressure& dynamic_kinematic_pressure) const noexcept {
    return value_ >= dynamic_kinematic_pressure.value_;
  }

  DynamicKinematicPressure operator+(const DynamicKinematicPressure& dynamic_kinematic_pressure) const noexcept {
    return {value_ + dynamic_kinematic_pressure.value_};
  }

  TotalKinematicPressure operator+(const StaticKinematicPressure& static_kinematic_pressure) const noexcept;

  constexpr void operator+=(const DynamicKinematicPressure& dynamic_kinematic_pressure) noexcept {
    value_ += dynamic_kinematic_pressure.value_;
  }

  DynamicKinematicPressure operator-(const DynamicKinematicPressure& dynamic_kinematic_pressure) const noexcept {
    return {value_ - dynamic_kinematic_pressure.value_};
  }

  constexpr void operator-=(const DynamicKinematicPressure& dynamic_kinematic_pressure) noexcept {
    value_ -= dynamic_kinematic_pressure.value_;
  }

private:

  constexpr DynamicKinematicPressure(double value) noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>(value) {}

};

Speed::Speed(const DynamicKinematicPressure& dynamic_kinematic_pressure) noexcept : Speed(std::sqrt(2.0 * dynamic_kinematic_pressure.Value())) {}

constexpr DynamicPressure::DynamicPressure(const DynamicKinematicPressure& dynamic_kinematic_pressure, const MassDensity& mass_density) noexcept : DynamicPressure(dynamic_kinematic_pressure.Value() * mass_density.Value()) {}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::DynamicKinematicPressure> {
  size_t operator()(const PhQ::DynamicKinematicPressure& dynamic_kinematic_pressure) const {
    return hash<double>()(dynamic_kinematic_pressure.Value());
  }
};

} // namespace std
