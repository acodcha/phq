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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_BASE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_BASE_HPP

#include "../Strain.hpp"
#include "../StrainRate.hpp"
#include "../Stress.hpp"

namespace PhQ {

class ConstitutiveModel {
public:
  enum class Type : int_least8_t {
    ElasticIsotropicSolid,
    IncompressibleNewtonianFluid,
    CompressibleNewtonianFluid,
  };

  virtual ~ConstitutiveModel() noexcept = default;

  virtual inline Type GetType() const noexcept = 0;

  virtual inline PhQ::Stress Stress(
      const PhQ::Strain& strain,
      const PhQ::StrainRate& strain_rate) const noexcept = 0;

  virtual inline PhQ::Stress Stress(
      const PhQ::Strain& strain) const noexcept = 0;

  virtual inline PhQ::Stress Stress(
      const PhQ::StrainRate& strain_rate) const noexcept = 0;

  virtual inline PhQ::Strain Strain(
      const PhQ::Stress& stress) const noexcept = 0;

  virtual inline PhQ::StrainRate StrainRate(
      const PhQ::Stress& stress) const noexcept = 0;

  virtual inline std::string Print() const noexcept = 0;

  virtual inline std::string JSON() const noexcept = 0;

  virtual inline std::string XML() const noexcept = 0;

  virtual inline std::string YAML() const noexcept = 0;

protected:
  constexpr ConstitutiveModel() noexcept = default;
};

template<> inline const std::map<ConstitutiveModel::Type, std::string_view>
    Abbreviations<ConstitutiveModel::Type>{
        {ConstitutiveModel::Type::ElasticIsotropicSolid,
         "Elastic Isotropic Solid"       },
        {ConstitutiveModel::Type::IncompressibleNewtonianFluid,
         "Incompressible Newtonian Fluid"},
        {ConstitutiveModel::Type::CompressibleNewtonianFluid,
         "Compressible Newtonian Fluid"  },
};

template<>
inline const std::unordered_map<std::string_view, ConstitutiveModel::Type>
    Spellings<ConstitutiveModel::Type>{
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

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_BASE_HPP
