// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Temperature.hpp"

namespace PhQ {

// Forward declaration.
class Length;
class Temperature;
class TemperatureGradientMagnitude;

class TemperatureDifference : public DimensionalScalarQuantity<Unit::Temperature> {

public:

  constexpr TemperatureDifference() noexcept : DimensionalScalarQuantity<Unit::Temperature>() {}

  constexpr TemperatureDifference(double value, Unit::Temperature unit) noexcept : DimensionalScalarQuantity<Unit::Temperature>(value, unit) {}

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

  TemperatureGradientMagnitude operator/(const Length& length) const;

protected:

  constexpr TemperatureDifference(double value) noexcept : DimensionalScalarQuantity<Unit::Temperature>(value) {}

  friend class Temperature;
  friend class TemperatureGradientMagnitude;

};

template <> constexpr bool sort(const TemperatureDifference& temperature_difference_1, const TemperatureDifference& temperature_difference_2) noexcept {
  return temperature_difference_1.value() < temperature_difference_2.value();
}

} // namespace PhQ
