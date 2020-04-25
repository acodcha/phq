// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../Base/String.hpp"
#include "../Base/Type.hpp"

namespace PhQ {

namespace StateModel {

enum class Type : uint_least8_t {
  PerfectGas
};

template <Type StateModelType> class GenericStateModel {

public:

  constexpr GenericStateModel() noexcept = default;

  constexpr Type type() const noexcept {
    return StateModelType;
  }

  virtual std::string print() const noexcept = 0;

  virtual std::string json() const noexcept = 0;

  virtual std::string xml() const noexcept = 0;

};

} // namespace StateModel

template <> const std::map<StateModel::Type, std::string> abbreviations<StateModel::Type>{
  {StateModel::Type::PerfectGas, "Perfect Gas"}
};

template <> const std::unordered_map<std::string, StateModel::Type> spellings<StateModel::Type>{
  {"Perfect Gas", StateModel::Type::PerfectGas},
  {"PerfectGas", StateModel::Type::PerfectGas},
  {"perfect gas", StateModel::Type::PerfectGas},
  {"perfect_gas", StateModel::Type::PerfectGas}
};

} // namespace PhQ

template <PhQ::StateModel::Type StateModelType> std::ostream& operator<<(std::ostream& output_stream, const PhQ::StateModel::GenericStateModel<StateModelType>& state_model) noexcept {
  output_stream << state_model.print();
  return output_stream;
}
