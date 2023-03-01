// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "DynamicPressure.hpp"

namespace PhQ {

class TotalPressure : public DimensionalScalarQuantity<Unit::Pressure> {

public:

  constexpr TotalPressure() noexcept : DimensionalScalarQuantity<Unit::Pressure>() {}

  TotalPressure(double value, Unit::Pressure unit) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  constexpr TotalPressure(const DynamicPressure& dynamic_pressure, const StaticPressure& static_pressure) noexcept : TotalPressure(dynamic_pressure.Value() + static_pressure.Value()) {}

  constexpr TotalPressure(const TotalKinematicPressure& total_kinematic_pressure, const MassDensity& mass_density) noexcept;

  constexpr bool operator==(const TotalPressure& total_pressure) const noexcept {
    return value_ == total_pressure.value_;
  }

  constexpr bool operator!=(const TotalPressure& total_pressure) const noexcept {
    return value_ != total_pressure.value_;
  }

  constexpr bool operator<(const TotalPressure& total_pressure) const noexcept {
    return value_ < total_pressure.value_;
  }

  constexpr bool operator<=(const TotalPressure& total_pressure) const noexcept {
    return value_ <= total_pressure.value_;
  }

  constexpr bool operator>(const TotalPressure& total_pressure) const noexcept {
    return value_ > total_pressure.value_;
  }

  constexpr bool operator>=(const TotalPressure& total_pressure) const noexcept {
    return value_ >= total_pressure.value_;
  }

  TotalPressure operator+(const TotalPressure& total_pressure) const noexcept {
    return {value_ + total_pressure.value_};
  }

  constexpr void operator+=(const TotalPressure& total_pressure) noexcept {
    value_ += total_pressure.value_;
  }

  TotalPressure operator-(const TotalPressure& total_pressure) const noexcept {
    return {value_ - total_pressure.value_};
  }

  DynamicPressure operator-(const StaticPressure& static_pressure) const noexcept {
    return {*this, static_pressure};
  }

  StaticPressure operator-(const DynamicPressure& dynamic_pressure) const noexcept {
    return {*this, dynamic_pressure};
  }

  constexpr void operator-=(const TotalPressure& total_pressure) noexcept {
    value_ -= total_pressure.value_;
  }

protected:

  constexpr TotalPressure(double value) noexcept : DimensionalScalarQuantity<Unit::Pressure>(value) {}

};

constexpr StaticPressure::StaticPressure(const TotalPressure& total_pressure, const DynamicPressure& dynamic_pressure) noexcept : StaticPressure(total_pressure.Value() - dynamic_pressure.Value()) {}

constexpr DynamicPressure::DynamicPressure(const TotalPressure& total_pressure, const StaticPressure& static_pressure) noexcept : DynamicPressure(total_pressure.Value() - static_pressure.Value()) {}

constexpr TotalPressure StaticPressure::operator+(const DynamicPressure& dynamic_pressure) const noexcept {
  return {dynamic_pressure, *this};
}

constexpr TotalPressure DynamicPressure::operator+(const StaticPressure& static_pressure) const noexcept {
  return {*this, static_pressure};
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::TotalPressure> {
  size_t operator()(const PhQ::TotalPressure& total_pressure) const {
    return hash<double>()(total_pressure.Value());
  }
};

} // namespace std
