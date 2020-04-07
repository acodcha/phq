// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Diffusivity.hpp"

namespace PhQ {

class ThermalDiffusivity : public DimensionalScalarQuantity<Unit::Diffusivity> {

public:

  constexpr ThermalDiffusivity() noexcept : DimensionalScalarQuantity<Unit::Diffusivity>() {}

  constexpr ThermalDiffusivity(double value, Unit::Diffusivity unit) noexcept : DimensionalScalarQuantity<Unit::Diffusivity>(value, unit) {}

  constexpr bool operator==(const ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return value_ == thermal_diffusivity.value_;
  }

  constexpr bool operator!=(const ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return value_ != thermal_diffusivity.value_;
  }

  constexpr bool operator<(const ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return value_ < thermal_diffusivity.value_;
  }

  constexpr bool operator<=(const ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return value_ <= thermal_diffusivity.value_;
  }

  constexpr bool operator>(const ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return value_ > thermal_diffusivity.value_;
  }

  constexpr bool operator>=(const ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return value_ >= thermal_diffusivity.value_;
  }

  constexpr ThermalDiffusivity operator+(const ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return {value_ + thermal_diffusivity.value_};
  }

  constexpr void operator+=(const ThermalDiffusivity& thermal_diffusivity) noexcept {
    value_ += thermal_diffusivity.value_;
  }

  constexpr ThermalDiffusivity operator-(const ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return {value_ - thermal_diffusivity.value_};
  }

  constexpr void operator-=(const ThermalDiffusivity& thermal_diffusivity) noexcept {
    value_ -= thermal_diffusivity.value_;
  }

protected:

  constexpr ThermalDiffusivity(double value) noexcept : DimensionalScalarQuantity<Unit::Diffusivity>(value) {}

};

} // namespace PhQ
