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
template <typename Number = double>
class Acceleration : public DimensionalVector<Unit::Acceleration, Number> {
public:
  // Default constructor. Constructs an acceleration vector with an uninitialized value.
  Acceleration() = default;

  // Constructor. Constructs an acceleration vector with a given value expressed in a given
  // acceleration unit.
  Acceleration(const Vector<Number>& value, const Unit::Acceleration unit)
    : DimensionalVector<Unit::Acceleration, Number>(value, unit) {}

  // Constructor. Constructs an acceleration vector from a given scalar acceleration magnitude and
  // direction.
  constexpr Acceleration(
      const ScalarAcceleration<Number>& scalar_acceleration, const Direction<Number>& direction)
    : Acceleration<Number>(scalar_acceleration.Value() * direction.Value()) {}

  // Constructor. Constructs an acceleration vector from a given velocity and time using the
  // definition of acceleration.
  constexpr Acceleration(const Velocity<Number>& velocity, const Time<Number>& time)
    : Acceleration<Number>(velocity.Value() / time.Value()) {}

  // Constructor. Constructs an acceleration vector from a given velocity and frequency using the
  // definition of acceleration.
  constexpr Acceleration(const Velocity<Number>& velocity, const Frequency<Number>& frequency)
    : Acceleration<Number>(velocity.Value() * frequency.Value()) {}

  // Destructor. Destroys this acceleration vector.
  ~Acceleration() noexcept = default;

  // Copy constructor. Constructs an acceleration vector by copying another one.
  constexpr Acceleration(const Acceleration<Number>& other) = default;

  // Copy constructor. Constructs an acceleration vector by copying another one.
  template <typename OtherNumber>
  explicit constexpr Acceleration(const Acceleration<OtherNumber>& other)
    : Acceleration(static_cast<Vector<Number>>(other.Value())) {}

  // Move constructor. Constructs an acceleration vector by moving another one.
  constexpr Acceleration(Acceleration<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this acceleration vector by copying another one.
  constexpr Acceleration<Number>& operator=(const Acceleration<Number>& other) = default;

  // Copy assignment operator. Assigns this acceleration vector by copying another one.
  template <typename OtherNumber>
  constexpr Acceleration<Number>& operator=(const Acceleration<OtherNumber>& other) {
    this->value = static_cast<Vector<Number>>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this acceleration vector by moving another one.
  constexpr Acceleration<Number>& operator=(Acceleration<Number>&& other) noexcept = default;

  // Statically creates an acceleration vector of zero.
  static constexpr Acceleration<Number> Zero() {
    return Acceleration<Number>{Vector<Number>::Zero()};
  }

  // Statically creates an acceleration vector from the given x, y, and z Cartesian components
  // expressed in a given acceleration unit.
  template <Unit::Acceleration Unit>
  static constexpr Acceleration<Number> Create(const Number x, const Number y, const Number z) {
    return Acceleration<Number>{
        StaticConvertCopy<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(
            Vector<Number>{x, y, z})};
  }

  // Statically creates an acceleration vector from the given x, y, and z Cartesian components
  // expressed in a given acceleration unit.
  template <Unit::Acceleration Unit>
  static constexpr Acceleration<Number> Create(const std::array<Number, 3>& x_y_z) {
    return Acceleration<Number>{
        StaticConvertCopy<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(
            Vector<Number>{x_y_z})};
  }

  // Statically creates an acceleration vector with a given value expressed in a given acceleration
  // unit.
  template <Unit::Acceleration Unit>
  static constexpr Acceleration<Number> Create(const Vector<Number>& value) {
    return Acceleration<Number>{
        StaticConvertCopy<Unit::Acceleration, Unit, Standard<Unit::Acceleration>>(value)};
  }

  // Returns the x Cartesian component of this acceleration vector.
  [[nodiscard]] constexpr ScalarAcceleration<Number> x() const noexcept {
    return ScalarAcceleration<Number>{this->value.x()};
  }

  // Returns the y Cartesian component of this acceleration vector.
  [[nodiscard]] constexpr ScalarAcceleration<Number> y() const noexcept {
    return ScalarAcceleration<Number>{this->value.y()};
  }

  // Returns the z Cartesian component of this acceleration vector.
  [[nodiscard]] constexpr ScalarAcceleration<Number> z() const noexcept {
    return ScalarAcceleration<Number>{this->value.z()};
  }

  // Returns the magnitude of this acceleration vector.
  [[nodiscard]] ScalarAcceleration<Number> Magnitude() const {
    return ScalarAcceleration<Number>{this->value.Magnitude()};
  }

  // Returns the direction of this acceleration vector.
  [[nodiscard]] PhQ::Direction<Number> Direction() const {
    return this->value.Direction();
  }

  // Returns the angle between this acceleration vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const Acceleration<Number>& other) const {
    return PhQ::Angle<Number>{*this, other};
  }

  constexpr Acceleration<Number> operator+(const Acceleration<Number>& other) const {
    return Acceleration<Number>{this->value + other.value};
  }

  constexpr Acceleration<Number> operator-(const Acceleration<Number>& other) const {
    return Acceleration<Number>{this->value - other.value};
  }

  constexpr Acceleration<Number> operator*(const Number number) const {
    return Acceleration<Number>{this->value * number};
  }

  constexpr Velocity<Number> operator*(const Time<Number>& time) const {
    return Velocity<Number>{*this, time};
  }

  constexpr Acceleration<Number> operator/(const Number number) const {
    return Acceleration<Number>{this->value / number};
  }

  constexpr Velocity<Number> operator/(const Frequency<Number>& frequency) const {
    return Velocity<Number>{*this, frequency};
  }

  constexpr void operator+=(const Acceleration<Number>& other) noexcept {
    this->value += other.value;
  }

  constexpr void operator-=(const Acceleration<Number>& other) noexcept {
    this->value -= other.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs an acceleration vector with a given value expressed in the standard
  // acceleration unit.
  explicit constexpr Acceleration(const Vector<Number>& value)
    : DimensionalVector<Unit::Acceleration, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const Acceleration<Number>& left, const Acceleration<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const Acceleration<Number>& left, const Acceleration<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const Acceleration<Number>& left, const Acceleration<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const Acceleration<Number>& left, const Acceleration<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const Acceleration<Number>& left, const Acceleration<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const Acceleration<Number>& left, const Acceleration<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Acceleration<Number>& acceleration) {
  stream << acceleration.Print();
  return stream;
}

template <typename Number>
inline constexpr Acceleration<Number> operator*(
    const Number number, const Acceleration<Number>& acceleration) {
  return acceleration * number;
}

template <typename Number>
inline Direction<Number>::Direction(const Acceleration<Number>& acceleration)
  : Direction<Number>(acceleration.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(
    const Acceleration<Number>& acceleration_1, const Acceleration<Number>& acceleration_2)
  : Angle<Number>(acceleration_1.Value(), acceleration_2.Value()) {}

template <typename Number>
inline constexpr Velocity<Number>::Velocity(
    const Acceleration<Number>& acceleration, const Time<Number>& time)
  : Velocity<Number>(acceleration.Value() * time.Value()) {}

template <typename Number>
inline constexpr Velocity<Number>::Velocity(
    const Acceleration<Number>& acceleration, const Frequency<Number>& frequency)
  : Velocity<Number>(acceleration.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr Acceleration<Number> Direction<Number>::operator*(
    const ScalarAcceleration<Number>& scalar_acceleration) const {
  return Acceleration<Number>{scalar_acceleration, *this};
}

template <typename Number>
inline constexpr Velocity<Number> Time<Number>::operator*(
    const Acceleration<Number>& acceleration) const {
  return Velocity<Number>{acceleration, *this};
}

template <typename Number>
inline constexpr Acceleration<Number> ScalarAcceleration<Number>::operator*(
    const Direction<Number>& direction) const {
  return Acceleration<Number>{*this, direction};
}

template <typename Number>
inline constexpr Acceleration<Number> Velocity<Number>::operator*(
    const Frequency<Number>& frequency) const {
  return Acceleration<Number>{*this, frequency};
}

template <typename Number>
inline constexpr Acceleration<Number> Velocity<Number>::operator/(const Time<Number>& time) const {
  return Acceleration<Number>{*this, time};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Acceleration<Number>> {
  inline size_t operator()(const PhQ::Acceleration<Number>& acceleration) const {
    return hash<PhQ::Vector<Number>>()(acceleration.Value());
  }
};

}  // namespace std

#endif  // PHQ_ACCELERATION_HPP
