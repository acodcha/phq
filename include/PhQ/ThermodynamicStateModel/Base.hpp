// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../Base/Enumeration.hpp"
#include "../Base/String.hpp"

namespace PhQ {

namespace ThermodynamicStateModel {

enum class Type : int_least8_t {
  IncompressibleFluid,
  IdealGas,
};

template <Type ThermodynamicStateModelType> class GenericThermodynamicStateModel {

public:

  constexpr ThermodynamicStateModel::Type Type() const noexcept {
    return ThermodynamicStateModelType;
  }

  virtual std::string Print() const noexcept = 0;

  virtual std::string Json() const noexcept = 0;

  virtual std::string Xml() const noexcept = 0;

protected:

  constexpr GenericThermodynamicStateModel() noexcept = default;

};

} // namespace ThermodynamicStateModel

template <> inline const std::map<ThermodynamicStateModel::Type, std::string_view> Abbreviations<ThermodynamicStateModel::Type>{
  {ThermodynamicStateModel::Type::IncompressibleFluid, "Incompressible Fluid"},
  {ThermodynamicStateModel::Type::IdealGas, "Ideal Gas"},
};

template <> inline const std::unordered_map<std::string_view, ThermodynamicStateModel::Type> Spellings<ThermodynamicStateModel::Type>{
  {"Incompressible Fluid", ThermodynamicStateModel::Type::IncompressibleFluid},
  {"IncompressibleFluid", ThermodynamicStateModel::Type::IncompressibleFluid},
  {"incompressible fluid", ThermodynamicStateModel::Type::IncompressibleFluid},
  {"incompressible_fluid", ThermodynamicStateModel::Type::IncompressibleFluid},
  {"Ideal Gas", ThermodynamicStateModel::Type::IdealGas},
  {"IdealGas", ThermodynamicStateModel::Type::IdealGas},
  {"ideal gas", ThermodynamicStateModel::Type::IdealGas},
  {"ideal_gas", ThermodynamicStateModel::Type::IdealGas},
};

} // namespace PhQ

template <PhQ::ThermodynamicStateModel::Type ThermodynamicStateModelType> std::ostream& operator<<(std::ostream& stream, const PhQ::ThermodynamicStateModel::GenericThermodynamicStateModel<ThermodynamicStateModelType>& model) noexcept {
  stream << model.print();
  return stream;
}
