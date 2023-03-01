// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../Base/Enumeration.hpp"
#include "../Base/String.hpp"

namespace PhQ {

namespace ConstitutiveModel {

enum class Type : int_least8_t {
  ElasticIsotropicSolid,
  IncompressibleNewtonianFluid,
  CompressibleNewtonianFluid,
};

template <Type ConstitutiveModelType> class GenericConstitutiveModel {

public:

  constexpr ConstitutiveModel::Type Type() const noexcept {
    return ConstitutiveModelType;
  }

  virtual std::string Print() const noexcept = 0;

  virtual std::string Json() const noexcept = 0;

  virtual std::string Xml() const noexcept = 0;

protected:

  constexpr GenericConstitutiveModel() noexcept = default;

};

} // namespace ConstitutiveModel

template <> inline const std::map<ConstitutiveModel::Type, std::string_view> Abbreviations<ConstitutiveModel::Type>{
  {ConstitutiveModel::Type::ElasticIsotropicSolid, "Elastic Isotropic Solid"},
  {ConstitutiveModel::Type::IncompressibleNewtonianFluid, "Incompressible Newtonian Fluid"},
  {ConstitutiveModel::Type::CompressibleNewtonianFluid, "Compressible Newtonian Fluid"},
};

template <> inline const std::unordered_map<std::string_view, ConstitutiveModel::Type> Spellings<ConstitutiveModel::Type>{
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
  {"compressible_newtonian_fluid", ConstitutiveModel::Type::CompressibleNewtonianFluid},
};

} // namespace PhQ

template <PhQ::ConstitutiveModel::Type ConstitutiveModelType> std::ostream& operator<<(std::ostream& stream, const PhQ::ConstitutiveModel::GenericConstitutiveModel<ConstitutiveModelType>& model) noexcept {
  stream << model.print();
  return stream;
}
