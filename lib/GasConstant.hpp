// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "IsobaricHeatCapacity.hpp"

namespace PhQ {

// Forward declaration.
class SpecificGasConstant;

class GasConstant : public DimensionalScalarQuantity<Unit::HeatCapacity> {

public:

  constexpr GasConstant() noexcept : DimensionalScalarQuantity<Unit::HeatCapacity>() {}

  constexpr GasConstant(double value, Unit::HeatCapacity unit) noexcept : DimensionalScalarQuantity<Unit::HeatCapacity>(value, unit) {}

  constexpr bool operator==(const GasConstant& gas_constant) const noexcept {
    return value_ == gas_constant.value_;
  }

  constexpr bool operator!=(const GasConstant& gas_constant) const noexcept {
    return value_ != gas_constant.value_;
  }

  constexpr bool operator<(const GasConstant& gas_constant) const noexcept {
    return value_ < gas_constant.value_;
  }

  constexpr bool operator<=(const GasConstant& gas_constant) const noexcept {
    return value_ <= gas_constant.value_;
  }

  constexpr bool operator>(const GasConstant& gas_constant) const noexcept {
    return value_ > gas_constant.value_;
  }

  constexpr bool operator>=(const GasConstant& gas_constant) const noexcept {
    return value_ >= gas_constant.value_;
  }

  constexpr GasConstant operator+(const GasConstant& gas_constant) const noexcept {
    return {value_ + gas_constant.value_};
  }

  constexpr IsobaricHeatCapacity operator+(const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
    return {value_ + isochoric_heat_capacity.value_};
  }

  constexpr void operator+=(const GasConstant& gas_constant) noexcept {
    value_ += gas_constant.value_;
  }

  constexpr GasConstant operator-(const GasConstant& gas_constant) const noexcept {
    return {value_ - gas_constant.value_};
  }

  constexpr void operator-=(const GasConstant& gas_constant) noexcept {
    value_ -= gas_constant.value_;
  }

  SpecificGasConstant operator/(const Mass& mass) const;

protected:

  constexpr GasConstant(double value) noexcept : DimensionalScalarQuantity<Unit::HeatCapacity>(value) {}

  friend class IsobaricHeatCapacity;
  friend class IsochoricHeatCapacity;
  friend class Mass;
  friend class SpecificHeatRatio;
  friend class SpecificGasConstant;

};

template <> constexpr bool sort(const GasConstant& gas_constant_1, const GasConstant& gas_constant_2) noexcept {
  return gas_constant_1.value() < gas_constant_2.value();
}

constexpr IsobaricHeatCapacity IsochoricHeatCapacity::operator+(const GasConstant& gas_constant) const noexcept {
  return {value_ + gas_constant.value_};
}

constexpr GasConstant IsobaricHeatCapacity::operator-(const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
  return {value_ - isochoric_heat_capacity.value_};
}

constexpr IsochoricHeatCapacity IsobaricHeatCapacity::operator-(const GasConstant& gas_constant) const noexcept {
  return {value_ - gas_constant.value_};
}

} // namespace PhQ
