// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "DynamicViscosity.hpp"
#include "MassDensity.hpp"
#include "Quantity/DimensionlessScalar.hpp"
#include "Speed.hpp"

namespace PhQ {

class ReynoldsNumber : public DimensionlessScalarQuantity {

public:

  constexpr ReynoldsNumber() noexcept : DimensionlessScalarQuantity() {}

  constexpr ReynoldsNumber(double value) noexcept : DimensionlessScalarQuantity(value) {}

  constexpr ReynoldsNumber(const DynamicViscosity& dynamic_viscosity, const MassDensity& mass_density, const Speed& speed, const Length& length) noexcept : ReynoldsNumber(mass_density.Value() * speed.Value() * length.Value() / dynamic_viscosity.Value()) {}

  constexpr ReynoldsNumber(const KinematicViscosity& kinematic_viscosity, const Speed& speed, const Length& length) noexcept : ReynoldsNumber(speed.Value() * length.Value() / kinematic_viscosity.Value()) {}

  PhQ::DynamicViscosity DynamicViscosity(const PhQ::MassDensity& mass_density, const PhQ::Speed& speed, const PhQ::Length& length) const noexcept {
    return {*this, mass_density, speed, length};
  }

  PhQ::KinematicViscosity KinematicViscosity(const PhQ::Speed& speed, const PhQ::Length& length) const noexcept {
    return {*this, speed, length};
  }

  PhQ::MassDensity MassDensity(const PhQ::DynamicViscosity& dynamic_viscosity, const PhQ::Speed& speed, const PhQ::Length& length) const noexcept {
    return {*this, dynamic_viscosity, speed, length};
  }

  PhQ::Speed Speed(const PhQ::DynamicViscosity& dynamic_viscosity, const PhQ::MassDensity& mass_density, const PhQ::Length& length) const noexcept {
    return {*this, dynamic_viscosity, mass_density, length};
  }

  PhQ::Speed Speed(const PhQ::KinematicViscosity& kinematic_viscosity, const PhQ::Length& length) const noexcept {
    return {*this, kinematic_viscosity, length};
  }

  PhQ::Length Length(const PhQ::DynamicViscosity& dynamic_viscosity, const PhQ::MassDensity& mass_density, const PhQ::Speed& speed) const noexcept {
    return {*this, dynamic_viscosity, mass_density, speed};
  }

  PhQ::Length Length(const PhQ::KinematicViscosity& kinematic_viscosity, const PhQ::Speed& speed) const noexcept {
    return {*this, kinematic_viscosity, speed};
  }

};

constexpr Length::Length(const ReynoldsNumber& reynolds_number, const DynamicViscosity& dynamic_viscosity, const MassDensity& mass_density, const Speed& speed) noexcept : Length(reynolds_number.Value() * dynamic_viscosity.Value() / (mass_density.Value() * speed.Value())) {}

constexpr Length::Length(const ReynoldsNumber& reynolds_number, const KinematicViscosity& kinematic_viscosity, const Speed& speed) noexcept : Length(reynolds_number.Value() * kinematic_viscosity.Value() / speed.Value()) {}

constexpr Speed::Speed(const ReynoldsNumber& reynolds_number, const DynamicViscosity& dynamic_viscosity, const MassDensity& mass_density, const Length& length) noexcept : Speed(reynolds_number.Value() * dynamic_viscosity.Value() / (mass_density.Value() * length.Value())) {}

constexpr Speed::Speed(const ReynoldsNumber& reynolds_number, const KinematicViscosity& kinematic_viscosity, const Length& length) noexcept : Speed(reynolds_number.Value() * kinematic_viscosity.Value() / length.Value()) {}

constexpr MassDensity::MassDensity(const ReynoldsNumber& reynolds_number, const DynamicViscosity& dynamic_viscosity, const Speed& speed, const Length& length) noexcept : MassDensity(reynolds_number.Value() * dynamic_viscosity.Value() / (speed.Value() * length.Value())) {}

constexpr KinematicViscosity::KinematicViscosity(const ReynoldsNumber& reynolds_number, const Speed& speed, const Length& length) noexcept : KinematicViscosity(speed.Value() * length.Value() / reynolds_number.Value()) {}

constexpr DynamicViscosity::DynamicViscosity(const ReynoldsNumber& reynolds_number, const MassDensity& mass_density, const Speed& speed, const Length& length) noexcept : DynamicViscosity(mass_density.Value() * speed.Value() * length.Value() / reynolds_number.Value()) {}

} // namespace PhQ

PhQ::ReynoldsNumber operator+(double real, const PhQ::ReynoldsNumber& reynolds_number) noexcept {
  return {real + reynolds_number.Value()};
}

PhQ::ReynoldsNumber operator-(double real, const PhQ::ReynoldsNumber& reynolds_number) noexcept {
  return {real - reynolds_number.Value()};
}

PhQ::ReynoldsNumber operator*(double real, const PhQ::ReynoldsNumber& reynolds_number) noexcept {
  return {real * reynolds_number.Value()};
}

constexpr double operator/(double real, const PhQ::ReynoldsNumber& reynolds_number) noexcept {
  return real / reynolds_number.Value();
}

namespace std {

template <> struct hash<PhQ::ReynoldsNumber> {
  size_t operator()(const PhQ::ReynoldsNumber& reynolds_number) const {
    return hash<double>()(reynolds_number.Value());
  }
};

} // namespace std
