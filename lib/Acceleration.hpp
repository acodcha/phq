// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "AccelerationMagnitude.hpp"
#include "Velocity.hpp"

namespace PhQ {

class Acceleration : public DimensionalVectorQuantity<Unit::Acceleration> {

public:

  constexpr Acceleration() noexcept : DimensionalVectorQuantity<Unit::Acceleration>() {}

  constexpr Acceleration(const Value::Vector& value, Unit::Acceleration unit) noexcept : DimensionalVectorQuantity<Unit::Acceleration>(value, unit) {}

  constexpr AccelerationMagnitude magnitude() const noexcept {
    return {value_.magnitude()};
  }

  constexpr Angle angle(const Acceleration& acceleration) const noexcept {
    return value_.angle(acceleration.value_);
  }

  constexpr bool operator==(const Acceleration& acceleration) const noexcept {
    return value_ == acceleration.value_;
  }

  constexpr bool operator!=(const Acceleration& acceleration) const noexcept {
    return value_ != acceleration.value_;
  }

  constexpr Acceleration operator+(const Acceleration& acceleration) const noexcept {
    return {value_ + acceleration.value_};
  }

  constexpr void operator+=(const Acceleration& acceleration) noexcept {
    value_ += acceleration.value_;
  }

  constexpr Acceleration operator-(const Acceleration& acceleration) const noexcept {
    return {value_ - acceleration.value_};
  }

  constexpr void operator-=(const Acceleration& acceleration) noexcept {
    value_ -= acceleration.value_;
  }

  constexpr Velocity operator*(const Duration& duration) const noexcept {
    return {value_ * duration.value_};
  }

  Velocity operator/(const Frequency& frequency) const {
    if (frequency.value_ != 0.0) {
      return {value_ / frequency.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + frequency.print() + "."};
    }
  }

protected:

  constexpr Acceleration(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Acceleration>(value) {}

  friend class AccelerationMagnitude;
  friend class Direction;
  friend class Duration;
  friend class Frequency;
  friend class Velocity;

};

template <> constexpr bool sort(const Acceleration& acceleration_1, const Acceleration& acceleration_2) noexcept {
  return sort(acceleration_1.value(), acceleration_2.value());
}

constexpr Acceleration Direction::operator*(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
  return {{x_y_z_[0] * acceleration_magnitude.value_, x_y_z_[1] * acceleration_magnitude.value_, x_y_z_[2] * acceleration_magnitude.value_}};
}

constexpr Angle::Angle(const Acceleration& acceleration_1, const Acceleration& acceleration_2) noexcept : DimensionalScalarQuantity<Unit::Angle>(acceleration_1.angle(acceleration_2)) {}

constexpr AccelerationMagnitude::AccelerationMagnitude(const Acceleration& acceleration) noexcept : AccelerationMagnitude(acceleration.magnitude()) {}

constexpr Acceleration Velocity::operator*(const Frequency& frequency) const noexcept {
  return {value_ * frequency.value_};
}

Acceleration Velocity::operator/(const Duration& duration) const {
  if (duration.value_ != 0.0) {
    return {value_ / duration.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + duration.print() + "."};
  }
}

} // namespace PhQ

constexpr PhQ::Acceleration operator*(const PhQ::AccelerationMagnitude& acceleration_magnitude, const PhQ::Direction& direction) noexcept {
  return {direction * acceleration_magnitude};
}
