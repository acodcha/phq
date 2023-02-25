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

  constexpr Position(const Value::Vector& value, Unit::Length unit) noexcept : DimensionalVectorQuantity<Unit::Length>(value, unit) {}

  constexpr Length magnitude() const noexcept {
    return {*this};
  }

  constexpr Angle angle(const Position& position) const noexcept {
    return {*this, position};
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

  constexpr Position operator+(const Displacement& displacement) const noexcept {
    return {value_ + displacement.value()};
  }

  constexpr void operator+=(const Position& position) noexcept {
    value_ += position.value_;
  }

  constexpr void operator+=(const Displacement& displacement) noexcept {
    value_ += displacement.value();
  }

  constexpr Displacement operator-(const Position& position) const noexcept {
    return {value_ - position.value_};
  }

  constexpr Position operator-(const Displacement& displacement) const noexcept {
    return {value_ - displacement.value()};
  }

  constexpr void operator-=(const Position& position) noexcept {
    value_ -= position.value_;
  }

  constexpr void operator-=(const Displacement& displacement) noexcept {
    value_ -= displacement.value();
  }

protected:

  constexpr Position(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Length>(value) {}

  friend class Displacement;

};

template <> constexpr bool sort(const Position& position_1, const Position& position_2) noexcept {
  return sort(position_1.value(), position_2.value());
}

constexpr Direction::Direction(const Position& position) : Direction(position.value()) {}

constexpr Angle::Angle(const Position& position_1, const Position& position_2) noexcept : Angle(position_1.value(), position_2.value()) {}

constexpr Length::Length(const Position& position) noexcept : Length(position.value().magnitude()) {}

constexpr Position Displacement::operator+(const Position& position) const noexcept {
  return {value_ + position.value()};
}

constexpr Position Displacement::operator-(const Position& position) const noexcept {
  return {value_ - position.value()};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::Position> {
  size_t operator()(const PhQ::Position& position) const {
    return hash<PhQ::Value::Vector>()(position.value());
  }
};

} // namespace std
