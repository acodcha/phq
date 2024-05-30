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

#ifndef PHQ_SCALAR_VELOCITY_GRADIENT_HPP
#define PHQ_SCALAR_VELOCITY_GRADIENT_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "ScalarDisplacementGradient.hpp"
#include "Time.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

/// \brief Scalar component or resultant of a three-dimensional Euclidean velocity gradient dyadic
/// tensor. For the related tensor, see PhQ::VelocityGradient. Can also represent the time rate of
/// change of a scalar displacement gradient; see PhQ::ScalarDisplacementGradient, PhQ::Time, and
/// PhQ::Frequency.
template <typename NumericType = double>
class ScalarVelocityGradient : public DimensionalScalar<Unit::Frequency, NumericType> {
public:
  /// \brief Default constructor. Constructs a scalar velocity gradient with an uninitialized value.
  ScalarVelocityGradient() = default;

  /// \brief Constructor. Constructs a scalar velocity gradient with a given value expressed in a
  /// given frequency unit.
  ScalarVelocityGradient(const NumericType value, const Unit::Frequency unit)
    : DimensionalScalar<Unit::Frequency, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a scalar velocity gradient from a given scalar displacement
  /// gradient and time using the definition of speed.
  constexpr ScalarVelocityGradient(
      const ScalarDisplacementGradient<NumericType>& scalar_displacement_gradient,
      const Time<NumericType>& time)
    : ScalarVelocityGradient<NumericType>(scalar_displacement_gradient.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a scalar velocity gradient from a given scalar displacement
  /// gradient and frequency using the definition of speed.
  constexpr ScalarVelocityGradient(
      const ScalarDisplacementGradient<NumericType>& scalar_displacement_gradient,
      const Frequency<NumericType>& frequency)
    : ScalarVelocityGradient<NumericType>(
        scalar_displacement_gradient.Value() * frequency.Value()) {}

  /// \brief Destructor. Destroys this scalar velocity gradient.
  ~ScalarVelocityGradient() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar velocity gradient by copying another one.
  constexpr ScalarVelocityGradient(const ScalarVelocityGradient<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a scalar velocity gradient by copying another one.
  template <typename OtherNumericType>
  explicit constexpr ScalarVelocityGradient(const ScalarVelocityGradient<OtherNumericType>& other)
    : ScalarVelocityGradient(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar velocity gradient by moving another one.
  constexpr ScalarVelocityGradient(ScalarVelocityGradient<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar velocity gradient by copying another one.
  constexpr ScalarVelocityGradient<NumericType>& operator=(
      const ScalarVelocityGradient<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar velocity gradient by copying another one.
  template <typename OtherNumericType>
  constexpr ScalarVelocityGradient<NumericType>& operator=(
      const ScalarVelocityGradient<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar velocity gradient by moving another one.
  constexpr ScalarVelocityGradient<NumericType>& operator=(
      ScalarVelocityGradient<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a scalar velocity gradient of zero.
  static constexpr ScalarVelocityGradient<NumericType> Zero() {
    return ScalarVelocityGradient<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a scalar velocity gradient with a given value expressed in a given
  /// frequency unit.
  template <Unit::Frequency Unit>
  static constexpr ScalarVelocityGradient<NumericType> Create(const NumericType value) {
    return ScalarVelocityGradient<NumericType>{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  constexpr ScalarVelocityGradient<NumericType> operator+(
      const ScalarVelocityGradient<NumericType>& other) const {
    return ScalarVelocityGradient<NumericType>{this->value + other.value};
  }

  constexpr ScalarVelocityGradient<NumericType> operator-(
      const ScalarVelocityGradient<NumericType>& other) const {
    return ScalarVelocityGradient<NumericType>{this->value - other.value};
  }

  constexpr ScalarVelocityGradient<NumericType> operator*(const NumericType number) const {
    return ScalarVelocityGradient<NumericType>{this->value * number};
  }

  constexpr ScalarVelocityGradient<NumericType> operator/(const NumericType number) const {
    return ScalarVelocityGradient<NumericType>{this->value / number};
  }

  constexpr ScalarDisplacementGradient<NumericType> operator*(const Time<NumericType>& time) const {
    return ScalarDisplacementGradient<NumericType>{*this, time};
  }

  constexpr NumericType operator/(const ScalarVelocityGradient<NumericType>& other) const noexcept {
    return this->value / other.value;
  }

  constexpr ScalarDisplacementGradient<NumericType> operator/(
      const Frequency<NumericType>& frequency) const {
    return ScalarDisplacementGradient<NumericType>{*this, frequency};
  }

  constexpr void operator+=(const ScalarVelocityGradient<NumericType>& other) noexcept {
    this->value += other.value;
  }

  constexpr void operator-=(const ScalarVelocityGradient<NumericType>& other) noexcept {
    this->value -= other.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a scalar velocity gradient with a given value expressed in the
  /// standard frequency unit.
  explicit constexpr ScalarVelocityGradient(const NumericType value)
    : DimensionalScalar<Unit::Frequency, NumericType>(value) {}

  template <typename OtherNumericType>
  friend class VelocityGradient;
};

template <typename NumericType>
inline constexpr bool operator==(const ScalarVelocityGradient<NumericType>& left,
                                 const ScalarVelocityGradient<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const ScalarVelocityGradient<NumericType>& left,
                                 const ScalarVelocityGradient<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const ScalarVelocityGradient<NumericType>& left,
                                const ScalarVelocityGradient<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const ScalarVelocityGradient<NumericType>& left,
                                const ScalarVelocityGradient<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const ScalarVelocityGradient<NumericType>& left,
                                 const ScalarVelocityGradient<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const ScalarVelocityGradient<NumericType>& left,
                                 const ScalarVelocityGradient<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const ScalarVelocityGradient<NumericType>& scalar_velocity_gradient) {
  stream << scalar_velocity_gradient.Print();
  return stream;
}

template <typename NumericType>
inline constexpr ScalarVelocityGradient<NumericType> operator*(
    const NumericType number, const ScalarVelocityGradient<NumericType>& scalar_velocity_gradient) {
  return scalar_velocity_gradient * number;
}

template <typename NumericType>
inline constexpr ScalarDisplacementGradient<NumericType>::ScalarDisplacementGradient(
    const ScalarVelocityGradient<NumericType>& scalar_velocity_gradient,
    const Time<NumericType>& time)
  : ScalarDisplacementGradient<NumericType>(scalar_velocity_gradient.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr ScalarDisplacementGradient<NumericType>::ScalarDisplacementGradient(
    const ScalarVelocityGradient<NumericType>& scalar_velocity_gradient,
    const Frequency<NumericType>& frequency)
  : ScalarDisplacementGradient<NumericType>(scalar_velocity_gradient.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr ScalarVelocityGradient<NumericType>
ScalarDisplacementGradient<NumericType>::operator*(const Frequency<NumericType>& frequency) const {
  return ScalarVelocityGradient<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr ScalarVelocityGradient<NumericType>
ScalarDisplacementGradient<NumericType>::operator/(const Time<NumericType>& time) const {
  return ScalarVelocityGradient<NumericType>{*this, time};
}

template <typename NumericType>
inline constexpr ScalarDisplacementGradient<NumericType> Time<NumericType>::operator*(
    const ScalarVelocityGradient<NumericType>& scalar_velocity_gradient) const {
  return ScalarDisplacementGradient<NumericType>{scalar_velocity_gradient, *this};
}

template <typename NumericType>
inline constexpr ScalarVelocityGradient<NumericType> Frequency<NumericType>::operator*(
    const ScalarDisplacementGradient<NumericType>& scalar_displacement_gradient) const {
  return ScalarVelocityGradient<NumericType>{scalar_displacement_gradient, *this};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::ScalarVelocityGradient<NumericType>> {
  inline size_t operator()(
      const PhQ::ScalarVelocityGradient<NumericType>& scalar_velocity_gradient) const {
    return hash<NumericType>()(scalar_velocity_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_SCALAR_VELOCITY_GRADIENT_HPP
