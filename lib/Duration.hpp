// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Time.hpp"

namespace PhQ {

// Forward declarations.
class AccelerationMagnitude;
class Angle;
class AngularAccelerationMagnitude;
class AngularSpeed;
class Energy;
class Frequency;
class Length;
class Mass;
class MassRate;
class Memory;
class MemoryRate;
class Power;
class Speed;
class Strain;
class StrainRate;
class Time;
class Volume;
class VolumeRate;

class Duration : public DimensionalScalarQuantity<Unit::Time> {

public:

  constexpr Duration() noexcept : DimensionalScalarQuantity<Unit::Time>() {}

  constexpr Duration(double value, Unit::Time unit) noexcept : DimensionalScalarQuantity<Unit::Time>(value, unit) {}

  Frequency frequency() const;

  constexpr bool operator==(const Duration& duration) const noexcept {
    return value_ == duration.value_;
  }

  constexpr bool operator!=(const Duration& duration) const noexcept {
    return value_ != duration.value_;
  }

  constexpr bool operator<(const Duration& duration) const noexcept {
    return value_ < duration.value_;
  }

  constexpr bool operator<=(const Duration& duration) const noexcept {
    return value_ <= duration.value_;
  }

  constexpr bool operator>(const Duration& duration) const noexcept {
    return value_ > duration.value_;
  }

  constexpr bool operator>=(const Duration& duration) const noexcept {
    return value_ >= duration.value_;
  }

  Time operator+(const Time& time) const noexcept;

  Duration operator+(const Duration& duration) const noexcept {
    return {value_ + duration.value_};
  }

  constexpr void operator+=(const Duration& duration) noexcept {
    value_ += duration.value_;
  }

  Time operator-(const Time& time) const noexcept;

  Duration operator-(const Duration& duration) const noexcept {
    return {value_ - duration.value_};
  }

  constexpr void operator-=(const Duration& duration) noexcept {
    value_ -= duration.value_;
  }

  constexpr double operator*(const Frequency& frequency) const noexcept;

  constexpr Mass operator*(const MassRate& mass_rate) const noexcept;

  constexpr Volume operator*(const VolumeRate& volume_rate) const noexcept;

  constexpr Energy operator*(const Power& power) const noexcept;

  constexpr Strain operator*(const StrainRate& strain_rate) const noexcept;

protected:

  constexpr Duration(double value) noexcept : DimensionalScalarQuantity<Unit::Time>(value) {}

  friend class Acceleration;
  friend class AccelerationMagnitude;
  friend class Angle;
  friend class AngularAccelerationMagnitude;
  friend class AngularSpeed;
  friend class Displacement;
  friend class Energy;
  friend class Frequency;
  friend class Length;
  friend class Mass;
  friend class MassRate;
  friend class Memory;
  friend class MemoryRate;
  friend class Power;
  friend class Speed;
  friend class Strain;
  friend class StrainRate;
  friend class Time;
  friend class Velocity;
  friend class Volume;
  friend class VolumeRate;

};

template <> constexpr bool sort(const Duration& duration_1, const Duration& duration_2) noexcept {
  return duration_1.value() < duration_2.value();
}

} // namespace PhQ
