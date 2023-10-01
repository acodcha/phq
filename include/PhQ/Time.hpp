// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DURATION_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DURATION_HPP

#include "DimensionalScalarQuantity.hpp"
#include "Unit/Time.hpp"

namespace PhQ {

// Forward declarations for class Time.
class Acceleration;
class AccelerationMagnitude;
class Angle;
class AngularAccelerationMagnitude;
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
class Velocity;
class Volume;
class VolumeRate;

// Time. Can represent either a point in time, a time duration, or a period.
class Time : public DimensionalScalarQuantity<Unit::Time> {
public:
  // Default constructor. Constructs a time quantity with an uninitialized
  // value.
  Time() = default;

  // Constructor. Constructs a time quantity with a given value expressed in a
  // given time unit.
  Time(const double value, const Unit::Time unit)
    : DimensionalScalarQuantity<Unit::Time>(value, unit) {}

  // Constructor. Constructs a time quantity from a given frequency using the
  // definition of frequency.
  constexpr Time(const PhQ::Frequency& frequency);

  // Constructor. Constructs a time quantity from a given acceleration magnitude
  // and speed using the definition of acceleration.
  constexpr Time(
      const AccelerationMagnitude& acceleration_magnitude, const Speed& speed);

  // Constructor. Constructs a time quantity from a given angular acceleration
  // magnitude and angular speed using the definition of angular acceleration.
  constexpr Time(
      const AngularAccelerationMagnitude& angular_acceleration_magnitude,
      const AngularSpeed& angular_speed);

  // Constructor. Constructs a time quantity from a given angular speed and
  // angle using the definition of angular speed.
  constexpr Time(const AngularSpeed& angular_speed, const Angle& angle);

  // Constructor. Constructs a time quantity from a given mass rate and mass
  // using the definition of mass rate.
  constexpr Time(const MassRate& mass_rate, const Mass& mass);

  // Constructor. Constructs a time quantity from a given memory rate and memory
  // using the definition of memory rate.
  constexpr Time(const MemoryRate& memory_rate, const Memory& memory);

  // Constructor. Constructs a time quantity from a given power and energy using
  // the definition of power.
  constexpr Time(const Power& power, const Energy& energy);

  // Constructor. Constructs a time quantity from a given specific power and
  // specific energy using the definition of specific power.
  constexpr Time(const SpecificPower& specific_power,
                 const SpecificEnergy& specific_energy);

  // Constructor. Constructs a time quantity from a given speed and length using
  // the definition of speed.
  constexpr Time(const Speed& speed, const Length& length);

  // Constructor. Constructs a time quantity from a given volume rate and volume
  // using the definition of volume rate.
  constexpr Time(const VolumeRate& volume_rate, const Volume& volume);

  // Destructor. Destroys this time quantity.
  ~Time() noexcept = default;

  // Copy constructor. Constructs a time quantity by copying another one.
  constexpr Time(const Time& other) = default;

  // Move constructor. Constructs a time quantity by moving another one.
  constexpr Time(Time&& other) noexcept = default;

  // Copy assignment operator. Assigns this time quantity by copying another
  // one.
  constexpr Time& operator=(const Time& other) = default;

  // Move assignment operator. Assigns this time quantity by moving another one.
  constexpr Time& operator=(Time&& other) noexcept = default;

  // Statically creates a time quantity of zero.
  static constexpr Time Zero() {
    return Time{0.0};
  }

  // Statically creates a time quantity with a given value expressed in a given
  // time unit.
  template <Unit::Time Unit>
  static constexpr Time Create(const double value) {
    return Time{
        StaticConvertCopy<Unit::Time, Unit, Standard<Unit::Time>>(value)};
  }

  constexpr PhQ::Frequency Frequency() const;

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

  constexpr Mass operator*(const MassRate& mass_rate) const;

  constexpr Volume operator*(const VolumeRate& volume_rate) const;

  constexpr Energy operator*(const Power& power) const;

  constexpr SpecificEnergy operator*(const SpecificPower& specific_power) const;

  constexpr Strain operator*(const StrainRate& strain_rate) const;

  constexpr Displacement operator*(const Velocity& velocity) const;

  constexpr Velocity operator*(const Acceleration& acceleration) const;

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
  // Constructor. Constructs a time quantity with a given value expressed in the
  // standard time unit.
  explicit constexpr Time(const double value)
    : DimensionalScalarQuantity<Unit::Time>(value) {}
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
