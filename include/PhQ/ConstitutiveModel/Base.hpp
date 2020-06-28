// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../Base/String.hpp"
#include "../Base/Type.hpp"

namespace PhQ {

namespace ConstitutiveModel {

enum class Type : uint_least8_t {
  ElasticIsotropicSolid,
  IncompressibleNewtonianFluid,
  CompressibleNewtonianFluid
};

template <Type ConstitutiveModelType> class GenericConstitutiveModel {

public:

  constexpr Type type() const noexcept {
    return ConstitutiveModelType;
  }

  virtual std::string print() const noexcept = 0;

  virtual std::string json() const noexcept = 0;

  virtual std::string xml() const noexcept = 0;

protected:

  constexpr GenericConstitutiveModel() noexcept = default;

};

} // namespace ConstitutiveModel

template <> const std::map<ConstitutiveModel::Type, std::string> abbreviations<ConstitutiveModel::Type>{
  {ConstitutiveModel::Type::ElasticIsotropicSolid, "Elastic Isotropic Solid"},
  {ConstitutiveModel::Type::IncompressibleNewtonianFluid, "Incompressible Newtonian Fluid"},
  {ConstitutiveModel::Type::CompressibleNewtonianFluid, "Compressible Newtonian Fluid"}
};

template <> const std::unordered_map<std::string, ConstitutiveModel::Type> spellings<ConstitutiveModel::Type>{
  {"Elastic Isotropic Solid", ConstitutiveModel::Type::ElasticIsotropicSolid},
  {"ElasticIsotropicSolid", ConstitutiveModel::Type::ElasticIsotropicSolid},
  {"elastic isotropic solid", ConstitutiveModel::Type::ElasticIsotropicSolid},
  {"elastic_isotropic_solid", ConstitutiveModel::Type::ElasticIsotropicSolid},
  {"Incompressible Newtonian Fluid", ConstitutiveModel::Type::IncompressibleNewtonianFluid},
  {"IncompressibleNewtonianFluid", ConstitutiveModel::Type::IncompressibleNewtonianFluid},
  {"incompressible newtonian fluid", ConstitutiveModel::Type::IncompressibleNewtonianFluid},
  {"incompressible_newtonian_fluid", ConstitutiveModel::Type::IncompressibleNewtonianFluid},
  {"Compressible Newtonian Fluid", ConstitutiveModel::Type::CompressibleNewtonianFluid},
  {"CompressibleNewtonianFluid", ConstitutiveModel::Type::CompressibleNewtonianFluid},
  {"compressible newtonian fluid", ConstitutiveModel::Type::CompressibleNewtonianFluid},
  {"compressible_newtonian_fluid", ConstitutiveModel::Type::CompressibleNewtonianFluid}
};

} // namespace PhQ

template <PhQ::ConstitutiveModel::Type ConstitutiveModelType> std::ostream& operator<<(std::ostream& output_stream, const PhQ::ConstitutiveModel::GenericConstitutiveModel<ConstitutiveModelType>& constitutive_model) noexcept {
  output_stream << constitutive_model.print();
  return output_stream;
}
