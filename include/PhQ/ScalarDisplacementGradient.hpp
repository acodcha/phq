// Copyright 2020-2023 Alexandre Coderre-Chabot
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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DISPLACEMENT_GRADIENT_SCALAR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DISPLACEMENT_GRADIENT_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"

namespace PhQ {

// Forward declarations for class ScalarDisplacementGradient.
class Frequency;
class ScalarVelocityGradient;
class Time;

// Scalar component or resultant of a displacement gradient tensor. See also
// PhQ::DisplacementGradient and PhQ::ScalarVelocityGradient.
class ScalarDisplacementGradient : public DimensionlessScalar {
public:
  // Default constructor. Constructs a scalar displacement gradient with an uninitialized value.
  ScalarDisplacementGradient() = default;

  // Constructor. Constructs a scalar displacement gradient with a given value.
  explicit constexpr ScalarDisplacementGradient(const double value) : DimensionlessScalar(value) {}

  // Constructor. Constructs a scalar displacement gradient from a given scalar velocity gradient
  // and time using the definition of speed.
  constexpr ScalarDisplacementGradient(
      const ScalarVelocityGradient& scalar_velocity_gradient, const Time& time);

  // Constructor. Constructs a scalar displacement gradient from a given scalar velocity gradient
  // and frequency using the definition of speed.
  constexpr ScalarDisplacementGradient(
      const ScalarVelocityGradient& scalar_velocity_gradient, const Frequency& frequency);

  // Destructor. Destroys this scalar displacement gradient.
  ~ScalarDisplacementGradient() noexcept = default;

  // Copy constructor. Constructs a scalar displacement gradient by copying another one.
  constexpr ScalarDisplacementGradient(const ScalarDisplacementGradient& other) = default;

  // Move constructor. Constructs a scalar displacement gradient by moving another one.
  constexpr ScalarDisplacementGradient(ScalarDisplacementGradient&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar displacement gradient by copying another one.
  constexpr ScalarDisplacementGradient& operator=(
      const ScalarDisplacementGradient& other) = default;

  // Move assignment operator. Assigns this scalar displacement gradient by moving another one.
  constexpr ScalarDisplacementGradient& operator=(
      ScalarDisplacementGradient&& other) noexcept = default;

  // Statically creates a scalar displacement gradient of zero.
  static constexpr ScalarDisplacementGradient Zero() {
    return ScalarDisplacementGradient{0.0};
  }

  constexpr ScalarDisplacementGradient operator+(
      const ScalarDisplacementGradient& scalar_displacement_gradient) const {
    return ScalarDisplacementGradient{value_ + scalar_displacement_gradient.value_};
  }

  constexpr ScalarDisplacementGradient operator-(
      const ScalarDisplacementGradient& scalar_displacement_gradient) const {
    return ScalarDisplacementGradient{value_ - scalar_displacement_gradient.value_};
  }

  constexpr ScalarDisplacementGradient operator*(const double number) const {
    return ScalarDisplacementGradient{value_ * number};
  }

  constexpr ScalarVelocityGradient operator*(const Frequency& frequency) const;

  constexpr ScalarDisplacementGradient operator/(const double number) const {
    return ScalarDisplacementGradient{value_ / number};
  }

  constexpr ScalarVelocityGradient operator/(const Time& time) const;

  constexpr double operator/(
      const ScalarDisplacementGradient& scalar_displacement_gradient) const noexcept {
    return value_ / scalar_displacement_gradient.value_;
  }

  constexpr void operator+=(
      const ScalarDisplacementGradient& scalar_displacement_gradient) noexcept {
    value_ += scalar_displacement_gradient.value_;
  }

  constexpr void operator-=(
      const ScalarDisplacementGradient& scalar_displacement_gradient) noexcept {
    value_ -= scalar_displacement_gradient.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }
};

inline constexpr bool operator==(
    const ScalarDisplacementGradient& left, const ScalarDisplacementGradient& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const ScalarDisplacementGradient& left, const ScalarDisplacementGradient& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const ScalarDisplacementGradient& left, const ScalarDisplacementGradient& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const ScalarDisplacementGradient& left, const ScalarDisplacementGradient& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const ScalarDisplacementGradient& left, const ScalarDisplacementGradient& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const ScalarDisplacementGradient& left, const ScalarDisplacementGradient& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const ScalarDisplacementGradient& scalar_displacement_gradient) {
  stream << scalar_displacement_gradient.Print();
  return stream;
}

inline constexpr ScalarDisplacementGradient operator*(
    const double number, const ScalarDisplacementGradient& scalar_displacement_gradient) {
  return ScalarDisplacementGradient{number * scalar_displacement_gradient.Value()};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ScalarDisplacementGradient> {
  inline size_t operator()(
      const PhQ::ScalarDisplacementGradient& scalar_displacement_gradient) const {
    return hash<double>()(scalar_displacement_gradient.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DISPLACEMENT_GRADIENT_SCALAR_HPP
