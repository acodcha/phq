// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Angle.hpp"
#include "Direction.hpp"
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

  Displacement(const Value::Vector& value, Unit::Length unit) noexcept : DimensionalVectorQuantity<Unit::Length>(value, unit) {}

  constexpr Displacement(const Length& length, const Direction& direction) noexcept : Displacement(length.Value() * direction.Value()) {}

  constexpr Displacement(const Velocity& velocity, const Duration& duration) noexcept;

  constexpr Displacement(const Velocity& velocity, const Frequency& frequency) noexcept;

  Length Magnitude() const noexcept {
    return {*this};
  }

  PhQ::Angle Angle(const Displacement& displacement) const noexcept {
    return {*this, displacement};
  }

  constexpr bool operator==(const Displacement& displacement) const noexcept {
    return value_ == displacement.value_;
  }

  constexpr bool operator!=(const Displacement& displacement) const noexcept {
    return value_ != displacement.value_;
  }

  Position operator+(const Position& position) const noexcept;

  Displacement operator+(const Displacement& displacement) const noexcept {
    return {value_ + displacement.value_};
  }

  constexpr void operator+=(const Displacement& displacement) noexcept {
    value_ += displacement.value_;
  }

  Position operator-(const Position& position) const noexcept;

  Displacement operator-(const Displacement& displacement) const noexcept {
    return {value_ - displacement.value_};
  }

  constexpr void operator-=(const Displacement& displacement) noexcept {
    value_ -= displacement.value_;
  }

  Velocity operator*(const Frequency& frequency) const noexcept;

  Velocity operator/(const Duration& duration) const noexcept;

protected:

  constexpr Displacement(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Length>(value) {}

  friend class Position;

};

Direction::Direction(const Displacement& displacement) noexcept : Direction(displacement.Value()) {}

Angle::Angle(const Displacement& displacement_1, const Displacement& displacement_2) noexcept : Angle(displacement_1.Value(), displacement_2.Value()) {}

Length::Length(const Displacement& displacement) noexcept : Length(displacement.Value().Magnitude()) {}

Displacement Direction::operator*(const Length& length) const noexcept {
  return {length, *this};
}

Displacement Length::operator*(const Direction& direction) const noexcept {
  return {*this, direction};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::Displacement> {
  size_t operator()(const PhQ::Displacement& displacement) const {
    return hash<PhQ::Value::Vector>()(displacement.Value());
  }
};

} // namespace std
