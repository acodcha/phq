// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Position.hpp"
#include "Speed.hpp"

namespace PhQ {

// Forward declaration.
class Acceleration;

class Velocity : public DimensionalVectorQuantity<Unit::Speed> {

public:

  constexpr Velocity() noexcept : DimensionalVectorQuantity<Unit::Speed>() {}

  Velocity(const Value::Vector& value, Unit::Speed unit) noexcept : DimensionalVectorQuantity<Unit::Speed>(value, unit) {}

  constexpr Velocity(const Speed& speed, const Direction& direction) noexcept : Velocity(speed.Value() * direction.Value()) {}

  constexpr Velocity(const Displacement& displacement, const Time& time) noexcept : Velocity(displacement.Value() / time.Value()) {}

  constexpr Velocity(const Displacement& displacement, const Frequency& frequency) noexcept : Velocity(displacement.Value() * frequency.Value()) {}

  constexpr Velocity(const Acceleration& acceleration, const Time& time) noexcept;

  constexpr Velocity(const Acceleration& acceleration, const Frequency& frequency) noexcept;

  Speed Magnitude() const noexcept {
    return {*this};
  }

  PhQ::Angle Angle(const Velocity& velocity) const noexcept {
    return {*this, velocity};
  }

  constexpr bool operator==(const Velocity& velocity) const noexcept {
    return value_ == velocity.value_;
  }

  constexpr bool operator!=(const Velocity& velocity) const noexcept {
    return value_ != velocity.value_;
  }

  Velocity operator+(const Velocity& velocity) const noexcept {
    return {value_ + velocity.value_};
  }

  constexpr void operator+=(const Velocity& velocity) noexcept {
    value_ += velocity.value_;
  }

  Velocity operator-(const Velocity& velocity) const noexcept {
    return {value_ - velocity.value_};
  }

  constexpr void operator-=(const Velocity& velocity) noexcept {
    value_ -= velocity.value_;
  }

  Displacement operator*(const Time& time) const noexcept {
    return {*this, time};
  }

  Acceleration operator*(const Frequency& frequency) const noexcept;

  Acceleration operator/(const Time& time) const noexcept;

  Displacement operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

private:

  constexpr Velocity(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Speed>(value) {}

};

Direction::Direction(const Velocity& velocity) noexcept : Direction(velocity.Value()) {}

Angle::Angle(const Velocity& velocity_1, const Velocity& velocity_2) noexcept : Angle(velocity_1.Value(), velocity_2.Value()) {}

constexpr Displacement::Displacement(const Velocity& velocity, const Time& time) noexcept : Displacement(velocity.Value() * time.Value()) {}

constexpr Displacement::Displacement(const Velocity& velocity, const Frequency& frequency) noexcept : Displacement(velocity.Value() / frequency.Value()) {}

Speed::Speed(const Velocity& velocity) noexcept : Speed(velocity.Value().Magnitude()) {}

Velocity Direction::operator*(const Speed& speed) const noexcept {
  return {speed, *this};
}

Velocity Speed::operator*(const Direction& direction) const noexcept {
  return {*this, direction};
}

Velocity Frequency::operator*(const Displacement& displacement) const noexcept {
  return {displacement, *this};
}

Velocity Displacement::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

Velocity Displacement::operator/(const Time& time) const noexcept {
  return {*this, time};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::Velocity> {
  size_t operator()(const PhQ::Velocity& velocity) const {
    return hash<PhQ::Value::Vector>()(velocity.Value());
  }
};

} // namespace std
