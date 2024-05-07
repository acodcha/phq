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

#ifndef PHQ_ACCELERATION_HPP
#define PHQ_ACCELERATION_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalVector.hpp"
#include "Direction.hpp"
#include "Frequency.hpp"
#include "ScalarAcceleration.hpp"
#include "Time.hpp"
#include "Unit/Acceleration.hpp"
#include "Vector.hpp"
#include "Velocity.hpp"

namespace PhQ {

// Acceleration vector. See also PhQ::ScalarAcceleration.
class Acceleration : public DimensionalVector<Unit::Acceleration, double> {
public:
  // Default constructor. Constructs an acceleration vector with an uninitialized value.
  Acceleration() = default;

  // Constructor. Constructs an acceleration vector with a given value expressed in a given
  // acceleration unit.
  Acceleration(const Vector<double>& value, const Unit::Acceleration unit)
    : DimensionalVector<Unit::Acceleration>(value, unit) {}

  // Constructor. Constructs an acceleration vector from a given scalar acceleration magnitude and
  // direction.
  constexpr Acceleration(const ScalarAcceleration& scalar_acceleration, const Direction& direction)
    : Acceleration(scalar_acceleration.Value() * direction.Value()) {}

  // Constructor. Constructs an acceleration vector from a given velocity and time using the
  // definition of acceleration.
  constexpr Acceleration(const Velocity& velocity, const Time& time)
    : Acceleration(velocity.Value() / time.Value()) {}

  // Constructor. Constructs an acceleration vector from a given velocity and frequency using the
  // definition of acceleration.
  constexpr Acceleration(const Velocity& velocity, const Frequency& frequency)
    : Acceleration(velocity.Value() * frequency.Value()) {}

  // Destructor. Destroys this acceleration vector.
  ~Acceleration() noexcept = default;

  // Copy constructor. Constructs an acceleration vector by copying another one.
  constexpr Acceleration(const Acceleration& other) = default;

  // Move constructor. Constructs an acceleration vector by moving another one.
  constexpr Acceleration(Acceleration&& other) noexcept = default;

  // Copy assignment operator. Assigns this acceleration vector by copying another one.
  constexpr Acceleration& operator=(const Acceleration& other) = default;

  // Move assignment operator. Assigns this acceleration vector by moving another one.
  constexpr Acceleration& operator=(Acceleration&& other) noexcept = default;

  // Statically creates an acceleration vector of zero.
  static constexpr Acceleration Zero() {
    return Acceleration{Vector<>::Zero()};
  }

  // Statically creates an acceleration vector from the given x, y, and z Cartesian components
  // expressed in a given acceleration unit.
  template <Unit::Acceleration Unit>
  static constexpr Acceleration Create(const double x, const double y, const double z) {
    return Acceleration{StaticConvertCopy<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(
        Vector<double>{x, y, z})};
  }

  // Statically creates an acceleration vector from the given x, y, and z Cartesian components
  // expressed in a given acceleration unit.
  template <Unit::Acceleration Unit>
  static constexpr Acceleration Create(const std::array<double, 3>& x_y_z) {
    return Acceleration{StaticConvertCopy<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(
        Vector<double>{x_y_z})};
  }

  // Statically creates an acceleration vector with a given value expressed in a given acceleration
  // unit.
  template <Unit::Acceleration Unit>
  static constexpr Acceleration Create(const Vector<double>& value) {
    return Acceleration{
        StaticConvertCopy<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(value)};
  }

  // Returns the x Cartesian component of this acceleration vector.
  [[nodiscard]] constexpr ScalarAcceleration x() const noexcept {
    return ScalarAcceleration{value.x()};
  }

  // Returns the y Cartesian component of this acceleration vector.
  [[nodiscard]] constexpr ScalarAcceleration y() const noexcept {
    return ScalarAcceleration{value.y()};
  }

  // Returns the z Cartesian component of this acceleration vector.
  [[nodiscard]] constexpr ScalarAcceleration z() const noexcept {
    return ScalarAcceleration{value.z()};
  }

  // Returns the magnitude of this acceleration vector.
  [[nodiscard]] ScalarAcceleration Magnitude() const {
    return ScalarAcceleration{value.Magnitude()};
  }

  // Returns the direction of this acceleration vector.
  [[nodiscard]] PhQ::Direction Direction() const {
    return value.Direction();
  }

  // Returns the angle between this acceleration vector and another one.
  [[nodiscard]] PhQ::Angle Angle(const Acceleration& acceleration) const {
    return {*this, acceleration};
  }

  constexpr Acceleration operator+(const Acceleration& acceleration) const {
    return Acceleration{value + acceleration.value};
  }

  constexpr Acceleration operator-(const Acceleration& acceleration) const {
    return Acceleration{value - acceleration.value};
  }

  constexpr Acceleration operator*(const double number) const {
    return Acceleration{value * number};
  }

  constexpr Velocity operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr Acceleration operator/(const double number) const {
    return Acceleration{value / number};
  }

  constexpr Velocity operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr void operator+=(const Acceleration& acceleration) noexcept {
    value += acceleration.value;
  }

  constexpr void operator-=(const Acceleration& acceleration) noexcept {
    value -= acceleration.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs an acceleration vector with a given value expressed in the standard
  // acceleration unit.
  explicit constexpr Acceleration(const Vector<double>& value)
    : DimensionalVector<Unit::Acceleration>(value) {}
};

inline constexpr bool operator==(const Acceleration& left, const Acceleration& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Acceleration& left, const Acceleration& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Acceleration& left, const Acceleration& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Acceleration& left, const Acceleration& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Acceleration& left, const Acceleration& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Acceleration& left, const Acceleration& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Acceleration& acceleration) {
  stream << acceleration.Print();
  return stream;
}

inline constexpr Acceleration operator*(const double number, const Acceleration& acceleration) {
  return acceleration * number;
}

inline Direction::Direction(const Acceleration& acceleration) : Direction(acceleration.Value()) {}

inline Angle::Angle(const Acceleration& acceleration_1, const Acceleration& acceleration_2)
  : Angle(acceleration_1.Value(), acceleration_2.Value()) {}

inline constexpr Velocity::Velocity(const Acceleration& acceleration, const Time& time)
  : Velocity(acceleration.Value() * time.Value()) {}

inline constexpr Velocity::Velocity(const Acceleration& acceleration, const Frequency& frequency)
  : Velocity(acceleration.Value() / frequency.Value()) {}

inline constexpr Acceleration Direction::operator*(
    const ScalarAcceleration& scalar_acceleration) const {
  return {scalar_acceleration, *this};
}

inline constexpr Velocity Time::operator*(const Acceleration& acceleration) const {
  return {acceleration, *this};
}

inline constexpr Acceleration ScalarAcceleration::operator*(const Direction& direction) const {
  return {*this, direction};
}

inline constexpr Acceleration Velocity::operator*(const Frequency& frequency) const {
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
    return hash<PhQ::Vector<double>>()(acceleration.Value());
  }
};

}  // namespace std

#endif  // PHQ_ACCELERATION_HPP
