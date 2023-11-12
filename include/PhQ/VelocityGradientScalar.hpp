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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_VELOCITY_GRADIENT_SCALAR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_VELOCITY_GRADIENT_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "DisplacementGradientScalar.hpp"
#include "Frequency.hpp"
#include "Time.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

// Scalar component or resultant of a velocity gradient tensor. Time rate of change of a scalar
// displacement gradient.
class VelocityGradientScalar : public DimensionalScalar<Unit::Frequency> {
public:
  // Default constructor. Constructs a scalar velocity gradient with an uninitialized value.
  VelocityGradientScalar() = default;

  // Constructor. Constructs a scalar velocity gradient with a given value expressed in a given
  // frequency unit.
  VelocityGradientScalar(const double value, const Unit::Frequency unit)
    : DimensionalScalar<Unit::Frequency>(value, unit) {}

  // Constructor. Constructs a scalar velocity gradient from a given scalar displacement gradient
  // and time using the definition of speed.
  constexpr VelocityGradientScalar(
      const DisplacementGradientScalar& displacement_gradient_scalar, const Time& time)
    : VelocityGradientScalar(displacement_gradient_scalar.Value() / time.Value()) {}

  // Constructor. Constructs a scalar velocity gradient from a given scalar displacement gradient
  // and frequency using the definition of speed.
  constexpr VelocityGradientScalar(
      const DisplacementGradientScalar& displacement_gradient_scalar, const Frequency& frequency)
    : VelocityGradientScalar(displacement_gradient_scalar.Value() * frequency.Value()) {}

  // Destructor. Destroys this scalar velocity gradient.
  ~VelocityGradientScalar() noexcept = default;

  // Copy constructor. Constructs a scalar velocity gradient by copying another one.
  constexpr VelocityGradientScalar(const VelocityGradientScalar& other) = default;

  // Move constructor. Constructs a scalar velocity gradient by moving another one.
  constexpr VelocityGradientScalar(VelocityGradientScalar&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar velocity gradient by copying another one.
  constexpr VelocityGradientScalar& operator=(const VelocityGradientScalar& other) = default;

  // Move assignment operator. Assigns this scalar velocity gradient by moving another one.
  constexpr VelocityGradientScalar& operator=(VelocityGradientScalar&& other) noexcept = default;

  // Statically creates a scalar velocity gradient of zero.
  static constexpr VelocityGradientScalar Zero() {
    return VelocityGradientScalar{0.0};
  }

  // Statically creates a scalar velocity gradient with a given value expressed in a given frequency
  // unit.
  template <Unit::Frequency Unit>
  static constexpr VelocityGradientScalar Create(const double value) {
    return VelocityGradientScalar{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  constexpr VelocityGradientScalar operator+(const VelocityGradientScalar& other) const {
    return VelocityGradientScalar{value_ + other.value_};
  }

  constexpr VelocityGradientScalar operator-(const VelocityGradientScalar& other) const {
    return VelocityGradientScalar{value_ - other.value_};
  }

  constexpr VelocityGradientScalar operator*(const double number) const {
    return VelocityGradientScalar{value_ * number};
  }

  constexpr VelocityGradientScalar operator/(const double number) const {
    return VelocityGradientScalar{value_ / number};
  }

  constexpr DisplacementGradientScalar operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr double operator/(const VelocityGradientScalar& other) const noexcept {
    return value_ / other.value_;
  }

  constexpr DisplacementGradientScalar operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr void operator+=(const VelocityGradientScalar& other) noexcept {
    value_ += other.value_;
  }

  constexpr void operator-=(const VelocityGradientScalar& other) noexcept {
    value_ -= other.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a scalar velocity gradient with a given value expressed in the standard
  // frequency unit.
  explicit constexpr VelocityGradientScalar(const double value)
    : DimensionalScalar<Unit::Frequency>(value) {}

  friend class VelocityGradient;
};

inline constexpr bool operator==(
    const VelocityGradientScalar& left, const VelocityGradientScalar& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const VelocityGradientScalar& left, const VelocityGradientScalar& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const VelocityGradientScalar& left, const VelocityGradientScalar& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const VelocityGradientScalar& left, const VelocityGradientScalar& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const VelocityGradientScalar& left, const VelocityGradientScalar& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const VelocityGradientScalar& left, const VelocityGradientScalar& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const VelocityGradientScalar& velocity_gradient_scalar) {
  stream << velocity_gradient_scalar.Print();
  return stream;
}

inline constexpr VelocityGradientScalar operator*(
    const double number, const VelocityGradientScalar& velocity_gradient_scalar) {
  return velocity_gradient_scalar * number;
}

inline constexpr DisplacementGradientScalar::DisplacementGradientScalar(
    const VelocityGradientScalar& velocity_gradient_scalar, const Time& time)
  : DisplacementGradientScalar(velocity_gradient_scalar.Value() * time.Value()) {}

inline constexpr DisplacementGradientScalar::DisplacementGradientScalar(
    const VelocityGradientScalar& velocity_gradient_scalar, const Frequency& frequency)
  : DisplacementGradientScalar(velocity_gradient_scalar.Value() / frequency.Value()) {}

inline constexpr VelocityGradientScalar DisplacementGradientScalar::operator*(
    const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr VelocityGradientScalar DisplacementGradientScalar::operator/(
    const Time& time) const {
  return {*this, time};
}

inline constexpr DisplacementGradientScalar Time::operator*(
    const VelocityGradientScalar& velocity_gradient_scalar) const {
  return {velocity_gradient_scalar, *this};
}

inline constexpr VelocityGradientScalar Frequency::operator*(
    const DisplacementGradientScalar& displacement_gradient_scalar) const {
  return {displacement_gradient_scalar, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::VelocityGradientScalar> {
  inline size_t operator()(const PhQ::VelocityGradientScalar& velocity_gradient_scalar) const {
    return hash<double>()(velocity_gradient_scalar.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_VELOCITY_GRADIENT_SCALAR_HPP
