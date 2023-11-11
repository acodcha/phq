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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGULAR_ACCELERATION_SCALAR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGULAR_ACCELERATION_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "AngularSpeed.hpp"
#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "Time.hpp"
#include "Unit/AngularAcceleration.hpp"

namespace PhQ {

// Planar scalar angular acceleration component or magnitude of an angular acceleration vector. Time
// rate of change of angular speed. Typically measured in radians per square second.
class AngularAccelerationScalar : public DimensionalScalar<Unit::AngularAcceleration> {
public:
  // Default constructor. Constructs a scalar angular acceleration with an uninitialized value.
  AngularAccelerationScalar() = default;

  // Constructor. Constructs a scalar angular acceleration with a given value expressed in a given
  // angular acceleration unit.
  AngularAccelerationScalar(const double value, const Unit::AngularAcceleration unit)
    : DimensionalScalar<Unit::AngularAcceleration>(value, unit) {}

  // Constructor. Constructs a scalar angular acceleration from a given angular speed and time using
  // the definition of angular acceleration.
  constexpr AngularAccelerationScalar(const AngularSpeed& angular_speed, const Time& time)
    : AngularAccelerationScalar(angular_speed.Value() / time.Value()) {}

  // Constructor. Constructs a scalar angular acceleration from a given angular speed and frequency
  // using the definition of angular acceleration.
  constexpr AngularAccelerationScalar(const AngularSpeed& angular_speed, const Frequency& frequency)
    : AngularAccelerationScalar(angular_speed.Value() * frequency.Value()) {}

  // Destructor. Destroys this scalar angular acceleration.
  ~AngularAccelerationScalar() noexcept = default;

  // Copy constructor. Constructs a scalar angular acceleration by copying another one.
  constexpr AngularAccelerationScalar(const AngularAccelerationScalar& other) = default;

  // Move constructor. Constructs a scalar angular acceleration by moving another one.
  constexpr AngularAccelerationScalar(AngularAccelerationScalar&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar angular acceleration by copying another one.
  constexpr AngularAccelerationScalar& operator=(const AngularAccelerationScalar& other) = default;

  // Move assignment operator. Assigns this scalar angular acceleration by moving another one.
  constexpr AngularAccelerationScalar& operator=(
      AngularAccelerationScalar&& other) noexcept = default;

  // Statically creates a scalar angular acceleration of zero.
  static constexpr AngularAccelerationScalar Zero() {
    return AngularAccelerationScalar{0.0};
  }

  // Statically creates a scalar angular acceleration with a given value expressed in a given
  // angular acceleration unit.
  template <Unit::AngularAcceleration Unit>
  static constexpr AngularAccelerationScalar Create(const double value) {
    return AngularAccelerationScalar{
        StaticConvertCopy<Unit::AngularAcceleration, Unit, Standard<Unit::AngularAcceleration>>(
            value)};
  }

  constexpr AngularAccelerationScalar operator+(
      const AngularAccelerationScalar& angular_acceleration_scalar) const {
    return AngularAccelerationScalar{value_ + angular_acceleration_scalar.value_};
  }

  constexpr AngularAccelerationScalar operator-(
      const AngularAccelerationScalar& angular_acceleration_scalar) const {
    return AngularAccelerationScalar{value_ - angular_acceleration_scalar.value_};
  }

  constexpr AngularAccelerationScalar operator*(const double number) const {
    return AngularAccelerationScalar{value_ * number};
  }

  constexpr AngularSpeed operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr AngularAccelerationScalar operator/(const double number) const {
    return AngularAccelerationScalar{value_ / number};
  }

  constexpr AngularSpeed operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const AngularSpeed& angular_speed) const {
    return {*this, angular_speed};
  }

  constexpr double operator/(
      const AngularAccelerationScalar& angular_acceleration_scalar) const noexcept {
    return value_ / angular_acceleration_scalar.value_;
  }

  constexpr void operator+=(const AngularAccelerationScalar& angular_acceleration_scalar) noexcept {
    value_ += angular_acceleration_scalar.value_;
  }

  constexpr void operator-=(const AngularAccelerationScalar& angular_acceleration_scalar) noexcept {
    value_ -= angular_acceleration_scalar.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a scalar angular acceleration with a given value expressed in the
  // standard angular acceleration unit.
  explicit constexpr AngularAccelerationScalar(const double value)
    : DimensionalScalar<Unit::AngularAcceleration>(value) {}
};

inline constexpr bool operator==(
    const AngularAccelerationScalar& left, const AngularAccelerationScalar& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const AngularAccelerationScalar& left, const AngularAccelerationScalar& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const AngularAccelerationScalar& left, const AngularAccelerationScalar& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const AngularAccelerationScalar& left, const AngularAccelerationScalar& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const AngularAccelerationScalar& left, const AngularAccelerationScalar& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const AngularAccelerationScalar& left, const AngularAccelerationScalar& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const AngularAccelerationScalar& angular_acceleration_scalar) {
  stream << angular_acceleration_scalar.Print();
  return stream;
}

inline constexpr AngularAccelerationScalar operator*(
    const double number, const AngularAccelerationScalar& angular_acceleration_scalar) {
  return angular_acceleration_scalar * number;
}

inline constexpr Time::Time(
    const AngularSpeed& angular_speed, const AngularAccelerationScalar& angular_acceleration_scalar)
  : Time(angular_speed.Value() / angular_acceleration_scalar.Value()) {}

inline constexpr Frequency::Frequency(
    const AngularAccelerationScalar& angular_acceleration_scalar, const AngularSpeed& angular_speed)
  : Frequency(angular_acceleration_scalar.Value() / angular_speed.Value()) {}

inline constexpr AngularSpeed::AngularSpeed(
    const AngularAccelerationScalar& angular_acceleration_scalar, const Time& time)
  : AngularSpeed(angular_acceleration_scalar.Value() * time.Value()) {}

inline constexpr AngularSpeed::AngularSpeed(
    const AngularAccelerationScalar& angular_acceleration_scalar, const Frequency& frequency)
  : AngularSpeed(angular_acceleration_scalar.Value() / frequency.Value()) {}

inline constexpr AngularAccelerationScalar Frequency::operator*(
    const AngularSpeed& angular_speed) const {
  return {angular_speed, *this};
}

inline constexpr AngularAccelerationScalar AngularSpeed::operator*(
    const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr AngularAccelerationScalar AngularSpeed::operator/(const Time& time) const {
  return {*this, time};
}

inline constexpr Time AngularSpeed::operator/(
    const AngularAccelerationScalar& angular_acceleration_scalar) const {
  return {*this, angular_acceleration_scalar};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::AngularAccelerationScalar> {
  inline size_t operator()(
      const PhQ::AngularAccelerationScalar& angular_acceleration_scalar) const {
    return hash<double>()(angular_acceleration_scalar.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGULAR_ACCELERATION_SCALAR_HPP
