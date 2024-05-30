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

#ifndef PHQ_FORCE_HPP
#define PHQ_FORCE_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalVector.hpp"
#include "Direction.hpp"
#include "PlanarForce.hpp"
#include "ScalarForce.hpp"
#include "Unit/Force.hpp"
#include "Vector.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Force.
template <typename NumericType>
class Traction;

/// \brief Three-dimensional Euclidean force vector. Contains three components in Cartesian
/// coordinates: x, y, and z. For a two-dimensional Euclidean force vector in the XY plane, see
/// PhQ::PlanarForce. For scalar force components or for the magnitude of a force vector, see
/// PhQ::ScalarForce.
template <typename NumericType = double>
class Force : public DimensionalVector<Unit::Force, NumericType> {
public:
  /// \brief Default constructor. Constructs a force vector with an uninitialized value.
  Force() = default;

  /// \brief Constructor. Constructs a force vector with a given value expressed in a given force
  /// unit.
  Force(const Vector<NumericType>& value, const Unit::Force unit)
    : DimensionalVector<Unit::Force, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a force vector from a given set of scalar force components.
  Force(const ScalarForce<NumericType>& x, const ScalarForce<NumericType>& y,
        const ScalarForce<NumericType>& z)
    : Force<NumericType>({x.Value(), y.Value(), z.Value()}) {}

  /// \brief Constructor. Constructs a force vector from a given scalar force magnitude and
  /// direction.
  constexpr Force(
      const ScalarForce<NumericType>& scalar_force, const Direction<NumericType>& direction)
    : Force<NumericType>(scalar_force.Value() * direction.Value()) {}

  /// \brief Constructor. Constructs a force vector from a given planar force vector in the XY
  /// plane. This force vector's z-component is initialized to zero.
  explicit constexpr Force(const PlanarForce<NumericType>& planar_force)
    : Force<NumericType>(Vector<NumericType>{planar_force.Value()}) {}

  /// \brief Constructor. Constructs a force vector from a given traction and area using the
  /// definition of traction.
  constexpr Force(const Traction<NumericType>& traction, const Area<NumericType>& area);

  /// \brief Destructor. Destroys this force vector.
  ~Force() noexcept = default;

  /// \brief Copy constructor. Constructs a force vector by copying another one.
  constexpr Force(const Force<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a force vector by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Force(const Force<OtherNumericType>& other)
    : Force(static_cast<Vector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a force vector by moving another one.
  constexpr Force(Force<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this force vector by copying another one.
  constexpr Force<NumericType>& operator=(const Force<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this force vector by copying another one.
  template <typename OtherNumericType>
  constexpr Force<NumericType>& operator=(const Force<OtherNumericType>& other) {
    this->value = static_cast<Vector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this force vector by moving another one.
  constexpr Force<NumericType>& operator=(Force<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a force vector of zero.
  static constexpr Force<NumericType> Zero() {
    return Force<NumericType>{Vector<NumericType>::Zero()};
  }

  /// \brief Statically creates a force vector from the given x, y, and z Cartesian components
  /// expressed in a given force unit.
  template <Unit::Force Unit>
  static constexpr Force<NumericType> Create(
      const NumericType x, const NumericType y, const NumericType z) {
    return Force<NumericType>{
        ConvertStatically<Unit::Force, Unit, Standard<Unit::Force>>(Vector<NumericType>{x, y, z})};
  }

  /// \brief Statically creates a force vector from the given x, y, and z Cartesian components
  /// expressed in a given force unit.
  template <Unit::Force Unit>
  static constexpr Force<NumericType> Create(const std::array<NumericType, 3>& x_y_z) {
    return Force<NumericType>{
        ConvertStatically<Unit::Force, Unit, Standard<Unit::Force>>(Vector<NumericType>{x_y_z})};
  }

  /// \brief Statically creates a force vector with a given value expressed in a given force unit.
  template <Unit::Force Unit>
  static constexpr Force<NumericType> Create(const Vector<NumericType>& value) {
    return Force<NumericType>{ConvertStatically<Unit::Force, Unit, Standard<Unit::Force>>(value)};
  }

  /// \brief Returns the x Cartesian component of this force vector.
  [[nodiscard]] constexpr ScalarForce<NumericType> x() const noexcept {
    return ScalarForce<NumericType>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this force vector.
  [[nodiscard]] constexpr ScalarForce<NumericType> y() const noexcept {
    return ScalarForce<NumericType>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this force vector.
  [[nodiscard]] constexpr ScalarForce<NumericType> z() const noexcept {
    return ScalarForce<NumericType>{this->value.z()};
  }

  /// \brief Returns the magnitude of this force vector.
  [[nodiscard]] ScalarForce<NumericType> Magnitude() const {
    return ScalarForce<NumericType>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this force vector.
  [[nodiscard]] PhQ::Direction<NumericType> Direction() const {
    return this->value.Direction();
  }

  /// \brief Returns the angle between this force vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(const Force<NumericType>& force) const {
    return PhQ::Angle<NumericType>{*this, force};
  }

  constexpr Force<NumericType> operator+(const Force<NumericType>& force) const {
    return Force<NumericType>{this->value + force.value};
  }

  constexpr Force<NumericType> operator-(const Force<NumericType>& force) const {
    return Force<NumericType>{this->value - force.value};
  }

  constexpr Force<NumericType> operator*(const NumericType number) const {
    return Force<NumericType>{this->value * number};
  }

  constexpr Force<NumericType> operator/(const NumericType number) const {
    return Force<NumericType>{this->value / number};
  }

  constexpr Traction<NumericType> operator/(const Area<NumericType>& area) const;

  constexpr void operator+=(const Force<NumericType>& force) noexcept {
    this->value += force.value;
  }

  constexpr void operator-=(const Force<NumericType>& force) noexcept {
    this->value -= force.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a force vector with a given value expressed in the standard
  /// force unit.
  explicit constexpr Force(const Vector<NumericType>& value)
    : DimensionalVector<Unit::Force, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const Force<NumericType>& left, const Force<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Force<NumericType>& left, const Force<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Force<NumericType>& left, const Force<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Force<NumericType>& left, const Force<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Force<NumericType>& left, const Force<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Force<NumericType>& left, const Force<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Force<NumericType>& force) {
  stream << force.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Force<NumericType> operator*(
    const NumericType number, const Force<NumericType>& force) {
  return force * number;
}

template <typename NumericType>
inline Direction<NumericType>::Direction(const Force<NumericType>& force)
  : Direction<NumericType>(force.Value()) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(const Force<NumericType>& force1, const Force<NumericType>& force2)
  : Angle<NumericType>(force1.Value(), force2.Value()) {}

template <typename NumericType>
inline constexpr Force<NumericType> Direction<NumericType>::operator*(
    const ScalarForce<NumericType>& scalar_force) const {
  return Force<NumericType>{scalar_force, *this};
}

template <typename NumericType>
inline constexpr Force<NumericType> ScalarForce<NumericType>::operator*(
    const Direction<NumericType>& direction) const {
  return Force<NumericType>{*this, direction};
}

template <typename NumericType>
inline constexpr PlanarForce<NumericType>::PlanarForce(const Force<NumericType>& force)
  : PlanarForce(PlanarVector<NumericType>{force.Value()}) {}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Force<NumericType>> {
  inline size_t operator()(const PhQ::Force<NumericType>& force) const {
    return hash<PhQ::Vector<NumericType>>()(force.Value());
  }
};

}  // namespace std

#endif  // PHQ_FORCE_HPP
