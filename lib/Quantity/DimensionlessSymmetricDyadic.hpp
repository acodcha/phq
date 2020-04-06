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

  DimensionlessSymmetricDyadicQuantity() noexcept : DimensionlessQuantity() {}

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

  DimensionlessSymmetricDyadicQuantity operator/(double real) const {
    if (real != 0.0) {
      return {value_ / real};
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

  DimensionlessSymmetricDyadicQuantity operator/(const DimensionlessScalarQuantity& scalar) const {
    if (scalar.value() != 0.0) {
      return {value_ / scalar.value()};
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + scalar.print() + "."};
    }
  }

  void operator/=(double real) {
    if (real != 0.0) {
      value_ /= real;
    } else {
      throw std::runtime_error{"Division of " + print() + " by 0."};
    }
  }

  void operator/=(const DimensionlessScalarQuantity& scalar) {
    if (scalar.value() != 0.0) {
      value_ /= scalar.value();
    } else {
      throw std::runtime_error{"Division of " + print() + " by " + scalar.print() + "."};
    }
  }

protected:

  Value::SymmetricDyadic value_;

};

template <> constexpr bool sort(const DimensionlessSymmetricDyadicQuantity& dyadic1, const DimensionlessSymmetricDyadicQuantity& dyadic2) noexcept {
  return sort(dyadic1.value(), dyadic2.value());
}

} // namespace PhQ

constexpr PhQ::DimensionlessSymmetricDyadicQuantity operator*(double real, const PhQ::DimensionlessSymmetricDyadicQuantity& dyadic) noexcept {
  return {dyadic * real};
}

constexpr PhQ::DimensionlessSymmetricDyadicQuantity operator*(const PhQ::DimensionlessScalarQuantity& scalar, const PhQ::DimensionlessSymmetricDyadicQuantity& dyadic) noexcept {
  return {dyadic * scalar.value()};
}
