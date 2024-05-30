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

#ifndef PHQ_TRACTION_HPP
#define PHQ_TRACTION_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Area.hpp"
#include "DimensionalVector.hpp"
#include "Direction.hpp"
#include "Force.hpp"
#include "PlanarTraction.hpp"
#include "ScalarTraction.hpp"
#include "Unit/Pressure.hpp"
#include "Vector.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Traction.
template <typename NumericType>
class Stress;

/// \brief Three-dimensional Euclidean traction vector. Contains three components in Cartesian
/// coordinates: x, y, and z. Traction is similar to pressure; however, traction can act in any
/// direction, whereas pressure always acts compressively perpendicular to a surface. For a
/// two-dimensional Euclidean traction vector in the XY plane, see PhQ::PlanarTraction. For scalar
/// traction components or for the magnitude of a traction vector, see PhQ::ScalarTraction.
template <typename NumericType = double>
class Traction : public DimensionalVector<Unit::Pressure, NumericType> {
public:
  /// \brief Default constructor. Constructs a traction vector with an uninitialized value.
  Traction() = default;

  /// \brief Constructor. Constructs a traction vector with a given value expressed in a given
  /// pressure unit.
  Traction(const Vector<NumericType>& value, const Unit::Pressure unit)
    : DimensionalVector<Unit::Pressure, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a traction vector from a given set of scalar traction
  /// components.
  Traction(const ScalarTraction<NumericType>& x, const ScalarTraction<NumericType>& y,
           const ScalarTraction<NumericType>& z)
    : Traction<NumericType>({x.Value(), y.Value(), z.Value()}) {}

  /// \brief Constructor. Constructs a traction vector from a given scalar traction and direction.
  constexpr Traction(
      const ScalarTraction<NumericType>& scalar_traction, const Direction<NumericType>& direction)
    : Traction<NumericType>(scalar_traction.Value() * direction.Value()) {}

  /// \brief Constructor. Constructs a traction vector from a given planar traction vector in the XY
  /// plane. This traction vector's z-component is initialized to zero.
  explicit constexpr Traction(const PlanarTraction<NumericType>& planar_traction)
    : Traction<NumericType>(Vector<NumericType>{planar_traction.Value()}) {}

  /// \brief Constructor. Constructs a traction vector from a given force and area using the
  /// definition of traction.
  constexpr Traction(const Force<NumericType>& force, const Area<NumericType>& area)
    : Traction<NumericType>(force.Value() / area.Value()) {}

  /// \brief Constructor. Constructs a traction vector from a given stress and direction using the
  /// definition of traction.
  constexpr Traction(const Stress<NumericType>& stress, const Direction<NumericType>& direction);

  /// \brief Destructor. Destroys this traction vector.
  ~Traction() noexcept = default;

  /// \brief Copy constructor. Constructs a traction vector by copying another one.
  constexpr Traction(const Traction<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a traction vector by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Traction(const Traction<OtherNumericType>& other)
    : Traction(static_cast<Vector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a traction vector by moving another one.
  constexpr Traction(Traction<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this traction vector by copying another one.
  constexpr Traction<NumericType>& operator=(const Traction<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this traction vector by copying another one.
  template <typename OtherNumericType>
  constexpr Traction<NumericType>& operator=(const Traction<OtherNumericType>& other) {
    this->value = static_cast<Vector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this traction vector by moving another one.
  constexpr Traction<NumericType>& operator=(Traction<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a traction vector of zero.
  static constexpr Traction<NumericType> Zero() {
    return Traction<NumericType>{Vector<NumericType>::Zero()};
  }

  /// \brief Statically creates a traction vector from the given x, y, and z Cartesian components
  /// expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Traction<NumericType> Create(
      const NumericType x, const NumericType y, const NumericType z) {
    return Traction<NumericType>{ConvertStatically<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
        Vector<NumericType>{x, y, z})};
  }

  /// \brief Statically creates a traction vector from the given x, y, and z Cartesian components
  /// expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Traction<NumericType> Create(const std::array<NumericType, 3>& x_y_z) {
    return Traction<NumericType>{ConvertStatically<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
        Vector<NumericType>{x_y_z})};
  }

  /// \brief Statically creates a traction vector with a given value expressed in a given pressure
  /// unit.
  template <Unit::Pressure Unit>
  static constexpr Traction<NumericType> Create(const Vector<NumericType>& value) {
    return Traction<NumericType>{
        ConvertStatically<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  /// \brief Returns the x Cartesian component of this traction vector.
  [[nodiscard]] constexpr ScalarTraction<NumericType> x() const noexcept {
    return ScalarTraction<NumericType>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this traction vector.
  [[nodiscard]] constexpr ScalarTraction<NumericType> y() const noexcept {
    return ScalarTraction<NumericType>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this traction vector.
  [[nodiscard]] constexpr ScalarTraction<NumericType> z() const noexcept {
    return ScalarTraction<NumericType>{this->value.z()};
  }

  /// \brief Returns the magnitude of this traction vector.
  [[nodiscard]] ScalarTraction<NumericType> Magnitude() const {
    return ScalarTraction<NumericType>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this traction vector.
  [[nodiscard]] PhQ::Direction<NumericType> Direction() const {
    return this->value.Direction();
  }

  /// \brief Returns the angle between this traction vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(const Traction<NumericType>& traction) const {
    return PhQ::Angle<NumericType>{*this, traction};
  }

  constexpr Traction<NumericType> operator+(const Traction<NumericType>& traction) const {
    return Traction<NumericType>{this->value + traction.value};
  }

  constexpr Traction<NumericType> operator-(const Traction<NumericType>& traction) const {
    return Traction<NumericType>{this->value - traction.value};
  }

  constexpr Traction<NumericType> operator*(const NumericType number) const {
    return Traction<NumericType>{this->value * number};
  }

  constexpr Force<NumericType> operator*(const Area<NumericType>& area) const {
    return Force<NumericType>{*this, area};
  }

  constexpr Traction<NumericType> operator/(const NumericType number) const {
    return Traction<NumericType>{this->value / number};
  }

  constexpr void operator+=(const Traction<NumericType>& traction) noexcept {
    this->value += traction.value;
  }

  constexpr void operator-=(const Traction<NumericType>& traction) noexcept {
    this->value -= traction.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a traction vector with a given value expressed in the standard
  /// pressure unit.
  explicit constexpr Traction(const Vector<NumericType>& value)
    : DimensionalVector<Unit::Pressure, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const Traction<NumericType>& left, const Traction<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Traction<NumericType>& left, const Traction<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Traction<NumericType>& left, const Traction<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Traction<NumericType>& left, const Traction<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Traction<NumericType>& left, const Traction<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Traction<NumericType>& left, const Traction<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Traction<NumericType>& traction) {
  stream << traction.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Traction<NumericType> operator*(
    const NumericType number, const Traction<NumericType>& traction) {
  return traction * number;
}

template <typename NumericType>
inline Direction<NumericType>::Direction(const Traction<NumericType>& traction)
  : Direction<NumericType>(traction.Value()) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(
    const Traction<NumericType>& traction1, const Traction<NumericType>& traction2)
  : Angle<NumericType>(traction1.Value(), traction2.Value()) {}

template <typename NumericType>
inline constexpr Force<NumericType>::Force(
    const Traction<NumericType>& traction, const Area<NumericType>& area)
  : Force<NumericType>(traction.Value() * area.Value()) {}

template <typename NumericType>
inline constexpr Traction<NumericType> Direction<NumericType>::operator*(
    const ScalarTraction<NumericType>& scalar_traction) const {
  return Traction<NumericType>{scalar_traction, *this};
}

template <typename NumericType>
inline constexpr Traction<NumericType> ScalarTraction<NumericType>::operator*(
    const Direction<NumericType>& direction) const {
  return Traction<NumericType>{*this, direction};
}

template <typename NumericType>
inline constexpr Traction<NumericType> Force<NumericType>::operator/(
    const Area<NumericType>& area) const {
  return Traction<NumericType>{*this, area};
}

template <typename NumericType>
inline constexpr PlanarTraction<NumericType>::PlanarTraction(const Traction<NumericType>& traction)
  : PlanarTraction(PlanarVector<NumericType>{traction.Value()}) {}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Traction<NumericType>> {
  inline size_t operator()(const PhQ::Traction<NumericType>& traction) const {
    return hash<PhQ::Vector<NumericType>>()(traction.Value());
  }
};

}  // namespace std

#endif  // PHQ_TRACTION_HPP
