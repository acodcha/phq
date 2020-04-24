// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/HeatCapacity.hpp"

namespace PhQ {

// Forward declarations.
class Mass;
class SpecificIsobaricHeatCapacity;

class IsobaricHeatCapacity : public DimensionalScalarQuantity<Unit::HeatCapacity> {

public:

  constexpr IsobaricHeatCapacity() noexcept : DimensionalScalarQuantity<Unit::HeatCapacity>() {}

  constexpr IsobaricHeatCapacity(double value, Unit::HeatCapacity unit) noexcept : DimensionalScalarQuantity<Unit::HeatCapacity>(value, unit) {}

  constexpr bool operator==(const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return value_ == isobaric_heat_capacity.value_;
  }

  constexpr bool operator!=(const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return value_ != isobaric_heat_capacity.value_;
  }

  constexpr bool operator<(const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return value_ < isobaric_heat_capacity.value_;
  }

  constexpr bool operator<=(const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return value_ <= isobaric_heat_capacity.value_;
  }

  constexpr bool operator>(const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return value_ > isobaric_heat_capacity.value_;
  }

  constexpr bool operator>=(const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return value_ >= isobaric_heat_capacity.value_;
  }

  IsobaricHeatCapacity operator+(const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return {value_ + isobaric_heat_capacity.value_};
  }

  constexpr void operator+=(const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept {
    value_ += isobaric_heat_capacity.value_;
  }

  IsobaricHeatCapacity operator-(const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return {value_ - isobaric_heat_capacity.value_};
  }

  constexpr void operator-=(const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept {
    value_ -= isobaric_heat_capacity.value_;
  }

  SpecificIsobaricHeatCapacity operator/(const Mass& mass) const;

protected:

  constexpr IsobaricHeatCapacity(double value) noexcept : DimensionalScalarQuantity<Unit::HeatCapacity>(value) {}

  friend class Mass;
  friend class SpecificIsobaricHeatCapacity;

};

template <> constexpr bool sort(const IsobaricHeatCapacity& isobaric_heat_capacity_1, const IsobaricHeatCapacity& isobaric_heat_capacity_2) noexcept {
  return isobaric_heat_capacity_1.value() < isobaric_heat_capacity_2.value();
}

} // namespace PhQ
