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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_ACCELERATION_MAGNITUDE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_ACCELERATION_MAGNITUDE_HPP

#include "Speed.hpp"
#include "Unit/Acceleration.hpp"

namespace PhQ {

// Forward declarations for class AccelerationMagnitude.
class Acceleration;
class Direction;

// Acceleration scalar. Magnitude of the acceleration vector.
class AccelerationMagnitude
  : public DimensionalScalarQuantity<Unit::Acceleration> {
public:
  // Default constructor. Constructs an acceleration magnitude with an
  // uninitialized value.
  AccelerationMagnitude() = default;

  // Constructor. Constructs an acceleration magnitude with a given value
  // expressed in a given acceleration unit.
  AccelerationMagnitude(const double value, const Unit::Acceleration unit)
    : DimensionalScalarQuantity<Unit::Acceleration>(value, unit) {}

  // Constructor. Constructs an acceleration magnitude from a given
  // acceleration.
  AccelerationMagnitude(const Acceleration& acceleration);

  // Constructor. Constructs an acceleration magnitude from a given speed and
  // time using the definition of acceleration.
  constexpr AccelerationMagnitude(const Speed& speed, const Time& time)
    : AccelerationMagnitude(speed.Value() / time.Value()) {}

  // Constructor. Constructs an acceleration magnitude from a given speed and
  // frequency using the definition of acceleration.
  constexpr AccelerationMagnitude(
      const Speed& speed, const Frequency& frequency)
    : AccelerationMagnitude(speed.Value() * frequency.Value()) {}

  // Destructor. Destroys this acceleration magnitude.
  ~AccelerationMagnitude() noexcept = default;

  // Copy constructor. Constructs an acceleration magnitude by copying another
  // one.
  constexpr AccelerationMagnitude(const AccelerationMagnitude& other) = default;

  // Move constructor. Constructs an acceleration magnitude by moving another
  // one.
  constexpr AccelerationMagnitude(
      AccelerationMagnitude&& other) noexcept = default;

  // Copy assignment operator. Assigns this acceleration magnitude by copying
  // another one.
  constexpr AccelerationMagnitude& operator=(
      const AccelerationMagnitude& other) = default;

  // Move assignment operator. Assigns this acceleration magnitude by moving
  // another one.
  constexpr AccelerationMagnitude& operator=(
      AccelerationMagnitude&& other) noexcept = default;

  // Statically creates an acceleration magnitude of zero.
  static constexpr AccelerationMagnitude Zero() {
    return AccelerationMagnitude{0.0};
  }

  // Statically creates an acceleration magnitude with a given value expressed
  // in a given acceleration unit.
  template <Unit::Acceleration Unit>
  static constexpr AccelerationMagnitude Create(const double value) {
    return AccelerationMagnitude{
        StaticConvertCopy<Unit::Acceleration, Unit,
                          Standard<Unit::Acceleration>>(value)};
  }

  constexpr AccelerationMagnitude operator+(
      const AccelerationMagnitude& acceleration_magnitude) const {
    return AccelerationMagnitude{value_ + acceleration_magnitude.value_};
  }

  constexpr AccelerationMagnitude operator-(
      const AccelerationMagnitude& acceleration_magnitude) const {
    return AccelerationMagnitude{value_ - acceleration_magnitude.value_};
  }

  constexpr AccelerationMagnitude operator*(const double number) const {
    return AccelerationMagnitude{value_ * number};
  }

  constexpr Speed operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr Acceleration operator*(const Direction& direction) const;

  constexpr AccelerationMagnitude operator/(const double number) const {
    return AccelerationMagnitude{value_ / number};
  }

  constexpr Speed operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const Speed& speed) const {
    return {*this, speed};
  }

  constexpr double operator/(
      const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return value_ / acceleration_magnitude.value_;
  }

  constexpr void operator+=(
      const AccelerationMagnitude& acceleration_magnitude) noexcept {
    value_ += acceleration_magnitude.value_;
  }

  constexpr void operator-=(
      const AccelerationMagnitude& acceleration_magnitude) noexcept {
    value_ -= acceleration_magnitude.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs an acceleration magnitude with a given value
  // expressed in the standard acceleration unit.
  explicit constexpr AccelerationMagnitude(const double value)
    : DimensionalScalarQuantity<Unit::Acceleration>(value) {}
};

inline constexpr bool operator==(const AccelerationMagnitude& left,
                                 const AccelerationMagnitude& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const AccelerationMagnitude& left,
                                 const AccelerationMagnitude& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const AccelerationMagnitude& left,
                                const AccelerationMagnitude& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const AccelerationMagnitude& left,
                                const AccelerationMagnitude& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const AccelerationMagnitude& left,
                                 const AccelerationMagnitude& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const AccelerationMagnitude& left,
                                 const AccelerationMagnitude& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const AccelerationMagnitude& acceleration_magnitude) {
  stream << acceleration_magnitude.Print();
  return stream;
}

inline constexpr AccelerationMagnitude operator*(
    const double number, const AccelerationMagnitude& acceleration_magnitude) {
  return acceleration_magnitude * number;
}

inline constexpr Time::Time(
    const AccelerationMagnitude& acceleration_magnitude, const Speed& speed)
  : Time(speed.Value() / acceleration_magnitude.Value()) {}

inline constexpr Frequency::Frequency(
    const AccelerationMagnitude& acceleration_magnitude, const Speed& speed)
  : Frequency(acceleration_magnitude.Value() / speed.Value()) {}

inline constexpr Speed::Speed(
    const AccelerationMagnitude& acceleration_magnitude, const Time& time)
  : Speed(acceleration_magnitude.Value() * time.Value()) {}

inline constexpr Speed::Speed(
    const AccelerationMagnitude& acceleration_magnitude,
    const Frequency& frequency)
  : Speed(acceleration_magnitude.Value() / frequency.Value()) {}

inline constexpr AccelerationMagnitude Frequency::operator*(
    const Speed& speed) const {
  return {speed, *this};
}

inline constexpr Speed Time::operator*(
    const AccelerationMagnitude& acceleration_magnitude) const {
  return {acceleration_magnitude, *this};
}

inline constexpr AccelerationMagnitude Speed::operator*(
    const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr AccelerationMagnitude Speed::operator/(
    const Time& time) const {
  return {*this, time};
}

inline constexpr Time Speed::operator/(
    const AccelerationMagnitude& acceleration_magnitude) const {
  return {acceleration_magnitude, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::AccelerationMagnitude> {
  inline size_t operator()(
      const PhQ::AccelerationMagnitude& acceleration_magnitude) const {
    return hash<double>()(acceleration_magnitude.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ACCELERATION_MAGNITUDE_HPP
