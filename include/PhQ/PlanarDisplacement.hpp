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

#ifndef PHQ_PLANAR_DISPLACEMENT_HPP
#define PHQ_PLANAR_DISPLACEMENT_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalPlanarVector.hpp"
#include "Length.hpp"
#include "PlanarDirection.hpp"
#include "PlanarVector.hpp"
#include "Unit/Length.hpp"

namespace PhQ {

// Forward declaration for class PhQ::PlanarDisplacement.
template <typename Number>
class Frequency;

// Forward declaration for class PhQ::PlanarDisplacement.
template <typename Number>
class PlanarPosition;

// Forward declaration for class PhQ::PlanarDisplacement.
template <typename Number>
class PlanarVelocity;

// Forward declaration for class PhQ::PlanarDisplacement.
template <typename Number>
class Time;

/// \brief Two-dimensional Euclidean displacement vector in the XY plane. Contains two components in
/// Cartesian coordinates: x and y. Displacement is not to be confused with position; for a
/// two-dimensional Euclidean position vector in the XY plane, see PhQ::PlanarPosition. For a
/// three-dimensional Euclidean displacement vector, see PhQ::Displacement. For scalar displacement
/// components or for the magnitude of a displacement vector, see PhQ::Length.
template <typename Number = double>
class PlanarDisplacement : public DimensionalPlanarVector<Unit::Length, Number> {
public:
  /// \brief Default constructor. Constructs a planar displacement vector with an uninitialized
  /// value.
  PlanarDisplacement() = default;

  /// \brief Constructor. Constructs a planar displacement vector with a given value expressed in a
  /// given length unit.
  PlanarDisplacement(const PlanarVector<Number>& value, const Unit::Length unit)
    : DimensionalPlanarVector<Unit::Length, Number>(value, unit) {}

  /// \brief Constructor. Constructs a planar displacement vector from a given set of length
  /// components.
  PlanarDisplacement(const Length<Number>& x, const Length<Number>& y)
    : PlanarDisplacement<Number>({x.Value(), y.Value()}) {}

  /// \brief Constructor. Constructs a planar displacement vector from a given length and planar
  /// direction.
  constexpr PlanarDisplacement(
      const Length<Number>& length, const PlanarDirection<Number>& planar_direction)
    : PlanarDisplacement<Number>(length.Value() * planar_direction.Value()) {}

  /// \brief Constructor. Constructs a planar displacement vector from a given displacement vector
  /// by projecting the displacement vector onto the XY plane.
  explicit constexpr PlanarDisplacement(const Displacement<Number>& displacement);

  /// \brief Constructor. Constructs a planar displacement vector from a given planar velocity
  /// vector and time using the definition of velocity.
  constexpr PlanarDisplacement(
      const PlanarVelocity<Number>& planar_velocity, const Time<Number>& time);

  /// \brief Constructor. Constructs a planar displacement vector from a given planar velocity
  /// vector and frequency using the definition of velocity.
  constexpr PlanarDisplacement(
      const PlanarVelocity<Number>& planar_velocity, const Frequency<Number>& frequency);

  /// \brief Constructor. Constructs a planar displacement vector between a given planar position
  /// vector and the origin.
  explicit constexpr PlanarDisplacement(const PlanarPosition<Number>& planar_position);

  /// \brief Destructor. Destroys this planar displacement vector.
  ~PlanarDisplacement() noexcept = default;

  /// \brief Copy constructor. Constructs a planar displacement vector by copying another one.
  constexpr PlanarDisplacement(const PlanarDisplacement<Number>& other) = default;

  /// \brief Copy constructor. Constructs a planar displacement by copying another one.
  template <typename OtherNumber>
  explicit constexpr PlanarDisplacement(const PlanarDisplacement<OtherNumber>& other)
    : PlanarDisplacement(static_cast<PlanarVector<Number>>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar displacement vector by moving another one.
  constexpr PlanarDisplacement(PlanarDisplacement<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this planar displacement vector by copying another
  /// one.
  constexpr PlanarDisplacement<Number>& operator=(
      const PlanarDisplacement<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this planar displacement vector by copying another
  /// one.
  template <typename OtherNumber>
  constexpr PlanarDisplacement<Number>& operator=(const PlanarDisplacement<OtherNumber>& other) {
    this->value = static_cast<PlanarVector<Number>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this planar displacement vector by moving another
  /// one.
  constexpr PlanarDisplacement<Number>& operator=(
      PlanarDisplacement<Number>&& other) noexcept = default;

  /// \brief Statically creates a planar displacement vector of zero.
  static constexpr PlanarDisplacement<Number> Zero() {
    return PlanarDisplacement<Number>{PlanarVector<Number>::Zero()};
  }

  /// \brief Statically creates a planar displacement vector from the given x and y Cartesian
  /// components expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr PlanarDisplacement<Number> Create(const Number x, const Number y) {
    return PlanarDisplacement<Number>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(PlanarVector<Number>{x, y})};
  }

  /// \brief Statically creates a planar displacement vector from the given x and y Cartesian
  /// components expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr PlanarDisplacement<Number> Create(const std::array<Number, 2>& x_y) {
    return PlanarDisplacement<Number>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(PlanarVector<Number>{x_y})};
  }

  /// \brief Statically creates a planar displacement vector with a given value expressed in a given
  /// length unit.
  template <Unit::Length Unit>
  static constexpr PlanarDisplacement<Number> Create(const PlanarVector<Number>& value) {
    return PlanarDisplacement<Number>{
        StaticConvertCopy<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  /// \brief Returns the x Cartesian component of this planar displacement vector.
  [[nodiscard]] constexpr Length<Number> x() const noexcept {
    return Length<Number>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this planar displacement vector.
  [[nodiscard]] constexpr Length<Number> y() const noexcept {
    return Length<Number>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this planar displacement vector.
  [[nodiscard]] constexpr Length<Number> z() const noexcept {
    return Length<Number>{this->value.z()};
  }

  /// \brief Returns the magnitude of this planar displacement vector.
  [[nodiscard]] Length<Number> Magnitude() const {
    return Length<Number>{this->value.Magnitude()};
  }

  /// \brief Returns the planar direction of this planar displacement vector.
  [[nodiscard]] PhQ::PlanarDirection<Number> PlanarDirection() const {
    return this->value.PlanarDirection();
  }

  /// \brief Returns the angle between this planar displacement vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(
      const PlanarDisplacement<Number>& planar_displacement) const {
    return PhQ::Angle<Number>{*this, planar_displacement};
  }

  constexpr PlanarPosition<Number> operator+(const PlanarPosition<Number>& planar_position) const;

  constexpr PlanarDisplacement<Number> operator+(
      const PlanarDisplacement<Number>& planar_displacement) const {
    return PlanarDisplacement<Number>{this->value + planar_displacement.value};
  }

  constexpr PlanarPosition<Number> operator-(const PlanarPosition<Number>& planar_position) const;

  constexpr PlanarDisplacement<Number> operator-(
      const PlanarDisplacement<Number>& planar_displacement) const {
    return PlanarDisplacement<Number>{this->value - planar_displacement.value};
  }

  constexpr PlanarDisplacement<Number> operator*(const Number number) const {
    return PlanarDisplacement<Number>{this->value * number};
  }

  constexpr PlanarVelocity<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr PlanarDisplacement<Number> operator/(const Number number) const {
    return PlanarDisplacement<Number>{this->value / number};
  }

  constexpr PlanarVelocity<Number> operator/(const Time<Number>& time) const;

  constexpr void operator+=(const PlanarDisplacement<Number>& planar_displacement) noexcept {
    this->value += planar_displacement.value;
  }

  constexpr void operator-=(const PlanarDisplacement<Number>& planar_displacement) noexcept {
    this->value -= planar_displacement.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a planar displacement vector with a given value expressed in
  /// the standard length unit.
  explicit constexpr PlanarDisplacement(const PlanarVector<Number>& value)
    : DimensionalPlanarVector<Unit::Length, Number>(value) {}

  template <typename OtherNumber>
  friend class PlanarPosition;
};

template <typename Number>
inline constexpr bool operator==(
    const PlanarDisplacement<Number>& left, const PlanarDisplacement<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const PlanarDisplacement<Number>& left, const PlanarDisplacement<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const PlanarDisplacement<Number>& left, const PlanarDisplacement<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const PlanarDisplacement<Number>& left, const PlanarDisplacement<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const PlanarDisplacement<Number>& left, const PlanarDisplacement<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const PlanarDisplacement<Number>& left, const PlanarDisplacement<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const PlanarDisplacement<Number>& planar_displacement) {
  stream << planar_displacement.Print();
  return stream;
}

template <typename Number>
inline constexpr PlanarDisplacement<Number> operator*(
    const Number number, const PlanarDisplacement<Number>& planar_displacement) {
  return planar_displacement * number;
}

template <typename Number>
inline PlanarDirection<Number>::PlanarDirection(
    const PlanarDisplacement<Number>& planar_displacement)
  : PlanarDirection<Number>(planar_displacement.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(const PlanarDisplacement<Number>& planar_displacement_1,
                            const PlanarDisplacement<Number>& planar_displacement_2)
  : Angle<Number>(planar_displacement_1.Value(), planar_displacement_2.Value()) {}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::PlanarDisplacement<Number>> {
  inline size_t operator()(const PhQ::PlanarDisplacement<Number>& planar_displacement) const {
    return hash<PhQ::PlanarVector<Number>>()(planar_displacement.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_DISPLACEMENT_HPP
