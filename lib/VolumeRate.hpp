// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Frequency.hpp"
#include "Volume.hpp"
#include "Unit/VolumeRate.hpp"

namespace PhQ {

class VolumeRate : public DimensionalScalarQuantity<Unit::VolumeRate> {

public:

  constexpr VolumeRate() noexcept : DimensionalScalarQuantity<Unit::VolumeRate>() {}

  constexpr VolumeRate(double value, Unit::VolumeRate unit) noexcept : DimensionalScalarQuantity<Unit::VolumeRate>(value, unit) {}

  constexpr bool operator==(const VolumeRate& volume_rate) const noexcept {
    return value_ == volume_rate.value_;
  }

  constexpr bool operator!=(const VolumeRate& volume_rate) const noexcept {
    return value_ != volume_rate.value_;
  }

  constexpr bool operator<(const VolumeRate& volume_rate) const noexcept {
    return value_ < volume_rate.value_;
  }

  constexpr bool operator<=(const VolumeRate& volume_rate) const noexcept {
    return value_ <= volume_rate.value_;
  }

  constexpr bool operator>(const VolumeRate& volume_rate) const noexcept {
    return value_ > volume_rate.value_;
  }

  constexpr bool operator>=(const VolumeRate& volume_rate) const noexcept {
    return value_ >= volume_rate.value_;
  }

  constexpr VolumeRate operator+(const VolumeRate& volume_rate) const noexcept {
    return {value_ + volume_rate.value_};
  }

  constexpr void operator+=(const VolumeRate& volume_rate) noexcept {
    value_ += volume_rate.value_;
  }

  constexpr VolumeRate operator-(const VolumeRate& volume_rate) const noexcept {
    return {value_ - volume_rate.value_};
  }

  constexpr void operator-=(const VolumeRate& volume_rate) noexcept {
    value_ -= volume_rate.value_;
  }

  constexpr Volume operator*(const Duration& duration) const noexcept {
    return {value_ * duration.value_};
  }

  Volume operator/(const Frequency& frequency) const {
    if (frequency.value_ != 0.0) {
      return {value_ / frequency.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + frequency.print() + "."};
    }
  }

  Frequency operator/(const Volume& volume) const {
    if (volume.value_ != 0.0) {
      return {value_ / volume.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + volume.print() + "."};
    }
  }

protected:

  constexpr VolumeRate(double value) noexcept : DimensionalScalarQuantity<Unit::VolumeRate>(value) {}

  friend class Duration;
  friend class Frequency;
  friend class Volume;

};

constexpr Volume Duration::operator*(const VolumeRate& volume_rate) const noexcept {
  return {value_ * volume_rate.value_};
}

constexpr VolumeRate Volume::operator*(const Frequency& frequency) const noexcept {
  return {value_ * frequency.value_};
}

constexpr VolumeRate Frequency::operator*(const Volume& volume) const noexcept {
  return {value_ * volume.value_};
}

VolumeRate Volume::operator/(const Duration& duration) const {
  if (duration.value_ != 0.0) {
    return {value_ / duration.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + duration.print() + "."};
  }
}

} // namespace PhQ
