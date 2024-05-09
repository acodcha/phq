// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

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
    : value(static_cast<Number>(other.Value())) {}

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
    value = static_cast<Number>(other.Value());
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
    return ScalarDisplacementGradient<Number>{value + scalar_displacement_gradient.value};
  }

  constexpr ScalarDisplacementGradient<Number> operator-(
      const ScalarDisplacementGradient<Number>& scalar_displacement_gradient) const {
    return ScalarDisplacementGradient<Number>{value - scalar_displacement_gradient.value};
  }

  constexpr ScalarDisplacementGradient<Number> operator*(const Number number) const {
    return ScalarDisplacementGradient<Number>{value * number};
  }

  constexpr ScalarVelocityGradient<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr ScalarDisplacementGradient<Number> operator/(const Number number) const {
    return ScalarDisplacementGradient<Number>{value / number};
  }

  constexpr ScalarVelocityGradient<Number> operator/(const Time<Number>& time) const;

  constexpr Number operator/(
      const ScalarDisplacementGradient<Number>& scalar_displacement_gradient) const noexcept {
    return value / scalar_displacement_gradient.value;
  }

  constexpr void operator+=(
      const ScalarDisplacementGradient<Number>& scalar_displacement_gradient) noexcept {
    value += scalar_displacement_gradient.value;
  }

  constexpr void operator-=(
      const ScalarDisplacementGradient<Number>& scalar_displacement_gradient) noexcept {
    value -= scalar_displacement_gradient.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
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
