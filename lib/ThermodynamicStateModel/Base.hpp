// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../Base/String.hpp"
#include "../Base/Type.hpp"

namespace PhQ {

namespace ThermodynamicStateModel {

enum class Type : uint_least8_t {
  PerfectGas
};

template <Type ThermodynamicStateModelType> class GenericThermodynamicStateModel {

public:

  constexpr Type type() const noexcept {
    return ThermodynamicStateModelType;
  }

  virtual std::string print() const noexcept = 0;

  virtual std::string json() const noexcept = 0;

  virtual std::string xml() const noexcept = 0;

protected:

  constexpr GenericThermodynamicStateModel() noexcept = default;

};

} // namespace ThermodynamicStateModel

template <> const std::map<ThermodynamicStateModel::Type, std::string> abbreviations<ThermodynamicStateModel::Type>{
  {ThermodynamicStateModel::Type::PerfectGas, "Perfect Gas"}
};

template <> const std::unordered_map<std::string, ThermodynamicStateModel::Type> spellings<ThermodynamicStateModel::Type>{
  {"Perfect Gas", ThermodynamicStateModel::Type::PerfectGas},
  {"PerfectGas", ThermodynamicStateModel::Type::PerfectGas},
  {"perfect gas", ThermodynamicStateModel::Type::PerfectGas},
  {"perfect_gas", ThermodynamicStateModel::Type::PerfectGas}
};

} // namespace PhQ

template <PhQ::ThermodynamicStateModel::Type ThermodynamicStateModelType> std::ostream& operator<<(std::ostream& output_stream, const PhQ::ThermodynamicStateModel::GenericThermodynamicStateModel<ThermodynamicStateModelType>& thermodynamic_state_model) noexcept {
  output_stream << thermodynamic_state_model.print();
  return output_stream;
}
