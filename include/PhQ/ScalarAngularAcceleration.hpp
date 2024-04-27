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

#ifndef PHQ_ANGULAR_ACCELERATION_SCALAR_HPP
#define PHQ_ANGULAR_ACCELERATION_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "AngularSpeed.hpp"
#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "Time.hpp"
#include "Unit/AngularAcceleration.hpp"

namespace PhQ {

// Planar scalar angular acceleration component or magnitude of an angular acceleration
// pseudovector. Time rate of change of angular speed. Typically measured in radians per square
// second.
class ScalarAngularAcceleration : public DimensionalScalar<Unit::AngularAcceleration> {
public:
  // Default constructor. Constructs a scalar angular acceleration with an uninitialized value.
  ScalarAngularAcceleration() = default;

  // Constructor. Constructs a scalar angular acceleration with a given value expressed in a given
  // angular acceleration unit.
  ScalarAngularAcceleration(const double value, const Unit::AngularAcceleration unit)
    : DimensionalScalar<Unit::AngularAcceleration>(value, unit) {}

  // Constructor. Constructs a scalar angular acceleration from a given angular speed and time using
  // the definition of angular acceleration.
  constexpr ScalarAngularAcceleration(const AngularSpeed& angular_speed, const Time& time)
    : ScalarAngularAcceleration(angular_speed.Value() / time.Value()) {}

  // Constructor. Constructs a scalar angular acceleration from a given angular speed and frequency
  // using the definition of angular acceleration.
  constexpr ScalarAngularAcceleration(const AngularSpeed& angular_speed, const Frequency& frequency)
    : ScalarAngularAcceleration(angular_speed.Value() * frequency.Value()) {}

  // Destructor. Destroys this scalar angular acceleration.
  ~ScalarAngularAcceleration() noexcept = default;

  // Copy constructor. Constructs a scalar angular acceleration by copying another one.
  constexpr ScalarAngularAcceleration(const ScalarAngularAcceleration& other) = default;

  // Move constructor. Constructs a scalar angular acceleration by moving another one.
  constexpr ScalarAngularAcceleration(ScalarAngularAcceleration&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar angular acceleration by copying another one.
  constexpr ScalarAngularAcceleration& operator=(const ScalarAngularAcceleration& other) = default;

  // Move assignment operator. Assigns this scalar angular acceleration by moving another one.
  constexpr ScalarAngularAcceleration& operator=(
      ScalarAngularAcceleration&& other) noexcept = default;

  // Statically creates a scalar angular acceleration of zero.
  static constexpr ScalarAngularAcceleration Zero() {
    return ScalarAngularAcceleration{0.0};
  }

  // Statically creates a scalar angular acceleration with a given value expressed in a given
  // angular acceleration unit.
  template <Unit::AngularAcceleration Unit>
  static constexpr ScalarAngularAcceleration Create(const double value) {
    return ScalarAngularAcceleration{
        StaticConvertCopy<Unit::AngularAcceleration, Unit, Standard<Unit::AngularAcceleration>>(
            value)};
  }

  constexpr ScalarAngularAcceleration operator+(
      const ScalarAngularAcceleration& scalar_angular_acceleration) const {
    return ScalarAngularAcceleration{value + scalar_angular_acceleration.value};
  }

  constexpr ScalarAngularAcceleration operator-(
      const ScalarAngularAcceleration& scalar_angular_acceleration) const {
    return ScalarAngularAcceleration{value - scalar_angular_acceleration.value};
  }

  constexpr ScalarAngularAcceleration operator*(const double number) const {
    return ScalarAngularAcceleration{value * number};
  }

  constexpr AngularSpeed operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr ScalarAngularAcceleration operator/(const double number) const {
    return ScalarAngularAcceleration{value / number};
  }

  constexpr AngularSpeed operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const AngularSpeed& angular_speed) const {
    return {*this, angular_speed};
  }

  constexpr double operator/(
      const ScalarAngularAcceleration& scalar_angular_acceleration) const noexcept {
    return value / scalar_angular_acceleration.value;
  }

  constexpr void operator+=(const ScalarAngularAcceleration& scalar_angular_acceleration) noexcept {
    value += scalar_angular_acceleration.value;
  }

  constexpr void operator-=(const ScalarAngularAcceleration& scalar_angular_acceleration) noexcept {
    value -= scalar_angular_acceleration.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a scalar angular acceleration with a given value expressed in the
  // standard angular acceleration unit.
  explicit constexpr ScalarAngularAcceleration(const double value)
    : DimensionalScalar<Unit::AngularAcceleration>(value) {}
};

inline constexpr bool operator==(
    const ScalarAngularAcceleration& left, const ScalarAngularAcceleration& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const ScalarAngularAcceleration& left, const ScalarAngularAcceleration& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const ScalarAngularAcceleration& left, const ScalarAngularAcceleration& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const ScalarAngularAcceleration& left, const ScalarAngularAcceleration& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const ScalarAngularAcceleration& left, const ScalarAngularAcceleration& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const ScalarAngularAcceleration& left, const ScalarAngularAcceleration& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const ScalarAngularAcceleration& scalar_angular_acceleration) {
  stream << scalar_angular_acceleration.Print();
  return stream;
}

inline constexpr ScalarAngularAcceleration operator*(
    const double number, const ScalarAngularAcceleration& scalar_angular_acceleration) {
  return scalar_angular_acceleration * number;
}

inline constexpr Time::Time(
    const AngularSpeed& angular_speed, const ScalarAngularAcceleration& scalar_angular_acceleration)
  : Time(angular_speed.Value() / scalar_angular_acceleration.Value()) {}

inline constexpr Frequency::Frequency(
    const ScalarAngularAcceleration& scalar_angular_acceleration, const AngularSpeed& angular_speed)
  : Frequency(scalar_angular_acceleration.Value() / angular_speed.Value()) {}

inline constexpr AngularSpeed::AngularSpeed(
    const ScalarAngularAcceleration& scalar_angular_acceleration, const Time& time)
  : AngularSpeed(scalar_angular_acceleration.Value() * time.Value()) {}

inline constexpr AngularSpeed::AngularSpeed(
    const ScalarAngularAcceleration& scalar_angular_acceleration, const Frequency& frequency)
  : AngularSpeed(scalar_angular_acceleration.Value() / frequency.Value()) {}

inline constexpr ScalarAngularAcceleration Frequency::operator*(
    const AngularSpeed& angular_speed) const {
  return {angular_speed, *this};
}

inline constexpr ScalarAngularAcceleration AngularSpeed::operator*(
    const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr ScalarAngularAcceleration AngularSpeed::operator/(const Time& time) const {
  return {*this, time};
}

inline constexpr Time AngularSpeed::operator/(
    const ScalarAngularAcceleration& scalar_angular_acceleration) const {
  return {*this, scalar_angular_acceleration};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ScalarAngularAcceleration> {
  inline size_t operator()(
      const PhQ::ScalarAngularAcceleration& scalar_angular_acceleration) const {
    return hash<double>()(scalar_angular_acceleration.Value());
  }
};

}  // namespace std

#endif  // PHQ_ANGULAR_ACCELERATION_SCALAR_HPP
