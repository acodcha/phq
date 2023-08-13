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
#include "Direction.hpp"
#include "Length.hpp"
#include "Quantity/DimensionalVector.hpp"

namespace PhQ {

// Forward declarations.
class Time;
class Frequency;
class Position;
class Velocity;

// Displacement vector. Not to be confused with position vector.
class Displacement : public DimensionalVectorQuantity<Unit::Length> {
public:
  constexpr Displacement() noexcept
    : DimensionalVectorQuantity<Unit::Length>() {}

  Displacement(const Value::Vector& value, const Unit::Length unit) noexcept
    : DimensionalVectorQuantity<Unit::Length>(value, unit) {}

  constexpr Displacement(
      const Length& length, const Direction& direction) noexcept
    : Displacement(length.Value() * direction.Value()) {}

  constexpr Displacement(const Velocity& velocity, const Time& time) noexcept;

  constexpr Displacement(
      const Velocity& velocity, const Frequency& frequency) noexcept;

  explicit constexpr Displacement(const Position& position) noexcept;

  static constexpr Displacement Zero() noexcept {
    return Displacement{Value::Vector::Zero()};
  }

  template<Unit::Length Unit>
  static constexpr Displacement Create(const Value::Vector& value) noexcept {
    return Displacement{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  inline constexpr Length Magnitude() const noexcept { return {*this}; }

  inline PhQ::Angle Angle(const Displacement& displacement) const noexcept {
    return {*this, displacement};
  }

  inline constexpr Position operator+(const Position& position) const noexcept;

  inline constexpr Displacement operator+(
      const Displacement& displacement) const noexcept {
    return Displacement{value_ + displacement.value_};
  }

  inline constexpr Position operator-(const Position& position) const noexcept;

  inline constexpr Displacement operator-(
      const Displacement& displacement) const noexcept {
    return Displacement{value_ - displacement.value_};
  }

  inline constexpr Displacement operator*(const double number) const noexcept {
    return Displacement{value_ * number};
  }

  inline constexpr Velocity operator*(
      const Frequency& frequency) const noexcept;

  inline constexpr Displacement operator/(const double number) const noexcept {
    return Displacement{value_ / number};
  }

  inline constexpr Velocity operator/(const Time& time) const noexcept;

  inline constexpr void operator+=(const Displacement& displacement) noexcept {
    value_ += displacement.value_;
  }

  inline constexpr void operator-=(const Displacement& displacement) noexcept {
    value_ -= displacement.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr Displacement(const Value::Vector& value) noexcept
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
    std::ostream& stream, const Displacement& displacement) noexcept {
  stream << displacement.Print();
  return stream;
}

inline constexpr Displacement operator*(
    const double number, const Displacement& displacement) noexcept {
  return displacement * number;
}

inline constexpr Direction::Direction(const Displacement& displacement) noexcept
  : Direction(displacement.Value()) {}

inline Angle::Angle(const Displacement& displacement1,
                    const Displacement& displacement2) noexcept
  : Angle(displacement1.Value(), displacement2.Value()) {}

inline constexpr Length::Length(const Displacement& displacement) noexcept
  : Length(displacement.Value().Magnitude()) {}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::Displacement> {
  size_t operator()(const PhQ::Displacement& displacement) const {
    return hash<PhQ::Value::Vector>()(displacement.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DISPLACEMENT_HPP
