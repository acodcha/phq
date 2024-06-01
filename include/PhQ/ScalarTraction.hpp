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

#ifndef PHQ_SCALAR_TRACTION_HPP
#define PHQ_SCALAR_TRACTION_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "Area.hpp"
#include "DimensionalScalar.hpp"
#include "ScalarForce.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ScalarTraction.
template <typename NumericType>
class Direction;

// Forward declaration for class PhQ::ScalarTraction.
template <typename NumericType>
class PlanarDirection;

// Forward declaration for class PhQ::ScalarTraction.
template <typename NumericType>
class PlanarTraction;

// Forward declaration for class PhQ::ScalarTraction.
template <typename NumericType>
class Traction;

/// \brief Scalar traction component or magnitude of a traction vector. Traction is similar to
/// pressure; however, traction can act in any direction, whereas pressure always acts compressively
/// perpendicular to a surface. For a three-dimensional Euclidean traction vector, see
/// PhQ::Traction. For a two-dimensional Euclidean traction vector in the XY plane, see
/// PhQ::PlanarTraction.
template <typename NumericType = double>
class ScalarTraction : public DimensionalScalar<Unit::Pressure, NumericType> {
public:
  /// \brief Default constructor. Constructs a scalar traction with an uninitialized value.
  ScalarTraction() = default;

  /// \brief Constructor. Constructs a scalar traction with a given value expressed in a given
  /// pressure unit.
  ScalarTraction(const NumericType value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a scalar traction from a given scalar force magnitude and area
  /// using the definition of traction.
  constexpr ScalarTraction(
      const ScalarForce<NumericType>& scalar_force, const Area<NumericType>& area)
    : ScalarTraction<NumericType>(scalar_force.Value() / area.Value()) {}

  /// \brief Destructor. Destroys this scalar traction.
  ~ScalarTraction() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar traction by copying another one.
  constexpr ScalarTraction(const ScalarTraction<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a scalar traction by copying another one.
  template <typename OtherNumericType>
  explicit constexpr ScalarTraction(const ScalarTraction<OtherNumericType>& other)
    : ScalarTraction(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar traction by moving another one.
  constexpr ScalarTraction(ScalarTraction<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar traction by copying another one.
  constexpr ScalarTraction<NumericType>& operator=(
      const ScalarTraction<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar traction by copying another one.
  template <typename OtherNumericType>
  constexpr ScalarTraction<NumericType>& operator=(const ScalarTraction<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar traction by moving another one.
  constexpr ScalarTraction<NumericType>& operator=(
      ScalarTraction<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a scalar traction of zero.
  static constexpr ScalarTraction<NumericType> Zero() {
    return ScalarTraction<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a scalar traction with a given value expressed in a given pressure
  /// unit.
  template <Unit::Pressure Unit>
  static constexpr ScalarTraction<NumericType> Create(const NumericType value) {
    return ScalarTraction<NumericType>{
        ConvertStatically<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr ScalarTraction<NumericType> operator+(const ScalarTraction<NumericType>& other) const {
    return ScalarTraction<NumericType>{this->value + other.value};
  }

  constexpr ScalarTraction<NumericType> operator-(const ScalarTraction<NumericType>& other) const {
    return ScalarTraction<NumericType>{this->value - other.value};
  }

  constexpr ScalarTraction<NumericType> operator*(const NumericType number) const {
    return ScalarTraction<NumericType>{this->value * number};
  }

  constexpr ScalarForce<NumericType> operator*(const Area<NumericType>& area) const {
    return ScalarForce<NumericType>{*this, area};
  }

  constexpr PlanarTraction<NumericType> operator*(
      const PlanarDirection<NumericType>& planar_direction) const;

  constexpr Traction<NumericType> operator*(const Direction<NumericType>& direction) const;

  constexpr ScalarTraction<NumericType> operator/(const NumericType number) const {
    return ScalarTraction<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(const ScalarTraction<NumericType>& other) const noexcept {
    return this->value / other.value;
  }

  constexpr void operator+=(const ScalarTraction<NumericType>& other) noexcept {
    this->value += other.value;
  }

  constexpr void operator-=(const ScalarTraction<NumericType>& other) noexcept {
    this->value -= other.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a scalar traction with a given value expressed in the standard
  /// pressure unit.
  explicit constexpr ScalarTraction(const NumericType value)
    : DimensionalScalar<Unit::Pressure, NumericType>(value) {}

  template <typename OtherNumericType>
  friend class PlanarTraction;

  template <typename OtherNumericType>
  friend class Traction;
};

template <typename NumericType>
inline constexpr bool operator==(
    const ScalarTraction<NumericType>& left, const ScalarTraction<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const ScalarTraction<NumericType>& left, const ScalarTraction<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const ScalarTraction<NumericType>& left, const ScalarTraction<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const ScalarTraction<NumericType>& left, const ScalarTraction<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const ScalarTraction<NumericType>& left, const ScalarTraction<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const ScalarTraction<NumericType>& left, const ScalarTraction<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const ScalarTraction<NumericType>& static_pressure) {
  stream << static_pressure.Print();
  return stream;
}

template <typename NumericType>
inline constexpr ScalarTraction<NumericType> operator*(
    const NumericType number, const ScalarTraction<NumericType>& static_pressure) {
  return static_pressure * number;
}

template <typename NumericType>
inline constexpr Area<NumericType>::Area(const ScalarForce<NumericType>& scalar_force,
                                         const ScalarTraction<NumericType>& scalar_traction)
  : Area<NumericType>(scalar_force.Value() / scalar_traction.Value()) {}

template <typename NumericType>
inline constexpr ScalarForce<NumericType>::ScalarForce(
    const ScalarTraction<NumericType>& scalar_traction, const Area<NumericType>& area)
  : ScalarForce<NumericType>(scalar_traction.Value() * area.Value()) {}

template <typename NumericType>
inline constexpr ScalarForce<NumericType> Area<NumericType>::operator*(
    const ScalarTraction<NumericType>& scalar_traction) const {
  return ScalarForce<NumericType>{scalar_traction, *this};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::ScalarTraction<NumericType>> {
  inline size_t operator()(const PhQ::ScalarTraction<NumericType>& static_pressure) const {
    return hash<NumericType>()(static_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_SCALAR_TRACTION_HPP
