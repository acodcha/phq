// Copyright 2020-2023 Alexandre Coderre-Chabot
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

  KinematicPressureDifference(double value, Unit::SpecificEnergy unit) noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>(value, unit) {}

  constexpr KinematicPressureDifference(const PressureDifference& pressure_difference, const MassDensity& mass_density) noexcept : KinematicPressureDifference(pressure_difference.Value() / mass_density.Value()) {}

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

  KinematicPressureDifference operator+(const KinematicPressureDifference& kinematic_pressure_difference) const noexcept {
    return {value_ + kinematic_pressure_difference.value_};
  }

  constexpr void operator+=(const KinematicPressureDifference& kinematic_pressure_difference) noexcept {
    value_ += kinematic_pressure_difference.value_;
  }

  constexpr StaticKinematicPressure operator-(const StaticKinematicPressure& kinematic_static_pressure) const noexcept;

  KinematicPressureDifference operator-(const KinematicPressureDifference& kinematic_pressure_difference) const noexcept {
    return {value_ - kinematic_pressure_difference.value_};
  }

  constexpr void operator-=(const KinematicPressureDifference& kinematic_pressure_difference) noexcept {
    value_ -= kinematic_pressure_difference.value_;
  }

  PressureDifference operator*(const MassDensity& mass_density) const noexcept {
    return {*this, mass_density};
  }

protected:

  constexpr KinematicPressureDifference(double value) noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>(value) {}

  friend class StaticKinematicPressure;

};

constexpr PressureDifference::PressureDifference(const KinematicPressureDifference& kinematic_pressure_difference, const MassDensity& mass_density) noexcept : PressureDifference(kinematic_pressure_difference.Value() * mass_density.Value()) {}

constexpr KinematicPressureDifference PressureDifference::operator/(const MassDensity& mass_density) const noexcept {
  return {*this, mass_density};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::KinematicPressureDifference> {
  size_t operator()(const PhQ::KinematicPressureDifference& kinematic_pressure_difference) const {
    return hash<double>()(kinematic_pressure_difference.Value());
  }
};

} // namespace std
