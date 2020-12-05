// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/ThermalConductivity.hpp"

namespace PhQ {

// Forward declarations.
class DynamicViscosity;
class MassDensity;
class PrandtlNumber;
class SpecificIsobaricHeatCapacity;
class ThermalDiffusivity;

class ThermalConductivityScalar : public DimensionalScalarQuantity<Unit::ThermalConductivity> {

public:

  constexpr ThermalConductivityScalar() noexcept : DimensionalScalarQuantity<Unit::ThermalConductivity>() {}

  constexpr ThermalConductivityScalar(double value, Unit::ThermalConductivity unit) noexcept : DimensionalScalarQuantity<Unit::ThermalConductivity>(value, unit) {}

  constexpr ThermalConductivityScalar(const ThermalDiffusivity& thermal_diffusivity, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const MassDensity& mass_density) noexcept;

  constexpr ThermalConductivityScalar(const PrandtlNumber& prandtl_number, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const DynamicViscosity& dynamic_viscosity) noexcept;

  constexpr bool operator==(const ThermalConductivityScalar& thermal_conductivity_scalar) const noexcept {
    return value_ == thermal_conductivity_scalar.value_;
  }

  constexpr bool operator!=(const ThermalConductivityScalar& thermal_conductivity_scalar) const noexcept {
    return value_ != thermal_conductivity_scalar.value_;
  }

  constexpr bool operator<(const ThermalConductivityScalar& thermal_conductivity_scalar) const noexcept {
    return value_ < thermal_conductivity_scalar.value_;
  }

  constexpr bool operator<=(const ThermalConductivityScalar& thermal_conductivity_scalar) const noexcept {
    return value_ <= thermal_conductivity_scalar.value_;
  }

  constexpr bool operator>(const ThermalConductivityScalar& thermal_conductivity_scalar) const noexcept {
    return value_ > thermal_conductivity_scalar.value_;
  }

  constexpr bool operator>=(const ThermalConductivityScalar& thermal_conductivity_scalar) const noexcept {
    return value_ >= thermal_conductivity_scalar.value_;
  }

  constexpr ThermalConductivityScalar operator+(const ThermalConductivityScalar& thermal_conductivity_scalar) const noexcept {
    return {value_ + thermal_conductivity_scalar.value_};
  }

  constexpr void operator+=(const ThermalConductivityScalar& thermal_conductivity_scalar) noexcept {
    value_ += thermal_conductivity_scalar.value_;
  }

  constexpr ThermalConductivityScalar operator-(const ThermalConductivityScalar& thermal_conductivity_scalar) const noexcept {
    return {value_ - thermal_conductivity_scalar.value_};
  }

  constexpr void operator-=(const ThermalConductivityScalar& thermal_conductivity_scalar) noexcept {
    value_ -= thermal_conductivity_scalar.value_;
  }

protected:

  constexpr ThermalConductivityScalar(double value) noexcept : DimensionalScalarQuantity<Unit::ThermalConductivity>(value) {}

};

template <> constexpr bool sort(const ThermalConductivityScalar& thermal_conductivity_scalar_1, const ThermalConductivityScalar& thermal_conductivity_scalar_2) noexcept {
  return sort(thermal_conductivity_scalar_1.value(), thermal_conductivity_scalar_2.value());
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::ThermalConductivityScalar> {
  size_t operator()(const PhQ::ThermalConductivityScalar& thermal_conductivity_scalar) const {
    return hash<double>()(thermal_conductivity_scalar.value());
  }
};

} // namespace std
