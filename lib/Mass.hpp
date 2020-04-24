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
class IsobaricHeatCapacity;
class IsochoricHeatCapacity;
class MassDensity;
class MassRate;
class Power;
class SpecificEnergy;
class SpecificIsobaricHeatCapacity;
class SpecificIsochoricHeatCapacity;
class SpecificPower;
class Volume;

class Mass : public DimensionalScalarQuantity<Unit::Mass> {

public:

  constexpr Mass() noexcept : DimensionalScalarQuantity<Unit::Mass>() {}

  constexpr Mass(double value, Unit::Mass unit) noexcept : DimensionalScalarQuantity<Unit::Mass>(value, unit) {}

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

  Mass operator+(const Mass& mass) const noexcept {
    return {value_ + mass.value_};
  }

  constexpr void operator+=(const Mass& mass) noexcept {
    value_ += mass.value_;
  }

  Mass operator-(const Mass& mass) const noexcept {
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

  MassDensity operator/(const Volume& volume) const;

  MassRate operator/(const Duration& duration) const;

protected:

  constexpr Mass(double value) noexcept : DimensionalScalarQuantity<Unit::Mass>(value) {}

  friend class Duration;
  friend class Energy;
  friend class Frequency;
  friend class IsobaricHeatCapacity;
  friend class IsochoricHeatCapacity;
  friend class MassDensity;
  friend class MassRate;
  friend class Power;
  friend class SpecificEnergy;
  friend class SpecificIsobaricHeatCapacity;
  friend class SpecificIsochoricHeatCapacity;
  friend class SpecificPower;
  friend class Volume;

};

template <> constexpr bool sort(const Mass& mass_1, const Mass& mass_2) noexcept {
  return mass_1.value() < mass_2.value();
}

} // namespace PhQ
