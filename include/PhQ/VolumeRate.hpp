// Copyright 2020-2023 Alexandre Coderre-Chabot
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

  VolumeRate(double value, Unit::VolumeRate unit) noexcept : DimensionalScalarQuantity<Unit::VolumeRate>(value, unit) {}

  constexpr VolumeRate(const Volume& volume, const Time& time) noexcept : VolumeRate(volume.Value() / time.Value()) {}

  constexpr VolumeRate(const Volume& volume, const Frequency& frequency) noexcept : VolumeRate(volume.Value() * frequency.Value()) {}

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

  VolumeRate operator+(const VolumeRate& volume_rate) const noexcept {
    return {value_ + volume_rate.value_};
  }

  constexpr void operator+=(const VolumeRate& volume_rate) noexcept {
    value_ += volume_rate.value_;
  }

  VolumeRate operator-(const VolumeRate& volume_rate) const noexcept {
    return {value_ - volume_rate.value_};
  }

  constexpr void operator-=(const VolumeRate& volume_rate) noexcept {
    value_ -= volume_rate.value_;
  }

  Volume operator*(const Time& time) const noexcept {
    return {*this, time};
  }

  Volume operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  Frequency operator/(const Volume& volume) const noexcept {
    return {*this, volume};
  }

protected:

  constexpr VolumeRate(double value) noexcept : DimensionalScalarQuantity<Unit::VolumeRate>(value) {}

};

constexpr Volume::Volume(const VolumeRate& volume_rate, const Time& time) noexcept : Volume(volume_rate.Value() * time.Value()) {}

constexpr Volume::Volume(const VolumeRate& volume_rate, const Frequency& frequency) noexcept : Volume(volume_rate.Value() / frequency.Value()) {}

constexpr Time::Time(const VolumeRate& volume_rate, const Volume& volume) noexcept : Time(volume.Value() / volume_rate.Value()) {}

constexpr Frequency::Frequency(const VolumeRate& volume_rate, const Volume& volume) noexcept : Frequency(volume_rate.Value() / volume.Value()) {}

Volume Time::operator*(const VolumeRate& volume_rate) const noexcept {
  return {volume_rate, *this};
}

VolumeRate Volume::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

Time Volume::operator/(const VolumeRate& volume_rate) const noexcept {
  return {volume_rate, *this};
}

VolumeRate Frequency::operator*(const Volume& volume) const noexcept {
  return {volume, *this};
}

VolumeRate Volume::operator/(const Time& time) const noexcept {
  return {*this, time};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::VolumeRate> {
  size_t operator()(const PhQ::VolumeRate& volume_rate) const {
    return hash<double>()(volume_rate.Value());
  }
};

} // namespace std
