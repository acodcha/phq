// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Displacement.hpp"
#include "Speed.hpp"

namespace PhQ {

// Forward declaration.
class Acceleration;

class Velocity : public DimensionalVectorQuantity<Unit::Speed> {

public:

  constexpr Velocity() noexcept : DimensionalVectorQuantity<Unit::Speed>() {}

  constexpr Velocity(const DimensionalVectorQuantity<Unit::Speed>& quantity) noexcept : DimensionalVectorQuantity<Unit::Speed>(quantity) {}

  constexpr Velocity(const Value::Vector& value, Unit::Speed unit) noexcept : DimensionalVectorQuantity<Unit::Speed>(value, unit) {}

  constexpr Speed magnitude() const noexcept {
    return {value_.magnitude()};
  }

  constexpr Angle angle(const Velocity& velocity) const noexcept {
    return value_.angle(velocity.value_);
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
    return {value_ * duration.value_};
  }

  constexpr Acceleration operator*(const Frequency& frequency) const noexcept;

  Acceleration operator/(const Duration& duration) const;

  Displacement operator/(const Frequency& frequency) const {
    if (frequency.value_ != 0.0) {
      return {value_ / frequency.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + frequency.print() + "."};
    }
  }

protected:

  constexpr Velocity(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::Speed>(value) {}

  friend class Acceleration;
  friend class Direction;
  friend class Displacement;
  friend class Duration;
  friend class Frequency;
  friend class Speed;

};

template <> constexpr bool sort(const Velocity& velocity_1, const Velocity& velocity_2) noexcept {
  return sort(velocity_1.value(), velocity_2.value());
}

constexpr Velocity Direction::operator*(const Speed& speed) const noexcept {
  return {{x_y_z_[0] * speed.value_, x_y_z_[1] * speed.value_, x_y_z_[2] * speed.value_}};
}

constexpr Angle::Angle(const Velocity& velocity_1, const Velocity& velocity_2) noexcept : DimensionalScalarQuantity<Unit::Angle>(velocity_1.angle(velocity_2)) {}

constexpr Speed::Speed(const Velocity& velocity) noexcept : Speed(velocity.magnitude()) {}

constexpr Velocity Frequency::operator*(const Displacement& displacement) const noexcept {
  return {displacement.value_ * value_};
}

constexpr Velocity Displacement::operator*(const Frequency& frequency) const noexcept {
  return {value_ * frequency.value_};
}

Velocity Displacement::operator/(const Duration& duration) const {
  if (duration.value_ != 0.0) {
    return {value_ / duration.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + duration.print() + "."};
  }
}

} // namespace PhQ

constexpr PhQ::Velocity operator*(const PhQ::Speed& speed, const PhQ::Direction& direction) noexcept {
  return {direction * speed};
}
