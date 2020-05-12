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

class PerfectGas : public GenericThermodynamicStateModel<Type::PerfectGas> {

public:

  constexpr PerfectGas() noexcept : GenericThermodynamicStateModel<Type::PerfectGas>() {}

  constexpr PerfectGas(const SpecificHeatRatio& specific_heat_ratio, const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) noexcept : GenericThermodynamicStateModel<Type::PerfectGas>(), specific_isobaric_heat_capacity_(specific_heat_ratio * specific_isochoric_heat_capacity), specific_gas_constant_(specific_isobaric_heat_capacity_ - specific_isochoric_heat_capacity) {}

  PerfectGas(const SpecificHeatRatio& specific_heat_ratio, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) : GenericThermodynamicStateModel<Type::PerfectGas>(), specific_isobaric_heat_capacity_(specific_isobaric_heat_capacity) {
    if (specific_heat_ratio != 0.0) {
      specific_gas_constant_ = {specific_isobaric_heat_capacity.value() * (1.0 - 1.0 / specific_heat_ratio.value()), standard_unit<Unit::SpecificHeatCapacity>};
    } else {
      throw std::runtime_error{"Division of " + number_to_string(1.0) + " by " + specific_heat_ratio.print() + "."};
    }
  }

  PerfectGas(const SpecificHeatRatio& specific_heat_ratio, const SpecificGasConstant& specific_gas_constant) : GenericThermodynamicStateModel<Type::PerfectGas>(), specific_gas_constant_(specific_gas_constant) {
    const double denominator{specific_heat_ratio.value() - 1.0};
    if (denominator != 0.0) {
      specific_isobaric_heat_capacity_ = {specific_heat_ratio.value() * specific_gas_constant.value() / denominator, standard_unit<Unit::SpecificHeatCapacity>};
    } else {
      throw std::runtime_error{"Division of " + number_to_string(1.0) + " by " + number_to_string(denominator) + "."};
    }
  }

  constexpr PerfectGas(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept : GenericThermodynamicStateModel<Type::PerfectGas>(), specific_isobaric_heat_capacity_(specific_isobaric_heat_capacity), specific_gas_constant_(specific_isobaric_heat_capacity - specific_isochoric_heat_capacity) {}

  constexpr PerfectGas(const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity, const SpecificGasConstant& specific_gas_constant) noexcept : GenericThermodynamicStateModel<Type::PerfectGas>(), specific_isobaric_heat_capacity_(specific_isochoric_heat_capacity + specific_gas_constant), specific_gas_constant_(specific_gas_constant) {}

  constexpr PerfectGas(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const SpecificGasConstant& specific_gas_constant) noexcept : GenericThermodynamicStateModel<Type::PerfectGas>(), specific_isobaric_heat_capacity_(specific_isobaric_heat_capacity), specific_gas_constant_(specific_gas_constant) {}

  SpecificHeatRatio specific_heat_ratio() const {
    const SpecificIsochoricHeatCapacity specific_isochoric_heat_capacity_{specific_isochoric_heat_capacity()};
    if (specific_isochoric_heat_capacity_.value() != 0.0) {
      return {specific_isobaric_heat_capacity_ / specific_isochoric_heat_capacity_};
    } else {
      throw std::runtime_error{"Division of " + specific_isobaric_heat_capacity_.print() + " by " + specific_isochoric_heat_capacity_.print() + "."};
    }
  }

  constexpr SpecificIsochoricHeatCapacity specific_isochoric_heat_capacity() const noexcept {
    return {specific_isobaric_heat_capacity_ - specific_gas_constant_};
  }

  constexpr const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity() const noexcept {
    return specific_isobaric_heat_capacity_;
  }

  constexpr const SpecificGasConstant& specific_gas_constant() const noexcept {
    return specific_gas_constant_;
  }

  MassDensity mass_density(const StaticPressure& static_pressure, const Temperature& temperature) const {
    const double denominator{temperature.value() * specific_gas_constant_.value()};
    if (denominator != 0.0) {
      return {static_pressure.value() / denominator, standard_unit<Unit::MassDensity>};
    } else {
      throw std::runtime_error{"Division of " + static_pressure.print() + " by " + number_to_string(denominator) + "."};
    }
  }

  constexpr StaticPressure static_pressure(const MassDensity& mass_density, const Temperature& temperature) const noexcept {
    return {mass_density.value() * temperature.value() * specific_gas_constant_.value(), standard_unit<Unit::Pressure>};
  }

  Temperature temperature(const MassDensity& mass_density, const StaticPressure& static_pressure) const {
    const double denominator{mass_density.value() * specific_gas_constant_.value()};
    if (denominator != 0.0) {
      return {static_pressure.value() / denominator, standard_unit<Unit::Temperature>};
    } else {
      throw std::runtime_error{"Division of " + static_pressure.print() + " by " + number_to_string(denominator) + "."};
    }
  }

  std::string print() const noexcept {
    return {"c_p = " + specific_isobaric_heat_capacity_.print() + ", R_gas = " + specific_gas_constant_.print()};
  }

  std::string json() const noexcept {
    return {"{\"type\": \"" + lowercase(abbreviation(type())) + "\", \"specific_isobaric_heat_capacity\": " + specific_isobaric_heat_capacity_.json()+ "\", \"specific_gas_constant\": " + specific_gas_constant_.json() + "}"};
  }

  std::string xml() const noexcept {
    return {"<type>" + lowercase(abbreviation(type())) + "</type><specific_isobaric_heat_capacity>" + specific_isobaric_heat_capacity_.xml() + "</specific_isobaric_heat_capacity><specific_gas_constant>" + specific_gas_constant_.xml() + "</specific_gas_constant>"};
  }

protected:

  SpecificIsobaricHeatCapacity specific_isobaric_heat_capacity_;

  SpecificGasConstant specific_gas_constant_;

};

} // namespace ThermodynamicStateModel

constexpr bool sort(const ThermodynamicStateModel::PerfectGas& model_1, const ThermodynamicStateModel::PerfectGas& model_2) noexcept {
  if (model_1.specific_isobaric_heat_capacity() < model_2.specific_isobaric_heat_capacity()) {
    return true;
  } else if (model_1.specific_isobaric_heat_capacity() > model_2.specific_isobaric_heat_capacity()) {
    return false;
  } else {
    return model_1.specific_gas_constant() < model_2.specific_gas_constant();
  }
}

} // namespace PhQ
