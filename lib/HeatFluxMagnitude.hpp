// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "TemperatureGradientMagnitude.hpp"
#include "ThermalConductivityScalar.hpp"
#include "Unit/EnergyFlux.hpp"

namespace PhQ {

// Forward declaration.
class HeatFlux;

class HeatFluxMagnitude : public DimensionalScalarQuantity<Unit::EnergyFlux> {

public:

  constexpr HeatFluxMagnitude() noexcept : DimensionalScalarQuantity<Unit::EnergyFlux>() {}

  constexpr HeatFluxMagnitude(double value, Unit::EnergyFlux unit) noexcept : DimensionalScalarQuantity<Unit::EnergyFlux>(value, unit) {}

  constexpr HeatFluxMagnitude(const ThermalConductivityScalar& thermal_conductivity_scalar, const TemperatureGradientMagnitude& temperature_gradient_magnitude) noexcept : HeatFluxMagnitude(-thermal_conductivity_scalar.value() * temperature_gradient_magnitude.value()) {}

  constexpr HeatFluxMagnitude(const HeatFlux& heat_flux) noexcept;

  constexpr bool operator==(const HeatFluxMagnitude& heat_flux_magnitude) const noexcept {
    return value_ == heat_flux_magnitude.value_;
  }

  constexpr bool operator!=(const HeatFluxMagnitude& heat_flux_magnitude) const noexcept {
    return value_ != heat_flux_magnitude.value_;
  }

  constexpr bool operator<(const HeatFluxMagnitude& heat_flux_magnitude) const noexcept {
    return value_ < heat_flux_magnitude.value_;
  }

  constexpr bool operator<=(const HeatFluxMagnitude& heat_flux_magnitude) const noexcept {
    return value_ <= heat_flux_magnitude.value_;
  }

  constexpr bool operator>(const HeatFluxMagnitude& heat_flux_magnitude) const noexcept {
    return value_ > heat_flux_magnitude.value_;
  }

  constexpr bool operator>=(const HeatFluxMagnitude& heat_flux_magnitude) const noexcept {
    return value_ >= heat_flux_magnitude.value_;
  }

  constexpr HeatFluxMagnitude operator+(const HeatFluxMagnitude& heat_flux_magnitude) const noexcept {
    return {value_ + heat_flux_magnitude.value_};
  }

  constexpr void operator+=(const HeatFluxMagnitude& heat_flux_magnitude) noexcept {
    value_ += heat_flux_magnitude.value_;
  }

  constexpr HeatFluxMagnitude operator-(const HeatFluxMagnitude& heat_flux_magnitude) const noexcept {
    return {value_ - heat_flux_magnitude.value_};
  }

  constexpr void operator-=(const HeatFluxMagnitude& heat_flux_magnitude) noexcept {
    value_ -= heat_flux_magnitude.value_;
  }

  constexpr HeatFlux operator*(const Direction& direction) const noexcept;

protected:

  constexpr HeatFluxMagnitude(double value) noexcept : DimensionalScalarQuantity<Unit::EnergyFlux>(value) {}

};

template <> constexpr bool sort(const HeatFluxMagnitude& heat_flux_magnitude_1, const HeatFluxMagnitude& heat_flux_magnitude_2) noexcept {
  return sort(heat_flux_magnitude_1.value(), heat_flux_magnitude_2.value());
}

} // namespace PhQ
