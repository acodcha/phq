// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalSymmetricDyad.hpp"
#include "StressScalar.hpp"
#include "Traction.hpp"

namespace PhQ {

class Stress : public DimensionalSymmetricDyadQuantity<Unit::Pressure> {

public:

  constexpr Stress() noexcept : DimensionalSymmetricDyadQuantity<Unit::Pressure>() {}

  Stress(const Value::SymmetricDyad& value, Unit::Pressure unit) noexcept : DimensionalSymmetricDyadQuantity<Unit::Pressure>(value, unit) {}

  constexpr Stress(const StaticPressure& static_pressure) noexcept : Stress({-1.0 * static_pressure.Value(), 0.0, 0.0, -1.0 * static_pressure.Value(), 0.0, -1.0 * static_pressure.Value()}) {}

  Traction traction(const Direction& direction) const noexcept {
    return {*this, direction};
  }

  constexpr bool operator==(const Stress& stress) const noexcept {
    return value_ == stress.value_;
  }

  constexpr bool operator!=(const Stress& stress) const noexcept {
    return value_ != stress.value_;
  }

  Stress operator+(const Stress& stress) const noexcept {
    return {value_ + stress.value_};
  }

  constexpr void operator+=(const Stress& stress) noexcept {
    value_ += stress.value_;
  }

  Stress operator-(const Stress& stress) const noexcept {
    return {value_ - stress.value_};
  }

  constexpr void operator-=(const Stress& stress) noexcept {
    value_ -= stress.value_;
  }

protected:

  constexpr Stress(const Value::SymmetricDyad& value) noexcept : DimensionalSymmetricDyadQuantity<Unit::Pressure>(value) {}

};

constexpr Traction::Traction(const Stress& stress, const Direction& direction) noexcept : Traction({stress.Value() * direction}) {}

Stress StaticPressure::stress() const noexcept {
  return {*this};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::Stress> {
  size_t operator()(const PhQ::Stress& stress) const {
    return hash<PhQ::Value::SymmetricDyad>()(stress.Value());
  }
};

} // namespace std
