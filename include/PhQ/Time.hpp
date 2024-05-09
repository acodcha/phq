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

#ifndef PHQ_DURATION_HPP
#define PHQ_DURATION_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Time.hpp"

namespace PhQ {

// Forward declaration for class PhQ::Time.
template <typename Number>
class Acceleration;

// Forward declaration for class PhQ::Time.
template <typename Number>
class Angle;

// Forward declaration for class PhQ::Time.
template <typename Number>
class AngularSpeed;

// Forward declaration for class PhQ::Time.
template <typename Number>
class Displacement;

// Forward declaration for class PhQ::Time.
template <typename Number>
class DisplacementGradient;

// Forward declaration for class PhQ::Time.
template <typename Number>
class Energy;

// Forward declaration for class PhQ::Time.
template <typename Number>
class Frequency;

// Forward declaration for class PhQ::Time.
template <typename Number>
class Length;

// Forward declaration for class PhQ::Time.
template <typename Number>
class Mass;

// Forward declaration for class PhQ::Time.
template <typename Number>
class MassRate;

// Forward declaration for class PhQ::Time.
template <typename Number>
class Memory;

// Forward declaration for class PhQ::Time.
template <typename Number>
class MemoryRate;

// Forward declaration for class PhQ::Time.
template <typename Number>
class Power;

// Forward declaration for class PhQ::Time.
template <typename Number>
class ScalarAcceleration;

// Forward declaration for class PhQ::Time.
template <typename Number>
class ScalarAngularAcceleration;

// Forward declaration for class PhQ::Time.
template <typename Number>
class ScalarDisplacementGradient;

// Forward declaration for class PhQ::Time.
template <typename Number>
class ScalarStrain;

// Forward declaration for class PhQ::Time.
template <typename Number>
class ScalarStrainRate;

// Forward declaration for class PhQ::Time.
template <typename Number>
class ScalarVelocityGradient;

// Forward declaration for class PhQ::Time.
template <typename Number>
class SpecificEnergy;

// Forward declaration for class PhQ::Time.
template <typename Number>
class SpecificPower;

// Forward declaration for class PhQ::Time.
template <typename Number>
class Speed;

// Forward declaration for class PhQ::Time.
template <typename Number>
class Strain;

// Forward declaration for class PhQ::Time.
template <typename Number>
class StrainRate;

// Forward declaration for class PhQ::Time.
template <typename Number>
class Velocity;

// Forward declaration for class PhQ::Time.
template <typename Number>
class VelocityGradient;

// Forward declaration for class PhQ::Time.
template <typename Number>
class Volume;

// Forward declaration for class PhQ::Time.
template <typename Number>
class VolumeRate;

// Time. Can represent either a point in time, a time duration, or a period.
template <typename Number = double>
class Time : public DimensionalScalar<Unit::Time, Number> {
public:
  // Default constructor. Constructs a time quantity with an uninitialized value.
  Time() = default;

  // Constructor. Constructs a time quantity with a given value expressed in a given time unit.
  Time(const Number value, const Unit::Time unit)
    : DimensionalScalar<Unit::Time, Number>(value, unit) {}

  // Constructor. Constructs a time quantity from a given frequency using the definition of
  // frequency.
  explicit constexpr Time(const PhQ::Frequency<Number>& frequency);

  // Constructor. Constructs a time quantity from a given speed and scalar acceleration using the
  // definition of acceleration.
  constexpr Time(const Speed<Number>& speed, const ScalarAcceleration<Number>& scalar_acceleration);

  // Constructor. Constructs a time quantity from a given angular speed and scalar angular
  // acceleration using the definition of angular acceleration.
  constexpr Time(const AngularSpeed<Number>& angular_speed,
                 const ScalarAngularAcceleration<Number>& scalar_angular_acceleration);

  // Constructor. Constructs a time quantity from a given angle and angular speed using the
  // definition of angular speed.
  constexpr Time(const Angle<Number>& angle, const AngularSpeed<Number>& angular_speed);

  // Constructor. Constructs a time quantity from a given mass and mass rate using the definition of
  // mass rate.
  constexpr Time(const Mass<Number>& mass, const MassRate<Number>& mass_rate);

  // Constructor. Constructs a time quantity from a given memory and memory rate using the
  // definition of memory rate.
  constexpr Time(const Memory<Number>& memory, const MemoryRate<Number>& memory_rate);

  // Constructor. Constructs a time quantity from a given energy and power using the definition of
  // power.
  constexpr Time(const Energy<Number>& energy, const Power<Number>& power);

  // Constructor. Constructs a time quantity from a given specific energy and specific power using
  // the definition of specific power.
  constexpr Time(
      const SpecificEnergy<Number>& specific_energy, const SpecificPower<Number>& specific_power);

  // Constructor. Constructs a time quantity from a given length and speed using the definition of
  // speed.
  constexpr Time(const Length<Number>& length, const Speed<Number>& speed);

  // Constructor. Constructs a time quantity from a given volume and volume rate using the
  // definition of volume rate.
  constexpr Time(const Volume<Number>& volume, const VolumeRate<Number>& volume_rate);

  // Destructor. Destroys this time quantity.
  ~Time() noexcept = default;

  // Copy constructor. Constructs a time quantity by copying another one.
  constexpr Time(const Time<Number>& other) = default;

  // Copy constructor. Constructs a time quantity by copying another one.
  template <typename OtherNumber>
  explicit constexpr Time(const Time<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a time quantity by moving another one.
  constexpr Time(Time<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this time quantity by copying another one.
  constexpr Time<Number>& operator=(const Time<Number>& other) = default;

  // Copy assignment operator. Assigns this time quantity by copying another one.
  template <typename OtherNumber>
  constexpr Time<Number>& operator=(const Time<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this time quantity by moving another one.
  constexpr Time<Number>& operator=(Time<Number>&& other) noexcept = default;

  // Statically creates a time quantity of zero.
  static constexpr Time<Number> Zero() {
    return Time<Number>{static_cast<Number>(0)};
  }

  // Statically creates a time quantity with a given value expressed in a given time unit.
  template <Unit::Time Unit>
  static constexpr Time<Number> Create(const Number value) {
    return Time<Number>{StaticConvertCopy<Unit::Time, Unit, Standard<Unit::Time>>(value)};
  }

  [[nodiscard]] constexpr PhQ::Frequency<Number> Frequency() const;

  constexpr Time<Number> operator+(const Time<Number>& time) const {
    return Time<Number>{value + time.value};
  }

  constexpr Time<Number> operator-(const Time<Number>& time) const {
    return Time<Number>{value - time.value};
  }

  constexpr Time<Number> operator*(const Number number) const {
    return Time<Number>{value * number};
  }

  constexpr Number operator*(const PhQ::Frequency<Number>& frequency) const noexcept;

  constexpr Velocity<Number> operator*(const Acceleration<Number>& acceleration) const;

  constexpr Speed<Number> operator*(const ScalarAcceleration<Number>& scalar_acceleration) const;

  constexpr Mass<Number> operator*(const MassRate<Number>& mass_rate) const;

  constexpr Energy<Number> operator*(const Power<Number>& power) const;

  constexpr SpecificEnergy<Number> operator*(const SpecificPower<Number>& specific_power) const;

  constexpr Strain<Number> operator*(const StrainRate<Number>& strain_rate) const;

  constexpr ScalarStrain<Number> operator*(
      const ScalarStrainRate<Number>& scalar_strain_rate) const;

  constexpr Displacement<Number> operator*(const Velocity<Number>& velocity) const;

  constexpr DisplacementGradient<Number> operator*(
      const VelocityGradient<Number>& velocity_gradient) const;

  constexpr ScalarDisplacementGradient<Number> operator*(
      const ScalarVelocityGradient<Number>& scalar_velocity_gradient) const;

  constexpr Volume<Number> operator*(const VolumeRate<Number>& volume_rate) const;

  constexpr Time<Number> operator/(const Number number) const {
    return Time<Number>{value / number};
  }

  constexpr Number operator/(const Time<Number>& time) const noexcept {
    return value / time.value;
  }

  constexpr void operator+=(const Time<Number>& time) noexcept {
    value += time.value;
  }

  constexpr void operator-=(const Time<Number>& time) noexcept {
    value -= time.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a time quantity with a given value expressed in the standard time unit.
  explicit constexpr Time(const Number value) : DimensionalScalar<Unit::Time>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const Time<Number>& left, const Time<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const Time<Number>& left, const Time<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const Time<Number>& left, const Time<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const Time<Number>& left, const Time<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const Time<Number>& left, const Time<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const Time<Number>& left, const Time<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Time<Number>& time) {
  stream << time.Print();
  return stream;
}

template <typename Number>
inline constexpr Time<Number> operator*(const Number number, const Time<Number>& time) {
  return time * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Time<Number>> {
  inline size_t operator()(const PhQ::Time<Number>& time) const {
    return hash<Number>()(time.Value());
  }
};

}  // namespace std

#endif  // PHQ_DURATION_HPP
