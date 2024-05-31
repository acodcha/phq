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

#ifndef PHQ_SCALAR_FORCE_HPP
#define PHQ_SCALAR_FORCE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "Area.hpp"
#include "DimensionalScalar.hpp"
#include "Unit/Force.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ScalarForce.
template <typename NumericType>
class Direction;

// Forward declaration for class PhQ::ScalarForce.
template <typename NumericType>
class Force;

// Forward declaration for class PhQ::ScalarForce.
template <typename NumericType>
class PlanarDirection;

// Forward declaration for class PhQ::ScalarForce.
template <typename NumericType>
class PlanarForce;

// Forward declaration for class PhQ::ScalarForce.
template <typename NumericType>
class ScalarTraction;

// Forward declaration for class PhQ::ScalarForce.
template <typename NumericType>
class StaticPressure;

/// \brief Scalar force component or magnitude of a force vector. For a three-dimensional Euclidean
/// force vector, see PhQ::Force. For a two-dimensional Euclidean force vector in the XY plane, see
/// PhQ::PlanarForce.
template <typename NumericType = double>
class ScalarForce : public DimensionalScalar<Unit::Force, NumericType> {
public:
  /// \brief Default constructor. Constructs a scalar force with an uninitialized value.
  ScalarForce() = default;

  /// \brief Constructor. Constructs a scalar force with a given value expressed in a given force
  /// unit.
  ScalarForce(const NumericType value, const Unit::Force unit)
    : DimensionalScalar<Unit::Force, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a scalar force from a given scalar traction and area using the
  /// definition of traction.
  constexpr ScalarForce(
      const ScalarTraction<NumericType>& scalar_traction, const Area<NumericType>& area);

  /// \brief Constructor. Constructs a scalar force from a given static pressure and area using the
  /// definition of pressure.
  constexpr ScalarForce(
      const StaticPressure<NumericType>& static_pressure, const Area<NumericType>& area);

  /// \brief Destructor. Destroys this scalar force.
  ~ScalarForce() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar force by copying another one.
  constexpr ScalarForce(const ScalarForce<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a scalar force by copying another one.
  template <typename OtherNumericType>
  explicit constexpr ScalarForce(const ScalarForce<OtherNumericType>& other)
    : ScalarForce(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar force by moving another one.
  constexpr ScalarForce(ScalarForce<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar force by copying another one.
  constexpr ScalarForce<NumericType>& operator=(const ScalarForce<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar force by copying another one.
  template <typename OtherNumericType>
  constexpr ScalarForce<NumericType>& operator=(const ScalarForce<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar force by moving another one.
  constexpr ScalarForce<NumericType>& operator=(
      ScalarForce<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a scalar force of zero.
  static constexpr ScalarForce<NumericType> Zero() {
    return ScalarForce<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a scalar force with a given value expressed in a given force unit.
  template <Unit::Force Unit>
  static constexpr ScalarForce<NumericType> Create(const NumericType value) {
    return ScalarForce<NumericType>{
        ConvertStatically<Unit::Force, Unit, Standard<Unit::Force>>(value)};
  }

  constexpr ScalarForce<NumericType> operator+(const ScalarForce<NumericType>& scalar_force) const {
    return ScalarForce<NumericType>{this->value + scalar_force.value};
  }

  constexpr ScalarForce<NumericType> operator-(const ScalarForce<NumericType>& scalar_force) const {
    return ScalarForce<NumericType>{this->value - scalar_force.value};
  }

  constexpr ScalarForce<NumericType> operator*(const NumericType number) const {
    return ScalarForce<NumericType>{this->value * number};
  }

  constexpr PlanarForce<NumericType> operator*(
      const PlanarDirection<NumericType>& planar_direction) const;

  constexpr Force<NumericType> operator*(const Direction<NumericType>& direction) const;

  constexpr ScalarForce<NumericType> operator/(const NumericType number) const {
    return ScalarForce<NumericType>{this->value / number};
  }

  constexpr StaticPressure<NumericType> operator/(const Area<NumericType>& area) const;

  constexpr NumericType operator/(const ScalarForce<NumericType>& scalar_force) const noexcept {
    return this->value / scalar_force.value;
  }

  constexpr void operator+=(const ScalarForce<NumericType>& scalar_force) noexcept {
    this->value += scalar_force.value;
  }

  constexpr void operator-=(const ScalarForce<NumericType>& scalar_force) noexcept {
    this->value -= scalar_force.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a scalar force with a given value expressed in the standard
  /// force unit.
  explicit constexpr ScalarForce(const NumericType value)
    : DimensionalScalar<Unit::Force, NumericType>(value) {}

  template <typename OtherNumericType>
  friend class PlanarForce;

  template <typename OtherNumericType>
  friend class Force;
};

template <typename NumericType>
inline constexpr bool operator==(
    const ScalarForce<NumericType>& left, const ScalarForce<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const ScalarForce<NumericType>& left, const ScalarForce<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const ScalarForce<NumericType>& left, const ScalarForce<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const ScalarForce<NumericType>& left, const ScalarForce<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const ScalarForce<NumericType>& left, const ScalarForce<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const ScalarForce<NumericType>& left, const ScalarForce<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const ScalarForce<NumericType>& scalar_force) {
  stream << scalar_force.Print();
  return stream;
}

template <typename NumericType>
inline constexpr ScalarForce<NumericType> operator*(
    const NumericType number, const ScalarForce<NumericType>& scalar_force) {
  return scalar_force * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::ScalarForce<NumericType>> {
  inline size_t operator()(const PhQ::ScalarForce<NumericType>& scalar_force) const {
    return hash<NumericType>()(scalar_force.Value());
  }
};

}  // namespace std

#endif  // PHQ_SCALAR_FORCE_HPP
