// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "SpecificEnergy.hpp"
#include "Unit/SpecificPower.hpp"

namespace PhQ {

class SpecificPower : public DimensionalScalarQuantity<Unit::SpecificPower> {

public:

  constexpr SpecificPower() noexcept : DimensionalScalarQuantity<Unit::SpecificPower>() {}

  constexpr SpecificPower(double value, Unit::SpecificPower unit) noexcept : DimensionalScalarQuantity<Unit::SpecificPower>(value, unit) {}

  constexpr SpecificPower(const SpecificEnergy& specific_energy, const Duration& duration) noexcept : SpecificPower(specific_energy.value() / duration.value()) {}

  constexpr SpecificPower(const SpecificEnergy& specific_energy, const Frequency& frequency) noexcept : SpecificPower(specific_energy.value() * frequency.value()) {}

  constexpr SpecificPower(const Power& power, const Mass& mass) noexcept : SpecificPower(power.value() / mass.value()) {}

  constexpr bool operator==(const SpecificPower& specific_power) const noexcept {
    return value_ == specific_power.value_;
  }

  constexpr bool operator!=(const SpecificPower& specific_power) const noexcept {
    return value_ != specific_power.value_;
  }

  constexpr bool operator<(const SpecificPower& specific_power) const noexcept {
    return value_ < specific_power.value_;
  }

  constexpr bool operator<=(const SpecificPower& specific_power) const noexcept {
    return value_ <= specific_power.value_;
  }

  constexpr bool operator>(const SpecificPower& specific_power) const noexcept {
    return value_ > specific_power.value_;
  }

  constexpr bool operator>=(const SpecificPower& specific_power) const noexcept {
    return value_ >= specific_power.value_;
  }

  constexpr SpecificPower operator+(const SpecificPower& specific_power) const noexcept {
    return {value_ + specific_power.value_};
  }

  constexpr void operator+=(const SpecificPower& specific_power) noexcept {
    value_ += specific_power.value_;
  }

  constexpr SpecificPower operator-(const SpecificPower& specific_power) const noexcept {
    return {value_ - specific_power.value_};
  }

  constexpr void operator-=(const SpecificPower& specific_power) noexcept {
    value_ -= specific_power.value_;
  }

  constexpr SpecificEnergy operator*(const Duration& duration) const noexcept {
    return {*this, duration};
  }

  constexpr Power operator*(const Mass& mass) const noexcept {
    return {*this, mass};
  }

  constexpr SpecificEnergy operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  constexpr Frequency operator/(const SpecificEnergy& specific_energy) const noexcept {
    return {*this, specific_energy};
  }

protected:

  constexpr SpecificPower(double value) noexcept : DimensionalScalarQuantity<Unit::SpecificPower>(value) {}

  friend class Duration;
  friend class Energy;
  friend class Frequency;
  friend class Mass;
  friend class Power;
  friend class SpecificEnergy;

};

template <> constexpr bool sort(const SpecificPower& specific_power_1, const SpecificPower& specific_power_2) noexcept {
  return sort(specific_power_1.value(), specific_power_2.value());
}

constexpr Duration::Duration(const SpecificPower& specific_power, const SpecificEnergy& specific_energy) noexcept : Duration(specific_energy.value() / specific_power.value()) {}

constexpr Frequency::Frequency(const SpecificPower& specific_power, const SpecificEnergy& specific_energy) noexcept : Frequency(specific_power.value() / specific_energy.value()) {}

constexpr Mass::Mass(const SpecificPower& specific_power, const Power& power) noexcept : Mass(power.value() / specific_power.value()) {}

constexpr Power::Power(const SpecificPower& specific_power, const Mass& mass) noexcept : Power(specific_power.value() * mass.value()) {}

constexpr SpecificEnergy::SpecificEnergy(const SpecificPower& specific_power, const Duration& duration) noexcept : SpecificEnergy(specific_power.value() * duration.value()) {}

constexpr SpecificEnergy::SpecificEnergy(const SpecificPower& specific_power, const Frequency& frequency) noexcept : SpecificEnergy(specific_power.value() / frequency.value()) {}

constexpr Power Mass::operator*(const SpecificPower& specific_power) const noexcept {
  return {specific_power, *this};
}

constexpr Mass Power::operator/(const SpecificPower& specific_power) const noexcept {
  return {specific_power, *this};
}

constexpr SpecificEnergy Duration::operator*(const SpecificPower& specific_power) const noexcept {
  return {specific_power, *this};
}

constexpr SpecificPower Frequency::operator*(const SpecificEnergy& specific_energy) const noexcept {
  return {specific_energy, *this};
}

constexpr SpecificPower Power::operator/(const Mass& mass) const noexcept {
  return {*this, mass};
}

constexpr SpecificPower SpecificEnergy::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

constexpr SpecificPower SpecificEnergy::operator/(const Duration& duration) const noexcept {
  return {*this, duration};
}

constexpr Duration SpecificEnergy::operator/(const SpecificPower& specific_power) const noexcept {
  return {specific_power, *this};
}

} // namespace PhQ
