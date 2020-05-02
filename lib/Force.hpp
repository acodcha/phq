// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Angle.hpp"
#include "ForceMagnitude.hpp"
#include "Quantity/DimensionalVector.hpp"

namespace PhQ {

// Forward declaration.
class Traction;

class Force : public DimensionalVectorQuantity<Unit::Force> {

public:

  constexpr Force() noexcept : DimensionalVectorQuantity<Unit::Force>() {}

  constexpr Force(const Value::Vector& value, Unit::Force unit) noexcept : DimensionalVectorQuantity<Unit::Force>(value, unit) {}

  constexpr ForceMagnitude magnitude() const noexcept {
    return {value_.magnitude()};
  }

  constexpr Angle angle(const Force& force) const noexcept {
    return value_.angle(force.value_);
  }

  constexpr bool operator==(const Force& force) const noexcept {
    return value_ == force.value_;
  }

  constexpr bool operator!=(const Force& force) const noexcept {
    return value_ != force.value_;
  }

  constexpr Force operator+(const Force& force) const noexcept {
    return {value_ + force.value_};
  }

  constexpr void operator+=(const Force& force) noexcept {
    value_ += force.value_;
  }

  constexpr Force operator-(const Force& force) const noexcept {
    return {value_ - force.value_};
  }

  constexpr void operator-=(const Force& force) noexcept {
    value_ -= force.value_;
  }

  Traction operator/(const Area& area) const;

protected:

  constexpr Force(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Force>(value) {}

  friend class Area;
  friend class Direction;
  friend class ForceMagnitude;
  friend class Traction;

};

template <> constexpr bool sort(const Force& force_1, const Force& force_2) noexcept {
  return sort(force_1.value(), force_2.value());
}

constexpr Force Direction::operator*(const ForceMagnitude& force_magnitude) const noexcept {
  return {{x_y_z_[0] * force_magnitude.value_, x_y_z_[1] * force_magnitude.value_, x_y_z_[2] * force_magnitude.value_}};
}

constexpr Angle::Angle(const Force& force_1, const Force& force_2) noexcept : DimensionalScalarQuantity<Unit::Angle>(force_1.angle(force_2)) {}

constexpr ForceMagnitude::ForceMagnitude(const Force& force) noexcept : ForceMagnitude(force.magnitude()) {}

constexpr Force ForceMagnitude::operator*(const Direction& direction) const noexcept {
  return {{direction.x() * value_, direction.y() * value_, direction.z() * value_}};
}

} // namespace PhQ
