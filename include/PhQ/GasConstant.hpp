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

  constexpr GasConstant(const IsobaricHeatCapacity& isobaric_heat_capacity, const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept : GasConstant(isobaric_heat_capacity.value() - isochoric_heat_capacity.value()) {}

  constexpr GasConstant(const IsobaricHeatCapacity& isobaric_heat_capacity, const SpecificHeatRatio& specific_heat_ratio) noexcept : GasConstant(isobaric_heat_capacity.value() * (1.0 - 1.0 / specific_heat_ratio.value())) {}

  constexpr GasConstant(const IsochoricHeatCapacity& isochoric_heat_capacity, const SpecificHeatRatio& specific_heat_ratio) noexcept : GasConstant(isochoric_heat_capacity.value() * (specific_heat_ratio.value() - 1.0)) {}

  constexpr GasConstant(const SpecificGasConstant& specific_gas_constant, const Mass& mass) noexcept;

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
    return {*this, isochoric_heat_capacity};
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

  constexpr SpecificGasConstant operator/(const Mass& mass) const noexcept;

  constexpr Mass operator/(const SpecificGasConstant& specific_gas_constant) const noexcept;

protected:

  constexpr GasConstant(double value) noexcept : DimensionalScalarQuantity<Unit::HeatCapacity>(value) {}

};

template <> constexpr bool sort(const GasConstant& gas_constant_1, const GasConstant& gas_constant_2) noexcept {
  return sort(gas_constant_1.value(), gas_constant_2.value());
}

constexpr SpecificHeatRatio::SpecificHeatRatio(const GasConstant& gas_constant, const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept : SpecificHeatRatio(isobaric_heat_capacity.value() / (isobaric_heat_capacity.value() - gas_constant.value())) {}

constexpr SpecificHeatRatio::SpecificHeatRatio(const GasConstant& gas_constant, const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept : SpecificHeatRatio(gas_constant.value() / isochoric_heat_capacity.value() + 1.0) {}

constexpr IsochoricHeatCapacity::IsochoricHeatCapacity(const GasConstant& gas_constant, const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept : IsochoricHeatCapacity(isobaric_heat_capacity.value() - gas_constant.value()) {}

constexpr IsochoricHeatCapacity::IsochoricHeatCapacity(const GasConstant& gas_constant, const SpecificHeatRatio& specific_heat_ratio) noexcept : IsochoricHeatCapacity(gas_constant.value() / (specific_heat_ratio.value() - 1.0)) {}

constexpr IsobaricHeatCapacity::IsobaricHeatCapacity(const GasConstant& gas_constant, const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept : IsobaricHeatCapacity(gas_constant.value() + isochoric_heat_capacity.value()) {}

constexpr IsobaricHeatCapacity::IsobaricHeatCapacity(const GasConstant& gas_constant, const SpecificHeatRatio& specific_heat_ratio) noexcept : IsobaricHeatCapacity(gas_constant.value() * specific_heat_ratio.value() / (specific_heat_ratio.value() - 1.0)) {}

constexpr IsobaricHeatCapacity IsochoricHeatCapacity::operator+(const GasConstant& gas_constant) const noexcept {
  return {gas_constant, *this};
}

constexpr GasConstant IsobaricHeatCapacity::operator-(const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept {
  return {*this, isochoric_heat_capacity};
}

constexpr IsochoricHeatCapacity IsobaricHeatCapacity::operator-(const GasConstant& gas_constant) const noexcept {
  return {gas_constant, *this};
}

} // namespace PhQ
