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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPEED_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPEED_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "Length.hpp"
#include "Unit/Speed.hpp"

namespace PhQ {

// Forward declarations for class Speed.
class AccelerationScalar;
class Direction;
class DynamicKinematicPressure;
class DynamicPressure;
class DynamicViscosity;
class KinematicViscosity;
class MachNumber;
class MassDensity;
class Power;
class ReynoldsNumber;
class SoundSpeed;
class TransportEnergyConsumption;
class Velocity;

// Speed scalar. Magnitude of the velocity vector.
class Speed : public DimensionalScalar<Unit::Speed> {
public:
  // Default constructor. Constructs a speed with an uninitialized value.
  Speed() = default;

  // Constructor. Constructs a speed with a given value expressed in a given speed unit.
  Speed(const double value, const Unit::Speed unit) : DimensionalScalar<Unit::Speed>(value, unit) {}

  // Constructor. Constructs a speed from a given length and time duration using the definition of
  // speed.
  constexpr Speed(const Length& length, const Time& time) : Speed(length.Value() / time.Value()) {}

  // Constructor. Constructs a speed from a given length and frequency using the definition of
  // speed.
  constexpr Speed(const Length& length, const Frequency& frequency)
    : Speed(length.Value() * frequency.Value()) {}

  // Constructor. Constructs a speed from a given scalar acceleration and time duration using the
  // definition of acceleration.
  constexpr Speed(const AccelerationScalar& acceleration_scalar, const Time& time);

  // Constructor. Constructs a speed from a given scalar acceleration and frequency using the
  // definition of acceleration.
  constexpr Speed(const AccelerationScalar& acceleration_scalar, const Frequency& frequency);

  // Constructor. Constructs a speed from a given dynamic pressure and mass density using the
  // definition of dynamic pressure.
  Speed(const DynamicPressure& dynamic_pressure, const MassDensity& mass_density);

  // Constructor. Constructs a speed from a given dynamic kinematic pressure using the definition of
  // dynamic kinematic pressure.
  explicit Speed(const DynamicKinematicPressure& dynamic_kinematic_pressure);

  // Constructor. Constructs a speed from a given Reynolds number, dynamic viscosity, mass density,
  // and length using the definition of the Reynolds number.
  constexpr Speed(const ReynoldsNumber& reynolds_number, const DynamicViscosity& dynamic_viscosity,
                  const MassDensity& mass_density, const Length& length);

  // Constructor. Constructs a speed from a given Reynolds number, kinematic viscosity, and length
  // using the definition of the Reynolds number.
  constexpr Speed(const ReynoldsNumber& reynolds_number,
                  const KinematicViscosity& kinematic_viscosity, const Length& length);

  // Constructor. Constructs a speed from a given sound speed and Mach number using the definition
  // of the Mach number.
  constexpr Speed(const SoundSpeed& sound_speed, const MachNumber& mach_number);

  // Destructor. Destroys this speed.
  ~Speed() noexcept = default;

  // Copy constructor. Constructs a speed by copying another one.
  constexpr Speed(const Speed& other) = default;

  // Move constructor. Constructs a speed by moving another one.
  constexpr Speed(Speed&& other) noexcept = default;

  // Copy assignment operator. Assigns this speed by copying another one.
  constexpr Speed& operator=(const Speed& other) = default;

  // Move assignment operator. Assigns this speed by moving another one.
  constexpr Speed& operator=(Speed&& other) noexcept = default;

  // Statically creates a speed of zero.
  static constexpr Speed Zero() {
    return Speed{0.0};
  }

  // Statically creates a speed with a given value expressed in a given speed unit.
  template <Unit::Speed Unit>
  static constexpr Speed Create(const double value) {
    return Speed{StaticConvertCopy<Unit::Speed, Unit, Standard<Unit::Speed>>(value)};
  }

  constexpr Speed operator+(const Speed& speed) const {
    return Speed{value_ + speed.value_};
  }

  constexpr Speed operator+(const SoundSpeed& sound_speed) const;

  constexpr Speed operator-(const Speed& speed) const {
    return Speed{value_ - speed.value_};
  }

  constexpr Speed operator-(const SoundSpeed& sound_speed) const;

  constexpr Speed operator*(const double number) const {
    return Speed{value_ * number};
  }

  constexpr Length operator*(const Time& time) const {
    return {*this, time};
  }

  constexpr AccelerationScalar operator*(const Frequency& frequency) const;

  constexpr Velocity operator*(const Direction& direction) const;

  constexpr Power operator*(const TransportEnergyConsumption& transport_energy_consumption) const;

  constexpr Speed operator/(const double number) const {
    return Speed{value_ / number};
  }

  constexpr Length operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const Length& length) const {
    return {*this, length};
  }

  constexpr AccelerationScalar operator/(const Time& time) const;

  constexpr Time operator/(const AccelerationScalar& acceleration_scalar) const;

  constexpr MachNumber operator/(const SoundSpeed& sound_speed) const;

  constexpr double operator/(const Speed& speed) const noexcept {
    return value_ / speed.value_;
  }

  constexpr void operator+=(const Speed& speed) noexcept {
    value_ += speed.value_;
  }

  constexpr void operator+=(const SoundSpeed& speed) noexcept;

  constexpr void operator-=(const Speed& speed) noexcept {
    value_ -= speed.value_;
  }

  constexpr void operator-=(const SoundSpeed& speed) noexcept;

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a speed with a given value expressed in the standard speed unit.
  explicit constexpr Speed(const double value) : DimensionalScalar<Unit::Speed>(value) {}

  friend class SoundSpeed;

  friend class Velocity;
};

inline constexpr bool operator==(const Speed& left, const Speed& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Speed& left, const Speed& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Speed& left, const Speed& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Speed& left, const Speed& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Speed& left, const Speed& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Speed& left, const Speed& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Speed& speed) {
  stream << speed.Print();
  return stream;
}

inline constexpr Speed operator*(const double number, const Speed& speed) {
  return speed * number;
}

inline constexpr Length::Length(const Speed& speed, const Time& time)
  : Length(speed.Value() * time.Value()) {}

inline constexpr Length::Length(const Speed& speed, const Frequency& frequency)
  : Length(speed.Value() / frequency.Value()) {}

inline constexpr Time::Time(const Length& length, const Speed& speed)
  : Time(length.Value() / speed.Value()) {}

inline constexpr Frequency::Frequency(const Speed& speed, const Length& length)
  : Frequency(speed.Value() / length.Value()) {}

inline constexpr Speed Length::operator*(const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr Time Length::operator/(const Speed& speed) const {
  return {*this, speed};
}

inline constexpr Speed Length::operator/(const Time& time) const {
  return {*this, time};
}

inline constexpr Speed Frequency::operator*(const Length& length) const {
  return {length, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Speed> {
  inline size_t operator()(const PhQ::Speed& speed) const {
    return hash<double>()(speed.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPEED_HPP
