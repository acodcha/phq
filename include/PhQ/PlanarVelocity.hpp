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
template <typename Number>
class PlanarAcceleration;

/// \brief Planar velocity vector in the XY plane. See also PhQ::Velocity and PhQ::Speed.
template <typename Number = double>
class PlanarVelocity : public DimensionalPlanarVector<Unit::Speed, Number> {
public:
  /// \brief Default constructor. Constructs a planar velocity vector with an uninitialized value.
  PlanarVelocity() = default;

  /// \brief Constructor. Constructs a planar velocity vector with a given value expressed in a
  /// given speed unit.
  PlanarVelocity(const PlanarVector<Number>& value, const Unit::Speed unit)
    : DimensionalPlanarVector<Unit::Speed, Number>(value, unit) {}

  /// \brief Constructor. Constructs a planar velocity vector from a given speed and planar
  /// direction.
  constexpr PlanarVelocity(
      const Speed<Number>& speed, const PlanarDirection<Number>& planar_direction)
    : PlanarVelocity<Number>(speed.Value() * planar_direction.Value()) {}

  /// \brief Constructor. Constructs a planar velocity vector from a given velocity vector by
  /// projecting the velocity vector onto the XY plane.
  explicit constexpr PlanarVelocity(const Velocity<Number>& velocity);

  /// \brief Constructor. Constructs a planar velocity vector from a given planar displacement
  /// vector and time using the definition of velocity.
  constexpr PlanarVelocity(
      const PlanarDisplacement<Number>& planar_displacement, const Time<Number>& time)
    : PlanarVelocity<Number>(planar_displacement.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a planar velocity vector from a given planar displacement
  /// vector and frequency using the definition of velocity.
  constexpr PlanarVelocity(
      const PlanarDisplacement<Number>& planar_displacement, const Frequency<Number>& frequency)
    : PlanarVelocity<Number>(planar_displacement.Value() * frequency.Value()) {}

  /// \brief Constructor. Constructs a planar velocity vector from a given planar acceleration
  /// vector and time using the definition of acceleration.
  constexpr PlanarVelocity(
      const PlanarAcceleration<Number>& planar_acceleration, const Time<Number>& time);

  /// \brief Constructor. Constructs a planar velocity vector from a given planar acceleration
  /// vector and frequency using the definition of acceleration.
  constexpr PlanarVelocity(
      const PlanarAcceleration<Number>& planar_acceleration, const Frequency<Number>& frequency);

  /// \brief Destructor. Destroys this planar velocity vector.
  ~PlanarVelocity() noexcept = default;

  /// \brief Copy constructor. Constructs a planar velocity vector by copying another one.
  constexpr PlanarVelocity(const PlanarVelocity<Number>& other) = default;

  /// \brief Copy constructor. Constructs a planar velocity by copying another one.
  template <typename OtherNumber>
  explicit constexpr PlanarVelocity(const PlanarVelocity<OtherNumber>& other)
    : PlanarVelocity(static_cast<PlanarVector<Number>>(other.Value())) {}

  /// \brief Move constructor. Constructs a planar velocity vector by moving another one.
  constexpr PlanarVelocity(PlanarVelocity<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this planar velocity vector by copying another one.
  constexpr PlanarVelocity<Number>& operator=(const PlanarVelocity<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this planar velocity by copying another one.
  template <typename OtherNumber>
  constexpr PlanarVelocity<Number>& operator=(const PlanarVelocity<OtherNumber>& other) {
    this->value = static_cast<PlanarVector<Number>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this planar velocity vector by moving another one.
  constexpr PlanarVelocity<Number>& operator=(PlanarVelocity<Number>&& other) noexcept = default;

  /// \brief Statically creates a planar velocity vector of zero.
  static constexpr PlanarVelocity<Number> Zero() {
    return PlanarVelocity<Number>{PlanarVector<Number>::Zero()};
  }

  /// \brief Statically creates a planar velocity vector from the given x and y Cartesian
  /// components expressed in a given speed unit.
  template <Unit::Speed Unit>
  static constexpr PlanarVelocity<Number> Create(const Number x, const Number y) {
    return PlanarVelocity<Number>{
        StaticConvertCopy<Unit::Speed, Unit, Standard<Unit::Speed>>(PlanarVector<Number>{x, y})};
  }

  /// \brief Statically creates a planar velocity vector from the given x and y Cartesian
  /// components expressed in a given speed unit.
  template <Unit::Speed Unit>
  static constexpr PlanarVelocity<Number> Create(const std::array<Number, 2>& x_y) {
    return PlanarVelocity<Number>{
        StaticConvertCopy<Unit::Speed, Unit, Standard<Unit::Speed>>(PlanarVector<Number>{x_y})};
  }

  /// \brief Statically creates a planar velocity vector with a given value expressed in a given
  /// speed unit.
  template <Unit::Speed Unit>
  static constexpr PlanarVelocity<Number> Create(const PlanarVector<Number>& value) {
    return PlanarVelocity<Number>{
        StaticConvertCopy<Unit::Speed, Unit, Standard<Unit::Speed>>(value)};
  }

  /// \brief Returns the x Cartesian component of this planar velocity vector.
  [[nodiscard]] constexpr Speed<Number> x() const noexcept {
    return Speed<Number>{this->value.x()};
  }

  /// \brief Returns the y Cartesian component of this planar velocity vector.
  [[nodiscard]] constexpr Speed<Number> y() const noexcept {
    return Speed<Number>{this->value.y()};
  }

  /// \brief Returns the magnitude of this planar velocity vector.
  [[nodiscard]] Speed<Number> Magnitude() const {
    return Speed<Number>{this->value.Magnitude()};
  }

  /// \brief Returns the planar direction of this planar velocity vector.
  [[nodiscard]] PhQ::PlanarDirection<Number> PlanarDirection() const {
    return this->value.PlanarDirection();
  }

  /// \brief Returns the angle between this planar velocity vector and another one.
  [[nodiscard]] PhQ::Angle<Number> Angle(const PlanarVelocity<Number>& planar_velocity) const {
    return PhQ::Angle<Number>{*this, planar_velocity};
  }

  constexpr PlanarVelocity<Number> operator+(const PlanarVelocity<Number>& planar_velocity) const {
    return PlanarVelocity<Number>{this->value + planar_velocity.value};
  }

  constexpr PlanarVelocity<Number> operator-(const PlanarVelocity<Number>& planar_velocity) const {
    return PlanarVelocity<Number>{this->value - planar_velocity.value};
  }

  constexpr PlanarVelocity<Number> operator*(const Number number) const {
    return PlanarVelocity<Number>{this->value * number};
  }

  constexpr PlanarDisplacement<Number> operator*(const Time<Number>& time) const {
    return PlanarDisplacement<Number>{*this, time};
  }

  constexpr PlanarAcceleration<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr PlanarVelocity<Number> operator/(const Number number) const {
    return PlanarVelocity<Number>{this->value / number};
  }

  constexpr PlanarAcceleration<Number> operator/(const Time<Number>& time) const;

  constexpr PlanarDisplacement<Number> operator/(const Frequency<Number>& frequency) const {
    return PlanarDisplacement<Number>{*this, frequency};
  }

  constexpr void operator+=(const PlanarVelocity<Number>& planar_velocity) noexcept {
    this->value += planar_velocity.value;
  }

  constexpr void operator-=(const PlanarVelocity<Number>& planar_velocity) noexcept {
    this->value -= planar_velocity.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a planar velocity vector with a given value expressed in the
  /// standard speed unit.
  explicit constexpr PlanarVelocity(const PlanarVector<Number>& value)
    : DimensionalPlanarVector<Unit::Speed, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const PlanarVelocity<Number>& left, const PlanarVelocity<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const PlanarVelocity<Number>& left, const PlanarVelocity<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const PlanarVelocity<Number>& left, const PlanarVelocity<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const PlanarVelocity<Number>& left, const PlanarVelocity<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const PlanarVelocity<Number>& left, const PlanarVelocity<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const PlanarVelocity<Number>& left, const PlanarVelocity<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const PlanarVelocity<Number>& planar_velocity) {
  stream << planar_velocity.Print();
  return stream;
}

template <typename Number>
inline constexpr PlanarVelocity<Number> operator*(
    const Number number, const PlanarVelocity<Number>& planar_velocity) {
  return planar_velocity * number;
}

template <typename Number>
inline PlanarDirection<Number>::PlanarDirection(const PlanarVelocity<Number>& planar_velocity)
  : PlanarDirection<Number>(planar_velocity.Value()) {}

template <typename Number>
inline Angle<Number>::Angle(const PlanarVelocity<Number>& planar_velocity_1,
                            const PlanarVelocity<Number>& planar_velocity_2)
  : Angle<Number>(planar_velocity_1.Value(), planar_velocity_2.Value()) {}

template <typename Number>
inline constexpr PlanarDisplacement<Number>::PlanarDisplacement(
    const PlanarVelocity<Number>& planar_velocity, const Time<Number>& time)
  : PlanarDisplacement<Number>(planar_velocity.Value() * time.Value()) {}

template <typename Number>
inline constexpr PlanarDisplacement<Number>::PlanarDisplacement(
    const PlanarVelocity<Number>& planar_velocity, const Frequency<Number>& frequency)
  : PlanarDisplacement<Number>(planar_velocity.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr PlanarVelocity<Number> PlanarDirection<Number>::operator*(
    const Speed<Number>& speed) const {
  return PlanarVelocity<Number>{speed, *this};
}

template <typename Number>
inline constexpr PlanarDisplacement<Number> Time<Number>::operator*(
    const PlanarVelocity<Number>& planar_velocity) const {
  return PlanarDisplacement<Number>{planar_velocity, *this};
}

template <typename Number>
inline constexpr PlanarVelocity<Number> Speed<Number>::operator*(
    const PlanarDirection<Number>& planar_direction) const {
  return PlanarVelocity<Number>{*this, planar_direction};
}

template <typename Number>
inline constexpr PlanarVelocity<Number> Frequency<Number>::operator*(
    const PlanarDisplacement<Number>& planar_displacement) const {
  return PlanarVelocity<Number>{planar_displacement, *this};
}

template <typename Number>
inline constexpr PlanarVelocity<Number> PlanarDisplacement<Number>::operator*(
    const Frequency<Number>& frequency) const {
  return PlanarVelocity<Number>{*this, frequency};
}

template <typename Number>
inline constexpr PlanarVelocity<Number> PlanarDisplacement<Number>::operator/(
    const Time<Number>& time) const {
  return PlanarVelocity<Number>{*this, time};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::PlanarVelocity<Number>> {
  inline size_t operator()(const PhQ::PlanarVelocity<Number>& planar_velocity) const {
    return hash<PhQ::PlanarVector<Number>>()(planar_velocity.Value());
  }
};

}  // namespace std

#endif  // PHQ_PLANAR_VELOCITY_HPP
