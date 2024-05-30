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

/// \brief Three-dimensional Euclidean position vector. Contains three components in Cartesian
/// coordinates: x, y, and z. Position is not to be confused with displacement; for a
/// three-dimensional Euclidean displacement vector, see PhQ::Displacement. For a two-dimensional
/// Euclidean position vector in the XY plane, see PhQ::PlanarPosition. For scalar position
/// components or for the magnitude of a position vector, see PhQ::Length.
template <typename NumericType = double>
class Position : public DimensionalVector<Unit::Length, NumericType> {
public:
  /// \brief Default constructor. Constructs a position vector with an uninitialized value.
  Position() = default;

  /// \brief Constructor. Constructs a position vector with a given value expressed in a given
  /// length unit.
  Position(const Vector<NumericType>& value, const Unit::Length unit)
    : DimensionalVector<Unit::Length, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a position vector from a given set of length components.
  Position(const Length<NumericType>& x, const Length<NumericType>& y, const Length<NumericType>& z)
    : Position<NumericType>({x.Value(), y.Value(), z.Value()}) {}

  /// \brief Constructor. Constructs a position vector from a given length and direction.
  constexpr Position(const Length<NumericType>& length, const Direction<NumericType>& direction)
    : Position<NumericType>(length.Value() * direction.Value()) {}

  /// \brief Constructor. Constructs a position vector from a given planar position vector in the XY
  /// plane. This position vector's z-component is initialized to zero.
  explicit constexpr Position(const PlanarPosition<NumericType>& planar_force)
    : Position<NumericType>(Vector<NumericType>{planar_force.Value()}) {}

  /// \brief Constructor. Constructs a position vector from a given displacement vector from the
  /// origin.
  explicit constexpr Position(const Displacement<NumericType>& displacement)
    : Position<NumericType>(displacement.Value()) {}

  /// \brief Destructor. Destroys this position vector.
  ~Position() noexcept = default;

  /// \brief Copy constructor. Constructs a position vector by copying another one.
  constexpr Position(const Position<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a position by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Position(const Position<OtherNumericType>& other)
    : Position(static_cast<Vector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a position vector by moving another one.
  constexpr Position(Position<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this position vector by copying another one.
  constexpr Position<NumericType>& operator=(const Position<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this position by copying another one.
  template <typename OtherNumericType>
  constexpr Position<NumericType>& operator=(const Position<OtherNumericType>& other) {
    this->value = static_cast<Vector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this position vector by moving another one.
  constexpr Position<NumericType>& operator=(Position<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a position vector of zero.
  static constexpr Position<NumericType> Zero() {
    return Position<NumericType>{Vector<NumericType>::Zero()};
  }

  /// \brief Statically creates a position vector from the given x, y, and z Cartesian components
  /// expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr Position<NumericType> Create(
      const NumericType x, const NumericType y, const NumericType z) {
    return Position<NumericType>{StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(
        Vector<NumericType>{x, y, z})};
  }

  /// \brief Statically creates a position vector from the given x, y, and z Cartesian components
  /// expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr Position<NumericType> Create(const std::array<NumericType, 3>& x_y_z) {
    return Position<NumericType>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(Vector<NumericType>{x_y_z})};
  }

  /// \brief Statically creates a position vector with a given value expressed in a given length
  /// unit.
  template <Unit::Length Unit>
  static constexpr Position<NumericType> Create(const Vector<NumericType>& value) {
    return Position<NumericType>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  /// \brief Returns the x Cartesian component of this position vector.
  [[nodiscard]] constexpr Length<NumericType> x() const noexcept {
    return Length<NumericType>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this position vector.
  [[nodiscard]] constexpr Length<NumericType> y() const noexcept {
    return Length<NumericType>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this position vector.
  [[nodiscard]] constexpr Length<NumericType> z() const noexcept {
    return Length<NumericType>{this->value.z()};
  }

  /// \brief Returns the magnitude of this position vector.
  [[nodiscard]] Length<NumericType> Magnitude() const {
    return Length<NumericType>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this position vector.
  [[nodiscard]] PhQ::Direction<NumericType> Direction() const {
    return this->value.Direction();
  }

  /// \brief Returns the angle between this position vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(const Position<NumericType>& position) const {
    return PhQ::Angle<NumericType>{*this, position};
  }

  constexpr Position<NumericType> operator+(const Position<NumericType>& position) const {
    return Position<NumericType>{this->value + position.value};
  }

  constexpr Position<NumericType> operator+(const Displacement<NumericType>& displacement) const {
    return Position<NumericType>{this->value + displacement.Value()};
  }

  constexpr Displacement<NumericType> operator-(const Position<NumericType>& position) const {
    return Displacement<NumericType>{this->value - position.value};
  }

  constexpr Position<NumericType> operator-(const Displacement<NumericType>& displacement) const {
    return Position<NumericType>{this->value - displacement.Value()};
  }

  constexpr Position<NumericType> operator*(const NumericType number) const {
    return Position<NumericType>{this->value * number};
  }

  constexpr Position<NumericType> operator/(const NumericType number) const {
    return Position<NumericType>{this->value / number};
  }

  constexpr void operator+=(const Position<NumericType>& position) noexcept {
    this->value += position.value;
  }

  constexpr void operator+=(const Displacement<NumericType>& displacement) noexcept {
    this->value += displacement.Value();
  }

  constexpr void operator-=(const Position<NumericType>& position) noexcept {
    this->value -= position.value;
  }

  constexpr void operator-=(const Displacement<NumericType>& displacement) noexcept {
    this->value -= displacement.Value();
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a position vector with a given value expressed in the standard
  /// length unit.
  explicit constexpr Position(const Vector<NumericType>& value)
    : DimensionalVector<Unit::Length, NumericType>(value) {}

  template <typename OtherNumericType>
  friend class Displacement;
};

template <typename NumericType>
inline constexpr bool operator==(
    const Position<NumericType>& left, const Position<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Position<NumericType>& left, const Position<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Position<NumericType>& left, const Position<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Position<NumericType>& left, const Position<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Position<NumericType>& left, const Position<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Position<NumericType>& left, const Position<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Position<NumericType>& position) {
  stream << position.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Position<NumericType> operator*(
    const NumericType number, const Position<NumericType>& position) {
  return position * number;
}

template <typename NumericType>
inline Direction<NumericType>::Direction(const Position<NumericType>& position)
  : Direction<NumericType>(position.Value()) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(
    const Position<NumericType>& position1, const Position<NumericType>& position2)
  : Angle<NumericType>(position1.Value(), position2.Value()) {}

template <typename NumericType>
inline constexpr Displacement<NumericType>::Displacement(const Position<NumericType>& position)
  : Displacement<NumericType>(position.Value()) {}

template <typename NumericType>
inline constexpr Position<NumericType> Displacement<NumericType>::operator+(
    const Position<NumericType>& position) const {
  return Position<NumericType>{this->value + position.Value()};
}

template <typename NumericType>
inline constexpr Position<NumericType> Displacement<NumericType>::operator-(
    const Position<NumericType>& position) const {
  return Position<NumericType>{this->value - position.Value()};
}

template <typename NumericType>
inline constexpr Position<NumericType> Direction<NumericType>::operator*(
    const Length<NumericType>& length) const {
  return Position<NumericType>{length, *this};
}

template <typename NumericType>
inline constexpr Position<NumericType> Length<NumericType>::operator*(
    const Direction<NumericType>& direction) const {
  return Position<NumericType>{*this, direction};
}

template <typename NumericType>
inline constexpr PlanarPosition<NumericType>::PlanarPosition(const Position<NumericType>& position)
  : PlanarPosition(PlanarVector<NumericType>{position.Value()}) {}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Position<NumericType>> {
  inline size_t operator()(const PhQ::Position<NumericType>& position) const {
    return hash<PhQ::Vector<NumericType>>()(position.Value());
  }
};

}  // namespace std

#endif  // PHQ_POSITION_HPP
