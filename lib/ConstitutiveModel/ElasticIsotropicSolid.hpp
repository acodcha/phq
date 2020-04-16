// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../LameFirstModulus.hpp"
#include "../IsentropicBulkModulus.hpp"
#include "../IsothermalBulkModulus.hpp"
#include "../PoissonRatio.hpp"
#include "../PWaveModulus.hpp"
#include "../ShearModulus.hpp"
#include "../Strain.hpp"
#include "../Stress.hpp"
#include "../YoungModulus.hpp"
#include "Base.hpp"

namespace PhQ {

namespace ConstitutiveModel {

class ElasticIsotropicSolid : public GenericConstitutiveModel<Type::ElasticIsotropicSolid> {

public:

  ElasticIsotropicSolid() noexcept : GenericConstitutiveModel<Type::ElasticIsotropicSolid>() {}

  ElasticIsotropicSolid(const YoungModulus& young_modulus, const PoissonRatio& poisson_ratio) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>() {
    const double numerator_1{young_modulus.value()};
    const double numerator_2{young_modulus.value() * poisson_ratio.value()};
    const double denominator_1{2.0 * (1.0 + poisson_ratio.value())};
    const double denominator_2{(1.0 + poisson_ratio.value()) * (1.0 - 2.0 * poisson_ratio.value())};
    if (denominator_1 != 0.0) {
      shear_modulus_ = {numerator_1 / denominator_1, standard_unit<Unit::Pressure>};
      if (denominator_2 != 0.0) {
        lame_first_modulus_ = {numerator_2 / denominator_2, standard_unit<Unit::Pressure>};
      } else {
        throw std::runtime_error{"Division of " + number_to_string(numerator_2) + " by " + number_to_string(denominator_2) + "."};
      }
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator_1) + " by " + number_to_string(denominator_1) + "."};
    }
  }

  ElasticIsotropicSolid(const YoungModulus& young_modulus, const ShearModulus& shear_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), shear_modulus_(shear_modulus) {
    const double numerator{shear_modulus.value() * (young_modulus.value() - 2.0 * shear_modulus.value())};
    const double denominator{3.0 * shear_modulus.value() - young_modulus.value()};
    if (denominator != 0.0) {
      lame_first_modulus_ = {numerator / denominator, standard_unit<Unit::Pressure>};
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator) + " by " + number_to_string(denominator) + "."};
    }
  }

  ElasticIsotropicSolid(const YoungModulus& young_modulus, const IsentropicBulkModulus& isentropic_bulk_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>() {
    const double numerator_1{3.0 * young_modulus.value() * isentropic_bulk_modulus.value()};
    const double numerator_2{3.0 * isentropic_bulk_modulus.value() * (3.0 * isentropic_bulk_modulus.value() - young_modulus.value())};
    const double denominator{9.0 * isentropic_bulk_modulus.value() - young_modulus.value()};
    if (denominator != 0.0) {
      shear_modulus_ = {numerator_1 / denominator, standard_unit<Unit::Pressure>};
      lame_first_modulus_ = {numerator_2 / denominator, standard_unit<Unit::Pressure>};
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator_1) + " by " + number_to_string(denominator) + "."};
    }
  }

  ElasticIsotropicSolid(const YoungModulus& young_modulus, const IsothermalBulkModulus& isothermal_bulk_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>() {
    const double numerator_1{3.0 * young_modulus.value() * isothermal_bulk_modulus.value()};
    const double numerator_2{3.0 * isothermal_bulk_modulus.value() * (3.0 * isothermal_bulk_modulus.value() - young_modulus.value())};
    const double denominator{9.0 * isothermal_bulk_modulus.value() - young_modulus.value()};
    if (denominator != 0.0) {
      shear_modulus_ = {numerator_1 / denominator, standard_unit<Unit::Pressure>};
      lame_first_modulus_ = {numerator_2 / denominator, standard_unit<Unit::Pressure>};
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator_1) + " by " + number_to_string(denominator) + "."};
    }
  }

  constexpr ElasticIsotropicSolid(const YoungModulus& young_modulus, const LameFirstModulus& lame_first_modulus) noexcept : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), shear_modulus_(0.25 * (young_modulus.value() - 3.0 * lame_first_modulus.value() + std::sqrt(std::pow(young_modulus.value(), 2) + 9.0 * std::pow(lame_first_modulus.value(), 2) + 2.0 * young_modulus.value() * lame_first_modulus.value())), standard_unit<Unit::Pressure>), lame_first_modulus_(lame_first_modulus) {}

  constexpr ElasticIsotropicSolid(const YoungModulus& young_modulus, const PWaveModulus& p_wave_modulus) noexcept : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), shear_modulus_(0.125 * (3.0 * p_wave_modulus.value() + young_modulus.value() - std::sqrt(std::pow(young_modulus.value(), 2) + 9.0 * std::pow(p_wave_modulus.value(), 2) - 10.0 * young_modulus.value() * p_wave_modulus.value())), standard_unit<Unit::Pressure>), lame_first_modulus_(0.25 * (p_wave_modulus.value() - young_modulus.value() + std::sqrt(std::pow(young_modulus.value(), 2) + 9.0 * std::pow(p_wave_modulus.value(), 2) - 10.0 * young_modulus.value() * p_wave_modulus.value())), standard_unit<Unit::Pressure>) {}

  ElasticIsotropicSolid(const ShearModulus& shear_modulus, const PoissonRatio& poisson_ratio) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), shear_modulus_(shear_modulus) {
    const double numerator{2.0 * shear_modulus.value() * poisson_ratio.value()};
    const double denominator{1.0 - 2.0 * poisson_ratio.value()};
    if (denominator != 0.0) {
      lame_first_modulus_ = {numerator / denominator, standard_unit<Unit::Pressure>};
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator) + " by " + number_to_string(denominator) + "."};
    }
  }

  constexpr ElasticIsotropicSolid(const ShearModulus& shear_modulus, const IsentropicBulkModulus& isentropic_bulk_modulus) noexcept : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), shear_modulus_(shear_modulus), lame_first_modulus_(isentropic_bulk_modulus.value() - 2.0 / 3.0 * shear_modulus.value(), standard_unit<Unit::Pressure>) {}

  constexpr ElasticIsotropicSolid(const ShearModulus& shear_modulus, const IsothermalBulkModulus& isothermal_bulk_modulus) noexcept : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), shear_modulus_(shear_modulus), lame_first_modulus_(isothermal_bulk_modulus.value() - 2.0 / 3.0 * shear_modulus.value(), standard_unit<Unit::Pressure>) {}

  constexpr ElasticIsotropicSolid(const ShearModulus& shear_modulus, const LameFirstModulus& lame_first_modulus) noexcept : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), shear_modulus_(shear_modulus), lame_first_modulus_(lame_first_modulus) {}

  constexpr ElasticIsotropicSolid(const ShearModulus& shear_modulus, const PWaveModulus& p_wave_modulus) noexcept : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), shear_modulus_(shear_modulus), lame_first_modulus_(p_wave_modulus.value() - 2.0 * shear_modulus.value(), standard_unit<Unit::Pressure>) {}

  constexpr ElasticIsotropicSolid(const IsentropicBulkModulus& isentropic_bulk_modulus, const LameFirstModulus& lame_first_modulus) noexcept : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), shear_modulus_(1.5 * (isentropic_bulk_modulus.value() - lame_first_modulus.value()), standard_unit<Unit::Pressure>), lame_first_modulus_(lame_first_modulus) {}

  constexpr ElasticIsotropicSolid(const IsentropicBulkModulus& isentropic_bulk_modulus, const PWaveModulus& p_wave_modulus) noexcept : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), shear_modulus_(0.75 * (p_wave_modulus.value() - isentropic_bulk_modulus.value()), standard_unit<Unit::Pressure>), lame_first_modulus_(1.5 * isentropic_bulk_modulus.value() - 0.5 * p_wave_modulus.value(), standard_unit<Unit::Pressure>) {}

  constexpr ElasticIsotropicSolid(const IsothermalBulkModulus& isothermal_bulk_modulus, const LameFirstModulus& lame_first_modulus) noexcept : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), shear_modulus_(1.5 * (isothermal_bulk_modulus.value() - lame_first_modulus.value()), standard_unit<Unit::Pressure>), lame_first_modulus_(lame_first_modulus) {}

  constexpr ElasticIsotropicSolid(const IsothermalBulkModulus& isothermal_bulk_modulus, const PWaveModulus& p_wave_modulus) noexcept : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), shear_modulus_(0.75 * (p_wave_modulus.value() - isothermal_bulk_modulus.value()), standard_unit<Unit::Pressure>), lame_first_modulus_(1.5 * isothermal_bulk_modulus.value() - 0.5 * p_wave_modulus.value(), standard_unit<Unit::Pressure>) {}

  constexpr ElasticIsotropicSolid(const LameFirstModulus& lame_first_modulus, const PWaveModulus& p_wave_modulus) noexcept : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), shear_modulus_(0.5 * (p_wave_modulus.value() - lame_first_modulus.value()), standard_unit<Unit::Pressure>), lame_first_modulus_(lame_first_modulus) {}

  constexpr const ShearModulus& shear_modulus() const noexcept {
    return shear_modulus_;
  }

  constexpr const LameFirstModulus& lame_first_modulus() const noexcept {
    return lame_first_modulus_;
  }

  YoungModulus young_modulus() const {
    const double numerator{shear_modulus_.value() * ( 3.0 * lame_first_modulus_.value() + 2.0 * shear_modulus_.value())};
    const double denominator{shear_modulus_.value() + lame_first_modulus_.value()};
    if (denominator != 0.0) {
      return {numerator / denominator, standard_unit<Unit::Pressure>};
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator) + " by " + number_to_string(denominator) + "."};
    }
  }

  constexpr IsentropicBulkModulus isentropic_bulk_modulus() const noexcept {
    return {lame_first_modulus_.value() + 2.0 / 3.0 * shear_modulus_.value(), standard_unit<Unit::Pressure>};
  }

  constexpr IsothermalBulkModulus isothermal_bulk_modulus() const noexcept {
    return {lame_first_modulus_.value() + 2.0 / 3.0 * shear_modulus_.value(), standard_unit<Unit::Pressure>};
  }

  constexpr PWaveModulus p_wave_modulus() const noexcept {
    return {lame_first_modulus_.value() + 2.0 * shear_modulus_.value(), standard_unit<Unit::Pressure>};
  }

  PoissonRatio poisson_ratio() const {
    const double numerator{0.5 * lame_first_modulus_.value()};
    const double denominator{shear_modulus_.value() + lame_first_modulus_.value()};
    if (denominator != 0.0) {
      return {numerator / denominator};
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator) + " by " + number_to_string(denominator) + "."};
    }
  }

  constexpr Stress stress(const Strain& strain) const noexcept {
    // stress = a * strain + b * trace(strain) * identity_matrix
    // a = 2 * shear_modulus
    // b = lame_first_modulus
    const double temporary{lame_first_modulus_.value() * strain.value().trace()};
    return {2.0 * shear_modulus_.value() * strain.value() + Value::SymmetricDyadic{temporary, 0.0, 0.0, temporary, 0.0, temporary}, standard_unit<Unit::Pressure>};
  }

  Strain strain(const Stress& stress) const {
    // strain = a * stress - b * trace(stress) * identity_matrix
    // a = 1 / (2 * shear_modulus)
    // b = lame_first_modulus / ((2 * shear_modulus) * (2 * shear_modulus + 3 * lame_first_modulus))
    const double denominator_1{2.0 * shear_modulus_.value()};
    if (denominator_1 != 0.0) {
      const double numerator_2{-lame_first_modulus_.value()};
      const double denominator_2{2.0 * shear_modulus_.value() * (2.0 * shear_modulus_.value() + 3.0 * lame_first_modulus_.value())};
      if (denominator_2 != 0.0) {
        const double temporary{numerator_2 / denominator_2 * stress.value().trace()};
        return {stress.value() / denominator_1 + Value::SymmetricDyadic{temporary, 0.0, 0.0, temporary, 0.0, temporary}};
      } else {
        throw std::runtime_error{"Division of " + number_to_string(numerator_2) + " by " + number_to_string(denominator_2) + "."};
      }
    } else {
      throw std::runtime_error{"Division of " + number_to_string(1.0) + " by " + number_to_string(denominator_1) + "."};
    }
  }

  std::string print() const noexcept {
    return {"G = " + shear_modulus_.print() + ", λ = " + lame_first_modulus_.print()};
  }

  std::string json() const noexcept {
    return {"{\"type\": \"" + lowercase(abbreviation(type())) + "\", \"shear_modulus\": " + shear_modulus_.print() + ", \"lamé_first_modulus\": " + lame_first_modulus_.print() + "}"};
  }

  std::string xml() const noexcept {
    return {"<type>" + lowercase(abbreviation(type())) + "</type><shear_modulus>" + shear_modulus_.print() + "</shear_modulus><lamé_first_modulus>" + lame_first_modulus_.print() + "</lamé_first_modulus>"};
  }

protected:

  ShearModulus shear_modulus_;

  LameFirstModulus lame_first_modulus_;

};

} // namespace ConstitutiveModel

constexpr bool sort(const ConstitutiveModel::ElasticIsotropicSolid& model1, const ConstitutiveModel::ElasticIsotropicSolid& model2) noexcept {
  if (model1.shear_modulus() < model2.shear_modulus()) {
    return true;
  } else if (model1.shear_modulus() > model2.shear_modulus()) {
    return false;
  } else {
    return model1.lame_first_modulus() < model2.lame_first_modulus();
  }
}

} // namespace PhQ
