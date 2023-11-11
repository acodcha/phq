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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGULAR_ACCELERATION_MAGNITUDE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGULAR_ACCELERATION_MAGNITUDE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "AngularSpeed.hpp"
#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "Time.hpp"
#include "Unit/AngularAcceleration.hpp"

namespace PhQ {

// Planar angular acceleration scalar. Magnitude of angular acceleration vector. Time rate of change
// of angular speed. Typically measured in radians per square second.
class AngularAccelerationMagnitude : public DimensionalScalar<Unit::AngularAcceleration> {
public:
  // Default constructor. Constructs an angular acceleration magnitude with an uninitialized value.
  AngularAccelerationMagnitude() = default;

  // Constructor. Constructs an angular acceleration magnitude with a given value expressed in a
  // given angular acceleration unit.
  AngularAccelerationMagnitude(const double value, const Unit::AngularAcceleration unit)
    : DimensionalScalar<Unit::AngularAcceleration>(value, unit) {}

  // Constructor. Constructs an angular acceleration magnitude from a given angular speed and time
  // using the definition of angular acceleration.
  constexpr AngularAccelerationMagnitude(const AngularSpeed& angular_speed, const Time& time)
    : AngularAccelerationMagnitude(angular_speed.Value() / time.Value()) {}

  // Constructor. Constructs an angular acceleration magnitude from a given angular speed and
  // frequency using the definition of angular acceleration.
  constexpr AngularAccelerationMagnitude(
      const AngularSpeed& angular_speed, const Frequency& frequency)
    : AngularAccelerationMagnitude(angular_speed.Value() * frequency.Value()) {}

  // Destructor. Destroys this angular acceleration magnitude.
  ~AngularAccelerationMagnitude() noexcept = default;

  // Copy constructor. Constructs an angular acceleration magnitude by copying another one.
  constexpr AngularAccelerationMagnitude(const AngularAccelerationMagnitude& other) = default;

  // Move constructor. Constructs an angular acceleration magnitude by moving another one.
  constexpr AngularAccelerationMagnitude(AngularAccelerationMagnitude&& other) noexcept = default;

  // Copy assignment operator. Assigns this angular acceleration magnitude by copying another one.
  constexpr AngularAccelerationMagnitude& operator=(
      const AngularAccelerationMagnitude& other) = default;

  // Move assignment operator. Assigns this angular acceleration magnitude by moving another one.
  constexpr AngularAccelerationMagnitude& operator=(
      AngularAccelerationMagnitude&& other) noexcept = default;

  // Statically creates an angular acceleration magnitude of zero.
  static constexpr AngularAccelerationMagnitude Zero() {
    return AngularAccelerationMagnitude{0.0};
  }

  // Statically creates an angular acceleration magnitude with a given value expressed in a given
  // angular acceleration unit.
  template <Unit::AngularAcceleration Unit>
  static constexpr AngularAccelerationMagnitude Create(const double value) {
    return AngularAccelerationMagnitude{
        StaticConvertCopy<Unit::AngularAcceleration, Unit, Standard<Unit::AngularAcceleration>>(
            value)};
  }

  constexpr AngularAccelerationMagnitude operator+(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude) const {
    return AngularAccelerationMagnitude{value_ + angular_acceleration_magnitude.value_};
  }

  constexpr AngularAccelerationMagnitude operator-(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude) const {
    return AngularAccelerationMagnitude{value_ - angular_acceleration_magnitude.value_};
  }

  constexpr AngularAccelerationMagnitude operator*(const double number) const {
    return AngularAccelerationMagnitude{value_ * number};
  }

  constexpr AngularSpeed operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr AngularAccelerationMagnitude operator/(const double number) const {
    return AngularAccelerationMagnitude{value_ / number};
  }

  constexpr AngularSpeed operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const AngularSpeed& angular_speed) const {
    return {*this, angular_speed};
  }

  constexpr double operator/(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude) const noexcept {
    return value_ / angular_acceleration_magnitude.value_;
  }

  constexpr void operator+=(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude) noexcept {
    value_ += angular_acceleration_magnitude.value_;
  }

  constexpr void operator-=(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude) noexcept {
    value_ -= angular_acceleration_magnitude.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs an angular acceleration magnitude with a given value expressed in the
  // standard angular acceleration unit.
  explicit constexpr AngularAccelerationMagnitude(const double value)
    : DimensionalScalar<Unit::AngularAcceleration>(value) {}
};

inline constexpr bool operator==(
    const AngularAccelerationMagnitude& left, const AngularAccelerationMagnitude& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const AngularAccelerationMagnitude& left, const AngularAccelerationMagnitude& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const AngularAccelerationMagnitude& left, const AngularAccelerationMagnitude& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const AngularAccelerationMagnitude& left, const AngularAccelerationMagnitude& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const AngularAccelerationMagnitude& left, const AngularAccelerationMagnitude& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const AngularAccelerationMagnitude& left, const AngularAccelerationMagnitude& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const AngularAccelerationMagnitude& angular_acceleration_magnitude) {
  stream << angular_acceleration_magnitude.Print();
  return stream;
}

inline constexpr AngularAccelerationMagnitude operator*(
    const double number, const AngularAccelerationMagnitude& angular_acceleration_magnitude) {
  return angular_acceleration_magnitude * number;
}

inline constexpr Time::Time(const AngularSpeed& angular_speed,
                            const AngularAccelerationMagnitude& angular_acceleration_magnitude)
  : Time(angular_speed.Value() / angular_acceleration_magnitude.Value()) {}

inline constexpr Frequency::Frequency(
    const AngularAccelerationMagnitude& angular_acceleration_magnitude,
    const AngularSpeed& angular_speed)
  : Frequency(angular_acceleration_magnitude.Value() / angular_speed.Value()) {}

inline constexpr AngularSpeed::AngularSpeed(
    const AngularAccelerationMagnitude& angular_acceleration_magnitude, const Time& time)
  : AngularSpeed(angular_acceleration_magnitude.Value() * time.Value()) {}

inline constexpr AngularSpeed::AngularSpeed(
    const AngularAccelerationMagnitude& angular_acceleration_magnitude, const Frequency& frequency)
  : AngularSpeed(angular_acceleration_magnitude.Value() / frequency.Value()) {}

inline constexpr AngularAccelerationMagnitude Frequency::operator*(
    const AngularSpeed& angular_speed) const {
  return {angular_speed, *this};
}

inline constexpr AngularAccelerationMagnitude AngularSpeed::operator*(
    const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr AngularAccelerationMagnitude AngularSpeed::operator/(const Time& time) const {
  return {*this, time};
}

inline constexpr Time AngularSpeed::operator/(
    const AngularAccelerationMagnitude& angular_acceleration_magnitude) const {
  return {*this, angular_acceleration_magnitude};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::AngularAccelerationMagnitude> {
  inline size_t operator()(
      const PhQ::AngularAccelerationMagnitude& angular_acceleration_magnitude) const {
    return hash<double>()(angular_acceleration_magnitude.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGULAR_ACCELERATION_MAGNITUDE_HPP
