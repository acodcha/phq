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

#ifndef PHQ_PLANAR_TRACTION_HPP
#define PHQ_PLANAR_TRACTION_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Area.hpp"
#include "DimensionalPlanarVector.hpp"
#include "PlanarDirection.hpp"
#include "PlanarForce.hpp"
#include "PlanarVector.hpp"
#include "ScalarTraction.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declaration for class PhQ::PlanarTraction.
template <typename NumericType>
class Stress;

/// \brief Two-dimensional Euclidean traction vector in the XY plane. Contains two components in
/// Cartesian coordinates: x and y. Traction is similar to pressure; however, traction can act in
/// any direction, whereas pressure always acts compressively perpendicular to a surface. For a
/// three-dimensional Euclidean traction vector, see PhQ::Traction. For scalar traction components
/// or for the magnitude of a traction vector, see PhQ::ScalarTraction.
template <typename NumericType = double>
class PlanarTraction : public DimensionalPlanarVector<Unit::Pressure, NumericType> {
public:
  /// \brief Default constructor. Constructs a planar traction vector with an uninitialized value.
  PlanarTraction() = default;

  /// \brief Constructor. Constructs a planar traction vector with a given value expressed in a
  /// given pressure unit.
  PlanarTraction(const PlanarVector<NumericType>& value, const Unit::Pressure unit)
    : DimensionalPlanarVector<Unit::Pressure, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a planar traction vector from a given set of scalar traction
  /// components.
  PlanarTraction(const ScalarTraction<NumericType>& x, const ScalarTraction<NumericType>& y)
    : PlanarTraction<NumericType>({x.Value(), y.Value()}) {}

  /// \brief Constructor. Constructs a planar traction vector from a given scalar traction and
  /// planar direction.
  constexpr PlanarTraction(const ScalarTraction<NumericType>& scalar_traction,
                           const PlanarDirection<NumericType>& planar_direction)
    : PlanarTraction<NumericType>(scalar_traction.Value() * planar_direction.Value()) {}

  /// \brief Constructor. Constructs a planar traction vector from a given traction vector by
  /// projecting the traction vector onto the XY plane.
  explicit constexpr PlanarTraction(const Traction<NumericType>& traction);

  /// \brief Constructor. Constructs a planar traction vector from a given planar force and area
  /// using the definition of traction.
  constexpr PlanarTraction(
      const PlanarForce<NumericType>& planar_force, const Area<NumericType>& area)
    : PlanarTraction<NumericType>(planar_force.Value() / area.Value()) {}

  /// \brief Constructor. Constructs a planar traction vector from a given stress and direction
  /// using the definition of traction.
  constexpr PlanarTraction(
      const Stress<NumericType>& stress, const PlanarDirection<NumericType>& planar_direction);

  /// \brief Destructor. Destroys this planar traction vector.
  ~PlanarTraction() noexcept = default;

  /// \brief Copy constructor. Constructs a planar traction vector by copying another one.
  constexpr PlanarTraction(const PlanarTraction<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a planar traction vector by copying another one.
  template <typename OtherNumericType>
  explicit constexpr PlanarTraction(const PlanarTraction<OtherNumericType>& other)
    : PlanarTraction(static_cast<PlanarVector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar traction vector by moving another one.
  constexpr PlanarTraction(PlanarTraction<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this planar traction vector by copying another one.
  constexpr PlanarTraction<NumericType>& operator=(
      const PlanarTraction<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this planar traction vector by copying another one.
  template <typename OtherNumericType>
  constexpr PlanarTraction<NumericType>& operator=(const PlanarTraction<OtherNumericType>& other) {
    this->value = static_cast<PlanarVector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this planar traction vector by moving another one.
  constexpr PlanarTraction<NumericType>& operator=(
      PlanarTraction<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a planar traction vector of zero.
  static constexpr PlanarTraction<NumericType> Zero() {
    return PlanarTraction<NumericType>{PlanarVector<NumericType>::Zero()};
  }

  /// \brief Statically creates a planar traction vector from the given x and y Cartesian components
  /// expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr PlanarTraction<NumericType> Create(const NumericType x, const NumericType y) {
    return PlanarTraction<NumericType>{
        ConvertStatically<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
            PlanarVector<NumericType>{x, y})};
  }

  /// \brief Statically creates a planar traction vector from the given x and y Cartesian components
  /// expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr PlanarTraction<NumericType> Create(const std::array<NumericType, 2>& x_y) {
    return PlanarTraction<NumericType>{
        ConvertStatically<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
            PlanarVector<NumericType>{x_y})};
  }

  /// \brief Statically creates a planar traction vector with a given value expressed in a given
  /// pressure unit.
  template <Unit::Pressure Unit>
  static constexpr PlanarTraction<NumericType> Create(const PlanarVector<NumericType>& value) {
    return PlanarTraction<NumericType>{
        ConvertStatically<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  /// \brief Returns the x Cartesian component of this planar traction vector.
  [[nodiscard]] constexpr ScalarTraction<NumericType> x() const noexcept {
    return ScalarTraction<NumericType>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this planar traction vector.
  [[nodiscard]] constexpr ScalarTraction<NumericType> y() const noexcept {
    return ScalarTraction<NumericType>{this->value.y()};
  }

  /// \brief Returns the magnitude of this planar traction vector.
  [[nodiscard]] ScalarTraction<NumericType> Magnitude() const {
    return ScalarTraction<NumericType>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this planar traction vector.
  [[nodiscard]] PhQ::PlanarDirection<NumericType> PlanarDirection() const {
    return this->value.PlanarDirection();
  }

  /// \brief Returns the angle between this planar traction vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(
      const PlanarTraction<NumericType>& planar_traction) const {
    return PhQ::Angle<NumericType>{*this, planar_traction};
  }

  constexpr PlanarTraction<NumericType> operator+(
      const PlanarTraction<NumericType>& planar_traction) const {
    return PlanarTraction<NumericType>{this->value + planar_traction.value};
  }

  constexpr PlanarTraction<NumericType> operator-(
      const PlanarTraction<NumericType>& planar_traction) const {
    return PlanarTraction<NumericType>{this->value - planar_traction.value};
  }

  constexpr PlanarTraction<NumericType> operator*(const NumericType number) const {
    return PlanarTraction<NumericType>{this->value * number};
  }

  constexpr PlanarForce<NumericType> operator*(const Area<NumericType>& area) const {
    return PlanarForce<NumericType>{*this, area};
  }

  constexpr PlanarTraction<NumericType> operator/(const NumericType number) const {
    return PlanarTraction<NumericType>{this->value / number};
  }

  constexpr void operator+=(const PlanarTraction<NumericType>& planar_traction) noexcept {
    this->value += planar_traction.value;
  }

  constexpr void operator-=(const PlanarTraction<NumericType>& planar_traction) noexcept {
    this->value -= planar_traction.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a planar traction vector with a given value expressed in the
  /// standard pressure unit.
  explicit constexpr PlanarTraction(const PlanarVector<NumericType>& value)
    : DimensionalPlanarVector<Unit::Pressure, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const PlanarTraction<NumericType>& left, const PlanarTraction<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const PlanarTraction<NumericType>& left, const PlanarTraction<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const PlanarTraction<NumericType>& left, const PlanarTraction<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const PlanarTraction<NumericType>& left, const PlanarTraction<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const PlanarTraction<NumericType>& left, const PlanarTraction<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const PlanarTraction<NumericType>& left, const PlanarTraction<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const PlanarTraction<NumericType>& planar_traction) {
  stream << planar_traction.Print();
  return stream;
}

template <typename NumericType>
inline constexpr PlanarTraction<NumericType> operator*(
    const NumericType number, const PlanarTraction<NumericType>& planar_traction) {
  return planar_traction * number;
}

template <typename NumericType>
inline PlanarDirection<NumericType>::PlanarDirection(
    const PlanarTraction<NumericType>& planar_traction)
  : PlanarDirection<NumericType>(planar_traction.Value()) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(const PlanarTraction<NumericType>& planar_traction_1,
                                 const PlanarTraction<NumericType>& planar_traction_2)
  : Angle<NumericType>(planar_traction_1.Value(), planar_traction_2.Value()) {}

template <typename NumericType>
inline constexpr PlanarForce<NumericType>::PlanarForce(
    const PlanarTraction<NumericType>& planar_traction, const Area<NumericType>& area)
  : PlanarForce<NumericType>(planar_traction.Value() * area.Value()) {}

template <typename NumericType>
inline constexpr PlanarTraction<NumericType> PlanarDirection<NumericType>::operator*(
    const ScalarTraction<NumericType>& scalar_traction) const {
  return PlanarTraction<NumericType>{scalar_traction, *this};
}

template <typename NumericType>
inline constexpr PlanarTraction<NumericType> ScalarTraction<NumericType>::operator*(
    const PlanarDirection<NumericType>& planar_direction) const {
  return PlanarTraction<NumericType>{*this, planar_direction};
}

template <typename NumericType>
inline constexpr PlanarTraction<NumericType> PlanarForce<NumericType>::operator/(
    const Area<NumericType>& area) const {
  return PlanarTraction<NumericType>{*this, area};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::PlanarTraction<NumericType>> {
  inline size_t operator()(const PhQ::PlanarTraction<NumericType>& planar_traction) const {
    return hash<PhQ::PlanarVector<NumericType>>()(planar_traction.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_TRACTION_HPP
