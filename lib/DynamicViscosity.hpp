// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "KinematicViscosity.hpp"
#include "MassDensity.hpp"
#include "Unit/DynamicViscosity.hpp"

namespace PhQ {

class DynamicViscosity : public DimensionalScalarQuantity<Unit::DynamicViscosity> {

public:

  constexpr DynamicViscosity() noexcept : DimensionalScalarQuantity<Unit::DynamicViscosity>() {}

  constexpr DynamicViscosity(double value, Unit::DynamicViscosity unit) noexcept : DimensionalScalarQuantity<Unit::DynamicViscosity>(value, unit) {}

  constexpr bool operator==(const DynamicViscosity& dynamic_viscosity) const noexcept {
    return value_ == dynamic_viscosity.value_;
  }

  constexpr bool operator!=(const DynamicViscosity& dynamic_viscosity) const noexcept {
    return value_ != dynamic_viscosity.value_;
  }

  constexpr bool operator<(const DynamicViscosity& dynamic_viscosity) const noexcept {
    return value_ < dynamic_viscosity.value_;
  }

  constexpr bool operator<=(const DynamicViscosity& dynamic_viscosity) const noexcept {
    return value_ <= dynamic_viscosity.value_;
  }

  constexpr bool operator>(const DynamicViscosity& dynamic_viscosity) const noexcept {
    return value_ > dynamic_viscosity.value_;
  }

  constexpr bool operator>=(const DynamicViscosity& dynamic_viscosity) const noexcept {
    return value_ >= dynamic_viscosity.value_;
  }

  constexpr DynamicViscosity operator+(const DynamicViscosity& dynamic_viscosity) const noexcept {
    return {value_ + dynamic_viscosity.value_};
  }

  constexpr void operator+=(const DynamicViscosity& dynamic_viscosity) noexcept {
    value_ += dynamic_viscosity.value_;
  }

  constexpr DynamicViscosity operator-(const DynamicViscosity& dynamic_viscosity) const noexcept {
    return {value_ - dynamic_viscosity.value_};
  }

  constexpr void operator-=(const DynamicViscosity& dynamic_viscosity) noexcept {
    value_ -= dynamic_viscosity.value_;
  }

  constexpr KinematicViscosity operator/(const MassDensity& mass_density) const noexcept {
    return {value_ / mass_density.value_};
  }

  constexpr MassDensity operator/(const KinematicViscosity& kinematic_viscosity) const noexcept {
    return {value_ / kinematic_viscosity.value_};
  }

protected:

  constexpr DynamicViscosity(double value) noexcept : DimensionalScalarQuantity<Unit::DynamicViscosity>(value) {}

  friend class KinematicViscosity;
  friend class MassDensity;

};

template <> constexpr bool sort(const DynamicViscosity& dynamic_viscosity_1, const DynamicViscosity& dynamic_viscosity_2) noexcept {
  return dynamic_viscosity_1.value() < dynamic_viscosity_2.value();
}

constexpr DynamicViscosity KinematicViscosity::operator*(const MassDensity& mass_density) const noexcept {
  return {value_ * mass_density.value_};
}

constexpr DynamicViscosity MassDensity::operator*(const KinematicViscosity& kinematic_viscosity) const noexcept {
  return {value_ * kinematic_viscosity.value_};
}

} // namespace PhQ
