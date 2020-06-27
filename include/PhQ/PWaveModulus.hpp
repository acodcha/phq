// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

class PWaveModulus : public DimensionalScalarQuantity<Unit::Pressure> {

public:

  constexpr PWaveModulus() noexcept : DimensionalScalarQuantity<Unit::Pressure>() {}

  constexpr PWaveModulus(double value, Unit::Pressure unit) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr bool operator==(const PWaveModulus& p_wave_modulus) const noexcept {
    return value_ == p_wave_modulus.value_;
  }

  constexpr bool operator!=(const PWaveModulus& p_wave_modulus) const noexcept {
    return value_ != p_wave_modulus.value_;
  }

  constexpr bool operator<(const PWaveModulus& p_wave_modulus) const noexcept {
    return value_ < p_wave_modulus.value_;
  }

  constexpr bool operator<=(const PWaveModulus& p_wave_modulus) const noexcept {
    return value_ <= p_wave_modulus.value_;
  }

  constexpr bool operator>(const PWaveModulus& p_wave_modulus) const noexcept {
    return value_ > p_wave_modulus.value_;
  }

  constexpr bool operator>=(const PWaveModulus& p_wave_modulus) const noexcept {
    return value_ >= p_wave_modulus.value_;
  }

  constexpr PWaveModulus operator+(const PWaveModulus& p_wave_modulus) const noexcept {
    return {value_ + p_wave_modulus.value_};
  }

  constexpr void operator+=(const PWaveModulus& p_wave_modulus) noexcept {
    value_ += p_wave_modulus.value_;
  }

  constexpr PWaveModulus operator-(const PWaveModulus& p_wave_modulus) const noexcept {
    return {value_ - p_wave_modulus.value_};
  }

  constexpr void operator-=(const PWaveModulus& p_wave_modulus) noexcept {
    value_ -= p_wave_modulus.value_;
  }

protected:

  constexpr PWaveModulus(double value) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value) {}

};

template <> constexpr bool sort(const PWaveModulus& p_wave_modulus_1, const PWaveModulus& p_wave_modulus_2) noexcept {
  return sort(p_wave_modulus_1.value(), p_wave_modulus_2.value());
}

} // namespace PhQ
