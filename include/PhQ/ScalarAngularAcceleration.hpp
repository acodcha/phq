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
template <typename Number = double>
class ScalarAngularAcceleration : public DimensionalScalar<Unit::AngularAcceleration, Number> {
public:
  // Default constructor. Constructs a scalar angular acceleration with an uninitialized value.
  ScalarAngularAcceleration() = default;

  // Constructor. Constructs a scalar angular acceleration with a given value expressed in a given
  // angular acceleration unit.
  ScalarAngularAcceleration(const Number value, const Unit::AngularAcceleration unit)
    : DimensionalScalar<Unit::AngularAcceleration, Number>(value, unit) {}

  // Constructor. Constructs a scalar angular acceleration from a given angular speed and time using
  // the definition of angular acceleration.
  constexpr ScalarAngularAcceleration(
      const AngularSpeed<Number>& angular_speed, const Time<Number>& time)
    : ScalarAngularAcceleration<Number>(angular_speed.Value() / time.Value()) {}

  // Constructor. Constructs a scalar angular acceleration from a given angular speed and frequency
  // using the definition of angular acceleration.
  constexpr ScalarAngularAcceleration(
      const AngularSpeed<Number>& angular_speed, const Frequency<Number>& frequency)
    : ScalarAngularAcceleration<Number>(angular_speed.Value() * frequency.Value()) {}

  // Destructor. Destroys this scalar angular acceleration.
  ~ScalarAngularAcceleration() noexcept = default;

  // Copy constructor. Constructs a scalar angular acceleration by copying another one.
  constexpr ScalarAngularAcceleration(const ScalarAngularAcceleration<Number>& other) = default;

  // Copy constructor. Constructs a scalar angular acceleration by copying another one.
  template <typename OtherNumber>
  explicit constexpr ScalarAngularAcceleration(const ScalarAngularAcceleration<OtherNumber>& other)
    : ScalarAngularAcceleration(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a scalar angular acceleration by moving another one.
  constexpr ScalarAngularAcceleration(ScalarAngularAcceleration<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar angular acceleration by copying another one.
  constexpr ScalarAngularAcceleration<Number>& operator=(
      const ScalarAngularAcceleration<Number>& other) = default;

  // Copy assignment operator. Assigns this scalar angular acceleration by copying another one.
  template <typename OtherNumber>
  constexpr ScalarAngularAcceleration<Number>& operator=(
      const ScalarAngularAcceleration<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this scalar angular acceleration by moving another one.
  constexpr ScalarAngularAcceleration<Number>& operator=(
      ScalarAngularAcceleration<Number>&& other) noexcept = default;

  // Statically creates a scalar angular acceleration of zero.
  static constexpr ScalarAngularAcceleration<Number> Zero() {
    return ScalarAngularAcceleration<Number>{static_cast<Number>(0)};
  }

  // Statically creates a scalar angular acceleration with a given value expressed in a given
  // angular acceleration unit.
  template <Unit::AngularAcceleration Unit>
  static constexpr ScalarAngularAcceleration<Number> Create(const Number value) {
    return ScalarAngularAcceleration<Number>{
        StaticConvertCopy<Unit::AngularAcceleration, Unit, Standard<Unit::AngularAcceleration>>(
            value)};
  }

  constexpr ScalarAngularAcceleration<Number> operator+(
      const ScalarAngularAcceleration<Number>& scalar_angular_acceleration) const {
    return ScalarAngularAcceleration<Number>{this->value + scalar_angular_acceleration.value};
  }

  constexpr ScalarAngularAcceleration<Number> operator-(
      const ScalarAngularAcceleration<Number>& scalar_angular_acceleration) const {
    return ScalarAngularAcceleration<Number>{this->value - scalar_angular_acceleration.value};
  }

  constexpr ScalarAngularAcceleration<Number> operator*(const Number number) const {
    return ScalarAngularAcceleration<Number>{this->value * number};
  }

  constexpr AngularSpeed<Number> operator*(const Time<Number>& time) const {
    return AngularSpeed<Number>{*this, time};
  }

  constexpr ScalarAngularAcceleration<Number> operator/(const Number number) const {
    return ScalarAngularAcceleration<Number>{this->value / number};
  }

  constexpr AngularSpeed<Number> operator/(const Frequency<Number>& frequency) const {
    return AngularSpeed<Number>{*this, frequency};
  }

  constexpr Frequency<Number> operator/(const AngularSpeed<Number>& angular_speed) const {
    return Frequency<Number>{*this, angular_speed};
  }

  constexpr Number operator/(
      const ScalarAngularAcceleration<Number>& scalar_angular_acceleration) const noexcept {
    return this->value / scalar_angular_acceleration.value;
  }

  constexpr void operator+=(
      const ScalarAngularAcceleration<Number>& scalar_angular_acceleration) noexcept {
    this->value += scalar_angular_acceleration.value;
  }

  constexpr void operator-=(
      const ScalarAngularAcceleration<Number>& scalar_angular_acceleration) noexcept {
    this->value -= scalar_angular_acceleration.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a scalar angular acceleration with a given value expressed in the
  // standard angular acceleration unit.
  explicit constexpr ScalarAngularAcceleration(const Number value)
    : DimensionalScalar<Unit::AngularAcceleration, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const ScalarAngularAcceleration<Number>& left,
                                 const ScalarAngularAcceleration<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const ScalarAngularAcceleration<Number>& left,
                                 const ScalarAngularAcceleration<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const ScalarAngularAcceleration<Number>& left,
                                const ScalarAngularAcceleration<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const ScalarAngularAcceleration<Number>& left,
                                const ScalarAngularAcceleration<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const ScalarAngularAcceleration<Number>& left,
                                 const ScalarAngularAcceleration<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const ScalarAngularAcceleration<Number>& left,
                                 const ScalarAngularAcceleration<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const ScalarAngularAcceleration<Number>& scalar_angular_acceleration) {
  stream << scalar_angular_acceleration.Print();
  return stream;
}

template <typename Number>
inline constexpr ScalarAngularAcceleration<Number> operator*(
    const Number number, const ScalarAngularAcceleration<Number>& scalar_angular_acceleration) {
  return scalar_angular_acceleration * number;
}

template <typename Number>
inline constexpr Time<Number>::Time(
    const AngularSpeed<Number>& angular_speed,
    const ScalarAngularAcceleration<Number>& scalar_angular_acceleration)
  : Time<Number>(angular_speed.Value() / scalar_angular_acceleration.Value()) {}

template <typename Number>
inline constexpr Frequency<Number>::Frequency(
    const ScalarAngularAcceleration<Number>& scalar_angular_acceleration,
    const AngularSpeed<Number>& angular_speed)
  : Frequency<Number>(scalar_angular_acceleration.Value() / angular_speed.Value()) {}

template <typename Number>
inline constexpr AngularSpeed<Number>::AngularSpeed(
    const ScalarAngularAcceleration<Number>& scalar_angular_acceleration, const Time<Number>& time)
  : AngularSpeed<Number>(scalar_angular_acceleration.Value() * time.Value()) {}

template <typename Number>
inline constexpr AngularSpeed<Number>::AngularSpeed(
    const ScalarAngularAcceleration<Number>& scalar_angular_acceleration,
    const Frequency<Number>& frequency)
  : AngularSpeed<Number>(scalar_angular_acceleration.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr ScalarAngularAcceleration<Number> Frequency<Number>::operator*(
    const AngularSpeed<Number>& angular_speed) const {
  return ScalarAngularAcceleration<Number>{angular_speed, *this};
}

template <typename Number>
inline constexpr ScalarAngularAcceleration<Number> AngularSpeed<Number>::operator*(
    const Frequency<Number>& frequency) const {
  return ScalarAngularAcceleration<Number>{*this, frequency};
}

template <typename Number>
inline constexpr ScalarAngularAcceleration<Number> AngularSpeed<Number>::operator/(
    const Time<Number>& time) const {
  return ScalarAngularAcceleration<Number>{*this, time};
}

template <typename Number>
inline constexpr Time<Number> AngularSpeed<Number>::operator/(
    const ScalarAngularAcceleration<Number>& scalar_angular_acceleration) const {
  return Time<Number>{*this, scalar_angular_acceleration};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ScalarAngularAcceleration<Number>> {
  inline size_t operator()(
      const PhQ::ScalarAngularAcceleration<Number>& scalar_angular_acceleration) const {
    return hash<Number>()(scalar_angular_acceleration.Value());
  }
};

}  // namespace std

#endif  // PHQ_ANGULAR_ACCELERATION_SCALAR_HPP
