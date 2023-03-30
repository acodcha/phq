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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMODYNAMIC_STATE_MODEL_BASE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMODYNAMIC_STATE_MODEL_BASE_HPP

#include "../Base/Enumeration.hpp"
#include "../Base/String.hpp"

namespace PhQ {

namespace ThermodynamicStateModel {

enum class Type : int_least8_t {
  IncompressibleFluid,
  IdealGas,
};

template <Type ThermodynamicStateModelType>
class GenericThermodynamicStateModel {
public:
  constexpr ThermodynamicStateModel::Type Type() const noexcept {
    return ThermodynamicStateModelType;
  }

  virtual inline std::string Print() const noexcept = 0;

  virtual inline std::string JSON() const noexcept = 0;

  virtual inline std::string XML() const noexcept = 0;

  virtual inline std::string YAML() const noexcept = 0;

protected:
  constexpr GenericThermodynamicStateModel() noexcept = default;

  ~GenericThermodynamicStateModel() noexcept = default;
};

}  // namespace ThermodynamicStateModel

template <>
inline const std::map<ThermodynamicStateModel::Type, std::string_view>
    Abbreviations<ThermodynamicStateModel::Type>{
        {ThermodynamicStateModel::Type::IncompressibleFluid,
         "Incompressible Fluid"},
        {ThermodynamicStateModel::Type::IdealGas, "Ideal Gas"},
    };

template <>
inline const std::unordered_map<std::string_view, ThermodynamicStateModel::Type>
    Spellings<ThermodynamicStateModel::Type>{
        {"Incompressible Fluid",
         ThermodynamicStateModel::Type::IncompressibleFluid},
        {"IncompressibleFluid",
         ThermodynamicStateModel::Type::IncompressibleFluid},
        {"incompressible fluid",
         ThermodynamicStateModel::Type::IncompressibleFluid},
        {"incompressible_fluid",
         ThermodynamicStateModel::Type::IncompressibleFluid},
        {"Ideal Gas", ThermodynamicStateModel::Type::IdealGas},
        {"IdealGas", ThermodynamicStateModel::Type::IdealGas},
        {"ideal gas", ThermodynamicStateModel::Type::IdealGas},
        {"ideal_gas", ThermodynamicStateModel::Type::IdealGas},
    };

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMODYNAMIC_STATE_MODEL_BASE_HPP
