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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_HPP

#include "Strain.hpp"
#include "StrainRate.hpp"
#include "Stress.hpp"

namespace PhQ {

// Abstract base class for a material's constitutive model, which is a model
// that defines the relationship between the stress and the strain and strain
// rate at any point in the material.
class ConstitutiveModel {
public:
  // Constitutive model type of a material.
  enum class Type : int8_t {
    // Compressible Newtonian fluid constitutive model
    CompressibleNewtonianFluid,

    // Elastic isotropic solid constitutive model
    ElasticIsotropicSolid,

    // Incompressible Newtonian fluid constitutive model
    IncompressibleNewtonianFluid,
  };

  // Forward declaration for class PhQ::ConstitutiveModel.
  class CompressibleNewtonianFluid;

  // Forward declaration for class PhQ::ConstitutiveModel.
  class ElasticIsotropicSolid;

  // Forward declaration for class PhQ::ConstitutiveModel.
  class IncompressibleNewtonianFluid;

  virtual ~ConstitutiveModel() noexcept = default;

  // Returns this constitutive model's type.
  virtual inline Type GetType() const noexcept = 0;

  // Returns the stress resulting from a given strain and strain rate.
  virtual inline PhQ::Stress Stress(
      const PhQ::Strain& strain,
      const PhQ::StrainRate& strain_rate) const noexcept = 0;

  // Returns the stress resulting from a given strain.
  virtual inline PhQ::Stress Stress(
      const PhQ::Strain& strain) const noexcept = 0;

  // Returns the stress resulting from a given strain rate.
  virtual inline PhQ::Stress Stress(
      const PhQ::StrainRate& strain_rate) const noexcept = 0;

  // Returns the strain resulting from a given stress.
  virtual inline PhQ::Strain Strain(
      const PhQ::Stress& stress) const noexcept = 0;

  // Returns the strain rate resulting from a given stress.
  virtual inline PhQ::StrainRate StrainRate(
      const PhQ::Stress& stress) const noexcept = 0;

  // Prints this constitutive model as a string.
  virtual inline std::string Print() const noexcept = 0;

  // Serializes this constitutive model as a JSON message.
  virtual inline std::string JSON() const noexcept = 0;

  // Serializes this constitutive model as an XML message.
  virtual inline std::string XML() const noexcept = 0;

  // Serializes this constitutive model as a YAML message.
  virtual inline std::string YAML() const noexcept = 0;

protected:
  constexpr ConstitutiveModel() noexcept = default;
};

template <>
inline const std::map<ConstitutiveModel::Type, std::string_view>
    Internal::Abbreviations<ConstitutiveModel::Type>{
        {ConstitutiveModel::Type::ElasticIsotropicSolid,
         "Elastic Isotropic Solid"       },
        {ConstitutiveModel::Type::IncompressibleNewtonianFluid,
         "Incompressible Newtonian Fluid"},
        {ConstitutiveModel::Type::CompressibleNewtonianFluid,
         "Compressible Newtonian Fluid"  },
};

template <>
inline const std::unordered_map<std::string_view, ConstitutiveModel::Type>
    Internal::Spellings<ConstitutiveModel::Type>{
        {"Elastic Isotropic Solid",
         ConstitutiveModel::Type::ElasticIsotropicSolid       },
        {"ElasticIsotropicSolid",
         ConstitutiveModel::Type::ElasticIsotropicSolid       },
        {"elastic isotropic solid",
         ConstitutiveModel::Type::ElasticIsotropicSolid       },
        {"elastic_isotropic_solid",
         ConstitutiveModel::Type::ElasticIsotropicSolid       },
        {"Incompressible Newtonian Fluid",
         ConstitutiveModel::Type::IncompressibleNewtonianFluid},
        {"IncompressibleNewtonianFluid",
         ConstitutiveModel::Type::IncompressibleNewtonianFluid},
        {"incompressible newtonian fluid",
         ConstitutiveModel::Type::IncompressibleNewtonianFluid},
        {"incompressible_newtonian_fluid",
         ConstitutiveModel::Type::IncompressibleNewtonianFluid},
        {"Compressible Newtonian Fluid",
         ConstitutiveModel::Type::CompressibleNewtonianFluid  },
        {"CompressibleNewtonianFluid",
         ConstitutiveModel::Type::CompressibleNewtonianFluid  },
        {"compressible newtonian fluid",
         ConstitutiveModel::Type::CompressibleNewtonianFluid  },
        {"compressible_newtonian_fluid",
         ConstitutiveModel::Type::CompressibleNewtonianFluid  },
};

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_HPP
