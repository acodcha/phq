// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Frequency.hpp"
#include "Quantity/DimensionalSymmetricDyad.hpp"
#include "Strain.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

// Forward declaration.
class VelocityGradient;

class StrainRate : public DimensionalSymmetricDyadQuantity<Unit::Frequency> {

public:

  constexpr StrainRate() noexcept : DimensionalSymmetricDyadQuantity<Unit::Frequency>() {}

  StrainRate(const Value::SymmetricDyad& value, Unit::Frequency unit) noexcept : DimensionalSymmetricDyadQuantity<Unit::Frequency>(value, unit) {}

  constexpr StrainRate(const Strain& strain, const Time& time) noexcept : StrainRate(strain.Value() / time.Value()) {}

  constexpr StrainRate(const Strain& strain, const Frequency& frequency) noexcept : StrainRate(strain.Value() * frequency.Value()) {}

  constexpr StrainRate(const VelocityGradient& velocity_gradient) noexcept;

  constexpr bool operator==(const StrainRate& strain_rate) const noexcept {
    return value_ == strain_rate.value_;
  }

  constexpr bool operator!=(const StrainRate& strain_rate) const noexcept {
    return value_ != strain_rate.value_;
  }

  StrainRate operator+(const StrainRate& strain_rate) const noexcept {
    return {value_ + strain_rate.value_};
  }

  constexpr void operator+=(const StrainRate& strain_rate) noexcept {
    value_ += strain_rate.value_;
  }

  StrainRate operator-(const StrainRate& strain_rate) const noexcept {
    return {value_ - strain_rate.value_};
  }

  constexpr void operator-=(const StrainRate& strain_rate) noexcept {
    value_ -= strain_rate.value_;
  }

  Strain operator*(const Time& time) const noexcept {
    return {*this, time};
  }

  Strain operator/(const Frequency& frequency) const noexcept {
    return {*this, frequency};
  }

protected:

  constexpr StrainRate(const Value::SymmetricDyad& value) noexcept : DimensionalSymmetricDyadQuantity<Unit::Frequency>(value) {}

};

constexpr Strain::Strain(const StrainRate& strain_rate, const Time& time) noexcept : Strain(strain_rate.Value() * time.Value()) {}

constexpr Strain::Strain(const StrainRate& strain_rate, const Frequency& frequency) noexcept : Strain(strain_rate.Value() / frequency.Value()) {}

StrainRate Strain::operator*(const Frequency& frequency) const noexcept {
  return {*this, frequency};
}

StrainRate Strain::operator/(const Time& time) const noexcept {
  return {*this, time};
}

Strain Time::operator*(const StrainRate& strain_rate) const noexcept {
  return {strain_rate, *this};
}

StrainRate Frequency::operator*(const Strain& strain) const noexcept {
  return {strain, *this};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::StrainRate> {
  size_t operator()(const PhQ::StrainRate& strain_rate) const {
    return hash<PhQ::Value::SymmetricDyad>()(strain_rate.Value());
  }
};

} // namespace std
