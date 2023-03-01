// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "AccelerationMagnitude.hpp"
#include "Velocity.hpp"

namespace PhQ {

class Acceleration : public DimensionalVectorQuantity<Unit::Acceleration> {

public:

  constexpr Acceleration() noexcept : DimensionalVectorQuantity<Unit::Acceleration>() {}

  Acceleration(const Value::Vector& value, Unit::Acceleration unit) noexcept : DimensionalVectorQuantity<Unit::Acceleration>(value, unit) {}

  constexpr Acceleration(const AccelerationMagnitude& acceleration_magnitude, const Direction& direction) noexcept : Acceleration(acceleration_magnitude.Value() * direction.Value()) {}

  constexpr Acceleration(const Velocity& velocity, const Duration& duration) noexcept : Acceleration(velocity.Value() / duration.Value()) {}

  constexpr Acceleration(const Velocity& velocity, const Frequency& frequency) noexcept : Acceleration(velocity.Value() * frequency.Value()) {}

  AccelerationMagnitude magnitude() const noexcept {
    return {*this};
  }

  Angle angle(const Acceleration& acceleration) const noexcept {
    return {*this, acceleration};
  }

  constexpr bool operator==(const Acceleration& acceleration) const noexcept {
    return value_ == acceleration.value_;
  }

  constexpr bool operator!=(const Acceleration& acceleration) const noexcept {
    return value_ != acceleration.value_;
  }

  Acceleration operator+(const Acceleration& acceleration) const noexcept {
    return {value_ + acceleration.value_};
  }

  constexpr void operator+=(const Acceleration& acceleration) noexcept {
    value_ += acceleration.value_;
  }

  Acceleration operator-(const Acceleration& acceleration) const noexcept {
    return {value_ - acceleration.value_};
  }

  constexpr void operator-=(const Acceleration& acceleration) noexcept {
    value_ -= acceleration.value_;
  }

  Velocity operator*(const Duration& duration) const noexcept {
    return {*this, duration};
  }

  Velocity operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

protected:

  constexpr Acceleration(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Acceleration>(value) {}

};

constexpr Direction::Direction(const Acceleration& acceleration) : Direction(acceleration.Value()) {}

constexpr Angle::Angle(const Acceleration& acceleration_1, const Acceleration& acceleration_2) noexcept : Angle(acceleration_1.Value(), acceleration_2.Value()) {}

constexpr AccelerationMagnitude::AccelerationMagnitude(const Acceleration& acceleration) noexcept : AccelerationMagnitude(acceleration.Value().Magnitude()) {}

constexpr Velocity::Velocity(const Acceleration& acceleration, const Duration& duration) noexcept : Velocity(acceleration.Value() * duration.Value()) {}

constexpr Velocity::Velocity(const Acceleration& acceleration, const Frequency& frequency) noexcept : Velocity(acceleration.Value() / frequency.Value()) {}

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

namespace std {

template <> struct hash<PhQ::Acceleration> {
  size_t operator()(const PhQ::Acceleration& acceleration) const {
    return hash<PhQ::Value::Vector>()(acceleration.Value());
  }
};

} // namespace std
