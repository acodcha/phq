// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "MassDensity.hpp"
#include "PressureDifference.hpp"
#include "Unit/SpecificEnergy.hpp"

namespace PhQ {

// Forward declaration.
class StaticKinematicPressure;

class KinematicPressureDifference : public DimensionalScalarQuantity<Unit::SpecificEnergy> {

public:

  constexpr KinematicPressureDifference() noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>() {}

  constexpr KinematicPressureDifference(double value, Unit::SpecificEnergy unit) noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>(value, unit) {}

  constexpr KinematicPressureDifference(const PressureDifference& pressure_difference, const MassDensity& mass_density) noexcept : KinematicPressureDifference(pressure_difference.value() / mass_density.value()) {}

  constexpr bool operator==(const KinematicPressureDifference& kinematic_pressure_difference) const noexcept {
    return value_ == kinematic_pressure_difference.value_;
  }

  constexpr bool operator!=(const KinematicPressureDifference& kinematic_pressure_difference) const noexcept {
    return value_ != kinematic_pressure_difference.value_;
  }

  constexpr bool operator<(const KinematicPressureDifference& kinematic_pressure_difference) const noexcept {
    return value_ < kinematic_pressure_difference.value_;
  }

  constexpr bool operator<=(const KinematicPressureDifference& kinematic_pressure_difference) const noexcept {
    return value_ <= kinematic_pressure_difference.value_;
  }

  constexpr bool operator>(const KinematicPressureDifference& kinematic_pressure_difference) const noexcept {
    return value_ > kinematic_pressure_difference.value_;
  }

  constexpr bool operator>=(const KinematicPressureDifference& kinematic_pressure_difference) const noexcept {
    return value_ >= kinematic_pressure_difference.value_;
  }

  constexpr StaticKinematicPressure operator+(const StaticKinematicPressure& kinematic_static_pressure) const noexcept;

  constexpr KinematicPressureDifference operator+(const KinematicPressureDifference& kinematic_pressure_difference) const noexcept {
    return {value_ + kinematic_pressure_difference.value_};
  }

  constexpr void operator+=(const KinematicPressureDifference& kinematic_pressure_difference) noexcept {
    value_ += kinematic_pressure_difference.value_;
  }

  constexpr StaticKinematicPressure operator-(const StaticKinematicPressure& kinematic_static_pressure) const noexcept;

  constexpr KinematicPressureDifference operator-(const KinematicPressureDifference& kinematic_pressure_difference) const noexcept {
    return {value_ - kinematic_pressure_difference.value_};
  }

  constexpr void operator-=(const KinematicPressureDifference& kinematic_pressure_difference) noexcept {
    value_ -= kinematic_pressure_difference.value_;
  }

  constexpr PressureDifference operator*(const MassDensity& mass_density) const noexcept {
    return {*this, mass_density};
  }

protected:

  constexpr KinematicPressureDifference(double value) noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>(value) {}

  friend class StaticKinematicPressure;

};

template <> constexpr bool sort(const KinematicPressureDifference& kinematic_pressure_difference_1, const KinematicPressureDifference& kinematic_pressure_difference_2) noexcept {
  return sort(kinematic_pressure_difference_1.value(), kinematic_pressure_difference_2.value());
}

constexpr PressureDifference::PressureDifference(const KinematicPressureDifference& kinematic_pressure_difference, const MassDensity& mass_density) noexcept : PressureDifference(kinematic_pressure_difference.value() * mass_density.value()) {}

constexpr KinematicPressureDifference PressureDifference::operator/(const MassDensity& mass_density) const noexcept {
  return {*this, mass_density};
}

} // namespace PhQ
