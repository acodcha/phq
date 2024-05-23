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
template <typename Number>
class Direction;

// Forward declaration for class PhQ::ScalarForce.
template <typename Number>
class Force;

// Forward declaration for class PhQ::ScalarForce.
template <typename Number>
class ScalarTraction;

// Forward declaration for class PhQ::ScalarForce.
template <typename Number>
class StaticPressure;

/// \brief Scalar force component or magnitude of a force vector. See also PhQ::Force.
template <typename Number = double>
class ScalarForce : public DimensionalScalar<Unit::Force, Number> {
public:
  /// \brief Default constructor. Constructs a scalar force with an uninitialized value.
  ScalarForce() = default;

  /// \brief Constructor. Constructs a scalar force with a given value expressed in a given force
  /// unit.
  ScalarForce(const Number value, const Unit::Force unit)
    : DimensionalScalar<Unit::Force, Number>(value, unit) {}

  /// \brief Constructor. Constructs a scalar force from a given scalar traction and area using the
  /// definition of traction.
  constexpr ScalarForce(const ScalarTraction<Number>& scalar_traction, const Area<Number>& area);

  /// \brief Constructor. Constructs a scalar force from a given static pressure and area using the
  /// definition of pressure.
  constexpr ScalarForce(const StaticPressure<Number>& static_pressure, const Area<Number>& area);

  /// \brief Destructor. Destroys this scalar force.
  ~ScalarForce() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar force by copying another one.
  constexpr ScalarForce(const ScalarForce<Number>& other) = default;

  /// \brief Copy constructor. Constructs a scalar force by copying another one.
  template <typename OtherNumber>
  explicit constexpr ScalarForce(const ScalarForce<OtherNumber>& other)
    : ScalarForce(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar force by moving another one.
  constexpr ScalarForce(ScalarForce<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar force by copying another one.
  constexpr ScalarForce<Number>& operator=(const ScalarForce<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar force by copying another one.
  template <typename OtherNumber>
  constexpr ScalarForce<Number>& operator=(const ScalarForce<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar force by moving another one.
  constexpr ScalarForce<Number>& operator=(ScalarForce<Number>&& other) noexcept = default;

  /// \brief Statically creates a scalar force of zero.
  static constexpr ScalarForce<Number> Zero() {
    return ScalarForce<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a scalar force with a given value expressed in a given force unit.
  template <Unit::Force Unit>
  static constexpr ScalarForce<Number> Create(const Number value) {
    return ScalarForce<Number>{StaticConvertCopy<Unit::Force, Unit, Standard<Unit::Force>>(value)};
  }

  constexpr ScalarForce<Number> operator+(const ScalarForce<Number>& scalar_force) const {
    return ScalarForce<Number>{this->value + scalar_force.value};
  }

  constexpr ScalarForce<Number> operator-(const ScalarForce<Number>& scalar_force) const {
    return ScalarForce<Number>{this->value - scalar_force.value};
  }

  constexpr ScalarForce<Number> operator*(const Number number) const {
    return ScalarForce<Number>{this->value * number};
  }

  constexpr Force<Number> operator*(const Direction<Number>& direction) const;

  constexpr ScalarForce<Number> operator/(const Number number) const {
    return ScalarForce<Number>{this->value / number};
  }

  constexpr StaticPressure<Number> operator/(const Area<Number>& area) const;

  constexpr Number operator/(const ScalarForce<Number>& scalar_force) const noexcept {
    return this->value / scalar_force.value;
  }

  constexpr void operator+=(const ScalarForce<Number>& scalar_force) noexcept {
    this->value += scalar_force.value;
  }

  constexpr void operator-=(const ScalarForce<Number>& scalar_force) noexcept {
    this->value -= scalar_force.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a scalar force with a given value expressed in the standard
  /// force unit.
  explicit constexpr ScalarForce(const Number value)
    : DimensionalScalar<Unit::Force, Number>(value) {}

  template <typename OtherNumber>
  friend class Force;
};

template <typename Number>
inline constexpr bool operator==(
    const ScalarForce<Number>& left, const ScalarForce<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const ScalarForce<Number>& left, const ScalarForce<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const ScalarForce<Number>& left, const ScalarForce<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const ScalarForce<Number>& left, const ScalarForce<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const ScalarForce<Number>& left, const ScalarForce<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const ScalarForce<Number>& left, const ScalarForce<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const ScalarForce<Number>& scalar_force) {
  stream << scalar_force.Print();
  return stream;
}

template <typename Number>
inline constexpr ScalarForce<Number> operator*(
    const Number number, const ScalarForce<Number>& scalar_force) {
  return scalar_force * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ScalarForce<Number>> {
  inline size_t operator()(const PhQ::ScalarForce<Number>& scalar_force) const {
    return hash<Number>()(scalar_force.Value());
  }
};

}  // namespace std

#endif  // PHQ_SCALAR_FORCE_HPP
