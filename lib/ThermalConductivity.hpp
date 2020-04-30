// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/ThermalConductivity.hpp"

namespace PhQ {

class ThermalConductivity : public DimensionalScalarQuantity<Unit::ThermalConductivity> {

public:

  constexpr ThermalConductivity() noexcept : DimensionalScalarQuantity<Unit::ThermalConductivity>() {}

  constexpr ThermalConductivity(double value, Unit::ThermalConductivity unit) noexcept : DimensionalScalarQuantity<Unit::ThermalConductivity>(value, unit) {}

  constexpr bool operator==(const ThermalConductivity& thermal_conductivity) const noexcept {
    return value_ == thermal_conductivity.value_;
  }

  constexpr bool operator!=(const ThermalConductivity& thermal_conductivity) const noexcept {
    return value_ != thermal_conductivity.value_;
  }

  constexpr bool operator<(const ThermalConductivity& thermal_conductivity) const noexcept {
    return value_ < thermal_conductivity.value_;
  }

  constexpr bool operator<=(const ThermalConductivity& thermal_conductivity) const noexcept {
    return value_ <= thermal_conductivity.value_;
  }

  constexpr bool operator>(const ThermalConductivity& thermal_conductivity) const noexcept {
    return value_ > thermal_conductivity.value_;
  }

  constexpr bool operator>=(const ThermalConductivity& thermal_conductivity) const noexcept {
    return value_ >= thermal_conductivity.value_;
  }

  constexpr ThermalConductivity operator+(const ThermalConductivity& thermal_conductivity) const noexcept {
    return {value_ + thermal_conductivity.value_};
  }

  constexpr void operator+=(const ThermalConductivity& thermal_conductivity) noexcept {
    value_ += thermal_conductivity.value_;
  }

  constexpr ThermalConductivity operator-(const ThermalConductivity& thermal_conductivity) const noexcept {
    return {value_ - thermal_conductivity.value_};
  }

  constexpr void operator-=(const ThermalConductivity& thermal_conductivity) noexcept {
    value_ -= thermal_conductivity.value_;
  }

protected:

  constexpr ThermalConductivity(double value) noexcept : DimensionalScalarQuantity<Unit::ThermalConductivity>(value) {}

};

template <> constexpr bool sort(const ThermalConductivity& thermal_conductivity_1, const ThermalConductivity& thermal_conductivity_2) noexcept {
  return thermal_conductivity_1.value() < thermal_conductivity_2.value();
}

} // namespace PhQ
