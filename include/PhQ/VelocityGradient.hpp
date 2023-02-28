// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalDyadic.hpp"
#include "StrainRate.hpp"

namespace PhQ {

class VelocityGradient : public DimensionalDyadicQuantity<Unit::Frequency> {

public:

  constexpr VelocityGradient() noexcept : DimensionalDyadicQuantity<Unit::Frequency>() {}

  constexpr VelocityGradient(const Value::Dyadic& value, const Unit::Frequency& unit) noexcept : DimensionalDyadicQuantity<Unit::Frequency>(value, unit) {}

  constexpr StrainRate strain_rate() const noexcept {
    return {*this};
  }

  constexpr bool operator==(const VelocityGradient& velocity_gradient) const noexcept {
    return value_ == velocity_gradient.value_;
  }

  constexpr bool operator!=(const VelocityGradient& velocity_gradient) const noexcept {
    return value_ != velocity_gradient.value_;
  }

  constexpr VelocityGradient operator+(const VelocityGradient& velocity_gradient) const noexcept {
    return {value_ + velocity_gradient.value_};
  }

  constexpr void operator+=(const VelocityGradient& velocity_gradient) noexcept {
    value_ += velocity_gradient.value_;
  }

  constexpr VelocityGradient operator-(const VelocityGradient& velocity_gradient) const noexcept {
    return {value_ - velocity_gradient.value_};
  }

  constexpr void operator-=(const VelocityGradient& velocity_gradient) noexcept {
    value_ -= velocity_gradient.value_;
  }

protected:

  constexpr VelocityGradient(const Value::Dyadic& value) noexcept : DimensionalDyadicQuantity<Unit::Frequency>(value) {}

};

template <> constexpr bool sort(const VelocityGradient& velocity_gradient_1, const VelocityGradient& velocity_gradient_2) noexcept {
  return sort(velocity_gradient_1.value(), velocity_gradient_2.value());
}

constexpr StrainRate::StrainRate(const VelocityGradient& velocity_gradient) noexcept : StrainRate({value_.xx(), 0.5 * (value_.xy() + value_.yx()), 0.5 * (value_.xz() + value_.zx()), value_.yy(), 0.5 * (value_.yz() + value_.zy()), value_.zz()}) {}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::VelocityGradient> {
  size_t operator()(const PhQ::VelocityGradient& velocity_gradient) const {
    return hash<PhQ::Value::Dyadic>()(velocity_gradient.value());
  }
};

} // namespace std
