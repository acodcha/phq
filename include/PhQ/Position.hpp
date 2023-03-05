// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Displacement.hpp"

namespace PhQ {

class Position : public DimensionalVectorQuantity<Unit::Length> {

public:

  constexpr Position() noexcept : DimensionalVectorQuantity<Unit::Length>() {}

  Position(const Value::Vector& value, Unit::Length unit) noexcept : DimensionalVectorQuantity<Unit::Length>(value, unit) {}

  Length Magnitude() const noexcept {
    return {*this};
  }

  PhQ::Angle Angle(const Position& position) const noexcept {
    return {*this, position};
  }

  constexpr bool operator==(const Position& position) const noexcept {
    return value_ == position.value_;
  }

  constexpr bool operator!=(const Position& position) const noexcept {
    return value_ != position.value_;
  }

  Position operator+(const Position& position) const noexcept {
    return {value_ + position.value_};
  }

  Position operator+(const Displacement& displacement) const noexcept {
    return {value_ + displacement.Value()};
  }

  constexpr void operator+=(const Position& position) noexcept {
    value_ += position.value_;
  }

  constexpr void operator+=(const Displacement& displacement) noexcept {
    value_ += displacement.Value();
  }

  Displacement operator-(const Position& position) const noexcept {
    return {value_ - position.value_};
  }

  Position operator-(const Displacement& displacement) const noexcept {
    return {value_ - displacement.Value()};
  }

  constexpr void operator-=(const Position& position) noexcept {
    value_ -= position.value_;
  }

  constexpr void operator-=(const Displacement& displacement) noexcept {
    value_ -= displacement.Value();
  }

private:

  constexpr Position(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Length>(value) {}

  friend class Displacement;

};

Direction::Direction(const Position& position) noexcept : Direction(position.Value()) {}

Angle::Angle(const Position& position_1, const Position& position_2) noexcept : Angle(position_1.Value(), position_2.Value()) {}

Length::Length(const Position& position) noexcept : Length(position.Value().Magnitude()) {}

Position Displacement::operator+(const Position& position) const noexcept {
  return {value_ + position.Value()};
}

Position Displacement::operator-(const Position& position) const noexcept {
  return {value_ - position.Value()};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::Position> {
  size_t operator()(const PhQ::Position& position) const {
    return hash<PhQ::Value::Vector>()(position.Value());
  }
};

} // namespace std
