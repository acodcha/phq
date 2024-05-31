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

#ifndef PHQ_SCALAR_DISPLACEMENT_GRADIENT_HPP
#define PHQ_SCALAR_DISPLACEMENT_GRADIENT_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ScalarDisplacementGradient.
template <typename NumericType>
class Frequency;

// Forward declaration for class PhQ::ScalarDisplacementGradient.
template <typename NumericType>
class ScalarVelocityGradient;

// Forward declaration for class PhQ::ScalarDisplacementGradient.
template <typename NumericType>
class Time;

/// \brief Scalar component or resultant of a three-dimensional Euclidean displacement gradient
/// dyadic tensor. For the related tensor, see PhQ::DisplacementGradient. The time rate of change of
/// a scalar displacement gradient is a scalar velocity gradient; see PhQ::ScalarVelocityGradient,
/// PhQ::Time, and PhQ::Frequency.
template <typename NumericType = double>
class ScalarDisplacementGradient : public DimensionlessScalar<NumericType> {
public:
  /// \brief Default constructor. Constructs a scalar displacement gradient with an uninitialized
  /// value.
  ScalarDisplacementGradient() = default;

  /// \brief Constructor. Constructs a scalar displacement gradient with a given value.
  explicit constexpr ScalarDisplacementGradient(const NumericType value)
    : DimensionlessScalar<NumericType>(value) {}

  /// \brief Constructor. Constructs a scalar displacement gradient from a given scalar velocity
  /// gradient and time using the definition of speed.
  constexpr ScalarDisplacementGradient(
      const ScalarVelocityGradient<NumericType>& scalar_velocity_gradient,
      const Time<NumericType>& time);

  /// \brief Constructor. Constructs a scalar displacement gradient from a given scalar velocity
  /// gradient and frequency using the definition of speed.
  constexpr ScalarDisplacementGradient(
      const ScalarVelocityGradient<NumericType>& scalar_velocity_gradient,
      const Frequency<NumericType>& frequency);

  /// \brief Destructor. Destroys this scalar displacement gradient.
  ~ScalarDisplacementGradient() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar displacement gradient by copying another one.
  constexpr ScalarDisplacementGradient(
      const ScalarDisplacementGradient<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a scalar displacement gradient by copying another one.
  template <typename OtherNumericType>
  explicit constexpr ScalarDisplacementGradient(
      const ScalarDisplacementGradient<OtherNumericType>& other)
    : ScalarDisplacementGradient(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar displacement gradient by moving another one.
  constexpr ScalarDisplacementGradient(
      ScalarDisplacementGradient<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar displacement gradient by copying another
  /// one.
  constexpr ScalarDisplacementGradient<NumericType>& operator=(
      const ScalarDisplacementGradient<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar displacement gradient by copying another
  /// one.
  template <typename OtherNumericType>
  constexpr ScalarDisplacementGradient<NumericType>& operator=(
      const ScalarDisplacementGradient<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar displacement gradient by moving another
  /// one.
  constexpr ScalarDisplacementGradient<NumericType>& operator=(
      ScalarDisplacementGradient<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a scalar displacement gradient of zero.
  static constexpr ScalarDisplacementGradient<NumericType> Zero() {
    return ScalarDisplacementGradient<NumericType>{static_cast<NumericType>(0)};
  }

  constexpr ScalarDisplacementGradient<NumericType> operator+(
      const ScalarDisplacementGradient<NumericType>& scalar_displacement_gradient) const {
    return ScalarDisplacementGradient<NumericType>{
        this->value + scalar_displacement_gradient.value};
  }

  constexpr ScalarDisplacementGradient<NumericType> operator-(
      const ScalarDisplacementGradient<NumericType>& scalar_displacement_gradient) const {
    return ScalarDisplacementGradient<NumericType>{
        this->value - scalar_displacement_gradient.value};
  }

  constexpr ScalarDisplacementGradient<NumericType> operator*(const NumericType number) const {
    return ScalarDisplacementGradient<NumericType>{this->value * number};
  }

  constexpr ScalarVelocityGradient<NumericType> operator*(
      const Frequency<NumericType>& frequency) const;

  constexpr ScalarDisplacementGradient<NumericType> operator/(const NumericType number) const {
    return ScalarDisplacementGradient<NumericType>{this->value / number};
  }

  constexpr ScalarVelocityGradient<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr NumericType operator/(
      const ScalarDisplacementGradient<NumericType>& scalar_displacement_gradient) const noexcept {
    return this->value / scalar_displacement_gradient.value;
  }

  constexpr void operator+=(
      const ScalarDisplacementGradient<NumericType>& scalar_displacement_gradient) noexcept {
    this->value += scalar_displacement_gradient.value;
  }

  constexpr void operator-=(
      const ScalarDisplacementGradient<NumericType>& scalar_displacement_gradient) noexcept {
    this->value -= scalar_displacement_gradient.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }
};

template <typename NumericType>
inline constexpr bool operator==(const ScalarDisplacementGradient<NumericType>& left,
                                 const ScalarDisplacementGradient<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const ScalarDisplacementGradient<NumericType>& left,
                                 const ScalarDisplacementGradient<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const ScalarDisplacementGradient<NumericType>& left,
                                const ScalarDisplacementGradient<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const ScalarDisplacementGradient<NumericType>& left,
                                const ScalarDisplacementGradient<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const ScalarDisplacementGradient<NumericType>& left,
                                 const ScalarDisplacementGradient<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const ScalarDisplacementGradient<NumericType>& left,
                                 const ScalarDisplacementGradient<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream,
    const ScalarDisplacementGradient<NumericType>& scalar_displacement_gradient) {
  stream << scalar_displacement_gradient.Print();
  return stream;
}

template <typename NumericType>
inline constexpr ScalarDisplacementGradient<NumericType> operator*(
    const NumericType number,
    const ScalarDisplacementGradient<NumericType>& scalar_displacement_gradient) {
  return ScalarDisplacementGradient<NumericType>{number * scalar_displacement_gradient.Value()};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::ScalarDisplacementGradient<NumericType>> {
  inline size_t operator()(
      const PhQ::ScalarDisplacementGradient<NumericType>& scalar_displacement_gradient) const {
    return hash<NumericType>()(scalar_displacement_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_SCALAR_DISPLACEMENT_GRADIENT_HPP
