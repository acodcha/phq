// Copyright 2020-2024 Alexandre Coderre-Chabot
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

#ifndef PHQ_CONSTITUTIVE_MODEL_HPP
#define PHQ_CONSTITUTIVE_MODEL_HPP

#include <cstddef>
#include <functional>
#include <ostream>
#include <string>

#include "Base.hpp"
#include "Strain.hpp"
#include "StrainRate.hpp"
#include "Stress.hpp"

namespace PhQ {

// Type of a material's constitutive model.
enum class ConstitutiveModelType : int8_t {
  // Compressible Newtonian fluid constitutive model
  CompressibleNewtonianFluid,

  // Elastic isotropic solid constitutive model
  ElasticIsotropicSolid,

  // Incompressible Newtonian fluid constitutive model
  IncompressibleNewtonianFluid,
};

// Abstract base class for a material's constitutive model, which is a model that defines the
// relationship between the stress and the strain and strain rate at any point in the material.
template <typename Number = double>
class ConstitutiveModel {
public:
  // Forward declaration for class PhQ::ConstitutiveModel.
  class CompressibleNewtonianFluid;

  // Forward declaration for class PhQ::ConstitutiveModel.
  class ElasticIsotropicSolid;

  // Forward declaration for class PhQ::ConstitutiveModel.
  class IncompressibleNewtonianFluid;

  // Default constructor. Constructs this constitutive model.
  constexpr ConstitutiveModel() = default;

  // Destructor. Destroys this constitutive model.
  virtual ~ConstitutiveModel() noexcept = default;

  // Copy constructor. Constructs a constitutive model by copying another one.
  constexpr ConstitutiveModel(const ConstitutiveModel<Number>& other) = default;

  // Move constructor. Constructs a constitutive model by moving another one.
  constexpr ConstitutiveModel(ConstitutiveModel<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this constitutive model by copying another one.
  ConstitutiveModel<Number>& operator=(const ConstitutiveModel<Number>& other) = default;

  // Move assignment operator. Assigns this constitutive model by moving another one.
  ConstitutiveModel<Number>& operator=(ConstitutiveModel<Number>&& other) noexcept = default;

  // Returns this constitutive model's type.
  [[nodiscard]] virtual inline ConstitutiveModelType Type() const noexcept = 0;

  // Returns the stress resulting from a given strain and strain rate.
  [[nodiscard]] virtual inline PhQ::Stress<Number> Stress(
      const PhQ::Strain<Number>& strain, const PhQ::StrainRate<Number>& strain_rate) const = 0;

  // Returns the stress resulting from a given strain.
  [[nodiscard]] virtual inline PhQ::Stress<Number> Stress(
      const PhQ::Strain<Number>& strain) const = 0;

  // Returns the stress resulting from a given strain rate.
  [[nodiscard]] virtual inline PhQ::Stress<Number> Stress(
      const PhQ::StrainRate<Number>& strain_rate) const = 0;

  // Returns the strain resulting from a given stress.
  [[nodiscard]] virtual inline PhQ::Strain<Number> Strain(
      const PhQ::Stress<Number>& stress) const = 0;

  // Returns the strain rate resulting from a given stress.
  [[nodiscard]] virtual inline PhQ::StrainRate<Number> StrainRate(
      const PhQ::Stress<Number>& stress) const = 0;

  // Prints this constitutive model as a string.
  [[nodiscard]] virtual inline std::string Print() const = 0;

  // Serializes this constitutive model as a JSON message.
  [[nodiscard]] virtual inline std::string JSON() const = 0;

  // Serializes this constitutive model as an XML message.
  [[nodiscard]] virtual inline std::string XML() const = 0;

  // Serializes this constitutive model as a YAML message.
  [[nodiscard]] virtual inline std::string YAML() const = 0;
};

template <>
inline const std::map<ConstitutiveModelType, std::string_view>
    Internal::Abbreviations<ConstitutiveModelType>{
        {ConstitutiveModelType::ElasticIsotropicSolid,        "Elastic Isotropic Solid"       },
        {ConstitutiveModelType::IncompressibleNewtonianFluid, "Incompressible Newtonian Fluid"},
        {ConstitutiveModelType::CompressibleNewtonianFluid,   "Compressible Newtonian Fluid"  },
};

template <>
inline const std::unordered_map<std::string_view, ConstitutiveModelType>
    Internal::Spellings<ConstitutiveModelType>{
        {"Elastic Isotropic Solid",        ConstitutiveModelType::ElasticIsotropicSolid       },
        {"ELASTIC ISOTROPIC SOLID",        ConstitutiveModelType::ElasticIsotropicSolid       },
        {"elastic isotropic solid",        ConstitutiveModelType::ElasticIsotropicSolid       },
        {"ElasticIsotropicSolid",          ConstitutiveModelType::ElasticIsotropicSolid       },
        {"ELASTIC_ISOTROPIC_SOLID",        ConstitutiveModelType::ElasticIsotropicSolid       },
        {"elastic_isotropic_solid",        ConstitutiveModelType::ElasticIsotropicSolid       },
        {"Incompressible Newtonian Fluid", ConstitutiveModelType::IncompressibleNewtonianFluid},
        {"INCOMPRESSIBLE NEWTONIAN FLUID", ConstitutiveModelType::IncompressibleNewtonianFluid},
        {"incompressible newtonian fluid", ConstitutiveModelType::IncompressibleNewtonianFluid},
        {"IncompressibleNewtonianFluid",   ConstitutiveModelType::IncompressibleNewtonianFluid},
        {"INCOMPRESSIBLE_NEWTONIAN_FLUID", ConstitutiveModelType::IncompressibleNewtonianFluid},
        {"incompressible_newtonian_fluid", ConstitutiveModelType::IncompressibleNewtonianFluid},
        {"Compressible Newtonian Fluid",   ConstitutiveModelType::CompressibleNewtonianFluid  },
        {"COMPRESSIBLE NEWTONIAN FLUID",   ConstitutiveModelType::CompressibleNewtonianFluid  },
        {"compressible newtonian fluid",   ConstitutiveModelType::CompressibleNewtonianFluid  },
        {"CompressibleNewtonianFluid",     ConstitutiveModelType::CompressibleNewtonianFluid  },
        {"COMPRESSIBLE_NEWTONIAN_FLUID",   ConstitutiveModelType::CompressibleNewtonianFluid  },
        {"compressible_newtonian_fluid",   ConstitutiveModelType::CompressibleNewtonianFluid  },
};

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const ConstitutiveModel<Number>& model) {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ

#endif  // PHQ_CONSTITUTIVE_MODEL_HPP
