// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/TemperatureDifference.hpp"

namespace PhQ {

// Forward declarations.
class Length;
class LinearThermalExpansionCoefficient;
class StrainScalar;
class Temperature;
class TemperatureGradientMagnitude;
class VolumetricThermalExpansionCoefficient;

class TemperatureDifference : public DimensionalScalarQuantity<Unit::TemperatureDifference> {

public:

  constexpr TemperatureDifference() noexcept : DimensionalScalarQuantity<Unit::TemperatureDifference>() {}

  constexpr TemperatureDifference(double value, Unit::TemperatureDifference unit) noexcept : DimensionalScalarQuantity<Unit::TemperatureDifference>(value, unit) {}

  constexpr TemperatureDifference(const TemperatureGradientMagnitude& temperature_gradient_magnitude, const Length& length) noexcept;

  constexpr bool operator==(const TemperatureDifference& temperature_difference) const noexcept {
    return value_ == temperature_difference.value_;
  }

  constexpr bool operator!=(const TemperatureDifference& temperature_difference) const noexcept {
    return value_ != temperature_difference.value_;
  }

  constexpr bool operator<(const TemperatureDifference& temperature_difference) const noexcept {
    return value_ < temperature_difference.value_;
  }

  constexpr bool operator<=(const TemperatureDifference& temperature_difference) const noexcept {
    return value_ <= temperature_difference.value_;
  }

  constexpr bool operator>(const TemperatureDifference& temperature_difference) const noexcept {
    return value_ > temperature_difference.value_;
  }

  constexpr bool operator>=(const TemperatureDifference& temperature_difference) const noexcept {
    return value_ >= temperature_difference.value_;
  }

  constexpr Temperature operator+(const Temperature& temperature) const noexcept;

  constexpr TemperatureDifference operator+(const TemperatureDifference& temperature_difference) const noexcept {
    return {value_ + temperature_difference.value_};
  }

  constexpr void operator+=(const TemperatureDifference& temperature_difference) noexcept {
    value_ += temperature_difference.value_;
  }

  constexpr Temperature operator-(const Temperature& temperature) const noexcept;

  constexpr TemperatureDifference operator-(const TemperatureDifference& temperature_difference) const noexcept {
    return {value_ - temperature_difference.value_};
  }

  constexpr void operator-=(const TemperatureDifference& temperature_difference) noexcept {
    value_ -= temperature_difference.value_;
  }

  constexpr StrainScalar operator*(const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) const noexcept;

  constexpr double operator*(const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) const noexcept;

  constexpr TemperatureGradientMagnitude operator/(const Length& length) const noexcept;

protected:

  constexpr TemperatureDifference(double value) noexcept : DimensionalScalarQuantity<Unit::TemperatureDifference>(value) {}

  friend class Temperature;

};

template <> constexpr bool sort(const TemperatureDifference& temperature_difference_1, const TemperatureDifference& temperature_difference_2) noexcept {
  return sort(temperature_difference_1.value(), temperature_difference_2.value());
}

} // namespace PhQ
