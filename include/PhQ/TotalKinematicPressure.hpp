// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "DynamicKinematicPressure.hpp"
#include "TotalPressure.hpp"

namespace PhQ {

class TotalKinematicPressure : public DimensionalScalarQuantity<Unit::SpecificEnergy> {

public:

  constexpr TotalKinematicPressure() noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>() {}

  constexpr TotalKinematicPressure(double value, Unit::SpecificEnergy unit) noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>(value, unit) {}

  constexpr TotalKinematicPressure(const DynamicKinematicPressure& dynamic_kinematic_pressure, const StaticKinematicPressure& static_kinematic_pressure) noexcept : TotalKinematicPressure(dynamic_kinematic_pressure.value() + static_kinematic_pressure.value()) {}

  constexpr TotalKinematicPressure(const TotalPressure& total_pressure, const MassDensity& mass_density) noexcept : TotalKinematicPressure(total_pressure.value() / mass_density.value()) {}

  constexpr bool operator==(const TotalKinematicPressure& total_kinematic_pressure) const noexcept {
    return value_ == total_kinematic_pressure.value_;
  }

  constexpr bool operator!=(const TotalKinematicPressure& total_kinematic_pressure) const noexcept {
    return value_ != total_kinematic_pressure.value_;
  }

  constexpr bool operator<(const TotalKinematicPressure& total_kinematic_pressure) const noexcept {
    return value_ < total_kinematic_pressure.value_;
  }

  constexpr bool operator<=(const TotalKinematicPressure& total_kinematic_pressure) const noexcept {
    return value_ <= total_kinematic_pressure.value_;
  }

  constexpr bool operator>(const TotalKinematicPressure& total_kinematic_pressure) const noexcept {
    return value_ > total_kinematic_pressure.value_;
  }

  constexpr bool operator>=(const TotalKinematicPressure& total_kinematic_pressure) const noexcept {
    return value_ >= total_kinematic_pressure.value_;
  }

  constexpr TotalKinematicPressure operator+(const TotalKinematicPressure& total_kinematic_pressure) const noexcept {
    return {value_ + total_kinematic_pressure.value_};
  }

  constexpr void operator+=(const TotalKinematicPressure& total_kinematic_pressure) noexcept {
    value_ += total_kinematic_pressure.value_;
  }

  constexpr TotalKinematicPressure operator-(const TotalKinematicPressure& total_kinematic_pressure) const noexcept {
    return {value_ - total_kinematic_pressure.value_};
  }

  constexpr DynamicKinematicPressure operator-(const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
    return {*this, static_kinematic_pressure};
  }

  constexpr StaticKinematicPressure operator-(const DynamicKinematicPressure& dynamic_kinematic_pressure) const noexcept {
    return {*this, dynamic_kinematic_pressure};
  }

  constexpr void operator-=(const TotalKinematicPressure& total_kinematic_pressure) noexcept {
    value_ -= total_kinematic_pressure.value_;
  }

protected:

  constexpr TotalKinematicPressure(double value) noexcept : DimensionalScalarQuantity<Unit::SpecificEnergy>(value) {}

};

template <> constexpr bool sort(const TotalKinematicPressure& total_kinematic_pressure_1, const TotalKinematicPressure& total_kinematic_pressure_2) noexcept {
  return sort(total_kinematic_pressure_1.value(), total_kinematic_pressure_2.value());
}

constexpr TotalPressure::TotalPressure(const TotalKinematicPressure& total_kinematic_pressure, const MassDensity& mass_density) noexcept : TotalPressure(total_kinematic_pressure.value() * mass_density.value()) {}

constexpr StaticKinematicPressure::StaticKinematicPressure(const TotalKinematicPressure& total_kinematic_pressure, const DynamicKinematicPressure& dynamic_kinematic_pressure) noexcept : StaticKinematicPressure(total_kinematic_pressure.value() - dynamic_kinematic_pressure.value()) {}

constexpr DynamicKinematicPressure::DynamicKinematicPressure(const TotalKinematicPressure& total_kinematic_pressure, const StaticKinematicPressure& static_kinematic_pressure) noexcept : DynamicKinematicPressure(total_kinematic_pressure.value() - static_kinematic_pressure.value()) {}

constexpr TotalKinematicPressure StaticKinematicPressure::operator+(const DynamicKinematicPressure& dynamic_kinematic_pressure) const noexcept {
  return {dynamic_kinematic_pressure, *this};
}

constexpr TotalKinematicPressure DynamicKinematicPressure::operator+(const StaticKinematicPressure& static_kinematic_pressure) const noexcept {
  return {*this, static_kinematic_pressure};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::TotalKinematicPressure> {
  size_t operator()(const PhQ::TotalKinematicPressure& total_kinematic_pressure) const {
    return hash<double>()(total_kinematic_pressure.value());
  }
};

} // namespace std
