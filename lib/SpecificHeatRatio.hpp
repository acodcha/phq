// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionlessScalar.hpp"

namespace PhQ {

// Forward declarations.
class GasConstant;
class IsobaricHeatCapacity;
class IsochoricHeatCapacity;
class Mass;
class SpecificGasConstant;
class SpecificIsobaricHeatCapacity;
class SpecificIsochoricHeatCapacity;

class SpecificHeatRatio : public DimensionlessScalarQuantity {

public:

  constexpr SpecificHeatRatio() noexcept : DimensionlessScalarQuantity() {}

  constexpr SpecificHeatRatio(double value) noexcept : DimensionlessScalarQuantity(value) {}

  constexpr SpecificHeatRatio(const SpecificGasConstant& specific_gas_constant, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept;

  constexpr SpecificHeatRatio(const SpecificGasConstant& specific_gas_constant, const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) noexcept;

  constexpr SpecificHeatRatio(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) noexcept;

  constexpr SpecificHeatRatio(const GasConstant& gas_constant, const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept;

  constexpr SpecificHeatRatio(const GasConstant& gas_constant, const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept;

  constexpr SpecificHeatRatio(const IsobaricHeatCapacity& isobaric_heat_capacity, const IsochoricHeatCapacity& isochoric_heat_capacity) noexcept;

  constexpr IsobaricHeatCapacity operator*(const IsochoricHeatCapacity& isochoric_heat_capacity) const noexcept;

  constexpr SpecificIsobaricHeatCapacity operator*(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const noexcept;

  friend class GasConstant;
  friend class IsobaricHeatCapacity;
  friend class IsochoricHeatCapacity;
  friend class Mass;
  friend class SpecificGasConstant;
  friend class SpecificIsobaricHeatCapacity;
  friend class SpecificIsochoricHeatCapacity;

};

} // namespace PhQ
