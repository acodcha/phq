// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Mass.hpp"

namespace PhQ {

// Forward declarations.
class MassDensity;
class Volume;

class Mass : public DimensionalScalarQuantity<Unit::Mass> {

public:

  constexpr Mass() noexcept : DimensionalScalarQuantity<Unit::Mass>() {}

  constexpr Mass(double value, Unit::Mass unit) noexcept : DimensionalScalarQuantity<Unit::Mass>(value, unit) {}

  constexpr bool operator==(const Mass& mass) const noexcept {
    return value_ == mass.value_;
  }

  constexpr bool operator!=(const Mass& mass) const noexcept {
    return value_ != mass.value_;
  }

  constexpr bool operator<(const Mass& mass) const noexcept {
    return value_ < mass.value_;
  }

  constexpr bool operator<=(const Mass& mass) const noexcept {
    return value_ <= mass.value_;
  }

  constexpr bool operator>(const Mass& mass) const noexcept {
    return value_ > mass.value_;
  }

  constexpr bool operator>=(const Mass& mass) const noexcept {
    return value_ >= mass.value_;
  }

  Mass operator+(const Mass& mass) const noexcept {
    return {value_ + mass.value_};
  }

  constexpr void operator+=(const Mass& mass) noexcept {
    value_ += mass.value_;
  }

  Mass operator-(const Mass& mass) const noexcept {
    return {value_ - mass.value_};
  }

  constexpr void operator-=(const Mass& mass) noexcept {
    value_ -= mass.value_;
  }

  MassDensity operator/(const Volume& volume) const;

protected:

  constexpr Mass(double value) noexcept : DimensionalScalarQuantity<Unit::Mass>(value) {}

  friend class MassDensity;
  friend class Volume;

};

} // namespace PhQ
