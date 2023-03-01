// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "DynamicViscosity.hpp"
#include "ThermalDiffusivity.hpp"
#include "Quantity/DimensionlessScalar.hpp"

namespace PhQ {

class PrandtlNumber : public DimensionlessScalarQuantity {

public:

  constexpr PrandtlNumber() noexcept : DimensionlessScalarQuantity() {}

  constexpr PrandtlNumber(double value) noexcept : DimensionlessScalarQuantity(value) {}

  constexpr PrandtlNumber(const KinematicViscosity& kinematic_viscosity, const ThermalDiffusivity& thermal_diffusivity) noexcept : PrandtlNumber(kinematic_viscosity.Value() / thermal_diffusivity.Value()) {}

  constexpr PrandtlNumber(const DynamicViscosity& dynamic_viscosity, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const ThermalConductivityScalar& thermal_conductivity_scalar) noexcept : PrandtlNumber(dynamic_viscosity.Value() * specific_isobaric_heat_capacity.Value() / thermal_conductivity_scalar.Value()) {}

  PhQ::ThermalDiffusivity ThermalDiffusivity(const PhQ::KinematicViscosity& kinematic_viscosity) const noexcept {
    return {*this, kinematic_viscosity};
  }

  PhQ::ThermalConductivityScalar ThermalConductivityScalar(const PhQ::SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const PhQ::DynamicViscosity& dynamic_viscosity) const noexcept {
    return {*this, specific_isobaric_heat_capacity, dynamic_viscosity};
  }

  PhQ::SpecificIsobaricHeatCapacity SpecificIsobaricHeatCapacity(const PhQ::ThermalConductivityScalar& thermal_conductivity_scalar, const PhQ::DynamicViscosity& dynamic_viscosity) const noexcept {
    return {*this, thermal_conductivity_scalar, dynamic_viscosity};
  }

  PhQ::DynamicViscosity DynamicViscosity(const PhQ::ThermalConductivityScalar& thermal_conductivity_scalar, PhQ::SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const noexcept {
    return {*this, thermal_conductivity_scalar, specific_isobaric_heat_capacity};
  }

  PhQ::KinematicViscosity KinematicViscosity(const PhQ::ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return {*this, thermal_diffusivity};
  }

};

constexpr ThermalDiffusivity::ThermalDiffusivity(const PrandtlNumber& prandtl_number, const KinematicViscosity& kinematic_viscosity) noexcept : ThermalDiffusivity(kinematic_viscosity.Value() / prandtl_number.Value()) {}

constexpr ThermalConductivityScalar::ThermalConductivityScalar(const PrandtlNumber& prandtl_number, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const DynamicViscosity& dynamic_viscosity) noexcept : ThermalConductivityScalar(specific_isobaric_heat_capacity.Value() * dynamic_viscosity.Value() / prandtl_number.Value()) {}

constexpr SpecificIsobaricHeatCapacity::SpecificIsobaricHeatCapacity(const PrandtlNumber& prandtl_number, const ThermalConductivityScalar& thermal_conductivity_scalar, const DynamicViscosity& dynamic_viscosity) noexcept : SpecificIsobaricHeatCapacity(prandtl_number.Value() * thermal_conductivity_scalar.Value() / dynamic_viscosity.Value()) {}

constexpr DynamicViscosity::DynamicViscosity(const PrandtlNumber& prandtl_number, const ThermalConductivityScalar& thermal_conductivity_scalar, SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept : DynamicViscosity(prandtl_number.Value() * thermal_conductivity_scalar.Value() / specific_isobaric_heat_capacity.Value()) {}

constexpr KinematicViscosity::KinematicViscosity(const PrandtlNumber& prandtl_number, const ThermalDiffusivity& thermal_diffusivity) noexcept : KinematicViscosity(prandtl_number.Value() * thermal_diffusivity.Value()) {}

} // namespace PhQ

PhQ::PrandtlNumber operator+(double real, const PhQ::PrandtlNumber& prandtl_number) noexcept {
  return {real + prandtl_number.Value()};
}

PhQ::PrandtlNumber operator-(double real, const PhQ::PrandtlNumber& prandtl_number) noexcept {
  return {real - prandtl_number.Value()};
}

PhQ::PrandtlNumber operator*(double real, const PhQ::PrandtlNumber& prandtl_number) noexcept {
  return {real * prandtl_number.Value()};
}

constexpr double operator/(double real, const PhQ::PrandtlNumber& prandtl_number) noexcept {
  return real / prandtl_number.Value();
}

namespace std {

template <> struct hash<PhQ::PrandtlNumber> {
  size_t operator()(const PhQ::PrandtlNumber& prandtl_number) const {
    return hash<double>()(prandtl_number.Value());
  }
};

} // namespace std
