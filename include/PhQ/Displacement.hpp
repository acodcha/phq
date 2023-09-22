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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DISPLACEMENT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DISPLACEMENT_HPP

#include "Angle.hpp"
#include "DimensionalVectorQuantity.hpp"
#include "Direction.hpp"
#include "Length.hpp"

namespace PhQ {

// Forward declaration for class Displacement.
class Time;

// Forward declaration for class Displacement.
class Frequency;

// Forward declaration for class Displacement.
class Position;

// Forward declaration for class Displacement.
class Velocity;

// Displacement vector. Not to be confused with position vector.
class Displacement : public DimensionalVectorQuantity<Unit::Length> {
public:
  constexpr Displacement() : DimensionalVectorQuantity<Unit::Length>() {}

  Displacement(const Value::Vector& value, const Unit::Length unit)
    : DimensionalVectorQuantity<Unit::Length>(value, unit) {}

  constexpr Displacement(const Length& length, const Direction& direction)
    : Displacement(length.Value() * direction.Value()) {}

  constexpr Displacement(const Velocity& velocity, const Time& time);

  constexpr Displacement(const Velocity& velocity, const Frequency& frequency);

  explicit constexpr Displacement(const Position& position);

  static constexpr Displacement Zero() {
    return Displacement{Value::Vector::Zero()};
  }

  template <Unit::Length Unit>
  static constexpr Displacement Create(const Value::Vector& value) {
    return Displacement{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  Length Magnitude() const {
    return {*this};
  }

  PhQ::Angle Angle(const Displacement& displacement) const {
    return {*this, displacement};
  }

  constexpr Position operator+(const Position& position) const;

  constexpr Displacement operator+(const Displacement& displacement) const {
    return Displacement{value_ + displacement.value_};
  }

  constexpr Position operator-(const Position& position) const;

  constexpr Displacement operator-(const Displacement& displacement) const {
    return Displacement{value_ - displacement.value_};
  }

  constexpr Displacement operator*(const double number) const {
    return Displacement{value_ * number};
  }

  constexpr Velocity operator*(const Frequency& frequency) const;

  constexpr Displacement operator/(const double number) const {
    return Displacement{value_ / number};
  }

  constexpr Velocity operator/(const Time& time) const;

  constexpr void operator+=(const Displacement& displacement) noexcept {
    value_ += displacement.value_;
  }

  constexpr void operator-=(const Displacement& displacement) noexcept {
    value_ -= displacement.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Displacement(const Value::Vector& value)
    : DimensionalVectorQuantity<Unit::Length>(value) {}

  friend class Position;
};

inline constexpr bool operator==(
    const Displacement& left, const Displacement& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Displacement& left, const Displacement& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Displacement& left, const Displacement& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Displacement& left, const Displacement& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Displacement& left, const Displacement& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Displacement& left, const Displacement& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const Displacement& displacement) {
  stream << displacement.Print();
  return stream;
}

inline constexpr Displacement operator*(
    const double number, const Displacement& displacement) {
  return displacement * number;
}

inline Direction::Direction(const Displacement& displacement)
  : Direction(displacement.Value()) {}

inline Angle::Angle(
    const Displacement& displacement1, const Displacement& displacement2)
  : Angle(displacement1.Value(), displacement2.Value()) {}

inline Length::Length(const Displacement& displacement)
  : Length(displacement.Value().Magnitude()) {}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Displacement> {
  inline size_t operator()(const PhQ::Displacement& displacement) const {
    return hash<PhQ::Value::Vector>()(displacement.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DISPLACEMENT_HPP
