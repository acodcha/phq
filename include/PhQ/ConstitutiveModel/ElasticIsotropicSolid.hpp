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

// Constitutive model for an elastic isotropic solid. This is the simplest constitutive model for a
// deformable solid material.
template <typename Number = double>
class ConstitutiveModel::ElasticIsotropicSolid : public ConstitutiveModel {
public:
  // Default constructor. Constructs an elastic isotropic solid constitutive model with an
  // uninitialized value.
  ElasticIsotropicSolid() : ConstitutiveModel() {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given Young's
  // modulus and Poisson's ratio.
  ElasticIsotropicSolid(
      const YoungModulus<Number>& young_modulus, const PoissonRatio<Number>& poisson_ratio)
    : ConstitutiveModel(),
      shear_modulus(young_modulus.Value()
                    / (static_cast<Number>(2) * (static_cast<Number>(1) + poisson_ratio.Value()))),
      lame_first_modulus(
          young_modulus.Value() * poisson_ratio.Value()
          / ((static_cast<Number>(1) + poisson_ratio.Value())
             * (static_cast<Number>(1) - static_cast<Number>(2) * poisson_ratio.Value()))) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given Young's
  // modulus and shear modulus.
  constexpr ElasticIsotropicSolid(
      const YoungModulus<Number>& young_modulus, const ShearModulus<Number>& shear_modulus)
    : ConstitutiveModel(), shear_modulus(shear_modulus),
      lame_first_modulus(
          (shear_modulus.Value()
           * (young_modulus.Value() - static_cast<Number>(2) * shear_modulus.Value()))
          / (static_cast<Number>(3) * shear_modulus.Value() - young_modulus.Value())) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given Young's
  // modulus and isentropic bulk modulus.
  ElasticIsotropicSolid(const YoungModulus<Number>& young_modulus,
                        const IsentropicBulkModulus<Number>& isentropic_bulk_modulus)
    : ConstitutiveModel(),
      shear_modulus(
          static_cast<Number>(3) * young_modulus.Value() * isentropic_bulk_modulus.Value()
          / (static_cast<Number>(9) * isentropic_bulk_modulus.Value() - young_modulus.Value())),
      lame_first_modulus(
          static_cast<Number>(3) * isentropic_bulk_modulus.Value()
          * (static_cast<Number>(3) * isentropic_bulk_modulus.Value() - young_modulus.Value())
          / (static_cast<Number>(9) * isentropic_bulk_modulus.Value() - young_modulus.Value())) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given Young's
  // modulus and isothermal bulk modulus.
  ElasticIsotropicSolid(const YoungModulus<Number>& young_modulus,
                        const IsothermalBulkModulus<Number>& isothermal_bulk_modulus)
    : ConstitutiveModel(),
      shear_modulus(
          static_cast<Number>(3) * young_modulus.Value() * isothermal_bulk_modulus.Value()
          / (static_cast<Number>(9) * isothermal_bulk_modulus.Value() - young_modulus.Value())),
      lame_first_modulus(
          static_cast<Number>(3) * isothermal_bulk_modulus.Value()
          * (static_cast<Number>(3) * isothermal_bulk_modulus.Value() - young_modulus.Value())
          / (static_cast<Number>(9) * isothermal_bulk_modulus.Value() - young_modulus.Value())) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given Young's
  // modulus and Lamé's first modulus.
  constexpr ElasticIsotropicSolid(
      const YoungModulus<Number>& young_modulus, const LameFirstModulus<Number>& lame_first_modulus)
    : ConstitutiveModel(),
      shear_modulus(
          static_cast<Number>(0.25)
          * (young_modulus.Value() - static_cast<Number>(3) * lame_first_modulus.Value()
             + ::std::sqrt(
                 ::std::pow(young_modulus.Value(), 2)
                 + static_cast<Number>(9) * ::std::pow(lame_first_modulus.Value(), 2)
                 + static_cast<Number>(2) * young_modulus.Value() * lame_first_modulus.Value()))),
      lame_first_modulus(lame_first_modulus) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given Young's
  // modulus and P-wave modulus.
  constexpr ElasticIsotropicSolid(
      const YoungModulus<Number>& young_modulus, const PWaveModulus<Number>& p_wave_modulus)
    : ConstitutiveModel(),
      shear_modulus(
          static_cast<Number>(0.125)
          * (static_cast<Number>(3) * p_wave_modulus.Value() + young_modulus.Value()
             - ::std::sqrt(
                 ::std::pow(young_modulus.Value(), 2)
                 + static_cast<Number>(9) * ::std::pow(p_wave_modulus.Value(), 2)
                 - static_cast<Number>(10) * young_modulus.Value() * p_wave_modulus.Value()))),
      lame_first_modulus(
          static_cast<Number>(0.25)
          * (p_wave_modulus.Value() - young_modulus.Value()
             + ::std::sqrt(
                 ::std::pow(young_modulus.Value(), 2)
                 + static_cast<Number>(9) * ::std::pow(p_wave_modulus.Value(), 2)
                 - static_cast<Number>(10) * young_modulus.Value() * p_wave_modulus.Value()))) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given shear
  // modulus and Poisson's ratio.
  constexpr ElasticIsotropicSolid(
      const ShearModulus<Number>& shear_modulus, const PoissonRatio<Number>& poisson_ratio)
    : ConstitutiveModel(), shear_modulus(shear_modulus),
      lame_first_modulus(
          (static_cast<Number>(2) * shear_modulus.Value() * poisson_ratio.Value())
          / (static_cast<Number>(1) - static_cast<Number>(2) * poisson_ratio.Value())) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given shear
  // modulus and isentropic bulk modulus.
  constexpr ElasticIsotropicSolid(const ShearModulus<Number>& shear_modulus,
                                  const IsentropicBulkModulus<Number>& isentropic_bulk_modulus)
    : ConstitutiveModel(), shear_modulus(shear_modulus),
      lame_first_modulus(
          isentropic_bulk_modulus.Value()
          - static_cast<Number>(2) / static_cast<Number>(3) * shear_modulus.Value()) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given shear
  // modulus and isothermal bulk modulus.
  constexpr ElasticIsotropicSolid(const ShearModulus<Number>& shear_modulus,
                                  const IsothermalBulkModulus<Number>& isothermal_bulk_modulus)
    : ConstitutiveModel(), shear_modulus(shear_modulus),
      lame_first_modulus(
          isothermal_bulk_modulus.Value()
          - static_cast<Number>(2) / static_cast<Number>(3) * shear_modulus.Value()) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given shear
  // modulus and Lamé's first modulus.
  constexpr ElasticIsotropicSolid(
      const ShearModulus<Number>& shear_modulus, const LameFirstModulus<Number>& lame_first_modulus)
    : ConstitutiveModel(), shear_modulus(shear_modulus), lame_first_modulus(lame_first_modulus) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given shear
  // modulus and P-wave modulus.
  constexpr ElasticIsotropicSolid(
      const ShearModulus<Number>& shear_modulus, const PWaveModulus<Number>& p_wave_modulus)
    : ConstitutiveModel(), shear_modulus(shear_modulus),
      lame_first_modulus(p_wave_modulus.Value() - static_cast<Number>(2) * shear_modulus.Value()) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given isentropic
  // bulk modulus and Lamé's first modulus.
  constexpr ElasticIsotropicSolid(const IsentropicBulkModulus<Number>& isentropic_bulk_modulus,
                                  const LameFirstModulus<Number>& lame_first_modulus)
    : ConstitutiveModel(),
      shear_modulus(static_cast<Number>(1.5)
                    * (isentropic_bulk_modulus.Value() - lame_first_modulus.Value())),
      lame_first_modulus(lame_first_modulus) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given isothermal
  // bulk modulus and Lamé's first modulus.
  constexpr ElasticIsotropicSolid(const IsothermalBulkModulus<Number>& isothermal_bulk_modulus,
                                  const LameFirstModulus<Number>& lame_first_modulus)
    : ConstitutiveModel(),
      shear_modulus(static_cast<Number>(1.5)
                    * (isothermal_bulk_modulus.Value() - lame_first_modulus.Value())),
      lame_first_modulus(lame_first_modulus) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given isentropic
  // bulk modulus and P-wave modulus.
  constexpr ElasticIsotropicSolid(const IsentropicBulkModulus<Number>& isentropic_bulk_modulus,
                                  const PWaveModulus<Number>& p_wave_modulus)
    : ConstitutiveModel(),
      shear_modulus(
          static_cast<Number>(0.75) * (p_wave_modulus.Value() - isentropic_bulk_modulus.Value())),
      lame_first_modulus(static_cast<Number>(1.5) * isentropic_bulk_modulus.Value()
                         - static_cast<Number>(0.5) * p_wave_modulus.Value()) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given isothermal
  // bulk modulus and P-wave modulus.
  constexpr ElasticIsotropicSolid(const IsothermalBulkModulus<Number>& isothermal_bulk_modulus,
                                  const PWaveModulus<Number>& p_wave_modulus)
    : ConstitutiveModel(),
      shear_modulus(
          static_cast<Number>(0.75) * (p_wave_modulus.Value() - isothermal_bulk_modulus.Value())),
      lame_first_modulus(static_cast<Number>(1.5) * isothermal_bulk_modulus.Value()
                         - static_cast<Number>(0.5) * p_wave_modulus.Value()) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given isentropic
  // bulk modulus and Poisson's ratio.
  constexpr ElasticIsotropicSolid(const IsentropicBulkModulus<Number>& isentropic_bulk_modulus,
                                  const PoissonRatio<Number>& poisson_ratio)
    : ConstitutiveModel(),
      shear_modulus(static_cast<Number>(3) * isentropic_bulk_modulus.Value()
                    * (static_cast<Number>(1) - static_cast<Number>(2) * poisson_ratio.Value())
                    / (static_cast<Number>(2) + static_cast<Number>(2) * poisson_ratio.Value())),
      lame_first_modulus(
          static_cast<Number>(3) * isentropic_bulk_modulus.Value() * poisson_ratio.Value()
          / (static_cast<Number>(1) + poisson_ratio.Value())) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given isothermal
  // bulk modulus and Poisson's ratio.
  constexpr ElasticIsotropicSolid(const IsothermalBulkModulus<Number>& isothermal_bulk_modulus,
                                  const PoissonRatio<Number>& poisson_ratio)
    : ConstitutiveModel(),
      shear_modulus(static_cast<Number>(3) * isothermal_bulk_modulus.Value()
                    * (static_cast<Number>(1) - static_cast<Number>(2) * poisson_ratio.Value())
                    / (static_cast<Number>(2) + static_cast<Number>(2) * poisson_ratio.Value())),
      lame_first_modulus(
          static_cast<Number>(3) * isothermal_bulk_modulus.Value() * poisson_ratio.Value()
          / (static_cast<Number>(1) + poisson_ratio.Value())) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given Lamé's first
  // modulus and P-wave modulus.
  constexpr ElasticIsotropicSolid(const LameFirstModulus<Number>& lame_first_modulus,
                                  const PWaveModulus<Number>& p_wave_modulus)
    : ConstitutiveModel(),
      shear_modulus(
          static_cast<Number>(0.5) * (p_wave_modulus.Value() - lame_first_modulus.Value())),
      lame_first_modulus(lame_first_modulus) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given Lamé's first
  // modulus and Poisson's ratio.
  constexpr ElasticIsotropicSolid(
      const LameFirstModulus<Number>& lame_first_modulus, const PoissonRatio<Number>& poisson_ratio)
    : ConstitutiveModel(),
      shear_modulus(lame_first_modulus.Value()
                    * (static_cast<Number>(1) - static_cast<Number>(2) * poisson_ratio.Value())
                    / (static_cast<Number>(2) * poisson_ratio.Value())),
      lame_first_modulus(lame_first_modulus) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given P-wave
  // modulus and Poisson's ratio.
  constexpr ElasticIsotropicSolid(
      const PWaveModulus<Number>& p_wave_modulus, const PoissonRatio<Number>& poisson_ratio)
    : ConstitutiveModel(),
      shear_modulus(p_wave_modulus.Value()
                    * (static_cast<Number>(1) - static_cast<Number>(2) * poisson_ratio.Value())
                    / (static_cast<Number>(2) - static_cast<Number>(2) * poisson_ratio.Value())),
      lame_first_modulus(p_wave_modulus.Value() * poisson_ratio.Value()
                         / (static_cast<Number>(1) - poisson_ratio.Value())) {}

  // Destructor. Destroys this elastic isotropic solid constitutive model.
  ~ElasticIsotropicSolid() noexcept override = default;

  // Copy constructor. Constructs an elastic isotropic solid constitutive model by copying another
  // one.
  constexpr ElasticIsotropicSolid(const ElasticIsotropicSolid& other) = default;

  // Move constructor. Constructs an elastic isotropic solid constitutive model by moving another
  // one.
  constexpr ElasticIsotropicSolid(ElasticIsotropicSolid&& other) noexcept = default;

  // Copy assignment operator. Assigns this elastic isotropic solid constitutive model by copying
  // another one.
  ElasticIsotropicSolid& operator=(const ElasticIsotropicSolid& other) = default;

  // Move assignment operator. Assigns this elastic isotropic solid constitutive model by moving
  // another one.
  ElasticIsotropicSolid& operator=(ElasticIsotropicSolid&& other) noexcept = default;

  // Shear modulus of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline constexpr const PhQ::ShearModulus<Number>& ShearModulus() const noexcept {
    return shear_modulus;
  }

  // Lamé's first modulus of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline constexpr const PhQ::LameFirstModulus<Number>&
  LameFirstModulus() const noexcept {
    return lame_first_modulus;
  }

  // Young's modulus of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline PhQ::YoungModulus<Number> YoungModulus() const {
    const Number numerator{shear_modulus.Value()
                           * (static_cast<Number>(3) * lame_first_modulus.Value()
                              + static_cast<Number>(2) * shear_modulus.Value())};
    const Number denominator{shear_modulus.Value() + lame_first_modulus.Value()};
    return PhQ::YoungModulus<Number>{numerator / denominator, Standard<Unit::Pressure>};
  }

  // Isentropic bulk modulus of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline PhQ::IsentropicBulkModulus<Number> IsentropicBulkModulus() const {
    return PhQ::IsentropicBulkModulus<Number>{
        lame_first_modulus.Value()
            + static_cast<Number>(2) / static_cast<Number>(3) * shear_modulus.Value(),
        Standard<Unit::Pressure>};
  }

  // Isothermal bulk modulus of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline PhQ::IsothermalBulkModulus<Number> IsothermalBulkModulus() const {
    return PhQ::IsothermalBulkModulus<Number>{
        lame_first_modulus.Value()
            + static_cast<Number>(2) / static_cast<Number>(3) * shear_modulus.Value(),
        Standard<Unit::Pressure>};
  }

  // P-wave modulus of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline PhQ::PWaveModulus<Number> PWaveModulus() const {
    return PhQ::PWaveModulus<Number>{
        lame_first_modulus.Value() + static_cast<Number>(2) * shear_modulus.Value(),
        Standard<Unit::Pressure>};
  }

  // Poisson's ratio of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline PhQ::PoissonRatio<Number> PoissonRatio() const {
    const Number numerator{static_cast<Number>(0.5) * lame_first_modulus.Value()};
    const Number denominator{shear_modulus.Value() + lame_first_modulus.Value()};
    return PhQ::PoissonRatio<Number>{numerator / denominator};
  }

  // Returns this constitutive model's type.
  [[nodiscard]] inline ConstitutiveModel::Type GetType() const noexcept override {
    return ConstitutiveModel::Type::ElasticIsotropicSolid;
  }

  // Returns the stress resulting from a given strain and strain rate. Since this is an elastic
  // isotropic solid constitutive model, the strain rate does not contribute to the stress and is
  // ignored.
  [[nodiscard]] inline PhQ::Stress<float> Stress(
      const PhQ::Strain<float>& strain,
      const PhQ::StrainRate<float>& /*strain_rate*/) const override {
    return this->Stress(strain);
  }

  // Returns the stress resulting from a given strain and strain rate. Since this is an elastic
  // isotropic solid constitutive model, the strain rate does not contribute to the stress and is
  // ignored.
  [[nodiscard]] inline PhQ::Stress<double> Stress(
      const PhQ::Strain<double>& strain,
      const PhQ::StrainRate<double>& /*strain_rate*/) const override {
    return this->Stress(strain);
  }

  // Returns the stress resulting from a given strain and strain rate. Since this is an elastic
  // isotropic solid constitutive model, the strain rate does not contribute to the stress and is
  // ignored.
  [[nodiscard]] inline PhQ::Stress<long double> Stress(
      const PhQ::Strain<long double>& strain,
      const PhQ::StrainRate<long double>& /*strain_rate*/) const override {
    return this->Stress(strain);
  }

  // Returns the stress resulting from a given strain.
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

  // Returns the stress resulting from a given strain.
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

  // Returns the stress resulting from a given strain.
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

  // Returns the stress resulting from a given strain rate. Since this is an elastic isotropic solid
  // constitutive model, the strain rate does not contribute to the stress, so this always returns a
  // stress of zero.
  [[nodiscard]] inline PhQ::Stress<float> Stress(
      const PhQ::StrainRate<float>& /*strain_rate*/) const override {
    return PhQ::Stress<float>::Zero();
  }

  // Returns the stress resulting from a given strain rate. Since this is an elastic isotropic solid
  // constitutive model, the strain rate does not contribute to the stress, so this always returns a
  // stress of zero.
  [[nodiscard]] inline PhQ::Stress<double> Stress(
      const PhQ::StrainRate<double>& /*strain_rate*/) const override {
    return PhQ::Stress<double>::Zero();
  }

  // Returns the stress resulting from a given strain rate. Since this is an elastic isotropic solid
  // constitutive model, the strain rate does not contribute to the stress, so this always returns a
  // stress of zero.
  [[nodiscard]] inline PhQ::Stress<long double> Stress(
      const PhQ::StrainRate<long double>& /*strain_rate*/) const override {
    return PhQ::Stress<long double>::Zero();
  }

  // Returns the strain resulting from a given stress.
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

  // Returns the strain resulting from a given stress.
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

  // Returns the strain resulting from a given stress.
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

  // Returns the strain rate resulting from a given stress. Since this is an elastic isotropic solid
  // constitutive model, stress does not depend on strain rate, so this always returns a strain rate
  // of zero.
  [[nodiscard]] inline PhQ::StrainRate<float> StrainRate(
      const PhQ::Stress<float>& /*stress*/) const override {
    return PhQ::StrainRate<float>::Zero();
  }

  // Returns the strain rate resulting from a given stress. Since this is an elastic isotropic solid
  // constitutive model, stress does not depend on strain rate, so this always returns a strain rate
  // of zero.
  [[nodiscard]] inline PhQ::StrainRate<double> StrainRate(
      const PhQ::Stress<double>& /*stress*/) const override {
    return PhQ::StrainRate<double>::Zero();
  }

  // Returns the strain rate resulting from a given stress. Since this is an elastic isotropic solid
  // constitutive model, stress does not depend on strain rate, so this always returns a strain rate
  // of zero.
  [[nodiscard]] inline PhQ::StrainRate<long double> StrainRate(
      const PhQ::Stress<long double>& /*stress*/) const override {
    return PhQ::StrainRate<long double>::Zero();
  }

  // Prints this elastic isotropic solid constitutive model as a string.
  [[nodiscard]] inline std::string Print() const override {
    return {"Type = " + std::string{Abbreviation(this->GetType())} + ", Shear Modulus = "
            + shear_modulus.Print() + ", Lamé's First Modulus = " + lame_first_modulus.Print()};
  }

  // Serializes this elastic isotropic solid constitutive model as a JSON message.
  [[nodiscard]] inline std::string JSON() const override {
    return {R"({"type":")" + SnakeCaseCopy(Abbreviation(this->GetType())) + R"(","shear_modulus":)"
            + shear_modulus.JSON() + ",\"lame_first_modulus\":" + lame_first_modulus.JSON() + "}"};
  }

  // Serializes this elastic isotropic solid constitutive model as an XML message.
  [[nodiscard]] inline std::string XML() const override {
    return {"<type>" + SnakeCaseCopy(Abbreviation(this->GetType())) + "</type><shear_modulus>"
            + shear_modulus.XML() + "</shear_modulus><lame_first_modulus>"
            + lame_first_modulus.XML() + "</lame_first_modulus>"};
  }

  // Serializes this elastic isotropic solid constitutive model as a YAML message.
  [[nodiscard]] inline std::string YAML() const override {
    return {"{type:\"" + SnakeCaseCopy(Abbreviation(this->GetType())) + "\",shear_modulus:"
            + shear_modulus.YAML() + ",lame_first_modulus:" + lame_first_modulus.YAML() + "}"};
  }

private:
  PhQ::ShearModulus<Number> shear_modulus;

  PhQ::LameFirstModulus<Number> lame_first_modulus;
};

template <typename Number>
inline constexpr bool operator==(
    const typename ConstitutiveModel::ElasticIsotropicSolid<Number>& left,
    const typename ConstitutiveModel::ElasticIsotropicSolid<Number>& right) noexcept {
  return left.ShearModulus() == right.ShearModulus()
         && left.LameFirstModulus() == right.LameFirstModulus();
}

template <typename Number>
inline constexpr bool operator!=(
    const typename ConstitutiveModel::ElasticIsotropicSolid<Number>& left,
    const typename ConstitutiveModel::ElasticIsotropicSolid<Number>& right) noexcept {
  return left.ShearModulus() != right.ShearModulus()
         || left.LameFirstModulus() != right.LameFirstModulus();
}

template <typename Number>
inline constexpr bool operator<(
    const typename ConstitutiveModel::ElasticIsotropicSolid<Number>& left,
    const typename ConstitutiveModel::ElasticIsotropicSolid<Number>& right) noexcept {
  if (left.ShearModulus() != right.ShearModulus()) {
    return left.ShearModulus() < right.ShearModulus();
  }
  return left.LameFirstModulus() < right.LameFirstModulus();
}

template <typename Number>
inline constexpr bool operator>(
    const typename ConstitutiveModel::ElasticIsotropicSolid<Number>& left,
    const typename ConstitutiveModel::ElasticIsotropicSolid<Number>& right) noexcept {
  if (left.ShearModulus() != right.ShearModulus()) {
    return left.ShearModulus() > right.ShearModulus();
  }
  return left.LameFirstModulus() > right.LameFirstModulus();
}

template <typename Number>
inline constexpr bool operator<=(
    const typename ConstitutiveModel::ElasticIsotropicSolid<Number>& left,
    const typename ConstitutiveModel::ElasticIsotropicSolid<Number>& right) noexcept {
  return !(left > right);
}

template <typename Number>
inline constexpr bool operator>=(
    const typename ConstitutiveModel::ElasticIsotropicSolid<Number>& left,
    const typename ConstitutiveModel::ElasticIsotropicSolid<Number>& right) noexcept {
  return !(left < right);
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const typename ConstitutiveModel::ElasticIsotropicSolid<Number>& model) {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<typename PhQ::ConstitutiveModel::ElasticIsotropicSolid<Number>> {
  size_t operator()(
      const typename PhQ::ConstitutiveModel::ElasticIsotropicSolid<Number>& model) const {
    size_t result{17};
    result =
        static_cast<size_t>(31) * result + hash<PhQ::ShearModulus<Number>>()(model.ShearModulus());
    result = static_cast<size_t>(31) * result
             + hash<PhQ::LameFirstModulus<Number>>()(model.LameFirstModulus());
    return result;
  }
};

}  // namespace std

#endif  // PHQ_CONSTITUTIVE_MODEL_ELASTIC_ISOTROPIC_SOLID_HPP
