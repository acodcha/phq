// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "PoissonRatio.hpp"
#include "YoungModulus.hpp"

namespace PhQ {

class ShearModulus : public DimensionalScalarQuantity<Unit::Pressure> {

public:

  constexpr ShearModulus() noexcept : DimensionalScalarQuantity<Unit::Pressure>() {}

  constexpr ShearModulus(double value, Unit::Pressure unit) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  ShearModulus(const YoungModulus& young_modulus, const PoissonRatio& poisson_ratio) : ShearModulus() {
    const double denominator{2.0 * (1.0 + poisson_ratio.value())};
    if (denominator != 0.0) {
      value_ = young_modulus.value() / denominator;
    } else {
      throw std::runtime_error{"Division of " + young_modulus.print() + " by " + number_to_string(denominator) + "."};
    }
  }

  constexpr bool operator==(const ShearModulus& shear_modulus) const noexcept {
    return value_ == shear_modulus.value_;
  }

  constexpr bool operator!=(const ShearModulus& shear_modulus) const noexcept {
    return value_ != shear_modulus.value_;
  }

  constexpr bool operator<(const ShearModulus& shear_modulus) const noexcept {
    return value_ < shear_modulus.value_;
  }

  constexpr bool operator<=(const ShearModulus& shear_modulus) const noexcept {
    return value_ <= shear_modulus.value_;
  }

  constexpr bool operator>(const ShearModulus& shear_modulus) const noexcept {
    return value_ > shear_modulus.value_;
  }

  constexpr bool operator>=(const ShearModulus& shear_modulus) const noexcept {
    return value_ >= shear_modulus.value_;
  }

  constexpr ShearModulus operator+(const ShearModulus& shear_modulus) const noexcept {
    return {value_ + shear_modulus.value_};
  }

  constexpr void operator+=(const ShearModulus& shear_modulus) noexcept {
    value_ += shear_modulus.value_;
  }

  constexpr ShearModulus operator-(const ShearModulus& shear_modulus) const noexcept {
    return {value_ - shear_modulus.value_};
  }

  constexpr void operator-=(const ShearModulus& shear_modulus) noexcept {
    value_ -= shear_modulus.value_;
  }

protected:

  constexpr ShearModulus(double value) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value) {}

};

PoissonRatio::PoissonRatio(const YoungModulus& young_modulus, const ShearModulus& shear_modulus) : PoissonRatio() {
  const double denominator{2.0 * shear_modulus.value()};
  if (denominator != 0.0) {
    value_ = young_modulus.value() / denominator - 1.0;
  } else {
    throw std::runtime_error{"Division of " + young_modulus.print() + " by " + number_to_string(denominator) + "."};
  }
}

constexpr YoungModulus::YoungModulus(const ShearModulus& shear_modulus, const PoissonRatio& poisson_ratio) noexcept : YoungModulus(shear_modulus * 2.0 * (poisson_ratio + 1.0)) {}

} // namespace PhQ
