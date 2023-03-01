// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "HeatFluxMagnitude.hpp"
#include "TemperatureGradient.hpp"
#include "ThermalConductivity.hpp"

namespace PhQ {

class HeatFlux : public DimensionalVectorQuantity<Unit::EnergyFlux> {

public:

  constexpr HeatFlux() noexcept : DimensionalVectorQuantity<Unit::EnergyFlux>() {}

  HeatFlux(const Value::Vector& value, Unit::EnergyFlux unit) noexcept : DimensionalVectorQuantity<Unit::EnergyFlux>(value, unit) {}

  constexpr HeatFlux(const HeatFluxMagnitude& heat_flux_magnitude, const Direction& direction) noexcept : HeatFlux(heat_flux_magnitude.Value() * direction.Value()) {}

  constexpr HeatFlux(const ThermalConductivityScalar& thermal_conductivity_scalar, const TemperatureGradient& temperature_gradient) noexcept : HeatFlux(-thermal_conductivity_scalar.Value() * temperature_gradient.Value()) {}

  constexpr HeatFlux(const ThermalConductivity& thermal_conductivity, const TemperatureGradient& temperature_gradient) noexcept : HeatFlux(-1.0 * thermal_conductivity.Value() * temperature_gradient.Value()) {}

  HeatFluxMagnitude Magnitude() const noexcept {
    return {*this};
  }

  PhQ::Angle Angle(const HeatFlux& heat_flux) const noexcept {
    return {*this, heat_flux};
  }

  constexpr bool operator==(const HeatFlux& heat_flux) const noexcept {
    return value_ == heat_flux.value_;
  }

  constexpr bool operator!=(const HeatFlux& heat_flux) const noexcept {
    return value_ != heat_flux.value_;
  }

  HeatFlux operator+(const HeatFlux& heat_flux) const noexcept {
    return {value_ + heat_flux.value_};
  }

  constexpr void operator+=(const HeatFlux& heat_flux) noexcept {
    value_ += heat_flux.value_;
  }

  HeatFlux operator-(const HeatFlux& heat_flux) const noexcept {
    return {value_ - heat_flux.value_};
  }

  constexpr void operator-=(const HeatFlux& heat_flux) noexcept {
    value_ -= heat_flux.value_;
  }

protected:

  constexpr HeatFlux(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::EnergyFlux>(value) {}

};

Direction::Direction(const HeatFlux& heat_flux) noexcept : Direction(heat_flux.Value()) {}

Angle::Angle(const HeatFlux& heat_flux_1, const HeatFlux& heat_flux_2) noexcept : Angle(heat_flux_1.Value(), heat_flux_2.Value()) {}

HeatFluxMagnitude::HeatFluxMagnitude(const HeatFlux& heat_flux) noexcept : HeatFluxMagnitude(heat_flux.Value().Magnitude()) {}

HeatFlux Direction::operator*(const HeatFluxMagnitude& heat_flux_magnitude) const noexcept {
  return {heat_flux_magnitude, *this};
}

HeatFlux HeatFluxMagnitude::operator*(const Direction& direction) const noexcept {
  return {*this, direction};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::HeatFlux> {
  size_t operator()(const PhQ::HeatFlux& heat_flux) const {
    return hash<PhQ::Value::Vector>()(heat_flux.Value());
  }
};

} // namespace std
