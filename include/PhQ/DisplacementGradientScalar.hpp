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

// Forward declarations for class DisplacementGradientScalar.
class Frequency;
class VelocityGradientScalar;
class Time;

// Scalar component or resultant of a displacement gradient tensor.
class DisplacementGradientScalar : public DimensionlessScalar {
public:
  // Default constructor. Constructs a scalar displacement gradient with an uninitialized value.
  DisplacementGradientScalar() = default;

  // Constructor. Constructs a scalar displacement gradient with a given value.
  explicit constexpr DisplacementGradientScalar(const double value) : DimensionlessScalar(value) {}

  // Constructor. Constructs a scalar displacement gradient from a given scalar velocity gradient
  // and time using the definition of speed.
  constexpr DisplacementGradientScalar(
      const VelocityGradientScalar& velocity_gradient_scalar, const Time& time);

  // Constructor. Constructs a scalar displacement gradient from a given scalar velocity gradient
  // and frequency using the definition of speed.
  constexpr DisplacementGradientScalar(
      const VelocityGradientScalar& velocity_gradient_scalar, const Frequency& frequency);

  // Destructor. Destroys this scalar displacement gradient.
  ~DisplacementGradientScalar() noexcept = default;

  // Copy constructor. Constructs a scalar displacement gradient by copying another one.
  constexpr DisplacementGradientScalar(const DisplacementGradientScalar& other) = default;

  // Move constructor. Constructs a scalar displacement gradient by moving another one.
  constexpr DisplacementGradientScalar(DisplacementGradientScalar&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar displacement gradient by copying another one.
  constexpr DisplacementGradientScalar& operator=(
      const DisplacementGradientScalar& other) = default;

  // Move assignment operator. Assigns this scalar displacement gradient by moving another one.
  constexpr DisplacementGradientScalar& operator=(
      DisplacementGradientScalar&& other) noexcept = default;

  // Statically creates a scalar displacement gradient of zero.
  static constexpr DisplacementGradientScalar Zero() {
    return DisplacementGradientScalar{0.0};
  }

  constexpr DisplacementGradientScalar operator+(
      const DisplacementGradientScalar& displacement_gradient_scalar) const {
    return DisplacementGradientScalar{value_ + displacement_gradient_scalar.value_};
  }

  constexpr DisplacementGradientScalar operator-(
      const DisplacementGradientScalar& displacement_gradient_scalar) const {
    return DisplacementGradientScalar{value_ - displacement_gradient_scalar.value_};
  }

  constexpr DisplacementGradientScalar operator*(const double number) const {
    return DisplacementGradientScalar{value_ * number};
  }

  constexpr VelocityGradientScalar operator*(const Frequency& frequency) const;

  constexpr DisplacementGradientScalar operator/(const double number) const {
    return DisplacementGradientScalar{value_ / number};
  }

  constexpr VelocityGradientScalar operator/(const Time& time) const;

  constexpr double operator/(
      const DisplacementGradientScalar& displacement_gradient_scalar) const noexcept {
    return value_ / displacement_gradient_scalar.value_;
  }

  constexpr void operator+=(
      const DisplacementGradientScalar& displacement_gradient_scalar) noexcept {
    value_ += displacement_gradient_scalar.value_;
  }

  constexpr void operator-=(
      const DisplacementGradientScalar& displacement_gradient_scalar) noexcept {
    value_ -= displacement_gradient_scalar.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }
};

inline constexpr bool operator==(
    const DisplacementGradientScalar& left, const DisplacementGradientScalar& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const DisplacementGradientScalar& left, const DisplacementGradientScalar& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const DisplacementGradientScalar& left, const DisplacementGradientScalar& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const DisplacementGradientScalar& left, const DisplacementGradientScalar& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const DisplacementGradientScalar& left, const DisplacementGradientScalar& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const DisplacementGradientScalar& left, const DisplacementGradientScalar& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const DisplacementGradientScalar& displacement_gradient_scalar) {
  stream << displacement_gradient_scalar.Print();
  return stream;
}

inline constexpr DisplacementGradientScalar operator*(
    const double number, const DisplacementGradientScalar& displacement_gradient_scalar) {
  return DisplacementGradientScalar{number * displacement_gradient_scalar.Value()};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::DisplacementGradientScalar> {
  inline size_t operator()(
      const PhQ::DisplacementGradientScalar& displacement_gradient_scalar) const {
    return hash<double>()(displacement_gradient_scalar.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DISPLACEMENT_GRADIENT_SCALAR_HPP
