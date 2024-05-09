// Copyright 2020-2024 Alexandre Coderre-Chabot
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

#ifndef PHQ_POSITION_HPP
#define PHQ_POSITION_HPP

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
template <typename Number = double>
class Position : public DimensionalVector<Unit::Length, Number> {
public:
  // Default constructor. Constructs a position vector with an uninitialized value.
  Position() = default;

  // Constructor. Constructs a position vector with a given value expressed in a given length unit.
  Position(const Vector<Number>& value, const Unit::Length unit)
    : DimensionalVector<Unit::Length, Number>(value, unit) {}

  // Constructor. Constructs a position vector from a given length and direction.
  constexpr Position(const Length<Number>& length, const Direction<Number>& direction)
    : Position<Number>(length.Value() * direction.Value()) {}

  // Constructor. Constructs a position vector from a given displacement vector from the origin.
  explicit constexpr Position(const Displacement<Number>& displacement)
    : Position<Number>(displacement.Value()) {}

  // Destructor. Destroys this position vector.
  ~Position() noexcept = default;

  // Copy constructor. Constructs a position vector by copying another one.
  constexpr Position(const Position<Number>& other) = default;

  // Copy constructor. Constructs a position by copying another one.
  template <typename OtherNumber>
  explicit constexpr Position(const Position<OtherNumber>& other)
    : value(static_cast<Vector<Number>>(other.Value())) {}

  // Move constructor. Constructs a position vector by moving another one.
  constexpr Position(Position<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this position vector by copying another one.
  constexpr Position<Number>& operator=(const Position<Number>& other) = default;

  // Copy assignment operator. Assigns this position by copying another one.
  template <typename OtherNumber>
  constexpr Position<Number>& operator=(const Position<OtherNumber>& other) {
    value = static_cast<Vector<Number>>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this position vector by moving another one.
  constexpr Position<Number>& operator=(Position<Number>&& other) noexcept = default;

  // Statically creates a position vector of zero.
  static constexpr Position<Number> Zero() {
    return Position<Number>{Vector<Number>::Zero()};
  }

  // Statically creates a position vector from the given x, y, and z Cartesian components expressed
  // in a given length unit.
  template <Unit::Length Unit>
  static constexpr Position<Number> Create(const Number x, const Number y, const Number z) {
    return Position<Number>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(Vector<Number>{x, y, z})};
  }

  // Statically creates a position vector from the given x, y, and z Cartesian components expressed
  // in a given length unit.
  template <Unit::Length Unit>
  static constexpr Position<Number> Create(const std::array<Number, 3>& x_y_z) {
    return Position<Number>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(Vector<Number>{x_y_z})};
  }

  // Statically creates a position vector with a given value expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr Position<Number> Create(const Vector<Number>& value) {
    return Position<Number>{StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  // Returns the x Cartesian component of this position vector.
  [[nodiscard]] constexpr Length<Number> x() const noexcept {
    return Length<Number>{value.x()};
  }

  // Returns the y Cartesian component of this position vector.
  [[nodiscard]] constexpr Length<Number> y() const noexcept {
    return Length<Number>{value.y()};
  }

  // Returns the z Cartesian component of this position vector.
  [[nodiscard]] constexpr Length<Number> z() const noexcept {
    return Length<Number>{value.z()};
  }

  // Returns the magnitude of this position vector.
  [[nodiscard]] Length<Number> Magnitude() const {
    return Length<Number>{value.Magnitude()};
  }

  // Returns the direction of this position vector.
  [[nodiscard]] PhQ::Direction<Number> Direction() const {
    return value.Direction();
  }

  // Returns the angle between this position vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const Position<Number>& position) const {
    return PhQ::Angle<Number>{*this, position};
  }

  constexpr Position<Number> operator+(const Position<Number>& position) const {
    return Position<Number>{value + position.value};
  }

  constexpr Position<Number> operator+(const Displacement<Number>& displacement) const {
    return Position<Number>{value + displacement.Value()};
  }

  constexpr Displacement<Number> operator-(const Position<Number>& position) const {
    return Displacement<Number>{value - position.value};
  }

  constexpr Position<Number> operator-(const Displacement<Number>& displacement) const {
    return Position<Number>{value - displacement.Value()};
  }

  constexpr Position<Number> operator*(const Number number) const {
    return Position<Number>{value * number};
  }

  constexpr Position<Number> operator/(const Number number) const {
    return Position<Number>{value / number};
  }

  constexpr void operator+=(const Position<Number>& position) noexcept {
    value += position.value;
  }

  constexpr void operator+=(const Displacement<Number>& displacement) noexcept {
    value += displacement.Value();
  }

  constexpr void operator-=(const Position<Number>& position) noexcept {
    value -= position.value;
  }

  constexpr void operator-=(const Displacement<Number>& displacement) noexcept {
    value -= displacement.Value();
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a position vector with a given value expressed in the standard length
  // unit.
  explicit constexpr Position(const Vector<Number>& value)
    : DimensionalVector<Unit::Length, Number>(value) {}

  template <typename OtherNumber>
  friend class Displacement;
};

template <typename Number>
inline constexpr bool operator==(
    const Position<Number>& left, const Position<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const Position<Number>& left, const Position<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const Position<Number>& left, const Position<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const Position<Number>& left, const Position<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const Position<Number>& left, const Position<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const Position<Number>& left, const Position<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Position<Number>& position) {
  stream << position.Print();
  return stream;
}

template <typename Number>
inline constexpr Position<Number> operator*(const Number number, const Position<Number>& position) {
  return position * number;
}

template <typename Number>
inline Direction<Number>::Direction(const Position<Number>& position)
  : Direction<Number>(position.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(const Position<Number>& position1, const Position<Number>& position2)
  : Angle<Number>(position1.Value(), position2.Value()) {}

template <typename Number>
inline constexpr Displacement<Number>::Displacement(const Position<Number>& position)
  : Displacement<Number>(position.Value()) {}

template <typename Number>
inline constexpr Position<Number> Displacement<Number>::operator+(
    const Position<Number>& position) const {
  return Position<Number>{value + position.Value()};
}

template <typename Number>
inline constexpr Position<Number> Displacement<Number>::operator-(
    const Position<Number>& position) const {
  return Position<Number>{value - position.Value()};
}

template <typename Number>
inline constexpr Position<Number> Direction<Number>::operator*(const Length<Number>& length) const {
  return Position<Number>{length, *this};
}

template <typename Number>
inline constexpr Position<Number> Length<Number>::operator*(
    const Direction<Number>& direction) const {
  return Position<Number>{*this, direction};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Position<Number>> {
  inline size_t operator()(const PhQ::Position<Number>& position) const {
    return hash<PhQ::Vector<Number>>()(position.Value());
  }
};

}  // namespace std

#endif  // PHQ_POSITION_HPP
