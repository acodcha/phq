// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Angle.hpp"
#include "Area.hpp"
#include "Direction.hpp"
#include "Quantity/DimensionalVector.hpp"

namespace PhQ {

class VectorArea : public DimensionalVectorQuantity<Unit::Area> {

public:

  constexpr VectorArea() noexcept : DimensionalVectorQuantity<Unit::Area>() {}

  constexpr VectorArea(const DimensionalVectorQuantity<Unit::Area>& quantity) noexcept : DimensionalVectorQuantity<Unit::Area>(quantity) {}

  constexpr VectorArea(const Value::Vector& value, Unit::Area unit) noexcept : DimensionalVectorQuantity<Unit::Area>(value, unit) {}

  constexpr Area magnitude() const noexcept {
    return {value_.magnitude()};
  }

  constexpr Angle angle(const VectorArea& vector_area) const noexcept {
    return value_.angle(vector_area.value_);
  }

  constexpr bool operator==(const VectorArea& vector_area) const noexcept {
    return value_ == vector_area.value_;
  }

  constexpr bool operator!=(const VectorArea& vector_area) const noexcept {
    return value_ != vector_area.value_;
  }

  constexpr VectorArea operator+(const VectorArea& vector_area) const noexcept {
    return {value_ + vector_area.value_};
  }

  constexpr void operator+=(const VectorArea& vector_area) noexcept {
    value_ += vector_area.value_;
  }

  constexpr VectorArea operator-(const VectorArea& vector_area) const noexcept {
    return {value_ - vector_area.value_};
  }

  constexpr void operator-=(const VectorArea& vector_area) noexcept {
    value_ -= vector_area.value_;
  }

protected:

  constexpr VectorArea(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Area>(value) {}

  friend class Area;
  friend class Direction;

};

template <> constexpr bool sort(const VectorArea& vector_area_1, const VectorArea& vector_area_2) noexcept {
  return sort(vector_area_1.value(), vector_area_2.value());
}

constexpr VectorArea Direction::operator*(const Area& area) const noexcept {
  return {{x_y_z_[0] * area.value_, x_y_z_[1] * area.value_, x_y_z_[2] * area.value_}};
}

constexpr Angle::Angle(const VectorArea& vector_area_1, const VectorArea& vector_area_2) noexcept : DimensionalScalarQuantity<Unit::Angle>(vector_area_1.angle(vector_area_2)) {}

} // namespace PhQ

constexpr PhQ::VectorArea operator*(const PhQ::Area& area, const PhQ::Direction& direction) noexcept {
  return {direction * area};
}
