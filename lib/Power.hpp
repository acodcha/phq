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

  constexpr Power(const Energy& energy, const Duration& duration) noexcept : Power(energy.value() / duration.value()) {}

  constexpr Power(const Energy& energy, const Frequency& frequency) noexcept : Power(energy.value() * frequency.value()) {}

  constexpr Power(const SpecificPower& specific_power, const Mass& mass) noexcept;

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
    return {*this, duration};
  }

  constexpr Energy operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const Energy& energy) const noexcept {
    return {*this, energy};
  }

  constexpr SpecificPower operator/(const Mass& mass) const noexcept;

  constexpr Mass operator/(const SpecificPower& specific_power) const noexcept;

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
  return sort(power_1.value(), power_2.value());
}

constexpr Duration::Duration(const Power& power, const Energy& energy) noexcept : Duration(energy.value() / power.value()) {}

constexpr Frequency::Frequency(const Power& power, const Energy& energy) noexcept : Frequency(power.value() / energy.value()) {}

constexpr Energy::Energy(const Power& power, const Duration& duration) noexcept : Energy(power.value() * duration.value()) {}

constexpr Energy::Energy(const Power& power, const Frequency& frequency) noexcept : Energy(power.value() / frequency.value()) {}

constexpr Energy Duration::operator*(const Power& power) const noexcept {
  return {power, *this};
}

constexpr Power Frequency::operator*(const Energy& energy) const noexcept {
  return {energy, *this};
}

constexpr Power Energy::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

constexpr Power Energy::operator/(const Duration& duration) const noexcept {
  return {*this, duration};
}

constexpr Duration Energy::operator/(const Power& power) const noexcept {
  return {power, *this};
}

} // namespace PhQ
