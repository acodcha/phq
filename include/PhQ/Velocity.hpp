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

// Forward declaration for class Velocity.
class Acceleration;

// Velocity vector.
class Velocity : public DimensionalVector<Unit::Speed> {
public:
  // Default constructor. Constructs a velocity vector with an uninitialized value.
  Velocity() = default;

  // Constructor. Constructs a velocity vector with a given value expressed in a given speed unit.
  Velocity(const Vector& value, const Unit::Speed unit)
    : DimensionalVector<Unit::Speed>(value, unit) {}

  // Constructor. Constructs a velocity vector from a given speed and direction.
  constexpr Velocity(const Speed& speed, const Direction& direction)
    : Velocity(speed.Value() * direction.Value()) {}

  // Constructor. Constructs a velocity vector from a given displacement vector and time using the
  // definition of velocity.
  constexpr Velocity(const Displacement& displacement, const Time& time)
    : Velocity(displacement.Value() / time.Value()) {}

  // Constructor. Constructs a velocity vector from a given displacement vector and frequency using
  // the definition of velocity.
  constexpr Velocity(const Displacement& displacement, const Frequency& frequency)
    : Velocity(displacement.Value() * frequency.Value()) {}

  // Constructor. Constructs a velocity vector from a given acceleration vector and time using the
  // definition of acceleration.
  constexpr Velocity(const Acceleration& acceleration, const Time& time);

  // Constructor. Constructs a velocity vector from a given acceleration vector and frequency using
  // the definition of acceleration.
  constexpr Velocity(const Acceleration& acceleration, const Frequency& frequency);

  // Destructor. Destroys this velocity vector.
  ~Velocity() noexcept = default;

  // Copy constructor. Constructs a velocity vector by copying another one.
  constexpr Velocity(const Velocity& other) = default;

  // Move constructor. Constructs a velocity vector by moving another one.
  constexpr Velocity(Velocity&& other) noexcept = default;

  // Copy assignment operator. Assigns this velocity vector by copying another one.
  constexpr Velocity& operator=(const Velocity& other) = default;

  // Move assignment operator. Assigns this velocity vector by moving another one.
  constexpr Velocity& operator=(Velocity&& other) noexcept = default;

  // Statically creates a velocity vector of zero.
  static constexpr Velocity Zero() {
    return Velocity{Vector::Zero()};
  }

  // Statically creates a velocity vector from the given x, y, and z Cartesian components expressed
  // in a given speed unit.
  template <Unit::Speed Unit>
  static constexpr Velocity Create(const double x, const double y, const double z) {
    return Velocity{StaticConvertCopy<Unit::Speed, Unit, Standard<Unit::Speed>>(Vector{x, y, z})};
  }

  // Statically creates a velocity vector from the given x, y, and z Cartesian components expressed
  // in a given speed unit.
  template <Unit::Speed Unit>
  static constexpr Velocity Create(const std::array<double, 3>& x_y_z) {
    return Velocity{StaticConvertCopy<Unit::Speed, Unit, Standard<Unit::Speed>>(Vector{x_y_z})};
  }

  // Statically creates a velocity vector with a given value expressed in a given speed unit.
  template <Unit::Speed Unit>
  static constexpr Velocity Create(const Vector& value) {
    return Velocity{StaticConvertCopy<Unit::Speed, Unit, Standard<Unit::Speed>>(value)};
  }

  // Returns the x Cartesian component of this velocity vector.
  [[nodiscard]] constexpr Speed x() const noexcept {
    return Speed{value_.x()};
  }

  // Returns the y Cartesian component of this velocity vector.
  [[nodiscard]] constexpr Speed y() const noexcept {
    return Speed{value_.y()};
  }

  // Returns the z Cartesian component of this velocity vector.
  [[nodiscard]] constexpr Speed z() const noexcept {
    return Speed{value_.z()};
  }

  // Returns the magnitude of this velocity vector.
  [[nodiscard]] Speed Magnitude() const {
    return Speed{value_.Magnitude()};
  }

  // Returns the direction of this velocity vector.
  [[nodiscard]] PhQ::Direction Direction() const {
    return value_.Direction();
  }

  // Returns the angle between this velocity vector and another one.
  [[nodiscard]] PhQ::Angle Angle(const Velocity& velocity) const {
    return {*this, velocity};
  }

  constexpr Velocity operator+(const Velocity& velocity) const {
    return Velocity{value_ + velocity.value_};
  }

  constexpr Velocity operator-(const Velocity& velocity) const {
    return Velocity{value_ - velocity.value_};
  }

  constexpr Velocity operator*(const double number) const {
    return Velocity{value_ * number};
  }

  constexpr Displacement operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr Acceleration operator*(const Frequency& frequency) const;

  constexpr Velocity operator/(const double number) const {
    return Velocity{value_ / number};
  }

  constexpr Acceleration operator/(const Time& time) const;

  constexpr Displacement operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr void operator+=(const Velocity& velocity) noexcept {
    value_ += velocity.value_;
  }

  constexpr void operator-=(const Velocity& velocity) noexcept {
    value_ -= velocity.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a velocity vector with a given value expressed in the standard speed
  // unit.
  explicit constexpr Velocity(const Vector& value) : DimensionalVector<Unit::Speed>(value) {}
};

inline constexpr bool operator==(const Velocity& left, const Velocity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Velocity& left, const Velocity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Velocity& left, const Velocity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Velocity& left, const Velocity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Velocity& left, const Velocity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Velocity& left, const Velocity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Velocity& velocity) {
  stream << velocity.Print();
  return stream;
}

inline constexpr Velocity operator*(const double number, const Velocity& velocity) {
  return velocity * number;
}

inline Direction::Direction(const Velocity& velocity) : Direction(velocity.Value()) {}

inline Angle::Angle(const Velocity& velocity1, const Velocity& velocity2)
  : Angle(velocity1.Value(), velocity2.Value()) {}

inline constexpr Displacement::Displacement(const Velocity& velocity, const Time& time)
  : Displacement(velocity.Value() * time.Value()) {}

inline constexpr Displacement::Displacement(const Velocity& velocity, const Frequency& frequency)
  : Displacement(velocity.Value() / frequency.Value()) {}

inline constexpr Velocity Direction::operator*(const Speed& speed) const {
  return {speed, *this};
}

inline constexpr Displacement Time::operator*(const Velocity& velocity) const {
  return {velocity, *this};
}

inline constexpr Velocity Speed::operator*(const Direction& direction) const {
  return {*this, direction};
}

inline constexpr Velocity Frequency::operator*(const Displacement& displacement) const {
  return {displacement, *this};
}

inline constexpr Velocity Displacement::operator*(const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr Velocity Displacement::operator/(const Time& time) const {
  return {*this, time};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Velocity> {
  inline size_t operator()(const PhQ::Velocity& velocity) const {
    return hash<PhQ::Vector>()(velocity.Value());
  }
};

}  // namespace std

#endif  // PHQ_VELOCITY_HPP
