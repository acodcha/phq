// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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

#ifndef PHQ_SPEED_HPP
#define PHQ_SPEED_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "Length.hpp"
#include "Time.hpp"
#include "Unit/Speed.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Speed.
template <typename NumericType>
class Direction;

// Forward declaration for class PhQ::Speed.
template <typename NumericType>
class DynamicKinematicPressure;

// Forward declaration for class PhQ::Speed.
template <typename NumericType>
class DynamicPressure;

// Forward declaration for class PhQ::Speed.
template <typename NumericType>
class DynamicViscosity;

// Forward declaration for class PhQ::Speed.
template <typename NumericType>
class KinematicViscosity;

// Forward declaration for class PhQ::Speed.
template <typename NumericType>
class MachNumber;

// Forward declaration for class PhQ::Speed.
template <typename NumericType>
class MassDensity;

// Forward declaration for class PhQ::Speed.
template <typename NumericType>
class PlanarVelocity;

// Forward declaration for class PhQ::Speed.
template <typename NumericType>
class Power;

// Forward declaration for class PhQ::Speed.
template <typename NumericType>
class ReynoldsNumber;

// Forward declaration for class PhQ::Speed.
template <typename NumericType>
class ScalarAcceleration;

// Forward declaration for class PhQ::Speed.
template <typename NumericType>
class SoundSpeed;

// Forward declaration for class PhQ::Speed.
template <typename NumericType>
class TransportEnergyConsumption;

// Forward declaration for class PhQ::Speed.
template <typename NumericType>
class Velocity;

/// \brief Scalar velocity component or magnitude of a velocity vector. For a three-dimensional
/// Euclidean velocity vector, see PhQ::Velocity. For a two-dimensional Euclidean velocity vector in
/// the XY plane, see PhQ::PlanarVelocity.
template <typename NumericType = double>
class Speed : public DimensionalScalar<Unit::Speed, NumericType> {
public:
  /// \brief Default constructor. Constructs a speed with an uninitialized value.
  Speed() = default;

  /// \brief Constructor. Constructs a speed with a given value expressed in a given speed unit.
  Speed(const NumericType value, const Unit::Speed unit)
    : DimensionalScalar<Unit::Speed, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a speed from a given length and time duration using the
  /// definition of speed.
  constexpr Speed(const Length<NumericType>& length, const Time<NumericType>& time)
    : Speed<NumericType>(length.Value() / time.Value()) {}

  /// \brief Constructor. Constructs a speed from a given length and frequency using the definition
  /// of speed.
  constexpr Speed(const Length<NumericType>& length, const Frequency<NumericType>& frequency)
    : Speed<NumericType>(length.Value() * frequency.Value()) {}

  /// \brief Constructor. Constructs a speed from a given scalar acceleration and time duration
  /// using the definition of acceleration.
  constexpr Speed(
      const ScalarAcceleration<NumericType>& scalar_acceleration, const Time<NumericType>& time);

  /// \brief Constructor. Constructs a speed from a given scalar acceleration and frequency using
  /// the definition of acceleration.
  constexpr Speed(const ScalarAcceleration<NumericType>& scalar_acceleration,
                  const Frequency<NumericType>& frequency);

  /// \brief Constructor. Constructs a speed from a given dynamic pressure and mass density using
  /// the definition of dynamic pressure.
  Speed(const DynamicPressure<NumericType>& dynamic_pressure,
        const MassDensity<NumericType>& mass_density);

  /// \brief Constructor. Constructs a speed from a given dynamic kinematic pressure using the
  /// definition of dynamic kinematic pressure.
  explicit Speed(const DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure);

  /// \brief Constructor. Constructs a speed from a given Reynolds number, dynamic viscosity, mass
  /// density, and length using the definition of the Reynolds number.
  constexpr Speed(const ReynoldsNumber<NumericType>& reynolds_number,
                  const DynamicViscosity<NumericType>& dynamic_viscosity,
                  const MassDensity<NumericType>& mass_density, const Length<NumericType>& length);

  /// \brief Constructor. Constructs a speed from a given Reynolds number, kinematic viscosity, and
  /// length using the definition of the Reynolds number.
  constexpr Speed(const ReynoldsNumber<NumericType>& reynolds_number,
                  const KinematicViscosity<NumericType>& kinematic_viscosity,
                  const Length<NumericType>& length);

  /// \brief Constructor. Constructs a speed from a given sound speed and Mach number using the
  /// definition of the Mach number.
  constexpr Speed(
      const SoundSpeed<NumericType>& sound_speed, const MachNumber<NumericType>& mach_number);

  /// \brief Destructor. Destroys this speed.
  ~Speed() noexcept = default;

  /// \brief Copy constructor. Constructs a speed by copying another one.
  constexpr Speed(const Speed<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a speed by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Speed(const Speed<OtherNumericType>& other)
    : Speed(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a speed by moving another one.
  constexpr Speed(Speed<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this speed by copying another one.
  constexpr Speed<NumericType>& operator=(const Speed<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this speed by copying another one.
  template <typename OtherNumericType>
  constexpr Speed<NumericType>& operator=(const Speed<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this speed by moving another one.
  constexpr Speed<NumericType>& operator=(Speed<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a speed of zero.
  static constexpr Speed<NumericType> Zero() {
    return Speed<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a speed with a given value expressed in a given speed unit.
  template <Unit::Speed Unit>
  static constexpr Speed<NumericType> Create(const NumericType value) {
    return Speed<NumericType>{ConvertStatically<Unit::Speed, Unit, Standard<Unit::Speed>>(value)};
  }

  constexpr Speed<NumericType> operator+(const Speed<NumericType>& speed) const {
    return Speed<NumericType>{this->value + speed.value};
  }

  constexpr Speed<NumericType> operator+(const SoundSpeed<NumericType>& sound_speed) const;

  constexpr Speed<NumericType> operator-(const Speed<NumericType>& speed) const {
    return Speed<NumericType>{this->value - speed.value};
  }

  constexpr Speed<NumericType> operator-(const SoundSpeed<NumericType>& sound_speed) const;

  constexpr Speed<NumericType> operator*(const NumericType number) const {
    return Speed<NumericType>{this->value * number};
  }

  constexpr Length<NumericType> operator*(const Time<NumericType>& time) const {
    return Length<NumericType>{*this, time};
  }

  constexpr ScalarAcceleration<NumericType> operator*(
      const Frequency<NumericType>& frequency) const;

  constexpr PlanarVelocity<NumericType> operator*(
      const PlanarDirection<NumericType>& direction) const;

  constexpr Velocity<NumericType> operator*(const Direction<NumericType>& direction) const;

  constexpr Power<NumericType> operator*(
      const TransportEnergyConsumption<NumericType>& transport_energy_consumption) const;

  constexpr Speed<NumericType> operator/(const NumericType number) const {
    return Speed<NumericType>{this->value / number};
  }

  constexpr Length<NumericType> operator/(const Frequency<NumericType>& frequency) const {
    return Length<NumericType>{*this, frequency};
  }

  constexpr Frequency<NumericType> operator/(const Length<NumericType>& length) const {
    return Frequency<NumericType>{*this, length};
  }

  constexpr ScalarAcceleration<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr Time<NumericType> operator/(
      const ScalarAcceleration<NumericType>& scalar_acceleration) const;

  constexpr MachNumber<NumericType> operator/(const SoundSpeed<NumericType>& sound_speed) const;

  constexpr NumericType operator/(const Speed<NumericType>& speed) const noexcept {
    return this->value / speed.value;
  }

  constexpr void operator+=(const Speed<NumericType>& speed) noexcept {
    this->value += speed.value;
  }

  constexpr void operator+=(const SoundSpeed<NumericType>& speed) noexcept;

  constexpr void operator-=(const Speed<NumericType>& speed) noexcept {
    this->value -= speed.value;
  }

  constexpr void operator-=(const SoundSpeed<NumericType>& speed) noexcept;

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a speed with a given value expressed in the standard speed
  /// unit.
  explicit constexpr Speed(const NumericType value)
    : DimensionalScalar<Unit::Speed, NumericType>(value) {}

  template <typename OtherNumericType>
  friend class SoundSpeed;

  template <typename OtherNumericType>
  friend class PlanarVelocity;

  template <typename OtherNumericType>
  friend class Velocity;
};

template <typename NumericType>
inline constexpr bool operator==(
    const Speed<NumericType>& left, const Speed<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Speed<NumericType>& left, const Speed<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Speed<NumericType>& left, const Speed<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Speed<NumericType>& left, const Speed<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Speed<NumericType>& left, const Speed<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Speed<NumericType>& left, const Speed<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Speed<NumericType>& speed) {
  stream << speed.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Speed<NumericType> operator*(
    const NumericType number, const Speed<NumericType>& speed) {
  return speed * number;
}

template <typename NumericType>
inline constexpr Length<NumericType>::Length(
    const Speed<NumericType>& speed, const Time<NumericType>& time)
  : Length<NumericType>(speed.Value() * time.Value()) {}

template <typename NumericType>
inline constexpr Length<NumericType>::Length(
    const Speed<NumericType>& speed, const Frequency<NumericType>& frequency)
  : Length<NumericType>(speed.Value() / frequency.Value()) {}

template <typename NumericType>
inline constexpr Time<NumericType>::Time(
    const Length<NumericType>& length, const Speed<NumericType>& speed)
  : Time<NumericType>(length.Value() / speed.Value()) {}

template <typename NumericType>
inline constexpr Frequency<NumericType>::Frequency(
    const Speed<NumericType>& speed, const Length<NumericType>& length)
  : Frequency<NumericType>(speed.Value() / length.Value()) {}

template <typename NumericType>
inline constexpr Speed<NumericType> Length<NumericType>::operator*(
    const Frequency<NumericType>& frequency) const {
  return Speed<NumericType>{*this, frequency};
}

template <typename NumericType>
inline constexpr Time<NumericType> Length<NumericType>::operator/(
    const Speed<NumericType>& speed) const {
  return Time<NumericType>{*this, speed};
}

template <typename NumericType>
inline constexpr Speed<NumericType> Length<NumericType>::operator/(
    const Time<NumericType>& time) const {
  return Speed<NumericType>{*this, time};
}

template <typename NumericType>
inline constexpr Speed<NumericType> Frequency<NumericType>::operator*(
    const Length<NumericType>& length) const {
  return Speed<NumericType>{length, *this};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Speed<NumericType>> {
  inline size_t operator()(const PhQ::Speed<NumericType>& speed) const {
    return hash<NumericType>()(speed.Value());
  }
};

}  // namespace std

#endif  // PHQ_SPEED_HPP
