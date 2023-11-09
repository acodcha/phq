// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_HPP

#include <cstddef>
#include <functional>
#include <ostream>
#include <string>

#include "Base.hpp"
#include "Strain.hpp"
#include "StrainRate.hpp"
#include "Stress.hpp"

namespace PhQ {

// Abstract base class for a material's constitutive model, which is a model that defines the
// relationship between the stress and the strain and strain rate at any point in the material.
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

  // Forward declarations for class PhQ::ConstitutiveModel.
  class CompressibleNewtonianFluid;
  class ElasticIsotropicSolid;
  class IncompressibleNewtonianFluid;

  // Destructor. Destroys this constitutive model.
  virtual ~ConstitutiveModel() noexcept = default;

  // Copy constructor. Constructs a constitutive model by copying another one.
  constexpr ConstitutiveModel(const ConstitutiveModel& other) = default;

  // Move constructor. Constructs a constitutive model by moving another one.
  constexpr ConstitutiveModel(ConstitutiveModel&& other) noexcept = default;

  // Copy assignment operator. Assigns this constitutive model by copying another one.
  ConstitutiveModel& operator=(const ConstitutiveModel& other) = default;

  // Move assignment operator. Assigns this constitutive model by moving another one.
  ConstitutiveModel& operator=(ConstitutiveModel&& other) noexcept = default;

  // Returns this constitutive model's type.
  [[nodiscard]] virtual inline Type GetType() const noexcept = 0;

  // Returns the stress resulting from a given strain and strain rate.
  [[nodiscard]] virtual inline PhQ::Stress Stress(
      const PhQ::Strain& strain, const PhQ::StrainRate& strain_rate) const = 0;

  // Returns the stress resulting from a given strain.
  [[nodiscard]] virtual inline PhQ::Stress Stress(const PhQ::Strain& strain) const = 0;

  // Returns the stress resulting from a given strain rate.
  [[nodiscard]] virtual inline PhQ::Stress Stress(const PhQ::StrainRate& strain_rate) const = 0;

  // Returns the strain resulting from a given stress.
  [[nodiscard]] virtual inline PhQ::Strain Strain(const PhQ::Stress& stress) const = 0;

  // Returns the strain rate resulting from a given stress.
  [[nodiscard]] virtual inline PhQ::StrainRate StrainRate(const PhQ::Stress& stress) const = 0;

  // Prints this constitutive model as a string.
  [[nodiscard]] virtual inline std::string Print() const = 0;

  // Serializes this constitutive model as a JSON message.
  [[nodiscard]] virtual inline std::string JSON() const = 0;

  // Serializes this constitutive model as an XML message.
  [[nodiscard]] virtual inline std::string XML() const = 0;

  // Serializes this constitutive model as a YAML message.
  [[nodiscard]] virtual inline std::string YAML() const = 0;

protected:
  // Default constructor. Constructs this constitutive model.
  constexpr ConstitutiveModel() = default;
};

template <>
inline const std::map<ConstitutiveModel::Type, std::string_view>
    Internal::Abbreviations<ConstitutiveModel::Type>{
        {ConstitutiveModel::Type::ElasticIsotropicSolid,        "Elastic Isotropic Solid"       },
        {ConstitutiveModel::Type::IncompressibleNewtonianFluid, "Incompressible Newtonian Fluid"},
        {ConstitutiveModel::Type::CompressibleNewtonianFluid,   "Compressible Newtonian Fluid"  },
};

template <>
inline const std::unordered_map<std::string_view, ConstitutiveModel::Type>
    Internal::Spellings<ConstitutiveModel::Type>{
        {"Elastic Isotropic Solid",        ConstitutiveModel::Type::ElasticIsotropicSolid       },
        {"ElasticIsotropicSolid",          ConstitutiveModel::Type::ElasticIsotropicSolid       },
        {"elastic isotropic solid",        ConstitutiveModel::Type::ElasticIsotropicSolid       },
        {"elastic_isotropic_solid",        ConstitutiveModel::Type::ElasticIsotropicSolid       },
        {"Incompressible Newtonian Fluid", ConstitutiveModel::Type::IncompressibleNewtonianFluid},
        {"IncompressibleNewtonianFluid",   ConstitutiveModel::Type::IncompressibleNewtonianFluid},
        {"incompressible newtonian fluid", ConstitutiveModel::Type::IncompressibleNewtonianFluid},
        {"incompressible_newtonian_fluid", ConstitutiveModel::Type::IncompressibleNewtonianFluid},
        {"Compressible Newtonian Fluid",   ConstitutiveModel::Type::CompressibleNewtonianFluid  },
        {"CompressibleNewtonianFluid",     ConstitutiveModel::Type::CompressibleNewtonianFluid  },
        {"compressible newtonian fluid",   ConstitutiveModel::Type::CompressibleNewtonianFluid  },
        {"compressible_newtonian_fluid",   ConstitutiveModel::Type::CompressibleNewtonianFluid  },
};

inline std::ostream& operator<<(std::ostream& stream, const ConstitutiveModel& model) {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_HPP
