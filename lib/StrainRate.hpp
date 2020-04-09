// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Frequency.hpp"
#include "Quantity/DimensionalSymmetricDyadic.hpp"
#include "Strain.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

class StrainRate : public DimensionalSymmetricDyadicQuantity<Unit::Frequency> {

public:

  constexpr StrainRate() noexcept : DimensionalSymmetricDyadicQuantity<Unit::Frequency>() {}

  constexpr StrainRate(const Value::SymmetricDyadic& value, Unit::Frequency unit) noexcept : DimensionalSymmetricDyadicQuantity<Unit::Frequency>(value, unit) {}

  constexpr bool operator==(const StrainRate& strain_rate) const noexcept {
    return value_ == strain_rate.value_;
  }

  constexpr bool operator!=(const StrainRate& strain_rate) const noexcept {
    return value_ != strain_rate.value_;
  }

  constexpr StrainRate operator+(const StrainRate& strain_rate) const noexcept {
    return {value_ + strain_rate.value_};
  }

  constexpr void operator+=(const StrainRate& strain_rate) noexcept {
    value_ += strain_rate.value_;
  }

  constexpr StrainRate operator-(const StrainRate& strain_rate) const noexcept {
    return {value_ - strain_rate.value_};
  }

  constexpr void operator-=(const StrainRate& strain_rate) noexcept {
    value_ -= strain_rate.value_;
  }

  constexpr Strain operator*(const Duration& duration) const noexcept {
    return {value_ * duration.value_};
  }

  Strain operator/(const Frequency& frequency) const {
    if (frequency.value_ != 0.0) {
      return {value_ / frequency.value_};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + frequency.print() + "."};
    }
  }

protected:

  constexpr StrainRate(const Value::SymmetricDyadic& value) noexcept : DimensionalSymmetricDyadicQuantity<Unit::Frequency>(value) {}

  friend class Duration;
  friend class Frequency;
  friend class Strain;

};

constexpr StrainRate Strain::operator*(const Frequency& frequency) const noexcept {
  return {value_ * frequency.value_};
}

StrainRate Strain::operator/(const Duration& duration) const {
  if (duration.value_ != 0.0) {
    return {value_ / duration.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + duration.print() + "."};
  }
}

constexpr Strain Duration::operator*(const StrainRate& strain_rate) const noexcept {
  return {value_ * strain_rate.value_};
}

constexpr StrainRate Frequency::operator*(const Strain& strain) const noexcept {
  return {value_ * strain.value_};
}

} // namespace PhQ
