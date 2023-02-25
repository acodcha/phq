// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

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

  constexpr Frequency(const Duration& duration) noexcept : Frequency(1.0 / duration.value()) {}

  constexpr Frequency(const AccelerationMagnitude& acceleration_magnitude, const Speed& speed) noexcept;

  constexpr Frequency(const AngularAccelerationMagnitude& angular_acceleration_magnitude, const AngularSpeed& angular_speed) noexcept;

  constexpr Frequency(const AngularSpeed& angular_speed, const Angle& angle) noexcept;

  constexpr Frequency(const MassRate& mass_rate, const Mass& mass) noexcept;

  constexpr Frequency(const MemoryRate& memory_rate, const Memory& memory) noexcept;

  constexpr Frequency(const Power& power, const Energy& energy) noexcept;

  constexpr Frequency(const SpecificPower& specific_power, const SpecificEnergy& specific_energy) noexcept;

  constexpr Frequency(const Speed& speed, const Length& length) noexcept;

  constexpr Frequency(const VolumeRate& volume_rate, const Volume& volume) noexcept;

  constexpr Duration period() const noexcept {
    return {*this};
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
    return value_ * duration.value();
  }

  constexpr Speed operator*(const Length& length) const noexcept;

  constexpr AngularSpeed operator*(const Angle& angle) const noexcept;

  constexpr Velocity operator*(const Displacement& displacement) const noexcept;

  constexpr MemoryRate operator*(const Memory& memory) const noexcept;

  constexpr AccelerationMagnitude operator*(const Speed& speed) const noexcept;

  constexpr AngularAccelerationMagnitude operator*(const AngularSpeed& angular_speed) const noexcept;

  constexpr MassRate operator*(const Mass& mass) const noexcept;

  constexpr VolumeRate operator*(const Volume& volume) const noexcept;

  constexpr Power operator*(const Energy& energy) const noexcept;

  constexpr SpecificPower operator*(const SpecificEnergy& specific_energy) const noexcept;

  constexpr StrainRate operator*(const Strain& strain) const noexcept;

protected:

  constexpr Frequency(double value) noexcept : DimensionalScalarQuantity<Unit::Frequency>(value) {}

};

template <> constexpr bool sort(const Frequency& frequency_1, const Frequency& frequency_2) noexcept {
  return sort(frequency_1.value(), frequency_2.value());
}

constexpr Duration::Duration(const Frequency& frequency) noexcept : Duration(1.0 / frequency.value()) {}

constexpr Frequency Duration::frequency() const noexcept {
  return {*this};
}

constexpr double Duration::operator*(const Frequency& frequency) const noexcept {
  return value_ * frequency.value();
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::Frequency> {
  size_t operator()(const PhQ::Frequency& frequency) const {
    return hash<double>()(frequency.value());
  }
};

} // namespace std
