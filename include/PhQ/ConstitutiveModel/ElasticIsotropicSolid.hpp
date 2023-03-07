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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_ELASTIC_ISOTROPIC_SOLID_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_ELASTIC_ISOTROPIC_SOLID_HPP

#include "../IsentropicBulkModulus.hpp"
#include "../IsothermalBulkModulus.hpp"
#include "../LameFirstModulus.hpp"
#include "../PWaveModulus.hpp"
#include "../PoissonRatio.hpp"
#include "../ShearModulus.hpp"
#include "../Strain.hpp"
#include "../Stress.hpp"
#include "../YoungModulus.hpp"
#include "Base.hpp"

namespace PhQ::ConstitutiveModel {

class ElasticIsotropicSolid
    : public GenericConstitutiveModel<Type::ElasticIsotropicSolid> {
public:
  constexpr ElasticIsotropicSolid() noexcept
      : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(),
        shear_modulus_(),
        lame_first_modulus_() {}

  constexpr ElasticIsotropicSolid(const YoungModulus& young_modulus,
                                  const PoissonRatio& poisson_ratio) noexcept
      : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(),
        shear_modulus_(),
        lame_first_modulus_() {
    const double numerator_1{young_modulus.Value()};
    const double numerator_2{young_modulus.Value() * poisson_ratio.Value()};
    const double denominator_1{2.0 * (1.0 + poisson_ratio.Value())};
    const double denominator_2{(1.0 + poisson_ratio.Value()) *
                               (1.0 - 2.0 * poisson_ratio.Value())};
    shear_modulus_ = {numerator_1 / denominator_1,
                      StandardUnit<Unit::Pressure>};
    lame_first_modulus_ = {numerator_2 / denominator_2,
                           StandardUnit<Unit::Pressure>};
  }

  ElasticIsotropicSolid(const YoungModulus& young_modulus,
                        const ShearModulus& shear_modulus) noexcept
      : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(),
        shear_modulus_(shear_modulus),
        lame_first_modulus_(
            (shear_modulus.Value() *
             (young_modulus.Value() - 2.0 * shear_modulus.Value())) /
                (3.0 * shear_modulus.Value() - young_modulus.Value()),
            StandardUnit<Unit::Pressure>) {}

  constexpr ElasticIsotropicSolid(
      const YoungModulus& young_modulus,
      const IsentropicBulkModulus& isentropic_bulk_modulus) noexcept
      : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(),
        shear_modulus_(),
        lame_first_modulus_() {
    const double numerator_1{3.0 * young_modulus.Value() *
                             isentropic_bulk_modulus.Value()};
    const double numerator_2{
        3.0 * isentropic_bulk_modulus.Value() *
        (3.0 * isentropic_bulk_modulus.Value() - young_modulus.Value())};
    const double denominator{9.0 * isentropic_bulk_modulus.Value() -
                             young_modulus.Value()};
    shear_modulus_ = {numerator_1 / denominator, StandardUnit<Unit::Pressure>};
    lame_first_modulus_ = {numerator_2 / denominator,
                           StandardUnit<Unit::Pressure>};
  }

  constexpr ElasticIsotropicSolid(
      const YoungModulus& young_modulus,
      const IsothermalBulkModulus& isothermal_bulk_modulus) noexcept
      : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(),
        shear_modulus_(),
        lame_first_modulus_() {
    const double numerator_1{3.0 * young_modulus.Value() *
                             isothermal_bulk_modulus.Value()};
    const double numerator_2{
        3.0 * isothermal_bulk_modulus.Value() *
        (3.0 * isothermal_bulk_modulus.Value() - young_modulus.Value())};
    const double denominator{9.0 * isothermal_bulk_modulus.Value() -
                             young_modulus.Value()};
    shear_modulus_ = {numerator_1 / denominator, StandardUnit<Unit::Pressure>};
    lame_first_modulus_ = {numerator_2 / denominator,
                           StandardUnit<Unit::Pressure>};
  }

  ElasticIsotropicSolid(const YoungModulus& young_modulus,
                        const LameFirstModulus& lame_first_modulus) noexcept
      : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(),
        shear_modulus_(
            0.25 * (young_modulus.Value() - 3.0 * lame_first_modulus.Value() +
                    std::sqrt(std::pow(young_modulus.Value(), 2) +
                              9.0 * std::pow(lame_first_modulus.Value(), 2) +
                              2.0 * young_modulus.Value() *
                                  lame_first_modulus.Value())),
            StandardUnit<Unit::Pressure>),
        lame_first_modulus_(lame_first_modulus) {}

  ElasticIsotropicSolid(const YoungModulus& young_modulus,
                        const PWaveModulus& p_wave_modulus) noexcept
      : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(),
        shear_modulus_(
            0.125 * (3.0 * p_wave_modulus.Value() + young_modulus.Value() -
                     std::sqrt(std::pow(young_modulus.Value(), 2) +
                               9.0 * std::pow(p_wave_modulus.Value(), 2) -
                               10.0 * young_modulus.Value() *
                                   p_wave_modulus.Value())),
            StandardUnit<Unit::Pressure>),
        lame_first_modulus_(
            0.25 * (p_wave_modulus.Value() - young_modulus.Value() +
                    std::sqrt(std::pow(young_modulus.Value(), 2) +
                              9.0 * std::pow(p_wave_modulus.Value(), 2) -
                              10.0 * young_modulus.Value() *
                                  p_wave_modulus.Value())),
            StandardUnit<Unit::Pressure>) {}

  ElasticIsotropicSolid(const ShearModulus& shear_modulus,
                        const PoissonRatio& poisson_ratio) noexcept
      : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(),
        shear_modulus_(shear_modulus),
        lame_first_modulus_(
            (2.0 * shear_modulus.Value() * poisson_ratio.Value()) /
                (1.0 - 2.0 * poisson_ratio.Value()),
            StandardUnit<Unit::Pressure>) {}

  ElasticIsotropicSolid(
      const ShearModulus& shear_modulus,
      const IsentropicBulkModulus& isentropic_bulk_modulus) noexcept
      : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(),
        shear_modulus_(shear_modulus),
        lame_first_modulus_(
            isentropic_bulk_modulus.Value() - 2.0 / 3.0 * shear_modulus.Value(),
            StandardUnit<Unit::Pressure>) {}

  ElasticIsotropicSolid(
      const ShearModulus& shear_modulus,
      const IsothermalBulkModulus& isothermal_bulk_modulus) noexcept
      : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(),
        shear_modulus_(shear_modulus),
        lame_first_modulus_(
            isothermal_bulk_modulus.Value() - 2.0 / 3.0 * shear_modulus.Value(),
            StandardUnit<Unit::Pressure>) {}

  ElasticIsotropicSolid(const ShearModulus& shear_modulus,
                        const LameFirstModulus& lame_first_modulus) noexcept
      : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(),
        shear_modulus_(shear_modulus),
        lame_first_modulus_(lame_first_modulus) {}

  ElasticIsotropicSolid(const ShearModulus& shear_modulus,
                        const PWaveModulus& p_wave_modulus) noexcept
      : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(),
        shear_modulus_(shear_modulus),
        lame_first_modulus_(
            p_wave_modulus.Value() - 2.0 * shear_modulus.Value(),
            StandardUnit<Unit::Pressure>) {}

  ElasticIsotropicSolid(const IsentropicBulkModulus& isentropic_bulk_modulus,
                        const LameFirstModulus& lame_first_modulus) noexcept
      : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(),
        shear_modulus_(1.5 * (isentropic_bulk_modulus.Value() -
                              lame_first_modulus.Value()),
                       StandardUnit<Unit::Pressure>),
        lame_first_modulus_(lame_first_modulus) {}

  ElasticIsotropicSolid(const IsentropicBulkModulus& isentropic_bulk_modulus,
                        const PWaveModulus& p_wave_modulus) noexcept
      : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(),
        shear_modulus_(
            0.75 * (p_wave_modulus.Value() - isentropic_bulk_modulus.Value()),
            StandardUnit<Unit::Pressure>),
        lame_first_modulus_(1.5 * isentropic_bulk_modulus.Value() -
                                0.5 * p_wave_modulus.Value(),
                            StandardUnit<Unit::Pressure>) {}

  ElasticIsotropicSolid(const IsothermalBulkModulus& isothermal_bulk_modulus,
                        const LameFirstModulus& lame_first_modulus) noexcept
      : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(),
        shear_modulus_(1.5 * (isothermal_bulk_modulus.Value() -
                              lame_first_modulus.Value()),
                       StandardUnit<Unit::Pressure>),
        lame_first_modulus_(lame_first_modulus) {}

  ElasticIsotropicSolid(const IsothermalBulkModulus& isothermal_bulk_modulus,
                        const PWaveModulus& p_wave_modulus) noexcept
      : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(),
        shear_modulus_(
            0.75 * (p_wave_modulus.Value() - isothermal_bulk_modulus.Value()),
            StandardUnit<Unit::Pressure>),
        lame_first_modulus_(1.5 * isothermal_bulk_modulus.Value() -
                                0.5 * p_wave_modulus.Value(),
                            StandardUnit<Unit::Pressure>) {}

  ElasticIsotropicSolid(const LameFirstModulus& lame_first_modulus,
                        const PWaveModulus& p_wave_modulus) noexcept
      : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(),
        shear_modulus_(
            0.5 * (p_wave_modulus.Value() - lame_first_modulus.Value()),
            StandardUnit<Unit::Pressure>),
        lame_first_modulus_(lame_first_modulus) {}

  inline constexpr const PhQ::ShearModulus& ShearModulus() const noexcept {
    return shear_modulus_;
  }

  inline constexpr const PhQ::LameFirstModulus& LameFirstModulus()
      const noexcept {
    return lame_first_modulus_;
  }

  inline PhQ::YoungModulus YoungModulus() const noexcept {
    const double numerator{
        shear_modulus_.Value() *
        (3.0 * lame_first_modulus_.Value() + 2.0 * shear_modulus_.Value())};
    const double denominator{shear_modulus_.Value() +
                             lame_first_modulus_.Value()};
    return {numerator / denominator, StandardUnit<Unit::Pressure>};
  }

  inline PhQ::IsentropicBulkModulus IsentropicBulkModulus() const noexcept {
    return {lame_first_modulus_.Value() + 2.0 / 3.0 * shear_modulus_.Value(),
            StandardUnit<Unit::Pressure>};
  }

  inline PhQ::IsothermalBulkModulus IsothermalBulkModulus() const noexcept {
    return {lame_first_modulus_.Value() + 2.0 / 3.0 * shear_modulus_.Value(),
            StandardUnit<Unit::Pressure>};
  }

  inline PhQ::PWaveModulus PWaveModulus() const noexcept {
    return {lame_first_modulus_.Value() + 2.0 * shear_modulus_.Value(),
            StandardUnit<Unit::Pressure>};
  }

  inline PhQ::PoissonRatio PoissonRatio() const noexcept {
    const double numerator{0.5 * lame_first_modulus_.Value()};
    const double denominator{shear_modulus_.Value() +
                             lame_first_modulus_.Value()};
    return PhQ::PoissonRatio{numerator / denominator};
  }

  inline PhQ::Stress Stress(const PhQ::Strain& strain) const noexcept {
    // stress = a * strain + b * trace(strain) * identity_matrix
    // a = 2 * shear_modulus
    // b = lame_first_modulus
    const double temporary{lame_first_modulus_.Value() *
                           strain.Value().Trace()};
    return {2.0 * shear_modulus_.Value() * strain.Value() +
                Value::SymmetricDyad{temporary, 0.0, 0.0, temporary, 0.0,
                                     temporary},
            StandardUnit<Unit::Pressure>};
  }

  inline PhQ::Strain Strain(const PhQ::Stress& stress) const noexcept {
    // strain = a * stress - b * trace(stress) * identity_matrix
    // a = 1 / (2 * shear_modulus)
    // b = lame_first_modulus / (2 * shear_modulus * (2 * shear_modulus + 3 *
    // lame_first_modulus))
    const double denominator_1{2.0 * shear_modulus_.Value()};
    const double numerator_2{-lame_first_modulus_.Value()};
    const double denominator_2{
        2.0 * shear_modulus_.Value() *
        (2.0 * shear_modulus_.Value() + 3.0 * lame_first_modulus_.Value())};
    const double temporary{numerator_2 / denominator_2 *
                           stress.Value().Trace()};
    return PhQ::Strain{
        stress.Value() / denominator_1 +
        Value::SymmetricDyad{temporary, 0.0, 0.0, temporary, 0.0, temporary}};
  }

  inline std::string Print() const noexcept override {
    return {"Shear Modulus = " + shear_modulus_.Print() +
            ", Lamé's First Modulus = " + lame_first_modulus_.Print()};
  }

  inline std::string Json() const noexcept override {
    return {"{\"type\": \"" + LowerCaseCopy(Abbreviation(Type())) +
            "\", \"shear_modulus\": " + shear_modulus_.Json() +
            ", \"lame_first_modulus\": " + lame_first_modulus_.Json() + "}"};
  }

  inline std::string Xml() const noexcept override {
    return {"<type>" + LowerCaseCopy(Abbreviation(Type())) +
            "</type><shear_modulus>" + shear_modulus_.Xml() +
            "</shear_modulus><lame_first_modulus>" + lame_first_modulus_.Xml() +
            "</lame_first_modulus>"};
  }

  inline std::string Yaml() const noexcept override {
    return {"{type: \"" + LowerCaseCopy(Abbreviation(Type())) +
            "\", shear_modulus: " + shear_modulus_.Json() +
            ", lame_first_modulus: " + lame_first_modulus_.Json() + "}"};
  }

private:
  PhQ::ShearModulus shear_modulus_;

  PhQ::LameFirstModulus lame_first_modulus_;
};

inline bool operator==(const ElasticIsotropicSolid& left,
                       const ElasticIsotropicSolid& right) noexcept {
  return left.ShearModulus() == right.ShearModulus() &&
         left.LameFirstModulus() == right.LameFirstModulus();
}

inline bool operator!=(const ElasticIsotropicSolid& left,
                       const ElasticIsotropicSolid& right) noexcept {
  return left.ShearModulus() != right.ShearModulus() ||
         left.LameFirstModulus() != right.LameFirstModulus();
}

inline std::ostream& operator<<(std::ostream& stream,
                                const ElasticIsotropicSolid& model) noexcept {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ::ConstitutiveModel

namespace std {

template <>
struct hash<PhQ::ConstitutiveModel::ElasticIsotropicSolid> {
  size_t operator()(
      const PhQ::ConstitutiveModel::ElasticIsotropicSolid& model) const {
    size_t result = 17;
    result = 31 * result + hash<PhQ::ShearModulus>()(model.ShearModulus());
    result =
        31 * result + hash<PhQ::LameFirstModulus>()(model.LameFirstModulus());
    return result;
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_ELASTIC_ISOTROPIC_SOLID_HPP
