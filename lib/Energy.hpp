// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Energy.hpp"

namespace PhQ {

// Forward declarations.
class Duration;
class Frequency;
class Power;

class Energy : public DimensionalScalarQuantity<Unit::Energy> {

public:

  constexpr Energy() noexcept : DimensionalScalarQuantity<Unit::Energy>() {}

  constexpr Energy(double value, Unit::Energy unit) noexcept : DimensionalScalarQuantity<Unit::Energy>(value, unit) {}

  constexpr bool operator==(const Energy& energy) const noexcept {
    return value_ == energy.value_;
  }

  constexpr bool operator!=(const Energy& energy) const noexcept {
    return value_ != energy.value_;
  }

  constexpr bool operator<(const Energy& energy) const noexcept {
    return value_ < energy.value_;
  }

  constexpr bool operator<=(const Energy& energy) const noexcept {
    return value_ <= energy.value_;
  }

  constexpr bool operator>(const Energy& energy) const noexcept {
    return value_ > energy.value_;
  }

  constexpr bool operator>=(const Energy& energy) const noexcept {
    return value_ >= energy.value_;
  }

  Energy operator+(const Energy& energy) const noexcept {
    return {value_ + energy.value_};
  }

  constexpr void operator+=(const Energy& energy) noexcept {
    value_ += energy.value_;
  }

  Energy operator-(const Energy& energy) const noexcept {
    return {value_ - energy.value_};
  }

  constexpr void operator-=(const Energy& energy) noexcept {
    value_ -= energy.value_;
  }

  constexpr Power operator*(const Frequency& frequency) const noexcept;

  Power operator/(const Duration& duration) const;

protected:

  constexpr Energy(double value) noexcept : DimensionalScalarQuantity<Unit::Energy>(value) {}

  friend class Duration;
  friend class Frequency;
  friend class Power;

};

template <> constexpr bool sort(const Energy& energy_1, const Energy& energy_2) noexcept {
  return energy_1.value() < energy_2.value();
}

} // namespace PhQ
