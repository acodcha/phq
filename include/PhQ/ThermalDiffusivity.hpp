// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "MassDensity.hpp"
#include "SpecificIsobaricHeatCapacity.hpp"
#include "ThermalConductivityScalar.hpp"
#include "Unit/Diffusivity.hpp"

namespace PhQ {

// Forward declaration.
class PrandtlNumber;

class ThermalDiffusivity : public DimensionalScalarQuantity<Unit::Diffusivity> {

public:

  constexpr ThermalDiffusivity() noexcept : DimensionalScalarQuantity<Unit::Diffusivity>() {}

  constexpr ThermalDiffusivity(double value, Unit::Diffusivity unit) noexcept : DimensionalScalarQuantity<Unit::Diffusivity>(value, unit) {}

  constexpr ThermalDiffusivity(const ThermalConductivityScalar& thermal_conductivity_scalar, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const MassDensity& mass_density) noexcept : ThermalDiffusivity(thermal_conductivity_scalar.value() / (mass_density.value() * specific_isobaric_heat_capacity.value())) {}

  constexpr ThermalDiffusivity(const PrandtlNumber& prandtl_number, const KinematicViscosity& kinematic_viscosity) noexcept;

  constexpr bool operator==(const ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return value_ == thermal_diffusivity.value_;
  }

  constexpr bool operator!=(const ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return value_ != thermal_diffusivity.value_;
  }

  constexpr bool operator<(const ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return value_ < thermal_diffusivity.value_;
  }

  constexpr bool operator<=(const ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return value_ <= thermal_diffusivity.value_;
  }

  constexpr bool operator>(const ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return value_ > thermal_diffusivity.value_;
  }

  constexpr bool operator>=(const ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return value_ >= thermal_diffusivity.value_;
  }

  constexpr ThermalDiffusivity operator+(const ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return {value_ + thermal_diffusivity.value_};
  }

  constexpr void operator+=(const ThermalDiffusivity& thermal_diffusivity) noexcept {
    value_ += thermal_diffusivity.value_;
  }

  constexpr ThermalDiffusivity operator-(const ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return {value_ - thermal_diffusivity.value_};
  }

  constexpr void operator-=(const ThermalDiffusivity& thermal_diffusivity) noexcept {
    value_ -= thermal_diffusivity.value_;
  }

protected:

  constexpr ThermalDiffusivity(double value) noexcept : DimensionalScalarQuantity<Unit::Diffusivity>(value) {}

};

template <> constexpr bool sort(const ThermalDiffusivity& thermal_diffusivity_1, const ThermalDiffusivity& thermal_diffusivity_2) noexcept {
  return sort(thermal_diffusivity_1.value(), thermal_diffusivity_2.value());
}

constexpr ThermalConductivityScalar::ThermalConductivityScalar(const ThermalDiffusivity& thermal_diffusivity, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const MassDensity& mass_density) noexcept : ThermalConductivityScalar(thermal_diffusivity.value() * specific_isobaric_heat_capacity.value() * mass_density.value()) {}

constexpr MassDensity::MassDensity(const ThermalDiffusivity& thermal_diffusivity, const ThermalConductivityScalar& thermal_conductivity_scalar, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept : MassDensity(thermal_conductivity_scalar.value() / (thermal_diffusivity.value() * specific_isobaric_heat_capacity.value())) {}

constexpr SpecificIsobaricHeatCapacity::SpecificIsobaricHeatCapacity(const ThermalDiffusivity& thermal_diffusivity, const ThermalConductivityScalar& thermal_conductivity_scalar, const MassDensity& mass_density) noexcept : SpecificIsobaricHeatCapacity(thermal_conductivity_scalar.value() / (thermal_diffusivity.value() * mass_density.value())) {}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::ThermalDiffusivity> {
  size_t operator()(const PhQ::ThermalDiffusivity& thermal_diffusivity) const {
    return hash<double>()(thermal_diffusivity.value());
  }
};

} // namespace std
