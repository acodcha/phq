// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "HeatFluxMagnitude.hpp"
#include "TemperatureGradient.hpp"
#include "ThermalConductivity.hpp"

namespace PhQ {

class HeatFlux : public DimensionalVectorQuantity<Unit::EnergyFlux> {

public:

  constexpr HeatFlux() noexcept : DimensionalVectorQuantity<Unit::EnergyFlux>() {}

  constexpr HeatFlux(const Value::Vector& value, Unit::EnergyFlux unit) noexcept : DimensionalVectorQuantity<Unit::EnergyFlux>(value, unit) {}

  constexpr HeatFlux(const HeatFluxMagnitude& heat_flux_magnitude, const Direction& direction) noexcept : HeatFlux({heat_flux_magnitude.value() * direction.x(), heat_flux_magnitude.value() * direction.y(), heat_flux_magnitude.value() * direction.z()}) {}

  constexpr HeatFlux(const ThermalConductivityScalar& thermal_conductivity_scalar, const TemperatureGradient& temperature_gradient) noexcept : HeatFlux(-thermal_conductivity_scalar.value() * temperature_gradient.value()) {}

  constexpr HeatFlux(const ThermalConductivity& thermal_conductivity, const TemperatureGradient& temperature_gradient) noexcept : HeatFlux(-1.0 * thermal_conductivity.value() * temperature_gradient.value()) {}

  constexpr HeatFluxMagnitude magnitude() const noexcept {
    return {*this};
  }

  constexpr Angle angle(const HeatFlux& heat_flux) const noexcept {
    return {*this, heat_flux};
  }

  constexpr bool operator==(const HeatFlux& heat_flux) const noexcept {
    return value_ == heat_flux.value_;
  }

  constexpr bool operator!=(const HeatFlux& heat_flux) const noexcept {
    return value_ != heat_flux.value_;
  }

  constexpr HeatFlux operator+(const HeatFlux& heat_flux) const noexcept {
    return {value_ + heat_flux.value_};
  }

  constexpr void operator+=(const HeatFlux& heat_flux) noexcept {
    value_ += heat_flux.value_;
  }

  constexpr HeatFlux operator-(const HeatFlux& heat_flux) const noexcept {
    return {value_ - heat_flux.value_};
  }

  constexpr void operator-=(const HeatFlux& heat_flux) noexcept {
    value_ -= heat_flux.value_;
  }

protected:

  constexpr HeatFlux(const Value::Vector& value) noexcept : DimensionalVectorQuantity<Unit::EnergyFlux>(value) {}

};

template <> constexpr bool sort(const HeatFlux& heat_flux_1, const HeatFlux& heat_flux_2) noexcept {
  return sort(heat_flux_1.value(), heat_flux_2.value());
}

constexpr Direction::Direction(const HeatFlux& heat_flux) : Direction(heat_flux.value()) {}

constexpr Angle::Angle(const HeatFlux& heat_flux_1, const HeatFlux& heat_flux_2) noexcept : Angle(heat_flux_1.value(), heat_flux_2.value()) {}

constexpr HeatFluxMagnitude::HeatFluxMagnitude(const HeatFlux& heat_flux) noexcept : HeatFluxMagnitude(heat_flux.value().magnitude()) {}

constexpr HeatFlux Direction::operator*(const HeatFluxMagnitude& heat_flux_magnitude) const noexcept {
  return {heat_flux_magnitude, *this};
}

constexpr HeatFlux HeatFluxMagnitude::operator*(const Direction& direction) const noexcept {
  return {*this, direction};
}

} // namespace PhQ
