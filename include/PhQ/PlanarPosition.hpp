// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef PHQ_PLANAR_POSITION_HPP
#define PHQ_PLANAR_POSITION_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalPlanarVector.hpp"
#include "Length.hpp"
#include "PlanarDirection.hpp"
#include "PlanarDisplacement.hpp"
#include "PlanarVector.hpp"
#include "Unit/Length.hpp"

namespace PhQ {

/// \brief Two-dimensional Euclidean position vector in the XY plane. Contains two components in
/// Cartesian coordinates: x and y. Position is not to be confused with displacement; for a
/// two-dimensional Euclidean displacement vector in the XY plane, see PhQ::PlanarDisplacement. For
/// a three-dimensional Euclidean position vector, see PhQ::Position. For scalar position components
/// or for the magnitude of a position vector, see PhQ::Length.
template <typename NumericType = double>
class PlanarPosition : public DimensionalPlanarVector<Unit::Length, NumericType> {
public:
  /// \brief Default constructor. Constructs a planar position vector with an uninitialized value.
  PlanarPosition() = default;

  /// \brief Constructor. Constructs a planar position vector with a given value expressed in a
  /// given length unit.
  PlanarPosition(const PlanarVector<NumericType>& value, const Unit::Length unit)
    : DimensionalPlanarVector<Unit::Length, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a planar position vector from a given set of length components.
  PlanarPosition(const Length<NumericType>& x, const Length<NumericType>& y)
    : PlanarPosition<NumericType>({x.Value(), y.Value()}) {}

  /// \brief Constructor. Constructs a planar position vector from a given length and planar
  /// direction.
  constexpr PlanarPosition(
      const Length<NumericType>& length, const PlanarDirection<NumericType>& planar_direction)
    : PlanarPosition<NumericType>(length.Value() * planar_direction.Value()) {}

  /// \brief Constructor. Constructs a planar position vector from a given position vector by
  /// projecting the position vector onto the XY plane.
  explicit constexpr PlanarPosition(const Position<NumericType>& position);

  /// \brief Constructor. Constructs a planar position vector from a given planar displacement
  /// vector from the origin.
  explicit constexpr PlanarPosition(const PlanarDisplacement<NumericType>& planar_displacement)
    : PlanarPosition<NumericType>(planar_displacement.Value()) {}

  /// \brief Destructor. Destroys this planar position vector.
  ~PlanarPosition() noexcept = default;

  /// \brief Copy constructor. Constructs a planar position vector by copying another one.
  constexpr PlanarPosition(const PlanarPosition<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a planar position by copying another one.
  template <typename OtherNumericType>
  explicit constexpr PlanarPosition(const PlanarPosition<OtherNumericType>& other)
    : PlanarPosition(static_cast<PlanarVector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar position vector by moving another one.
  constexpr PlanarPosition(PlanarPosition<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this planar position vector by copying another one.
  constexpr PlanarPosition<NumericType>& operator=(
      const PlanarPosition<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this planar position by copying another one.
  template <typename OtherNumericType>
  constexpr PlanarPosition<NumericType>& operator=(const PlanarPosition<OtherNumericType>& other) {
    this->value = static_cast<PlanarVector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this planar position vector by moving another one.
  constexpr PlanarPosition<NumericType>& operator=(
      PlanarPosition<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a planar position vector of zero.
  static constexpr PlanarPosition<NumericType> Zero() {
    return PlanarPosition<NumericType>{PlanarVector<NumericType>::Zero()};
  }

  /// \brief Statically creates a planar position vector from the given x and y Cartesian components
  /// expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr PlanarPosition<NumericType> Create(const NumericType x, const NumericType y) {
    return PlanarPosition<NumericType>{
        ConvertStatically<Unit::Length, Unit, Standard<Unit::Length>>(
            PlanarVector<NumericType>{x, y})};
  }

  /// \brief Statically creates a planar position vector from the given x and y Cartesian components
  /// expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr PlanarPosition<NumericType> Create(const std::array<NumericType, 2>& x_y) {
    return PlanarPosition<NumericType>{
        ConvertStatically<Unit::Length, Unit, Standard<Unit::Length>>(
            PlanarVector<NumericType>{x_y})};
  }

  /// \brief Statically creates a planar position vector with a given value expressed in a given
  /// length unit.
  template <Unit::Length Unit>
  static constexpr PlanarPosition<NumericType> Create(const PlanarVector<NumericType>& value) {
    return PlanarPosition<NumericType>{
        ConvertStatically<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  /// \brief Returns the x Cartesian component of this planar position vector.
  [[nodiscard]] constexpr Length<NumericType> x() const noexcept {
    return Length<NumericType>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this planar position vector.
  [[nodiscard]] constexpr Length<NumericType> y() const noexcept {
    return Length<NumericType>{this->value.y()};
  }

  /// \brief Returns the magnitude of this planar position vector.
  [[nodiscard]] Length<NumericType> Magnitude() const {
    return Length<NumericType>{this->value.Magnitude()};
  }

  /// \brief Returns the planar direction of this planar position vector.
  [[nodiscard]] PhQ::PlanarDirection<NumericType> PlanarDirection() const {
    return this->value.PlanarDirection();
  }

  /// \brief Returns the angle between this planar position vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(
      const PlanarPosition<NumericType>& planar_position) const {
    return PhQ::Angle<NumericType>{*this, planar_position};
  }

  constexpr PlanarPosition<NumericType> operator+(
      const PlanarPosition<NumericType>& planar_position) const {
    return PlanarPosition<NumericType>{this->value + planar_position.value};
  }

  constexpr PlanarPosition<NumericType> operator+(
      const PlanarDisplacement<NumericType>& planar_displacement) const {
    return PlanarPosition<NumericType>{this->value + planar_displacement.Value()};
  }

  constexpr PlanarDisplacement<NumericType> operator-(
      const PlanarPosition<NumericType>& planar_position) const {
    return PlanarDisplacement<NumericType>{this->value - planar_position.value};
  }

  constexpr PlanarPosition<NumericType> operator-(
      const PlanarDisplacement<NumericType>& planar_displacement) const {
    return PlanarPosition<NumericType>{this->value - planar_displacement.Value()};
  }

  constexpr PlanarPosition<NumericType> operator*(const NumericType number) const {
    return PlanarPosition<NumericType>{this->value * number};
  }

  constexpr PlanarPosition<NumericType> operator/(const NumericType number) const {
    return PlanarPosition<NumericType>{this->value / number};
  }

  constexpr void operator+=(const PlanarPosition<NumericType>& planar_position) noexcept {
    this->value += planar_position.value;
  }

  constexpr void operator+=(const PlanarDisplacement<NumericType>& planar_displacement) noexcept {
    this->value += planar_displacement.Value();
  }

  constexpr void operator-=(const PlanarPosition<NumericType>& planar_position) noexcept {
    this->value -= planar_position.value;
  }

  constexpr void operator-=(const PlanarDisplacement<NumericType>& planar_displacement) noexcept {
    this->value -= planar_displacement.Value();
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a planar position vector with a given value expressed in the
  /// standard length unit.
  explicit constexpr PlanarPosition(const PlanarVector<NumericType>& value)
    : DimensionalPlanarVector<Unit::Length, NumericType>(value) {}

  template <typename OtherNumericType>
  friend class PlanarDisplacement;
};

template <typename NumericType>
inline constexpr bool operator==(
    const PlanarPosition<NumericType>& left, const PlanarPosition<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const PlanarPosition<NumericType>& left, const PlanarPosition<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const PlanarPosition<NumericType>& left, const PlanarPosition<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const PlanarPosition<NumericType>& left, const PlanarPosition<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const PlanarPosition<NumericType>& left, const PlanarPosition<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const PlanarPosition<NumericType>& left, const PlanarPosition<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const PlanarPosition<NumericType>& planar_position) {
  stream << planar_position.Print();
  return stream;
}

template <typename NumericType>
inline constexpr PlanarPosition<NumericType> operator*(
    const NumericType number, const PlanarPosition<NumericType>& planar_position) {
  return planar_position * number;
}

template <typename NumericType>
inline PlanarDirection<NumericType>::PlanarDirection(
    const PlanarPosition<NumericType>& planar_position)
  : PlanarDirection<NumericType>(planar_position.Value()) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(const PlanarPosition<NumericType>& planar_position_1,
                                 const PlanarPosition<NumericType>& planar_position_2)
  : Angle<NumericType>(planar_position_1.Value(), planar_position_2.Value()) {}

template <typename NumericType>
inline constexpr PlanarDisplacement<NumericType>::PlanarDisplacement(
    const PlanarPosition<NumericType>& planar_position)
  : PlanarDisplacement<NumericType>(planar_position.Value()) {}

template <typename NumericType>
inline constexpr PlanarPosition<NumericType> PlanarDisplacement<NumericType>::operator+(
    const PlanarPosition<NumericType>& planar_position) const {
  return PlanarPosition<NumericType>{this->value + planar_position.Value()};
}

template <typename NumericType>
inline constexpr PlanarPosition<NumericType> PlanarDisplacement<NumericType>::operator-(
    const PlanarPosition<NumericType>& planar_position) const {
  return PlanarPosition<NumericType>{this->value - planar_position.Value()};
}

template <typename NumericType>
inline constexpr PlanarPosition<NumericType> PlanarDirection<NumericType>::operator*(
    const Length<NumericType>& length) const {
  return PlanarPosition<NumericType>{length, *this};
}

template <typename NumericType>
inline constexpr PlanarPosition<NumericType> Length<NumericType>::operator*(
    const PlanarDirection<NumericType>& planar_direction) const {
  return PlanarPosition<NumericType>{*this, planar_direction};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::PlanarPosition<NumericType>> {
  inline size_t operator()(const PhQ::PlanarPosition<NumericType>& planar_position) const {
    return hash<PhQ::PlanarVector<NumericType>>()(planar_position.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_POSITION_HPP
