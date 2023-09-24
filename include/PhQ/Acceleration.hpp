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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_ACCELERATION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_ACCELERATION_HPP

#include "AccelerationMagnitude.hpp"
#include "Velocity.hpp"

namespace PhQ {

// Acceleration vector.
class Acceleration : public DimensionalVectorQuantity<Unit::Acceleration> {
public:
  // Default constructor. Constructs an acceleration vector with an
  // uninitialized value.
  Acceleration() = default;

  // Constructor. Constructs an acceleration vector with a given value expressed
  // in a given acceleration unit.
  Acceleration(const Value::Vector& value, const Unit::Acceleration unit)
    : DimensionalVectorQuantity<Unit::Acceleration>(value, unit) {}

  // Constructor. Constructs an acceleration vector from a given acceleration
  // magnitude and direction.
  constexpr Acceleration(const AccelerationMagnitude& acceleration_magnitude,
                         const Direction& direction)
    : Acceleration(acceleration_magnitude.Value() * direction.Value()) {}

  // Constructor. Constructs an acceleration vector from a given velocity and
  // time using the definition of acceleration.
  constexpr Acceleration(const Velocity& velocity, const Time& time)
    : Acceleration(velocity.Value() / time.Value()) {}

  // Constructor. Constructs an acceleration vector from a given velocity and
  // frequency using the definition of acceleration.
  constexpr Acceleration(const Velocity& velocity, const Frequency& frequency)
    : Acceleration(velocity.Value() * frequency.Value()) {}

  // Destructor. Destroys this acceleration vector.
  ~Acceleration() noexcept = default;

  // Copy constructor. Constructs an acceleration vector by copying another one.
  constexpr Acceleration(const Acceleration& other) = default;

  // Move constructor. Constructs an acceleration vector by moving another one.
  constexpr Acceleration(Acceleration&& other) noexcept = default;

  // Copy assignment operator. Assigns this acceleration vector by copying
  // another one.
  constexpr Acceleration& operator=(const Acceleration& other) = default;

  // Move assignment operator. Assigns this acceleration vector by moving
  // another one.
  constexpr Acceleration& operator=(Acceleration&& other) noexcept = default;

  // Statically creates an acceleration vector of zero.
  static constexpr Acceleration Zero() {
    return Acceleration{Value::Vector::Zero()};
  }

  // Statically creates an acceleration vector with a given value expressed in a
  // given acceleration unit.
  template <Unit::Acceleration Unit>
  static constexpr Acceleration Create(const Value::Vector& value) {
    return Acceleration{StaticConvertCopy<Unit::Acceleration, Unit,
                                          Standard<Unit::Acceleration>>(value)};
  }

  // Returns the magnitude of this acceleration vector.
  AccelerationMagnitude Magnitude() const {
    return {*this};
  }

  // Returns the angle between this acceleration vector and another one.
  PhQ::Angle Angle(const Acceleration& acceleration) const {
    return {*this, acceleration};
  }

  constexpr Acceleration operator+(const Acceleration& acceleration) const {
    return Acceleration{value_ + acceleration.value_};
  }

  constexpr Acceleration operator-(const Acceleration& acceleration) const {
    return Acceleration{value_ - acceleration.value_};
  }

  constexpr Acceleration operator*(const double number) const {
    return Acceleration{value_ * number};
  }

  constexpr Velocity operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr Acceleration operator/(const double number) const {
    return Acceleration{value_ / number};
  }

  constexpr Velocity operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr void operator+=(const Acceleration& acceleration) noexcept {
    value_ += acceleration.value_;
  }

  constexpr void operator-=(const Acceleration& acceleration) noexcept {
    value_ -= acceleration.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs an acceleration vector with a given value expressed
  // in the standard acceleration unit.
  explicit constexpr Acceleration(const Value::Vector& value)
    : DimensionalVectorQuantity<Unit::Acceleration>(value) {}
};

inline constexpr bool operator==(
    const Acceleration& left, const Acceleration& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Acceleration& left, const Acceleration& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Acceleration& left, const Acceleration& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Acceleration& left, const Acceleration& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Acceleration& left, const Acceleration& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Acceleration& left, const Acceleration& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const Acceleration& acceleration) {
  stream << acceleration.Print();
  return stream;
}

inline constexpr Acceleration operator*(
    const double number, const Acceleration& acceleration) {
  return acceleration * number;
}

inline Direction::Direction(const Acceleration& acceleration)
  : Direction(acceleration.Value()) {}

inline Angle::Angle(
    const Acceleration& acceleration_1, const Acceleration& acceleration_2)
  : Angle(acceleration_1.Value(), acceleration_2.Value()) {}

inline AccelerationMagnitude::AccelerationMagnitude(
    const Acceleration& acceleration)
  : AccelerationMagnitude(acceleration.Value().Magnitude()) {}

inline constexpr Velocity::Velocity(
    const Acceleration& acceleration, const Time& time)
  : Velocity(acceleration.Value() * time.Value()) {}

inline constexpr Velocity::Velocity(
    const Acceleration& acceleration, const Frequency& frequency)
  : Velocity(acceleration.Value() / frequency.Value()) {}

inline constexpr Acceleration Direction::operator*(
    const AccelerationMagnitude& acceleration_magnitude) const {
  return {acceleration_magnitude, *this};
}

inline constexpr Velocity Time::operator*(
    const Acceleration& acceleration) const {
  return {acceleration, *this};
}

inline constexpr Acceleration AccelerationMagnitude::operator*(
    const Direction& direction) const {
  return {*this, direction};
}

inline constexpr Acceleration Velocity::operator*(
    const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr Acceleration Velocity::operator/(const Time& time) const {
  return {*this, time};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Acceleration> {
  inline size_t operator()(const PhQ::Acceleration& acceleration) const {
    return hash<PhQ::Value::Vector>()(acceleration.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ACCELERATION_HPP
