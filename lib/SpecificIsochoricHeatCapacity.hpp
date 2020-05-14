// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Mass.hpp"
#include "IsochoricHeatCapacity.hpp"
#include "Unit/SpecificHeatCapacity.hpp"

namespace PhQ {

class SpecificIsochoricHeatCapacity : public DimensionalScalarQuantity<Unit::SpecificHeatCapacity> {

public:

  constexpr SpecificIsochoricHeatCapacity() noexcept : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>() {}

  constexpr SpecificIsochoricHeatCapacity(double value, Unit::SpecificHeatCapacity unit) noexcept : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value, unit) {}

  constexpr bool operator==(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept {
    return value_ == specific_isochoric_heat_capacity.value_;
  }

  constexpr bool operator!=(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept {
    return value_ != specific_isochoric_heat_capacity.value_;
  }

  constexpr bool operator<(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept {
    return value_ < specific_isochoric_heat_capacity.value_;
  }

  constexpr bool operator<=(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept {
    return value_ <= specific_isochoric_heat_capacity.value_;
  }

  constexpr bool operator>(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept {
    return value_ > specific_isochoric_heat_capacity.value_;
  }

  constexpr bool operator>=(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept {
    return value_ >= specific_isochoric_heat_capacity.value_;
  }

  constexpr SpecificIsochoricHeatCapacity operator+(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept {
    return {value_ + specific_isochoric_heat_capacity.value_};
  }

  constexpr SpecificIsobaricHeatCapacity operator+(const SpecificGasConstant& specific_gas_constant) const noexcept;

  constexpr void operator+=(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) noexcept {
    value_ += specific_isochoric_heat_capacity.value_;
  }

  constexpr SpecificIsochoricHeatCapacity operator-(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept {
    return {value_ - specific_isochoric_heat_capacity.value_};
  }

  constexpr void operator-=(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) noexcept {
    value_ -= specific_isochoric_heat_capacity.value_;
  }

  constexpr IsochoricHeatCapacity operator*(const Mass& mass) const noexcept {
    return {value_ * mass.value_};
  }

  constexpr SpecificIsobaricHeatCapacity operator*(const SpecificHeatRatio& specific_heat_ratio) const noexcept;

protected:

  constexpr SpecificIsochoricHeatCapacity(double value) noexcept : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value) {}

  friend class IsochoricHeatCapacity;
  friend class Mass;
  friend class SpecificGasConstant;
  friend class SpecificHeatRatio;
  friend class SpecificIsobaricHeatCapacity;


};

template <> constexpr bool sort(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity_1, const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity_2) noexcept {
  return specific_isochoric_heat_capacity_1.value() < specific_isochoric_heat_capacity_2.value();
}

constexpr IsochoricHeatCapacity Mass::operator*(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept {
  return {value_ * specific_isochoric_heat_capacity.value_};
}

constexpr SpecificIsochoricHeatCapacity IsochoricHeatCapacity::operator/(const Mass& mass) const noexcept {
  return {value_ / mass.value_};
}

} // namespace PhQ
