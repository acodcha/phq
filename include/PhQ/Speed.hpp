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

  constexpr Speed(const Length& length, const Duration& duration) noexcept : Speed(length.Value() / duration.Value()) {}

  constexpr Speed(const Length& length, const Frequency& frequency) noexcept : Speed(length.Value() * frequency.Value()) {}

  constexpr Speed(const Velocity& velocity) noexcept;

  constexpr Speed(const AccelerationMagnitude& acceleration_magnitude, const Duration& duration) noexcept;

  constexpr Speed(const AccelerationMagnitude& acceleration_magnitude, const Frequency& frequency) noexcept;

  constexpr Speed(const DynamicPressure& dynamic_pressure, const MassDensity& mass_density) noexcept;

  constexpr Speed(const DynamicKinematicPressure& dynamic_kinematic_pressure) noexcept;

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

  Length operator*(const Duration& duration) const noexcept {
    return {*this, duration};
  }

  constexpr AccelerationMagnitude operator*(const Frequency& frequency) const noexcept;

  constexpr Velocity operator*(const Direction& direction) const noexcept;

  Length operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  Frequency operator/(const Length& length) const noexcept {
    return {*this, length};
  }

  constexpr AccelerationMagnitude operator/(const Duration& duration) const noexcept;

  constexpr Duration operator/(const AccelerationMagnitude& acceleration_magnitude) const noexcept;

protected:

  constexpr Speed(double value) noexcept : DimensionalScalarQuantity<Unit::Speed>(value) {}

};

constexpr Length::Length(const Speed& speed, const Duration& duration) noexcept : Length(speed.Value() * duration.Value()) {}

constexpr Length::Length(const Speed& speed, const Frequency& frequency) noexcept : Length(speed.Value() / frequency.Value()) {}

constexpr Duration::Duration(const Speed& speed, const Length& length) noexcept : Duration(length.Value() / speed.Value()) {}

constexpr Frequency::Frequency(const Speed& speed, const Length& length) noexcept : Frequency(speed.Value() / length.Value()) {}

constexpr Speed Length::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

constexpr Duration Length::operator/(const Speed& speed) const noexcept {
  return {speed, *this};
}

constexpr Speed Frequency::operator*(const Length& length) const noexcept {
  return {length, *this};
}

constexpr Speed Length::operator/(const Duration& duration) const noexcept {
  return {*this, duration};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::Speed> {
  size_t operator()(const PhQ::Speed& speed) const {
    return hash<double>()(speed.Value());
  }
};

} // namespace std
