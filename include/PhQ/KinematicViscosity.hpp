// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Diffusivity.hpp"

namespace PhQ {

// Forward declarations.
class DynamicViscosity;
class Length;
class MassDensity;
class PrandtlNumber;
class ReynoldsNumber;
class Speed;
class ThermalDiffusivity;

class KinematicViscosity : public DimensionalScalarQuantity<Unit::Diffusivity> {

public:

  constexpr KinematicViscosity() noexcept : DimensionalScalarQuantity<Unit::Diffusivity>() {}

  constexpr KinematicViscosity(double value, Unit::Diffusivity unit) noexcept : DimensionalScalarQuantity<Unit::Diffusivity>(value, unit) {}

  constexpr KinematicViscosity(const DynamicViscosity& dynamic_viscosity, const MassDensity& mass_density) noexcept;

  constexpr KinematicViscosity(const ReynoldsNumber& reynolds_number, const Speed& speed, const Length& length) noexcept;

  constexpr KinematicViscosity(const PrandtlNumber& prandtl_number, const ThermalDiffusivity& thermal_diffusivity) noexcept;

  constexpr bool operator==(const KinematicViscosity& kinematic_viscosity) const noexcept {
    return value_ == kinematic_viscosity.value_;
  }

  constexpr bool operator!=(const KinematicViscosity& kinematic_viscosity) const noexcept {
    return value_ != kinematic_viscosity.value_;
  }

  constexpr bool operator<(const KinematicViscosity& kinematic_viscosity) const noexcept {
    return value_ < kinematic_viscosity.value_;
  }

  constexpr bool operator<=(const KinematicViscosity& kinematic_viscosity) const noexcept {
    return value_ <= kinematic_viscosity.value_;
  }

  constexpr bool operator>(const KinematicViscosity& kinematic_viscosity) const noexcept {
    return value_ > kinematic_viscosity.value_;
  }

  constexpr bool operator>=(const KinematicViscosity& kinematic_viscosity) const noexcept {
    return value_ >= kinematic_viscosity.value_;
  }

  constexpr KinematicViscosity operator+(const KinematicViscosity& kinematic_viscosity) const noexcept {
    return {value_ + kinematic_viscosity.value_};
  }

  constexpr void operator+=(const KinematicViscosity& kinematic_viscosity) noexcept {
    value_ += kinematic_viscosity.value_;
  }

  constexpr KinematicViscosity operator-(const KinematicViscosity& kinematic_viscosity) const noexcept {
    return {value_ - kinematic_viscosity.value_};
  }

  constexpr void operator-=(const KinematicViscosity& kinematic_viscosity) noexcept {
    value_ -= kinematic_viscosity.value_;
  }

  constexpr DynamicViscosity operator*(const MassDensity& mass_density) const noexcept;

protected:

  constexpr KinematicViscosity(double value) noexcept : DimensionalScalarQuantity<Unit::Diffusivity>(value) {}

};

template <> constexpr bool sort(const KinematicViscosity& kinematic_viscosity_1, const KinematicViscosity& kinematic_viscosity_2) noexcept {
  return sort(kinematic_viscosity_1.value(), kinematic_viscosity_2.value());
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::KinematicViscosity> {
  size_t operator()(const PhQ::KinematicViscosity& kinematic_viscosity) const {
    return hash<double>()(kinematic_viscosity.value());
  }
};

} // namespace std
