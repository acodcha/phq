// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declaration.
class StaticPressure;

class PressureDifference : public DimensionalScalarQuantity<Unit::Pressure> {

public:

  constexpr PressureDifference() noexcept : DimensionalScalarQuantity<Unit::Pressure>() {}

  constexpr PressureDifference(double value, Unit::Pressure unit) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr bool operator==(const PressureDifference& pressure_difference) const noexcept {
    return value_ == pressure_difference.value_;
  }

  constexpr bool operator!=(const PressureDifference& pressure_difference) const noexcept {
    return value_ != pressure_difference.value_;
  }

  constexpr bool operator<(const PressureDifference& pressure_difference) const noexcept {
    return value_ < pressure_difference.value_;
  }

  constexpr bool operator<=(const PressureDifference& pressure_difference) const noexcept {
    return value_ <= pressure_difference.value_;
  }

  constexpr bool operator>(const PressureDifference& pressure_difference) const noexcept {
    return value_ > pressure_difference.value_;
  }

  constexpr bool operator>=(const PressureDifference& pressure_difference) const noexcept {
    return value_ >= pressure_difference.value_;
  }

  constexpr StaticPressure operator+(const StaticPressure& static_pressure) const noexcept;

  constexpr PressureDifference operator+(const PressureDifference& pressure_difference) const noexcept {
    return {value_ + pressure_difference.value_};
  }

  constexpr void operator+=(const PressureDifference& pressure_difference) noexcept {
    value_ += pressure_difference.value_;
  }

  constexpr StaticPressure operator-(const StaticPressure& static_pressure) const noexcept;

  constexpr PressureDifference operator-(const PressureDifference& pressure_difference) const noexcept {
    return {value_ - pressure_difference.value_};
  }

  constexpr void operator-=(const PressureDifference& pressure_difference) noexcept {
    value_ -= pressure_difference.value_;
  }

protected:

  constexpr PressureDifference(double value) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value) {}

};

template <> constexpr bool sort(const PressureDifference& pressure_difference_1, const PressureDifference& pressure_difference_2) noexcept {
  return sort(pressure_difference_1.value(), pressure_difference_2.value());
}

} // namespace PhQ
