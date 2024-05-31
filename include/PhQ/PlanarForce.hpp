// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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

#ifndef PHQ_PLANAR_FORCE_HPP
#define PHQ_PLANAR_FORCE_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalPlanarVector.hpp"
#include "PlanarDirection.hpp"
#include "PlanarVector.hpp"
#include "ScalarForce.hpp"
#include "Unit/Force.hpp"

namespace PhQ {

// Forward declaration for class PhQ::PlanarForce.
template <typename NumericType>
class PlanarTraction;

/// \brief Two-dimensional Euclidean force vector in the XY plane. Contains two components in
/// Cartesian coordinates: x and y. For a three-dimensional Euclidean force vector, see PhQ::Force.
/// For scalar force components or for the magnitude of a force vector, see PhQ::ScalarForce.
template <typename NumericType = double>
class PlanarForce : public DimensionalPlanarVector<Unit::Force, NumericType> {
public:
  /// \brief Default constructor. Constructs a planar force vector with an uninitialized value.
  PlanarForce() = default;

  /// \brief Constructor. Constructs a planar force vector with a given value expressed in a given
  /// force unit.
  PlanarForce(const PlanarVector<NumericType>& value, const Unit::Force unit)
    : DimensionalPlanarVector<Unit::Force, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a planar force vector from a given set of scalar force
  /// components.
  PlanarForce(const ScalarForce<NumericType>& x, const ScalarForce<NumericType>& y)
    : PlanarForce<NumericType>({x.Value(), y.Value()}) {}

  /// \brief Constructor. Constructs a planar force vector from a given scalar force magnitude and
  /// planar direction.
  constexpr PlanarForce(const ScalarForce<NumericType>& scalar_force,
                        const PlanarDirection<NumericType>& planar_direction)
    : PlanarForce<NumericType>(scalar_force.Value() * planar_direction.Value()) {}

  /// \brief Constructor. Constructs a planar force vector from a given force vector by projecting
  /// the force vector onto the XY plane.
  explicit constexpr PlanarForce(const Force<NumericType>& force);

  /// \brief Constructor. Constructs a planar force vector from a given planar traction and area
  /// using the definition of traction.
  constexpr PlanarForce(
      const PlanarTraction<NumericType>& planar_traction, const Area<NumericType>& area);

  /// \brief Destructor. Destroys this planar force vector.
  ~PlanarForce() noexcept = default;

  /// \brief Copy constructor. Constructs a planar force vector by copying another one.
  constexpr PlanarForce(const PlanarForce<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a planar force vector by copying another one.
  template <typename OtherNumericType>
  explicit constexpr PlanarForce(const PlanarForce<OtherNumericType>& other)
    : PlanarForce(static_cast<PlanarVector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar force vector by moving another one.
  constexpr PlanarForce(PlanarForce<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this planar force vector by copying another one.
  constexpr PlanarForce<NumericType>& operator=(const PlanarForce<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this planar force vector by copying another one.
  template <typename OtherNumericType>
  constexpr PlanarForce<NumericType>& operator=(const PlanarForce<OtherNumericType>& other) {
    this->value = static_cast<PlanarVector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this planar force vector by moving another one.
  constexpr PlanarForce<NumericType>& operator=(
      PlanarForce<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a planar force vector of zero.
  static constexpr PlanarForce<NumericType> Zero() {
    return PlanarForce<NumericType>{PlanarVector<NumericType>::Zero()};
  }

  /// \brief Statically creates a planar force vector from the given x and y Cartesian components
  /// expressed in a given force unit.
  template <Unit::Force Unit>
  static constexpr PlanarForce<NumericType> Create(const NumericType x, const NumericType y) {
    return PlanarForce<NumericType>{ConvertStatically<Unit::Force, Unit, Standard<Unit::Force>>(
        PlanarVector<NumericType>{x, y})};
  }

  /// \brief Statically creates a planar force vector from the given x and y Cartesian components
  /// expressed in a given force unit.
  template <Unit::Force Unit>
  static constexpr PlanarForce<NumericType> Create(const std::array<NumericType, 2>& x_y) {
    return PlanarForce<NumericType>{ConvertStatically<Unit::Force, Unit, Standard<Unit::Force>>(
        PlanarVector<NumericType>{x_y})};
  }

  /// \brief Statically creates a planar force vector with a given value expressed in a given force
  /// unit.
  template <Unit::Force Unit>
  static constexpr PlanarForce<NumericType> Create(const PlanarVector<NumericType>& value) {
    return PlanarForce<NumericType>{
        ConvertStatically<Unit::Force, Unit, Standard<Unit::Force>>(value)};
  }

  /// \brief Returns the x Cartesian component of this planar force vector.
  [[nodiscard]] constexpr ScalarForce<NumericType> x() const noexcept {
    return ScalarForce<NumericType>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this planar force vector.
  [[nodiscard]] constexpr ScalarForce<NumericType> y() const noexcept {
    return ScalarForce<NumericType>{this->value.y()};
  }

  /// \brief Returns the magnitude of this planar force vector.
  [[nodiscard]] ScalarForce<NumericType> Magnitude() const {
    return ScalarForce<NumericType>{this->value.Magnitude()};
  }

  /// \brief Returns the planar direction of this planar force vector.
  [[nodiscard]] PhQ::PlanarDirection<NumericType> PlanarDirection() const {
    return this->value.PlanarDirection();
  }

  /// \brief Returns the angle between this planar force vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(const PlanarForce<NumericType>& planar_force) const {
    return PhQ::Angle<NumericType>{*this, planar_force};
  }

  constexpr PlanarForce<NumericType> operator+(const PlanarForce<NumericType>& planar_force) const {
    return PlanarForce<NumericType>{this->value + planar_force.value};
  }

  constexpr PlanarForce<NumericType> operator-(const PlanarForce<NumericType>& planar_force) const {
    return PlanarForce<NumericType>{this->value - planar_force.value};
  }

  constexpr PlanarForce<NumericType> operator*(const NumericType number) const {
    return PlanarForce<NumericType>{this->value * number};
  }

  constexpr PlanarForce<NumericType> operator/(const NumericType number) const {
    return PlanarForce<NumericType>{this->value / number};
  }

  constexpr PlanarTraction<NumericType> operator/(const Area<NumericType>& area) const;

  constexpr void operator+=(const PlanarForce<NumericType>& planar_force) noexcept {
    this->value += planar_force.value;
  }

  constexpr void operator-=(const PlanarForce<NumericType>& planar_force) noexcept {
    this->value -= planar_force.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a planar force vector with a given value expressed in the
  /// standard force unit.
  explicit constexpr PlanarForce(const PlanarVector<NumericType>& value)
    : DimensionalPlanarVector<Unit::Force, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const PlanarForce<NumericType>& left, const PlanarForce<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const PlanarForce<NumericType>& left, const PlanarForce<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const PlanarForce<NumericType>& left, const PlanarForce<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const PlanarForce<NumericType>& left, const PlanarForce<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const PlanarForce<NumericType>& left, const PlanarForce<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const PlanarForce<NumericType>& left, const PlanarForce<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const PlanarForce<NumericType>& planar_force) {
  stream << planar_force.Print();
  return stream;
}

template <typename NumericType>
inline constexpr PlanarForce<NumericType> operator*(
    const NumericType number, const PlanarForce<NumericType>& planar_force) {
  return planar_force * number;
}

template <typename NumericType>
inline PlanarDirection<NumericType>::PlanarDirection(const PlanarForce<NumericType>& planar_force)
  : PlanarDirection<NumericType>(planar_force.Value()) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(
    const PlanarForce<NumericType>& planar_force_1, const PlanarForce<NumericType>& planar_force_2)
  : Angle<NumericType>(planar_force_1.Value(), planar_force_2.Value()) {}

template <typename NumericType>
inline constexpr PlanarForce<NumericType> PlanarDirection<NumericType>::operator*(
    const ScalarForce<NumericType>& scalar_force) const {
  return PlanarForce<NumericType>{scalar_force, *this};
}

template <typename NumericType>
inline constexpr PlanarForce<NumericType> ScalarForce<NumericType>::operator*(
    const PlanarDirection<NumericType>& planar_direction) const {
  return PlanarForce<NumericType>{*this, planar_direction};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::PlanarForce<NumericType>> {
  inline size_t operator()(const PhQ::PlanarForce<NumericType>& planar_force) const {
    return hash<PhQ::PlanarVector<NumericType>>()(planar_force.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_FORCE_HPP
