// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Mass.hpp"
#include "Volume.hpp"
#include "Unit/MassDensity.hpp"

namespace PhQ {

// Forward declarations.
class DynamicPressure;
class DynamicViscosity;
class KinematicViscosity;
class ReynoldsNumber;
class SpecificIsobaricHeatCapacity;
class Speed;
class ThermalConductivity;
class ThermalDiffusivity;

class MassDensity : public DimensionalScalarQuantity<Unit::MassDensity> {

public:

  constexpr MassDensity() noexcept : DimensionalScalarQuantity<Unit::MassDensity>() {}

  constexpr MassDensity(double value, Unit::MassDensity unit) noexcept : DimensionalScalarQuantity<Unit::MassDensity>(value, unit) {}

  constexpr MassDensity(const Mass& mass, const Volume& volume) noexcept : MassDensity(mass.value() / volume.value()) {}

  constexpr MassDensity(const DynamicViscosity& dynamic_viscosity, const KinematicViscosity& kinematic_viscosity) noexcept;

  constexpr MassDensity(const ThermalDiffusivity& thermal_diffusivity, const ThermalConductivity& thermal_conductivity, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept;

  constexpr MassDensity(const DynamicPressure& dynamic_pressure, const Speed& speed) noexcept;

  constexpr MassDensity(const ReynoldsNumber& reynolds_number, const DynamicViscosity& dynamic_viscosity, const Speed& speed, const Length& length) noexcept;

  constexpr bool operator==(const MassDensity& mass_density) const noexcept {
    return value_ == mass_density.value_;
  }

  constexpr bool operator!=(const MassDensity& mass_density) const noexcept {
    return value_ != mass_density.value_;
  }

  constexpr bool operator<(const MassDensity& mass_density) const noexcept {
    return value_ < mass_density.value_;
  }

  constexpr bool operator<=(const MassDensity& mass_density) const noexcept {
    return value_ <= mass_density.value_;
  }

  constexpr bool operator>(const MassDensity& mass_density) const noexcept {
    return value_ > mass_density.value_;
  }

  constexpr bool operator>=(const MassDensity& mass_density) const noexcept {
    return value_ >= mass_density.value_;
  }

  constexpr MassDensity operator+(const MassDensity& mass_density) const noexcept {
    return {value_ + mass_density.value_};
  }

  constexpr void operator+=(const MassDensity& mass_density) noexcept {
    value_ += mass_density.value_;
  }

  constexpr MassDensity operator-(const MassDensity& mass_density) const noexcept {
    return {value_ - mass_density.value_};
  }

  constexpr void operator-=(const MassDensity& mass_density) noexcept {
    value_ -= mass_density.value_;
  }

  constexpr Mass operator*(const Volume& volume) const noexcept {
    return {*this, volume};
  }

  constexpr DynamicViscosity operator*(const KinematicViscosity& kinematic_viscosity) const noexcept;

protected:

  constexpr MassDensity(double value) noexcept : DimensionalScalarQuantity<Unit::MassDensity>(value) {}

};

template <> constexpr bool sort(const MassDensity& mass_density_1, const MassDensity& mass_density_2) noexcept {
  return sort(mass_density_1.value(), mass_density_2.value());
}

constexpr Volume::Volume(const MassDensity& mass_density, const Mass& mass) noexcept : Volume(mass.value() / mass_density.value()) {}

constexpr Mass::Mass(const MassDensity& mass_density, const Volume& volume) noexcept : Mass(mass_density.value() * volume.value()) {}

constexpr MassDensity Mass::operator/(const Volume& volume) const noexcept {
  return {*this, volume};
}

constexpr Mass Volume::operator*(const MassDensity& mass_density) const noexcept {
  return {mass_density, *this};
}

} // namespace PhQ
