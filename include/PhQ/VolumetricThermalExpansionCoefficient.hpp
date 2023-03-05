// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Temperature.hpp"
#include "Unit/ThermalExpansion.hpp"

namespace PhQ {

class VolumetricThermalExpansionCoefficient : public DimensionalScalarQuantity<Unit::ThermalExpansion> {

public:

  constexpr VolumetricThermalExpansionCoefficient() noexcept : DimensionalScalarQuantity<Unit::ThermalExpansion>() {}

  VolumetricThermalExpansionCoefficient(double value, Unit::ThermalExpansion unit) noexcept : DimensionalScalarQuantity<Unit::ThermalExpansion>(value, unit) {}

  constexpr bool operator==(const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) const noexcept {
    return value_ == volumetric_thermal_expansion_coefficient.value_;
  }

  constexpr bool operator!=(const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) const noexcept {
    return value_ != volumetric_thermal_expansion_coefficient.value_;
  }

  constexpr bool operator<(const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) const noexcept {
    return value_ < volumetric_thermal_expansion_coefficient.value_;
  }

  constexpr bool operator<=(const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) const noexcept {
    return value_ <= volumetric_thermal_expansion_coefficient.value_;
  }

  constexpr bool operator>(const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) const noexcept {
    return value_ > volumetric_thermal_expansion_coefficient.value_;
  }

  constexpr bool operator>=(const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) const noexcept {
    return value_ >= volumetric_thermal_expansion_coefficient.value_;
  }

  VolumetricThermalExpansionCoefficient operator+(const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) const noexcept {
    return {value_ + volumetric_thermal_expansion_coefficient.value_};
  }

  constexpr void operator+=(const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) noexcept {
    value_ += volumetric_thermal_expansion_coefficient.value_;
  }

  VolumetricThermalExpansionCoefficient operator-(const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) const noexcept {
    return {value_ - volumetric_thermal_expansion_coefficient.value_};
  }

  constexpr void operator-=(const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) noexcept {
    value_ -= volumetric_thermal_expansion_coefficient.value_;
  }

  constexpr double operator*(const TemperatureDifference& temperature_difference) const noexcept {
    return value_ * temperature_difference.Value();
  }

private:

  constexpr VolumetricThermalExpansionCoefficient(double value) noexcept : DimensionalScalarQuantity<Unit::ThermalExpansion>(value) {}

};

constexpr double TemperatureDifference::operator*(const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) const noexcept {
  return value_ * volumetric_thermal_expansion_coefficient.Value();
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::VolumetricThermalExpansionCoefficient> {
  size_t operator()(const PhQ::VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) const {
    return hash<double>()(volumetric_thermal_expansion_coefficient.Value());
  }
};

} // namespace std
