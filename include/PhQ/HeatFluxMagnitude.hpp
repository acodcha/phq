// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

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

  HeatFluxMagnitude(double value, Unit::EnergyFlux unit) noexcept : DimensionalScalarQuantity<Unit::EnergyFlux>(value, unit) {}

  constexpr HeatFluxMagnitude(const ThermalConductivityScalar& thermal_conductivity_scalar, const TemperatureGradientMagnitude& temperature_gradient_magnitude) noexcept : HeatFluxMagnitude(-thermal_conductivity_scalar.Value() * temperature_gradient_magnitude.Value()) {}

  HeatFluxMagnitude(const HeatFlux& heat_flux) noexcept;

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

  HeatFluxMagnitude operator+(const HeatFluxMagnitude& heat_flux_magnitude) const noexcept {
    return {value_ + heat_flux_magnitude.value_};
  }

  constexpr void operator+=(const HeatFluxMagnitude& heat_flux_magnitude) noexcept {
    value_ += heat_flux_magnitude.value_;
  }

  HeatFluxMagnitude operator-(const HeatFluxMagnitude& heat_flux_magnitude) const noexcept {
    return {value_ - heat_flux_magnitude.value_};
  }

  constexpr void operator-=(const HeatFluxMagnitude& heat_flux_magnitude) noexcept {
    value_ -= heat_flux_magnitude.value_;
  }

  HeatFlux operator*(const Direction& direction) const noexcept;

protected:

  constexpr HeatFluxMagnitude(double value) noexcept : DimensionalScalarQuantity<Unit::EnergyFlux>(value) {}

};

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::HeatFluxMagnitude> {
  size_t operator()(const PhQ::HeatFluxMagnitude& heat_flux_magnitude) const {
    return hash<double>()(heat_flux_magnitude.Value());
  }
};

} // namespace std
