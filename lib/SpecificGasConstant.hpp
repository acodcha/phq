// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "GasConstant.hpp"
#include "SpecificIsobaricHeatCapacity.hpp"

namespace PhQ {

class SpecificGasConstant : public DimensionalScalarQuantity<Unit::SpecificHeatCapacity> {

public:

  constexpr SpecificGasConstant() noexcept : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>() {}

  constexpr SpecificGasConstant(double value, Unit::SpecificHeatCapacity unit) noexcept : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value, unit) {}

  constexpr bool operator==(const SpecificGasConstant& specific_gas_constant) const noexcept {
    return value_ == specific_gas_constant.value_;
  }

  constexpr bool operator!=(const SpecificGasConstant& specific_gas_constant) const noexcept {
    return value_ != specific_gas_constant.value_;
  }

  constexpr bool operator<(const SpecificGasConstant& specific_gas_constant) const noexcept {
    return value_ < specific_gas_constant.value_;
  }

  constexpr bool operator<=(const SpecificGasConstant& specific_gas_constant) const noexcept {
    return value_ <= specific_gas_constant.value_;
  }

  constexpr bool operator>(const SpecificGasConstant& specific_gas_constant) const noexcept {
    return value_ > specific_gas_constant.value_;
  }

  constexpr bool operator>=(const SpecificGasConstant& specific_gas_constant) const noexcept {
    return value_ >= specific_gas_constant.value_;
  }

  constexpr SpecificGasConstant operator+(const SpecificGasConstant& specific_gas_constant) const noexcept {
    return {value_ + specific_gas_constant.value_};
  }

  constexpr SpecificIsobaricHeatCapacity operator+(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept {
    return {value_ + specific_isochoric_heat_capacity.value_};
  }

  constexpr void operator+=(const SpecificGasConstant& specific_gas_constant) noexcept {
    value_ += specific_gas_constant.value_;
  }

  constexpr SpecificGasConstant operator-(const SpecificGasConstant& specific_gas_constant) const noexcept {
    return {value_ - specific_gas_constant.value_};
  }

  constexpr void operator-=(const SpecificGasConstant& specific_gas_constant) noexcept {
    value_ -= specific_gas_constant.value_;
  }

  constexpr GasConstant operator*(const Mass& mass) const noexcept {
    return {value_ * mass.value_};
  }

protected:

  constexpr SpecificGasConstant(double value) noexcept : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value) {}

  friend class GasConstant;
  friend class Mass;
  friend class SpecificHeatRatio;
  friend class SpecificIsobaricHeatCapacity;
  friend class SpecificIsochoricHeatCapacity;

};

template <> constexpr bool sort(const SpecificGasConstant& specific_gas_constant_1, const SpecificGasConstant& specific_gas_constant_2) noexcept {
  return specific_gas_constant_1.value() < specific_gas_constant_2.value();
}

constexpr GasConstant Mass::operator*(const SpecificGasConstant& specific_gas_constant) const noexcept {
  return {value_ * specific_gas_constant.value_};
}

SpecificGasConstant GasConstant::operator/(const Mass& mass) const {
  if (mass.value_ != 0.0) {
    return {value_ / mass.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + mass.print() + "."};
  }
}

constexpr SpecificIsobaricHeatCapacity SpecificIsochoricHeatCapacity::operator+(const SpecificGasConstant& specific_gas_constant) const noexcept {
  return {value_ + specific_gas_constant.value_};
}

constexpr SpecificGasConstant SpecificIsobaricHeatCapacity::operator-(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept {
  return {value_ - specific_isochoric_heat_capacity.value_};
}

} // namespace PhQ
