// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Frequency.hpp"
#include "Mass.hpp"
#include "Unit/MassRate.hpp"

namespace PhQ {

class MassRate : public DimensionalScalarQuantity<Unit::MassRate> {

public:

  constexpr MassRate() noexcept : DimensionalScalarQuantity<Unit::MassRate>() {}

  MassRate(double value, Unit::MassRate unit) noexcept : DimensionalScalarQuantity<Unit::MassRate>(value, unit) {}

  constexpr MassRate(const Mass& mass, const Duration& duration) noexcept : MassRate(mass.Value() / duration.Value()) {}

  constexpr MassRate(const Mass& mass, const Frequency& frequency) noexcept : MassRate(mass.Value() * frequency.Value()) {}

  constexpr bool operator==(const MassRate& mass_rate) const noexcept {
    return value_ == mass_rate.value_;
  }

  constexpr bool operator!=(const MassRate& mass_rate) const noexcept {
    return value_ != mass_rate.value_;
  }

  constexpr bool operator<(const MassRate& mass_rate) const noexcept {
    return value_ < mass_rate.value_;
  }

  constexpr bool operator<=(const MassRate& mass_rate) const noexcept {
    return value_ <= mass_rate.value_;
  }

  constexpr bool operator>(const MassRate& mass_rate) const noexcept {
    return value_ > mass_rate.value_;
  }

  constexpr bool operator>=(const MassRate& mass_rate) const noexcept {
    return value_ >= mass_rate.value_;
  }

  MassRate operator+(const MassRate& mass_rate) const noexcept {
    return {value_ + mass_rate.value_};
  }

  constexpr void operator+=(const MassRate& mass_rate) noexcept {
    value_ += mass_rate.value_;
  }

  MassRate operator-(const MassRate& mass_rate) const noexcept {
    return {value_ - mass_rate.value_};
  }

  constexpr void operator-=(const MassRate& mass_rate) noexcept {
    value_ -= mass_rate.value_;
  }

  Frequency operator/(const Mass& mass) const noexcept {
    return {*this, mass};
  }

  Mass operator*(const Duration& duration) const noexcept {
    return {*this, duration};
  }

  Mass operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

protected:

  constexpr MassRate(double value) noexcept : DimensionalScalarQuantity<Unit::MassRate>(value) {}

};

constexpr Duration::Duration(const MassRate& mass_rate, const Mass& mass) noexcept : Duration(mass.Value() / mass_rate.Value()) {}

constexpr Frequency::Frequency(const MassRate& mass_rate, const Mass& mass) noexcept : Frequency(mass_rate.Value() / mass.Value()) {}

constexpr Mass::Mass(const MassRate& mass_rate, const Duration& duration) noexcept : Mass(mass_rate.Value() * duration.Value()) {}

constexpr Mass::Mass(const MassRate& mass_rate, const Frequency& frequency) noexcept : Mass(mass_rate.Value() / frequency.Value()) {}

Mass Duration::operator*(const MassRate& mass_rate) const noexcept {
  return {mass_rate, *this};
}

MassRate Mass::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

MassRate Frequency::operator*(const Mass& mass) const noexcept {
  return {mass, *this};
}

MassRate Mass::operator/(const Duration& duration) const noexcept {
  return {*this, duration};
}

Duration Mass::operator/(const MassRate& mass_rate) const noexcept {
  return {mass_rate, *this};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::MassRate> {
  size_t operator()(const PhQ::MassRate& mass_rate) const {
    return hash<double>()(mass_rate.Value());
  }
};

} // namespace std
