// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Length.hpp"
#include "Unit/Area.hpp"

namespace PhQ {

// Forward declarations.
class Force;
class ForceMagnitude;
class Pressure;
class Traction;

class Area : public DimensionalScalarQuantity<Unit::Area> {

public:

  constexpr Area() noexcept : DimensionalScalarQuantity<Unit::Area>() {}

  constexpr Area(double value, Unit::Area unit) noexcept : DimensionalScalarQuantity<Unit::Area>(value, unit) {}

  constexpr bool operator==(const Area& area) const noexcept {
    return value_ == area.value_;
  }

  constexpr bool operator!=(const Area& area) const noexcept {
    return value_ != area.value_;
  }

  constexpr bool operator<(const Area& area) const noexcept {
    return value_ < area.value_;
  }

  constexpr bool operator<=(const Area& area) const noexcept {
    return value_ <= area.value_;
  }

  constexpr bool operator>(const Area& area) const noexcept {
    return value_ > area.value_;
  }

  constexpr bool operator>=(const Area& area) const noexcept {
    return value_ >= area.value_;
  }

  constexpr Area operator+(const Area& area) const noexcept {
    return {value_ + area.value_};
  }

  constexpr void operator+=(const Area& area) noexcept {
    value_ += area.value_;
  }

  constexpr Area operator-(const Area& area) const noexcept {
    return {value_ - area.value_};
  }

  constexpr void operator-=(const Area& area) noexcept {
    value_ -= area.value_;
  }

  constexpr Volume operator*(const Length& length) const noexcept;

  constexpr ForceMagnitude operator*(const Pressure& pressure) const noexcept;

  Length operator/(const Length& length) const {
    if (length.value_ != 0.0) {
      return {value_ / length.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + length.print() + "."};
    }
  }

protected:

  constexpr Area(double value) noexcept : DimensionalScalarQuantity<Unit::Area>(value) {}

  friend class Force;
  friend class ForceMagnitude;
  friend class Length;
  friend class Pressure;
  friend class Traction;
  friend class Volume;

};

constexpr Area Length::operator*(const Length& length) const noexcept {
  return {value_ * length.value_};
}

} // namespace PhQ
