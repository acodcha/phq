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

  constexpr ElasticIsotropicSolid(const YoungModulus& young_modulus, const PoissonRatio& poisson_ratio) noexcept : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), young_modulus_(young_modulus), poisson_ratio_(poisson_ratio) {}

  ElasticIsotropicSolid(const YoungModulus& young_modulus, const ShearModulus& shear_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), young_modulus_(young_modulus) {
    const double denominator{2.0 * shear_modulus.value()};
    if (denominator != 0.0) {
      poisson_ratio_ = young_modulus.value() / denominator - 1.0;
    } else {
      throw std::runtime_error{"Division of " + young_modulus.print() + " by " + number_to_string(denominator) + "."};
    }
  }

  ElasticIsotropicSolid(const YoungModulus& young_modulus, const IsentropicBulkModulus& isentropic_bulk_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), young_modulus_(young_modulus) {
    const double denominator{6.0 * isentropic_bulk_modulus.value()};
    if (denominator != 0.0) {
      poisson_ratio_ = 0.5 - young_modulus.value() / denominator;
    } else {
      throw std::runtime_error{"Division of " + young_modulus.print() + " by " + number_to_string(denominator) + "."};
    }
  }

  ElasticIsotropicSolid(const YoungModulus& young_modulus, const IsothermalBulkModulus& isothermal_bulk_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), young_modulus_(young_modulus) {
    const double denominator{6.0 * isothermal_bulk_modulus.value()};
    if (denominator != 0.0) {
      poisson_ratio_ = 0.5 - young_modulus.value() / denominator;
    } else {
      throw std::runtime_error{"Division of " + young_modulus.print() + " by " + number_to_string(denominator) + "."};
    }
  }

  ElasticIsotropicSolid(const YoungModulus& young_modulus, const LameFirstModulus& lame_first_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), young_modulus_(young_modulus) {
    const double denominator{young_modulus_.value() + lame_first_modulus.value() + std::sqrt(std::pow(young_modulus_.value(), 2) + 9.0 * std::pow(lame_first_modulus.value(), 2) + 2.0 * young_modulus_.value() * lame_first_modulus.value())};
    if (denominator != 0.0) {
      poisson_ratio_ = 2.0 * lame_first_modulus.value() / denominator;
    } else {
      throw std::runtime_error{"Division of " + lame_first_modulus.print() + " by " + number_to_string(denominator) + "."};
    }
  }

  ElasticIsotropicSolid(const YoungModulus& young_modulus, const PWaveModulus& p_wave_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), young_modulus_(young_modulus) {
    const double denominator{4.0 * p_wave_modulus.value()};
    const double numerator{young_modulus.value() - p_wave_modulus.value() + std::sqrt(std::pow(young_modulus.value(), 2) + 9.0 * std::pow(p_wave_modulus.value(), 2) - 10.0 * young_modulus.value() * p_wave_modulus.value())};
    if (denominator != 0.0) {
      poisson_ratio_ = numerator / denominator;
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator) + " by " + number_to_string(denominator) + "."};
    }
  }

  constexpr ElasticIsotropicSolid(const ShearModulus& shear_modulus, const PoissonRatio& poisson_ratio) noexcept : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), young_modulus_(shear_modulus.value() * 2.0 * (poisson_ratio.value() + 1.0), standard_unit<Unit::Pressure>), poisson_ratio_(poisson_ratio) {}

  ElasticIsotropicSolid(const ShearModulus& shear_modulus, const IsentropicBulkModulus& isentropic_bulk_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>() {
    const double numerator_1{9.0 * shear_modulus.value() * isentropic_bulk_modulus.value()};
    const double denominator_1{shear_modulus.value() + 3.0 * isentropic_bulk_modulus.value()};
    if (denominator_1 != 0.0) {
      young_modulus_ = {numerator_1 / denominator_1, standard_unit<Unit::Pressure>};
      const double numerator_2{3.0 * isentropic_bulk_modulus.value() - 2.0 * shear_modulus.value()};
      const double denominator_2{2.0 * shear_modulus.value() + 6.0 * isentropic_bulk_modulus.value()};
      if (denominator_2 != 0.0) {
        poisson_ratio_ = numerator_2 / denominator_2;
      } else {
        throw std::runtime_error{"Division of " + number_to_string(numerator_2) + " by " + number_to_string(denominator_2) + "."};
      }
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator_1) + " by " + number_to_string(denominator_1) + "."};
    }
  }

  ElasticIsotropicSolid(const ShearModulus& shear_modulus, const IsothermalBulkModulus& isothermal_bulk_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>() {
    const double numerator_1{9.0 * shear_modulus.value() * isothermal_bulk_modulus.value()};
    const double denominator_1{shear_modulus.value() + 3.0 * isothermal_bulk_modulus.value()};
    if (denominator_1 != 0.0) {
      young_modulus_ = {numerator_1 / denominator_1, standard_unit<Unit::Pressure>};
      const double numerator_2{3.0 * isothermal_bulk_modulus.value() - 2.0 * shear_modulus.value()};
      const double denominator_2{2.0 * shear_modulus.value() + 6.0 * isothermal_bulk_modulus.value()};
      if (denominator_2 != 0.0) {
        poisson_ratio_ = numerator_2 / denominator_2;
      } else {
        throw std::runtime_error{"Division of " + number_to_string(numerator_2) + " by " + number_to_string(denominator_2) + "."};
      }
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator_1) + " by " + number_to_string(denominator_1) + "."};
    }
  }

  ElasticIsotropicSolid(const ShearModulus& shear_modulus, const LameFirstModulus& lame_first_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>() {
    const double numerator_1{shear_modulus.value() * (2.0 * shear_modulus.value() + 3.0 * lame_first_modulus.value())};
    const double denominator_1{shear_modulus.value() + lame_first_modulus.value()};
    if (denominator_1 != 0.0) {
      young_modulus_ = {numerator_1 / denominator_1, standard_unit<Unit::Pressure>};
      const double numerator_2{lame_first_modulus.value()};
      const double denominator_2{2.0 * (shear_modulus.value() + lame_first_modulus.value())};
      if (denominator_2 != 0.0) {
        poisson_ratio_ = numerator_2 / denominator_2;
      } else {
        throw std::runtime_error{"Division of " + number_to_string(numerator_2) + " by " + number_to_string(denominator_2) + "."};
      }
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator_1) + " by " + number_to_string(denominator_1) + "."};
    }
  }

  ElasticIsotropicSolid(const ShearModulus& shear_modulus, const PWaveModulus& p_wave_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>() {
    const double numerator_1{shear_modulus.value() * (3.0 * p_wave_modulus.value() - 4.0 * shear_modulus.value())};
    const double denominator_1{p_wave_modulus.value() - shear_modulus.value()};
    if (denominator_1 != 0.0) {
      young_modulus_ = {numerator_1 / denominator_1, standard_unit<Unit::Pressure>};
      const double numerator_2{p_wave_modulus.value() - 2.0 * shear_modulus.value()};
      const double denominator_2{2.0 * (p_wave_modulus.value() - shear_modulus.value())};
      if (denominator_2 != 0.0) {
        poisson_ratio_ = numerator_2 / denominator_2;
      } else {
        throw std::runtime_error{"Division of " + number_to_string(numerator_2) + " by " + number_to_string(denominator_2) + "."};
      }
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator_1) + " by " + number_to_string(denominator_1) + "."};
    }
  }

  ElasticIsotropicSolid(const IsentropicBulkModulus& isentropic_bulk_modulus, const LameFirstModulus& lame_first_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>() {
    const double numerator_1{9.0 * isentropic_bulk_modulus.value() * (isentropic_bulk_modulus.value() - lame_first_modulus.value())};
    const double denominator{3.0 * isentropic_bulk_modulus.value() - lame_first_modulus.value()};
    if (denominator != 0.0) {
      young_modulus_ = {numerator_1 / denominator, standard_unit<Unit::Pressure>};
      const double numerator_2{lame_first_modulus.value()};
      poisson_ratio_ = numerator_2 / denominator;
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator_1) + " by " + number_to_string(denominator) + "."};
    }
  }

  ElasticIsotropicSolid(const IsentropicBulkModulus& isentropic_bulk_modulus, const PWaveModulus& p_wave_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>() {
    const double numerator_1{9.0 * isentropic_bulk_modulus.value() * (p_wave_modulus.value() - isentropic_bulk_modulus.value())};
    const double denominator{3.0 * isentropic_bulk_modulus.value() + p_wave_modulus.value()};
    if (denominator != 0.0) {
      young_modulus_ = {numerator_1 / denominator, standard_unit<Unit::Pressure>};
      const double numerator_2{3.0 * isentropic_bulk_modulus.value() - p_wave_modulus.value()};
      poisson_ratio_ = numerator_2 / denominator;
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator_1) + " by " + number_to_string(denominator) + "."};
    }
  }

  ElasticIsotropicSolid(const IsothermalBulkModulus& isothermal_bulk_modulus, const LameFirstModulus& lame_first_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>() {
    const double numerator_1{9.0 * isothermal_bulk_modulus.value() * (isothermal_bulk_modulus.value() - lame_first_modulus.value())};
    const double denominator{3.0 * isothermal_bulk_modulus.value() - lame_first_modulus.value()};
    if (denominator != 0.0) {
      young_modulus_ = {numerator_1 / denominator, standard_unit<Unit::Pressure>};
      const double numerator_2{lame_first_modulus.value()};
      poisson_ratio_ = numerator_2 / denominator;
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator_1) + " by " + number_to_string(denominator) + "."};
    }
  }

  ElasticIsotropicSolid(const IsothermalBulkModulus& isothermal_bulk_modulus, const PWaveModulus& p_wave_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>() {
    const double numerator_1{9.0 * isothermal_bulk_modulus.value() * (p_wave_modulus.value() - isothermal_bulk_modulus.value())};
    const double denominator{3.0 * isothermal_bulk_modulus.value() + p_wave_modulus.value()};
    if (denominator != 0.0) {
      young_modulus_ = {numerator_1 / denominator, standard_unit<Unit::Pressure>};
      const double numerator_2{3.0 * isothermal_bulk_modulus.value() - p_wave_modulus.value()};
      poisson_ratio_ = numerator_2 / denominator;
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator_1) + " by " + number_to_string(denominator) + "."};
    }
  }

  ElasticIsotropicSolid(const LameFirstModulus& lame_first_modulus, const PWaveModulus& p_wave_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>() {
    const double numerator_1{(p_wave_modulus.value() - lame_first_modulus.value()) * (p_wave_modulus.value() + 2.0 * lame_first_modulus.value())};
    const double denominator{p_wave_modulus.value() + lame_first_modulus.value()};
    if (denominator != 0.0) {
      young_modulus_ = {numerator_1 / denominator, standard_unit<Unit::Pressure>};
      const double numerator_2{lame_first_modulus.value()};
      poisson_ratio_ = numerator_2 / denominator;
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator_1) + " by " + number_to_string(denominator) + "."};
    }
  }

  constexpr const YoungModulus& young_modulus() const noexcept {
    return young_modulus_;
  }

  constexpr const PoissonRatio& poisson_ratio() const noexcept {
    return poisson_ratio_;
  }

  constexpr ShearModulus shear_modulus() const {
    const double denominator{2.0 + 2.0 * poisson_ratio_.value()};
    if (denominator != 0.0) {
      return {young_modulus_.value() / denominator, standard_unit<Unit::Pressure>};
    } else {
      throw std::runtime_error{"Division of " + young_modulus_.print() + " by " + number_to_string(denominator) + "."};
    }
  }

  constexpr IsentropicBulkModulus isentropic_bulk_modulus() const {
    const double denominator{3.0 - 6.0 * poisson_ratio_.value()};
    if (denominator != 0.0) {
      return {young_modulus_.value() / denominator, standard_unit<Unit::Pressure>};
    } else {
      throw std::runtime_error{"Division of " + young_modulus_.print() + " by " + number_to_string(denominator) + "."};
    }
  }

  constexpr IsothermalBulkModulus isothermal_bulk_modulus() const {
    const double denominator{3.0 - 6.0 * poisson_ratio_.value()};
    if (denominator != 0.0) {
      return {young_modulus_.value() / denominator, standard_unit<Unit::Pressure>};
    } else {
      throw std::runtime_error{"Division of " + young_modulus_.print() + " by " + number_to_string(denominator) + "."};
    }
  }

  constexpr PWaveModulus p_wave_modulus() const {
    const double numerator{young_modulus_.value() * (1.0 - poisson_ratio_.value())};
    const double denominator{(1.0 + poisson_ratio_.value()) * (1.0 - 2.0 * poisson_ratio_.value())};
    if (denominator != 0.0) {
      return {numerator / denominator, standard_unit<Unit::Pressure>};
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator) + " by " + number_to_string(denominator) + "."};
    }
  }

  constexpr LameFirstModulus lame_first_modulus() const {
    const double numerator{young_modulus_.value() * poisson_ratio_.value()};
    const double denominator{(1.0 + poisson_ratio_.value()) * (1.0 - 2.0 * poisson_ratio_.value())};
    if (denominator != 0.0) {
      return {numerator / denominator, standard_unit<Unit::Pressure>};
    } else {
      throw std::runtime_error{"Division of " + number_to_string(numerator) + " by " + number_to_string(denominator) + "."};
    }
  }

  std::string print() const noexcept {
    return {"E = " + young_modulus_.print() + ", ν = " + poisson_ratio_.print()};
  }

  std::string json() const noexcept {
    return {"{\"type\": \"" + lowercase(abbreviation(type())) + "\", \"young_modulus\": " + young_modulus_.print() + ", \"poisson_ratio\": " + poisson_ratio_.print() + "}"};
  }

  std::string xml() const noexcept {
    return {"<type>" + lowercase(abbreviation(type())) + "</type><young_modulus>" + young_modulus_.print() + "</young_modulus><poisson_ratio>" + poisson_ratio_.print() + "</poisson_ratio>"};
  }

protected:

  YoungModulus young_modulus_;

  PoissonRatio poisson_ratio_;

};

} // namespace ConstitutiveModel

constexpr bool sort(const ConstitutiveModel::ElasticIsotropicSolid& model1, const ConstitutiveModel::ElasticIsotropicSolid& model2) noexcept {
  if (model1.young_modulus() < model2.young_modulus()) {
    return true;
  } else if (model1.young_modulus() > model2.young_modulus()) {
    return false;
  } else {
    return model1.poisson_ratio() < model2.poisson_ratio();
  }
}

} // namespace PhQ
