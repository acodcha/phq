// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionlessDyadic.hpp"
#include "Strain.hpp"

namespace PhQ {

class DisplacementGradient : public DimensionlessDyadicQuantity {

public:

  constexpr DisplacementGradient() noexcept : DimensionlessDyadicQuantity() {}

  constexpr DisplacementGradient(const Value::Dyadic& value) noexcept : DimensionlessDyadicQuantity(value) {}

  constexpr Strain strain() const noexcept {
    return {*this};
  }

  constexpr bool operator==(const DisplacementGradient& displacement_gradient) const noexcept {
    return value_ == displacement_gradient.value_;
  }

  constexpr bool operator!=(const DisplacementGradient& displacement_gradient) const noexcept {
    return value_ != displacement_gradient.value_;
  }

  constexpr DisplacementGradient operator+(const DisplacementGradient& displacement_gradient) const noexcept {
    return {value_ + displacement_gradient.value_};
  }

  constexpr void operator+=(const DisplacementGradient& displacement_gradient) noexcept {
    value_ += displacement_gradient.value_;
  }

  constexpr DisplacementGradient operator-(const DisplacementGradient& displacement_gradient) const noexcept {
    return {value_ - displacement_gradient.value_};
  }

  constexpr void operator-=(const DisplacementGradient& displacement_gradient) noexcept {
    value_ -= displacement_gradient.value_;
  }

};

template <> constexpr bool sort(const DisplacementGradient& displacement_gradient_1, const DisplacementGradient& displacement_gradient_2) noexcept {
  return sort(displacement_gradient_1.value(), displacement_gradient_2.value());
}

constexpr Strain::Strain(const DisplacementGradient& displacement_gradient) noexcept : Strain({value_.xx(), 0.5 * (value_.xy() + value_.yx()), 0.5 * (value_.xz() + value_.zx()), value_.yy(), 0.5 * (value_.yz() + value_.zy()), value_.zz()}) {}

} // namespace PhQ

constexpr PhQ::DisplacementGradient operator*(double real, const PhQ::DisplacementGradient& displacement_gradient) noexcept {
  return {real * displacement_gradient.value()};
}

namespace std {

template <> struct hash<PhQ::DisplacementGradient> {
  size_t operator()(const PhQ::DisplacementGradient& displacement_gradient) const {
    return hash<PhQ::Value::Dyadic>()(displacement_gradient.value());
  }
};

} // namespace std
