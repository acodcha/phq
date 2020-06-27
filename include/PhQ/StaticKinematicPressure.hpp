// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "KinematicPressureDifference.hpp"
#include "StaticPressure.hpp"

namespace PhQ {

// Forward declarations.
class DynamicKinematicPressure;
class TotalKinematicPressure;

class StaticKinematicPressure : public DimensionalScalarQuantity<Unit::SpecificEnergy> {

public:

  constexpr StaticKinematicPressure() noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>() {}

  constexpr StaticKinematicPressure(double value, Unit::SpecificEnergy unit) noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>(value, unit) {}

  constexpr StaticKinematicPressure(const TotalKinematicPressure& total_kinematic_pressure, const DynamicKinematicPressure& dynamic_kinematic_pressure) noexcept;

  constexpr StaticKinematicPressure(const StaticPressure& static_pressure, const MassDensity& mass_density) noexcept : StaticKinematicPressure(static_pressure.value() / mass_density.value()) {}

  constexpr bool operator==(const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
    return value_ == static_kinematic_pressure.value_;
  }

  constexpr bool operator!=(const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
    return value_ != static_kinematic_pressure.value_;
  }

  constexpr bool operator<(const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
    return value_ < static_kinematic_pressure.value_;
  }

  constexpr bool operator<=(const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
    return value_ <= static_kinematic_pressure.value_;
  }

  constexpr bool operator>(const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
    return value_ > static_kinematic_pressure.value_;
  }

  constexpr bool operator>=(const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
    return value_ >= static_kinematic_pressure.value_;
  }

  constexpr StaticKinematicPressure operator+(const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
    return {value_ + static_kinematic_pressure.value_};
  }

  constexpr StaticKinematicPressure operator+(const KinematicPressureDifference& kinematic_pressure_difference) const noexcept {
    return {value_ + kinematic_pressure_difference.value()};
  }

  constexpr TotalKinematicPressure operator+(const DynamicKinematicPressure& dynamic_kinematic_pressure) const noexcept;

  constexpr void operator+=(const StaticKinematicPressure& static_kinematic_pressure) noexcept {
    value_ += static_kinematic_pressure.value_;
  }

  constexpr void operator+=(const KinematicPressureDifference& kinematic_pressure_difference) noexcept {
    value_ += kinematic_pressure_difference.value();
  }

  constexpr KinematicPressureDifference operator-(const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
    return {value_ - static_kinematic_pressure.value_};
  }

  constexpr StaticKinematicPressure operator-(const KinematicPressureDifference& kinematic_pressure_difference) const noexcept {
    return {value_ - kinematic_pressure_difference.value()};
  }

  constexpr void operator-=(const StaticKinematicPressure& static_kinematic_pressure) noexcept {
    value_ -= static_kinematic_pressure.value_;
  }

  constexpr void operator-=(const KinematicPressureDifference& kinematic_pressure_difference) noexcept {
    value_ -= kinematic_pressure_difference.value();
  }

  constexpr StaticPressure operator*(const MassDensity& mass_density) const noexcept {
    return {*this, mass_density};
  }

protected:

  constexpr StaticKinematicPressure(double value) noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>(value) {}

  friend class KinematicPressureDifference;

};

template <> constexpr bool sort(const StaticKinematicPressure& static_kinematic_pressure_1, const StaticKinematicPressure& static_kinematic_pressure_2) noexcept {
  return sort(static_kinematic_pressure_1.value(), static_kinematic_pressure_2.value());
}

constexpr StaticPressure::StaticPressure(const StaticKinematicPressure& static_kinematic_pressure, const MassDensity& mass_density) noexcept : StaticPressure(static_kinematic_pressure.value() * mass_density.value()) {}

constexpr StaticKinematicPressure StaticPressure::operator/(const MassDensity& mass_density) const noexcept {
  return {*this, mass_density};
}

constexpr StaticKinematicPressure KinematicPressureDifference::operator+(const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
  return {value_ + static_kinematic_pressure.value()};
}

constexpr StaticKinematicPressure KinematicPressureDifference::operator-(const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
  return {value_ - static_kinematic_pressure.value()};
}

} // namespace PhQ
