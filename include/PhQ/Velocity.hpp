// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
#include "PlanarVelocity.hpp"
#include "Speed.hpp"
#include "Time.hpp"
#include "Unit/Speed.hpp"
#include "Vector.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Velocity.
template <typename NumericType>
class Acceleration;

/// \brief Three-dimensional Euclidean velocity vector. Contains three components in Cartesian
/// coordinates: x, y, and z. For a two-dimensional Euclidean velocity vector in the XY plane, see
/// PhQ::PlanarVelocity. For scalar velocity components or for the magnitude of a velocity vector,
/// see PhQ::Speed.
template <typename NumericType = double>
class Velocity : public DimensionalVector<Unit::Speed, NumericType> {
public:
  /// \brief Default constructor. Constructs a velocity vector with an uninitialized value.
  Velocity() = default;

  /// \brief Constructor. Constructs a velocity vector with a given value expressed in a given speed
  /// unit.
  Velocity(const Vector<NumericType>& value, const Unit::Speed unit)
    : DimensionalVector<Unit::Speed, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a velocity vector from a given set of speed components.
  Velocity(const Speed<NumericType>& x, const Speed<NumericType>& y, const Speed<NumericType>& z)
    : Velocity<NumericType>({x.Value(), y.Value(), z.Value()}) {}

  /// \brief Constructor. Constructs a velocity vector from a given speed and direction.
  constexpr Velocity(const Speed<NumericType>& speed, const Direction<NumericType>& direction)
    : Velocity<NumericType>(speed.Value() * direction.Value()) {}

  /// \brief Constructor. Constructs a velocity vector from a given planar velocity vector in the XY
  /// plane. This velocity vector's z-component is initialized to zero.
  explicit constexpr Velocity(const PlanarVelocity<NumericType>& planar_velocity)
    : Velocity<NumericType>(Vector<NumericType>{planar_velocity.Value()}) {}

  /// \brief Constructor. Constructs a velocity vector from a given displacement vector and time
  /// using the definition of velocity.
  constexpr Velocity(const Displacement<NumericType>& displacement, const Time<NumericType>& time)
    : Velocity<NumericType>(displacement.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a velocity vector from a given displacement vector and
  /// frequency using the definition of velocity.
  constexpr Velocity(
      const Displacement<NumericType>& displacement, const Frequency<NumericType>& frequency)
    : Velocity<NumericType>(displacement.Value() * frequency.Value()) {}

  /// \brief Constructor. Constructs a velocity vector from a given acceleration vector and time
  /// using the definition of acceleration.
  constexpr Velocity(const Acceleration<NumericType>& acceleration, const Time<NumericType>& time);

  /// \brief Constructor. Constructs a velocity vector from a given acceleration vector and
  /// frequency using the definition of acceleration.
  constexpr Velocity(
      const Acceleration<NumericType>& acceleration, const Frequency<NumericType>& frequency);

  /// \brief Destructor. Destroys this velocity vector.
  ~Velocity() noexcept = default;

  /// \brief Copy constructor. Constructs a velocity vector by copying another one.
  constexpr Velocity(const Velocity<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a velocity by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Velocity(const Velocity<OtherNumericType>& other)
    : Velocity(static_cast<Vector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a velocity vector by moving another one.
  constexpr Velocity(Velocity<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this velocity vector by copying another one.
  constexpr Velocity<NumericType>& operator=(const Velocity<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this velocity by copying another one.
  template <typename OtherNumericType>
  constexpr Velocity<NumericType>& operator=(const Velocity<OtherNumericType>& other) {
    this->value = static_cast<Vector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this velocity vector by moving another one.
  constexpr Velocity<NumericType>& operator=(Velocity<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a velocity vector of zero.
  static constexpr Velocity<NumericType> Zero() {
    return Velocity<NumericType>{Vector<NumericType>::Zero()};
  }

  /// \brief Statically creates a velocity vector from the given x, y, and z Cartesian components
  /// expressed in a given speed unit.
  template <Unit::Speed Unit>
  static constexpr Velocity<NumericType> Create(
      const NumericType x, const NumericType y, const NumericType z) {
    return Velocity<NumericType>{
        ConvertStatically<Unit::Speed, Unit, Standard<Unit::Speed>>(Vector<NumericType>{x, y, z})};
  }

  /// \brief Statically creates a velocity vector from the given x, y, and z Cartesian components
  /// expressed in a given speed unit.
  template <Unit::Speed Unit>
  static constexpr Velocity<NumericType> Create(const std::array<NumericType, 3>& x_y_z) {
    return Velocity<NumericType>{
        ConvertStatically<Unit::Speed, Unit, Standard<Unit::Speed>>(Vector<NumericType>{x_y_z})};
  }

  /// \brief Statically creates a velocity vector with a given value expressed in a given speed
  /// unit.
  template <Unit::Speed Unit>
  static constexpr Velocity<NumericType> Create(const Vector<NumericType>& value) {
    return Velocity<NumericType>{
        ConvertStatically<Unit::Speed, Unit, Standard<Unit::Speed>>(value)};
  }

  /// \brief Returns the x Cartesian component of this velocity vector.
  [[nodiscard]] constexpr Speed<NumericType> x() const noexcept {
    return Speed<NumericType>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this velocity vector.
  [[nodiscard]] constexpr Speed<NumericType> y() const noexcept {
    return Speed<NumericType>{this->value.y()};
  }

  /// \brief Returns the z Cartesian component of this velocity vector.
  [[nodiscard]] constexpr Speed<NumericType> z() const noexcept {
    return Speed<NumericType>{this->value.z()};
  }

  /// \brief Returns the magnitude of this velocity vector.
  [[nodiscard]] Speed<NumericType> Magnitude() const {
    return Speed<NumericType>{this->value.Magnitude()};
  }

  /// \brief Returns the direction of this velocity vector.
  [[nodiscard]] PhQ::Direction<NumericType> Direction() const {
    return this->value.Direction();
  }

  /// \brief Returns the angle between this velocity vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(const Velocity<NumericType>& velocity) const {
    return PhQ::Angle<NumericType>{*this, velocity};
  }

  constexpr Velocity<NumericType> operator+(const Velocity<NumericType>& velocity) const {
    return Velocity<NumericType>{this->value + velocity.value};
  }

  constexpr Velocity<NumericType> operator-(const Velocity<NumericType>& velocity) const {
    return Velocity<NumericType>{this->value - velocity.value};
  }

  constexpr Velocity<NumericType> operator*(const NumericType number) const {
    return Velocity<NumericType>{this->value * number};
  }

  constexpr Displacement<NumericType> operator*(const Time<NumericType>& time) const {
    return Displacement<NumericType>{*this, time};
  }

  constexpr Acceleration<NumericType> operator*(const Frequency<NumericType>& frequency) const;

  constexpr Velocity<NumericType> operator/(const NumericType number) const {
    return Velocity<NumericType>{this->value / number};
  }

  constexpr Acceleration<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr Displacement<NumericType> operator/(const Frequency<NumericType>& frequency) const {
    return Displacement<NumericType>{*this, frequency};
  }

  constexpr void operator+=(const Velocity<NumericType>& velocity) noexcept {
    this->value += velocity.value;
  }

  constexpr void operator-=(const Velocity<NumericType>& velocity) noexcept {
    this->value -= velocity.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a velocity vector with a given value expressed in the standard
  /// speed unit.
  explicit constexpr Velocity(const Vector<NumericType>& value)
    : DimensionalVector<Unit::Speed, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const Velocity<NumericType>& left, const Velocity<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Velocity<NumericType>& left, const Velocity<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Velocity<NumericType>& left, const Velocity<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Velocity<NumericType>& left, const Velocity<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Velocity<NumericType>& left, const Velocity<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Velocity<NumericType>& left, const Velocity<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Velocity<NumericType>& velocity) {
  stream << velocity.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Velocity<NumericType> operator*(
    const NumericType number, const Velocity<NumericType>& velocity) {
  return velocity * number;
}

template <typename NumericType>
inline Direction<NumericType>::Direction(const Velocity<NumericType>& velocity)
  : Direction<NumericType>(velocity.Value()) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(
    const Velocity<NumericType>& velocity1, const Velocity<NumericType>& velocity2)
  : Angle<NumericType>(velocity1.Value(), velocity2.Value()) {}

template <typename NumericType>
inline constexpr Displacement<NumericType>::Displacement(
    const Velocity<NumericType>& velocity, const Time<NumericType>& time)
  : Displacement<NumericType>(velocity.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr Displacement<NumericType>::Displacement(
    const Velocity<NumericType>& velocity, const Frequency<NumericType>& frequency)
  : Displacement<NumericType>(velocity.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr PlanarVelocity<NumericType>::PlanarVelocity(const Velocity<NumericType>& velocity)
  : PlanarVelocity(PlanarVector<NumericType>{velocity.Value()}) {}

template <typename NumericType>
inline constexpr Velocity<NumericType> Direction<NumericType>::operator*(
    const Speed<NumericType>& speed) const {
  return Velocity<NumericType>{speed, *this};
}

template <typename NumericType>
inline constexpr Displacement<NumericType> Time<NumericType>::operator*(
    const Velocity<NumericType>& velocity) const {
  return Displacement<NumericType>{velocity, *this};
}

template <typename NumericType>
inline constexpr Velocity<NumericType> Speed<NumericType>::operator*(
    const Direction<NumericType>& direction) const {
  return Velocity<NumericType>{*this, direction};
}

template <typename NumericType>
inline constexpr Velocity<NumericType> Frequency<NumericType>::operator*(
    const Displacement<NumericType>& displacement) const {
  return Velocity<NumericType>{displacement, *this};
}

template <typename NumericType>
inline constexpr Velocity<NumericType> Displacement<NumericType>::operator*(
    const Frequency<NumericType>& frequency) const {
  return Velocity<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr Velocity<NumericType> Displacement<NumericType>::operator/(
    const Time<NumericType>& time) const {
  return Velocity<NumericType>{*this, time};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Velocity<NumericType>> {
  inline size_t operator()(const PhQ::Velocity<NumericType>& velocity) const {
    return hash<PhQ::Vector<NumericType>>()(velocity.Value());
  }
};

}  // namespace std

#endif  // PHQ_VELOCITY_HPP
