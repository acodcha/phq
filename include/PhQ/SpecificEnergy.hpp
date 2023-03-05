// Copyright 2020-2023 Alexandre Coderre-Chabot
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

  SpecificEnergy(double value, Unit::SpecificEnergy unit) noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>(value, unit) {}

  constexpr SpecificEnergy(const Energy& energy, const Mass& mass) noexcept : SpecificEnergy(energy.Value() / mass.Value()) {}

  constexpr SpecificEnergy(const SpecificPower& specific_power, const Time& time) noexcept;

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

  Energy operator*(const Mass& mass) const noexcept {
    return {*this, mass};
  }

  SpecificPower operator*(const Frequency& frequency) const noexcept;

  SpecificPower operator/(const Time& time) const noexcept;

  Time operator/(const SpecificPower& specific_power) const noexcept;

protected:

  constexpr SpecificEnergy(double value) noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>(value) {}

};

constexpr Mass::Mass(const SpecificEnergy& specific_energy, const Energy& energy) noexcept : Mass(energy.Value() / specific_energy.Value()) {}

constexpr Energy::Energy(const SpecificEnergy& specific_energy, const Mass& mass) noexcept : Energy(specific_energy.Value() * mass.Value()) {}

Energy Mass::operator*(const SpecificEnergy& specific_energy) const noexcept {
  return {specific_energy, *this};
}

Mass Energy::operator/(const SpecificEnergy& specific_energy) const noexcept {
  return {specific_energy, *this};
}

SpecificEnergy Energy::operator/(const Mass& mass) const noexcept {
  return {*this, mass};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::SpecificEnergy> {
  size_t operator()(const PhQ::SpecificEnergy& specific_energy) const {
    return hash<double>()(specific_energy.Value());
  }
};

} // namespace std
