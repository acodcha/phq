// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
    : AngularSpeed(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs an angular speed by moving another one.
  constexpr AngularSpeed(AngularSpeed<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this angular speed by copying another one.
  constexpr AngularSpeed<Number>& operator=(const AngularSpeed<Number>& other) = default;

  // Copy assignment operator. Assigns this angular speed by copying another one.
  template <typename OtherNumber>
  constexpr AngularSpeed<Number>& operator=(const AngularSpeed<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
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
    return AngularSpeed<Number>{this->value + angular_speed.value};
  }

  constexpr AngularSpeed<Number> operator-(const AngularSpeed<Number>& angular_speed) const {
    return AngularSpeed<Number>{this->value - angular_speed.value};
  }

  constexpr AngularSpeed<Number> operator*(const Number number) const {
    return AngularSpeed<Number>{this->value * number};
  }

  constexpr Angle<Number> operator*(const Time<Number>& time) const {
    return Angle<Number>{*this, time};
  }

  constexpr ScalarAngularAcceleration<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr AngularSpeed<Number> operator/(const Number number) const {
    return AngularSpeed<Number>{this->value / number};
  }

  constexpr Angle<Number> operator/(const Frequency<Number>& frequency) const {
    return Angle<Number>{*this, frequency};
  }

  constexpr Frequency<Number> operator/(const Angle<Number>& angle) const {
    return Frequency<Number>{*this, angle};
  }

  constexpr ScalarAngularAcceleration<Number> operator/(const Time<Number>& time) const;

  constexpr Time<Number> operator/(
      const ScalarAngularAcceleration<Number>& scalar_angular_acceleration) const;

  constexpr Number operator/(const AngularSpeed<Number>& angular_speed) const noexcept {
    return this->value / angular_speed.value;
  }

  constexpr void operator+=(const AngularSpeed<Number>& angular_speed) noexcept {
    this->value += angular_speed.value;
  }

  constexpr void operator-=(const AngularSpeed<Number>& angular_speed) noexcept {
    this->value -= angular_speed.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
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
