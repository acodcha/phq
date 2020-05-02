// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Speed.hpp"
#include "Unit/Acceleration.hpp"

namespace PhQ {

// Forward declarations.
class Acceleration;
class Direction;

class AccelerationMagnitude : public DimensionalScalarQuantity<Unit::Acceleration> {

public:

  constexpr AccelerationMagnitude() noexcept : DimensionalScalarQuantity<Unit::Acceleration>() {}

  constexpr AccelerationMagnitude(double value, Unit::Acceleration unit) noexcept : DimensionalScalarQuantity<Unit::Acceleration>(value, unit) {}

  constexpr AccelerationMagnitude(const Acceleration& acceleration) noexcept;

  constexpr bool operator==(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return value_ == acceleration_magnitude.value_;
  }

  constexpr bool operator!=(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return value_ != acceleration_magnitude.value_;
  }

  constexpr bool operator<(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return value_ < acceleration_magnitude.value_;
  }

  constexpr bool operator<=(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return value_ <= acceleration_magnitude.value_;
  }

  constexpr bool operator>(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return value_ > acceleration_magnitude.value_;
  }

  constexpr bool operator>=(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return value_ >= acceleration_magnitude.value_;
  }

  constexpr AccelerationMagnitude operator+(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return {value_ + acceleration_magnitude.value_};
  }

  constexpr void operator+=(const AccelerationMagnitude& acceleration_magnitude) noexcept {
    value_ += acceleration_magnitude.value_;
  }

  constexpr AccelerationMagnitude operator-(const AccelerationMagnitude& acceleration_magnitude) const noexcept {
    return {value_ - acceleration_magnitude.value_};
  }

  constexpr void operator-=(const AccelerationMagnitude& acceleration_magnitude) noexcept {
    value_ -= acceleration_magnitude.value_;
  }

  constexpr Speed operator*(const Duration& duration) const noexcept {
    return {value_ * duration.value_};
  }

  constexpr Acceleration operator*(const Direction& direction) const noexcept;

  Speed operator/(const Frequency& frequency) const {
    if (frequency.value_ != 0.0) {
      return {value_ / frequency.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + frequency.print() + "."};
    }
  }

  Frequency operator/(const Speed& speed) const {
    if (speed.value_ != 0.0) {
      return {value_ / speed.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + speed.print() + "."};
    }
  }

protected:

  constexpr AccelerationMagnitude(double value) noexcept : DimensionalScalarQuantity<Unit::Acceleration>(value) {}

  friend class Acceleration;
  friend class Direction;
  friend class Duration;
  friend class Frequency;
  friend class Speed;

};

template <> constexpr bool sort(const AccelerationMagnitude& acceleration_magnitude_1, const AccelerationMagnitude& acceleration_magnitude_2) noexcept {
  return acceleration_magnitude_1.value() < acceleration_magnitude_2.value();
}

constexpr AccelerationMagnitude Frequency::operator*(const Speed& speed) const noexcept {
  return {value_ * speed.value_};
}

constexpr AccelerationMagnitude Speed::operator*(const Frequency& frequency) const noexcept {
  return {value_ * frequency.value_};
}

AccelerationMagnitude Speed::operator/(const Duration& duration) const {
  if (duration.value_ != 0.0) {
    return {value_ / duration.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + duration.print() + "."};
  }
}

} // namespace PhQ
