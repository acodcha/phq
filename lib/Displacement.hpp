// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Position.hpp"

namespace PhQ {

// Forward declarations.
class Duration;
class Frequency;
class Velocity;

class Displacement : public DimensionalVectorQuantity<Unit::Length> {

public:

  constexpr Displacement() noexcept : DimensionalVectorQuantity<Unit::Length>() {}

  constexpr Displacement(const Value::Vector& value, Unit::Length unit) noexcept : DimensionalVectorQuantity<Unit::Length>(value, unit) {}

  constexpr Length magnitude() const noexcept {
    return {value_.magnitude()};
  }

  constexpr Angle angle(const Displacement& displacement) const noexcept {
    return value_.angle(displacement.value_);
  }

  constexpr bool operator==(const Displacement& displacement) const noexcept {
    return value_ == displacement.value_;
  }

  constexpr bool operator!=(const Displacement& displacement) const noexcept {
    return value_ != displacement.value_;
  }

  constexpr Position operator+(const Position& position) const noexcept {
    return {value_ + position.value_};
  }

  constexpr Displacement operator+(const Displacement& displacement) const noexcept {
    return {value_ + displacement.value_};
  }

  constexpr void operator+=(const Displacement& displacement) noexcept {
    value_ += displacement.value_;
  }

  constexpr Displacement operator-(const Position& position) const noexcept {
    return {value_ - position.value_};
  }

  constexpr Displacement operator-(const Displacement& displacement) const noexcept {
    return {value_ - displacement.value_};
  }

  constexpr void operator-=(const Displacement& displacement) noexcept {
    value_ -= displacement.value_;
  }

  constexpr Velocity operator*(const Frequency& frequency) const noexcept;

  Velocity operator/(const Duration& duration) const;

protected:

  constexpr Displacement(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Length>(value) {}

  friend class Duration;
  friend class Frequency;
  friend class Length;
  friend class Position;
  friend class Velocity;

};

constexpr Angle::Angle(const Displacement& displacement1, const Displacement& displacement2) noexcept : DimensionalScalarQuantity<Unit::Angle>(displacement1.angle(displacement2)) {}

constexpr Length::Length(const Displacement& displacement) noexcept : Length(displacement.magnitude()) {}

constexpr Position Position::operator+(const Displacement& displacement) const noexcept {
  return {value_ + displacement.value_};
}

constexpr Displacement Position::operator-(const Position& position) const noexcept {
  return {value_ - position.value_};
}

constexpr Position Position::operator-(const Displacement& displacement) const noexcept {
  return {value_ - displacement.value_};
}

constexpr void Position::operator+=(const Displacement& displacement) noexcept {
  value_ += displacement.value_;
}

constexpr void Position::operator-=(const Displacement& displacement) noexcept {
  value_ -= displacement.value_;
}

} // namespace PhQ
