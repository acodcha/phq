// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Frequency.hpp"
#include "Quantity/DimensionalSymmetricDyadic.hpp"
#include "Strain.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

// Forward declaration.
class VelocityGradient;

class StrainRate : public DimensionalSymmetricDyadicQuantity<Unit::Frequency> {

public:

  constexpr StrainRate() noexcept : DimensionalSymmetricDyadicQuantity<Unit::Frequency>() {}

  constexpr StrainRate(const Value::SymmetricDyadic& value, Unit::Frequency unit) noexcept : DimensionalSymmetricDyadicQuantity<Unit::Frequency>(value, unit) {}

  constexpr StrainRate(const Strain& strain, const Duration& duration) noexcept : StrainRate(strain.value() / duration.value()) {}

  constexpr StrainRate(const Strain& strain, const Frequency& frequency) noexcept : StrainRate(strain.value() * frequency.value()) {}

  constexpr StrainRate(const VelocityGradient& velocity_gradient) noexcept;

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
    return {*this, duration};
  }

  constexpr Strain operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

protected:

  constexpr StrainRate(const Value::SymmetricDyadic& value) noexcept : DimensionalSymmetricDyadicQuantity<Unit::Frequency>(value) {}

};

template <> constexpr bool sort(const StrainRate& strain_rate_1, const StrainRate& strain_rate_2) noexcept {
  return sort(strain_rate_1.value(), strain_rate_2.value());
}

constexpr Strain::Strain(const StrainRate& strain_rate, const Duration& duration) noexcept : Strain(strain_rate.value() * duration.value()) {}

constexpr Strain::Strain(const StrainRate& strain_rate, const Frequency& frequency) noexcept : Strain(strain_rate.value() / frequency.value()) {}

constexpr StrainRate Strain::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

constexpr StrainRate Strain::operator/(const Duration& duration) const noexcept {
  return {*this, duration};
}

constexpr Strain Duration::operator*(const StrainRate& strain_rate) const noexcept {
  return {strain_rate, *this};
}

constexpr StrainRate Frequency::operator*(const Strain& strain) const noexcept {
  return {strain, *this};
}

} // namespace PhQ
