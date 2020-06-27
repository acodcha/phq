// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Angle.hpp"
#include "Length.hpp"
#include "Quantity/DimensionalVector.hpp"

namespace PhQ {

// Forward declarations.
class Duration;
class Frequency;
class Position;
class Velocity;

class Displacement : public DimensionalVectorQuantity<Unit::Length> {

public:

  constexpr Displacement() noexcept : DimensionalVectorQuantity<Unit::Length>() {}

  constexpr Displacement(const Value::Vector& value, Unit::Length unit) noexcept : DimensionalVectorQuantity<Unit::Length>(value, unit) {}

  constexpr Displacement(const Length& length, const Direction& direction) noexcept : Displacement({length.value() * direction.x(), length.value() * direction.y(), length.value() * direction.z()}) {}

  constexpr Displacement(const Velocity& velocity, const Duration& duration) noexcept;

  constexpr Displacement(const Velocity& velocity, const Frequency& frequency) noexcept;

  constexpr Length magnitude() const noexcept {
    return {*this};
  }

  constexpr Angle angle(const Displacement& displacement) const noexcept {
    return {*this, displacement};
  }

  constexpr bool operator==(const Displacement& displacement) const noexcept {
    return value_ == displacement.value_;
  }

  constexpr bool operator!=(const Displacement& displacement) const noexcept {
    return value_ != displacement.value_;
  }

  constexpr Position operator+(const Position& position) const noexcept;

  constexpr Displacement operator+(const Displacement& displacement) const noexcept {
    return {value_ + displacement.value_};
  }

  constexpr void operator+=(const Displacement& displacement) noexcept {
    value_ += displacement.value_;
  }

  constexpr Position operator-(const Position& position) const noexcept;

  constexpr Displacement operator-(const Displacement& displacement) const noexcept {
    return {value_ - displacement.value_};
  }

  constexpr void operator-=(const Displacement& displacement) noexcept {
    value_ -= displacement.value_;
  }

  constexpr Velocity operator*(const Frequency& frequency) const noexcept;

  constexpr Velocity operator/(const Duration& duration) const noexcept;

protected:

  constexpr Displacement(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Length>(value) {}

  friend class Position;

};

template <> constexpr bool sort(const Displacement& displacement_1, const Displacement& displacement_2) noexcept {
  return sort(displacement_1.value(), displacement_2.value());
}

constexpr Direction::Direction(const Displacement& displacement) : Direction(displacement.value()) {}

constexpr Angle::Angle(const Displacement& displacement_1, const Displacement& displacement_2) noexcept : Angle(displacement_1.value(), displacement_2.value()) {}

constexpr Length::Length(const Displacement& displacement) noexcept : Length(displacement.value().magnitude()) {}

constexpr Displacement Direction::operator*(const Length& length) const noexcept {
  return {length, *this};
}

constexpr Displacement Length::operator*(const Direction& direction) const noexcept {
  return {*this, direction};
}

} // namespace PhQ
