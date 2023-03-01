// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

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

  constexpr const PhQ::SpecificGasConstant& SpecificGasConstant() const noexcept {
    return specific_gas_constant_;
  }

  constexpr const PhQ::SpecificIsobaricHeatCapacity& SpecificIsobaricHeatCapacity() const noexcept {
    return specific_isobaric_heat_capacity_;
  }

  PhQ::SpecificIsochoricHeatCapacity SpecificIsochoricHeatCapacity() const noexcept {
    return {specific_isobaric_heat_capacity_ - specific_gas_constant_};
  }

  PhQ::SpecificHeatRatio SpecificHeatRatio() const noexcept {
    return {specific_isobaric_heat_capacity_ / SpecificIsochoricHeatCapacity()};
  }

  PhQ::MassDensity MassDensity(const PhQ::StaticPressure& static_pressure, const PhQ::Temperature& temperature) const noexcept {
    return {static_pressure.Value() / (temperature.Value() * specific_gas_constant_.Value()), StandardUnit<Unit::MassDensity>};
  }

  PhQ::StaticPressure StaticPressure(const PhQ::MassDensity& mass_density, const PhQ::Temperature& temperature) const noexcept {
    return {mass_density.Value() * temperature.Value() * specific_gas_constant_.Value(), StandardUnit<Unit::Pressure>};
  }

  PhQ::Temperature Temperature(const PhQ::MassDensity& mass_density, const PhQ::StaticPressure& static_pressure) const noexcept {
    return {static_pressure.Value() / (mass_density.Value() * specific_gas_constant_.Value()), StandardUnit<Unit::Temperature>};
  }

  std::string Print() const noexcept override {
    return {"Specific Gas Constant = " + specific_gas_constant_.Print() + ", Specific Isobaric Heat Capacity = " + specific_isobaric_heat_capacity_.Print()};
  }

  std::string Json() const noexcept override {
    return {"{\"type\": \"" + LowerCaseCopy(Abbreviation(Type())) + "\", \"specific_gas_constant\": " + specific_gas_constant_.Json()+ "\", \"specific_isobaric_heat_capacity\": " + specific_isobaric_heat_capacity_.Json() + "}"};
  }

  std::string Xml() const noexcept override {
    return {"<type>" + LowerCaseCopy(Abbreviation(Type())) + "</type><specific_gas_constant>" + specific_gas_constant_.Xml() + "</specific_gas_constant><specific_isobaric_heat_capacity>" + specific_isobaric_heat_capacity_.Xml() + "</specific_isobaric_heat_capacity>"};
  }

protected:

  PhQ::SpecificGasConstant specific_gas_constant_;

  PhQ::SpecificIsobaricHeatCapacity specific_isobaric_heat_capacity_;

};

} // namespace ThermodynamicStateModel

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::ThermodynamicStateModel::IdealGas> {
  size_t operator()(const PhQ::ThermodynamicStateModel::IdealGas& model) const {
    return hash<PhQ::SpecificGasConstant>()(model.SpecificGasConstant()) ^ hash<PhQ::SpecificIsobaricHeatCapacity>()(model.SpecificIsobaricHeatCapacity());
  }
};

} // namespace std
