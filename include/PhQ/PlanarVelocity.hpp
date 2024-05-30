// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef PHQ_PLANAR_VELOCITY_HPP
#define PHQ_PLANAR_VELOCITY_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "Angle.hpp"
#include "DimensionalPlanarVector.hpp"
#include "Frequency.hpp"
#include "PlanarDirection.hpp"
#include "PlanarDisplacement.hpp"
#include "PlanarVector.hpp"
#include "Speed.hpp"
#include "Time.hpp"
#include "Unit/Speed.hpp"

namespace PhQ {

// Forward declaration for class PhQ::PlanarVelocity.
template <typename NumericType>
class PlanarAcceleration;

/// \brief Two-dimensional Euclidean velocity vector in the XY plane. Contains two components in
/// Cartesian coordinates: x and y. For a three-dimensional Euclidean velocity vector, see
/// PhQ::Velocity. For scalar velocity components or for the magnitude of a velocity vector, see
/// PhQ::Speed.
template <typename NumericType = double>
class PlanarVelocity : public DimensionalPlanarVector<Unit::Speed, NumericType> {
public:
  /// \brief Default constructor. Constructs a planar velocity vector with an uninitialized value.
  PlanarVelocity() = default;

  /// \brief Constructor. Constructs a planar velocity vector with a given value expressed in a
  /// given speed unit.
  PlanarVelocity(const PlanarVector<NumericType>& value, const Unit::Speed unit)
    : DimensionalPlanarVector<Unit::Speed, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a planar velocity vector from a given set of speed components.
  PlanarVelocity(const Speed<NumericType>& x, const Speed<NumericType>& y)
    : PlanarVelocity<NumericType>({x.Value(), y.Value()}) {}

  /// \brief Constructor. Constructs a planar velocity vector from a given speed and planar
  /// direction.
  constexpr PlanarVelocity(
      const Speed<NumericType>& speed, const PlanarDirection<NumericType>& planar_direction)
    : PlanarVelocity<NumericType>(speed.Value() * planar_direction.Value()) {}

  /// \brief Constructor. Constructs a planar velocity vector from a given velocity vector by
  /// projecting the velocity vector onto the XY plane.
  explicit constexpr PlanarVelocity(const Velocity<NumericType>& velocity);

  /// \brief Constructor. Constructs a planar velocity vector from a given planar displacement
  /// vector and time using the definition of velocity.
  constexpr PlanarVelocity(
      const PlanarDisplacement<NumericType>& planar_displacement, const Time<NumericType>& time)
    : PlanarVelocity<NumericType>(planar_displacement.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a planar velocity vector from a given planar displacement
  /// vector and frequency using the definition of velocity.
  constexpr PlanarVelocity(const PlanarDisplacement<NumericType>& planar_displacement,
                           const Frequency<NumericType>& frequency)
    : PlanarVelocity<NumericType>(planar_displacement.Value() * frequency.Value()) {}

  /// \brief Constructor. Constructs a planar velocity vector from a given planar acceleration
  /// vector and time using the definition of acceleration.
  constexpr PlanarVelocity(
      const PlanarAcceleration<NumericType>& planar_acceleration, const Time<NumericType>& time);

  /// \brief Constructor. Constructs a planar velocity vector from a given planar acceleration
  /// vector and frequency using the definition of acceleration.
  constexpr PlanarVelocity(const PlanarAcceleration<NumericType>& planar_acceleration,
                           const Frequency<NumericType>& frequency);

  /// \brief Destructor. Destroys this planar velocity vector.
  ~PlanarVelocity() noexcept = default;

  /// \brief Copy constructor. Constructs a planar velocity vector by copying another one.
  constexpr PlanarVelocity(const PlanarVelocity<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a planar velocity by copying another one.
  template <typename OtherNumericType>
  explicit constexpr PlanarVelocity(const PlanarVelocity<OtherNumericType>& other)
    : PlanarVelocity(static_cast<PlanarVector<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar velocity vector by moving another one.
  constexpr PlanarVelocity(PlanarVelocity<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this planar velocity vector by copying another one.
  constexpr PlanarVelocity<NumericType>& operator=(
      const PlanarVelocity<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this planar velocity by copying another one.
  template <typename OtherNumericType>
  constexpr PlanarVelocity<NumericType>& operator=(const PlanarVelocity<OtherNumericType>& other) {
    this->value = static_cast<PlanarVector<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this planar velocity vector by moving another one.
  constexpr PlanarVelocity<NumericType>& operator=(
      PlanarVelocity<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a planar velocity vector of zero.
  static constexpr PlanarVelocity<NumericType> Zero() {
    return PlanarVelocity<NumericType>{PlanarVector<NumericType>::Zero()};
  }

  /// \brief Statically creates a planar velocity vector from the given x and y Cartesian
  /// components expressed in a given speed unit.
  template <Unit::Speed Unit>
  static constexpr PlanarVelocity<NumericType> Create(const NumericType x, const NumericType y) {
    return PlanarVelocity<NumericType>{StaticConvertCopy<Unit::Speed, Unit, Standard<Unit::Speed>>(
        PlanarVector<NumericType>{x, y})};
  }

  /// \brief Statically creates a planar velocity vector from the given x and y Cartesian
  /// components expressed in a given speed unit.
  template <Unit::Speed Unit>
  static constexpr PlanarVelocity<NumericType> Create(const std::array<NumericType, 2>& x_y) {
    return PlanarVelocity<NumericType>{StaticConvertCopy<Unit::Speed, Unit, Standard<Unit::Speed>>(
        PlanarVector<NumericType>{x_y})};
  }

  /// \brief Statically creates a planar velocity vector with a given value expressed in a given
  /// speed unit.
  template <Unit::Speed Unit>
  static constexpr PlanarVelocity<NumericType> Create(const PlanarVector<NumericType>& value) {
    return PlanarVelocity<NumericType>{
        StaticConvertCopy<Unit::Speed, Unit, Standard<Unit::Speed>>(value)};
  }

  /// \brief Returns the x Cartesian component of this planar velocity vector.
  [[nodiscard]] constexpr Speed<NumericType> x() const noexcept {
    return Speed<NumericType>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this planar velocity vector.
  [[nodiscard]] constexpr Speed<NumericType> y() const noexcept {
    return Speed<NumericType>{this->value.y()};
  }

  /// \brief Returns the magnitude of this planar velocity vector.
  [[nodiscard]] Speed<NumericType> Magnitude() const {
    return Speed<NumericType>{this->value.Magnitude()};
  }

  /// \brief Returns the planar direction of this planar velocity vector.
  [[nodiscard]] PhQ::PlanarDirection<NumericType> PlanarDirection() const {
    return this->value.PlanarDirection();
  }

  /// \brief Returns the angle between this planar velocity vector and another one.
  [[nodiscard]] PhQ::Angle<NumericType> Angle(
      const PlanarVelocity<NumericType>& planar_velocity) const {
    return PhQ::Angle<NumericType>{*this, planar_velocity};
  }

  constexpr PlanarVelocity<NumericType> operator+(
      const PlanarVelocity<NumericType>& planar_velocity) const {
    return PlanarVelocity<NumericType>{this->value + planar_velocity.value};
  }

  constexpr PlanarVelocity<NumericType> operator-(
      const PlanarVelocity<NumericType>& planar_velocity) const {
    return PlanarVelocity<NumericType>{this->value - planar_velocity.value};
  }

  constexpr PlanarVelocity<NumericType> operator*(const NumericType number) const {
    return PlanarVelocity<NumericType>{this->value * number};
  }

  constexpr PlanarDisplacement<NumericType> operator*(const Time<NumericType>& time) const {
    return PlanarDisplacement<NumericType>{*this, time};
  }

  constexpr PlanarAcceleration<NumericType> operator*(
      const Frequency<NumericType>& frequency) const;

  constexpr PlanarVelocity<NumericType> operator/(const NumericType number) const {
    return PlanarVelocity<NumericType>{this->value / number};
  }

  constexpr PlanarAcceleration<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr PlanarDisplacement<NumericType> operator/(
      const Frequency<NumericType>& frequency) const {
    return PlanarDisplacement<NumericType>{*this, frequency};
  }

  constexpr void operator+=(const PlanarVelocity<NumericType>& planar_velocity) noexcept {
    this->value += planar_velocity.value;
  }

  constexpr void operator-=(const PlanarVelocity<NumericType>& planar_velocity) noexcept {
    this->value -= planar_velocity.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a planar velocity vector with a given value expressed in the
  /// standard speed unit.
  explicit constexpr PlanarVelocity(const PlanarVector<NumericType>& value)
    : DimensionalPlanarVector<Unit::Speed, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const PlanarVelocity<NumericType>& left, const PlanarVelocity<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const PlanarVelocity<NumericType>& left, const PlanarVelocity<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const PlanarVelocity<NumericType>& left, const PlanarVelocity<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const PlanarVelocity<NumericType>& left, const PlanarVelocity<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const PlanarVelocity<NumericType>& left, const PlanarVelocity<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const PlanarVelocity<NumericType>& left, const PlanarVelocity<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const PlanarVelocity<NumericType>& planar_velocity) {
  stream << planar_velocity.Print();
  return stream;
}

template <typename NumericType>
inline constexpr PlanarVelocity<NumericType> operator*(
    const NumericType number, const PlanarVelocity<NumericType>& planar_velocity) {
  return planar_velocity * number;
}

template <typename NumericType>
inline PlanarDirection<NumericType>::PlanarDirection(
    const PlanarVelocity<NumericType>& planar_velocity)
  : PlanarDirection<NumericType>(planar_velocity.Value()) {}

template <typename NumericType>
inline Angle<NumericType>::Angle(const PlanarVelocity<NumericType>& planar_velocity_1,
                                 const PlanarVelocity<NumericType>& planar_velocity_2)
  : Angle<NumericType>(planar_velocity_1.Value(), planar_velocity_2.Value()) {}

template <typename NumericType>
inline constexpr PlanarDisplacement<NumericType>::PlanarDisplacement(
    const PlanarVelocity<NumericType>& planar_velocity, const Time<NumericType>& time)
  : PlanarDisplacement<NumericType>(planar_velocity.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr PlanarDisplacement<NumericType>::PlanarDisplacement(
    const PlanarVelocity<NumericType>& planar_velocity, const Frequency<NumericType>& frequency)
  : PlanarDisplacement<NumericType>(planar_velocity.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr PlanarVelocity<NumericType> PlanarDirection<NumericType>::operator*(
    const Speed<NumericType>& speed) const {
  return PlanarVelocity<NumericType>{speed, *this};
}

template <typename NumericType>
inline constexpr PlanarDisplacement<NumericType> Time<NumericType>::operator*(
    const PlanarVelocity<NumericType>& planar_velocity) const {
  return PlanarDisplacement<NumericType>{planar_velocity, *this};
}

template <typename NumericType>
inline constexpr PlanarVelocity<NumericType> Speed<NumericType>::operator*(
    const PlanarDirection<NumericType>& planar_direction) const {
  return PlanarVelocity<NumericType>{*this, planar_direction};
}

template <typename NumericType>
inline constexpr PlanarVelocity<NumericType> Frequency<NumericType>::operator*(
    const PlanarDisplacement<NumericType>& planar_displacement) const {
  return PlanarVelocity<NumericType>{planar_displacement, *this};
}

template <typename NumericType>
inline constexpr PlanarVelocity<NumericType> PlanarDisplacement<NumericType>::operator*(
    const Frequency<NumericType>& frequency) const {
  return PlanarVelocity<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr PlanarVelocity<NumericType> PlanarDisplacement<NumericType>::operator/(
    const Time<NumericType>& time) const {
  return PlanarVelocity<NumericType>{*this, time};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::PlanarVelocity<NumericType>> {
  inline size_t operator()(const PhQ::PlanarVelocity<NumericType>& planar_velocity) const {
    return hash<PhQ::PlanarVector<NumericType>>()(planar_velocity.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_VELOCITY_HPP
