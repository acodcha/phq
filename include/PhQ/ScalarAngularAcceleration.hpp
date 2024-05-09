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
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a scalar angular acceleration by moving another one.
  constexpr ScalarAngularAcceleration(ScalarAngularAcceleration<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar angular acceleration by copying another one.
  constexpr ScalarAngularAcceleration<Number>& operator=(
      const ScalarAngularAcceleration<Number>& other) = default;

  // Copy assignment operator. Assigns this scalar angular acceleration by copying another one.
  template <typename OtherNumber>
  constexpr ScalarAngularAcceleration<Number>& operator=(
      const ScalarAngularAcceleration<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
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
    return ScalarAngularAcceleration<Number>{value + scalar_angular_acceleration.value};
  }

  constexpr ScalarAngularAcceleration<Number> operator-(
      const ScalarAngularAcceleration<Number>& scalar_angular_acceleration) const {
    return ScalarAngularAcceleration<Number>{value - scalar_angular_acceleration.value};
  }

  constexpr ScalarAngularAcceleration<Number> operator*(const Number number) const {
    return ScalarAngularAcceleration<Number>{value * number};
  }

  constexpr AngularSpeed<Number> operator*(const Time<Number>& time) const {
    return AngularSpeed<Number>{*this, time};
  }

  constexpr ScalarAngularAcceleration<Number> operator/(const Number number) const {
    return ScalarAngularAcceleration<Number>{value / number};
  }

  constexpr AngularSpeed<Number> operator/(const Frequency<Number>& frequency) const {
    return AngularSpeed<Number>{*this, frequency};
  }

  constexpr Frequency<Number> operator/(const AngularSpeed<Number>& angular_speed) const {
    return Frequency<Number>{*this, angular_speed};
  }

  constexpr Number operator/(
      const ScalarAngularAcceleration<Number>& scalar_angular_acceleration) const noexcept {
    return value / scalar_angular_acceleration.value;
  }

  constexpr void operator+=(
      const ScalarAngularAcceleration<Number>& scalar_angular_acceleration) noexcept {
    value += scalar_angular_acceleration.value;
  }

  constexpr void operator-=(
      const ScalarAngularAcceleration<Number>& scalar_angular_acceleration) noexcept {
    value -= scalar_angular_acceleration.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
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
  return ScalarAngularAcceleration<Number>{*this, scalar_angular_acceleration};
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
