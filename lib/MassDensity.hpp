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
class DynamicViscosity;
class KinematicViscosity;

class MassDensity : public DimensionalScalarQuantity<Unit::MassDensity> {

public:

  constexpr MassDensity() noexcept : DimensionalScalarQuantity<Unit::MassDensity>() {}

  constexpr MassDensity(double value, Unit::MassDensity unit) noexcept : DimensionalScalarQuantity<Unit::MassDensity>(value, unit) {}

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

  constexpr Mass operator*(const Volume& volume) const noexcept {
    return {value_ * volume.value_};
  }

  constexpr DynamicViscosity operator*(const KinematicViscosity& kinematic_viscosity) const noexcept;

protected:

  constexpr MassDensity(double value) noexcept : DimensionalScalarQuantity<Unit::MassDensity>(value) {}

  friend class DynamicViscosity;
  friend class KinematicViscosity;
  friend class Mass;
  friend class Volume;

};

template <> constexpr bool sort(const MassDensity& mass_density_1, const MassDensity& mass_density_2) noexcept {
  return mass_density_1.value() < mass_density_2.value();
}

MassDensity Mass::operator/(const Volume& volume) const {
  if (volume.value_ != 0.0) {
    return {value_ / volume.value_};
  } else {
    throw std::runtime_error{"Division of " + print() + " by " + volume.print() + "."};
  }
}

constexpr Mass Volume::operator*(const MassDensity& mass_density) const noexcept {
  return {value_ * mass_density.value_};
}

} // namespace PhQ
