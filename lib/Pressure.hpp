// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "ForceMagnitude.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declaration.
class Direction;
class Traction;

class Pressure : public DimensionalScalarQuantity<Unit::Pressure> {

public:

  constexpr Pressure() noexcept : DimensionalScalarQuantity<Unit::Pressure>() {}

  constexpr Pressure(double value, Unit::Pressure unit) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr Pressure(const Traction& traction) noexcept;

  constexpr bool operator==(const Pressure& pressure) const noexcept {
    return value_ == pressure.value_;
  }

  constexpr bool operator!=(const Pressure& pressure) const noexcept {
    return value_ != pressure.value_;
  }

  constexpr bool operator<(const Pressure& pressure) const noexcept {
    return value_ < pressure.value_;
  }

  constexpr bool operator<=(const Pressure& pressure) const noexcept {
    return value_ <= pressure.value_;
  }

  constexpr bool operator>(const Pressure& pressure) const noexcept {
    return value_ > pressure.value_;
  }

  constexpr bool operator>=(const Pressure& pressure) const noexcept {
    return value_ >= pressure.value_;
  }

  constexpr Pressure operator+(const Pressure& pressure) const noexcept {
    return {value_ + pressure.value_};
  }

  constexpr void operator+=(const Pressure& pressure) noexcept {
    value_ += pressure.value_;
  }

  constexpr Pressure operator-(const Pressure& pressure) const noexcept {
    return {value_ - pressure.value_};
  }

  constexpr void operator-=(const Pressure& pressure) noexcept {
    value_ -= pressure.value_;
  }

  ForceMagnitude operator*(const Area& area) const noexcept {
    return {value_ * area.value_};
  }

protected:

  constexpr Pressure(double value) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value) {}

  friend class Area;
  friend class Direction;
  friend class ForceMagnitude;
  friend class Traction;

};

template <> constexpr bool sort(const Pressure& pressure_1, const Pressure& pressure_2) noexcept {
  return pressure_1.value() < pressure_2.value();
}

constexpr ForceMagnitude Area::operator*(const Pressure& pressure) const noexcept {
  return {value_ * pressure.value_};
}

Pressure ForceMagnitude::operator/(const Area& area) const {
  if (area.value_ != 0.0) {
    return {value_ / area.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + area.print() + "."};
  }
}

} // namespace PhQ
