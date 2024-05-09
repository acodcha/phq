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

#ifndef PHQ_ACCELERATION_SCALAR_HPP
#define PHQ_ACCELERATION_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "Speed.hpp"
#include "Time.hpp"
#include "Unit/Acceleration.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ScalarAcceleration.
template <typename Number>
class Acceleration;

// Forward declaration for class PhQ::ScalarAcceleration.
template <typename Number>
class Direction;

// Scalar acceleration component or magnitude of an acceleration vector. See also PhQ::Acceleration.
template <typename Number = double>
class ScalarAcceleration : public DimensionalScalar<Unit::Acceleration, Number> {
public:
  // Default constructor. Constructs a scalar acceleration with an uninitialized value.
  ScalarAcceleration() = default;

  // Constructor. Constructs a scalar acceleration with a given value expressed in a given
  // acceleration unit.
  ScalarAcceleration(const Number value, const Unit::Acceleration unit)
    : DimensionalScalar<Unit::Acceleration, Number>(value, unit) {}

  // Constructor. Constructs a scalar acceleration from a given speed and time using the definition
  // of acceleration.
  constexpr ScalarAcceleration(const Speed<Number>& speed, const Time<Number>& time)
    : ScalarAcceleration<Number>(speed.Value() / time.Value()) {}

  // Constructor. Constructs a scalar acceleration from a given speed and frequency using the
  // definition of acceleration.
  constexpr ScalarAcceleration(const Speed<Number>& speed, const Frequency<Number>& frequency)
    : ScalarAcceleration<Number>(speed.Value() * frequency.Value()) {}

  // Destructor. Destroys this acceleration scalar.
  ~ScalarAcceleration() noexcept = default;

  // Copy constructor. Constructs a scalar acceleration by copying another one.
  constexpr ScalarAcceleration(const ScalarAcceleration<Number>& other) = default;

  // Copy constructor. Constructs a scalar acceleration by copying another one.
  template <typename OtherNumber>
  explicit constexpr ScalarAcceleration(const ScalarAcceleration<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a scalar acceleration by moving another one.
  constexpr ScalarAcceleration(ScalarAcceleration<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar acceleration by copying another one.
  constexpr ScalarAcceleration<Number>& operator=(
      const ScalarAcceleration<Number>& other) = default;

  // Copy assignment operator. Assigns this scalar acceleration by copying another one.
  template <typename OtherNumber>
  constexpr ScalarAcceleration<Number>& operator=(const ScalarAcceleration<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this scalar acceleration by moving another one.
  constexpr ScalarAcceleration<Number>& operator=(
      ScalarAcceleration<Number>&& other) noexcept = default;

  // Statically creates a scalar acceleration of zero.
  static constexpr ScalarAcceleration<Number> Zero() {
    return ScalarAcceleration<Number>{static_cast<Number>(0)};
  }

  // Statically creates a scalar acceleration with a given value expressed in a given acceleration
  // unit.
  template <Unit::Acceleration Unit>
  static constexpr ScalarAcceleration<Number> Create(const Number value) {
    return ScalarAcceleration<Number>{
        StaticConvertCopy<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(value)};
  }

  constexpr ScalarAcceleration<Number> operator+(
      const ScalarAcceleration<Number>& scalar_acceleration) const {
    return ScalarAcceleration<Number>{value + scalar_acceleration.value};
  }

  constexpr ScalarAcceleration<Number> operator-(
      const ScalarAcceleration<Number>& scalar_acceleration) const {
    return ScalarAcceleration<Number>{value - scalar_acceleration.value};
  }

  constexpr ScalarAcceleration<Number> operator*(const Number number) const {
    return ScalarAcceleration<Number>{value * number};
  }

  constexpr Speed<Number> operator*(const Time<Number>& time) const {
    return Speed<Number>{*this, time};
  }

  constexpr Acceleration<Number> operator*(const Direction<Number>& direction) const;

  constexpr ScalarAcceleration<Number> operator/(const Number number) const {
    return ScalarAcceleration<Number>{value / number};
  }

  constexpr Speed<Number> operator/(const Frequency<Number>& frequency) const {
    return Speed<Number>{*this, frequency};
  }

  constexpr Frequency<Number> operator/(const Speed<Number>& speed) const {
    return Frequency<Number>{*this, speed};
  }

  constexpr Number operator/(const ScalarAcceleration<Number>& scalar_acceleration) const noexcept {
    return value / scalar_acceleration.value;
  }

  constexpr void operator+=(const ScalarAcceleration<Number>& scalar_acceleration) noexcept {
    value += scalar_acceleration.value;
  }

  constexpr void operator-=(const ScalarAcceleration<Number>& scalar_acceleration) noexcept {
    value -= scalar_acceleration.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a scalar acceleration with a given value expressed in the standard
  // acceleration unit.
  explicit constexpr ScalarAcceleration(const Number value)
    : DimensionalScalar<Unit::Acceleration, Number>(value) {}

  template <typename OtherNumber>
  friend class Acceleration;
};

template <typename Number>
inline constexpr bool operator==(
    const ScalarAcceleration<Number>& left, const ScalarAcceleration<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const ScalarAcceleration<Number>& left, const ScalarAcceleration<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const ScalarAcceleration<Number>& left, const ScalarAcceleration<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const ScalarAcceleration<Number>& left, const ScalarAcceleration<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const ScalarAcceleration<Number>& left, const ScalarAcceleration<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const ScalarAcceleration<Number>& left, const ScalarAcceleration<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const ScalarAcceleration<Number>& scalar_acceleration) {
  stream << scalar_acceleration.Print();
  return stream;
}

template <typename Number>
inline constexpr ScalarAcceleration<Number> operator*(
    const Number number, const ScalarAcceleration<Number>& scalar_acceleration) {
  return scalar_acceleration * number;
}

template <typename Number>
inline constexpr Time<Number>::Time(
    const Speed<Number>& speed, const ScalarAcceleration<Number>& scalar_acceleration)
  : Time<Number>(speed.Value() / scalar_acceleration.Value()) {}

template <typename Number>
inline constexpr Frequency<Number>::Frequency(
    const ScalarAcceleration<Number>& scalar_acceleration, const Speed<Number>& speed)
  : Frequency<Number>(scalar_acceleration.Value() / speed.Value()) {}

template <typename Number>
inline constexpr Speed<Number>::Speed(
    const ScalarAcceleration<Number>& scalar_acceleration, const Time<Number>& time)
  : Speed<Number>(scalar_acceleration.Value() * time.Value()) {}

template <typename Number>
inline constexpr Speed<Number>::Speed(
    const ScalarAcceleration<Number>& scalar_acceleration, const Frequency<Number>& frequency)
  : Speed<Number>(scalar_acceleration.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr ScalarAcceleration<Number> Frequency<Number>::operator*(
    const Speed<Number>& speed) const {
  return ScalarAcceleration<Number>{speed, *this};
}

template <typename Number>
inline constexpr Speed<Number> Time<Number>::operator*(
    const ScalarAcceleration<Number>& scalar_acceleration) const {
  return Speed<Number>{scalar_acceleration, *this};
}

template <typename Number>
inline constexpr ScalarAcceleration<Number> Speed<Number>::operator*(
    const Frequency<Number>& frequency) const {
  return ScalarAcceleration<Number>{*this, frequency};
}

template <typename Number>
inline constexpr ScalarAcceleration<Number> Speed<Number>::operator/(
    const Time<Number>& time) const {
  return ScalarAcceleration<Number>{*this, time};
}

template <typename Number>
inline constexpr Time<Number> Speed<Number>::operator/(
    const ScalarAcceleration<Number>& scalar_acceleration) const {
  return Time<Number>{*this, scalar_acceleration};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ScalarAcceleration<Number>> {
  inline size_t operator()(const PhQ::ScalarAcceleration<Number>& scalar_acceleration) const {
    return hash<Number>()(scalar_acceleration.Value());
  }
};

}  // namespace std

#endif  // PHQ_ACCELERATION_SCALAR_HPP
