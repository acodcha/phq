// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Force.hpp"
#include "StaticPressure.hpp"

namespace PhQ {

class Traction : public DimensionalVectorQuantity<Unit::Pressure> {

public:

  constexpr Traction() noexcept : DimensionalVectorQuantity<Unit::Pressure>() {}

  constexpr Traction(const Value::Vector& value, Unit::Pressure unit) noexcept : DimensionalVectorQuantity<Unit::Pressure>(value, unit) {}

  constexpr StaticPressure magnitude() const noexcept {
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
  friend class StaticPressure;

};

template <> constexpr bool sort(const Traction& traction_1, const Traction& traction_2) noexcept {
  return sort(traction_1.value(), traction_2.value());
}

constexpr Traction Direction::operator*(const StaticPressure& static_pressure) const noexcept {
  return {{x_y_z_[0] * static_pressure.value_, x_y_z_[1] * static_pressure.value_, x_y_z_[2] * static_pressure.value_}};
}

constexpr Angle::Angle(const Traction& traction_1, const Traction& traction_2) noexcept : DimensionalScalarQuantity<Unit::Angle>(traction_1.angle(traction_2)) {}

constexpr StaticPressure::StaticPressure(const Traction& traction) noexcept : StaticPressure(traction.magnitude()) {}

constexpr Traction StaticPressure::operator*(const Direction& direction) const noexcept {
  return {{direction.x_y_z_[0] * value_, direction.x_y_z_[1] * value_, direction.x_y_z_[2] * value_}};
}

Traction Force::operator/(const Area& area) const {
  if (area.value_ != 0.0) {
    return {value_ / area.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + area.print() + "."};
  }
}

} // namespace PhQ
