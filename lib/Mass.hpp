// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Mass.hpp"

namespace PhQ {

// Forward declarations.
class Duration;
class Energy;
class Frequency;
class GasConstant;
class IsobaricHeatCapacity;
class IsochoricHeatCapacity;
class MassDensity;
class MassRate;
class Power;
class SpecificEnergy;
class SpecificGasConstant;
class SpecificIsobaricHeatCapacity;
class SpecificIsochoricHeatCapacity;
class SpecificPower;
class Volume;

class Mass : public DimensionalScalarQuantity<Unit::Mass> {

public:

  constexpr Mass() noexcept : DimensionalScalarQuantity<Unit::Mass>() {}

  constexpr Mass(double value, Unit::Mass unit) noexcept : DimensionalScalarQuantity<Unit::Mass>(value, unit) {}

  constexpr Mass(const MassDensity& mass_density, const Volume& volume) noexcept;

  constexpr Mass(const MassRate& mass_rate, const Duration& duration) noexcept;

  constexpr Mass(const MassRate& mass_rate, const Frequency& frequency) noexcept;

  constexpr Mass(const SpecificEnergy& specific_energy, const Energy& energy) noexcept;

  constexpr Mass(const SpecificPower& specific_power, const Power& power) noexcept;

  constexpr Mass(const SpecificGasConstant& specific_gas_constant, const GasConstant& gas_constant) noexcept;

  constexpr Mass(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept;

  constexpr Mass(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity, const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept;

  constexpr bool operator==(const Mass& mass) const noexcept {
    return value_ == mass.value_;
  }

  constexpr bool operator!=(const Mass& mass) const noexcept {
    return value_ != mass.value_;
  }

  constexpr bool operator<(const Mass& mass) const noexcept {
    return value_ < mass.value_;
  }

  constexpr bool operator<=(const Mass& mass) const noexcept {
    return value_ <= mass.value_;
  }

  constexpr bool operator>(const Mass& mass) const noexcept {
    return value_ > mass.value_;
  }

  constexpr bool operator>=(const Mass& mass) const noexcept {
    return value_ >= mass.value_;
  }

  constexpr Mass operator+(const Mass& mass) const noexcept {
    return {value_ + mass.value_};
  }

  constexpr void operator+=(const Mass& mass) noexcept {
    value_ += mass.value_;
  }

  constexpr Mass operator-(const Mass& mass) const noexcept {
    return {value_ - mass.value_};
  }

  constexpr void operator-=(const Mass& mass) noexcept {
    value_ -= mass.value_;
  }

  constexpr MassRate operator*(const Frequency& frequency) const noexcept;

  constexpr Energy operator*(const SpecificEnergy& specific_energy) const noexcept;

  constexpr Power operator*(const SpecificPower& specific_power) const noexcept;

  constexpr IsobaricHeatCapacity operator*(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const noexcept;

  constexpr IsochoricHeatCapacity operator*(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept;

  constexpr GasConstant operator*(const SpecificGasConstant& specific_gas_constant) const noexcept;

  constexpr MassDensity operator/(const Volume& volume) const noexcept;

  constexpr MassRate operator/(const Duration& duration) const noexcept;

  constexpr Duration operator/(const MassRate& mass_rate) const noexcept;

protected:

  constexpr Mass(double value) noexcept : DimensionalScalarQuantity<Unit::Mass>(value) {}

};

template <> constexpr bool sort(const Mass& mass_1, const Mass& mass_2) noexcept {
  return sort(mass_1.value(), mass_2.value());
}

} // namespace PhQ
