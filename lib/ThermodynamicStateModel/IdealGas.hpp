// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../SpecificGasConstant.hpp"
#include "../MassDensity.hpp"
#include "../StaticPressure.hpp"
#include "../Temperature.hpp"
#include "Base.hpp"

namespace PhQ {

namespace ThermodynamicStateModel {

class IdealGas : public GenericThermodynamicStateModel<Type::IdealGas> {

public:

  constexpr IdealGas() noexcept : GenericThermodynamicStateModel<Type::IdealGas>(), specific_gas_constant_(), specific_isobaric_heat_capacity_() {}

  constexpr IdealGas(const SpecificGasConstant& specific_gas_constant, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept : GenericThermodynamicStateModel<Type::IdealGas>(), specific_gas_constant_(specific_gas_constant), specific_isobaric_heat_capacity_(specific_isobaric_heat_capacity) {}

  constexpr IdealGas(const SpecificGasConstant& specific_gas_constant, const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) noexcept : GenericThermodynamicStateModel<Type::IdealGas>(), specific_gas_constant_(specific_gas_constant), specific_isobaric_heat_capacity_(specific_gas_constant, specific_isochoric_heat_capacity) {}

  constexpr IdealGas(const SpecificGasConstant& specific_gas_constant, const SpecificHeatRatio& specific_heat_ratio) noexcept : GenericThermodynamicStateModel<Type::IdealGas>(), specific_gas_constant_(specific_gas_constant), specific_isobaric_heat_capacity_(specific_gas_constant, specific_heat_ratio) {}

  constexpr IdealGas(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) noexcept : GenericThermodynamicStateModel<Type::IdealGas>(), specific_gas_constant_(specific_isobaric_heat_capacity, specific_isochoric_heat_capacity), specific_isobaric_heat_capacity_(specific_isobaric_heat_capacity) {}

  constexpr IdealGas(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const SpecificHeatRatio& specific_heat_ratio) noexcept : GenericThermodynamicStateModel<Type::IdealGas>(), specific_gas_constant_(specific_isobaric_heat_capacity, specific_heat_ratio), specific_isobaric_heat_capacity_(specific_isobaric_heat_capacity) {}

  constexpr IdealGas(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity, const SpecificHeatRatio& specific_heat_ratio) noexcept : GenericThermodynamicStateModel<Type::IdealGas>(), specific_gas_constant_(specific_isochoric_heat_capacity, specific_heat_ratio), specific_isobaric_heat_capacity_(specific_isochoric_heat_capacity, specific_heat_ratio) {}

  constexpr const SpecificGasConstant& specific_gas_constant() const noexcept {
    return specific_gas_constant_;
  }

  constexpr const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity() const noexcept {
    return specific_isobaric_heat_capacity_;
  }

  constexpr SpecificIsochoricHeatCapacity specific_isochoric_heat_capacity() const noexcept {
    return {specific_isobaric_heat_capacity_ - specific_gas_constant_};
  }

  constexpr SpecificHeatRatio specific_heat_ratio() const noexcept {
    return {specific_isobaric_heat_capacity_ / specific_isochoric_heat_capacity()};
  }

  constexpr MassDensity mass_density(const StaticPressure& static_pressure, const Temperature& temperature) const noexcept {
    return {static_pressure.value() / (temperature.value() * specific_gas_constant_.value()), standard_unit<Unit::MassDensity>};
  }

  constexpr StaticPressure static_pressure(const MassDensity& mass_density, const Temperature& temperature) const noexcept {
    return {mass_density.value() * temperature.value() * specific_gas_constant_.value(), standard_unit<Unit::Pressure>};
  }

  constexpr Temperature temperature(const MassDensity& mass_density, const StaticPressure& static_pressure) const noexcept {
    return {static_pressure.value() / (mass_density.value() * specific_gas_constant_.value()), standard_unit<Unit::Temperature>};
  }

  std::string print() const noexcept {
    return {"R_gas = " + specific_gas_constant_.print() + ", c_p = " + specific_isobaric_heat_capacity_.print()};
  }

  std::string json() const noexcept {
    return {"{\"type\": \"" + lowercase(abbreviation(type())) + "\", \"specific_gas_constant\": " + specific_gas_constant_.json()+ "\", \"specific_isobaric_heat_capacity\": " + specific_isobaric_heat_capacity_.json() + "}"};
  }

  std::string xml() const noexcept {
    return {"<type>" + lowercase(abbreviation(type())) + "</type><specific_gas_constant>" + specific_gas_constant_.xml() + "</specific_gas_constant><specific_isobaric_heat_capacity>" + specific_isobaric_heat_capacity_.xml() + "</specific_isobaric_heat_capacity>"};
  }

protected:

  SpecificGasConstant specific_gas_constant_;

  SpecificIsobaricHeatCapacity specific_isobaric_heat_capacity_;

};

} // namespace ThermodynamicStateModel

constexpr bool sort(const ThermodynamicStateModel::IdealGas& model_1, const ThermodynamicStateModel::IdealGas& model_2) noexcept {
  if (model_1.specific_gas_constant() == model_2.specific_gas_constant()) {
    return model_1.specific_isobaric_heat_capacity() < model_2.specific_isobaric_heat_capacity();
  } else {
    return model_1.specific_gas_constant() < model_2.specific_gas_constant();
  }
}

} // namespace PhQ
