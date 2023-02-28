// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "StrainScalar.hpp"
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

  constexpr StrainScalar operator*(const TemperatureDifference& temperature_difference) const noexcept {
    return {*this, temperature_difference};
  }

protected:

  constexpr LinearThermalExpansionCoefficient(double value) noexcept : DimensionalScalarQuantity<Unit::ThermalExpansion>(value) {}

};

template <> constexpr bool sort(const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient_1, const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient_2) noexcept {
  return sort(linear_thermal_expansion_coefficient_1.value(), linear_thermal_expansion_coefficient_2.value());
}

constexpr StrainScalar::StrainScalar(const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient, const TemperatureDifference& temperature_difference) noexcept : StrainScalar(linear_thermal_expansion_coefficient.value() * temperature_difference.value()) {}

constexpr StrainScalar TemperatureDifference::operator*(const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) const noexcept {
  return {linear_thermal_expansion_coefficient, *this};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::LinearThermalExpansionCoefficient> {
  size_t operator()(const PhQ::LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) const {
    return hash<double>()(linear_thermal_expansion_coefficient.value());
  }
};

} // namespace std
