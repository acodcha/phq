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

#ifndef PHQ_VELOCITY_HPP
#define PHQ_VELOCITY_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalVector.hpp"
#include "Direction.hpp"
#include "Displacement.hpp"
#include "Frequency.hpp"
#include "Speed.hpp"
#include "Time.hpp"
#include "Unit/Speed.hpp"
#include "Vector.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Velocity.
template <typename Number>
class Acceleration;

// Velocity vector.
template <typename Number = double>
class Velocity : public DimensionalVector<Unit::Speed, Number> {
public:
  // Default constructor. Constructs a velocity vector with an uninitialized value.
  Velocity() = default;

  // Constructor. Constructs a velocity vector with a given value expressed in a given speed unit.
  Velocity(const Vector<Number>& value, const Unit::Speed unit)
    : DimensionalVector<Unit::Speed, Number>(value, unit) {}

  // Constructor. Constructs a velocity vector from a given speed and direction.
  constexpr Velocity(const Speed<Number>& speed, const Direction<Number>& direction)
    : Velocity<Number>(speed.Value() * direction.Value()) {}

  // Constructor. Constructs a velocity vector from a given displacement vector and time using the
  // definition of velocity.
  constexpr Velocity(const Displacement<Number>& displacement, const Time<Number>& time)
    : Velocity<Number>(displacement.Value() / time.Value()) {}

  // Constructor. Constructs a velocity vector from a given displacement vector and frequency using
  // the definition of velocity.
  constexpr Velocity(const Displacement<Number>& displacement, const Frequency<Number>& frequency)
    : Velocity<Number>(displacement.Value() * frequency.Value()) {}

  // Constructor. Constructs a velocity vector from a given acceleration vector and time using the
  // definition of acceleration.
  constexpr Velocity(const Acceleration<Number>& acceleration, const Time<Number>& time);

  // Constructor. Constructs a velocity vector from a given acceleration vector and frequency using
  // the definition of acceleration.
  constexpr Velocity(const Acceleration<Number>& acceleration, const Frequency<Number>& frequency);

  // Destructor. Destroys this velocity vector.
  ~Velocity() noexcept = default;

  // Copy constructor. Constructs a velocity vector by copying another one.
  constexpr Velocity(const Velocity<Number>& other) = default;

  // Copy constructor. Constructs a velocity by copying another one.
  template <typename OtherNumber>
  explicit constexpr Velocity(const Velocity<OtherNumber>& other)
    : Velocity(static_cast<Vector<Number>>(other.Value())) {}

  // Move constructor. Constructs a velocity vector by moving another one.
  constexpr Velocity(Velocity<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this velocity vector by copying another one.
  constexpr Velocity<Number>& operator=(const Velocity<Number>& other) = default;

  // Copy assignment operator. Assigns this velocity by copying another one.
  template <typename OtherNumber>
  constexpr Velocity<Number>& operator=(const Velocity<OtherNumber>& other) {
    this->value = static_cast<Vector<Number>>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this velocity vector by moving another one.
  constexpr Velocity<Number>& operator=(Velocity<Number>&& other) noexcept = default;

  // Statically creates a velocity vector of zero.
  static constexpr Velocity<Number> Zero() {
    return Velocity<Number>{Vector<Number>::Zero()};
  }

  // Statically creates a velocity vector from the given x, y, and z Cartesian components expressed
  // in a given speed unit.
  template <Unit::Speed Unit>
  static constexpr Velocity<Number> Create(const Number x, const Number y, const Number z) {
    return Velocity<Number>{
        StaticConvertCopy<Unit::Speed, Unit, Standard<Unit::Speed>>(Vector<Number>{x, y, z})};
  }

  // Statically creates a velocity vector from the given x, y, and z Cartesian components expressed
  // in a given speed unit.
  template <Unit::Speed Unit>
  static constexpr Velocity<Number> Create(const std::array<Number, 3>& x_y_z) {
    return Velocity<Number>{
        StaticConvertCopy<Unit::Speed, Unit, Standard<Unit::Speed>>(Vector<Number>{x_y_z})};
  }

  // Statically creates a velocity vector with a given value expressed in a given speed unit.
  template <Unit::Speed Unit>
  static constexpr Velocity<Number> Create(const Vector<Number>& value) {
    return Velocity<Number>{StaticConvertCopy<Unit::Speed, Unit, Standard<Unit::Speed>>(value)};
  }

  // Returns the x Cartesian component of this velocity vector.
  [[nodiscard]] constexpr Speed<Number> x() const noexcept {
    return Speed<Number>{this->value.x()};
  }

  // Returns the y Cartesian component of this velocity vector.
  [[nodiscard]] constexpr Speed<Number> y() const noexcept {
    return Speed<Number>{this->value.y()};
  }

  // Returns the z Cartesian component of this velocity vector.
  [[nodiscard]] constexpr Speed<Number> z() const noexcept {
    return Speed<Number>{this->value.z()};
  }

  // Returns the magnitude of this velocity vector.
  [[nodiscard]] Speed<Number> Magnitude() const {
    return Speed<Number>{this->value.Magnitude()};
  }

  // Returns the direction of this velocity vector.
  [[nodiscard]] PhQ::Direction<Number> Direction() const {
    return this->value.Direction();
  }

  // Returns the angle between this velocity vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const Velocity<Number>& velocity) const {
    return PhQ::Angle<Number>{*this, velocity};
  }

  constexpr Velocity<Number> operator+(const Velocity<Number>& velocity) const {
    return Velocity<Number>{this->value + velocity.value};
  }

  constexpr Velocity<Number> operator-(const Velocity<Number>& velocity) const {
    return Velocity<Number>{this->value - velocity.value};
  }

  constexpr Velocity<Number> operator*(const Number number) const {
    return Velocity<Number>{this->value * number};
  }

  constexpr Displacement<Number> operator*(const Time<Number>& time) const {
    return Displacement<Number>{*this, time};
  }

  constexpr Acceleration<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr Velocity<Number> operator/(const Number number) const {
    return Velocity<Number>{this->value / number};
  }

  constexpr Acceleration<Number> operator/(const Time<Number>& time) const;

  constexpr Displacement<Number> operator/(const Frequency<Number>& frequency) const {
    return Displacement<Number>{*this, frequency};
  }

  constexpr void operator+=(const Velocity<Number>& velocity) noexcept {
    this->value += velocity.value;
  }

  constexpr void operator-=(const Velocity<Number>& velocity) noexcept {
    this->value -= velocity.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a velocity vector with a given value expressed in the standard speed
  // unit.
  explicit constexpr Velocity(const Vector<Number>& value)
    : DimensionalVector<Unit::Speed, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const Velocity<Number>& left, const Velocity<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const Velocity<Number>& left, const Velocity<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const Velocity<Number>& left, const Velocity<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const Velocity<Number>& left, const Velocity<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const Velocity<Number>& left, const Velocity<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const Velocity<Number>& left, const Velocity<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Velocity<Number>& velocity) {
  stream << velocity.Print();
  return stream;
}

template <typename Number>
inline constexpr Velocity<Number> operator*(const Number number, const Velocity<Number>& velocity) {
  return velocity * number;
}

template <typename Number>
inline Direction<Number>::Direction(const Velocity<Number>& velocity)
  : Direction<Number>(velocity.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(const Velocity<Number>& velocity1, const Velocity<Number>& velocity2)
  : Angle<Number>(velocity1.Value(), velocity2.Value()) {}

template <typename Number>
inline constexpr Displacement<Number>::Displacement(
    const Velocity<Number>& velocity, const Time<Number>& time)
  : Displacement<Number>(velocity.Value() * time.Value()) {}

template <typename Number>
inline constexpr Displacement<Number>::Displacement(
    const Velocity<Number>& velocity, const Frequency<Number>& frequency)
  : Displacement<Number>(velocity.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr Velocity<Number> Direction<Number>::operator*(const Speed<Number>& speed) const {
  return Velocity<Number>{speed, *this};
}

template <typename Number>
inline constexpr Displacement<Number> Time<Number>::operator*(
    const Velocity<Number>& velocity) const {
  return Displacement<Number>{velocity, *this};
}

template <typename Number>
inline constexpr Velocity<Number> Speed<Number>::operator*(
    const Direction<Number>& direction) const {
  return Velocity<Number>{*this, direction};
}

template <typename Number>
inline constexpr Velocity<Number> Frequency<Number>::operator*(
    const Displacement<Number>& displacement) const {
  return Velocity<Number>{displacement, *this};
}

template <typename Number>
inline constexpr Velocity<Number> Displacement<Number>::operator*(
    const Frequency<Number>& frequency) const {
  return Velocity<Number>{*this, frequency};
}

template <typename Number>
inline constexpr Velocity<Number> Displacement<Number>::operator/(const Time<Number>& time) const {
  return Velocity<Number>{*this, time};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Velocity<Number>> {
  inline size_t operator()(const PhQ::Velocity<Number>& velocity) const {
    return hash<PhQ::Vector<Number>>()(velocity.Value());
  }
};

}  // namespace std

#endif  // PHQ_VELOCITY_HPP
