// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_POSITION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_POSITION_HPP

#include "Displacement.hpp"

namespace PhQ {

class Position : public DimensionalVectorQuantity<Unit::Length> {
public:
  constexpr Position() noexcept : DimensionalVectorQuantity<Unit::Length>() {}

  Position(const Value::Vector& value, const Unit::Length unit) noexcept
      : DimensionalVectorQuantity<Unit::Length>(value, unit) {}

  explicit constexpr Position(const Displacement& displacement) noexcept
      : Position(displacement.Value()) {}

  inline Length Magnitude() const noexcept { return {*this}; }

  inline PhQ::Angle Angle(const Position& position) const noexcept {
    return {*this, position};
  }

  inline Position operator+(const Position& position) const noexcept {
    return Position{value_ + position.value_};
  }

  inline Position operator+(const Displacement& displacement) const noexcept {
    return Position{value_ + displacement.Value()};
  }

  inline Displacement operator-(const Position& position) const noexcept {
    return Displacement{value_ - position.value_};
  }

  inline Position operator-(const Displacement& displacement) const noexcept {
    return Position{value_ - displacement.Value()};
  }

  inline Position operator*(const double number) const noexcept {
    return Position{value_ * number};
  }

  inline Position operator/(const double number) const noexcept {
    return Position{value_ / number};
  }

  inline constexpr void operator+=(const Position& position) noexcept {
    value_ += position.value_;
  }

  inline constexpr void operator+=(const Displacement& displacement) noexcept {
    value_ += displacement.Value();
  }

  inline constexpr void operator-=(const Position& position) noexcept {
    value_ -= position.value_;
  }

  inline constexpr void operator-=(const Displacement& displacement) noexcept {
    value_ -= displacement.Value();
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Position(const Value::Vector& value) noexcept
      : DimensionalVectorQuantity<Unit::Length>(value) {}

  friend class Displacement;
};

inline constexpr bool operator==(const Position& left,
                                 const Position& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Position& left,
                                 const Position& right) noexcept {
  return left.Value() != right.Value();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const Position& position) noexcept {
  stream << position.Print();
  return stream;
}

inline Position operator*(const double number,
                          const Position& position) noexcept {
  return position * number;
}

inline Direction::Direction(const Position& position) noexcept
    : Direction(position.Value()) {}

inline Angle::Angle(const Position& position_1,
                    const Position& position_2) noexcept
    : Angle(position_1.Value(), position_2.Value()) {}

inline Length::Length(const Position& position) noexcept
    : Length(position.Value().Magnitude()) {}

inline constexpr Displacement::Displacement(const Position& position) noexcept
    : Displacement(position.Value()) {}

inline Position Displacement::operator+(
    const Position& position) const noexcept {
  return Position{value_ + position.Value()};
}

inline Position Displacement::operator-(
    const Position& position) const noexcept {
  return Position{value_ - position.Value()};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Position> {
  size_t operator()(const PhQ::Position& position) const {
    return hash<PhQ::Value::Vector>()(position.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_POSITION_HPP
