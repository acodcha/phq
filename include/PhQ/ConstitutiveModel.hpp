// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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

/// \brief Abstract base class for a material's constitutive model, which is a model that defines
/// the relationship between the stress and the strain and strain rate at any point in the material.
class ConstitutiveModel {
public:
  // Forward declaration for class PhQ::ConstitutiveModel.
  template <typename Number = double>
  class CompressibleNewtonianFluid;

  // Forward declaration for class PhQ::ConstitutiveModel.
  template <typename Number = double>
  class ElasticIsotropicSolid;

  // Forward declaration for class PhQ::ConstitutiveModel.
  template <typename Number = double>
  class IncompressibleNewtonianFluid;

  /// \brief Type of a material's constitutive model.
  enum class Type : int8_t {
    /// \brief Compressible Newtonian fluid constitutive model
    CompressibleNewtonianFluid,

    /// \brief Elastic isotropic solid constitutive model
    ElasticIsotropicSolid,

    /// \brief Incompressible Newtonian fluid constitutive model
    IncompressibleNewtonianFluid,
  };

  /// \brief Default constructor. Constructs this constitutive model.
  constexpr ConstitutiveModel() = default;

  /// \brief Destructor. Destroys this constitutive model.
  virtual ~ConstitutiveModel() noexcept = default;

  /// \brief Copy constructor. Constructs a constitutive model by copying another one.
  constexpr ConstitutiveModel(const ConstitutiveModel& other) = default;

  /// \brief Move constructor. Constructs a constitutive model by moving another one.
  constexpr ConstitutiveModel(ConstitutiveModel&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this constitutive model by copying another one.
  ConstitutiveModel& operator=(const ConstitutiveModel& other) = default;

  /// \brief Move assignment operator. Assigns this constitutive model by moving another one.
  ConstitutiveModel& operator=(ConstitutiveModel&& other) noexcept = default;

  /// \brief Returns this constitutive model's type.
  [[nodiscard]] virtual inline Type GetType() const noexcept = 0;

  /// \brief Returns the stress resulting from a given strain and strain rate.
  [[nodiscard]] virtual inline PhQ::Stress<float> Stress(
      const PhQ::Strain<float>& strain, const PhQ::StrainRate<float>& strain_rate) const = 0;

  /// \brief Returns the stress resulting from a given strain and strain rate.
  [[nodiscard]] virtual inline PhQ::Stress<double> Stress(
      const PhQ::Strain<double>& strain, const PhQ::StrainRate<double>& strain_rate) const = 0;

  /// \brief Returns the stress resulting from a given strain and strain rate.
  [[nodiscard]] virtual inline PhQ::Stress<long double> Stress(
      const PhQ::Strain<long double>& strain,
      const PhQ::StrainRate<long double>& strain_rate) const = 0;

  /// \brief Returns the stress resulting from a given strain.
  [[nodiscard]] virtual inline PhQ::Stress<float> Stress(
      const PhQ::Strain<float>& strain) const = 0;

  /// \brief Returns the stress resulting from a given strain.
  [[nodiscard]] virtual inline PhQ::Stress<double> Stress(
      const PhQ::Strain<double>& strain) const = 0;

  /// \brief Returns the stress resulting from a given strain.
  [[nodiscard]] virtual inline PhQ::Stress<long double> Stress(
      const PhQ::Strain<long double>& strain) const = 0;

  /// \brief Returns the stress resulting from a given strain rate.
  [[nodiscard]] virtual inline PhQ::Stress<float> Stress(
      const PhQ::StrainRate<float>& strain_rate) const = 0;

  /// \brief Returns the stress resulting from a given strain rate.
  [[nodiscard]] virtual inline PhQ::Stress<double> Stress(
      const PhQ::StrainRate<double>& strain_rate) const = 0;

  /// \brief Returns the stress resulting from a given strain rate.
  [[nodiscard]] virtual inline PhQ::Stress<long double> Stress(
      const PhQ::StrainRate<long double>& strain_rate) const = 0;

  /// \brief Returns the strain resulting from a given stress.
  [[nodiscard]] virtual inline PhQ::Strain<float> Strain(
      const PhQ::Stress<float>& stress) const = 0;

  /// \brief Returns the strain resulting from a given stress.
  [[nodiscard]] virtual inline PhQ::Strain<double> Strain(
      const PhQ::Stress<double>& stress) const = 0;

  /// \brief Returns the strain resulting from a given stress.
  [[nodiscard]] virtual inline PhQ::Strain<long double> Strain(
      const PhQ::Stress<long double>& stress) const = 0;

  /// \brief Returns the strain rate resulting from a given stress.
  [[nodiscard]] virtual inline PhQ::StrainRate<float> StrainRate(
      const PhQ::Stress<float>& stress) const = 0;

  /// \brief Returns the strain rate resulting from a given stress.
  [[nodiscard]] virtual inline PhQ::StrainRate<double> StrainRate(
      const PhQ::Stress<double>& stress) const = 0;

  /// \brief Returns the strain rate resulting from a given stress.
  [[nodiscard]] virtual inline PhQ::StrainRate<long double> StrainRate(
      const PhQ::Stress<long double>& stress) const = 0;

  /// \brief Prints this constitutive model as a string.
  [[nodiscard]] virtual inline std::string Print() const = 0;

  /// \brief Serializes this constitutive model as a JSON message.
  [[nodiscard]] virtual inline std::string JSON() const = 0;

  /// \brief Serializes this constitutive model as an XML message.
  [[nodiscard]] virtual inline std::string XML() const = 0;

  /// \brief Serializes this constitutive model as a YAML message.
  [[nodiscard]] virtual inline std::string YAML() const = 0;
};

template <>
inline const std::map<typename ConstitutiveModel::Type, std::string_view>
    Internal::Abbreviations<typename ConstitutiveModel::Type>{
        {ConstitutiveModel::Type::ElasticIsotropicSolid,        "Elastic Isotropic Solid"       },
        {ConstitutiveModel::Type::IncompressibleNewtonianFluid, "Incompressible Newtonian Fluid"},
        {ConstitutiveModel::Type::CompressibleNewtonianFluid,   "Compressible Newtonian Fluid"  },
};

template <>
inline const std::unordered_map<std::string_view, typename ConstitutiveModel::Type>
    Internal::Spellings<typename ConstitutiveModel::Type>{
        {"Elastic Isotropic Solid",        ConstitutiveModel::Type::ElasticIsotropicSolid       },
        {"ELASTIC ISOTROPIC SOLID",        ConstitutiveModel::Type::ElasticIsotropicSolid       },
        {"elastic isotropic solid",        ConstitutiveModel::Type::ElasticIsotropicSolid       },
        {"ElasticIsotropicSolid",          ConstitutiveModel::Type::ElasticIsotropicSolid       },
        {"ELASTIC_ISOTROPIC_SOLID",        ConstitutiveModel::Type::ElasticIsotropicSolid       },
        {"elastic_isotropic_solid",        ConstitutiveModel::Type::ElasticIsotropicSolid       },
        {"Incompressible Newtonian Fluid", ConstitutiveModel::Type::IncompressibleNewtonianFluid},
        {"INCOMPRESSIBLE NEWTONIAN FLUID", ConstitutiveModel::Type::IncompressibleNewtonianFluid},
        {"incompressible newtonian fluid", ConstitutiveModel::Type::IncompressibleNewtonianFluid},
        {"IncompressibleNewtonianFluid",   ConstitutiveModel::Type::IncompressibleNewtonianFluid},
        {"INCOMPRESSIBLE_NEWTONIAN_FLUID", ConstitutiveModel::Type::IncompressibleNewtonianFluid},
        {"incompressible_newtonian_fluid", ConstitutiveModel::Type::IncompressibleNewtonianFluid},
        {"Compressible Newtonian Fluid",   ConstitutiveModel::Type::CompressibleNewtonianFluid  },
        {"COMPRESSIBLE NEWTONIAN FLUID",   ConstitutiveModel::Type::CompressibleNewtonianFluid  },
        {"compressible newtonian fluid",   ConstitutiveModel::Type::CompressibleNewtonianFluid  },
        {"CompressibleNewtonianFluid",     ConstitutiveModel::Type::CompressibleNewtonianFluid  },
        {"COMPRESSIBLE_NEWTONIAN_FLUID",   ConstitutiveModel::Type::CompressibleNewtonianFluid  },
        {"compressible_newtonian_fluid",   ConstitutiveModel::Type::CompressibleNewtonianFluid  },
};

inline std::ostream& operator<<(std::ostream& stream, const ConstitutiveModel& model) {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ

#endif  // PHQ_CONSTITUTIVE_MODEL_HPP
