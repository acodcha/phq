// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "ForceMagnitude.hpp"
#include "PressureDifference.hpp"

namespace PhQ {

// Forward declarations.
class Direction;
class DynamicPressure;
class StaticKinematicPressure;
class Stress;
class TotalPressure;
class Traction;

class StaticPressure : public DimensionalScalarQuantity<Unit::Pressure> {

public:

  constexpr StaticPressure() noexcept : DimensionalScalarQuantity<Unit::Pressure>() {}

  StaticPressure(double value, Unit::Pressure unit) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr StaticPressure(const ForceMagnitude& force_magnitude, const Area& area) noexcept : StaticPressure(force_magnitude.Value() / area.Value()) {}

  constexpr StaticPressure(const Traction& traction) noexcept;

  constexpr StaticPressure(const TotalPressure& total_pressure, const DynamicPressure& dynamic_pressure) noexcept;

  constexpr StaticPressure(const StaticKinematicPressure& static_kinematic_pressure, const MassDensity& mass_density) noexcept;

  constexpr Stress stress() const noexcept;

  constexpr bool operator==(const StaticPressure& static_pressure) const noexcept {
    return value_ == static_pressure.value_;
  }

  constexpr bool operator!=(const StaticPressure& static_pressure) const noexcept {
    return value_ != static_pressure.value_;
  }

  constexpr bool operator<(const StaticPressure& static_pressure) const noexcept {
    return value_ < static_pressure.value_;
  }

  constexpr bool operator<=(const StaticPressure& static_pressure) const noexcept {
    return value_ <= static_pressure.value_;
  }

  constexpr bool operator>(const StaticPressure& static_pressure) const noexcept {
    return value_ > static_pressure.value_;
  }

  constexpr bool operator>=(const StaticPressure& static_pressure) const noexcept {
    return value_ >= static_pressure.value_;
  }

  StaticPressure operator+(const StaticPressure& static_pressure) const noexcept {
    return {value_ + static_pressure.value_};
  }

  StaticPressure operator+(const PressureDifference& pressure_difference) const noexcept {
    return {value_ + pressure_difference.Value()};
  }

  constexpr TotalPressure operator+(const DynamicPressure& dynamic_pressure) const noexcept;

  constexpr void operator+=(const StaticPressure& static_pressure) noexcept {
    value_ += static_pressure.value_;
  }

  constexpr void operator+=(const PressureDifference& pressure_difference) noexcept {
    value_ += pressure_difference.Value();
  }

  PressureDifference operator-(const StaticPressure& static_pressure) const noexcept {
    return {value_ - static_pressure.value_};
  }

  StaticPressure operator-(const PressureDifference& pressure_difference) const noexcept {
    return {value_ - pressure_difference.Value()};
  }

  constexpr void operator-=(const StaticPressure& static_pressure) noexcept {
    value_ -= static_pressure.value_;
  }

  constexpr void operator-=(const PressureDifference& pressure_difference) noexcept {
    value_ -= pressure_difference.Value();
  }

  ForceMagnitude operator*(const Area& area) const noexcept {
    return {*this, area};
  }

  constexpr Traction operator*(const Direction& direction) const noexcept;

  constexpr StaticKinematicPressure operator/(const MassDensity& mass_density) const noexcept;

protected:

  constexpr StaticPressure(double value) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value) {}

  friend class PressureDifference;

};

constexpr Area::Area(const StaticPressure& static_pressure, const ForceMagnitude& force_magnitude) noexcept : Area(force_magnitude.Value() / static_pressure.Value()) {}

constexpr ForceMagnitude::ForceMagnitude(const StaticPressure& static_pressure, const Area& area) noexcept : ForceMagnitude(static_pressure.Value() * area.Value()) {}

constexpr ForceMagnitude Area::operator*(const StaticPressure& static_pressure) const noexcept {
  return {static_pressure, *this};
}

constexpr StaticPressure ForceMagnitude::operator/(const Area& area) const noexcept {
  return {*this, area};
}

constexpr StaticPressure PressureDifference::operator+(const StaticPressure& static_pressure) const noexcept {
  return {value_ + static_pressure.Value()};
}

constexpr StaticPressure PressureDifference::operator-(const StaticPressure& static_pressure) const noexcept {
  return {value_ - static_pressure.Value()};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::StaticPressure> {
  size_t operator()(const PhQ::StaticPressure& static_pressure) const {
    return hash<double>()(static_pressure.Value());
  }
};

} // namespace std
