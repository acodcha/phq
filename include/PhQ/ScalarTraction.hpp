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
template <typename Number>
class Direction;

// Forward declaration for class PhQ::ScalarTraction.
template <typename Number>
class PlanarDirection;

// Forward declaration for class PhQ::ScalarTraction.
template <typename Number>
class PlanarTraction;

// Forward declaration for class PhQ::ScalarTraction.
template <typename Number>
class Traction;

/// \brief Scalar traction component or magnitude of a traction vector. Traction is similar to
/// pressure; however, traction can act in any direction, whereas pressure always acts compressively
/// perpendicular to a surface. For a three-dimensional Euclidean traction vector, see
/// PhQ::Traction. For a two-dimensional Euclidean traction vector in the XY plane, see
/// PhQ::PlanarTraction.
template <typename Number = double>
class ScalarTraction : public DimensionalScalar<Unit::Pressure, Number> {
public:
  /// \brief Default constructor. Constructs a scalar traction with an uninitialized value.
  ScalarTraction() = default;

  /// \brief Constructor. Constructs a scalar traction with a given value expressed in a given
  /// pressure unit.
  ScalarTraction(const Number value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, Number>(value, unit) {}

  /// \brief Constructor. Constructs a scalar traction from a given scalar force magnitude and area
  /// using the definition of traction.
  constexpr ScalarTraction(const ScalarForce<Number>& scalar_force, const Area<Number>& area)
    : ScalarTraction<Number>(scalar_force.Value() / area.Value()) {}

  /// \brief Destructor. Destroys this scalar traction.
  ~ScalarTraction() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar traction by copying another one.
  constexpr ScalarTraction(const ScalarTraction<Number>& other) = default;

  /// \brief Copy constructor. Constructs a scalar traction by copying another one.
  template <typename OtherNumber>
  explicit constexpr ScalarTraction(const ScalarTraction<OtherNumber>& other)
    : ScalarTraction(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar traction by moving another one.
  constexpr ScalarTraction(ScalarTraction<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar traction by copying another one.
  constexpr ScalarTraction<Number>& operator=(const ScalarTraction<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar traction by copying another one.
  template <typename OtherNumber>
  constexpr ScalarTraction<Number>& operator=(const ScalarTraction<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar traction by moving another one.
  constexpr ScalarTraction<Number>& operator=(ScalarTraction<Number>&& other) noexcept = default;

  /// \brief Statically creates a scalar traction of zero.
  static constexpr ScalarTraction<Number> Zero() {
    return ScalarTraction<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a scalar traction with a given value expressed in a given pressure
  /// unit.
  template <Unit::Pressure Unit>
  static constexpr ScalarTraction<Number> Create(const Number value) {
    return ScalarTraction<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr ScalarTraction<Number> operator+(const ScalarTraction<Number>& other) const {
    return ScalarTraction<Number>{this->value + other.value};
  }

  constexpr ScalarTraction<Number> operator-(const ScalarTraction<Number>& other) const {
    return ScalarTraction<Number>{this->value - other.value};
  }

  constexpr ScalarTraction<Number> operator*(const Number number) const {
    return ScalarTraction<Number>{this->value * number};
  }

  constexpr ScalarForce<Number> operator*(const Area<Number>& area) const {
    return ScalarForce<Number>{*this, area};
  }

  constexpr PlanarTraction<Number> operator*(const PlanarDirection<Number>& planar_direction) const;

  constexpr Traction<Number> operator*(const Direction<Number>& direction) const;

  constexpr ScalarTraction<Number> operator/(const Number number) const {
    return ScalarTraction<Number>{this->value / number};
  }

  constexpr Number operator/(const ScalarTraction<Number>& other) const noexcept {
    return this->value / other.value;
  }

  constexpr void operator+=(const ScalarTraction<Number>& other) noexcept {
    this->value += other.value;
  }

  constexpr void operator-=(const ScalarTraction<Number>& other) noexcept {
    this->value -= other.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a scalar traction with a given value expressed in the standard
  /// pressure unit.
  explicit constexpr ScalarTraction(const Number value)
    : DimensionalScalar<Unit::Pressure, Number>(value) {}

  template <typename OtherNumber>
  friend class PlanarTraction;

  template <typename OtherNumber>
  friend class Traction;
};

template <typename Number>
inline constexpr bool operator==(
    const ScalarTraction<Number>& left, const ScalarTraction<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const ScalarTraction<Number>& left, const ScalarTraction<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const ScalarTraction<Number>& left, const ScalarTraction<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const ScalarTraction<Number>& left, const ScalarTraction<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const ScalarTraction<Number>& left, const ScalarTraction<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const ScalarTraction<Number>& left, const ScalarTraction<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const ScalarTraction<Number>& static_pressure) {
  stream << static_pressure.Print();
  return stream;
}

template <typename Number>
inline constexpr ScalarTraction<Number> operator*(
    const Number number, const ScalarTraction<Number>& static_pressure) {
  return static_pressure * number;
}

template <typename Number>
inline constexpr Area<Number>::Area(
    const ScalarForce<Number>& scalar_force, const ScalarTraction<Number>& scalar_traction)
  : Area<Number>(scalar_force.Value() / scalar_traction.Value()) {}

template <typename Number>
inline constexpr ScalarForce<Number>::ScalarForce(
    const ScalarTraction<Number>& scalar_traction, const Area<Number>& area)
  : ScalarForce<Number>(scalar_traction.Value() * area.Value()) {}

template <typename Number>
inline constexpr ScalarForce<Number> Area<Number>::operator*(
    const ScalarTraction<Number>& scalar_traction) const {
  return ScalarForce<Number>{scalar_traction, *this};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ScalarTraction<Number>> {
  inline size_t operator()(const PhQ::ScalarTraction<Number>& static_pressure) const {
    return hash<Number>()(static_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_SCALAR_TRACTION_HPP
