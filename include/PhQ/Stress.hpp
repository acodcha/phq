// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalSymmetricDyadic.hpp"
#include "StressScalar.hpp"
#include "Traction.hpp"

namespace PhQ {

class Stress : public DimensionalSymmetricDyadicQuantity<Unit::Pressure> {

public:

  constexpr Stress() noexcept : DimensionalSymmetricDyadicQuantity<Unit::Pressure>() {}

  constexpr Stress(const Value::SymmetricDyadic& value, Unit::Pressure unit) noexcept : DimensionalSymmetricDyadicQuantity<Unit::Pressure>(value, unit) {}

  constexpr Stress(const StaticPressure& static_pressure) noexcept : Stress({-1.0 * static_pressure.value(), 0.0, 0.0, -1.0 * static_pressure.value(), 0.0, -1.0 * static_pressure.value()}) {}

  constexpr Traction traction(const Direction& direction) const noexcept {
    return {*this, direction};
  }

  constexpr bool operator==(const Stress& stress) const noexcept {
    return value_ == stress.value_;
  }

  constexpr bool operator!=(const Stress& stress) const noexcept {
    return value_ != stress.value_;
  }

  constexpr Stress operator+(const Stress& stress) const noexcept {
    return {value_ + stress.value_};
  }

  constexpr void operator+=(const Stress& stress) noexcept {
    value_ += stress.value_;
  }

  constexpr Stress operator-(const Stress& stress) const noexcept {
    return {value_ - stress.value_};
  }

  constexpr void operator-=(const Stress& stress) noexcept {
    value_ -= stress.value_;
  }

protected:

  constexpr Stress(const Value::SymmetricDyadic& value) noexcept : DimensionalSymmetricDyadicQuantity<Unit::Pressure>(value) {}

};

template <> constexpr bool sort(const Stress& stress_1, const Stress& stress_2) noexcept {
  return sort(stress_1.value(), stress_2.value());
}

constexpr Traction::Traction(const Stress& stress, const Direction& direction) noexcept : Traction({stress.value() * direction}) {}

constexpr Stress StaticPressure::stress() const noexcept {
  return {*this};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::Stress> {
  size_t operator()(const PhQ::Stress& stress) const {
    return hash<PhQ::Value::SymmetricDyadic>()(stress.value());
  }
};

} // namespace std
