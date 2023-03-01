// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionlessSymmetricDyad.hpp"
#include "StrainScalar.hpp"

namespace PhQ {

// Forward declarations.
class DisplacementGradient;
class Duration;
class Frequency;
class StrainRate;

class Strain : public DimensionlessSymmetricDyadQuantity {

public:

  constexpr Strain() noexcept : DimensionlessSymmetricDyadQuantity() {}

  constexpr Strain(const Value::SymmetricDyad& value) noexcept : DimensionlessSymmetricDyadQuantity(value) {}

  constexpr Strain(const StrainRate& strain_rate, const Duration& duration) noexcept;

  constexpr Strain(const StrainRate& strain_rate, const Frequency& frequency) noexcept;

  constexpr Strain(const DisplacementGradient& displacement_gradient) noexcept;

  constexpr bool operator==(const Strain& strain) const noexcept {
    return value_ == strain.value_;
  }

  constexpr bool operator!=(const Strain& strain) const noexcept {
    return value_ != strain.value_;
  }

  Strain operator+(const Strain& strain) const noexcept {
    return {value_ + strain.value_};
  }

  constexpr void operator+=(const Strain& strain) noexcept {
    value_ += strain.value_;
  }

  Strain operator-(const Strain& strain) const noexcept {
    return {value_ - strain.value_};
  }

  constexpr void operator-=(const Strain& strain) noexcept {
    value_ -= strain.value_;
  }

  constexpr StrainRate operator*(const Frequency& frequency) const noexcept;

  constexpr StrainRate operator/(const Duration& duration) const noexcept;

};

} // namespace PhQ

PhQ::Strain operator*(double real, const PhQ::Strain& strain) noexcept {
  return {real * strain.Value()};
}

namespace std {

template <> struct hash<PhQ::Strain> {
  size_t operator()(const PhQ::Strain& strain) const {
    return hash<PhQ::Value::SymmetricDyad>()(strain.Value());
  }
};

} // namespace std
