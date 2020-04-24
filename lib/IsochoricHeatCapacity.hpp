// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/HeatCapacity.hpp"

namespace PhQ {

class IsochoricHeatCapacity : public DimensionalScalarQuantity<Unit::HeatCapacity> {

public:

  constexpr IsochoricHeatCapacity() noexcept : DimensionalScalarQuantity<Unit::HeatCapacity>() {}

  constexpr IsochoricHeatCapacity(double value, Unit::HeatCapacity unit) noexcept : DimensionalScalarQuantity<Unit::HeatCapacity>(value, unit) {}

  constexpr bool operator==(const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
    return value_ == isochoric_heat_capacity.value_;
  }

  constexpr bool operator!=(const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
    return value_ != isochoric_heat_capacity.value_;
  }

  constexpr bool operator<(const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
    return value_ < isochoric_heat_capacity.value_;
  }

  constexpr bool operator<=(const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
    return value_ <= isochoric_heat_capacity.value_;
  }

  constexpr bool operator>(const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
    return value_ > isochoric_heat_capacity.value_;
  }

  constexpr bool operator>=(const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
    return value_ >= isochoric_heat_capacity.value_;
  }

  IsochoricHeatCapacity operator+(const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
    return {value_ + isochoric_heat_capacity.value_};
  }

  constexpr void operator+=(const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept {
    value_ += isochoric_heat_capacity.value_;
  }

  IsochoricHeatCapacity operator-(const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
    return {value_ - isochoric_heat_capacity.value_};
  }

  constexpr void operator-=(const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept {
    value_ -= isochoric_heat_capacity.value_;
  }

protected:

  constexpr IsochoricHeatCapacity(double value) noexcept : DimensionalScalarQuantity<Unit::HeatCapacity>(value) {}

};

template <> constexpr bool sort(const IsochoricHeatCapacity& isochoric_heat_capacity_1, const IsochoricHeatCapacity& isochoric_heat_capacity_2) noexcept {
  return isochoric_heat_capacity_1.value() < isochoric_heat_capacity_2.value();
}

} // namespace PhQ
