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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_ACCELERATION_SCALAR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_ACCELERATION_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "Speed.hpp"
#include "Time.hpp"
#include "Unit/Acceleration.hpp"

namespace PhQ {

// Forward declarations for class ScalarAcceleration.
class Acceleration;
class Direction;

// Scalar acceleration component or magnitude of an acceleration vector. See also PhQ::Acceleration.
class ScalarAcceleration : public DimensionalScalar<Unit::Acceleration> {
public:
  // Default constructor. Constructs a scalar acceleration with an uninitialized value.
  ScalarAcceleration() = default;

  // Constructor. Constructs a scalar acceleration with a given value expressed in a given
  // acceleration unit.
  ScalarAcceleration(const double value, const Unit::Acceleration unit)
    : DimensionalScalar<Unit::Acceleration>(value, unit) {}

  // Constructor. Constructs a scalar acceleration from a given speed and time using the definition
  // of acceleration.
  constexpr ScalarAcceleration(const Speed& speed, const Time& time)
    : ScalarAcceleration(speed.Value() / time.Value()) {}

  // Constructor. Constructs a scalar acceleration from a given speed and frequency using the
  // definition of acceleration.
  constexpr ScalarAcceleration(const Speed& speed, const Frequency& frequency)
    : ScalarAcceleration(speed.Value() * frequency.Value()) {}

  // Destructor. Destroys this acceleration scalar.
  ~ScalarAcceleration() noexcept = default;

  // Copy constructor. Constructs a scalar acceleration by copying another one.
  constexpr ScalarAcceleration(const ScalarAcceleration& other) = default;

  // Move constructor. Constructs a scalar acceleration by moving another one.
  constexpr ScalarAcceleration(ScalarAcceleration&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar acceleration by copying another one.
  constexpr ScalarAcceleration& operator=(const ScalarAcceleration& other) = default;

  // Move assignment operator. Assigns this scalar acceleration by moving another one.
  constexpr ScalarAcceleration& operator=(ScalarAcceleration&& other) noexcept = default;

  // Statically creates a scalar acceleration of zero.
  static constexpr ScalarAcceleration Zero() {
    return ScalarAcceleration{0.0};
  }

  // Statically creates a scalar acceleration with a given value expressed in a given acceleration
  // unit.
  template <Unit::Acceleration Unit>
  static constexpr ScalarAcceleration Create(const double value) {
    return ScalarAcceleration{
        StaticConvertCopy<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(value)};
  }

  constexpr ScalarAcceleration operator+(const ScalarAcceleration& scalar_acceleration) const {
    return ScalarAcceleration{value_ + scalar_acceleration.value_};
  }

  constexpr ScalarAcceleration operator-(const ScalarAcceleration& scalar_acceleration) const {
    return ScalarAcceleration{value_ - scalar_acceleration.value_};
  }

  constexpr ScalarAcceleration operator*(const double number) const {
    return ScalarAcceleration{value_ * number};
  }

  constexpr Speed operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr Acceleration operator*(const Direction& direction) const;

  constexpr ScalarAcceleration operator/(const double number) const {
    return ScalarAcceleration{value_ / number};
  }

  constexpr Speed operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const Speed& speed) const {
    return {*this, speed};
  }

  constexpr double operator/(const ScalarAcceleration& scalar_acceleration) const noexcept {
    return value_ / scalar_acceleration.value_;
  }

  constexpr void operator+=(const ScalarAcceleration& scalar_acceleration) noexcept {
    value_ += scalar_acceleration.value_;
  }

  constexpr void operator-=(const ScalarAcceleration& scalar_acceleration) noexcept {
    value_ -= scalar_acceleration.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a scalar acceleration with a given value expressed in the standard
  // acceleration unit.
  explicit constexpr ScalarAcceleration(const double value)
    : DimensionalScalar<Unit::Acceleration>(value) {}

  friend class Acceleration;
};

inline constexpr bool operator==(
    const ScalarAcceleration& left, const ScalarAcceleration& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const ScalarAcceleration& left, const ScalarAcceleration& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const ScalarAcceleration& left, const ScalarAcceleration& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const ScalarAcceleration& left, const ScalarAcceleration& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const ScalarAcceleration& left, const ScalarAcceleration& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const ScalarAcceleration& left, const ScalarAcceleration& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const ScalarAcceleration& scalar_acceleration) {
  stream << scalar_acceleration.Print();
  return stream;
}

inline constexpr ScalarAcceleration operator*(
    const double number, const ScalarAcceleration& scalar_acceleration) {
  return scalar_acceleration * number;
}

inline constexpr Time::Time(const Speed& speed, const ScalarAcceleration& scalar_acceleration)
  : Time(speed.Value() / scalar_acceleration.Value()) {}

inline constexpr Frequency::Frequency(
    const ScalarAcceleration& scalar_acceleration, const Speed& speed)
  : Frequency(scalar_acceleration.Value() / speed.Value()) {}

inline constexpr Speed::Speed(const ScalarAcceleration& scalar_acceleration, const Time& time)
  : Speed(scalar_acceleration.Value() * time.Value()) {}

inline constexpr Speed::Speed(
    const ScalarAcceleration& scalar_acceleration, const Frequency& frequency)
  : Speed(scalar_acceleration.Value() / frequency.Value()) {}

inline constexpr ScalarAcceleration Frequency::operator*(const Speed& speed) const {
  return {speed, *this};
}

inline constexpr Speed Time::operator*(const ScalarAcceleration& scalar_acceleration) const {
  return {scalar_acceleration, *this};
}

inline constexpr ScalarAcceleration Speed::operator*(const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr ScalarAcceleration Speed::operator/(const Time& time) const {
  return {*this, time};
}

inline constexpr Time Speed::operator/(const ScalarAcceleration& scalar_acceleration) const {
  return {*this, scalar_acceleration};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ScalarAcceleration> {
  inline size_t operator()(const PhQ::ScalarAcceleration& scalar_acceleration) const {
    return hash<double>()(scalar_acceleration.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ACCELERATION_SCALAR_HPP
