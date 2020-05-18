// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Temperature.hpp"
#include "Unit/ThermalExpansion.hpp"

namespace PhQ {

class LinearThermalExpansionCoefficient : public DimensionalScalarQuantity<Unit::ThermalExpansion> {

public:

  constexpr LinearThermalExpansionCoefficient() noexcept : DimensionalScalarQuantity<Unit::ThermalExpansion>() {}

  constexpr LinearThermalExpansionCoefficient(double value, Unit::ThermalExpansion unit) noexcept : DimensionalScalarQuantity<Unit::ThermalExpansion>(value, unit) {}

  constexpr bool operator==(const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) const noexcept {
    return value_ == linear_thermal_expansion_coefficient.value_;
  }

  constexpr bool operator!=(const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) const noexcept {
    return value_ != linear_thermal_expansion_coefficient.value_;
  }

  constexpr bool operator<(const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) const noexcept {
    return value_ < linear_thermal_expansion_coefficient.value_;
  }

  constexpr bool operator<=(const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) const noexcept {
    return value_ <= linear_thermal_expansion_coefficient.value_;
  }

  constexpr bool operator>(const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) const noexcept {
    return value_ > linear_thermal_expansion_coefficient.value_;
  }

  constexpr bool operator>=(const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) const noexcept {
    return value_ >= linear_thermal_expansion_coefficient.value_;
  }

  constexpr LinearThermalExpansionCoefficient operator+(const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) const noexcept {
    return {value_ + linear_thermal_expansion_coefficient.value_};
  }

  constexpr void operator+=(const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) noexcept {
    value_ += linear_thermal_expansion_coefficient.value_;
  }

  constexpr LinearThermalExpansionCoefficient operator-(const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) const noexcept {
    return {value_ - linear_thermal_expansion_coefficient.value_};
  }

  constexpr void operator-=(const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) noexcept {
    value_ -= linear_thermal_expansion_coefficient.value_;
  }

  constexpr double operator*(const TemperatureDifference& temperature_difference) const noexcept {
    return value_ * temperature_difference.value();
  }

protected:

  constexpr LinearThermalExpansionCoefficient(double value) noexcept : DimensionalScalarQuantity<Unit::ThermalExpansion>(value) {}

};

template <> constexpr bool sort(const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient_1, const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient_2) noexcept {
  return sort(linear_thermal_expansion_coefficient_1.value(), linear_thermal_expansion_coefficient_2.value());
}

constexpr double TemperatureDifference::operator*(const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) const noexcept {
  return value_ * linear_thermal_expansion_coefficient.value();
}

} // namespace PhQ
