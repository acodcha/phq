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
    return {value_ * duration.value_};
  }

  constexpr Power operator*(const Mass& mass) const noexcept {
    return {value_ * mass.value_};
  }

  constexpr SpecificEnergy operator/(const Frequency& frequency) const noexcept {
    return {value_ / frequency.value_};
  }

  constexpr Frequency operator/(const SpecificEnergy& specific_energy) const noexcept {
    return {value_ / specific_energy.value_};
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
  return specific_power_1.value() < specific_power_2.value();
}

constexpr Power Mass::operator*(const SpecificPower& specific_power) const noexcept {
  return {value_ * specific_power.value_};
}

constexpr SpecificEnergy Duration::operator*(const SpecificPower& specific_power) const noexcept {
  return {value_ * specific_power.value_};
}

constexpr SpecificPower Frequency::operator*(const SpecificEnergy& specific_energy) const noexcept {
  return {value_ * specific_energy.value_};
}

constexpr SpecificPower Power::operator/(const Mass& mass) const noexcept {
  return {value_ / mass.value_};
}

constexpr SpecificPower SpecificEnergy::operator*(const Frequency& frequency) const noexcept {
  return {value_ * frequency.value_};
}

constexpr SpecificPower SpecificEnergy::operator/(const Duration& duration) const noexcept {
  return {value_ / duration.value_};
}

} // namespace PhQ
