// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMODYNAMIC_STATE_MODEL_IDEAL_GAS_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMODYNAMIC_STATE_MODEL_IDEAL_GAS_HPP

#include "../MassDensity.hpp"
#include "../SpecificGasConstant.hpp"
#include "../StaticPressure.hpp"
#include "../Temperature.hpp"
#include "Base.hpp"

namespace PhQ::ThermodynamicStateModel {

class IdealGas : public GenericThermodynamicStateModel<Type::IdealGas> {
public:
  constexpr IdealGas() noexcept
      : GenericThermodynamicStateModel<Type::IdealGas>(),
        specific_gas_constant_(),
        specific_isobaric_heat_capacity_() {}

  constexpr IdealGas(const SpecificGasConstant& specific_gas_constant,
                     const SpecificIsobaricHeatCapacity&
                         specific_isobaric_heat_capacity) noexcept
      : GenericThermodynamicStateModel<Type::IdealGas>(),
        specific_gas_constant_(specific_gas_constant),
        specific_isobaric_heat_capacity_(specific_isobaric_heat_capacity) {}

  constexpr IdealGas(const SpecificGasConstant& specific_gas_constant,
                     const SpecificIsochoricHeatCapacity&
                         specific_isochoric_heat_capacity) noexcept
      : GenericThermodynamicStateModel<Type::IdealGas>(),
        specific_gas_constant_(specific_gas_constant),
        specific_isobaric_heat_capacity_(specific_gas_constant,
                                         specific_isochoric_heat_capacity) {}

  constexpr IdealGas(const SpecificGasConstant& specific_gas_constant,
                     const SpecificHeatRatio& specific_heat_ratio) noexcept
      : GenericThermodynamicStateModel<Type::IdealGas>(),
        specific_gas_constant_(specific_gas_constant),
        specific_isobaric_heat_capacity_(specific_gas_constant,
                                         specific_heat_ratio) {}

  constexpr IdealGas(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const SpecificIsochoricHeatCapacity&
          specific_isochoric_heat_capacity) noexcept
      : GenericThermodynamicStateModel<Type::IdealGas>(),
        specific_gas_constant_(specific_isobaric_heat_capacity,
                               specific_isochoric_heat_capacity),
        specific_isobaric_heat_capacity_(specific_isobaric_heat_capacity) {}

  constexpr IdealGas(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const SpecificHeatRatio& specific_heat_ratio) noexcept
      : GenericThermodynamicStateModel<Type::IdealGas>(),
        specific_gas_constant_(specific_isobaric_heat_capacity,
                               specific_heat_ratio),
        specific_isobaric_heat_capacity_(specific_isobaric_heat_capacity) {}

  constexpr IdealGas(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity,
      const SpecificHeatRatio& specific_heat_ratio) noexcept
      : GenericThermodynamicStateModel<Type::IdealGas>(),
        specific_gas_constant_(specific_isochoric_heat_capacity,
                               specific_heat_ratio),
        specific_isobaric_heat_capacity_(specific_isochoric_heat_capacity,
                                         specific_heat_ratio) {}

  inline constexpr const PhQ::SpecificGasConstant& SpecificGasConstant()
      const noexcept {
    return specific_gas_constant_;
  }

  inline constexpr const PhQ::SpecificIsobaricHeatCapacity&
  SpecificIsobaricHeatCapacity() const noexcept {
    return specific_isobaric_heat_capacity_;
  }

  inline PhQ::SpecificIsochoricHeatCapacity SpecificIsochoricHeatCapacity()
      const noexcept {
    return {specific_isobaric_heat_capacity_ - specific_gas_constant_};
  }

  inline PhQ::SpecificHeatRatio SpecificHeatRatio() const noexcept {
    return {specific_isobaric_heat_capacity_ / SpecificIsochoricHeatCapacity()};
  }

  inline PhQ::MassDensity MassDensity(
      const PhQ::StaticPressure& static_pressure,
      const PhQ::Temperature& temperature) const noexcept {
    return {static_pressure.Value() /
                (temperature.Value() * specific_gas_constant_.Value()),
            StandardUnit<Unit::MassDensity>};
  }

  inline PhQ::StaticPressure StaticPressure(
      const PhQ::MassDensity& mass_density,
      const PhQ::Temperature& temperature) const noexcept {
    return {mass_density.Value() * temperature.Value() *
                specific_gas_constant_.Value(),
            StandardUnit<Unit::Pressure>};
  }

  inline PhQ::Temperature Temperature(
      const PhQ::MassDensity& mass_density,
      const PhQ::StaticPressure& static_pressure) const noexcept {
    return {static_pressure.Value() /
                (mass_density.Value() * specific_gas_constant_.Value()),
            StandardUnit<Unit::Temperature>};
  }

  inline std::string Print() const noexcept override {
    return {"Specific Gas Constant = " + specific_gas_constant_.Print() +
            ", Specific Isobaric Heat Capacity = " +
            specific_isobaric_heat_capacity_.Print()};
  }

  inline std::string Json() const noexcept override {
    return {"{\"type\": \"" + LowerCaseCopy(Abbreviation(Type())) +
            "\", \"specific_gas_constant\": " + specific_gas_constant_.Json() +
            "\", \"specific_isobaric_heat_capacity\": " +
            specific_isobaric_heat_capacity_.Json() + "}"};
  }

  inline std::string Xml() const noexcept override {
    return {"<type>" + LowerCaseCopy(Abbreviation(Type())) +
            "</type><specific_gas_constant>" + specific_gas_constant_.Xml() +
            "</specific_gas_constant><specific_isobaric_heat_capacity>" +
            specific_isobaric_heat_capacity_.Xml() +
            "</specific_isobaric_heat_capacity>"};
  }

  inline std::string Yaml() const noexcept override {
    return {"{type: \"" + LowerCaseCopy(Abbreviation(Type())) +
            "\", specific_gas_constant: " + specific_gas_constant_.Json() +
            "\", specific_isobaric_heat_capacity: " +
            specific_isobaric_heat_capacity_.Json() + "}"};
  }

private:
  PhQ::SpecificGasConstant specific_gas_constant_;

  PhQ::SpecificIsobaricHeatCapacity specific_isobaric_heat_capacity_;
};

inline bool operator==(const IdealGas& left, const IdealGas& right) noexcept {
  return left.SpecificGasConstant() == right.SpecificGasConstant() &&
         left.SpecificIsobaricHeatCapacity() ==
             right.SpecificIsobaricHeatCapacity();
}

inline bool operator!=(const IdealGas& left, const IdealGas& right) noexcept {
  return left.SpecificGasConstant() != right.SpecificGasConstant() ||
         left.SpecificIsobaricHeatCapacity() !=
             right.SpecificIsobaricHeatCapacity();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const IdealGas& model) noexcept {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ::ThermodynamicStateModel

namespace std {

template <>
struct hash<PhQ::ThermodynamicStateModel::IdealGas> {
  size_t operator()(const PhQ::ThermodynamicStateModel::IdealGas& model) const {
    size_t result = 17;
    result = 31 * result +
             hash<PhQ::SpecificGasConstant>()(model.SpecificGasConstant());
    result = 31 * result + hash<PhQ::SpecificIsobaricHeatCapacity>()(
                               model.SpecificIsobaricHeatCapacity());
    return result;
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMODYNAMIC_STATE_MODEL_IDEAL_GAS_HPP
