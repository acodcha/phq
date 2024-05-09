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

#ifndef PHQ_ANGULAR_SPEED_HPP
#define PHQ_ANGULAR_SPEED_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "Time.hpp"
#include "Unit/AngularSpeed.hpp"

namespace PhQ {

// Forward declaration for class PhQ::AngularSpeed.
template <typename Number>
class ScalarAngularAcceleration;

// Planar angular speed component or magnitude of an angular velocity pseudovector. Time rate of
// change of an angle. Typically measured in radians per second. Can also represent a circular
// frequency.
template <typename Number = double>
class AngularSpeed : public DimensionalScalar<Unit::AngularSpeed, Number> {
public:
  // Default constructor. Constructs an angular speed with an uninitialized value.
  AngularSpeed() = default;

  // Constructor. Constructs an angular speed with a given value expressed in a given angular speed
  // unit.
  AngularSpeed(const Number value, const Unit::AngularSpeed unit)
    : DimensionalScalar<Unit::AngularSpeed, Number>(value, unit) {}

  // Constructor. Constructs an angular speed from a given angle and time using the definition of
  // angular speed.
  constexpr AngularSpeed(const Angle<Number>& angle, const Time<Number>& time)
    : AngularSpeed<Number>(angle.Value() / time.Value()) {}

  // Constructor. Constructs an angular speed from a given angle and frequency using the definition
  // of angular speed.
  constexpr AngularSpeed(const Angle<Number>& angle, const Frequency<Number>& frequency)
    : AngularSpeed<Number>(angle.Value() * frequency.Value()) {}

  // Constructor. Constructs an angular speed from a given scalar angular acceleration and time
  // using the definition of angular acceleration.
  constexpr AngularSpeed(const ScalarAngularAcceleration<Number>& scalar_angular_acceleration,
                         const Time<Number>& time);

  // Constructor. Constructs an angular speed from a given scalar angular acceleration and frequency
  // using the definition of angular acceleration.
  constexpr AngularSpeed(const ScalarAngularAcceleration<Number>& scalar_angular_acceleration,
                         const Frequency<Number>& frequency);

  // Destructor. Destroys this angular speed.
  ~AngularSpeed() noexcept = default;

  // Copy constructor. Constructs an angular speed by copying another one.
  constexpr AngularSpeed(const AngularSpeed<Number>& other) = default;

  // Copy constructor. Constructs an angular speed by copying another one.
  template <typename OtherNumber>
  explicit constexpr AngularSpeed(const AngularSpeed<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs an angular speed by moving another one.
  constexpr AngularSpeed(AngularSpeed<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this angular speed by copying another one.
  constexpr AngularSpeed<Number>& operator=(const AngularSpeed<Number>& other) = default;

  // Copy assignment operator. Assigns this angular speed by copying another one.
  template <typename OtherNumber>
  constexpr AngularSpeed<Number>& operator=(const AngularSpeed<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this angular speed by moving another one.
  constexpr AngularSpeed<Number>& operator=(AngularSpeed<Number>&& other) noexcept = default;

  // Statically creates an angular speed of zero.
  static constexpr AngularSpeed<Number> Zero() {
    return AngularSpeed<Number>{static_cast<Number>(0)};
  }

  // Statically creates an angular speed with a given value expressed in a given angular speed unit.
  template <Unit::AngularSpeed Unit>
  static constexpr AngularSpeed<Number> Create(const Number value) {
    return AngularSpeed<Number>{
        StaticConvertCopy<Unit::AngularSpeed, Unit, Standard<Unit::AngularSpeed>>(value)};
  }

  constexpr AngularSpeed<Number> operator+(const AngularSpeed<Number>& angular_speed) const {
    return AngularSpeed<Number>{value + angular_speed.value};
  }

  constexpr AngularSpeed<Number> operator-(const AngularSpeed<Number>& angular_speed) const {
    return AngularSpeed<Number>{value - angular_speed.value};
  }

  constexpr AngularSpeed<Number> operator*(const Number number) const {
    return AngularSpeed<Number>{value * number};
  }

  constexpr Angle<Number> operator*(const Time<Number>& time) const {
    return {*this, time};
  }

  constexpr ScalarAngularAcceleration<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr AngularSpeed<Number> operator/(const Number number) const {
    return AngularSpeed<Number>{value / number};
  }

  constexpr Angle<Number> operator/(const Frequency<Number>& frequency) const {
    return {*this, frequency};
  }

  constexpr Frequency<Number> operator/(const Angle<Number>& angle) const {
    return {*this, angle};
  }

  constexpr ScalarAngularAcceleration<Number> operator/(const Time<Number>& time) const;

  constexpr Time<Number> operator/(
      const ScalarAngularAcceleration<Number>& scalar_angular_acceleration) const;

  constexpr Number operator/(const AngularSpeed<Number>& angular_speed) const noexcept {
    return value / angular_speed.value;
  }

  constexpr void operator+=(const AngularSpeed<Number>& angular_speed) noexcept {
    value += angular_speed.value;
  }

  constexpr void operator-=(const AngularSpeed<Number>& angular_speed) noexcept {
    value -= angular_speed.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs an angular speed with a given value expressed in the standard angular
  // speed unit.
  explicit constexpr AngularSpeed(const Number value)
    : DimensionalScalar<Unit::AngularSpeed, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const AngularSpeed<Number>& left, const AngularSpeed<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const AngularSpeed<Number>& left, const AngularSpeed<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const AngularSpeed<Number>& left, const AngularSpeed<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const AngularSpeed<Number>& left, const AngularSpeed<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const AngularSpeed<Number>& left, const AngularSpeed<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const AngularSpeed<Number>& left, const AngularSpeed<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const AngularSpeed<Number>& angular_speed) {
  stream << angular_speed.Print();
  return stream;
}

template <typename Number>
inline constexpr AngularSpeed<Number> operator*(
    const Number number, const AngularSpeed<Number>& angular_speed) {
  return angular_speed * number;
}

template <typename Number>
inline constexpr Angle<Number>::Angle(
    const AngularSpeed<Number>& angular_speed, const Time<Number>& time)
  : Angle<Number>(angular_speed.Value() * time.Value()) {}

template <typename Number>
inline constexpr Angle<Number>::Angle(
    const AngularSpeed<Number>& angular_speed, const Frequency<Number>& frequency)
  : Angle<Number>(angular_speed.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr Time<Number>::Time(
    const Angle<Number>& angle, const AngularSpeed<Number>& angular_speed)
  : Time<Number>(angle.Value() / angular_speed.Value()) {}

template <typename Number>
inline constexpr Frequency<Number>::Frequency(
    const AngularSpeed<Number>& angular_speed, const Angle<Number>& angle)
  : Frequency<Number>(angular_speed.Value() / angle.Value()) {}

template <typename Number>
inline constexpr AngularSpeed<Number> Angle<Number>::operator*(
    const Frequency<Number>& frequency) const {
  return AngularSpeed<Number>{*this, frequency};
}

template <typename Number>
inline constexpr AngularSpeed<Number> Frequency<Number>::operator*(
    const Angle<Number>& angle) const {
  return AngularSpeed<Number>{angle, *this};
}

template <typename Number>
inline constexpr AngularSpeed<Number> Angle<Number>::operator/(const Time<Number>& time) const {
  return AngularSpeed<Number>{*this, time};
}

template <typename Number>
inline constexpr Time<Number> Angle<Number>::operator/(
    const AngularSpeed<Number>& angular_speed) const {
  return Time<Number>{*this, angular_speed};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::AngularSpeed<Number>> {
  inline size_t operator()(const PhQ::AngularSpeed<Number>& angular_speed) const {
    return hash<Number>()(angular_speed.Value());
  }
};

}  // namespace std

#endif  // PHQ_ANGULAR_SPEED_HPP
