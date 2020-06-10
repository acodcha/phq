// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../Value/SymmetricDyadic.hpp"
#include "DimensionlessScalar.hpp"

namespace PhQ {

class DimensionlessSymmetricDyadicQuantity : public DimensionlessQuantity {

public:

  constexpr DimensionlessSymmetricDyadicQuantity() noexcept : DimensionlessQuantity(), value_() {}

  constexpr DimensionlessSymmetricDyadicQuantity(const Value::SymmetricDyadic& value) noexcept : DimensionlessQuantity(), value_(value) {}

  constexpr const Value::SymmetricDyadic& value() const noexcept {
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

  constexpr DimensionlessSymmetricDyadicQuantity operator*(double real) const noexcept {
    return {value_ * real};
  }

  constexpr DimensionlessSymmetricDyadicQuantity operator*(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ * scalar.value()};
  }

  constexpr void operator*=(double real) noexcept {
    value_ *= real;
  }

  constexpr void operator*=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ *= scalar.value();
  }

  constexpr DimensionlessSymmetricDyadicQuantity operator/(double real) const noexcept {
    return {value_ / real};
  }

  constexpr DimensionlessSymmetricDyadicQuantity operator/(const DimensionlessScalarQuantity& scalar) const noexcept {
    return {value_ / scalar.value()};
  }

  constexpr void operator/=(double real) noexcept {
    value_ /= real;
  }

  constexpr void operator/=(const DimensionlessScalarQuantity& scalar) noexcept {
    value_ /= scalar.value();
  }

protected:

  Value::SymmetricDyadic value_;

};

template <> constexpr bool sort(const DimensionlessSymmetricDyadicQuantity& symmetric_dyadic_1, const DimensionlessSymmetricDyadicQuantity& symmetric_dyadic_2) noexcept {
  return sort(symmetric_dyadic_1.value(), symmetric_dyadic_2.value());
}

constexpr DimensionlessSymmetricDyadicQuantity DimensionlessScalarQuantity::operator*(const DimensionlessSymmetricDyadicQuantity& symmetric_dyadic) const noexcept {
  return {symmetric_dyadic * value_};
}

} // namespace PhQ

constexpr PhQ::DimensionlessSymmetricDyadicQuantity operator*(double real, const PhQ::DimensionlessSymmetricDyadicQuantity& symmetric_dyadic) noexcept {
  return {symmetric_dyadic * real};
}
