// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "TemperatureDifference.hpp"
#include "Unit/Temperature.hpp"

namespace PhQ {

class Temperature : public DimensionalScalarQuantity<Unit::Temperature> {

public:

  constexpr Temperature() noexcept : DimensionalScalarQuantity<Unit::Temperature>() {}

  constexpr Temperature(double value, Unit::Temperature unit) noexcept : DimensionalScalarQuantity<Unit::Temperature>(value, unit) {}

  constexpr bool operator==(const Temperature& temperature) const noexcept {
    return value_ == temperature.value_;
  }

  constexpr bool operator!=(const Temperature& temperature) const noexcept {
    return value_ != temperature.value_;
  }

  constexpr bool operator<(const Temperature& temperature) const noexcept {
    return value_ < temperature.value_;
  }

  constexpr bool operator<=(const Temperature& temperature) const noexcept {
    return value_ <= temperature.value_;
  }

  constexpr bool operator>(const Temperature& temperature) const noexcept {
    return value_ > temperature.value_;
  }

  constexpr bool operator>=(const Temperature& temperature) const noexcept {
    return value_ >= temperature.value_;
  }

  constexpr Temperature operator+(const Temperature& temperature) const noexcept {
    return {value_ + temperature.value_};
  }

  constexpr Temperature operator+(const TemperatureDifference& temperature_difference) const noexcept {
    return {value_ + temperature_difference.value()};
  }

  constexpr void operator+=(const Temperature& temperature) noexcept {
    value_ += temperature.value_;
  }

  constexpr void operator+=(const TemperatureDifference& temperature_difference) noexcept {
    value_ += temperature_difference.value();
  }

  constexpr TemperatureDifference operator-(const Temperature& temperature) const noexcept {
    return {value_ - temperature.value_};
  }

  constexpr Temperature operator-(const TemperatureDifference& temperature_difference) const noexcept {
    return {value_ - temperature_difference.value()};
  }

  constexpr void operator-=(const Temperature& temperature) noexcept {
    value_ -= temperature.value_;
  }

  constexpr void operator-=(const TemperatureDifference& temperature_difference) noexcept {
    value_ -= temperature_difference.value();
  }

protected:

  constexpr Temperature(double value) noexcept : DimensionalScalarQuantity<Unit::Temperature>(value) {}

  friend class TemperatureDifference;

};

template <> constexpr bool sort(const Temperature& temperature_1, const Temperature& temperature_2) noexcept {
  return sort(temperature_1.value(), temperature_2.value());
}

constexpr Temperature TemperatureDifference::operator+(const Temperature& temperature) const noexcept {
  return {value_ + temperature.value()};
}

constexpr Temperature TemperatureDifference::operator-(const Temperature& temperature) const noexcept {
  return {value_ - temperature.value()};
}

} // namespace PhQ
