// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

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

  constexpr Speed(double value, Unit::Speed unit) noexcept : DimensionalScalarQuantity<Unit::Speed>(value, unit) {}

  constexpr Speed(const Length& length, const Duration& duration) noexcept : Speed(length.value() / duration.value()) {}

  constexpr Speed(const Length& length, const Frequency& frequency) noexcept : Speed(length.value() * frequency.value()) {}

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

  constexpr Speed operator+(const Speed& speed) const noexcept {
    return {value_ + speed.value_};
  }

  constexpr void operator+=(const Speed& speed) noexcept {
    value_ += speed.value_;
  }

  constexpr Speed operator-(const Speed& speed) const noexcept {
    return {value_ - speed.value_};
  }

  constexpr void operator-=(const Speed& speed) noexcept {
    value_ -= speed.value_;
  }

  constexpr Length operator*(const Duration& duration) const noexcept {
    return {*this, duration};
  }

  constexpr AccelerationMagnitude operator*(const Frequency& frequency) const noexcept;

  constexpr Velocity operator*(const Direction& direction) const noexcept;

  constexpr Length operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const Length& length) const noexcept {
    return {*this, length};
  }

  constexpr AccelerationMagnitude operator/(const Duration& duration) const noexcept;

  constexpr Duration operator/(const AccelerationMagnitude& acceleration_magnitude) const noexcept;

protected:

  constexpr Speed(double value) noexcept : DimensionalScalarQuantity<Unit::Speed>(value) {}

};

template <> constexpr bool sort(const Speed& speed_1, const Speed& speed_2) noexcept {
  return sort(speed_1.value(), speed_2.value());
}

constexpr Length::Length(const Speed& speed, const Duration& duration) noexcept : Length(speed.value() * duration.value()) {}

constexpr Length::Length(const Speed& speed, const Frequency& frequency) noexcept : Length(speed.value() / frequency.value()) {}

constexpr Duration::Duration(const Speed& speed, const Length& length) noexcept : Duration(length.value() / speed.value()) {}

constexpr Frequency::Frequency(const Speed& speed, const Length& length) noexcept : Frequency(speed.value() / length.value()) {}

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
