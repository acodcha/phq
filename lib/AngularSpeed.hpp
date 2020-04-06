// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Angle.hpp"
#include "Frequency.hpp"
#include "Unit/AngularSpeed.hpp"

namespace PhQ {

// Forward declaration.
class AngularAccelerationMagnitude;

class AngularSpeed : public DimensionalScalarQuantity<Unit::AngularSpeed> {

public:

  constexpr AngularSpeed() noexcept : DimensionalScalarQuantity<Unit::AngularSpeed>() {}

  constexpr AngularSpeed(double value, Unit::AngularSpeed unit) noexcept : DimensionalScalarQuantity<Unit::AngularSpeed>(value, unit) {}

  constexpr bool operator==(const AngularSpeed& angular_speed) const noexcept {
    return value_ == angular_speed.value_;
  }

  constexpr bool operator!=(const AngularSpeed& angular_speed) const noexcept {
    return value_ != angular_speed.value_;
  }

  constexpr bool operator<(const AngularSpeed& angular_speed) const noexcept {
    return value_ < angular_speed.value_;
  }

  constexpr bool operator<=(const AngularSpeed& angular_speed) const noexcept {
    return value_ <= angular_speed.value_;
  }

  constexpr bool operator>(const AngularSpeed& angular_speed) const noexcept {
    return value_ > angular_speed.value_;
  }

  constexpr bool operator>=(const AngularSpeed& angular_speed) const noexcept {
    return value_ >= angular_speed.value_;
  }

  constexpr AngularSpeed operator+(const AngularSpeed& angular_speed) const noexcept {
    return {value_ + angular_speed.value_};
  }

  constexpr void operator+=(const AngularSpeed& angular_speed) noexcept {
    value_ += angular_speed.value_;
  }

  constexpr AngularSpeed operator-(const AngularSpeed& angular_speed) const noexcept {
    return {value_ - angular_speed.value_};
  }

  constexpr void operator-=(const AngularSpeed& angular_speed) noexcept {
    value_ -= angular_speed.value_;
  }

  constexpr Angle operator*(const Duration& duration) const noexcept {
    return {value_ * duration.value_};
  }

  constexpr AngularAccelerationMagnitude operator*(const Frequency& frequency) const noexcept;

  AngularAccelerationMagnitude operator/(const Duration& duration) const;

  Angle operator/(const Frequency& frequency) const {
    if (frequency.value_ != 0.0) {
      return {value_ / frequency.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + frequency.print() + "."};
    }
  }

  Frequency operator/(const Angle& angle) const {
    if (angle.value_ != 0.0) {
      return {value_ / angle.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + angle.print() + "."};
    }
  }

protected:

  constexpr AngularSpeed(double value) noexcept : DimensionalScalarQuantity<Unit::AngularSpeed>(value) {}

  friend class Angle;
  friend class AngularAccelerationMagnitude;
  friend class Duration;
  friend class Frequency;

};

constexpr AngularSpeed Angle::operator*(const Frequency& frequency) const noexcept {
  return {value_ * frequency.value_};
}

constexpr AngularSpeed Frequency::operator*(const Angle& angle) const noexcept {
  return {value_ * angle.value_};
}

AngularSpeed Angle::operator/(const Duration& time) const {

}

} // namespace PhQ
