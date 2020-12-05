// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

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

  constexpr AreaVector(const Area& area, const Direction& direction) noexcept : AreaVector({area.value() * direction.x(), area.value() * direction.y(), area.value() * direction.z()}) {}

  constexpr Area magnitude() const noexcept {
    return {*this};
  }

  constexpr Angle angle(const AreaVector& area_vector) const noexcept {
    return {*this, area_vector};
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

protected:

  constexpr AreaVector(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Area>(value) {}

};

template <> constexpr bool sort(const AreaVector& area_vector_1, const AreaVector& area_vector_2) noexcept {
  return sort(area_vector_1.value(), area_vector_2.value());
}

constexpr Direction::Direction(const AreaVector& area_vector) : Direction(area_vector.value()) {}

constexpr Angle::Angle(const AreaVector& area_vector_1, const AreaVector& area_vector_2) noexcept : Angle(area_vector_1.value(), area_vector_2.value()) {}

constexpr Area::Area(const AreaVector& area_vector) noexcept : Area(area_vector.value().magnitude()) {}

constexpr AreaVector Direction::operator*(const Area& area) const noexcept {
  return {area, *this};
}

constexpr AreaVector Area::operator*(const Direction& direction) const noexcept {
  return {*this, direction};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::AreaVector> {
  size_t operator()(const PhQ::AreaVector& area_vector) const {
    return hash<PhQ::Value::Vector>()(area_vector.value());
  }
};

} // namespace std
