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

  constexpr Acceleration(const AccelerationMagnitude& acceleration_magnitude, const Direction& direction) noexcept : Acceleration({acceleration_magnitude.value() * direction.x(), acceleration_magnitude.value() * direction.y(), acceleration_magnitude.value() * direction.z()}) {}

  constexpr Acceleration(const Velocity& velocity, const Duration& duration) noexcept : Acceleration(velocity.value() / duration.value()) {}

  constexpr Acceleration(const Velocity& velocity, const Frequency& frequency) noexcept : Acceleration(velocity.value() * frequency.value()) {}

  constexpr AccelerationMagnitude magnitude() const noexcept {
    return {*this};
  }

  constexpr Angle angle(const Acceleration& acceleration) const noexcept {
    return {*this, acceleration};
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
    return {*this, duration};
  }

  constexpr Velocity operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

protected:

  constexpr Acceleration(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Acceleration>(value) {}

};

template <> constexpr bool sort(const Acceleration& acceleration_1, const Acceleration& acceleration_2) noexcept {
  return sort(acceleration_1.value(), acceleration_2.value());
}

constexpr Direction::Direction(const Acceleration& acceleration) : Direction(acceleration.value()) {}

constexpr Angle::Angle(const Acceleration& acceleration_1, const Acceleration& acceleration_2) noexcept : Angle(acceleration_1.value(), acceleration_2.value()) {}

constexpr AccelerationMagnitude::AccelerationMagnitude(const Acceleration& acceleration) noexcept : AccelerationMagnitude(acceleration.value().magnitude()) {}

constexpr Velocity::Velocity(const Acceleration& acceleration, const Duration& duration) noexcept : Velocity(acceleration.value() * duration.value()) {}

constexpr Velocity::Velocity(const Acceleration& acceleration, const Frequency& frequency) noexcept : Velocity(acceleration.value() / frequency.value()) {}

constexpr Acceleration Direction::operator*(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
  return {acceleration_magnitude, *this};
}

constexpr Acceleration AccelerationMagnitude::operator*(const Direction& direction) const noexcept {
  return {*this, direction};
}

constexpr Acceleration Velocity::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

constexpr Acceleration Velocity::operator/(const Duration& duration) const noexcept {
  return {*this, duration};
}

} // namespace PhQ
