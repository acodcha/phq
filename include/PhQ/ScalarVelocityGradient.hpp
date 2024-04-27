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

#ifndef PHQ_VELOCITY_GRADIENT_SCALAR_HPP
#define PHQ_VELOCITY_GRADIENT_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "ScalarDisplacementGradient.hpp"
#include "Time.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

// Scalar component or resultant of a velocity gradient tensor. Time rate of change of a scalar
// displacement gradient. See also PhQ::VelocityGradient and PhQ::ScalarDisplacementGradient.
class ScalarVelocityGradient : public DimensionalScalar<Unit::Frequency> {
public:
  // Default constructor. Constructs a scalar velocity gradient with an uninitialized value.
  ScalarVelocityGradient() = default;

  // Constructor. Constructs a scalar velocity gradient with a given value expressed in a given
  // frequency unit.
  ScalarVelocityGradient(const double value, const Unit::Frequency unit)
    : DimensionalScalar<Unit::Frequency>(value, unit) {}

  // Constructor. Constructs a scalar velocity gradient from a given scalar displacement gradient
  // and time using the definition of speed.
  constexpr ScalarVelocityGradient(
      const ScalarDisplacementGradient& scalar_displacement_gradient, const Time& time)
    : ScalarVelocityGradient(scalar_displacement_gradient.Value() / time.Value()) {}

  // Constructor. Constructs a scalar velocity gradient from a given scalar displacement gradient
  // and frequency using the definition of speed.
  constexpr ScalarVelocityGradient(
      const ScalarDisplacementGradient& scalar_displacement_gradient, const Frequency& frequency)
    : ScalarVelocityGradient(scalar_displacement_gradient.Value() * frequency.Value()) {}

  // Destructor. Destroys this scalar velocity gradient.
  ~ScalarVelocityGradient() noexcept = default;

  // Copy constructor. Constructs a scalar velocity gradient by copying another one.
  constexpr ScalarVelocityGradient(const ScalarVelocityGradient& other) = default;

  // Move constructor. Constructs a scalar velocity gradient by moving another one.
  constexpr ScalarVelocityGradient(ScalarVelocityGradient&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar velocity gradient by copying another one.
  constexpr ScalarVelocityGradient& operator=(const ScalarVelocityGradient& other) = default;

  // Move assignment operator. Assigns this scalar velocity gradient by moving another one.
  constexpr ScalarVelocityGradient& operator=(ScalarVelocityGradient&& other) noexcept = default;

  // Statically creates a scalar velocity gradient of zero.
  static constexpr ScalarVelocityGradient Zero() {
    return ScalarVelocityGradient{0.0};
  }

  // Statically creates a scalar velocity gradient with a given value expressed in a given frequency
  // unit.
  template <Unit::Frequency Unit>
  static constexpr ScalarVelocityGradient Create(const double value) {
    return ScalarVelocityGradient{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  constexpr ScalarVelocityGradient operator+(const ScalarVelocityGradient& other) const {
    return ScalarVelocityGradient{value_ + other.value_};
  }

  constexpr ScalarVelocityGradient operator-(const ScalarVelocityGradient& other) const {
    return ScalarVelocityGradient{value_ - other.value_};
  }

  constexpr ScalarVelocityGradient operator*(const double number) const {
    return ScalarVelocityGradient{value_ * number};
  }

  constexpr ScalarVelocityGradient operator/(const double number) const {
    return ScalarVelocityGradient{value_ / number};
  }

  constexpr ScalarDisplacementGradient operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr double operator/(const ScalarVelocityGradient& other) const noexcept {
    return value_ / other.value_;
  }

  constexpr ScalarDisplacementGradient operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr void operator+=(const ScalarVelocityGradient& other) noexcept {
    value_ += other.value_;
  }

  constexpr void operator-=(const ScalarVelocityGradient& other) noexcept {
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
  explicit constexpr ScalarVelocityGradient(const double value)
    : DimensionalScalar<Unit::Frequency>(value) {}

  friend class VelocityGradient;
};

inline constexpr bool operator==(
    const ScalarVelocityGradient& left, const ScalarVelocityGradient& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const ScalarVelocityGradient& left, const ScalarVelocityGradient& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const ScalarVelocityGradient& left, const ScalarVelocityGradient& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const ScalarVelocityGradient& left, const ScalarVelocityGradient& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const ScalarVelocityGradient& left, const ScalarVelocityGradient& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const ScalarVelocityGradient& left, const ScalarVelocityGradient& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const ScalarVelocityGradient& scalar_velocity_gradient) {
  stream << scalar_velocity_gradient.Print();
  return stream;
}

inline constexpr ScalarVelocityGradient operator*(
    const double number, const ScalarVelocityGradient& scalar_velocity_gradient) {
  return scalar_velocity_gradient * number;
}

inline constexpr ScalarDisplacementGradient::ScalarDisplacementGradient(
    const ScalarVelocityGradient& scalar_velocity_gradient, const Time& time)
  : ScalarDisplacementGradient(scalar_velocity_gradient.Value() * time.Value()) {}

inline constexpr ScalarDisplacementGradient::ScalarDisplacementGradient(
    const ScalarVelocityGradient& scalar_velocity_gradient, const Frequency& frequency)
  : ScalarDisplacementGradient(scalar_velocity_gradient.Value() / frequency.Value()) {}

inline constexpr ScalarVelocityGradient ScalarDisplacementGradient::operator*(
    const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr ScalarVelocityGradient ScalarDisplacementGradient::operator/(
    const Time& time) const {
  return {*this, time};
}

inline constexpr ScalarDisplacementGradient Time::operator*(
    const ScalarVelocityGradient& scalar_velocity_gradient) const {
  return {scalar_velocity_gradient, *this};
}

inline constexpr ScalarVelocityGradient Frequency::operator*(
    const ScalarDisplacementGradient& scalar_displacement_gradient) const {
  return {scalar_displacement_gradient, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ScalarVelocityGradient> {
  inline size_t operator()(const PhQ::ScalarVelocityGradient& scalar_velocity_gradient) const {
    return hash<double>()(scalar_velocity_gradient.Value());
  }
};

}  // namespace std

#endif  // PHQ_VELOCITY_GRADIENT_SCALAR_HPP
