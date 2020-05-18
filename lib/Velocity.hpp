// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Position.hpp"
#include "Speed.hpp"

namespace PhQ {

// Forward declaration.
class Acceleration;

class Velocity : public DimensionalVectorQuantity<Unit::Speed> {

public:

  constexpr Velocity() noexcept : DimensionalVectorQuantity<Unit::Speed>() {}

  constexpr Velocity(const Value::Vector& value, Unit::Speed unit) noexcept : DimensionalVectorQuantity<Unit::Speed>(value, unit) {}

  constexpr Velocity(const Speed& speed, const Direction& direction) noexcept : Velocity({speed.value() * direction.x(), speed.value() * direction.y(), speed.value() * direction.z()}) {}

  constexpr Velocity(const Displacement& displacement, const Duration& duration) noexcept : Velocity(displacement.value() / duration.value()) {}

  constexpr Velocity(const Displacement& displacement, const Frequency& frequency) noexcept : Velocity(displacement.value() * frequency.value()) {}

  constexpr Velocity(const Acceleration& acceleration, const Duration& duration) noexcept;

  constexpr Velocity(const Acceleration& acceleration, const Frequency& frequency) noexcept;

  constexpr Speed magnitude() const noexcept {
    return {*this};
  }

  constexpr Angle angle(const Velocity& velocity) const noexcept {
    return {*this, velocity};
  }

  constexpr bool operator==(const Velocity& velocity) const noexcept {
    return value_ == velocity.value_;
  }

  constexpr bool operator!=(const Velocity& velocity) const noexcept {
    return value_ != velocity.value_;
  }

  constexpr Velocity operator+(const Velocity& velocity) const noexcept {
    return {value_ + velocity.value_};
  }

  constexpr void operator+=(const Velocity& velocity) noexcept {
    value_ += velocity.value_;
  }

  constexpr Velocity operator-(const Velocity& velocity) const noexcept {
    return {value_ - velocity.value_};
  }

  constexpr void operator-=(const Velocity& velocity) noexcept {
    value_ -= velocity.value_;
  }

  constexpr Displacement operator*(const Duration& duration) const noexcept {
    return {*this, duration};
  }

  constexpr Acceleration operator*(const Frequency& frequency) const noexcept;

  constexpr Acceleration operator/(const Duration& duration) const noexcept;

  constexpr Displacement operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

protected:

  constexpr Velocity(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Speed>(value) {}

};

template <> constexpr bool sort(const Velocity& velocity_1, const Velocity& velocity_2) noexcept {
  return sort(velocity_1.value(), velocity_2.value());
}

constexpr Direction::Direction(const Velocity& velocity) : Direction(velocity.value()) {}

constexpr Angle::Angle(const Velocity& velocity_1, const Velocity& velocity_2) noexcept : Angle(velocity_1.value(), velocity_2.value()) {}

constexpr Displacement::Displacement(const Velocity& velocity, const Duration& duration) noexcept : Displacement(velocity.value() * duration.value()) {}

constexpr Displacement::Displacement(const Velocity& velocity, const Frequency& frequency) noexcept : Displacement(velocity.value() / frequency.value()) {}

constexpr Speed::Speed(const Velocity& velocity) noexcept : Speed(velocity.value().magnitude()) {}

constexpr Velocity Direction::operator*(const Speed& speed) const noexcept {
  return {speed, *this};
}

constexpr Velocity Speed::operator*(const Direction& direction) const noexcept {
  return {*this, direction};
}

constexpr Velocity Frequency::operator*(const Displacement& displacement) const noexcept {
  return {displacement, *this};
}

constexpr Velocity Displacement::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

constexpr Velocity Displacement::operator/(const Duration& duration) const noexcept {
  return {*this, duration};
}

} // namespace PhQ
