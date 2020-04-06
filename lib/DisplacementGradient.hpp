// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionlessDyadic.hpp"

namespace PhQ {

class DisplacementGradient : public DimensionlessDyadicQuantity {

public:

  DisplacementGradient() noexcept : DimensionlessDyadicQuantity() {}

  constexpr DisplacementGradient(const Value::Dyadic& value) noexcept : DimensionlessDyadicQuantity(value) {}

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

} // namespace PhQ
