// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
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

#ifndef PHQ_CONSTITUTIVE_MODEL_ELASTIC_ISOTROPIC_SOLID_HPP
#define PHQ_CONSTITUTIVE_MODEL_ELASTIC_ISOTROPIC_SOLID_HPP

#include <cmath>
#include <cstddef>
#include <functional>
#include <ostream>
#include <string>

#include "../Base.hpp"
#include "../BulkDynamicViscosity.hpp"
#include "../ConstitutiveModel.hpp"
#include "../DynamicViscosity.hpp"
#include "../IsentropicBulkModulus.hpp"
#include "../IsothermalBulkModulus.hpp"
#include "../LameFirstModulus.hpp"
#include "../PoissonRatio.hpp"
#include "../PWaveModulus.hpp"
#include "../ShearModulus.hpp"
#include "../Strain.hpp"
#include "../StrainRate.hpp"
#include "../Stress.hpp"
#include "../SymmetricDyad.hpp"
#include "../Unit/Pressure.hpp"
#include "../YoungModulus.hpp"

namespace PhQ {

/// \brief Constitutive model for an elastic isotropic solid. This is the simplest constitutive
/// model for a deformable solid material.
template <typename NumericType = double>
class ConstitutiveModel::ElasticIsotropicSolid : public ConstitutiveModel {
public:
  /// \brief Default constructor. Constructs an elastic isotropic solid constitutive model with an
  /// uninitialized value.
  ElasticIsotropicSolid() : ConstitutiveModel() {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// Young's modulus and Poisson's ratio.
  ElasticIsotropicSolid(const YoungModulus<NumericType>& young_modulus,
                        const PoissonRatio<NumericType>& poisson_ratio)
    : ConstitutiveModel(),
      shear_modulus(
          young_modulus.Value()
          / (static_cast<NumericType>(2) * (static_cast<NumericType>(1) + poisson_ratio.Value()))),
      lame_first_modulus(young_modulus.Value() * poisson_ratio.Value()
                         / ((static_cast<NumericType>(1) + poisson_ratio.Value())
                            * (static_cast<NumericType>(1)
                               - static_cast<NumericType>(2) * poisson_ratio.Value()))) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// Young's modulus and shear modulus.
  constexpr ElasticIsotropicSolid(const YoungModulus<NumericType>& young_modulus,
                                  const ShearModulus<NumericType>& shear_modulus)
    : ConstitutiveModel(), shear_modulus(shear_modulus),
      lame_first_modulus(
          (shear_modulus.Value()
           * (young_modulus.Value() - static_cast<NumericType>(2) * shear_modulus.Value()))
          / (static_cast<NumericType>(3) * shear_modulus.Value() - young_modulus.Value())) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// Young's modulus and isentropic bulk modulus.
  ElasticIsotropicSolid(const YoungModulus<NumericType>& young_modulus,
                        const IsentropicBulkModulus<NumericType>& isentropic_bulk_modulus)
    : ConstitutiveModel(),
      shear_modulus(
          static_cast<NumericType>(3) * young_modulus.Value() * isentropic_bulk_modulus.Value()
          / (static_cast<NumericType>(9) * isentropic_bulk_modulus.Value()
             - young_modulus.Value())),
      lame_first_modulus(
          static_cast<NumericType>(3) * isentropic_bulk_modulus.Value()
          * (static_cast<NumericType>(3) * isentropic_bulk_modulus.Value() - young_modulus.Value())
          / (static_cast<NumericType>(9) * isentropic_bulk_modulus.Value()
             - young_modulus.Value())) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// Young's modulus and isothermal bulk modulus.
  ElasticIsotropicSolid(const YoungModulus<NumericType>& young_modulus,
                        const IsothermalBulkModulus<NumericType>& isothermal_bulk_modulus)
    : ConstitutiveModel(),
      shear_modulus(
          static_cast<NumericType>(3) * young_modulus.Value() * isothermal_bulk_modulus.Value()
          / (static_cast<NumericType>(9) * isothermal_bulk_modulus.Value()
             - young_modulus.Value())),
      lame_first_modulus(
          static_cast<NumericType>(3) * isothermal_bulk_modulus.Value()
          * (static_cast<NumericType>(3) * isothermal_bulk_modulus.Value() - young_modulus.Value())
          / (static_cast<NumericType>(9) * isothermal_bulk_modulus.Value()
             - young_modulus.Value())) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// Young's modulus and Lamé's first modulus.
  constexpr ElasticIsotropicSolid(const YoungModulus<NumericType>& young_modulus,
                                  const LameFirstModulus<NumericType>& lame_first_modulus)
    : ConstitutiveModel(),
      shear_modulus(
          static_cast<NumericType>(0.25)
          * (young_modulus.Value() - static_cast<NumericType>(3) * lame_first_modulus.Value()
             + ::std::sqrt(::std::pow(young_modulus.Value(), 2)
                           + static_cast<NumericType>(9) * ::std::pow(lame_first_modulus.Value(), 2)
                           + static_cast<NumericType>(2) * young_modulus.Value()
                                 * lame_first_modulus.Value()))),
      lame_first_modulus(lame_first_modulus) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// Young's modulus and P-wave modulus.
  constexpr ElasticIsotropicSolid(const YoungModulus<NumericType>& young_modulus,
                                  const PWaveModulus<NumericType>& p_wave_modulus)
    : ConstitutiveModel(),
      shear_modulus(
          static_cast<NumericType>(0.125)
          * (static_cast<NumericType>(3) * p_wave_modulus.Value() + young_modulus.Value()
             - ::std::sqrt(
                 ::std::pow(young_modulus.Value(), 2)
                 + static_cast<NumericType>(9) * ::std::pow(p_wave_modulus.Value(), 2)
                 - static_cast<NumericType>(10) * young_modulus.Value() * p_wave_modulus.Value()))),
      lame_first_modulus(
          static_cast<NumericType>(0.25)
          * (p_wave_modulus.Value() - young_modulus.Value()
             + ::std::sqrt(::std::pow(young_modulus.Value(), 2)
                           + static_cast<NumericType>(9) * ::std::pow(p_wave_modulus.Value(), 2)
                           - static_cast<NumericType>(10) * young_modulus.Value()
                                 * p_wave_modulus.Value()))) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// shear modulus and Poisson's ratio.
  constexpr ElasticIsotropicSolid(const ShearModulus<NumericType>& shear_modulus,
                                  const PoissonRatio<NumericType>& poisson_ratio)
    : ConstitutiveModel(), shear_modulus(shear_modulus),
      lame_first_modulus(
          (static_cast<NumericType>(2) * shear_modulus.Value() * poisson_ratio.Value())
          / (static_cast<NumericType>(1) - static_cast<NumericType>(2) * poisson_ratio.Value())) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// shear modulus and isentropic bulk modulus.
  constexpr ElasticIsotropicSolid(const ShearModulus<NumericType>& shear_modulus,
                                  const IsentropicBulkModulus<NumericType>& isentropic_bulk_modulus)
    : ConstitutiveModel(), shear_modulus(shear_modulus),
      lame_first_modulus(
          isentropic_bulk_modulus.Value()
          - static_cast<NumericType>(2) / static_cast<NumericType>(3) * shear_modulus.Value()) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// shear modulus and isothermal bulk modulus.
  constexpr ElasticIsotropicSolid(const ShearModulus<NumericType>& shear_modulus,
                                  const IsothermalBulkModulus<NumericType>& isothermal_bulk_modulus)
    : ConstitutiveModel(), shear_modulus(shear_modulus),
      lame_first_modulus(
          isothermal_bulk_modulus.Value()
          - static_cast<NumericType>(2) / static_cast<NumericType>(3) * shear_modulus.Value()) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// shear modulus and Lamé's first modulus.
  constexpr ElasticIsotropicSolid(const ShearModulus<NumericType>& shear_modulus,
                                  const LameFirstModulus<NumericType>& lame_first_modulus)
    : ConstitutiveModel(), shear_modulus(shear_modulus), lame_first_modulus(lame_first_modulus) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// shear modulus and P-wave modulus.
  constexpr ElasticIsotropicSolid(const ShearModulus<NumericType>& shear_modulus,
                                  const PWaveModulus<NumericType>& p_wave_modulus)
    : ConstitutiveModel(), shear_modulus(shear_modulus),
      lame_first_modulus(
          p_wave_modulus.Value() - static_cast<NumericType>(2) * shear_modulus.Value()) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// isentropic bulk modulus and Lamé's first modulus.
  constexpr ElasticIsotropicSolid(const IsentropicBulkModulus<NumericType>& isentropic_bulk_modulus,
                                  const LameFirstModulus<NumericType>& lame_first_modulus)
    : ConstitutiveModel(),
      shear_modulus(static_cast<NumericType>(1.5)
                    * (isentropic_bulk_modulus.Value() - lame_first_modulus.Value())),
      lame_first_modulus(lame_first_modulus) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// isothermal bulk modulus and Lamé's first modulus.
  constexpr ElasticIsotropicSolid(const IsothermalBulkModulus<NumericType>& isothermal_bulk_modulus,
                                  const LameFirstModulus<NumericType>& lame_first_modulus)
    : ConstitutiveModel(),
      shear_modulus(static_cast<NumericType>(1.5)
                    * (isothermal_bulk_modulus.Value() - lame_first_modulus.Value())),
      lame_first_modulus(lame_first_modulus) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// isentropic bulk modulus and P-wave modulus.
  constexpr ElasticIsotropicSolid(const IsentropicBulkModulus<NumericType>& isentropic_bulk_modulus,
                                  const PWaveModulus<NumericType>& p_wave_modulus)
    : ConstitutiveModel(),
      shear_modulus(static_cast<NumericType>(0.75)
                    * (p_wave_modulus.Value() - isentropic_bulk_modulus.Value())),
      lame_first_modulus(static_cast<NumericType>(1.5) * isentropic_bulk_modulus.Value()
                         - static_cast<NumericType>(0.5) * p_wave_modulus.Value()) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// isothermal bulk modulus and P-wave modulus.
  constexpr ElasticIsotropicSolid(const IsothermalBulkModulus<NumericType>& isothermal_bulk_modulus,
                                  const PWaveModulus<NumericType>& p_wave_modulus)
    : ConstitutiveModel(),
      shear_modulus(static_cast<NumericType>(0.75)
                    * (p_wave_modulus.Value() - isothermal_bulk_modulus.Value())),
      lame_first_modulus(static_cast<NumericType>(1.5) * isothermal_bulk_modulus.Value()
                         - static_cast<NumericType>(0.5) * p_wave_modulus.Value()) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// isentropic bulk modulus and Poisson's ratio.
  constexpr ElasticIsotropicSolid(const IsentropicBulkModulus<NumericType>& isentropic_bulk_modulus,
                                  const PoissonRatio<NumericType>& poisson_ratio)
    : ConstitutiveModel(),
      shear_modulus(
          static_cast<NumericType>(3) * isentropic_bulk_modulus.Value()
          * (static_cast<NumericType>(1) - static_cast<NumericType>(2) * poisson_ratio.Value())
          / (static_cast<NumericType>(2) + static_cast<NumericType>(2) * poisson_ratio.Value())),
      lame_first_modulus(
          static_cast<NumericType>(3) * isentropic_bulk_modulus.Value() * poisson_ratio.Value()
          / (static_cast<NumericType>(1) + poisson_ratio.Value())) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// isothermal bulk modulus and Poisson's ratio.
  constexpr ElasticIsotropicSolid(const IsothermalBulkModulus<NumericType>& isothermal_bulk_modulus,
                                  const PoissonRatio<NumericType>& poisson_ratio)
    : ConstitutiveModel(),
      shear_modulus(
          static_cast<NumericType>(3) * isothermal_bulk_modulus.Value()
          * (static_cast<NumericType>(1) - static_cast<NumericType>(2) * poisson_ratio.Value())
          / (static_cast<NumericType>(2) + static_cast<NumericType>(2) * poisson_ratio.Value())),
      lame_first_modulus(
          static_cast<NumericType>(3) * isothermal_bulk_modulus.Value() * poisson_ratio.Value()
          / (static_cast<NumericType>(1) + poisson_ratio.Value())) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// Lamé's first modulus and P-wave modulus.
  constexpr ElasticIsotropicSolid(const LameFirstModulus<NumericType>& lame_first_modulus,
                                  const PWaveModulus<NumericType>& p_wave_modulus)
    : ConstitutiveModel(),
      shear_modulus(
          static_cast<NumericType>(0.5) * (p_wave_modulus.Value() - lame_first_modulus.Value())),
      lame_first_modulus(lame_first_modulus) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// Lamé's first modulus and Poisson's ratio.
  constexpr ElasticIsotropicSolid(const LameFirstModulus<NumericType>& lame_first_modulus,
                                  const PoissonRatio<NumericType>& poisson_ratio)
    : ConstitutiveModel(),
      shear_modulus(
          lame_first_modulus.Value()
          * (static_cast<NumericType>(1) - static_cast<NumericType>(2) * poisson_ratio.Value())
          / (static_cast<NumericType>(2) * poisson_ratio.Value())),
      lame_first_modulus(lame_first_modulus) {}

  /// \brief Constructor. Constructs an elastic isotropic solid constitutive model from a given
  /// P-wave modulus and Poisson's ratio.
  constexpr ElasticIsotropicSolid(const PWaveModulus<NumericType>& p_wave_modulus,
                                  const PoissonRatio<NumericType>& poisson_ratio)
    : ConstitutiveModel(),
      shear_modulus(
          p_wave_modulus.Value()
          * (static_cast<NumericType>(1) - static_cast<NumericType>(2) * poisson_ratio.Value())
          / (static_cast<NumericType>(2) - static_cast<NumericType>(2) * poisson_ratio.Value())),
      lame_first_modulus(p_wave_modulus.Value() * poisson_ratio.Value()
                         / (static_cast<NumericType>(1) - poisson_ratio.Value())) {}

  /// \brief Destructor. Destroys this elastic isotropic solid constitutive model.
  ~ElasticIsotropicSolid() noexcept override = default;

  /// \brief Copy constructor. Constructs an elastic isotropic solid constitutive model by copying
  /// another one.
  constexpr ElasticIsotropicSolid(const ElasticIsotropicSolid& other) = default;

  /// \brief Move constructor. Constructs an elastic isotropic solid constitutive model by moving
  /// another one.
  constexpr ElasticIsotropicSolid(ElasticIsotropicSolid&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this elastic isotropic solid constitutive model by
  /// copying another one.
  ElasticIsotropicSolid& operator=(const ElasticIsotropicSolid& other) = default;

  /// \brief Move assignment operator. Assigns this elastic isotropic solid constitutive model by
  /// moving another one.
  ElasticIsotropicSolid& operator=(ElasticIsotropicSolid&& other) noexcept = default;

  /// \brief Shear modulus of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline constexpr const PhQ::ShearModulus<NumericType>&
  ShearModulus() const noexcept {
    return shear_modulus;
  }

  /// \brief Lamé's first modulus of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline constexpr const PhQ::LameFirstModulus<NumericType>&
  LameFirstModulus() const noexcept {
    return lame_first_modulus;
  }

  /// \brief Young's modulus of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline PhQ::YoungModulus<NumericType> YoungModulus() const {
    const NumericType numerator{shear_modulus.Value()
                                * (static_cast<NumericType>(3) * lame_first_modulus.Value()
                                   + static_cast<NumericType>(2) * shear_modulus.Value())};
    const NumericType denominator{shear_modulus.Value() + lame_first_modulus.Value()};
    return PhQ::YoungModulus<NumericType>{numerator / denominator, Standard<Unit::Pressure>};
  }

  /// \brief Isentropic bulk modulus of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline PhQ::IsentropicBulkModulus<NumericType> IsentropicBulkModulus() const {
    return PhQ::IsentropicBulkModulus<NumericType>{
        lame_first_modulus.Value()
            + static_cast<NumericType>(2) / static_cast<NumericType>(3) * shear_modulus.Value(),
        Standard<Unit::Pressure>};
  }

  /// \brief Isothermal bulk modulus of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline PhQ::IsothermalBulkModulus<NumericType> IsothermalBulkModulus() const {
    return PhQ::IsothermalBulkModulus<NumericType>{
        lame_first_modulus.Value()
            + static_cast<NumericType>(2) / static_cast<NumericType>(3) * shear_modulus.Value(),
        Standard<Unit::Pressure>};
  }

  /// \brief P-wave modulus of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline PhQ::PWaveModulus<NumericType> PWaveModulus() const {
    return PhQ::PWaveModulus<NumericType>{
        lame_first_modulus.Value() + static_cast<NumericType>(2) * shear_modulus.Value(),
        Standard<Unit::Pressure>};
  }

  /// \brief Poisson's ratio of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline PhQ::PoissonRatio<NumericType> PoissonRatio() const {
    const NumericType numerator{static_cast<NumericType>(0.5) * lame_first_modulus.Value()};
    const NumericType denominator{shear_modulus.Value() + lame_first_modulus.Value()};
    return PhQ::PoissonRatio<NumericType>{numerator / denominator};
  }

  /// \brief Returns this constitutive model's type.
  [[nodiscard]] inline ConstitutiveModel::Type GetType() const noexcept override {
    return ConstitutiveModel::Type::ElasticIsotropicSolid;
  }

  /// \brief Returns the stress resulting from a given strain and strain rate. Since this is an
  /// elastic isotropic solid constitutive model, the strain rate does not contribute to the stress
  /// and is ignored.
  [[nodiscard]] inline PhQ::Stress<float> Stress(
      const PhQ::Strain<float>& strain,
      const PhQ::StrainRate<float>& /*strain_rate*/) const override {
    return this->Stress(strain);
  }

  /// \brief Returns the stress resulting from a given strain and strain rate. Since this is an
  /// elastic isotropic solid constitutive model, the strain rate does not contribute to the stress
  /// and is ignored.
  [[nodiscard]] inline PhQ::Stress<double> Stress(
      const PhQ::Strain<double>& strain,
      const PhQ::StrainRate<double>& /*strain_rate*/) const override {
    return this->Stress(strain);
  }

  /// \brief Returns the stress resulting from a given strain and strain rate. Since this is an
  /// elastic isotropic solid constitutive model, the strain rate does not contribute to the stress
  /// and is ignored.
  [[nodiscard]] inline PhQ::Stress<long double> Stress(
      const PhQ::Strain<long double>& strain,
      const PhQ::StrainRate<long double>& /*strain_rate*/) const override {
    return this->Stress(strain);
  }

  /// \brief Returns the stress resulting from a given strain.
  [[nodiscard]] inline PhQ::Stress<float> Stress(const PhQ::Strain<float>& strain) const override {
    // stress = a * strain + b * trace(strain) * identity_matrix
    // a = 2 * shear_modulus
    // b = lame_first_modulus
    const float temporary{static_cast<float>(lame_first_modulus.Value())
                          * static_cast<float>(strain.Value().Trace())};
    return {
        static_cast<float>(2) * static_cast<float>(shear_modulus.Value())
                * static_cast<SymmetricDyad<float>>(strain.Value())
            + SymmetricDyad<float>{temporary, static_cast<float>(0), static_cast<float>(0),
                                   temporary, static_cast<float>(0), temporary},
        Standard<Unit::Pressure>
    };
  }

  /// \brief Returns the stress resulting from a given strain.
  [[nodiscard]] inline PhQ::Stress<double> Stress(
      const PhQ::Strain<double>& strain) const override {
    // stress = a * strain + b * trace(strain) * identity_matrix
    // a = 2 * shear_modulus
    // b = lame_first_modulus
    const double temporary{static_cast<double>(lame_first_modulus.Value())
                           * static_cast<double>(strain.Value().Trace())};
    return {
        static_cast<double>(2) * static_cast<double>(shear_modulus.Value())
                * static_cast<SymmetricDyad<double>>(strain.Value())
            + SymmetricDyad<double>{temporary, static_cast<double>(0), static_cast<double>(0),
                                    temporary, static_cast<double>(0), temporary},
        Standard<Unit::Pressure>
    };
  }

  /// \brief Returns the stress resulting from a given strain.
  [[nodiscard]] inline PhQ::Stress<long double> Stress(
      const PhQ::Strain<long double>& strain) const override {
    // stress = a * strain + b * trace(strain) * identity_matrix
    // a = 2 * shear_modulus
    // b = lame_first_modulus
    const long double temporary{static_cast<long double>(lame_first_modulus.Value())
                                * static_cast<long double>(strain.Value().Trace())};
    return {
        static_cast<long double>(2) * static_cast<long double>(shear_modulus.Value())
                * static_cast<SymmetricDyad<long double>>(strain.Value())
            + SymmetricDyad<long double>{temporary, static_cast<long double>(0),
                                         static_cast<long double>(0), temporary,
                                         static_cast<long double>(0), temporary},
        Standard<Unit::Pressure>
    };
  }

  /// \brief Returns the stress resulting from a given strain rate. Since this is an elastic
  /// isotropic solid constitutive model, the strain rate does not contribute to the stress, so this
  /// always returns a stress of zero.
  [[nodiscard]] inline PhQ::Stress<float> Stress(
      const PhQ::StrainRate<float>& /*strain_rate*/) const override {
    return PhQ::Stress<float>::Zero();
  }

  /// \brief Returns the stress resulting from a given strain rate. Since this is an elastic
  /// isotropic solid constitutive model, the strain rate does not contribute to the stress, so this
  /// always returns a stress of zero.
  [[nodiscard]] inline PhQ::Stress<double> Stress(
      const PhQ::StrainRate<double>& /*strain_rate*/) const override {
    return PhQ::Stress<double>::Zero();
  }

  /// \brief Returns the stress resulting from a given strain rate. Since this is an elastic
  /// isotropic solid constitutive model, the strain rate does not contribute to the stress, so this
  /// always returns a stress of zero.
  [[nodiscard]] inline PhQ::Stress<long double> Stress(
      const PhQ::StrainRate<long double>& /*strain_rate*/) const override {
    return PhQ::Stress<long double>::Zero();
  }

  /// \brief Returns the strain resulting from a given stress.
  [[nodiscard]] inline PhQ::Strain<float> Strain(const PhQ::Stress<float>& stress) const override {
    // strain = a * stress + b * trace(stress) * identity_matrix
    // a = 1 / (2 * shear_modulus)
    // b = -1 * lame_first_modulus / (2 * shear_modulus * (2 * shear_modulus + 3
    //     * lame_first_modulus))
    const float a{static_cast<float>(1)
                  / (static_cast<float>(2) * static_cast<float>(shear_modulus.Value()))};
    const float b{-static_cast<float>(lame_first_modulus.Value())
                  / (static_cast<float>(2) * static_cast<float>(shear_modulus.Value())
                     * (static_cast<float>(2) * static_cast<float>(shear_modulus.Value())
                        + static_cast<float>(3) * static_cast<float>(lame_first_modulus.Value())))};
    const float c{b * static_cast<float>(stress.Value().Trace())};
    return PhQ::Strain<float>{
        a * static_cast<SymmetricDyad<float>>(stress.Value())
        + SymmetricDyad<float>{
                               c, static_cast<float>(0), static_cast<float>(0), c, static_cast<float>(0), c}
    };
  }

  /// \brief Returns the strain resulting from a given stress.
  [[nodiscard]] inline PhQ::Strain<double> Strain(
      const PhQ::Stress<double>& stress) const override {
    // strain = a * stress + b * trace(stress) * identity_matrix
    // a = 1 / (2 * shear_modulus)
    // b = -1 * lame_first_modulus / (2 * shear_modulus * (2 * shear_modulus + 3
    //     * lame_first_modulus))
    const double a{static_cast<double>(1)
                   / (static_cast<double>(2) * static_cast<double>(shear_modulus.Value()))};
    const double b{
        -static_cast<double>(lame_first_modulus.Value())
        / (static_cast<double>(2) * static_cast<double>(shear_modulus.Value())
           * (static_cast<double>(2) * static_cast<double>(shear_modulus.Value())
              + static_cast<double>(3) * static_cast<double>(lame_first_modulus.Value())))};
    const double c{b * static_cast<double>(stress.Value().Trace())};
    return PhQ::Strain<double>{
        a * static_cast<SymmetricDyad<double>>(stress.Value())
        + SymmetricDyad<double>{
                                c, static_cast<double>(0), static_cast<double>(0), c, static_cast<double>(0), c}
    };
  }

  /// \brief Returns the strain resulting from a given stress.
  [[nodiscard]] inline PhQ::Strain<long double> Strain(
      const PhQ::Stress<long double>& stress) const override {
    // strain = a * stress + b * trace(stress) * identity_matrix
    // a = 1 / (2 * shear_modulus)
    // b = -1 * lame_first_modulus / (2 * shear_modulus * (2 * shear_modulus + 3
    //     * lame_first_modulus))
    const long double a{
        static_cast<long double>(1)
        / (static_cast<long double>(2) * static_cast<long double>(shear_modulus.Value()))};
    const long double b{
        -static_cast<long double>(lame_first_modulus.Value())
        / (static_cast<long double>(2) * static_cast<long double>(shear_modulus.Value())
           * (static_cast<long double>(2) * static_cast<long double>(shear_modulus.Value())
              + static_cast<long double>(3)
                    * static_cast<long double>(lame_first_modulus.Value())))};
    const long double c{b * static_cast<long double>(stress.Value().Trace())};
    return PhQ::Strain<long double>{
        a * static_cast<SymmetricDyad<long double>>(stress.Value())
        + SymmetricDyad<long double>{c, static_cast<long double>(0), static_cast<long double>(0), c,
                                     static_cast<long double>(0), c}
    };
  }

  /// \brief Returns the strain rate resulting from a given stress. Since this is an elastic
  /// isotropic solid constitutive model, stress does not depend on strain rate, so this always
  /// returns a strain rate of zero.
  [[nodiscard]] inline PhQ::StrainRate<float> StrainRate(
      const PhQ::Stress<float>& /*stress*/) const override {
    return PhQ::StrainRate<float>::Zero();
  }

  /// \brief Returns the strain rate resulting from a given stress. Since this is an elastic
  /// isotropic solid constitutive model, stress does not depend on strain rate, so this always
  /// returns a strain rate of zero.
  [[nodiscard]] inline PhQ::StrainRate<double> StrainRate(
      const PhQ::Stress<double>& /*stress*/) const override {
    return PhQ::StrainRate<double>::Zero();
  }

  /// \brief Returns the strain rate resulting from a given stress. Since this is an elastic
  /// isotropic solid constitutive model, stress does not depend on strain rate, so this always
  /// returns a strain rate of zero.
  [[nodiscard]] inline PhQ::StrainRate<long double> StrainRate(
      const PhQ::Stress<long double>& /*stress*/) const override {
    return PhQ::StrainRate<long double>::Zero();
  }

  /// \brief Prints this elastic isotropic solid constitutive model as a string.
  [[nodiscard]] inline std::string Print() const override {
    return {"Type = " + std::string{Abbreviation(this->GetType())} + ", Shear Modulus = "
            + shear_modulus.Print() + ", Lamé's First Modulus = " + lame_first_modulus.Print()};
  }

  /// \brief Serializes this elastic isotropic solid constitutive model as a JSON message.
  [[nodiscard]] inline std::string JSON() const override {
    return {R"({"type":")" + SnakeCase(Abbreviation(this->GetType())) + R"(","shear_modulus":)"
            + shear_modulus.JSON() + ",\"lame_first_modulus\":" + lame_first_modulus.JSON() + "}"};
  }

  /// \brief Serializes this elastic isotropic solid constitutive model as an XML message.
  [[nodiscard]] inline std::string XML() const override {
    return {"<type>" + SnakeCase(Abbreviation(this->GetType())) + "</type><shear_modulus>"
            + shear_modulus.XML() + "</shear_modulus><lame_first_modulus>"
            + lame_first_modulus.XML() + "</lame_first_modulus>"};
  }

  /// \brief Serializes this elastic isotropic solid constitutive model as a YAML message.
  [[nodiscard]] inline std::string YAML() const override {
    return {"{type:\"" + SnakeCase(Abbreviation(this->GetType())) + "\",shear_modulus:"
            + shear_modulus.YAML() + ",lame_first_modulus:" + lame_first_modulus.YAML() + "}"};
  }

private:
  /// \brief Shear modulus of this elastic isotropic solid constitutive model.
  PhQ::ShearModulus<NumericType> shear_modulus;

  /// \brief Lamé's first modulus of this elastic isotropic solid constitutive model.
  PhQ::LameFirstModulus<NumericType> lame_first_modulus;
};

template <typename NumericType>
inline constexpr bool operator==(
    const typename ConstitutiveModel::ElasticIsotropicSolid<NumericType>& left,
    const typename ConstitutiveModel::ElasticIsotropicSolid<NumericType>& right) noexcept {
  return left.ShearModulus() == right.ShearModulus()
         && left.LameFirstModulus() == right.LameFirstModulus();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const typename ConstitutiveModel::ElasticIsotropicSolid<NumericType>& left,
    const typename ConstitutiveModel::ElasticIsotropicSolid<NumericType>& right) noexcept {
  return left.ShearModulus() != right.ShearModulus()
         || left.LameFirstModulus() != right.LameFirstModulus();
}

template <typename NumericType>
inline constexpr bool operator<(
    const typename ConstitutiveModel::ElasticIsotropicSolid<NumericType>& left,
    const typename ConstitutiveModel::ElasticIsotropicSolid<NumericType>& right) noexcept {
  if (left.ShearModulus() != right.ShearModulus()) {
    return left.ShearModulus() < right.ShearModulus();
  }
  return left.LameFirstModulus() < right.LameFirstModulus();
}

template <typename NumericType>
inline constexpr bool operator>(
    const typename ConstitutiveModel::ElasticIsotropicSolid<NumericType>& left,
    const typename ConstitutiveModel::ElasticIsotropicSolid<NumericType>& right) noexcept {
  if (left.ShearModulus() != right.ShearModulus()) {
    return left.ShearModulus() > right.ShearModulus();
  }
  return left.LameFirstModulus() > right.LameFirstModulus();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const typename ConstitutiveModel::ElasticIsotropicSolid<NumericType>& left,
    const typename ConstitutiveModel::ElasticIsotropicSolid<NumericType>& right) noexcept {
  return !(left > right);
}

template <typename NumericType>
inline constexpr bool operator>=(
    const typename ConstitutiveModel::ElasticIsotropicSolid<NumericType>& left,
    const typename ConstitutiveModel::ElasticIsotropicSolid<NumericType>& right) noexcept {
  return !(left < right);
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream,
    const typename ConstitutiveModel::ElasticIsotropicSolid<NumericType>& model) {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<typename PhQ::ConstitutiveModel::ElasticIsotropicSolid<NumericType>> {
  size_t operator()(
      const typename PhQ::ConstitutiveModel::ElasticIsotropicSolid<NumericType>& model) const {
    size_t result{17};
    result = static_cast<size_t>(31) * result
             + hash<PhQ::ShearModulus<NumericType>>()(model.ShearModulus());
    result = static_cast<size_t>(31) * result
             + hash<PhQ::LameFirstModulus<NumericType>>()(model.LameFirstModulus());
    return result;
  }
};

}  // namespace std

#endif  // PHQ_CONSTITUTIVE_MODEL_ELASTIC_ISOTROPIC_SOLID_HPP
