// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
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
#include "Unit/Speed.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Speed.
template <typename Number>
class Direction;

// Forward declaration for class PhQ::Speed.
template <typename Number>
class DynamicKinematicPressure;

// Forward declaration for class PhQ::Speed.
template <typename Number>
class DynamicPressure;

// Forward declaration for class PhQ::Speed.
template <typename Number>
class DynamicViscosity;

// Forward declaration for class PhQ::Speed.
template <typename Number>
class KinematicViscosity;

// Forward declaration for class PhQ::Speed.
template <typename Number>
class MachNumber;

// Forward declaration for class PhQ::Speed.
template <typename Number>
class MassDensity;

// Forward declaration for class PhQ::Speed.
template <typename Number>
class Power;

// Forward declaration for class PhQ::Speed.
template <typename Number>
class ReynoldsNumber;

// Forward declaration for class PhQ::Speed.
template <typename Number>
class ScalarAcceleration;

// Forward declaration for class PhQ::Speed.
template <typename Number>
class SoundSpeed;

// Forward declaration for class PhQ::Speed.
template <typename Number>
class TransportEnergyConsumption;

// Forward declaration for class PhQ::Speed.
template <typename Number>
class Velocity;

// Speed scalar. Magnitude of the velocity vector.
template <typename Number = double>
class Speed : public DimensionalScalar<Unit::Speed, Number> {
public:
  // Default constructor. Constructs a speed with an uninitialized value.
  Speed() = default;

  // Constructor. Constructs a speed with a given value expressed in a given speed unit.
  Speed(const Number value, const Unit::Speed unit)
    : DimensionalScalar<Unit::Speed, Number>(value, unit) {}

  // Constructor. Constructs a speed from a given length and time duration using the definition of
  // speed.
  constexpr Speed(const Length<Number>& length, const Time<Number>& time)
    : Speed<Number>(length.Value() / time.Value()) {}

  // Constructor. Constructs a speed from a given length and frequency using the definition of
  // speed.
  constexpr Speed(const Length<Number>& length, const Frequency<Number>& frequency)
    : Speed<Number>(length.Value() * frequency.Value()) {}

  // Constructor. Constructs a speed from a given scalar acceleration and time duration using the
  // definition of acceleration.
  constexpr Speed(const ScalarAcceleration<Number>& scalar_acceleration, const Time<Number>& time);

  // Constructor. Constructs a speed from a given scalar acceleration and frequency using the
  // definition of acceleration.
  constexpr Speed(
      const ScalarAcceleration<Number>& scalar_acceleration, const Frequency<Number>& frequency);

  // Constructor. Constructs a speed from a given dynamic pressure and mass density using the
  // definition of dynamic pressure.
  Speed(const DynamicPressure<Number>& dynamic_pressure, const MassDensity<Number>& mass_density);

  // Constructor. Constructs a speed from a given dynamic kinematic pressure using the definition of
  // dynamic kinematic pressure.
  explicit Speed(const DynamicKinematicPressure<Number>& dynamic_kinematic_pressure);

  // Constructor. Constructs a speed from a given Reynolds number, dynamic viscosity, mass density,
  // and length using the definition of the Reynolds number.
  constexpr Speed(const ReynoldsNumber<Number>& reynolds_number,
                  const DynamicViscosity<Number>& dynamic_viscosity,
                  const MassDensity<Number>& mass_density, const Length<Number>& length);

  // Constructor. Constructs a speed from a given Reynolds number, kinematic viscosity, and length
  // using the definition of the Reynolds number.
  constexpr Speed(
      const ReynoldsNumber<Number>& reynolds_number,
      const KinematicViscosity<Number>& kinematic_viscosity, const Length<Number>& length);

  // Constructor. Constructs a speed from a given sound speed and Mach number using the definition
  // of the Mach number.
  constexpr Speed(const SoundSpeed<Number>& sound_speed, const MachNumber<Number>& mach_number);

  // Destructor. Destroys this speed.
  ~Speed() noexcept = default;

  // Copy constructor. Constructs a speed by copying another one.
  constexpr Speed(const Speed<Number>& other) = default;

  // Copy constructor. Constructs a speed by copying another one.
  template <typename OtherNumber>
  explicit constexpr Speed(const Speed<OtherNumber>& other)
    : Speed(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a speed by moving another one.
  constexpr Speed(Speed<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this speed by copying another one.
  constexpr Speed<Number>& operator=(const Speed<Number>& other) = default;

  // Copy assignment operator. Assigns this speed by copying another one.
  template <typename OtherNumber>
  constexpr Speed<Number>& operator=(const Speed<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this speed by moving another one.
  constexpr Speed<Number>& operator=(Speed<Number>&& other) noexcept = default;

  // Statically creates a speed of zero.
  static constexpr Speed<Number> Zero() {
    return Speed<Number>{static_cast<Number>(0)};
  }

  // Statically creates a speed with a given value expressed in a given speed unit.
  template <Unit::Speed Unit>
  static constexpr Speed<Number> Create(const Number value) {
    return Speed<Number>{StaticConvertCopy<Unit::Speed, Unit, Standard<Unit::Speed>>(value)};
  }

  constexpr Speed<Number> operator+(const Speed<Number>& speed) const {
    return Speed<Number>{this->value + speed.value};
  }

  constexpr Speed<Number> operator+(const SoundSpeed<Number>& sound_speed) const;

  constexpr Speed<Number> operator-(const Speed<Number>& speed) const {
    return Speed<Number>{this->value - speed.value};
  }

  constexpr Speed<Number> operator-(const SoundSpeed<Number>& sound_speed) const;

  constexpr Speed<Number> operator*(const Number number) const {
    return Speed<Number>{this->value * number};
  }

  constexpr Length<Number> operator*(const Time<Number>& time) const {
    return Length<Number>{*this, time};
  }

  constexpr ScalarAcceleration<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr Velocity<Number> operator*(const Direction<Number>& direction) const;

  constexpr Power<Number> operator*(
      const TransportEnergyConsumption<Number>& transport_energy_consumption) const;

  constexpr Speed<Number> operator/(const Number number) const {
    return Speed<Number>{this->value / number};
  }

  constexpr Length<Number> operator/(const Frequency<Number>& frequency) const {
    return Length<Number>{*this, frequency};
  }

  constexpr Frequency<Number> operator/(const Length<Number>& length) const {
    return Frequency<Number>{*this, length};
  }

  constexpr ScalarAcceleration<Number> operator/(const Time<Number>& time) const;

  constexpr Time<Number> operator/(const ScalarAcceleration<Number>& scalar_acceleration) const;

  constexpr MachNumber<Number> operator/(const SoundSpeed<Number>& sound_speed) const;

  constexpr Number operator/(const Speed<Number>& speed) const noexcept {
    return this->value / speed.value;
  }

  constexpr void operator+=(const Speed<Number>& speed) noexcept {
    this->value += speed.value;
  }

  constexpr void operator+=(const SoundSpeed<Number>& speed) noexcept;

  constexpr void operator-=(const Speed<Number>& speed) noexcept {
    this->value -= speed.value;
  }

  constexpr void operator-=(const SoundSpeed<Number>& speed) noexcept;

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a speed with a given value expressed in the standard speed unit.
  explicit constexpr Speed(const Number value) : DimensionalScalar<Unit::Speed, Number>(value) {}

  template <typename OtherNumber>
  friend class SoundSpeed;

  template <typename OtherNumber>
  friend class Velocity;
};

template <typename Number>
inline constexpr bool operator==(const Speed<Number>& left, const Speed<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const Speed<Number>& left, const Speed<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const Speed<Number>& left, const Speed<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const Speed<Number>& left, const Speed<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const Speed<Number>& left, const Speed<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const Speed<Number>& left, const Speed<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Speed<Number>& speed) {
  stream << speed.Print();
  return stream;
}

template <typename Number>
inline constexpr Speed<Number> operator*(const Number number, const Speed<Number>& speed) {
  return speed * number;
}

template <typename Number>
inline constexpr Length<Number>::Length(const Speed<Number>& speed, const Time<Number>& time)
  : Length<Number>(speed.Value() * time.Value()) {}

template <typename Number>
inline constexpr Length<Number>::Length(
    const Speed<Number>& speed, const Frequency<Number>& frequency)
  : Length<Number>(speed.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr Time<Number>::Time(const Length<Number>& length, const Speed<Number>& speed)
  : Time<Number>(length.Value() / speed.Value()) {}

template <typename Number>
inline constexpr Frequency<Number>::Frequency(
    const Speed<Number>& speed, const Length<Number>& length)
  : Frequency<Number>(speed.Value() / length.Value()) {}

template <typename Number>
inline constexpr Speed<Number> Length<Number>::operator*(const Frequency<Number>& frequency) const {
  return Speed<Number>{*this, frequency};
}

template <typename Number>
inline constexpr Time<Number> Length<Number>::operator/(const Speed<Number>& speed) const {
  return Time<Number>{*this, speed};
}

template <typename Number>
inline constexpr Speed<Number> Length<Number>::operator/(const Time<Number>& time) const {
  return Speed<Number>{*this, time};
}

template <typename Number>
inline constexpr Speed<Number> Frequency<Number>::operator*(const Length<Number>& length) const {
  return Speed<Number>{length, *this};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Speed<Number>> {
  inline size_t operator()(const PhQ::Speed<Number>& speed) const {
    return hash<Number>()(speed.Value());
  }
};

}  // namespace std

#endif  // PHQ_SPEED_HPP
