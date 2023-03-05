// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "KinematicViscosity.hpp"
#include "MassDensity.hpp"
#include "Unit/DynamicViscosity.hpp"

namespace PhQ {

// Forward declarations.
class ReynoldsNumber;
class ThermalConductivityScalar;
class SpecificIsobaricHeatCapacity;

class DynamicViscosity : public DimensionalScalarQuantity<Unit::DynamicViscosity> {

public:

  constexpr DynamicViscosity() noexcept : DimensionalScalarQuantity<Unit::DynamicViscosity>() {}

  DynamicViscosity(double value, Unit::DynamicViscosity unit) noexcept : DimensionalScalarQuantity<Unit::DynamicViscosity>(value, unit) {}

  constexpr DynamicViscosity(const KinematicViscosity& kinematic_viscosity, const MassDensity& mass_density) noexcept : DynamicViscosity(kinematic_viscosity.Value() * mass_density.Value()) {}

  constexpr DynamicViscosity(const ReynoldsNumber& reynolds_number, const MassDensity& mass_density, const Speed& speed, const Length& length) noexcept;

  constexpr DynamicViscosity(const PrandtlNumber& prandtl_number, const ThermalConductivityScalar& thermal_conductivity_scalar, SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept;

  constexpr bool operator==(const DynamicViscosity& dynamic_viscosity) const noexcept {
    return value_ == dynamic_viscosity.value_;
  }

  constexpr bool operator!=(const DynamicViscosity& dynamic_viscosity) const noexcept {
    return value_ != dynamic_viscosity.value_;
  }

  constexpr bool operator<(const DynamicViscosity& dynamic_viscosity) const noexcept {
    return value_ < dynamic_viscosity.value_;
  }

  constexpr bool operator<=(const DynamicViscosity& dynamic_viscosity) const noexcept {
    return value_ <= dynamic_viscosity.value_;
  }

  constexpr bool operator>(const DynamicViscosity& dynamic_viscosity) const noexcept {
    return value_ > dynamic_viscosity.value_;
  }

  constexpr bool operator>=(const DynamicViscosity& dynamic_viscosity) const noexcept {
    return value_ >= dynamic_viscosity.value_;
  }

  DynamicViscosity operator+(const DynamicViscosity& dynamic_viscosity) const noexcept {
    return {value_ + dynamic_viscosity.value_};
  }

  constexpr void operator+=(const DynamicViscosity& dynamic_viscosity) noexcept {
    value_ += dynamic_viscosity.value_;
  }

  DynamicViscosity operator-(const DynamicViscosity& dynamic_viscosity) const noexcept {
    return {value_ - dynamic_viscosity.value_};
  }

  constexpr void operator-=(const DynamicViscosity& dynamic_viscosity) noexcept {
    value_ -= dynamic_viscosity.value_;
  }

  KinematicViscosity operator/(const MassDensity& mass_density) const noexcept {
    return {*this, mass_density};
  }

  MassDensity operator/(const KinematicViscosity& kinematic_viscosity) const noexcept {
    return {*this, kinematic_viscosity};
  }

private:

  constexpr DynamicViscosity(double value) noexcept : DimensionalScalarQuantity<Unit::DynamicViscosity>(value) {}

};

constexpr MassDensity::MassDensity(const DynamicViscosity& dynamic_viscosity, const KinematicViscosity& kinematic_viscosity) noexcept : MassDensity(dynamic_viscosity.Value() / kinematic_viscosity.Value()) {}

constexpr KinematicViscosity::KinematicViscosity(const DynamicViscosity& dynamic_viscosity, const MassDensity& mass_density) noexcept : KinematicViscosity(dynamic_viscosity.Value() / mass_density.Value()) {}

DynamicViscosity KinematicViscosity::operator*(const MassDensity& mass_density) const noexcept {
  return {*this, mass_density};
}

DynamicViscosity MassDensity::operator*(const KinematicViscosity& kinematic_viscosity) const noexcept {
  return {kinematic_viscosity, *this};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::DynamicViscosity> {
  size_t operator()(const PhQ::DynamicViscosity& dynamic_viscosity) const {
    return hash<double>()(dynamic_viscosity.Value());
  }
};

} // namespace std
