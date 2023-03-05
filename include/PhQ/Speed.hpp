// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Frequency.hpp"
#include "Length.hpp"
#include "Unit/Speed.hpp"

namespace PhQ {

// Forward declarations.
class AccelerationMagnitude;
class Direction;
class DynamicKinematicPressure;
class DynamicPressure;
class DynamicViscosity;
class KinematicViscosity;
class MassDensity;
class ReynoldsNumber;
class Velocity;

class Speed : public DimensionalScalarQuantity<Unit::Speed> {

public:

  constexpr Speed() noexcept : DimensionalScalarQuantity<Unit::Speed>() {}

  Speed(double value, Unit::Speed unit) noexcept : DimensionalScalarQuantity<Unit::Speed>(value, unit) {}

  constexpr Speed(const Length& length, const Time& time) noexcept : Speed(length.Value() / time.Value()) {}

  constexpr Speed(const Length& length, const Frequency& frequency) noexcept : Speed(length.Value() * frequency.Value()) {}

  Speed(const Velocity& velocity) noexcept;

  constexpr Speed(const AccelerationMagnitude& acceleration_magnitude, const Time& time) noexcept;

  constexpr Speed(const AccelerationMagnitude& acceleration_magnitude, const Frequency& frequency) noexcept;

  constexpr Speed(const DynamicPressure& dynamic_pressure, const MassDensity& mass_density) noexcept;

  Speed(const DynamicKinematicPressure& dynamic_kinematic_pressure) noexcept;

  constexpr Speed(const ReynoldsNumber& reynolds_number, const DynamicViscosity& dynamic_viscosity, const MassDensity& mass_density, const Length& length) noexcept;

  constexpr Speed(const ReynoldsNumber& reynolds_number, const KinematicViscosity& kinematic_viscosity, const Length& length) noexcept;

  constexpr bool operator==(const Speed& speed) const noexcept {
    return value_ == speed.value_;
  }

  constexpr bool operator!=(const Speed& speed) const noexcept {
    return value_ != speed.value_;
  }

  constexpr bool operator<(const Speed& speed) const noexcept {
    return value_ < speed.value_;
  }

  constexpr bool operator<=(const Speed& speed) const noexcept {
    return value_ <= speed.value_;
  }

  constexpr bool operator>(const Speed& speed) const noexcept {
    return value_ > speed.value_;
  }

  constexpr bool operator>=(const Speed& speed) const noexcept {
    return value_ >= speed.value_;
  }

  Speed operator+(const Speed& speed) const noexcept {
    return {value_ + speed.value_};
  }

  constexpr void operator+=(const Speed& speed) noexcept {
    value_ += speed.value_;
  }

  Speed operator-(const Speed& speed) const noexcept {
    return {value_ - speed.value_};
  }

  constexpr void operator-=(const Speed& speed) noexcept {
    value_ -= speed.value_;
  }

  Length operator*(const Time& time) const noexcept {
    return {*this, time};
  }

  AccelerationMagnitude operator*(const Frequency& frequency) const noexcept;

  Velocity operator*(const Direction& direction) const noexcept;

  Length operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  Frequency operator/(const Length& length) const noexcept {
    return {*this, length};
  }

  AccelerationMagnitude operator/(const Time& time) const noexcept;

  Time operator/(const AccelerationMagnitude& acceleration_magnitude) const noexcept;

protected:

  constexpr Speed(double value) noexcept : DimensionalScalarQuantity<Unit::Speed>(value) {}

};

constexpr Length::Length(const Speed& speed, const Time& time) noexcept : Length(speed.Value() * time.Value()) {}

constexpr Length::Length(const Speed& speed, const Frequency& frequency) noexcept : Length(speed.Value() / frequency.Value()) {}

constexpr Time::Time(const Speed& speed, const Length& length) noexcept : Time(length.Value() / speed.Value()) {}

constexpr Frequency::Frequency(const Speed& speed, const Length& length) noexcept : Frequency(speed.Value() / length.Value()) {}

Speed Length::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

Time Length::operator/(const Speed& speed) const noexcept {
  return {speed, *this};
}

Speed Frequency::operator*(const Length& length) const noexcept {
  return {length, *this};
}

Speed Length::operator/(const Time& time) const noexcept {
  return {*this, time};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::Speed> {
  size_t operator()(const PhQ::Speed& speed) const {
    return hash<double>()(speed.Value());
  }
};

} // namespace std
