// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalSymmetricDyad.hpp"
#include "ThermalConductivityScalar.hpp"

namespace PhQ {

class ThermalConductivity : public DimensionalSymmetricDyadQuantity<Unit::ThermalConductivity> {

public:

  constexpr ThermalConductivity() noexcept : DimensionalSymmetricDyadQuantity<Unit::ThermalConductivity>() {}

  ThermalConductivity(const Value::SymmetricDyad& value, Unit::ThermalConductivity unit) noexcept : DimensionalSymmetricDyadQuantity<Unit::ThermalConductivity>(value, unit) {}

  constexpr ThermalConductivity(const ThermalConductivityScalar& thermal_conductivity_scalar) noexcept : ThermalConductivity({thermal_conductivity_scalar.Value(), 0.0, 0.0, thermal_conductivity_scalar.Value(), 0.0, thermal_conductivity_scalar.Value()}) {}

  constexpr bool operator==(const ThermalConductivity& thermal_conductivity) const noexcept {
    return value_ == thermal_conductivity.value_;
  }

  constexpr bool operator!=(const ThermalConductivity& thermal_conductivity) const noexcept {
    return value_ != thermal_conductivity.value_;
  }

  ThermalConductivity operator+(const ThermalConductivity& thermal_conductivity) const noexcept {
    return {value_ + thermal_conductivity.value_};
  }

  constexpr void operator+=(const ThermalConductivity& thermal_conductivity) noexcept {
    value_ += thermal_conductivity.value_;
  }

  ThermalConductivity operator-(const ThermalConductivity& thermal_conductivity) const noexcept {
    return {value_ - thermal_conductivity.value_};
  }

  constexpr void operator-=(const ThermalConductivity& thermal_conductivity) noexcept {
    value_ -= thermal_conductivity.value_;
  }

protected:

  constexpr ThermalConductivity(const Value::SymmetricDyad& value) noexcept : DimensionalSymmetricDyadQuantity<Unit::ThermalConductivity>(value) {}

};

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::ThermalConductivity> {
  size_t operator()(const PhQ::ThermalConductivity& thermal_conductivity) const {
    return hash<PhQ::Value::SymmetricDyad>()(thermal_conductivity.Value());
  }
};

} // namespace std
