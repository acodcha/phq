// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Time.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

// Forward declarations.
class Acceleration;
class Displacement;
class Length;
class Velocity;

class Frequency : public DimensionalScalarQuantity<Unit::Frequency> {

public:

  constexpr Frequency() noexcept : DimensionalScalarQuantity<Unit::Frequency>() {}

  constexpr Frequency(double value, Unit::Frequency unit) noexcept : DimensionalScalarQuantity<Unit::Frequency>(value, unit) {}

  Duration period() const {
    if (value_ != 0.0) {
      return {1.0 / value_};
    } else {
      throw std::runtime_error{"Inversion of " + print() + "."};
    }
  }

  constexpr bool operator==(const Frequency& frequency) const noexcept {
    return value_ == frequency.value_;
  }

  constexpr bool operator!=(const Frequency& frequency) const noexcept {
    return value_ != frequency.value_;
  }

  constexpr bool operator<(const Frequency& frequency) const noexcept {
    return value_ < frequency.value_;
  }

  constexpr bool operator<=(const Frequency& frequency) const noexcept {
    return value_ <= frequency.value_;
  }

  constexpr bool operator>(const Frequency& frequency) const noexcept {
    return value_ > frequency.value_;
  }

  constexpr bool operator>=(const Frequency& frequency) const noexcept {
    return value_ >= frequency.value_;
  }

  constexpr Frequency operator+(const Frequency& frequency) const noexcept {
    return {value_ + frequency.value_};
  }

  constexpr void operator+=(const Frequency& frequency) noexcept {
    value_ += frequency.value_;
  }

  constexpr Frequency operator-(const Frequency& frequency) const noexcept {
    return {value_ - frequency.value_};
  }

  constexpr void operator-=(const Frequency& frequency) noexcept {
    value_ -= frequency.value_;
  }

  constexpr double operator*(const Duration& duration) const noexcept {
    return value_ * duration.value_;
  }

  constexpr Speed operator*(const Length& length) const noexcept;

  constexpr AngularSpeed operator*(const Angle& angle) const noexcept;

  constexpr Velocity operator*(const Displacement& displacement) const noexcept;

  constexpr MemoryRate operator*(const Memory& memory) const noexcept;

  constexpr AccelerationMagnitude operator*(const Speed& speed) const noexcept;

  constexpr AngularAccelerationMagnitude operator*(const AngularSpeed& angular_speed) const noexcept;

  constexpr MassRate operator*(const Mass& mass) const noexcept;

  constexpr VolumeRate operator*(const Volume& volume) const noexcept;

  constexpr StrainRate operator*(const Strain& strain) const noexcept;

protected:

  constexpr Frequency(double value) noexcept : DimensionalScalarQuantity<Unit::Frequency>(value) {}

  friend class Acceleration;
  friend class AccelerationMagnitude;
  friend class Angle;
  friend class AngularAccelerationMagnitude;
  friend class AngularSpeed;
  friend class Displacement;
  friend class Duration;
  friend class Length;
  friend class Mass;
  friend class MassRate;
  friend class Memory;
  friend class MemoryRate;
  friend class Speed;
  friend class Strain;
  friend class StrainRate;
  friend class Velocity;
  friend class Volume;
  friend class VolumeRate;

};

template <> constexpr bool sort(const Frequency& frequency_1, const Frequency& frequency_2) noexcept {
  return frequency_1.value() < frequency_2.value();
}

Frequency Duration::frequency() const {
  if (value_ != 0.0) {
    return {1.0 / value_};
  } else {
    throw std::runtime_error{"Inversion of " + print() + "."};
  }
}

constexpr double Duration::operator*(const Frequency& frequency) const noexcept {
  return value_ * frequency.value_;
}

} // namespace PhQ
