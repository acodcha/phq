// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Area.hpp"
#include "Unit/Volume.hpp"

namespace PhQ {

// Forward declarations.
class Duration;
class Frequency;
class Mass;
class MassDensity;
class VolumeRate;

class Volume : public DimensionalScalarQuantity<Unit::Volume> {

public:

  constexpr Volume() noexcept : DimensionalScalarQuantity<Unit::Volume>() {}

  constexpr Volume(double value, Unit::Volume unit) noexcept : DimensionalScalarQuantity<Unit::Volume>(value, unit) {}

  constexpr Volume(const Area& area, const Length& length) noexcept : Volume(area.value() * length.value()) {}

  constexpr Volume(const VolumeRate& volume_rate, const Duration& duration) noexcept;

  constexpr Volume(const VolumeRate& volume_rate, const Frequency& frequency) noexcept;

  constexpr Volume(const MassDensity& mass_density, const Mass& mass) noexcept;

  constexpr bool operator==(const Volume& volume) const noexcept {
    return value_ == volume.value_;
  }

  constexpr bool operator!=(const Volume& volume) const noexcept {
    return value_ != volume.value_;
  }

  constexpr bool operator<(const Volume& volume) const noexcept {
    return value_ < volume.value_;
  }

  constexpr bool operator<=(const Volume& volume) const noexcept {
    return value_ <= volume.value_;
  }

  constexpr bool operator>(const Volume& volume) const noexcept {
    return value_ > volume.value_;
  }

  constexpr bool operator>=(const Volume& volume) const noexcept {
    return value_ >= volume.value_;
  }

  constexpr Volume operator+(const Volume& volume) const noexcept {
    return {value_ + volume.value_};
  }

  constexpr void operator+=(const Volume& volume) noexcept {
    value_ += volume.value_;
  }

  constexpr Volume operator-(const Volume& volume) const noexcept {
    return {value_ - volume.value_};
  }

  constexpr void operator-=(const Volume& volume) noexcept {
    value_ -= volume.value_;
  }

  constexpr Mass operator*(const MassDensity& mass_density) const noexcept;

  constexpr VolumeRate operator*(const Frequency& frequency) const noexcept;

  constexpr Area operator/(const Length& length) const noexcept {
    return {*this, length};
  }

  constexpr Length operator/(const Area& area) const noexcept {
    return {*this, area};
  }

  constexpr VolumeRate operator/(const Duration& duration) const noexcept;

  constexpr Duration operator/(const VolumeRate& volume_rate) const noexcept;

protected:

  constexpr Volume(double value) noexcept : DimensionalScalarQuantity<Unit::Volume>(value) {}

};

template <> constexpr bool sort(const Volume& volume_1, const Volume& volume_2) noexcept {
  return sort(volume_1.value(), volume_2.value());
}

constexpr Length::Length(const Volume& volume, const Area& area) noexcept : Length(volume.value() / area.value()) {}

constexpr Area::Area(const Volume& volume, const Length& length) noexcept : Area(volume.value() / length.value()) {}

constexpr Volume Length::operator*(const Area& area) const noexcept {
  return {area, *this};
}

constexpr Volume Area::operator*(const Length& length) const noexcept {
  return {*this, length};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::Volume> {
  size_t operator()(const PhQ::Volume& volume) const {
    return hash<double>()(volume.value());
  }
};

} // namespace std
