// Copyright 2020 Alexandre Coderre-Chabot
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

  constexpr MassDensity mass_density() const noexcept {
    return mass_density_;
  }

  constexpr const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity() const noexcept {
    return specific_isobaric_heat_capacity_;
  }

  std::string print() const noexcept {
    return {"ρ = " + mass_density_.print() + ", c_p = " + specific_isobaric_heat_capacity_.print()};
  }

  std::string json() const noexcept {
    return {"{\"type\": \"" + lowercase(abbreviation(type())) + "\", \"mass_density\": " + mass_density_.json()+ "\", \"specific_isobaric_heat_capacity\": " + specific_isobaric_heat_capacity_.json() + "}"};
  }

  std::string xml() const noexcept {
    return {"<type>" + lowercase(abbreviation(type())) + "</type><mass_density>" + specific_isobaric_heat_capacity_.xml() + "</mass_density><specific_isobaric_heat_capacity>" + specific_isobaric_heat_capacity_.xml() + "</specific_isobaric_heat_capacity>"};
  }

protected:

  MassDensity mass_density_;

  SpecificIsobaricHeatCapacity specific_isobaric_heat_capacity_;

};

} // namespace ThermodynamicStateModel

constexpr bool sort(const ThermodynamicStateModel::IncompressibleFluid& model_1, const ThermodynamicStateModel::IncompressibleFluid& model_2) noexcept {
  if (model_1.mass_density() == model_2.mass_density()) {
    return model_1.specific_isobaric_heat_capacity() < model_2.specific_isobaric_heat_capacity();
  } else {
    return model_1.mass_density() < model_2.mass_density();
  }
}

} // namespace PhQ
