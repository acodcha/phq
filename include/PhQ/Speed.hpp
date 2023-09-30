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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPEED_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPEED_HPP

#include "Frequency.hpp"
#include "Length.hpp"
#include "Unit/Speed.hpp"

namespace PhQ {

// Forward declarations for class Speed.
class AccelerationMagnitude;
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
class Speed : public DimensionalScalarQuantity<Unit::Speed> {
public:
  Speed() = default;

  Speed(const double value, const Unit::Speed unit)
    : DimensionalScalarQuantity<Unit::Speed>(value, unit) {}

  constexpr Speed(const Length& length, const Time& time)
    : Speed(length.Value() / time.Value()) {}

  constexpr Speed(const Length& length, const Frequency& frequency)
    : Speed(length.Value() * frequency.Value()) {}

  Speed(const Velocity& velocity);

  constexpr Speed(
      const AccelerationMagnitude& acceleration_magnitude, const Time& time);

  constexpr Speed(const AccelerationMagnitude& acceleration_magnitude,
                  const Frequency& frequency);

  Speed(const DynamicPressure& dynamic_pressure,
        const MassDensity& mass_density);

  Speed(const DynamicKinematicPressure& dynamic_kinematic_pressure);

  constexpr Speed(const ReynoldsNumber& reynolds_number,
                  const DynamicViscosity& dynamic_viscosity,
                  const MassDensity& mass_density, const Length& length);

  constexpr Speed(
      const ReynoldsNumber& reynolds_number,
      const KinematicViscosity& kinematic_viscosity, const Length& length);

  constexpr Speed(const SoundSpeed& sound_speed, const MachNumber& mach_number);

  static constexpr Speed Zero() {
    return Speed{0.0};
  }

  template <Unit::Speed Unit>
  static constexpr Speed Create(const double value) {
    return Speed{
        StaticConvertCopy<Unit::Speed, Unit, Standard<Unit::Speed>>(value)};
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

  constexpr AccelerationMagnitude operator*(const Frequency& frequency) const;

  constexpr Velocity operator*(const Direction& direction) const;

  constexpr Power operator*(
      const TransportEnergyConsumption& transport_energy_consumption) const;

  constexpr Speed operator/(const double number) const {
    return Speed{value_ / number};
  }

  constexpr Length operator/(const Frequency& frequency) const {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const Length& length) const {
    return {*this, length};
  }

  constexpr AccelerationMagnitude operator/(const Time& time) const;

  constexpr Time operator/(
      const AccelerationMagnitude& acceleration_magnitude) const;

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
  explicit constexpr Speed(const double value)
    : DimensionalScalarQuantity<Unit::Speed>(value) {}

  friend SoundSpeed;
};

inline constexpr bool operator==(
    const Speed& left, const Speed& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Speed& left, const Speed& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Speed& left, const Speed& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Speed& left, const Speed& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Speed& left, const Speed& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Speed& left, const Speed& right) noexcept {
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

inline constexpr Time::Time(const Speed& speed, const Length& length)
  : Time(length.Value() / speed.Value()) {}

inline constexpr Frequency::Frequency(const Speed& speed, const Length& length)
  : Frequency(speed.Value() / length.Value()) {}

inline constexpr Speed Length::operator*(const Frequency& frequency) const {
  return {*this, frequency};
}

inline constexpr Time Length::operator/(const Speed& speed) const {
  return {speed, *this};
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
