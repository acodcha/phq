// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "AngularSpeed.hpp"
#include "Unit/AngularAcceleration.hpp"

namespace PhQ {

class AngularAccelerationMagnitude : public DimensionalScalarQuantity<Unit::AngularAcceleration> {

public:

  constexpr AngularAccelerationMagnitude() noexcept : DimensionalScalarQuantity<Unit::AngularAcceleration>() {}

  constexpr AngularAccelerationMagnitude(double value, Unit::AngularAcceleration unit) noexcept : DimensionalScalarQuantity<Unit::AngularAcceleration>(value, unit) {}

  constexpr AngularAccelerationMagnitude(const AngularSpeed& angular_speed, const Duration& duration) noexcept : AngularAccelerationMagnitude(angular_speed.value() / duration.value()) {}

  constexpr AngularAccelerationMagnitude(const AngularSpeed& angular_speed, const Frequency& frequency) noexcept : AngularAccelerationMagnitude(angular_speed.value() * frequency.value()) {}

  constexpr bool operator==(const AngularAccelerationMagnitude& angular_acceleration_magnitude) const noexcept {
    return value_ == angular_acceleration_magnitude.value_;
  }

  constexpr bool operator!=(const AngularAccelerationMagnitude& angular_acceleration_magnitude) const noexcept {
    return value_ != angular_acceleration_magnitude.value_;
  }

  constexpr bool operator<(const AngularAccelerationMagnitude& angular_acceleration_magnitude) const noexcept {
    return value_ < angular_acceleration_magnitude.value_;
  }

  constexpr bool operator<=(const AngularAccelerationMagnitude& angular_acceleration_magnitude) const noexcept {
    return value_ <= angular_acceleration_magnitude.value_;
  }

  constexpr bool operator>(const AngularAccelerationMagnitude& angular_acceleration_magnitude) const noexcept {
    return value_ > angular_acceleration_magnitude.value_;
  }

  constexpr bool operator>=(const AngularAccelerationMagnitude& angular_acceleration_magnitude) const noexcept {
    return value_ >= angular_acceleration_magnitude.value_;
  }

  constexpr AngularAccelerationMagnitude operator+(const AngularAccelerationMagnitude& angular_acceleration_magnitude) const noexcept {
    return {value_ + angular_acceleration_magnitude.value_};
  }

  constexpr void operator+=(const AngularAccelerationMagnitude& angular_acceleration_magnitude) noexcept {
    value_ += angular_acceleration_magnitude.value_;
  }

  constexpr AngularAccelerationMagnitude operator-(const AngularAccelerationMagnitude& angular_acceleration_magnitude) const noexcept {
    return {value_ - angular_acceleration_magnitude.value_};
  }

  constexpr void operator-=(const AngularAccelerationMagnitude& angular_acceleration_magnitude) noexcept {
    value_ -= angular_acceleration_magnitude.value_;
  }

  constexpr AngularSpeed operator*(const Duration& duration) const noexcept {
    return {*this, duration};
  }

  constexpr AngularSpeed operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const AngularSpeed& angular_speed) const noexcept {
    return {*this, angular_speed};
  }

protected:

  constexpr AngularAccelerationMagnitude(double value) noexcept : DimensionalScalarQuantity<Unit::AngularAcceleration>(value) {}

  friend class AngularSpeed;
  friend class Duration;
  friend class Frequency;

};

template <> constexpr bool sort(const AngularAccelerationMagnitude& angular_acceleration_magnitude_1, const AngularAccelerationMagnitude& angular_acceleration_magnitude_2) noexcept {
  return sort(angular_acceleration_magnitude_1.value(), angular_acceleration_magnitude_2.value());
}

constexpr Duration::Duration(const AngularAccelerationMagnitude& angular_acceleration_magnitude, const AngularSpeed& angular_speed) noexcept : Duration(angular_speed.value() / angular_acceleration_magnitude.value()) {}

constexpr Frequency::Frequency(const AngularAccelerationMagnitude& angular_acceleration_magnitude, const AngularSpeed& angular_speed) noexcept : Frequency(angular_acceleration_magnitude.value() / angular_speed.value()) {}

constexpr AngularSpeed::AngularSpeed(const AngularAccelerationMagnitude& angular_acceleration_magnitude, const Duration& duration) noexcept : AngularSpeed(angular_acceleration_magnitude.value() * duration.value()) {}

constexpr AngularSpeed::AngularSpeed(const AngularAccelerationMagnitude& angular_acceleration_magnitude, const Frequency& frequency) noexcept : AngularSpeed(angular_acceleration_magnitude.value() / frequency.value()) {}

constexpr AngularAccelerationMagnitude Frequency::operator*(const AngularSpeed& angular_speed) const noexcept {
  return {angular_speed, *this};
}

constexpr AngularAccelerationMagnitude AngularSpeed::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

constexpr AngularAccelerationMagnitude AngularSpeed::operator/(const Duration& duration) const noexcept {
  return {*this, duration};
}

constexpr Duration AngularSpeed::operator/(const AngularAccelerationMagnitude& angular_acceleration_magnitude) const noexcept {
  return {angular_acceleration_magnitude, *this};
}

} // namespace PhQ
