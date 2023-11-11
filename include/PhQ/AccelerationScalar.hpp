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

// Forward declarations for class AccelerationScalar.
class Acceleration;
class Direction;

// Scalar acceleration component or magnitude of an acceleration vector.
class AccelerationScalar : public DimensionalScalar<Unit::Acceleration> {
public:
  // Default constructor. Constructs a scalar acceleration with an uninitialized value.
  AccelerationScalar() = default;

  // Constructor. Constructs a scalar acceleration with a given value expressed in a given
  // acceleration unit.
  AccelerationScalar(const double value, const Unit::Acceleration unit)
    : DimensionalScalar<Unit::Acceleration>(value, unit) {}

  // Constructor. Constructs a scalar acceleration from the magnitude of a given acceleration
  // vector.
  explicit AccelerationScalar(const Acceleration& acceleration);

  // Constructor. Constructs a scalar acceleration from a given speed and time using the definition
  // of acceleration.
  constexpr AccelerationScalar(const Speed& speed, const Time& time)
    : AccelerationScalar(speed.Value() / time.Value()) {}

  // Constructor. Constructs a scalar acceleration from a given speed and frequency using the
  // definition of acceleration.
  constexpr AccelerationScalar(const Speed& speed, const Frequency& frequency)
    : AccelerationScalar(speed.Value() * frequency.Value()) {}

  // Destructor. Destroys this acceleration scalar.
  ~AccelerationScalar() noexcept = default;

  // Copy constructor. Constructs a scalar acceleration by copying another one.
  constexpr AccelerationScalar(const AccelerationScalar& other) = default;

  // Move constructor. Constructs a scalar acceleration by moving another one.
  constexpr AccelerationScalar(AccelerationScalar&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar acceleration by copying another one.
  constexpr AccelerationScalar& operator=(const AccelerationScalar& other) = default;

  // Move assignment operator. Assigns this scalar acceleration by moving another one.
  constexpr AccelerationScalar& operator=(AccelerationScalar&& other) noexcept = default;

  // Statically creates a scalar acceleration of zero.
  static constexpr AccelerationScalar Zero() {
    return AccelerationScalar{0.0};
  }

  // Statically creates a scalar acceleration with a given value expressed in a given acceleration
  // unit.
  template <Unit::Acceleration Unit>
  static constexpr AccelerationScalar Create(const double value) {
    return AccelerationScalar{
        StaticConvertCopy<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(value)};
  }

  constexpr AccelerationScalar operator+(const AccelerationScalar& acceleration_scalar) const {
    return AccelerationScalar{value_ + acceleration_scalar.value_};
  }

  constexpr AccelerationScalar operator-(const AccelerationScalar& acceleration_scalar) const {
    return AccelerationScalar{value_ - acceleration_scalar.value_};
  }

  constexpr AccelerationScalar operator*(const double number) const {
    return AccelerationScalar{value_ * number};
  }

  constexpr Speed operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr Acceleration operator*(const Direction& direction) const;

  constexpr AccelerationScalar operator/(const double number) const {
    return AccelerationScalar{value_ / number};
  }

  constexpr Speed operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const Speed& speed) const {
    return {*this, speed};
  }

  constexpr double operator/(const AccelerationScalar& acceleration_scalar) const noexcept {
    return value_ / acceleration_scalar.value_;
  }

  constexpr void operator+=(const AccelerationScalar& acceleration_scalar) noexcept {
    value_ += acceleration_scalar.value_;
  }

  constexpr void operator-=(const AccelerationScalar& acceleration_scalar) noexcept {
    value_ -= acceleration_scalar.value_;
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
  explicit constexpr AccelerationScalar(const double value)
    : DimensionalScalar<Unit::Acceleration>(value) {}
};

inline constexpr bool operator==(
    const AccelerationScalar& left, const AccelerationScalar& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const AccelerationScalar& left, const AccelerationScalar& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const AccelerationScalar& left, const AccelerationScalar& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const AccelerationScalar& left, const AccelerationScalar& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const AccelerationScalar& left, const AccelerationScalar& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const AccelerationScalar& left, const AccelerationScalar& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const AccelerationScalar& acceleration_scalar) {
  stream << acceleration_scalar.Print();
  return stream;
}

inline constexpr AccelerationScalar operator*(
    const double number, const AccelerationScalar& acceleration_scalar) {
  return acceleration_scalar * number;
}

inline constexpr Time::Time(const Speed& speed, const AccelerationScalar& acceleration_scalar)
  : Time(speed.Value() / acceleration_scalar.Value()) {}

inline constexpr Frequency::Frequency(
    const AccelerationScalar& acceleration_scalar, const Speed& speed)
  : Frequency(acceleration_scalar.Value() / speed.Value()) {}

inline constexpr Speed::Speed(const AccelerationScalar& acceleration_scalar, const Time& time)
  : Speed(acceleration_scalar.Value() * time.Value()) {}

inline constexpr Speed::Speed(
    const AccelerationScalar& acceleration_scalar, const Frequency& frequency)
  : Speed(acceleration_scalar.Value() / frequency.Value()) {}

inline constexpr AccelerationScalar Frequency::operator*(const Speed& speed) const {
  return {speed, *this};
}

inline constexpr Speed Time::operator*(const AccelerationScalar& acceleration_scalar) const {
  return {acceleration_scalar, *this};
}

inline constexpr AccelerationScalar Speed::operator*(const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr AccelerationScalar Speed::operator/(const Time& time) const {
  return {*this, time};
}

inline constexpr Time Speed::operator/(const AccelerationScalar& acceleration_scalar) const {
  return {*this, acceleration_scalar};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::AccelerationScalar> {
  inline size_t operator()(const PhQ::AccelerationScalar& acceleration_scalar) const {
    return hash<double>()(acceleration_scalar.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ACCELERATION_SCALAR_HPP
