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
template <typename NumericType>
class Frequency;

// Forward declaration for class PhQ::PlanarDisplacement.
template <typename NumericType>
class PlanarPosition;

// Forward declaration for class PhQ::PlanarDisplacement.
template <typename NumericType>
class PlanarVelocity;

// Forward declaration for class PhQ::PlanarDisplacement.
template <typename NumericType>
class Time;

/// \brief Two-dimensional Euclidean displacement vector in the XY plane. Contains two components in
/// Cartesian coordinates: x and y. Displacement is not to be confused with position; for a
/// two-dimensional Euclidean position vector in the XY plane, see PhQ::PlanarPosition. For a
/// three-dimensional Euclidean displacement vector, see PhQ::Displacement. For scalar displacement
/// components or for the magnitude of a displacement vector, see PhQ::Length.
template <typename NumericType = double>
class PlanarDisplacement : public DimensionalPlanarVector<Unit::Length, NumericType> {
public:
  /// \brief Default constructor. Constructs a planar displacement vector with an uninitialized
  /// value.
  PlanarDisplacement() = default;

  /// \brief Constructor. Constructs a planar displacement vector with a given value expressed in a
  /// given length unit.
  PlanarDisplacement(const PlanarVector<NumericType>& value, const Unit::Length unit)
    : DimensionalPlanarVector<Unit::Length, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a planar displacement vector from a given set of length
  /// components.
  PlanarDisplacement(const Length<NumericType>& x, const Length<NumericType>& y)
    : PlanarDisplacement<NumericType>({x.Value(), y.Value()}) {}

  /// \brief Constructor. Constructs a planar displacement vector from a given length and planar
  /// direction.
  constexpr PlanarDisplacement(
      const Length<NumericType>& length, const PlanarDirection<NumericType>& planar_direction)
    : PlanarDisplacement<NumericType>(length.Value() * planar_direction.Value()) {}

  /// \brief Constructor. Constructs a planar displacement vector from a given displacement vector
  /// by projecting the displacement vector onto the XY plane.
  explicit constexpr PlanarDisplacement(const Displacement<NumericType>& displacement);

  /// \brief Constructor. Constructs a planar displacement vector from a given planar velocity
  /// vector and time using the definition of velocity.
  constexpr PlanarDisplacement(
      const PlanarVelocity<NumericType>& planar_velocity, const Time<NumericType>& time);

  /// \brief Constructor. Constructs a planar displacement vector from a given planar velocity
  /// vector and frequency using the definition of velocity.
  constexpr PlanarDisplacement(
      const PlanarVelocity<NumericType>& planar_velocity, const Frequency<NumericType>& frequency);

  /// \brief Constructor. Constructs a planar displacement vector between a given planar position
  /// vector and the origin.
  explicit constexpr PlanarDisplacement(const PlanarPosition<NumericType>& planar_position);

  /// \brief Destructor. Destroys this planar displacement vector.
  ~PlanarDisplacement() noexcept = default;

  /// \brief Copy constructor. Constructs a planar displacement vector by copying another one.
  constexpr PlanarDisplacement(const PlanarDisplacement<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a planar displacement by copying another one.
  template <typename OtherNumericType>
  explicit constexpr PlanarDisplacement(const PlanarDisplacement<OtherNumericType>& other)
    : PlanarDisplacement(static_cast<PlanarVector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar displacement vector by moving another one.
  constexpr PlanarDisplacement(PlanarDisplacement<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this planar displacement vector by copying another
  /// one.
  constexpr PlanarDisplacement<NumericType>& operator=(
      const PlanarDisplacement<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this planar displacement vector by copying another
  /// one.
  template <typename OtherNumericType>
  constexpr PlanarDisplacement<NumericType>& operator=(
      const PlanarDisplacement<OtherNumericType>& other) {
    this->value = static_cast<PlanarVector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this planar displacement vector by moving another
  /// one.
  constexpr PlanarDisplacement<NumericType>& operator=(
      PlanarDisplacement<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a planar displacement vector of zero.
  static constexpr PlanarDisplacement<NumericType> Zero() {
    return PlanarDisplacement<NumericType>{PlanarVector<NumericType>::Zero()};
  }

  /// \brief Statically creates a planar displacement vector from the given x and y Cartesian
  /// components expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr PlanarDisplacement<NumericType> Create(
      const NumericType x, const NumericType y) {
    return PlanarDisplacement<NumericType>{
        ConvertStatically<Unit::Length, Unit, Standard<Unit::Length>>(
            PlanarVector<NumericType>{x, y})};
  }

  /// \brief Statically creates a planar displacement vector from the given x and y Cartesian
  /// components expressed in a given length unit.
  template <Unit::Length Unit>
  static constexpr PlanarDisplacement<NumericType> Create(const std::array<NumericType, 2>& x_y) {
    return PlanarDisplacement<NumericType>{
        ConvertStatically<Unit::Length, Unit, Standard<Unit::Length>>(
            PlanarVector<NumericType>{x_y})};
  }

  /// \brief Statically creates a planar displacement vector with a given value expressed in a given
  /// length unit.
  template <Unit::Length Unit>
  static constexpr PlanarDisplacement<NumericType> Create(const PlanarVector<NumericType>& value) {
    return PlanarDisplacement<NumericType>{
        ConvertStatically<Unit::Length, Unit, Standard<Unit::Length>>(value)};
  }

  /// \brief Returns the x Cartesian component of this planar displacement vector.
  [[nodiscard]] constexpr Length<NumericType> x() const noexcept {
    return Length<NumericType>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this planar displacement vector.
  [[nodiscard]] constexpr Length<NumericType> y() const noexcept {
    return Length<NumericType>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this planar displacement vector.
  [[nodiscard]] constexpr Length<NumericType> z() const noexcept {
    return Length<NumericType>{this->value.z()};
  }

  /// \brief Returns the magnitude of this planar displacement vector.
  [[nodiscard]] Length<NumericType> Magnitude() const {
    return Length<NumericType>{this->value.Magnitude()};
  }

  /// \brief Returns the planar direction of this planar displacement vector.
  [[nodiscard]] PhQ::PlanarDirection<NumericType> PlanarDirection() const {
    return this->value.PlanarDirection();
  }

  /// \brief Returns the angle between this planar displacement vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(
      const PlanarDisplacement<NumericType>& planar_displacement) const {
    return PhQ::Angle<NumericType>{*this, planar_displacement};
  }

  constexpr PlanarPosition<NumericType> operator+(
      const PlanarPosition<NumericType>& planar_position) const;

  constexpr PlanarDisplacement<NumericType> operator+(
      const PlanarDisplacement<NumericType>& planar_displacement) const {
    return PlanarDisplacement<NumericType>{this->value + planar_displacement.value};
  }

  constexpr PlanarPosition<NumericType> operator-(
      const PlanarPosition<NumericType>& planar_position) const;

  constexpr PlanarDisplacement<NumericType> operator-(
      const PlanarDisplacement<NumericType>& planar_displacement) const {
    return PlanarDisplacement<NumericType>{this->value - planar_displacement.value};
  }

  constexpr PlanarDisplacement<NumericType> operator*(const NumericType number) const {
    return PlanarDisplacement<NumericType>{this->value * number};
  }

  constexpr PlanarVelocity<NumericType> operator*(const Frequency<NumericType>& frequency) const;

  constexpr PlanarDisplacement<NumericType> operator/(const NumericType number) const {
    return PlanarDisplacement<NumericType>{this->value / number};
  }

  constexpr PlanarVelocity<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr void operator+=(const PlanarDisplacement<NumericType>& planar_displacement) noexcept {
    this->value += planar_displacement.value;
  }

  constexpr void operator-=(const PlanarDisplacement<NumericType>& planar_displacement) noexcept {
    this->value -= planar_displacement.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a planar displacement vector with a given value expressed in
  /// the standard length unit.
  explicit constexpr PlanarDisplacement(const PlanarVector<NumericType>& value)
    : DimensionalPlanarVector<Unit::Length, NumericType>(value) {}

  template <typename OtherNumericType>
  friend class PlanarPosition;
};

template <typename NumericType>
inline constexpr bool operator==(const PlanarDisplacement<NumericType>& left,
                                 const PlanarDisplacement<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const PlanarDisplacement<NumericType>& left,
                                 const PlanarDisplacement<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const PlanarDisplacement<NumericType>& left,
                                const PlanarDisplacement<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const PlanarDisplacement<NumericType>& left,
                                const PlanarDisplacement<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const PlanarDisplacement<NumericType>& left,
                                 const PlanarDisplacement<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const PlanarDisplacement<NumericType>& left,
                                 const PlanarDisplacement<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const PlanarDisplacement<NumericType>& planar_displacement) {
  stream << planar_displacement.Print();
  return stream;
}

template <typename NumericType>
inline constexpr PlanarDisplacement<NumericType> operator*(
    const NumericType number, const PlanarDisplacement<NumericType>& planar_displacement) {
  return planar_displacement * number;
}

template <typename NumericType>
inline PlanarDirection<NumericType>::PlanarDirection(
    const PlanarDisplacement<NumericType>& planar_displacement)
  : PlanarDirection<NumericType>(planar_displacement.Value()) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(const PlanarDisplacement<NumericType>& planar_displacement_1,
                                 const PlanarDisplacement<NumericType>& planar_displacement_2)
  : Angle<NumericType>(planar_displacement_1.Value(), planar_displacement_2.Value()) {}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::PlanarDisplacement<NumericType>> {
  inline size_t operator()(const PhQ::PlanarDisplacement<NumericType>& planar_displacement) const {
    return hash<PhQ::PlanarVector<NumericType>>()(planar_displacement.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_DISPLACEMENT_HPP
