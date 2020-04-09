// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Force.hpp"
#include "Pressure.hpp"

namespace PhQ {

class Traction : public DimensionalVectorQuantity<Unit::Pressure> {

public:

  constexpr Traction() noexcept : DimensionalVectorQuantity<Unit::Pressure>() {}

  constexpr Traction(const Value::Vector& value, Unit::Pressure unit) noexcept : DimensionalVectorQuantity<Unit::Pressure>(value, unit) {}

  constexpr Pressure magnitude() const noexcept {
    return {value_.magnitude()};
  }

  constexpr Angle angle(const Traction& traction) const noexcept {
    return value_.angle(traction.value_);
  }

  constexpr bool operator==(const Traction& traction) const noexcept {
    return value_ == traction.value_;
  }

  constexpr bool operator!=(const Traction& traction) const noexcept {
    return value_ != traction.value_;
  }

  constexpr Traction operator+(const Traction& traction) const noexcept {
    return {value_ + traction.value_};
  }

  constexpr void operator+=(const Traction& traction) noexcept {
    value_ += traction.value_;
  }

  constexpr Traction operator-(const Traction& traction) const noexcept {
    return {value_ - traction.value_};
  }

  constexpr void operator-=(const Traction& traction) noexcept {
    value_ -= traction.value_;
  }

  constexpr Force operator*(const Area& area) const noexcept {
    return {value_ * area.value_};
  }

protected:

  constexpr Traction(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Pressure>(value) {}

  friend class Area;
  friend class Direction;
  friend class Force;

};

template <> constexpr bool sort(const Traction& traction_1, const Traction& traction_2) noexcept {
  return sort(traction_1.value(), traction_2.value());
}

constexpr Traction Direction::operator*(const Pressure& pressure) const noexcept {
  return {{x_y_z_[0] * pressure.value_, x_y_z_[1] * pressure.value_, x_y_z_[2] * pressure.value_}};
}

constexpr Angle::Angle(const Traction& traction_1, const Traction& traction_2) noexcept : DimensionalScalarQuantity<Unit::Angle>(traction_1.angle(traction_2)) {}

constexpr Pressure::Pressure(const Traction& traction) noexcept : Pressure(traction.magnitude()) {}

Traction Force::operator/(const Area& area) const {
  if (area.value_ != 0.0) {
    return {value_ / area.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + area.print() + "."};
  }
}

} // namespace PhQ

constexpr PhQ::Traction operator*(const PhQ::Pressure& pressure, const PhQ::Direction& direction) noexcept {
  return {direction * pressure};
}
