// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

class IsentropicBulkModulus : public DimensionalScalarQuantity<Unit::Pressure> {

public:

  constexpr IsentropicBulkModulus() noexcept : DimensionalScalarQuantity<Unit::Pressure>() {}

  IsentropicBulkModulus(double value, Unit::Pressure unit) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr bool operator==(const IsentropicBulkModulus& isentropic_bulk_modulus) const noexcept {
    return value_ == isentropic_bulk_modulus.value_;
  }

  constexpr bool operator!=(const IsentropicBulkModulus& isentropic_bulk_modulus) const noexcept {
    return value_ != isentropic_bulk_modulus.value_;
  }

  constexpr bool operator<(const IsentropicBulkModulus& isentropic_bulk_modulus) const noexcept {
    return value_ < isentropic_bulk_modulus.value_;
  }

  constexpr bool operator<=(const IsentropicBulkModulus& isentropic_bulk_modulus) const noexcept {
    return value_ <= isentropic_bulk_modulus.value_;
  }

  constexpr bool operator>(const IsentropicBulkModulus& isentropic_bulk_modulus) const noexcept {
    return value_ > isentropic_bulk_modulus.value_;
  }

  constexpr bool operator>=(const IsentropicBulkModulus& isentropic_bulk_modulus) const noexcept {
    return value_ >= isentropic_bulk_modulus.value_;
  }

  IsentropicBulkModulus operator+(const IsentropicBulkModulus& isentropic_bulk_modulus) const noexcept {
    return {value_ + isentropic_bulk_modulus.value_};
  }

  constexpr void operator+=(const IsentropicBulkModulus& isentropic_bulk_modulus) noexcept {
    value_ += isentropic_bulk_modulus.value_;
  }

  IsentropicBulkModulus operator-(const IsentropicBulkModulus& isentropic_bulk_modulus) const noexcept {
    return {value_ - isentropic_bulk_modulus.value_};
  }

  constexpr void operator-=(const IsentropicBulkModulus& isentropic_bulk_modulus) noexcept {
    value_ -= isentropic_bulk_modulus.value_;
  }

private:

  constexpr IsentropicBulkModulus(double value) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value) {}

};

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::IsentropicBulkModulus> {
  size_t operator()(const PhQ::IsentropicBulkModulus& isentropic_bulk_modulus) const {
    return hash<double>()(isentropic_bulk_modulus.Value());
  }
};

} // namespace std
