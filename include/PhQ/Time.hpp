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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DURATION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DURATION_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Time.hpp"

namespace PhQ {

// Forward declarations for class Time.
class Acceleration;
class AccelerationScalar;
class Angle;
class AngularAccelerationScalar;
class AngularSpeed;
class Displacement;
class Energy;
class Frequency;
class Length;
class Mass;
class MassRate;
class Memory;
class MemoryRate;
class Power;
class SpecificEnergy;
class SpecificPower;
class Speed;
class Strain;
class StrainRate;
class StrainRateScalar;
class StrainScalar;
class Velocity;
class Volume;
class VolumeRate;

// Time. Can represent either a point in time, a time duration, or a period.
class Time : public DimensionalScalar<Unit::Time> {
public:
  // Default constructor. Constructs a time quantity with an uninitialized value.
  Time() = default;

  // Constructor. Constructs a time quantity with a given value expressed in a given time unit.
  Time(const double value, const Unit::Time unit) : DimensionalScalar<Unit::Time>(value, unit) {}

  // Constructor. Constructs a time quantity from a given frequency using the definition of
  // frequency.
  explicit constexpr Time(const PhQ::Frequency& frequency);

  // Constructor. Constructs a time quantity from a given speed and scalar acceleration using the
  // definition of acceleration.
  constexpr Time(const Speed& speed, const AccelerationScalar& acceleration_scalar);

  // Constructor. Constructs a time quantity from a given angular speed and scalar angular
  // acceleration using the definition of angular acceleration.
  constexpr Time(const AngularSpeed& angular_speed,
                 const AngularAccelerationScalar& angular_acceleration_scalar);

  // Constructor. Constructs a time quantity from a given angle and angular speed using the
  // definition of angular speed.
  constexpr Time(const Angle& angle, const AngularSpeed& angular_speed);

  // Constructor. Constructs a time quantity from a given mass and mass rate using the definition of
  // mass rate.
  constexpr Time(const Mass& mass, const MassRate& mass_rate);

  // Constructor. Constructs a time quantity from a given memory and memory rate using the
  // definition of memory rate.
  constexpr Time(const Memory& memory, const MemoryRate& memory_rate);

  // Constructor. Constructs a time quantity from a given energy and power using the definition of
  // power.
  constexpr Time(const Energy& energy, const Power& power);

  // Constructor. Constructs a time quantity from a given specific energy and specific power using
  // the definition of specific power.
  constexpr Time(const SpecificEnergy& specific_energy, const SpecificPower& specific_power);

  // Constructor. Constructs a time quantity from a given length and speed using the definition of
  // speed.
  constexpr Time(const Length& length, const Speed& speed);

  // Constructor. Constructs a time quantity from a given volume and volume rate using the
  // definition of volume rate.
  constexpr Time(const Volume& volume, const VolumeRate& volume_rate);

  // Destructor. Destroys this time quantity.
  ~Time() noexcept = default;

  // Copy constructor. Constructs a time quantity by copying another one.
  constexpr Time(const Time& other) = default;

  // Move constructor. Constructs a time quantity by moving another one.
  constexpr Time(Time&& other) noexcept = default;

  // Copy assignment operator. Assigns this time quantity by copying another one.
  constexpr Time& operator=(const Time& other) = default;

  // Move assignment operator. Assigns this time quantity by moving another one.
  constexpr Time& operator=(Time&& other) noexcept = default;

  // Statically creates a time quantity of zero.
  static constexpr Time Zero() {
    return Time{0.0};
  }

  // Statically creates a time quantity with a given value expressed in a given time unit.
  template <Unit::Time Unit>
  static constexpr Time Create(const double value) {
    return Time{StaticConvertCopy<Unit::Time, Unit, Standard<Unit::Time>>(value)};
  }

  [[nodiscard]] constexpr PhQ::Frequency Frequency() const;

  constexpr Time operator+(const Time& time) const {
    return Time{value_ + time.value_};
  }

  constexpr Time operator-(const Time& time) const {
    return Time{value_ - time.value_};
  }

  constexpr Time operator*(const double number) const {
    return Time{value_ * number};
  }

  constexpr double operator*(const PhQ::Frequency& frequency) const noexcept;

  constexpr Velocity operator*(const Acceleration& acceleration) const;

  constexpr Speed operator*(const AccelerationScalar& acceleration_scalar) const;

  constexpr Mass operator*(const MassRate& mass_rate) const;

  constexpr Energy operator*(const Power& power) const;

  constexpr SpecificEnergy operator*(const SpecificPower& specific_power) const;

  constexpr Strain operator*(const StrainRate& strain_rate) const;

  constexpr StrainScalar operator*(const StrainRateScalar& strain_rate_scalar) const;

  constexpr Displacement operator*(const Velocity& velocity) const;

  constexpr Volume operator*(const VolumeRate& volume_rate) const;

  constexpr Time operator/(const double number) const {
    return Time{value_ / number};
  }

  constexpr double operator/(const Time& time) const noexcept {
    return value_ / time.value_;
  }

  constexpr void operator+=(const Time& time) noexcept {
    value_ += time.value_;
  }

  constexpr void operator-=(const Time& time) noexcept {
    value_ -= time.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a time quantity with a given value expressed in the standard time unit.
  explicit constexpr Time(const double value) : DimensionalScalar<Unit::Time>(value) {}
};

inline constexpr bool operator==(const Time& left, const Time& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Time& left, const Time& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Time& left, const Time& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Time& left, const Time& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Time& left, const Time& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Time& left, const Time& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Time& time) {
  stream << time.Print();
  return stream;
}

inline constexpr Time operator*(const double number, const Time& time) {
  return time * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Time> {
  inline size_t operator()(const PhQ::Time& time) const {
    return hash<double>()(time.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DURATION_HPP
