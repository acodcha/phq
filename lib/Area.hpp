// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Length.hpp"
#include "Unit/Area.hpp"

namespace PhQ {

// Forward declarations.
class AreaVector;
class Direction;
class Force;
class ForceMagnitude;
class StaticPressure;
class Traction;

class Area : public DimensionalScalarQuantity<Unit::Area> {

public:

  constexpr Area() noexcept : DimensionalScalarQuantity<Unit::Area>() {}

  constexpr Area(double value, Unit::Area unit) noexcept : DimensionalScalarQuantity<Unit::Area>(value, unit) {}

  constexpr Area(const Length& length_1, const Length& length_2) noexcept : Area(length_1.value() * length_2.value()) {}

  constexpr Area(const Volume& volume, const Length& length) noexcept;

  constexpr Area(const AreaVector& vector_area) noexcept;

  constexpr Area(const StaticPressure& static_pressure, const ForceMagnitude& force_magnitude) noexcept;

  constexpr bool operator==(const Area& area) const noexcept {
    return value_ == area.value_;
  }

  constexpr bool operator!=(const Area& area) const noexcept {
    return value_ != area.value_;
  }

  constexpr bool operator<(const Area& area) const noexcept {
    return value_ < area.value_;
  }

  constexpr bool operator<=(const Area& area) const noexcept {
    return value_ <= area.value_;
  }

  constexpr bool operator>(const Area& area) const noexcept {
    return value_ > area.value_;
  }

  constexpr bool operator>=(const Area& area) const noexcept {
    return value_ >= area.value_;
  }

  constexpr Area operator+(const Area& area) const noexcept {
    return {value_ + area.value_};
  }

  constexpr void operator+=(const Area& area) noexcept {
    value_ += area.value_;
  }

  constexpr Area operator-(const Area& area) const noexcept {
    return {value_ - area.value_};
  }

  constexpr void operator-=(const Area& area) noexcept {
    value_ -= area.value_;
  }

  constexpr Volume operator*(const Length& length) const noexcept;

  constexpr ForceMagnitude operator*(const StaticPressure& static_pressure) const noexcept;

  constexpr AreaVector operator*(const Direction& direction) const noexcept;

  constexpr Length operator/(const Length& length) const noexcept {
    return {*this, length};
  }

protected:

  constexpr Area(double value) noexcept : DimensionalScalarQuantity<Unit::Area>(value) {}

};

template <> constexpr bool sort(const Area& area_1, const Area& area_2) noexcept {
  return sort(area_1.value(), area_2.value());
}

constexpr Length::Length(const Area& area, const Length& length) noexcept : Length(area.value() / length.value()) {}

constexpr Area Length::operator*(const Length& length) const noexcept {
  return {*this, length};
}

} // namespace PhQ
