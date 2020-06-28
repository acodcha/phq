// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Frequency.hpp"
#include "Volume.hpp"
#include "Unit/VolumeRate.hpp"

namespace PhQ {

class VolumeRate : public DimensionalScalarQuantity<Unit::VolumeRate> {

public:

  constexpr VolumeRate() noexcept : DimensionalScalarQuantity<Unit::VolumeRate>() {}

  constexpr VolumeRate(double value, Unit::VolumeRate unit) noexcept : DimensionalScalarQuantity<Unit::VolumeRate>(value, unit) {}

  constexpr VolumeRate(const Volume& volume, const Duration& duration) noexcept : VolumeRate(volume.value() / duration.value()) {}

  constexpr VolumeRate(const Volume& volume, const Frequency& frequency) noexcept : VolumeRate(volume.value() * frequency.value()) {}

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
    return {*this, duration};
  }

  constexpr Volume operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const Volume& volume) const noexcept {
    return {*this, volume};
  }

protected:

  constexpr VolumeRate(double value) noexcept : DimensionalScalarQuantity<Unit::VolumeRate>(value) {}

};

template <> constexpr bool sort(const VolumeRate& volume_rate_1, const VolumeRate& volume_rate_2) noexcept {
  return sort(volume_rate_1.value(), volume_rate_2.value());
}

constexpr Volume::Volume(const VolumeRate& volume_rate, const Duration& duration) noexcept : Volume(volume_rate.value() * duration.value()) {}

constexpr Volume::Volume(const VolumeRate& volume_rate, const Frequency& frequency) noexcept : Volume(volume_rate.value() / frequency.value()) {}

constexpr Duration::Duration(const VolumeRate& volume_rate, const Volume& volume) noexcept : Duration(volume.value() / volume_rate.value()) {}

constexpr Frequency::Frequency(const VolumeRate& volume_rate, const Volume& volume) noexcept : Frequency(volume_rate.value() / volume.value()) {}

constexpr Volume Duration::operator*(const VolumeRate& volume_rate) const noexcept {
  return {volume_rate, *this};
}

constexpr VolumeRate Volume::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

constexpr Duration Volume::operator/(const VolumeRate& volume_rate) const noexcept {
  return {volume_rate, *this};
}

constexpr VolumeRate Frequency::operator*(const Volume& volume) const noexcept {
  return {volume, *this};
}

constexpr VolumeRate Volume::operator/(const Duration& duration) const noexcept {
  return {*this, duration};
}

} // namespace PhQ
