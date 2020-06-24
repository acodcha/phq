// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../Value/Dyadic.hpp"
#include "DimensionlessSymmetricDyadic.hpp"

namespace PhQ {

class DimensionlessDyadicQuantity : public DimensionlessQuantity {

public:

  constexpr const Value::Dyadic& value() const noexcept {
    return value_;
  }

  std::string print() const noexcept {
    return value_.print();
  }

  std::string json() const noexcept {
    return value_.json();
  }

  std::string xml() const noexcept {
    return value_.xml();
  }

  constexpr DimensionlessDyadicQuantity operator*(double real) const noexcept {
    return {value_ * real};
  }

  constexpr DimensionlessDyadicQuantity operator*(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ * scalar.value()};
  }

  constexpr void operator*=(double real) noexcept {
    value_ *= real;
  }

  constexpr void operator*=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ *= scalar.value();
  }

  constexpr DimensionlessDyadicQuantity operator/(double real) const noexcept {
    return {value_ / real};
  }

  constexpr DimensionlessDyadicQuantity operator/(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ / scalar.value()};
  }

  constexpr void operator/=(double real) noexcept {
    value_ /= real;
  }

  constexpr void operator/=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ /= scalar.value();
  }

protected:

  constexpr DimensionlessDyadicQuantity() noexcept : DimensionlessQuantity(), value_() {}

  constexpr DimensionlessDyadicQuantity(const Value::Dyadic& value) noexcept : DimensionlessQuantity(), value_(value) {}

  Value::Dyadic value_;

};

template <> constexpr bool sort(const DimensionlessDyadicQuantity& dyadic_1, const DimensionlessDyadicQuantity& dyadic_2) noexcept {
  return sort(dyadic_1.value(), dyadic_2.value());
}

constexpr DimensionlessDyadicQuantity DimensionlessScalarQuantity::operator*(const DimensionlessDyadicQuantity& dyadic) const noexcept {
  return {dyadic * value_};
}

} // namespace PhQ
