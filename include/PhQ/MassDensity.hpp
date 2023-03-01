// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

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
class ThermalConductivityScalar;
class ThermalDiffusivity;

class MassDensity : public DimensionalScalarQuantity<Unit::MassDensity> {

public:

  constexpr MassDensity() noexcept : DimensionalScalarQuantity<Unit::MassDensity>() {}

  MassDensity(double value, Unit::MassDensity unit) noexcept : DimensionalScalarQuantity<Unit::MassDensity>(value, unit) {}

  constexpr MassDensity(const Mass& mass, const Volume& volume) noexcept : MassDensity(mass.Value() / volume.Value()) {}

  constexpr MassDensity(const DynamicViscosity& dynamic_viscosity, const KinematicViscosity& kinematic_viscosity) noexcept;

  constexpr MassDensity(const ThermalDiffusivity& thermal_diffusivity, const ThermalConductivityScalar& thermal_conductivity_scalar, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept;

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

  MassDensity operator+(const MassDensity& mass_density) const noexcept {
    return {value_ + mass_density.value_};
  }

  constexpr void operator+=(const MassDensity& mass_density) noexcept {
    value_ += mass_density.value_;
  }

  MassDensity operator-(const MassDensity& mass_density) const noexcept {
    return {value_ - mass_density.value_};
  }

  constexpr void operator-=(const MassDensity& mass_density) noexcept {
    value_ -= mass_density.value_;
  }

  Mass operator*(const Volume& volume) const noexcept {
    return {*this, volume};
  }

  constexpr DynamicViscosity operator*(const KinematicViscosity& kinematic_viscosity) const noexcept;

protected:

  constexpr MassDensity(double value) noexcept : DimensionalScalarQuantity<Unit::MassDensity>(value) {}

};

constexpr Volume::Volume(const MassDensity& mass_density, const Mass& mass) noexcept : Volume(mass.Value() / mass_density.Value()) {}

constexpr Mass::Mass(const MassDensity& mass_density, const Volume& volume) noexcept : Mass(mass_density.Value() * volume.Value()) {}

constexpr MassDensity Mass::operator/(const Volume& volume) const noexcept {
  return {*this, volume};
}

constexpr Mass Volume::operator*(const MassDensity& mass_density) const noexcept {
  return {mass_density, *this};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::MassDensity> {
  size_t operator()(const PhQ::MassDensity& mass_density) const {
    return hash<double>()(mass_density.Value());
  }
};

} // namespace std
