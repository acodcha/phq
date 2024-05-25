// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
#include "PlanarPosition.hpp"
#include "Unit/Length.hpp"
#include "Vector.hpp"

namespace PhQ {

/// \brief Position vector. Not to be confused with the displacement vector. See also
/// PhQ::Displacement.
template <typename Number = double>
class Position : public DimensionalVector<Unit::Length, Number> {
public:
  /// \brief Default constructor. Constructs a position vector with an uninitialized value.
  Position() = default;

  /// \brief Constructor. Constructs a position vector with a given value expressed in a given
  /// length unit.
  Position(const Vector<Number>& value, const Unit::Length unit)
    : DimensionalVector<Unit::Length, Number>(value, unit) {}

  /// \brief Constructor. Constructs a position vector from a given length and direction.
  constexpr Position(const Length<Number>& length, const Direction<Number>& direction)
    : Position<Number>(length.Value() * direction.Value()) {}

  /// \brief Constructor. Constructs a position vector from a given planar position vector in the XY
  /// plane. This position vector's z-component is initialized to zero.
  explicit constexpr Position(const PlanarPosition<Number>& planar_force)
    : Position<Number>(Vector<Number>{planar_force.Value()}) {}

  /// \brief Constructor. Constructs a position vector from a given displacement vector from the
  /// origin.
  explicit constexpr Position(const Displacement<Number>& displacement)
    : Position<Number>(displacement.Value()) {}

  /// \brief Destructor. Destroys this position vector.
  ~Position() noexcept = default;

  /// \brief Copy constructor. Constructs a position vector by copying another one.
  constexpr Position(const Position<Number>& other) = default;

  /// \brief Copy constructor. Constructs a position by copying another one.
  template <typename OtherNumber>
  explicit constexpr Position(const Position<OtherNumber>& other)
    : Position(static_cast<Vector<Number>>(other.Value())) {}

  /// \brief Move constructor. Constructs a position vector by moving another one.
  constexpr Position(Position<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this position vector by copying another one.
  constexpr Position<Number>& operator=(const Position<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this position by copying another one.
  template <typename OtherNumber>
  constexpr Position<Number>& operator=(const Position<OtherNumber>& other) {
    this->value = static_cast<Vector<Number>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this position vector by moving another one.
  constexpr Position<Number>& operator=(Position<Number>&& other) noexcept = default;

  /// \brief Statically creates a position vector of zero.
  static constexpr Position<Number> Zero() {
    return Position<Number>{Vector<Number>::Zero()};
  }

  /// \brief Statically creates a position vector from the given x, y, and z Cartesian components
  /// expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr Position<Number> Create(const Number x, const Number y, const Number z) {
    return Position<Number>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(Vector<Number>{x, y, z})};
  }

  /// \brief Statically creates a position vector from the given x, y, and z Cartesian components
  /// expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr Position<Number> Create(const std::array<Number, 3>& x_y_z) {
    return Position<Number>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(Vector<Number>{x_y_z})};
  }

  /// \brief Statically creates a position vector with a given value expressed in a given length
  /// unit.
  template <Unit::Length Unit>
  static constexpr Position<Number> Create(const Vector<Number>& value) {
    return Position<Number>{StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  /// \brief Returns the x Cartesian component of this position vector.
  [[nodiscard]] constexpr Length<Number> x() const noexcept {
    return Length<Number>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this position vector.
  [[nodiscard]] constexpr Length<Number> y() const noexcept {
    return Length<Number>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this position vector.
  [[nodiscard]] constexpr Length<Number> z() const noexcept {
    return Length<Number>{this->value.z()};
  }

  /// \brief Returns the magnitude of this position vector.
  [[nodiscard]] Length<Number> Magnitude() const {
    return Length<Number>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this position vector.
  [[nodiscard]] PhQ::Direction<Number> Direction() const {
    return this->value.Direction();
  }

  /// \brief Returns the angle between this position vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const Position<Number>& position) const {
    return PhQ::Angle<Number>{*this, position};
  }

  constexpr Position<Number> operator+(const Position<Number>& position) const {
    return Position<Number>{this->value + position.value};
  }

  constexpr Position<Number> operator+(const Displacement<Number>& displacement) const {
    return Position<Number>{this->value + displacement.Value()};
  }

  constexpr Displacement<Number> operator-(const Position<Number>& position) const {
    return Displacement<Number>{this->value - position.value};
  }

  constexpr Position<Number> operator-(const Displacement<Number>& displacement) const {
    return Position<Number>{this->value - displacement.Value()};
  }

  constexpr Position<Number> operator*(const Number number) const {
    return Position<Number>{this->value * number};
  }

  constexpr Position<Number> operator/(const Number number) const {
    return Position<Number>{this->value / number};
  }

  constexpr void operator+=(const Position<Number>& position) noexcept {
    this->value += position.value;
  }

  constexpr void operator+=(const Displacement<Number>& displacement) noexcept {
    this->value += displacement.Value();
  }

  constexpr void operator-=(const Position<Number>& position) noexcept {
    this->value -= position.value;
  }

  constexpr void operator-=(const Displacement<Number>& displacement) noexcept {
    this->value -= displacement.Value();
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a position vector with a given value expressed in the standard
  /// length unit.
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
  return Position<Number>{this->value + position.Value()};
}

template <typename Number>
inline constexpr Position<Number> Displacement<Number>::operator-(
    const Position<Number>& position) const {
  return Position<Number>{this->value - position.Value()};
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

template <typename Number>
inline constexpr PlanarPosition<Number>::PlanarPosition(const Position<Number>& position)
  : PlanarPosition(PlanarVector<Number>{position.Value()}) {}

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
