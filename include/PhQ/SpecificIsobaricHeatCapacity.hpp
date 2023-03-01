// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "IsobaricHeatCapacity.hpp"
#include "SpecificIsochoricHeatCapacity.hpp"

namespace PhQ {

// Forward declarations.
class DynamicViscosity;
class MassDensity;
class PrandtlNumber;
class ThermalConductivityScalar;
class ThermalDiffusivity;

class SpecificIsobaricHeatCapacity : public DimensionalScalarQuantity<Unit::SpecificHeatCapacity> {

public:

  constexpr SpecificIsobaricHeatCapacity() noexcept : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>() {}

  SpecificIsobaricHeatCapacity(double value, Unit::SpecificHeatCapacity unit) noexcept : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value, unit) {}

  constexpr SpecificIsobaricHeatCapacity(const SpecificGasConstant& specific_gas_constant, const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) noexcept;

  constexpr SpecificIsobaricHeatCapacity(const SpecificGasConstant& specific_gas_constant, const SpecificHeatRatio& specific_heat_ratio) noexcept;

  constexpr SpecificIsobaricHeatCapacity(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity, const SpecificHeatRatio& specific_heat_ratio) noexcept : SpecificIsobaricHeatCapacity(specific_isochoric_heat_capacity.Value() * specific_heat_ratio.Value()) {}

  constexpr SpecificIsobaricHeatCapacity(const IsobaricHeatCapacity& isobaric_heat_capacity, const Mass& mass) noexcept : SpecificIsobaricHeatCapacity(isobaric_heat_capacity.Value() / mass.Value()) {}

  constexpr SpecificIsobaricHeatCapacity(const ThermalDiffusivity& thermal_diffusivity, const ThermalConductivityScalar& thermal_conductivity_scalar, const MassDensity& mass_density) noexcept;

  constexpr SpecificIsobaricHeatCapacity(const PrandtlNumber& prandtl_number, const ThermalConductivityScalar& thermal_conductivity_scalar, const DynamicViscosity& dynamic_viscosity) noexcept;

  constexpr bool operator==(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const noexcept {
    return value_ == specific_isobaric_heat_capacity.value_;
  }

  constexpr bool operator!=(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const noexcept {
    return value_ != specific_isobaric_heat_capacity.value_;
  }

  constexpr bool operator<(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const noexcept {
    return value_ < specific_isobaric_heat_capacity.value_;
  }

  constexpr bool operator<=(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const noexcept {
    return value_ <= specific_isobaric_heat_capacity.value_;
  }

  constexpr bool operator>(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const noexcept {
    return value_ > specific_isobaric_heat_capacity.value_;
  }

  constexpr bool operator>=(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const noexcept {
    return value_ >= specific_isobaric_heat_capacity.value_;
  }

  SpecificIsobaricHeatCapacity operator+(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const noexcept {
    return {value_ + specific_isobaric_heat_capacity.value_};
  }

  constexpr void operator+=(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept {
    value_ += specific_isobaric_heat_capacity.value_;
  }

  SpecificIsobaricHeatCapacity operator-(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const noexcept {
    return {value_ - specific_isobaric_heat_capacity.value_};
  }

  constexpr SpecificGasConstant operator-(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept;

  constexpr SpecificIsochoricHeatCapacity operator-(const SpecificGasConstant& specific_gas_constant) const noexcept;

  constexpr void operator-=(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept {
    value_ -= specific_isobaric_heat_capacity.value_;
  }

  IsobaricHeatCapacity operator*(const Mass& mass) const noexcept {
    return {*this, mass};
  }

  SpecificHeatRatio operator/(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept {
    return {*this, specific_isochoric_heat_capacity};
  }

  SpecificIsochoricHeatCapacity operator/(const SpecificHeatRatio& specific_heat_ratio) const noexcept {
    return {*this, specific_heat_ratio};
  }

protected:

  constexpr SpecificIsobaricHeatCapacity(double value) noexcept : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value) {}

};

constexpr SpecificHeatRatio::SpecificHeatRatio(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) noexcept : SpecificHeatRatio(specific_isobaric_heat_capacity.Value() / specific_isochoric_heat_capacity.Value()) {}

constexpr Mass::Mass(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept : Mass(isobaric_heat_capacity.Value() / specific_isobaric_heat_capacity.Value()) {}

constexpr IsobaricHeatCapacity::IsobaricHeatCapacity(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const Mass& mass) noexcept : IsobaricHeatCapacity(specific_isobaric_heat_capacity.Value() * mass.Value()) {}

constexpr SpecificIsochoricHeatCapacity::SpecificIsochoricHeatCapacity(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const SpecificHeatRatio& specific_heat_ratio) noexcept : SpecificIsochoricHeatCapacity(specific_isobaric_heat_capacity.Value() / specific_heat_ratio.Value()) {}

constexpr IsobaricHeatCapacity Mass::operator*(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const noexcept {
  return {specific_isobaric_heat_capacity, *this};
}

constexpr SpecificIsobaricHeatCapacity SpecificHeatRatio::operator*(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept {
  return {specific_isochoric_heat_capacity, *this};
}

constexpr SpecificIsobaricHeatCapacity IsobaricHeatCapacity::operator/(const Mass& mass) const noexcept {
  return {*this, mass};
}

constexpr Mass IsobaricHeatCapacity::operator/(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const noexcept {
  return {specific_isobaric_heat_capacity, *this};
}

constexpr SpecificIsobaricHeatCapacity SpecificIsochoricHeatCapacity::operator*(const SpecificHeatRatio& specific_heat_ratio) const noexcept {
  return {*this, specific_heat_ratio};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::SpecificIsobaricHeatCapacity> {
  size_t operator()(const PhQ::SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const {
    return hash<double>()(specific_isobaric_heat_capacity.Value());
  }
};

} // namespace std
