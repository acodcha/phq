// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

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

  constexpr SpecificEnergy(const Energy& energy, const Mass& mass) noexcept : SpecificEnergy(energy.value() / mass.value()) {}

  constexpr SpecificEnergy(const SpecificPower& specific_power, const Duration& duration) noexcept;

  constexpr SpecificEnergy(const SpecificPower& specific_power, const Frequency& frequency) noexcept;

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

  constexpr SpecificEnergy operator+(const SpecificEnergy& specific_energy) const noexcept {
    return {value_ + specific_energy.value_};
  }

  constexpr void operator+=(const SpecificEnergy& specific_energy) noexcept {
    value_ += specific_energy.value_;
  }

  constexpr SpecificEnergy operator-(const SpecificEnergy& specific_energy) const noexcept {
    return {value_ - specific_energy.value_};
  }

  constexpr void operator-=(const SpecificEnergy& specific_energy) noexcept {
    value_ -= specific_energy.value_;
  }

  constexpr Energy operator*(const Mass& mass) const noexcept {
    return {*this, mass};
  }

  constexpr SpecificPower operator*(const Frequency& frequency) const noexcept;

  constexpr SpecificPower operator/(const Duration& duration) const noexcept;

  constexpr Duration operator/(const SpecificPower& specific_power) const noexcept;

protected:

  constexpr SpecificEnergy(double value) noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>(value) {}

};

template <> constexpr bool sort(const SpecificEnergy& specific_energy_1, const SpecificEnergy& specific_energy_2) noexcept {
  return sort(specific_energy_1.value(), specific_energy_2.value());
}

constexpr Mass::Mass(const SpecificEnergy& specific_energy, const Energy& energy) noexcept : Mass(energy.value() / specific_energy.value()) {}

constexpr Energy::Energy(const SpecificEnergy& specific_energy, const Mass& mass) noexcept : Energy(specific_energy.value() * mass.value()) {}

constexpr Energy Mass::operator*(const SpecificEnergy& specific_energy) const noexcept {
  return {specific_energy, *this};
}

constexpr Mass Energy::operator/(const SpecificEnergy& specific_energy) const noexcept {
  return {specific_energy, *this};
}

constexpr SpecificEnergy Energy::operator/(const Mass& mass) const noexcept {
  return {*this, mass};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::SpecificEnergy> {
  size_t operator()(const PhQ::SpecificEnergy& specific_energy) const {
    return hash<double>()(specific_energy.value());
  }
};

} // namespace std
