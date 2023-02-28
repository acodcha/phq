// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

class StressScalar : public DimensionalScalarQuantity<Unit::Pressure> {

public:

  constexpr StressScalar() noexcept : DimensionalScalarQuantity<Unit::Pressure>() {}

  constexpr StressScalar(double value, Unit::Pressure unit) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr bool operator==(const StressScalar& stress_scalar) const noexcept {
    return value_ == stress_scalar.value_;
  }

  constexpr bool operator!=(const StressScalar& stress_scalar) const noexcept {
    return value_ != stress_scalar.value_;
  }

  constexpr bool operator<(const StressScalar& stress_scalar) const noexcept {
    return value_ < stress_scalar.value_;
  }

  constexpr bool operator<=(const StressScalar& stress_scalar) const noexcept {
    return value_ <= stress_scalar.value_;
  }

  constexpr bool operator>(const StressScalar& stress_scalar) const noexcept {
    return value_ > stress_scalar.value_;
  }

  constexpr bool operator>=(const StressScalar& stress_scalar) const noexcept {
    return value_ >= stress_scalar.value_;
  }

  constexpr StressScalar operator+(const StressScalar& stress_scalar) const noexcept {
    return {value_ + stress_scalar.value_};
  }

  constexpr void operator+=(const StressScalar& stress_scalar) noexcept {
    value_ += stress_scalar.value_;
  }

  constexpr StressScalar operator-(const StressScalar& stress_scalar) const noexcept {
    return {value_ - stress_scalar.value_};
  }

  constexpr void operator-=(const StressScalar& stress_scalar) noexcept {
    value_ -= stress_scalar.value_;
  }

protected:

  constexpr StressScalar(double value) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value) {}

};

template <> constexpr bool sort(const StressScalar& stress_scalar_1, const StressScalar& stress_scalar_2) noexcept {
  return sort(stress_scalar_1.value(), stress_scalar_2.value());
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::StressScalar> {
  size_t operator()(const PhQ::StressScalar& stress_scalar) const {
    return hash<double>()(stress_scalar.value());
  }
};

} // namespace std
