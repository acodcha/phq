// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Energy.hpp"
#include "Frequency.hpp"
#include "Unit/Power.hpp"

namespace PhQ {

class Power : public DimensionalScalarQuantity<Unit::Power> {

public:

  constexpr Power() noexcept : DimensionalScalarQuantity<Unit::Power>() {}

  constexpr Power(double value, Unit::Power unit) noexcept : DimensionalScalarQuantity<Unit::Power>(value, unit) {}

  constexpr bool operator==(const Power& power) const noexcept {
    return value_ == power.value_;
  }

  constexpr bool operator!=(const Power& power) const noexcept {
    return value_ != power.value_;
  }

  constexpr bool operator<(const Power& power) const noexcept {
    return value_ < power.value_;
  }

  constexpr bool operator<=(const Power& power) const noexcept {
    return value_ <= power.value_;
  }

  constexpr bool operator>(const Power& power) const noexcept {
    return value_ > power.value_;
  }

  constexpr bool operator>=(const Power& power) const noexcept {
    return value_ >= power.value_;
  }

  constexpr Power operator+(const Power& power) const noexcept {
    return {value_ + power.value_};
  }

  constexpr void operator+=(const Power& power) noexcept {
    value_ += power.value_;
  }

  constexpr Power operator-(const Power& power) const noexcept {
    return {value_ - power.value_};
  }

  constexpr void operator-=(const Power& power) noexcept {
    value_ -= power.value_;
  }

  constexpr Energy operator*(const Duration& duration) const noexcept {
    return {value_ * duration.value_};
  }

  Energy operator/(const Frequency& frequency) const {
    if (frequency.value_ != 0.0) {
      return {value_ / frequency.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + frequency.print() + "."};
    }
  }

  Frequency operator/(const Energy& energy) const {
    if (energy.value_ != 0.0) {
      return {value_ / energy.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + energy.print() + "."};
    }
  }

  SpecificPower operator/(const Mass& mass) const;

protected:

  constexpr Power(double value) noexcept : DimensionalScalarQuantity<Unit::Power>(value) {}

  friend class Duration;
  friend class Energy;
  friend class Frequency;
  friend class Mass;
  friend class SpecificEnergy;
  friend class SpecificPower;

};

template <> constexpr bool sort(const Power& power_1, const Power& power_2) noexcept {
  return power_1.value() < power_2.value();
}

constexpr Energy Duration::operator*(const Power& power) const noexcept {
  return {value_ * power.value_};
}

constexpr Power Frequency::operator*(const Energy& energy) const noexcept {
  return {value_ * energy.value_};
}

constexpr Power Energy::operator*(const Frequency& frequency) const noexcept {
  return {value_ * frequency.value_};
}

Power Energy::operator/(const Duration& duration) const {
  if (duration.value_ != 0.0) {
    return {value_ / duration.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + duration.print() + "."};
  }
}

} // namespace PhQ
