// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Length.hpp"

namespace PhQ {

// Forward declarations.
class Area;
class Direction;
class Displacement;
class Duration;
class Frequency;
class Position;
class Speed;
class Volume;

class Length : public DimensionalScalarQuantity<Unit::Length> {

public:

  constexpr Length() noexcept : DimensionalScalarQuantity<Unit::Length>() {}

  constexpr Length(double value, Unit::Length unit) noexcept : DimensionalScalarQuantity<Unit::Length>(value, unit) {}

  constexpr Length(const Displacement& displacement) noexcept;

  constexpr Length(const Position& position) noexcept;

  constexpr Length(const Area& area, const Length& length) noexcept;

  constexpr Length(const Volume& volume, const Area& area) noexcept;

  constexpr Length(const Speed& speed, const Duration& duration) noexcept;

  constexpr Length(const Speed& speed, const Frequency& frequency) noexcept;

  constexpr bool operator==(const Length& length) const noexcept {
    return value_ == length.value_;
  }

  constexpr bool operator!=(const Length& length) const noexcept {
    return value_ != length.value_;
  }

  constexpr bool operator<(const Length& length) const noexcept {
    return value_ < length.value_;
  }

  constexpr bool operator<=(const Length& length) const noexcept {
    return value_ <= length.value_;
  }

  constexpr bool operator>(const Length& length) const noexcept {
    return value_ > length.value_;
  }

  constexpr bool operator>=(const Length& length) const noexcept {
    return value_ >= length.value_;
  }

  constexpr Length operator+(const Length& length) const noexcept {
    return {value_ + length.value_};
  }

  constexpr void operator+=(const Length& length) noexcept {
    value_ += length.value_;
  }

  constexpr Length operator-(const Length& length) const noexcept {
    return {value_ - length.value_};
  }

  constexpr void operator-=(const Length& length) noexcept {
    value_ -= length.value_;
  }

  constexpr Area operator*(const Length& length) const noexcept;

  constexpr Volume operator*(const Area& area) const noexcept;

  constexpr Speed operator*(const Frequency& frequency) const noexcept;

  constexpr Displacement operator*(const Direction& direction) const noexcept;

  constexpr Speed operator/(const Duration& duration) const noexcept;

  constexpr Duration operator/(const Speed& speed) const noexcept;

protected:

  constexpr Length(double value) noexcept : DimensionalScalarQuantity<Unit::Length>(value) {}

};

template <> constexpr bool sort(const Length& length_1, const Length& length_2) noexcept {
  return sort(length_1.value(), length_2.value());
}

} // namespace PhQ
