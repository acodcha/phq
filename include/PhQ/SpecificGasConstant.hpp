// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "GasConstant.hpp"
#include "SpecificIsobaricHeatCapacity.hpp"

namespace PhQ {

class SpecificGasConstant : public DimensionalScalarQuantity<Unit::SpecificHeatCapacity> {

public:

  constexpr SpecificGasConstant() noexcept : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>() {}

  SpecificGasConstant(double value, Unit::SpecificHeatCapacity unit) noexcept : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value, unit) {}

  constexpr SpecificGasConstant(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) noexcept : SpecificGasConstant(specific_isobaric_heat_capacity.Value() - specific_isochoric_heat_capacity.Value()) {}

  constexpr SpecificGasConstant(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const SpecificHeatRatio& specific_heat_ratio) noexcept : SpecificGasConstant(specific_isobaric_heat_capacity.Value() * (1.0 - 1.0 / specific_heat_ratio.Value())) {}

  constexpr SpecificGasConstant(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity, const SpecificHeatRatio& specific_heat_ratio) noexcept : SpecificGasConstant(specific_isochoric_heat_capacity.Value() * (specific_heat_ratio.Value() - 1.0)) {}

  constexpr SpecificGasConstant(const GasConstant& gas_constant, const Mass& mass) noexcept : SpecificGasConstant(gas_constant.Value() / mass.Value()) {}

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

  SpecificGasConstant operator+(const SpecificGasConstant& specific_gas_constant) const noexcept {
    return {value_ + specific_gas_constant.value_};
  }

  SpecificIsobaricHeatCapacity operator+(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept {
    return {*this, specific_isochoric_heat_capacity};
  }

  constexpr void operator+=(const SpecificGasConstant& specific_gas_constant) noexcept {
    value_ += specific_gas_constant.value_;
  }

  SpecificGasConstant operator-(const SpecificGasConstant& specific_gas_constant) const noexcept {
    return {value_ - specific_gas_constant.value_};
  }

  constexpr void operator-=(const SpecificGasConstant& specific_gas_constant) noexcept {
    value_ -= specific_gas_constant.value_;
  }

  GasConstant operator*(const Mass& mass) const noexcept {
    return {*this, mass};
  }

protected:

  constexpr SpecificGasConstant(double value) noexcept : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value) {}

};

constexpr SpecificHeatRatio::SpecificHeatRatio(const SpecificGasConstant& specific_gas_constant, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept : SpecificHeatRatio(specific_isobaric_heat_capacity.Value() / (specific_isobaric_heat_capacity.Value() - specific_gas_constant.Value())) {}

constexpr SpecificHeatRatio::SpecificHeatRatio(const SpecificGasConstant& specific_gas_constant, const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) noexcept : SpecificHeatRatio(specific_gas_constant.Value() / specific_isochoric_heat_capacity.Value() + 1.0) {}

constexpr Mass::Mass(const SpecificGasConstant& specific_gas_constant, const GasConstant& gas_constant) noexcept : Mass(gas_constant.Value() / specific_gas_constant.Value()) {}

constexpr GasConstant::GasConstant(const SpecificGasConstant& specific_gas_constant, const Mass& mass) noexcept : GasConstant(specific_gas_constant.Value() * mass.Value()) {}

constexpr SpecificIsochoricHeatCapacity::SpecificIsochoricHeatCapacity(const SpecificGasConstant& specific_gas_constant, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept : SpecificIsochoricHeatCapacity(specific_isobaric_heat_capacity.Value() - specific_gas_constant.Value()) {}

constexpr SpecificIsochoricHeatCapacity::SpecificIsochoricHeatCapacity(const SpecificGasConstant& specific_gas_constant, const SpecificHeatRatio& specific_heat_ratio) noexcept : SpecificIsochoricHeatCapacity(specific_gas_constant.Value() / (specific_heat_ratio.Value() - 1.0)) {}

constexpr SpecificIsobaricHeatCapacity::SpecificIsobaricHeatCapacity(const SpecificGasConstant& specific_gas_constant, const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) noexcept : SpecificIsobaricHeatCapacity(specific_gas_constant.Value() + specific_isochoric_heat_capacity.Value()) {}

constexpr SpecificIsobaricHeatCapacity::SpecificIsobaricHeatCapacity(const SpecificGasConstant& specific_gas_constant, const SpecificHeatRatio& specific_heat_ratio) noexcept : SpecificIsobaricHeatCapacity(specific_gas_constant.Value() * specific_heat_ratio.Value() / (specific_heat_ratio.Value() - 1.0)) {}

constexpr GasConstant Mass::operator*(const SpecificGasConstant& specific_gas_constant) const noexcept {
  return {specific_gas_constant, *this};
}

constexpr SpecificGasConstant GasConstant::operator/(const Mass& mass) const noexcept {
  return {*this, mass};
}

constexpr Mass GasConstant::operator/(const SpecificGasConstant& specific_gas_constant) const noexcept {
  return {specific_gas_constant, *this};
}

constexpr SpecificIsobaricHeatCapacity SpecificIsochoricHeatCapacity::operator+(const SpecificGasConstant& specific_gas_constant) const noexcept {
  return {specific_gas_constant, *this};
}

constexpr SpecificGasConstant SpecificIsobaricHeatCapacity::operator-(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept {
  return {*this, specific_isochoric_heat_capacity};
}

constexpr SpecificIsochoricHeatCapacity SpecificIsobaricHeatCapacity::operator-(const SpecificGasConstant& specific_gas_constant) const noexcept {
  return {specific_gas_constant, *this};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::SpecificGasConstant> {
  size_t operator()(const PhQ::SpecificGasConstant& specific_gas_constant) const {
    return hash<double>()(specific_gas_constant.Value());
  }
};

} // namespace std
