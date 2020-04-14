// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

class LameFirstModulus : public DimensionalScalarQuantity<Unit::Pressure> {

public:

  constexpr LameFirstModulus() noexcept : DimensionalScalarQuantity<Unit::Pressure>() {}

  constexpr LameFirstModulus(double value, Unit::Pressure unit) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr bool operator==(const LameFirstModulus& lame_first_modulus) const noexcept {
    return value_ == lame_first_modulus.value_;
  }

  constexpr bool operator!=(const LameFirstModulus& lame_first_modulus) const noexcept {
    return value_ != lame_first_modulus.value_;
  }

  constexpr bool operator<(const LameFirstModulus& lame_first_modulus) const noexcept {
    return value_ < lame_first_modulus.value_;
  }

  constexpr bool operator<=(const LameFirstModulus& lame_first_modulus) const noexcept {
    return value_ <= lame_first_modulus.value_;
  }

  constexpr bool operator>(const LameFirstModulus& lame_first_modulus) const noexcept {
    return value_ > lame_first_modulus.value_;
  }

  constexpr bool operator>=(const LameFirstModulus& lame_first_modulus) const noexcept {
    return value_ >= lame_first_modulus.value_;
  }

  constexpr LameFirstModulus operator+(const LameFirstModulus& lame_first_modulus) const noexcept {
    return {value_ + lame_first_modulus.value_};
  }

  constexpr void operator+=(const LameFirstModulus& lame_first_modulus) noexcept {
    value_ += lame_first_modulus.value_;
  }

  constexpr LameFirstModulus operator-(const LameFirstModulus& lame_first_modulus) const noexcept {
    return {value_ - lame_first_modulus.value_};
  }

  constexpr void operator-=(const LameFirstModulus& lame_first_modulus) noexcept {
    value_ -= lame_first_modulus.value_;
  }

protected:

  constexpr LameFirstModulus(double value) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value) {}

};

template <> constexpr bool sort(const LameFirstModulus& lame_first_modulus_1, const LameFirstModulus& lame_first_modulus_2) noexcept {
  return lame_first_modulus_1.value() < lame_first_modulus_2.value();
}

} // namespace PhQ
