// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_POSITION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_POSITION_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalVector.hpp"
#include "Direction.hpp"
#include "Displacement.hpp"
#include "Length.hpp"
#include "Unit/Length.hpp"
#include "Vector.hpp"

namespace PhQ {

// Position vector. Not to be confused with displacement vector.
class Position : public DimensionalVector<Unit::Length> {
public:
  // Default constructor. Constructs a position with an uninitialized value.
  Position() = default;

  // Constructor. Constructs a position with a given value expressed in a given length unit.
  Position(const Vector& value, const Unit::Length unit)
    : DimensionalVector<Unit::Length>(value, unit) {}

  // Constructor. Constructs a position from a given length and direction.
  constexpr Position(const Length& length, const Direction& direction)
    : Position(length.Value() * direction.Value()) {}

  // Constructor. Constructs a position from a given displacement from the origin.
  explicit constexpr Position(const Displacement& displacement) : Position(displacement.Value()) {}

  // Destructor. Destroys this position.
  ~Position() noexcept = default;

  // Copy constructor. Constructs a position by copying another one.
  constexpr Position(const Position& other) = default;

  // Move constructor. Constructs a position by moving another one.
  constexpr Position(Position&& other) noexcept = default;

  // Copy assignment operator. Assigns this position by copying another one.
  constexpr Position& operator=(const Position& other) = default;

  // Move assignment operator. Assigns this position by moving another one.
  constexpr Position& operator=(Position&& other) noexcept = default;

  // Statically creates a position of zero.
  static constexpr Position Zero() {
    return Position{Vector::Zero()};
  }

  // Statically creates a position from the given x, y, and z Cartesian components expressed in a
  // given length unit.
  template <Unit::Length Unit>
  static constexpr Position Create(const double x, const double y, const double z) {
    return Position{StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(Vector{x, y, z})};
  }

  // Statically creates a position from the given x, y, and z Cartesian components expressed in a
  // given length unit.
  template <Unit::Length Unit>
  static constexpr Position Create(const std::array<double, 3>& x_y_z) {
    return Position{StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(Vector{x_y_z})};
  }

  // Statically creates a position with a given value expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr Position Create(const Vector& value) {
    return Position{StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  // Returns the magnitude of this position.
  [[nodiscard]] Length Magnitude() const {
    return Length{value_.Magnitude()};
  }

  // Returns the angle between this position and another one.
  [[nodiscard]] PhQ::Angle Angle(const Position& position) const {
    return {*this, position};
  }

  constexpr Position operator+(const Position& position) const {
    return Position{value_ + position.value_};
  }

  constexpr Position operator+(const Displacement& displacement) const {
    return Position{value_ + displacement.Value()};
  }

  constexpr Displacement operator-(const Position& position) const {
    return Displacement{value_ - position.value_};
  }

  constexpr Position operator-(const Displacement& displacement) const {
    return Position{value_ - displacement.Value()};
  }

  constexpr Position operator*(const double number) const {
    return Position{value_ * number};
  }

  constexpr Position operator/(const double number) const {
    return Position{value_ / number};
  }

  constexpr void operator+=(const Position& position) noexcept {
    value_ += position.value_;
  }

  constexpr void operator+=(const Displacement& displacement) noexcept {
    value_ += displacement.Value();
  }

  constexpr void operator-=(const Position& position) noexcept {
    value_ -= position.value_;
  }

  constexpr void operator-=(const Displacement& displacement) noexcept {
    value_ -= displacement.Value();
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a position with a given value expressed in the standard length unit.
  explicit constexpr Position(const Vector& value) : DimensionalVector<Unit::Length>(value) {}

  friend class Displacement;
};

inline constexpr bool operator==(const Position& left, const Position& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Position& left, const Position& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Position& left, const Position& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Position& left, const Position& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Position& left, const Position& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Position& left, const Position& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Position& position) {
  stream << position.Print();
  return stream;
}

inline constexpr Position operator*(const double number, const Position& position) {
  return position * number;
}

inline Direction::Direction(const Position& position) : Direction(position.Value()) {}

inline Angle::Angle(const Position& position1, const Position& position2)
  : Angle(position1.Value(), position2.Value()) {}

inline constexpr Displacement::Displacement(const Position& position)
  : Displacement(position.Value()) {}

inline constexpr Position Displacement::operator+(const Position& position) const {
  return Position{value_ + position.Value()};
}

inline constexpr Position Displacement::operator-(const Position& position) const {
  return Position{value_ - position.Value()};
}

inline constexpr Position Direction::operator*(const Length& length) const {
  return {length, *this};
}

inline constexpr Position Length::operator*(const Direction& direction) const {
  return {*this, direction};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Position> {
  inline size_t operator()(const PhQ::Position& position) const {
    return hash<PhQ::Vector>()(position.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_POSITION_HPP
