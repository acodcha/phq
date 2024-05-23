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

/// \brief Scalar component or resultant of a velocity gradient tensor. Time rate of change of a
/// scalar displacement gradient. See also PhQ::VelocityGradient and
/// PhQ::ScalarDisplacementGradient.
template <typename Number = double>
class ScalarVelocityGradient : public DimensionalScalar<Unit::Frequency, Number> {
public:
  /// \brief Default constructor. Constructs a scalar velocity gradient with an uninitialized value.
  ScalarVelocityGradient() = default;

  /// \brief Constructor. Constructs a scalar velocity gradient with a given value expressed in a
  /// given frequency unit.
  ScalarVelocityGradient(const Number value, const Unit::Frequency unit)
    : DimensionalScalar<Unit::Frequency, Number>(value, unit) {}

  /// \brief Constructor. Constructs a scalar velocity gradient from a given scalar displacement
  /// gradient and time using the definition of speed.
  constexpr ScalarVelocityGradient(
      const ScalarDisplacementGradient<Number>& scalar_displacement_gradient,
      const Time<Number>& time)
    : ScalarVelocityGradient<Number>(scalar_displacement_gradient.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a scalar velocity gradient from a given scalar displacement
  /// gradient and frequency using the definition of speed.
  constexpr ScalarVelocityGradient(
      const ScalarDisplacementGradient<Number>& scalar_displacement_gradient,
      const Frequency<Number>& frequency)
    : ScalarVelocityGradient<Number>(scalar_displacement_gradient.Value() * frequency.Value()) {}

  /// \brief Destructor. Destroys this scalar velocity gradient.
  ~ScalarVelocityGradient() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar velocity gradient by copying another one.
  constexpr ScalarVelocityGradient(const ScalarVelocityGradient<Number>& other) = default;

  /// \brief Copy constructor. Constructs a scalar velocity gradient by copying another one.
  template <typename OtherNumber>
  explicit constexpr ScalarVelocityGradient(const ScalarVelocityGradient<OtherNumber>& other)
    : ScalarVelocityGradient(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar velocity gradient by moving another one.
  constexpr ScalarVelocityGradient(ScalarVelocityGradient<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar velocity gradient by copying another one.
  constexpr ScalarVelocityGradient<Number>& operator=(
      const ScalarVelocityGradient<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar velocity gradient by copying another one.
  template <typename OtherNumber>
  constexpr ScalarVelocityGradient<Number>& operator=(
      const ScalarVelocityGradient<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar velocity gradient by moving another one.
  constexpr ScalarVelocityGradient<Number>& operator=(
      ScalarVelocityGradient<Number>&& other) noexcept = default;

  /// \brief Statically creates a scalar velocity gradient of zero.
  static constexpr ScalarVelocityGradient<Number> Zero() {
    return ScalarVelocityGradient<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a scalar velocity gradient with a given value expressed in a given
  /// frequency unit.
  template <Unit::Frequency Unit>
  static constexpr ScalarVelocityGradient<Number> Create(const Number value) {
    return ScalarVelocityGradient<Number>{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  constexpr ScalarVelocityGradient<Number> operator+(
      const ScalarVelocityGradient<Number>& other) const {
    return ScalarVelocityGradient<Number>{this->value + other.value};
  }

  constexpr ScalarVelocityGradient<Number> operator-(
      const ScalarVelocityGradient<Number>& other) const {
    return ScalarVelocityGradient<Number>{this->value - other.value};
  }

  constexpr ScalarVelocityGradient<Number> operator*(const Number number) const {
    return ScalarVelocityGradient<Number>{this->value * number};
  }

  constexpr ScalarVelocityGradient<Number> operator/(const Number number) const {
    return ScalarVelocityGradient<Number>{this->value / number};
  }

  constexpr ScalarDisplacementGradient<Number> operator*(const Time<Number>& time) const {
    return ScalarDisplacementGradient<Number>{*this, time};
  }

  constexpr Number operator/(const ScalarVelocityGradient<Number>& other) const noexcept {
    return this->value / other.value;
  }

  constexpr ScalarDisplacementGradient<Number> operator/(const Frequency<Number>& frequency) const {
    return ScalarDisplacementGradient<Number>{*this, frequency};
  }

  constexpr void operator+=(const ScalarVelocityGradient<Number>& other) noexcept {
    this->value += other.value;
  }

  constexpr void operator-=(const ScalarVelocityGradient<Number>& other) noexcept {
    this->value -= other.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a scalar velocity gradient with a given value expressed in the
  /// standard frequency unit.
  explicit constexpr ScalarVelocityGradient(const Number value)
    : DimensionalScalar<Unit::Frequency, Number>(value) {}

  template <typename OtherNumber>
  friend class VelocityGradient;
};

template <typename Number>
inline constexpr bool operator==(const ScalarVelocityGradient<Number>& left,
                                 const ScalarVelocityGradient<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const ScalarVelocityGradient<Number>& left,
                                 const ScalarVelocityGradient<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const ScalarVelocityGradient<Number>& left,
                                const ScalarVelocityGradient<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const ScalarVelocityGradient<Number>& left,
                                const ScalarVelocityGradient<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const ScalarVelocityGradient<Number>& left,
                                 const ScalarVelocityGradient<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const ScalarVelocityGradient<Number>& left,
                                 const ScalarVelocityGradient<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const ScalarVelocityGradient<Number>& scalar_velocity_gradient) {
  stream << scalar_velocity_gradient.Print();
  return stream;
}

template <typename Number>
inline constexpr ScalarVelocityGradient<Number> operator*(
    const Number number, const ScalarVelocityGradient<Number>& scalar_velocity_gradient) {
  return scalar_velocity_gradient * number;
}

template <typename Number>
inline constexpr ScalarDisplacementGradient<Number>::ScalarDisplacementGradient(
    const ScalarVelocityGradient<Number>& scalar_velocity_gradient, const Time<Number>& time)
  : ScalarDisplacementGradient<Number>(scalar_velocity_gradient.Value() * time.Value()) {}

template <typename Number>
inline constexpr ScalarDisplacementGradient<Number>::ScalarDisplacementGradient(
    const ScalarVelocityGradient<Number>& scalar_velocity_gradient,
    const Frequency<Number>& frequency)
  : ScalarDisplacementGradient<Number>(scalar_velocity_gradient.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr ScalarVelocityGradient<Number> ScalarDisplacementGradient<Number>::operator*(
    const Frequency<Number>& frequency) const {
  return ScalarVelocityGradient<Number>{*this, frequency};
}

template <typename Number>
inline constexpr ScalarVelocityGradient<Number> ScalarDisplacementGradient<Number>::operator/(
    const Time<Number>& time) const {
  return ScalarVelocityGradient<Number>{*this, time};
}

template <typename Number>
inline constexpr ScalarDisplacementGradient<Number> Time<Number>::operator*(
    const ScalarVelocityGradient<Number>& scalar_velocity_gradient) const {
  return ScalarDisplacementGradient<Number>{scalar_velocity_gradient, *this};
}

template <typename Number>
inline constexpr ScalarVelocityGradient<Number> Frequency<Number>::operator*(
    const ScalarDisplacementGradient<Number>& scalar_displacement_gradient) const {
  return ScalarVelocityGradient<Number>{scalar_displacement_gradient, *this};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ScalarVelocityGradient<Number>> {
  inline size_t operator()(
      const PhQ::ScalarVelocityGradient<Number>& scalar_velocity_gradient) const {
    return hash<Number>()(scalar_velocity_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_SCALAR_VELOCITY_GRADIENT_HPP
