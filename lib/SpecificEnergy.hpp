// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Mass.hpp"
#include "Power.hpp"
#include "Unit/SpecificEnergy.hpp"

namespace PhQ {

// Forward declaration.
class SpecificPower;

class SpecificEnergy : public DimensionalScalarQuantity<Unit::SpecificEnergy> {

public:

  constexpr SpecificEnergy() noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>() {}

  constexpr SpecificEnergy(double value, Unit::SpecificEnergy unit) noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>(value, unit) {}

  constexpr bool operator==(const SpecificEnergy& specific_energy) const noexcept {
    return value_ == specific_energy.value_;
  }

  constexpr bool operator!=(const SpecificEnergy& specific_energy) const noexcept {
    return value_ != specific_energy.value_;
  }

  constexpr bool operator<(const SpecificEnergy& specific_energy) const noexcept {
    return value_ < specific_energy.value_;
  }

  constexpr bool operator<=(const SpecificEnergy& specific_energy) const noexcept {
    return value_ <= specific_energy.value_;
  }

  constexpr bool operator>(const SpecificEnergy& specific_energy) const noexcept {
    return value_ > specific_energy.value_;
  }

  constexpr bool operator>=(const SpecificEnergy& specific_energy) const noexcept {
    return value_ >= specific_energy.value_;
  }

  SpecificEnergy operator+(const SpecificEnergy& specific_energy) const noexcept {
    return {value_ + specific_energy.value_};
  }

  constexpr void operator+=(const SpecificEnergy& specific_energy) noexcept {
    value_ += specific_energy.value_;
  }

  SpecificEnergy operator-(const SpecificEnergy& specific_energy) const noexcept {
    return {value_ - specific_energy.value_};
  }

  constexpr void operator-=(const SpecificEnergy& specific_energy) noexcept {
    value_ -= specific_energy.value_;
  }

  constexpr SpecificPower operator*(const Frequency& frequency) const noexcept;

  constexpr Energy operator*(const Mass& mass) const noexcept {
    return {value_ * mass.value_};
  }

  SpecificPower operator/(const Duration& duration) const;

protected:

  constexpr SpecificEnergy(double value) noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>(value) {}

  friend class Duration;
  friend class Energy;
  friend class Frequency;
  friend class Mass;
  friend class Power;
  friend class SpecificPower;

};

template <> constexpr bool sort(const SpecificEnergy& specific_energy_1, const SpecificEnergy& specific_energy_2) noexcept {
  return specific_energy_1.value() < specific_energy_2.value();
}

constexpr Energy Mass::operator*(const SpecificEnergy& specific_energy) const noexcept {
  return {value_ * specific_energy.value_};
}

SpecificEnergy Energy::operator/(const Mass& mass) const {
  if (mass.value_ != 0.0) {
    return {value_ / mass.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + mass.print() + "."};
  }
}

} // namespace PhQ
