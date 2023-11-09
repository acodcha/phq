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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_ELASTIC_ISOTROPIC_SOLID_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_ELASTIC_ISOTROPIC_SOLID_HPP

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
#include "../Unit/Pressure.hpp"
#include "../Value/SymmetricDyad.hpp"
#include "../YoungModulus.hpp"

namespace PhQ {

// Constitutive model for an elastic isotropic solid. This is the simplest constitutive model for a
// deformable solid material.
class ConstitutiveModel::ElasticIsotropicSolid : public ConstitutiveModel {
public:
  // Default constructor. Constructs an elastic isotropic solid constitutive model with an
  // uninitialized value.
  ElasticIsotropicSolid() = default;

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given Young's
  // modulus and Poisson's ratio.
  ElasticIsotropicSolid(const YoungModulus& young_modulus, const PoissonRatio& poisson_ratio)
    : ConstitutiveModel(),
      shear_modulus_(young_modulus.Value() / (2.0 * (1.0 + poisson_ratio.Value()))),
      lame_first_modulus_(young_modulus.Value() * poisson_ratio.Value()
                          / ((1.0 + poisson_ratio.Value()) * (1.0 - 2.0 * poisson_ratio.Value()))) {
  }

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given Young's
  // modulus and shear modulus.
  constexpr ElasticIsotropicSolid(
      const YoungModulus& young_modulus, const ShearModulus& shear_modulus)
    : ConstitutiveModel(), shear_modulus_(shear_modulus),
      lame_first_modulus_(
          (shear_modulus.Value() * (young_modulus.Value() - 2.0 * shear_modulus.Value()))
          / (3.0 * shear_modulus.Value() - young_modulus.Value())) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given Young's
  // modulus and isentropic bulk modulus.
  ElasticIsotropicSolid(
      const YoungModulus& young_modulus, const IsentropicBulkModulus& isentropic_bulk_modulus)
    : ConstitutiveModel(),
      shear_modulus_(3.0 * young_modulus.Value() * isentropic_bulk_modulus.Value()
                     / (9.0 * isentropic_bulk_modulus.Value() - young_modulus.Value())),
      lame_first_modulus_(3.0 * isentropic_bulk_modulus.Value()
                          * (3.0 * isentropic_bulk_modulus.Value() - young_modulus.Value())
                          / (9.0 * isentropic_bulk_modulus.Value() - young_modulus.Value())) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given Young's
  // modulus and isothermal bulk modulus.
  ElasticIsotropicSolid(
      const YoungModulus& young_modulus, const IsothermalBulkModulus& isothermal_bulk_modulus)
    : ConstitutiveModel(),
      shear_modulus_(3.0 * young_modulus.Value() * isothermal_bulk_modulus.Value()
                     / (9.0 * isothermal_bulk_modulus.Value() - young_modulus.Value())),
      lame_first_modulus_(3.0 * isothermal_bulk_modulus.Value()
                          * (3.0 * isothermal_bulk_modulus.Value() - young_modulus.Value())
                          / (9.0 * isothermal_bulk_modulus.Value() - young_modulus.Value())) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given Young's
  // modulus and Lamé's first modulus.
  constexpr ElasticIsotropicSolid(
      const YoungModulus& young_modulus, const LameFirstModulus& lame_first_modulus)
    : ConstitutiveModel(),
      shear_modulus_(0.25
                     * (young_modulus.Value() - 3.0 * lame_first_modulus.Value()
                        + ::std::sqrt(::std::pow(young_modulus.Value(), 2)
                                      + 9.0 * ::std::pow(lame_first_modulus.Value(), 2)
                                      + 2.0 * young_modulus.Value() * lame_first_modulus.Value()))),
      lame_first_modulus_(lame_first_modulus) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given Young's
  // modulus and P-wave modulus.
  constexpr ElasticIsotropicSolid(
      const YoungModulus& young_modulus, const PWaveModulus& p_wave_modulus)
    : ConstitutiveModel(),
      shear_modulus_(0.125
                     * (3.0 * p_wave_modulus.Value() + young_modulus.Value()
                        - ::std::sqrt(::std::pow(young_modulus.Value(), 2)
                                      + 9.0 * ::std::pow(p_wave_modulus.Value(), 2)
                                      - 10.0 * young_modulus.Value() * p_wave_modulus.Value()))),
      lame_first_modulus_(
          0.25
          * (p_wave_modulus.Value() - young_modulus.Value()
             + ::std::sqrt(
                 ::std::pow(young_modulus.Value(), 2) + 9.0 * ::std::pow(p_wave_modulus.Value(), 2)
                 - 10.0 * young_modulus.Value() * p_wave_modulus.Value()))) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given shear
  // modulus and Poisson's ratio.
  constexpr ElasticIsotropicSolid(
      const ShearModulus& shear_modulus, const PoissonRatio& poisson_ratio)
    : ConstitutiveModel(), shear_modulus_(shear_modulus),
      lame_first_modulus_((2.0 * shear_modulus.Value() * poisson_ratio.Value())
                          / (1.0 - 2.0 * poisson_ratio.Value())) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given shear
  // modulus and isentropic bulk modulus.
  constexpr ElasticIsotropicSolid(
      const ShearModulus& shear_modulus, const IsentropicBulkModulus& isentropic_bulk_modulus)
    : ConstitutiveModel(), shear_modulus_(shear_modulus),
      lame_first_modulus_(isentropic_bulk_modulus.Value() - 2.0 / 3.0 * shear_modulus.Value()) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given shear
  // modulus and isothermal bulk modulus.
  constexpr ElasticIsotropicSolid(
      const ShearModulus& shear_modulus, const IsothermalBulkModulus& isothermal_bulk_modulus)
    : ConstitutiveModel(), shear_modulus_(shear_modulus),
      lame_first_modulus_(isothermal_bulk_modulus.Value() - 2.0 / 3.0 * shear_modulus.Value()) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given shear
  // modulus and Lamé's first modulus.
  constexpr ElasticIsotropicSolid(
      const ShearModulus& shear_modulus, const LameFirstModulus& lame_first_modulus)
    : ConstitutiveModel(), shear_modulus_(shear_modulus), lame_first_modulus_(lame_first_modulus) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given shear
  // modulus and P-wave modulus.
  constexpr ElasticIsotropicSolid(
      const ShearModulus& shear_modulus, const PWaveModulus& p_wave_modulus)
    : ConstitutiveModel(), shear_modulus_(shear_modulus),
      lame_first_modulus_(p_wave_modulus.Value() - 2.0 * shear_modulus.Value()) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given isentropic
  // bulk modulus and Lamé's first modulus.
  constexpr ElasticIsotropicSolid(const IsentropicBulkModulus& isentropic_bulk_modulus,
                                  const LameFirstModulus& lame_first_modulus)
    : ConstitutiveModel(),
      shear_modulus_(1.5 * (isentropic_bulk_modulus.Value() - lame_first_modulus.Value())),
      lame_first_modulus_(lame_first_modulus) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given isothermal
  // bulk modulus and Lamé's first modulus.
  constexpr ElasticIsotropicSolid(const IsothermalBulkModulus& isothermal_bulk_modulus,
                                  const LameFirstModulus& lame_first_modulus)
    : ConstitutiveModel(),
      shear_modulus_(1.5 * (isothermal_bulk_modulus.Value() - lame_first_modulus.Value())),
      lame_first_modulus_(lame_first_modulus) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given isentropic
  // bulk modulus and P-wave modulus.
  constexpr ElasticIsotropicSolid(
      const IsentropicBulkModulus& isentropic_bulk_modulus, const PWaveModulus& p_wave_modulus)
    : ConstitutiveModel(),
      shear_modulus_(0.75 * (p_wave_modulus.Value() - isentropic_bulk_modulus.Value())),
      lame_first_modulus_(1.5 * isentropic_bulk_modulus.Value() - 0.5 * p_wave_modulus.Value()) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given isothermal
  // bulk modulus and P-wave modulus.
  constexpr ElasticIsotropicSolid(
      const IsothermalBulkModulus& isothermal_bulk_modulus, const PWaveModulus& p_wave_modulus)
    : ConstitutiveModel(),
      shear_modulus_(0.75 * (p_wave_modulus.Value() - isothermal_bulk_modulus.Value())),
      lame_first_modulus_(1.5 * isothermal_bulk_modulus.Value() - 0.5 * p_wave_modulus.Value()) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given isentropic
  // bulk modulus and Poisson's ratio.
  constexpr ElasticIsotropicSolid(
      const IsentropicBulkModulus& isentropic_bulk_modulus, const PoissonRatio& poisson_ratio)
    : ConstitutiveModel(),
      shear_modulus_(3.0 * isentropic_bulk_modulus.Value() * (1.0 - 2.0 * poisson_ratio.Value())
                     / (2.0 + 2.0 * poisson_ratio.Value())),
      lame_first_modulus_(3.0 * isentropic_bulk_modulus.Value() * poisson_ratio.Value()
                          / (1.0 + poisson_ratio.Value())) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given isothermal
  // bulk modulus and Poisson's ratio.
  constexpr ElasticIsotropicSolid(
      const IsothermalBulkModulus& isothermal_bulk_modulus, const PoissonRatio& poisson_ratio)
    : ConstitutiveModel(),
      shear_modulus_(3.0 * isothermal_bulk_modulus.Value() * (1.0 - 2.0 * poisson_ratio.Value())
                     / (2.0 + 2.0 * poisson_ratio.Value())),
      lame_first_modulus_(3.0 * isothermal_bulk_modulus.Value() * poisson_ratio.Value()
                          / (1.0 + poisson_ratio.Value())) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given Lamé's first
  // modulus and P-wave modulus.
  constexpr ElasticIsotropicSolid(
      const LameFirstModulus& lame_first_modulus, const PWaveModulus& p_wave_modulus)
    : ConstitutiveModel(),
      shear_modulus_(0.5 * (p_wave_modulus.Value() - lame_first_modulus.Value())),
      lame_first_modulus_(lame_first_modulus) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given Lamé's first
  // modulus and Poisson's ratio.
  constexpr ElasticIsotropicSolid(
      const LameFirstModulus& lame_first_modulus, const PoissonRatio& poisson_ratio)
    : ConstitutiveModel(),
      shear_modulus_(lame_first_modulus.Value() * (1.0 - 2.0 * poisson_ratio.Value())
                     / (2.0 * poisson_ratio.Value())),
      lame_first_modulus_(lame_first_modulus) {}

  // Constructor. Constructs an elastic isotropic solid constitutive model from a given P-wave
  // modulus and Poisson's ratio.
  constexpr ElasticIsotropicSolid(
      const PWaveModulus& p_wave_modulus, const PoissonRatio& poisson_ratio)
    : ConstitutiveModel(),
      shear_modulus_(p_wave_modulus.Value() * (1.0 - 2.0 * poisson_ratio.Value())
                     / (2.0 - 2.0 * poisson_ratio.Value())),
      lame_first_modulus_(
          p_wave_modulus.Value() * poisson_ratio.Value() / (1.0 - poisson_ratio.Value())) {}

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
  [[nodiscard]] inline constexpr const PhQ::ShearModulus& ShearModulus() const noexcept {
    return shear_modulus_;
  }

  // Lamé's first modulus of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline constexpr const PhQ::LameFirstModulus& LameFirstModulus() const noexcept {
    return lame_first_modulus_;
  }

  // Young's modulus of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline PhQ::YoungModulus YoungModulus() const {
    const double numerator{shear_modulus_.Value()
                           * (3.0 * lame_first_modulus_.Value() + 2.0 * shear_modulus_.Value())};
    const double denominator{shear_modulus_.Value() + lame_first_modulus_.Value()};
    return {numerator / denominator, Standard<Unit::Pressure>};
  }

  // Isentropic bulk modulus of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline PhQ::IsentropicBulkModulus IsentropicBulkModulus() const {
    return {
        lame_first_modulus_.Value() + 2.0 / 3.0 * shear_modulus_.Value(), Standard<Unit::Pressure>};
  }

  // Isothermal bulk modulus of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline PhQ::IsothermalBulkModulus IsothermalBulkModulus() const {
    return {
        lame_first_modulus_.Value() + 2.0 / 3.0 * shear_modulus_.Value(), Standard<Unit::Pressure>};
  }

  // P-wave modulus of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline PhQ::PWaveModulus PWaveModulus() const {
    return {lame_first_modulus_.Value() + 2.0 * shear_modulus_.Value(), Standard<Unit::Pressure>};
  }

  // Poisson's ratio of this elastic isotropic solid constitutive model.
  [[nodiscard]] inline PhQ::PoissonRatio PoissonRatio() const {
    const double numerator{0.5 * lame_first_modulus_.Value()};
    const double denominator{shear_modulus_.Value() + lame_first_modulus_.Value()};
    return PhQ::PoissonRatio{numerator / denominator};
  }

  // Returns this constitutive model's type.
  [[nodiscard]] inline Type GetType() const noexcept override {
    return Type::ElasticIsotropicSolid;
  }

  // Returns the stress resulting from a given strain and strain rate. Since this is an elastic
  // isotropic solid constitutive model, the strain rate does not contribute to the stress and is
  // ignored.
  [[nodiscard]] inline PhQ::Stress Stress(
      const PhQ::Strain& strain, const PhQ::StrainRate& /*strain_rate*/) const override {
    return Stress(strain);
  }

  // Returns the stress resulting from a given strain.
  [[nodiscard]] inline PhQ::Stress Stress(const PhQ::Strain& strain) const override {
    // stress = a * strain + b * trace(strain) * identity_matrix
    // a = 2 * shear_modulus
    // b = lame_first_modulus
    const double temporary = lame_first_modulus_.Value() * strain.Value().Trace();
    return {
        2.0 * shear_modulus_.Value() * strain.Value()
            + Value::SymmetricDyad{temporary, 0.0, 0.0, temporary, 0.0, temporary},
        Standard<Unit::Pressure>
    };
  }

  // Returns the stress resulting from a given strain rate. Since this is an elastic isotropic solid
  // constitutive model, the strain rate does not contribute to the stress, so this always returns a
  // stress of zero.
  [[nodiscard]] inline PhQ::Stress Stress(const PhQ::StrainRate& /*strain_rate*/) const override {
    return PhQ::Stress::Zero();
  }

  // Returns the strain resulting from a given stress.
  [[nodiscard]] inline PhQ::Strain Strain(const PhQ::Stress& stress) const override {
    // strain = a * stress + b * trace(stress) * identity_matrix
    // a = 1 / (2 * shear_modulus)
    // b = -1 * lame_first_modulus / (2 * shear_modulus * (2 * shear_modulus + 3
    //     * lame_first_modulus))
    const double a = 1.0 / (2.0 * shear_modulus_.Value());
    const double b = -lame_first_modulus_.Value()
                     / (2.0 * shear_modulus_.Value()
                        * (2.0 * shear_modulus_.Value() + 3.0 * lame_first_modulus_.Value()));
    const double temporary = b * stress.Value().Trace();
    return PhQ::Strain{
        a * stress.Value() + Value::SymmetricDyad{temporary, 0.0, 0.0, temporary, 0.0, temporary}
    };
  }

  // Returns the strain rate resulting from a given stress. Since this is an elastic isotropic solid
  // constitutive model, stress does not depend on strain rate, so this always returns a strain rate
  // of zero.
  [[nodiscard]] inline PhQ::StrainRate StrainRate(const PhQ::Stress& /*stress*/) const override {
    return PhQ::StrainRate::Zero();
  }

  // Prints this elastic isotropic solid constitutive model as a string.
  [[nodiscard]] inline std::string Print() const override {
    return {"Type = " + std::string{Abbreviation(GetType())} + ", Shear Modulus = "
            + shear_modulus_.Print() + ", Lamé's First Modulus = " + lame_first_modulus_.Print()};
  }

  // Serializes this elastic isotropic solid constitutive model as a JSON message.
  [[nodiscard]] inline std::string JSON() const override {
    return {R"({"type":")" + SnakeCaseCopy(Abbreviation(GetType())) + R"(","shear_modulus":)"
            + shear_modulus_.JSON() + ",\"lame_first_modulus\":" + lame_first_modulus_.JSON()
            + "}"};
  }

  // Serializes this elastic isotropic solid constitutive model as an XML message.
  [[nodiscard]] inline std::string XML() const override {
    return {"<type>" + SnakeCaseCopy(Abbreviation(GetType())) + "</type><shear_modulus>"
            + shear_modulus_.XML() + "</shear_modulus><lame_first_modulus>"
            + lame_first_modulus_.XML() + "</lame_first_modulus>"};
  }

  // Serializes this elastic isotropic solid constitutive model as a YAML message.
  [[nodiscard]] inline std::string YAML() const override {
    return {"{type:\"" + SnakeCaseCopy(Abbreviation(GetType())) + "\",shear_modulus:"
            + shear_modulus_.YAML() + ",lame_first_modulus:" + lame_first_modulus_.YAML() + "}"};
  }

private:
  PhQ::ShearModulus shear_modulus_;

  PhQ::LameFirstModulus lame_first_modulus_;
};

inline constexpr bool operator==(const ConstitutiveModel::ElasticIsotropicSolid& left,
                                 const ConstitutiveModel::ElasticIsotropicSolid& right) noexcept {
  return left.ShearModulus() == right.ShearModulus()
         && left.LameFirstModulus() == right.LameFirstModulus();
}

inline constexpr bool operator!=(const ConstitutiveModel::ElasticIsotropicSolid& left,
                                 const ConstitutiveModel::ElasticIsotropicSolid& right) noexcept {
  return left.ShearModulus() != right.ShearModulus()
         || left.LameFirstModulus() != right.LameFirstModulus();
}

inline constexpr bool operator<(const ConstitutiveModel::ElasticIsotropicSolid& left,
                                const ConstitutiveModel::ElasticIsotropicSolid& right) noexcept {
  if (left.ShearModulus() != right.ShearModulus()) {
    return left.ShearModulus() < right.ShearModulus();
  }
  return left.LameFirstModulus() < right.LameFirstModulus();
}

inline constexpr bool operator>(const ConstitutiveModel::ElasticIsotropicSolid& left,
                                const ConstitutiveModel::ElasticIsotropicSolid& right) noexcept {
  if (left.ShearModulus() != right.ShearModulus()) {
    return left.ShearModulus() > right.ShearModulus();
  }
  return left.LameFirstModulus() > right.LameFirstModulus();
}

inline constexpr bool operator<=(const ConstitutiveModel::ElasticIsotropicSolid& left,
                                 const ConstitutiveModel::ElasticIsotropicSolid& right) noexcept {
  return !(left > right);
}

inline constexpr bool operator>=(const ConstitutiveModel::ElasticIsotropicSolid& left,
                                 const ConstitutiveModel::ElasticIsotropicSolid& right) noexcept {
  return !(left < right);
}

inline std::ostream& operator<<(
    std::ostream& stream, const ConstitutiveModel::ElasticIsotropicSolid& model) {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ConstitutiveModel::ElasticIsotropicSolid> {
  size_t operator()(const PhQ::ConstitutiveModel::ElasticIsotropicSolid& model) const {
    size_t result = 17;
    result = 31 * result + hash<PhQ::ShearModulus>()(model.ShearModulus());
    result = 31 * result + hash<PhQ::LameFirstModulus>()(model.LameFirstModulus());
    return result;
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_ELASTIC_ISOTROPIC_SOLID_HPP
