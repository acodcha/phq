// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Energy.hpp"

namespace PhQ {

// Forward declarations.
class Duration;
class Frequency;
class Mass;
class Power;
class SpecificEnergy;
class SpecificPower;

class Energy : public DimensionalScalarQuantity<Unit::Energy> {

public:

  constexpr Energy() noexcept : DimensionalScalarQuantity<Unit::Energy>() {}

  Energy(double value, Unit::Energy unit) noexcept : DimensionalScalarQuantity<Unit::Energy>(value, unit) {}

  constexpr Energy(const Power& power, const Duration& duration) noexcept;

  constexpr Energy(const Power& power, const Frequency& frequency) noexcept;

  constexpr Energy(const SpecificEnergy& specific_energy, const Mass& mass) noexcept;

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

  Power operator*(const Frequency& frequency) const noexcept;

  Power operator/(const Duration& duration) const noexcept;

  Duration operator/(const Power& power) const noexcept;

  SpecificEnergy operator/(const Mass& mass) const noexcept;

  Mass operator/(const SpecificEnergy& specific_energy) const noexcept;

protected:

  constexpr Energy(double value) noexcept : DimensionalScalarQuantity<Unit::Energy>(value) {}

};

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::Energy> {
  size_t operator()(const PhQ::Energy& energy) const {
    return hash<double>()(energy.Value());
  }
};

} // namespace std
