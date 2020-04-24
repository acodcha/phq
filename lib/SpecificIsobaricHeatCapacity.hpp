// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "IsobaricHeatCapacity.hpp"
#include "SpecificIsochoricHeatCapacity.hpp"

namespace PhQ {

class SpecificIsobaricHeatCapacity : public DimensionalScalarQuantity<Unit::SpecificHeatCapacity> {

public:

  constexpr SpecificIsobaricHeatCapacity() noexcept : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>() {}

  constexpr SpecificIsobaricHeatCapacity(double value, Unit::SpecificHeatCapacity unit) noexcept : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value, unit) {}

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

  constexpr SpecificIsobaricHeatCapacity operator+(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const noexcept {
    return {value_ + specific_isobaric_heat_capacity.value_};
  }

  constexpr void operator+=(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept {
    value_ += specific_isobaric_heat_capacity.value_;
  }

  constexpr SpecificIsobaricHeatCapacity operator-(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const noexcept {
    return {value_ - specific_isobaric_heat_capacity.value_};
  }

  constexpr SpecificGasConstant operator-(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept;

  constexpr void operator-=(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept {
    value_ -= specific_isobaric_heat_capacity.value_;
  }

  constexpr IsobaricHeatCapacity operator*(const Mass& mass) const noexcept {
    return {value_ * mass.value_};
  }

  SpecificHeatRatio operator/(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const {
    if (specific_isochoric_heat_capacity.value_ != 0.0) {
      return {value_ / specific_isochoric_heat_capacity.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + specific_isochoric_heat_capacity.print() + "."};
    }
  }

protected:

  constexpr SpecificIsobaricHeatCapacity(double value) noexcept : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value) {}

  friend class IsobaricHeatCapacity;
  friend class Mass;
  friend class SpecificGasConstant;
  friend class SpecificHeatRatio;
  friend class SpecificIsochoricHeatCapacity;

};

template <> constexpr bool sort(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity_1, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity_2) noexcept {
  return specific_isobaric_heat_capacity_1.value() < specific_isobaric_heat_capacity_2.value();
}

constexpr IsobaricHeatCapacity Mass::operator*(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const noexcept {
  return {value_ * specific_isobaric_heat_capacity.value_};
}

SpecificIsobaricHeatCapacity IsobaricHeatCapacity::operator/(const Mass& mass) const {
  if (mass.value_ != 0.0) {
    return {value_ / mass.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + mass.print() + "."};
  }
}

} // namespace PhQ
