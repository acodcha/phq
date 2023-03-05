// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Energy.hpp"
#include "Frequency.hpp"
#include "Unit/Power.hpp"

namespace PhQ {

class Power : public DimensionalScalarQuantity<Unit::Power> {

public:

  constexpr Power() noexcept : DimensionalScalarQuantity<Unit::Power>() {}

  Power(double value, Unit::Power unit) noexcept : DimensionalScalarQuantity<Unit::Power>(value, unit) {}

  constexpr Power(const Energy& energy, const Time& time) noexcept : Power(energy.Value() / time.Value()) {}

  constexpr Power(const Energy& energy, const Frequency& frequency) noexcept : Power(energy.Value() * frequency.Value()) {}

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

  Power operator+(const Power& power) const noexcept {
    return {value_ + power.value_};
  }

  constexpr void operator+=(const Power& power) noexcept {
    value_ += power.value_;
  }

  Power operator-(const Power& power) const noexcept {
    return {value_ - power.value_};
  }

  constexpr void operator-=(const Power& power) noexcept {
    value_ -= power.value_;
  }

  Energy operator*(const Time& time) const noexcept {
    return {*this, time};
  }

  Energy operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

  Frequency operator/(const Energy& energy) const noexcept {
    return {*this, energy};
  }

  SpecificPower operator/(const Mass& mass) const noexcept;

  Mass operator/(const SpecificPower& specific_power) const noexcept;

protected:

  constexpr Power(double value) noexcept : DimensionalScalarQuantity<Unit::Power>(value) {}

};

constexpr Time::Time(const Power& power, const Energy& energy) noexcept : Time(energy.Value() / power.Value()) {}

constexpr Frequency::Frequency(const Power& power, const Energy& energy) noexcept : Frequency(power.Value() / energy.Value()) {}

constexpr Energy::Energy(const Power& power, const Time& time) noexcept : Energy(power.Value() * time.Value()) {}

constexpr Energy::Energy(const Power& power, const Frequency& frequency) noexcept : Energy(power.Value() / frequency.Value()) {}

Energy Time::operator*(const Power& power) const noexcept {
  return {power, *this};
}

Power Frequency::operator*(const Energy& energy) const noexcept {
  return {energy, *this};
}

Power Energy::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

Power Energy::operator/(const Time& time) const noexcept {
  return {*this, time};
}

Time Energy::operator/(const Power& power) const noexcept {
  return {power, *this};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::Power> {
  size_t operator()(const PhQ::Power& power) const {
    return hash<double>()(power.Value());
  }
};

} // namespace std
