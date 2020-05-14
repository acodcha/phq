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

class AreaVector : public DimensionalVectorQuantity<Unit::Area> {

public:

  constexpr AreaVector() noexcept : DimensionalVectorQuantity<Unit::Area>() {}

  constexpr AreaVector(const Value::Vector& value, Unit::Area unit) noexcept : DimensionalVectorQuantity<Unit::Area>(value, unit) {}

  constexpr Area magnitude() const noexcept {
    return {value_.magnitude()};
  }

  constexpr Angle angle(const AreaVector& area_vector) const noexcept {
    return value_.angle(area_vector.value_);
  }

  constexpr bool operator==(const AreaVector& area_vector) const noexcept {
    return value_ == area_vector.value_;
  }

  constexpr bool operator!=(const AreaVector& area_vector) const noexcept {
    return value_ != area_vector.value_;
  }

  constexpr AreaVector operator+(const AreaVector& area_vector) const noexcept {
    return {value_ + area_vector.value_};
  }

  constexpr void operator+=(const AreaVector& area_vector) noexcept {
    value_ += area_vector.value_;
  }

  constexpr AreaVector operator-(const AreaVector& area_vector) const noexcept {
    return {value_ - area_vector.value_};
  }

  constexpr void operator-=(const AreaVector& area_vector) noexcept {
    value_ -= area_vector.value_;
  }

  constexpr Direction operator/(const Area& area) const noexcept {
    return {value_ / area.value_};
  }

protected:

  constexpr AreaVector(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Area>(value) {}

  friend class Area;
  friend class Direction;

};

template <> constexpr bool sort(const AreaVector& area_vector_1, const AreaVector& area_vector_2) noexcept {
  return sort(area_vector_1.value(), area_vector_2.value());
}

constexpr AreaVector Direction::operator*(const Area& area) const noexcept {
  return {{x_y_z_[0] * area.value_, x_y_z_[1] * area.value_, x_y_z_[2] * area.value_}};
}

constexpr Angle::Angle(const AreaVector& area_vector_1, const AreaVector& area_vector_2) noexcept : DimensionalScalarQuantity<Unit::Angle>(area_vector_1.angle(area_vector_2)) {}

constexpr Area::Area(const AreaVector& area_vector) noexcept : Area(area_vector.magnitude()) {}

constexpr AreaVector Area::operator*(const Direction& direction) const noexcept {
  return {{direction.x() * value_, direction.y() * value_, direction.z() * value_}};
}

} // namespace PhQ
