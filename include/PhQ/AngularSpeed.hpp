// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGULAR_SPEED_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGULAR_SPEED_HPP

#include "Angle.hpp"
#include "Frequency.hpp"
#include "Unit/AngularSpeed.hpp"

namespace PhQ {

// Forward declaration for class AngularSpeed.
class AngularAccelerationMagnitude;

// Planar angular speed. Magnitude of angular velocity. Time rate of change of
// an angle. Typically measured in radians per second. Can also represent a
// circular frequency.
class AngularSpeed : public DimensionalScalarQuantity<Unit::AngularSpeed> {
public:
  // Default constructor. Constructs an angular speed with an uninitialized
  // value.
  AngularSpeed() = default;

  // Constructor. Constructs an angular speed with a given value expressed in a
  // given angular speed unit.
  AngularSpeed(const double value, const Unit::AngularSpeed unit)
    : DimensionalScalarQuantity<Unit::AngularSpeed>(value, unit) {}

  // Constructor. Constructs an angular speed from a given angle and time using
  // the definition of angular speed.
  constexpr AngularSpeed(const Angle& angle, const Time& time)
    : AngularSpeed(angle.Value() / time.Value()) {}

  // Constructor. Constructs an angular speed from a given angle and frequency
  // using the definition of angular speed.
  constexpr AngularSpeed(const Angle& angle, const Frequency& frequency)
    : AngularSpeed(angle.Value() * frequency.Value()) {}

  // Constructor. Constructs an angular speed from a given angular acceleration
  // magnitude and time using the definition of angular acceleration.
  constexpr AngularSpeed(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude,
      const Time& time);

  // Constructor. Constructs an angular speed from a given angular acceleration
  // magnitude and frequency using the definition of angular acceleration.
  constexpr AngularSpeed(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude,
      const Frequency& frequency);

  // Destructor. Destroys this angular speed.
  ~AngularSpeed() noexcept = default;

  // Copy constructor. Constructs an angular speed by copying another one.
  constexpr AngularSpeed(const AngularSpeed& other) = default;

  // Move constructor. Constructs an angular speed by moving another one.
  constexpr AngularSpeed(AngularSpeed&& other) noexcept = default;

  // Copy assignment operator. Assigns this angular speed by copying another
  // one.
  constexpr AngularSpeed& operator=(const AngularSpeed& other) = default;

  // Move assignment operator. Assigns this angular speed by moving another one.
  constexpr AngularSpeed& operator=(AngularSpeed&& other) noexcept = default;

  // Statically creates an angular speed of zero.
  static constexpr AngularSpeed Zero() {
    return AngularSpeed{0.0};
  }

  // Statically creates an angular speed with a given value expressed in a given
  // angular speed unit.
  template <Unit::AngularSpeed Unit>
  static constexpr AngularSpeed Create(const double value) {
    return AngularSpeed{StaticConvertCopy<Unit::AngularSpeed, Unit,
                                          Standard<Unit::AngularSpeed>>(value)};
  }

  constexpr AngularSpeed operator+(const AngularSpeed& angular_speed) const {
    return AngularSpeed{value_ + angular_speed.value_};
  }

  constexpr AngularSpeed operator-(const AngularSpeed& angular_speed) const {
    return AngularSpeed{value_ - angular_speed.value_};
  }

  constexpr AngularSpeed operator*(const double number) const {
    return AngularSpeed{value_ * number};
  }

  constexpr Angle operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr AngularAccelerationMagnitude operator*(
      const Frequency& frequency) const;

  constexpr AngularSpeed operator/(const double number) const {
    return AngularSpeed{value_ / number};
  }

  constexpr Angle operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const Angle& angle) const {
    return {*this, angle};
  }

  constexpr AngularAccelerationMagnitude operator/(const Time& time) const;

  constexpr Time operator/(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude) const;

  constexpr double operator/(const AngularSpeed& angular_speed) const noexcept {
    return value_ / angular_speed.value_;
  }

  constexpr void operator+=(const AngularSpeed& angular_speed) noexcept {
    value_ += angular_speed.value_;
  }

  constexpr void operator-=(const AngularSpeed& angular_speed) noexcept {
    value_ -= angular_speed.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs an angular speed with a given value expressed in
  // the standard angular speed unit.
  explicit constexpr AngularSpeed(const double value)
    : DimensionalScalarQuantity<Unit::AngularSpeed>(value) {}
};

inline constexpr bool operator==(
    const AngularSpeed& left, const AngularSpeed& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const AngularSpeed& left, const AngularSpeed& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const AngularSpeed& left, const AngularSpeed& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const AngularSpeed& left, const AngularSpeed& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const AngularSpeed& left, const AngularSpeed& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const AngularSpeed& left, const AngularSpeed& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const AngularSpeed& angular_speed) {
  stream << angular_speed.Print();
  return stream;
}

inline constexpr AngularSpeed operator*(
    const double number, const AngularSpeed& angular_speed) {
  return angular_speed * number;
}

inline constexpr Angle::Angle(
    const AngularSpeed& angular_speed, const Time& time)
  : Angle(angular_speed.Value() * time.Value()) {}

inline constexpr Angle::Angle(
    const AngularSpeed& angular_speed, const Frequency& frequency)
  : Angle(angular_speed.Value() / frequency.Value()) {}

inline constexpr Time::Time(
    const Angle& angle, const AngularSpeed& angular_speed)
  : Time(angle.Value() / angular_speed.Value()) {}

inline constexpr Frequency::Frequency(
    const AngularSpeed& angular_speed, const Angle& angle)
  : Frequency(angular_speed.Value() / angle.Value()) {}

inline constexpr AngularSpeed Angle::operator*(
    const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr AngularSpeed Frequency::operator*(const Angle& angle) const {
  return {angle, *this};
}

inline constexpr AngularSpeed Angle::operator/(const Time& time) const {
  return {*this, time};
}

inline constexpr Time Angle::operator/(
    const AngularSpeed& angular_speed) const {
  return {*this, angular_speed};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::AngularSpeed> {
  inline size_t operator()(const PhQ::AngularSpeed& angular_speed) const {
    return hash<double>()(angular_speed.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ANGULAR_SPEED_HPP
