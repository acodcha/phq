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

  constexpr ReynoldsNumber(const DynamicViscosity& dynamic_viscosity, const MassDensity& mass_density, const Speed& speed, const Length& length) noexcept : ReynoldsNumber(mass_density.value() * speed.value() * length.value() / dynamic_viscosity.value()) {}

  constexpr ReynoldsNumber(const KinematicViscosity& kinematic_viscosity, const Speed& speed, const Length& length) noexcept : ReynoldsNumber(speed.value() * length.value() / kinematic_viscosity.value()) {}

  constexpr DynamicViscosity dynamic_viscosity(const MassDensity& mass_density, const Speed& speed, const Length& length) const noexcept {
    return {*this, mass_density, speed, length};
  }

  constexpr KinematicViscosity kinematic_viscosity(const Speed& speed, const Length& length) const noexcept {
    return {*this, speed, length};
  }

  constexpr MassDensity mass_density(const DynamicViscosity& dynamic_viscosity, const Speed& speed, const Length& length) const noexcept {
    return {*this, dynamic_viscosity, speed, length};
  }

  constexpr Speed speed(const DynamicViscosity& dynamic_viscosity, const MassDensity& mass_density, const Length& length) const noexcept {
    return {*this, dynamic_viscosity, mass_density, length};
  }

  constexpr Speed speed(const KinematicViscosity& kinematic_viscosity, const Length& length) const noexcept {
    return {*this, kinematic_viscosity, length};
  }

  constexpr Length length(const DynamicViscosity& dynamic_viscosity, const MassDensity& mass_density, const Speed& speed) const noexcept {
    return {*this, dynamic_viscosity, mass_density, speed};
  }

  constexpr Length length(const KinematicViscosity& kinematic_viscosity, const Speed& speed) const noexcept {
    return {*this, kinematic_viscosity, speed};
  }

};

constexpr Length::Length(const ReynoldsNumber& reynolds_number, const DynamicViscosity& dynamic_viscosity, const MassDensity& mass_density, const Speed& speed) noexcept : Length(reynolds_number.value() * dynamic_viscosity.value() / (mass_density.value() * speed.value())) {}

constexpr Length::Length(const ReynoldsNumber& reynolds_number, const KinematicViscosity& kinematic_viscosity, const Speed& speed) noexcept : Length(reynolds_number.value() * kinematic_viscosity.value() / speed.value()) {}

constexpr Speed::Speed(const ReynoldsNumber& reynolds_number, const DynamicViscosity& dynamic_viscosity, const MassDensity& mass_density, const Length& length) noexcept : Speed(reynolds_number.value() * dynamic_viscosity.value() / (mass_density.value() * length.value())) {}

constexpr Speed::Speed(const ReynoldsNumber& reynolds_number, const KinematicViscosity& kinematic_viscosity, const Length& length) noexcept : Speed(reynolds_number.value() * kinematic_viscosity.value() / length.value()) {}

constexpr MassDensity::MassDensity(const ReynoldsNumber& reynolds_number, const DynamicViscosity& dynamic_viscosity, const Speed& speed, const Length& length) noexcept : MassDensity(reynolds_number.value() * dynamic_viscosity.value() / (speed.value() * length.value())) {}

constexpr KinematicViscosity::KinematicViscosity(const ReynoldsNumber& reynolds_number, const Speed& speed, const Length& length) noexcept : KinematicViscosity(speed.value() * length.value() / reynolds_number.value()) {}

constexpr DynamicViscosity::DynamicViscosity(const ReynoldsNumber& reynolds_number, const MassDensity& mass_density, const Speed& speed, const Length& length) noexcept : DynamicViscosity(mass_density.value() * speed.value() * length.value() / reynolds_number.value()) {}

} // namespace PhQ

constexpr PhQ::ReynoldsNumber operator+(double real, const PhQ::ReynoldsNumber& reynolds_number) noexcept {
  return {real + reynolds_number.value()};
}

constexpr PhQ::ReynoldsNumber operator-(double real, const PhQ::ReynoldsNumber& reynolds_number) noexcept {
  return {real - reynolds_number.value()};
}

constexpr PhQ::ReynoldsNumber operator*(double real, const PhQ::ReynoldsNumber& reynolds_number) noexcept {
  return {real * reynolds_number.value()};
}

constexpr double operator/(double real, const PhQ::ReynoldsNumber& reynolds_number) noexcept {
  return real / reynolds_number.value();
}

namespace std {

template <> struct hash<PhQ::ReynoldsNumber> {
  size_t operator()(const PhQ::ReynoldsNumber& reynolds_number) const {
    return hash<double>()(reynolds_number.value());
  }
};

} // namespace std
