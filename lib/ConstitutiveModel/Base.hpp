// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../Base/String.hpp"
#include "../Base/Type.hpp"

namespace PhQ {

namespace ConstitutiveModel {

enum class Type : uint_least8_t {
  ElasticIsotropicSolid
};

template <Type ConstitutiveModelType> class GenericConstitutiveModel {

public:

  constexpr GenericConstitutiveModel() noexcept = default;

  constexpr Type type() const noexcept {
    return ConstitutiveModelType;
  }

  virtual std::string print() const noexcept = 0;

  virtual std::string json() const noexcept = 0;

  virtual std::string xml() const noexcept = 0;

};

} // namespace ConstitutiveModel

template <> const std::map<ConstitutiveModel::Type, std::string> abbreviations<ConstitutiveModel::Type>{
  {ConstitutiveModel::Type::ElasticIsotropicSolid, "Elastic Isotropic Solid"}
};

template <> const std::unordered_map<std::string, ConstitutiveModel::Type> spellings<ConstitutiveModel::Type>{
  {"Elastic Isotropic Solid", ConstitutiveModel::Type::ElasticIsotropicSolid},
  {"ElasticIsotropicSolid", ConstitutiveModel::Type::ElasticIsotropicSolid},
  {"elastic isotropic solid", ConstitutiveModel::Type::ElasticIsotropicSolid},
  {"elastic_isotropic_solid", ConstitutiveModel::Type::ElasticIsotropicSolid}
};

} // namespace PhQ

template <PhQ::ConstitutiveModel::Type ConstitutiveModelType> std::ostream& operator<<(std::ostream& output_stream, const PhQ::ConstitutiveModel::GenericConstitutiveModel<ConstitutiveModelType>& constitutive_model) noexcept {
  output_stream << constitutive_model.print();
  return output_stream;
}
