// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Area.hpp"
#include "Unit/Volume.hpp"

namespace PhQ {

// Forward declarations.
class Mass;
class MassDensity;

class Volume : public DimensionalScalarQuantity<Unit::Volume> {

public:

  constexpr Volume() noexcept : DimensionalScalarQuantity<Unit::Volume>() {}

  constexpr Volume(double value, Unit::Volume unit) noexcept : DimensionalScalarQuantity<Unit::Volume>(value, unit) {}

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

  Area operator/(const Length& length) const {
    if (length.value_ != 0.0) {
      return {value_ / length.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + length.print() + "."};
    }
  }

  Length operator/(const Area& area) const {
    if (area.value_ != 0.0) {
      return {value_ / area.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + area.print() + "."};
    }
  }

protected:

  constexpr Volume(double value) noexcept : DimensionalScalarQuantity<Unit::Volume>(value) {}

  friend class Area;
  friend class Length;
  friend class Mass;
  friend class MassDensity;

};

constexpr Volume Length::operator*(const Area& area) const noexcept {
  return {value_ * area.value_};
}

constexpr Volume Area::operator*(const Length& length) const noexcept {
  return {value_ * length.value_};
}


} // namespace PhQ
