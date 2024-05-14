// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
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

#ifndef PHQ_DISPLACEMENT_GRADIENT_SCALAR_HPP
#define PHQ_DISPLACEMENT_GRADIENT_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ScalarDisplacementGradient.
template <typename Number>
class Frequency;

// Forward declaration for class PhQ::ScalarDisplacementGradient.
template <typename Number>
class ScalarVelocityGradient;

// Forward declaration for class PhQ::ScalarDisplacementGradient.
template <typename Number>
class Time;

// Scalar component or resultant of a displacement gradient tensor. See also
// PhQ::DisplacementGradient and PhQ::ScalarVelocityGradient.
template <typename Number = double>
class ScalarDisplacementGradient : public DimensionlessScalar<Number> {
public:
  // Default constructor. Constructs a scalar displacement gradient with an uninitialized value.
  ScalarDisplacementGradient() = default;

  // Constructor. Constructs a scalar displacement gradient with a given value.
  explicit constexpr ScalarDisplacementGradient(const Number value)
    : DimensionlessScalar<Number>(value) {}

  // Constructor. Constructs a scalar displacement gradient from a given scalar velocity gradient
  // and time using the definition of speed.
  constexpr ScalarDisplacementGradient(
      const ScalarVelocityGradient<Number>& scalar_velocity_gradient, const Time<Number>& time);

  // Constructor. Constructs a scalar displacement gradient from a given scalar velocity gradient
  // and frequency using the definition of speed.
  constexpr ScalarDisplacementGradient(
      const ScalarVelocityGradient<Number>& scalar_velocity_gradient,
      const Frequency<Number>& frequency);

  // Destructor. Destroys this scalar displacement gradient.
  ~ScalarDisplacementGradient() noexcept = default;

  // Copy constructor. Constructs a scalar displacement gradient by copying another one.
  constexpr ScalarDisplacementGradient(const ScalarDisplacementGradient<Number>& other) = default;

  // Copy constructor. Constructs a scalar displacement gradient by copying another one.
  template <typename OtherNumber>
  explicit constexpr ScalarDisplacementGradient(
      const ScalarDisplacementGradient<OtherNumber>& other)
    : ScalarDisplacementGradient(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a scalar displacement gradient by moving another one.
  constexpr ScalarDisplacementGradient(
      ScalarDisplacementGradient<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar displacement gradient by copying another one.
  constexpr ScalarDisplacementGradient<Number>& operator=(
      const ScalarDisplacementGradient<Number>& other) = default;

  // Copy assignment operator. Assigns this scalar displacement gradient by copying another one.
  template <typename OtherNumber>
  constexpr ScalarDisplacementGradient<Number>& operator=(
      const ScalarDisplacementGradient<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this scalar displacement gradient by moving another one.
  constexpr ScalarDisplacementGradient<Number>& operator=(
      ScalarDisplacementGradient<Number>&& other) noexcept = default;

  // Statically creates a scalar displacement gradient of zero.
  static constexpr ScalarDisplacementGradient<Number> Zero() {
    return ScalarDisplacementGradient<Number>{static_cast<Number>(0)};
  }

  constexpr ScalarDisplacementGradient<Number> operator+(
      const ScalarDisplacementGradient<Number>& scalar_displacement_gradient) const {
    return ScalarDisplacementGradient<Number>{this->value + scalar_displacement_gradient.value};
  }

  constexpr ScalarDisplacementGradient<Number> operator-(
      const ScalarDisplacementGradient<Number>& scalar_displacement_gradient) const {
    return ScalarDisplacementGradient<Number>{this->value - scalar_displacement_gradient.value};
  }

  constexpr ScalarDisplacementGradient<Number> operator*(const Number number) const {
    return ScalarDisplacementGradient<Number>{this->value * number};
  }

  constexpr ScalarVelocityGradient<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr ScalarDisplacementGradient<Number> operator/(const Number number) const {
    return ScalarDisplacementGradient<Number>{this->value / number};
  }

  constexpr ScalarVelocityGradient<Number> operator/(const Time<Number>& time) const;

  constexpr Number operator/(
      const ScalarDisplacementGradient<Number>& scalar_displacement_gradient) const noexcept {
    return this->value / scalar_displacement_gradient.value;
  }

  constexpr void operator+=(
      const ScalarDisplacementGradient<Number>& scalar_displacement_gradient) noexcept {
    this->value += scalar_displacement_gradient.value;
  }

  constexpr void operator-=(
      const ScalarDisplacementGradient<Number>& scalar_displacement_gradient) noexcept {
    this->value -= scalar_displacement_gradient.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }
};

template <typename Number>
inline constexpr bool operator==(const ScalarDisplacementGradient<Number>& left,
                                 const ScalarDisplacementGradient<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const ScalarDisplacementGradient<Number>& left,
                                 const ScalarDisplacementGradient<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const ScalarDisplacementGradient<Number>& left,
                                const ScalarDisplacementGradient<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const ScalarDisplacementGradient<Number>& left,
                                const ScalarDisplacementGradient<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const ScalarDisplacementGradient<Number>& left,
                                 const ScalarDisplacementGradient<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const ScalarDisplacementGradient<Number>& left,
                                 const ScalarDisplacementGradient<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const ScalarDisplacementGradient<Number>& scalar_displacement_gradient) {
  stream << scalar_displacement_gradient.Print();
  return stream;
}

template <typename Number>
inline constexpr ScalarDisplacementGradient<Number> operator*(
    const Number number, const ScalarDisplacementGradient<Number>& scalar_displacement_gradient) {
  return ScalarDisplacementGradient<Number>{number * scalar_displacement_gradient.Value()};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ScalarDisplacementGradient<Number>> {
  inline size_t operator()(
      const PhQ::ScalarDisplacementGradient<Number>& scalar_displacement_gradient) const {
    return hash<Number>()(scalar_displacement_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_DISPLACEMENT_GRADIENT_SCALAR_HPP
