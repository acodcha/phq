// Copyright 2020-2023 Alexandre Coderre-Chabot
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

  AreaVector(const Value::Vector& value, Unit::Area unit) noexcept : DimensionalVectorQuantity<Unit::Area>(value, unit) {}

  constexpr AreaVector(const Area& area, const Direction& direction) noexcept : AreaVector(area.Value() * direction.Value()) {}

  Area Magnitude() const noexcept {
    return {*this};
  }

  PhQ::Angle Angle(const AreaVector& area_vector) const noexcept {
    return {*this, area_vector};
  }

  constexpr bool operator==(const AreaVector& area_vector) const noexcept {
    return value_ == area_vector.value_;
  }

  constexpr bool operator!=(const AreaVector& area_vector) const noexcept {
    return value_ != area_vector.value_;
  }

  AreaVector operator+(const AreaVector& area_vector) const noexcept {
    return {value_ + area_vector.value_};
  }

  constexpr void operator+=(const AreaVector& area_vector) noexcept {
    value_ += area_vector.value_;
  }

  AreaVector operator-(const AreaVector& area_vector) const noexcept {
    return {value_ - area_vector.value_};
  }

  constexpr void operator-=(const AreaVector& area_vector) noexcept {
    value_ -= area_vector.value_;
  }

private:

  constexpr AreaVector(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Area>(value) {}

};

Direction::Direction(const AreaVector& area_vector) noexcept : Direction(area_vector.Value()) {}

Angle::Angle(const AreaVector& area_vector_1, const AreaVector& area_vector_2) noexcept : Angle(area_vector_1.Value(), area_vector_2.Value()) {}

Area::Area(const AreaVector& area_vector) noexcept : Area(area_vector.Value().Magnitude()) {}

AreaVector Direction::operator*(const Area& area) const noexcept {
  return {area, *this};
}

AreaVector Area::operator*(const Direction& direction) const noexcept {
  return {*this, direction};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::AreaVector> {
  size_t operator()(const PhQ::AreaVector& area_vector) const {
    return hash<PhQ::Value::Vector>()(area_vector.Value());
  }
};

} // namespace std
