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

/// \brief Planar position vector in the XY plane. Not to be confused with the planar displacement
/// vector in the XY plane. See also PhQ::PlanarDisplacement.
template <typename Number = double>
class PlanarPosition : public DimensionalPlanarVector<Unit::Length, Number> {
public:
  /// \brief Default constructor. Constructs a planar position vector with an uninitialized value.
  PlanarPosition() = default;

  /// \brief Constructor. Constructs a planar position vector with a given value expressed in a
  /// given length unit.
  PlanarPosition(const PlanarVector<Number>& value, const Unit::Length unit)
    : DimensionalPlanarVector<Unit::Length, Number>(value, unit) {}

  /// \brief Constructor. Constructs a planar position vector from a given length and planar
  /// direction.
  constexpr PlanarPosition(
      const Length<Number>& length, const PlanarDirection<Number>& planar_direction)
    : PlanarPosition<Number>(length.Value() * planar_direction.Value()) {}

  /// \brief Constructor. Constructs a planar position vector from a given planar displacement
  /// vector from the origin.
  explicit constexpr PlanarPosition(const PlanarDisplacement<Number>& planar_displacement)
    : PlanarPosition<Number>(planar_displacement.Value()) {}

  /// \brief Destructor. Destroys this planar position vector.
  ~PlanarPosition() noexcept = default;

  /// \brief Copy constructor. Constructs a planar position vector by copying another one.
  constexpr PlanarPosition(const PlanarPosition<Number>& other) = default;

  /// \brief Copy constructor. Constructs a planar position by copying another one.
  template <typename OtherNumber>
  explicit constexpr PlanarPosition(const PlanarPosition<OtherNumber>& other)
    : PlanarPosition(static_cast<PlanarVector<Number>>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar position vector by moving another one.
  constexpr PlanarPosition(PlanarPosition<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this planar position vector by copying another one.
  constexpr PlanarPosition<Number>& operator=(const PlanarPosition<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this planar position by copying another one.
  template <typename OtherNumber>
  constexpr PlanarPosition<Number>& operator=(const PlanarPosition<OtherNumber>& other) {
    this->value = static_cast<PlanarVector<Number>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this planar position vector by moving another one.
  constexpr PlanarPosition<Number>& operator=(PlanarPosition<Number>&& other) noexcept = default;

  /// \brief Statically creates a planar position vector of zero.
  static constexpr PlanarPosition<Number> Zero() {
    return PlanarPosition<Number>{PlanarVector<Number>::Zero()};
  }

  /// \brief Statically creates a planar position vector from the given x and y Cartesian components
  /// expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr PlanarPosition<Number> Create(const Number x, const Number y) {
    return PlanarPosition<Number>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(PlanarVector<Number>{x, y})};
  }

  /// \brief Statically creates a planar position vector from the given x and y Cartesian components
  /// expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr PlanarPosition<Number> Create(const std::array<Number, 2>& x_y) {
    return PlanarPosition<Number>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(PlanarVector<Number>{x_y})};
  }

  /// \brief Statically creates a planar position vector with a given value expressed in a given
  /// length unit.
  template <Unit::Length Unit>
  static constexpr PlanarPosition<Number> Create(const PlanarVector<Number>& value) {
    return PlanarPosition<Number>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  /// \brief Returns the x Cartesian component of this planar position vector.
  [[nodiscard]] constexpr Length<Number> x() const noexcept {
    return Length<Number>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this planar position vector.
  [[nodiscard]] constexpr Length<Number> y() const noexcept {
    return Length<Number>{this->value.y()};
  }

  /// \brief Returns the magnitude of this planar position vector.
  [[nodiscard]] Length<Number> Magnitude() const {
    return Length<Number>{this->value.Magnitude()};
  }

  /// \brief Returns the planar direction of this planar position vector.
  [[nodiscard]] PhQ::PlanarDirection<Number> PlanarDirection() const {
    return this->value.PlanarDirection();
  }

  /// \brief Returns the angle between this planar position vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const PlanarPosition<Number>& planar_position) const {
    return PhQ::Angle<Number>{*this, planar_position};
  }

  constexpr PlanarPosition<Number> operator+(const PlanarPosition<Number>& planar_position) const {
    return PlanarPosition<Number>{this->value + planar_position.value};
  }

  constexpr PlanarPosition<Number> operator+(
      const PlanarDisplacement<Number>& planar_displacement) const {
    return PlanarPosition<Number>{this->value + planar_displacement.Value()};
  }

  constexpr PlanarDisplacement<Number> operator-(
      const PlanarPosition<Number>& planar_position) const {
    return PlanarDisplacement<Number>{this->value - planar_position.value};
  }

  constexpr PlanarPosition<Number> operator-(
      const PlanarDisplacement<Number>& planar_displacement) const {
    return PlanarPosition<Number>{this->value - planar_displacement.Value()};
  }

  constexpr PlanarPosition<Number> operator*(const Number number) const {
    return PlanarPosition<Number>{this->value * number};
  }

  constexpr PlanarPosition<Number> operator/(const Number number) const {
    return PlanarPosition<Number>{this->value / number};
  }

  constexpr void operator+=(const PlanarPosition<Number>& planar_position) noexcept {
    this->value += planar_position.value;
  }

  constexpr void operator+=(const PlanarDisplacement<Number>& planar_displacement) noexcept {
    this->value += planar_displacement.Value();
  }

  constexpr void operator-=(const PlanarPosition<Number>& planar_position) noexcept {
    this->value -= planar_position.value;
  }

  constexpr void operator-=(const PlanarDisplacement<Number>& planar_displacement) noexcept {
    this->value -= planar_displacement.Value();
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a planar position vector with a given value expressed in the
  /// standard length unit.
  explicit constexpr PlanarPosition(const PlanarVector<Number>& value)
    : DimensionalPlanarVector<Unit::Length, Number>(value) {}

  template <typename OtherNumber>
  friend class PlanarDisplacement;
};

template <typename Number>
inline constexpr bool operator==(
    const PlanarPosition<Number>& left, const PlanarPosition<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const PlanarPosition<Number>& left, const PlanarPosition<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const PlanarPosition<Number>& left, const PlanarPosition<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const PlanarPosition<Number>& left, const PlanarPosition<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const PlanarPosition<Number>& left, const PlanarPosition<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const PlanarPosition<Number>& left, const PlanarPosition<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const PlanarPosition<Number>& planar_position) {
  stream << planar_position.Print();
  return stream;
}

template <typename Number>
inline constexpr PlanarPosition<Number> operator*(
    const Number number, const PlanarPosition<Number>& planar_position) {
  return planar_position * number;
}

template <typename Number>
inline PlanarDirection<Number>::PlanarDirection(const PlanarPosition<Number>& planar_position)
  : PlanarDirection<Number>(planar_position.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(const PlanarPosition<Number>& planar_position_1,
                            const PlanarPosition<Number>& planar_position_2)
  : Angle<Number>(planar_position_1.Value(), planar_position_2.Value()) {}

template <typename Number>
inline constexpr PlanarDisplacement<Number>::PlanarDisplacement(
    const PlanarPosition<Number>& planar_position)
  : PlanarDisplacement<Number>(planar_position.Value()) {}

template <typename Number>
inline constexpr PlanarPosition<Number> PlanarDisplacement<Number>::operator+(
    const PlanarPosition<Number>& planar_position) const {
  return PlanarPosition<Number>{this->value + planar_position.Value()};
}

template <typename Number>
inline constexpr PlanarPosition<Number> PlanarDisplacement<Number>::operator-(
    const PlanarPosition<Number>& planar_position) const {
  return PlanarPosition<Number>{this->value - planar_position.Value()};
}

template <typename Number>
inline constexpr PlanarPosition<Number> PlanarDirection<Number>::operator*(
    const Length<Number>& length) const {
  return PlanarPosition<Number>{length, *this};
}

template <typename Number>
inline constexpr PlanarPosition<Number> Length<Number>::operator*(
    const PlanarDirection<Number>& planar_direction) const {
  return PlanarPosition<Number>{*this, planar_direction};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::PlanarPosition<Number>> {
  inline size_t operator()(const PhQ::PlanarPosition<Number>& planar_position) const {
    return hash<PhQ::PlanarVector<Number>>()(planar_position.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_POSITION_HPP
