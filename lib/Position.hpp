// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Angle.hpp"
#include "Length.hpp"
#include "Quantity/DimensionalVector.hpp"

namespace PhQ {

// Forward declaration.
class Displacement;

class Position : public DimensionalVectorQuantity<Unit::Length> {

public:

  constexpr Position() noexcept : DimensionalVectorQuantity<Unit::Length>() {}

  constexpr Position(const Value::Vector& value, Unit::Length unit) noexcept : DimensionalVectorQuantity<Unit::Length>(value, unit) {}

  constexpr Length magnitude() const noexcept {
    return {value_.magnitude()};
  }

  constexpr Angle angle(const Position& position) const noexcept {
    return value_.angle(position.value_);
  }

  constexpr bool operator==(const Position& position) const noexcept {
    return value_ == position.value_;
  }

  constexpr bool operator!=(const Position& position) const noexcept {
    return value_ != position.value_;
  }

  constexpr Position operator+(const Position& position) const noexcept {
    return {value_ + position.value_};
  }

  constexpr Position operator+(const Displacement& displacement) const noexcept;

  constexpr void operator+=(const Position& position) noexcept {
    value_ += position.value_;
  }

  constexpr void operator+=(const Displacement& displacement) noexcept;

  constexpr Displacement operator-(const Position& position) const noexcept;

  constexpr Position operator-(const Displacement& displacement) const noexcept;

  constexpr void operator-=(const Position& position) noexcept {
    value_ -= position.value_;
  }

  constexpr void operator-=(const Displacement& displacement) noexcept;

protected:

  constexpr Position(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Length>(value) {}

  friend class Displacement;
  friend class Length;

};

template <> constexpr bool sort(const Position& position_1, const Position& position_2) noexcept {
  return sort(position_1.value(), position_2.value());
}

constexpr Angle::Angle(const Position& position_1, const Position& position_2) noexcept : DimensionalScalarQuantity<Unit::Angle>(position_1.angle(position_2)) {}

} // namespace PhQ
