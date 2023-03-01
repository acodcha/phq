// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../SpecificIsobaricHeatCapacity.hpp"
#include "../MassDensity.hpp"
#include "Base.hpp"

namespace PhQ {

namespace ThermodynamicStateModel {

class IncompressibleFluid : public GenericThermodynamicStateModel<Type::IncompressibleFluid> {

public:

  constexpr IncompressibleFluid() noexcept : GenericThermodynamicStateModel<Type::IncompressibleFluid>(), mass_density_(), specific_isobaric_heat_capacity_() {}

  constexpr IncompressibleFluid(const MassDensity& mass_density, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept : GenericThermodynamicStateModel<Type::IncompressibleFluid>(), mass_density_(mass_density), specific_isobaric_heat_capacity_(specific_isobaric_heat_capacity) {}

  PhQ::MassDensity MassDensity() const noexcept {
    return mass_density_;
  }

  constexpr const PhQ::SpecificIsobaricHeatCapacity& SpecificIsobaricHeatCapacity() const noexcept {
    return specific_isobaric_heat_capacity_;
  }

  std::string Print() const noexcept override {
    return {"Mass Density = " + mass_density_.Print() + ", Specific Isobaric Heat Capacity = " + specific_isobaric_heat_capacity_.Print()};
  }

  std::string Json() const noexcept override {
    return {"{\"type\": \"" + LowerCaseCopy(Abbreviation(Type())) + "\", \"mass_density\": " + mass_density_.Json()+ "\", \"specific_isobaric_heat_capacity\": " + specific_isobaric_heat_capacity_.Json() + "}"};
  }

  std::string Xml() const noexcept override {
    return {"<type>" + LowerCaseCopy(Abbreviation(Type())) + "</type><mass_density>" + specific_isobaric_heat_capacity_.Xml() + "</mass_density><specific_isobaric_heat_capacity>" + specific_isobaric_heat_capacity_.Xml() + "</specific_isobaric_heat_capacity>"};
  }

protected:

  PhQ::MassDensity mass_density_;

  PhQ::SpecificIsobaricHeatCapacity specific_isobaric_heat_capacity_;

};

} // namespace ThermodynamicStateModel

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::ThermodynamicStateModel::IncompressibleFluid> {
  size_t operator()(const PhQ::ThermodynamicStateModel::IncompressibleFluid& model) const {
    return hash<PhQ::MassDensity>()(model.MassDensity()) ^ hash<PhQ::SpecificIsobaricHeatCapacity>()(model.SpecificIsobaricHeatCapacity());
  }
};

} // namespace std
