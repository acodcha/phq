// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../PoissonRatio.hpp"
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

  constexpr ElasticIsotropicSolid(const ShearModulus& shear_modulus, const PoissonRatio& poisson_ratio) noexcept : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), young_modulus_(shear_modulus.value() * 2.0 * (poisson_ratio.value() + 1.0), standard_unit<Unit::Pressure>), poisson_ratio_(poisson_ratio) {}

  ElasticIsotropicSolid(const YoungModulus& young_modulus, const ShearModulus& shear_modulus) : GenericConstitutiveModel<Type::ElasticIsotropicSolid>(), young_modulus_(young_modulus) {
    const double denominator{2.0 * shear_modulus.value()};
    if (denominator != 0.0) {
      poisson_ratio_ = young_modulus.value() / denominator - 1.0;
    } else {
      throw std::runtime_error{"Division of " + young_modulus.print() + " by " + number_to_string(denominator) + "."};
    }
  }

  constexpr const YoungModulus& young_modulus() const noexcept {
    return young_modulus_;
  }

  constexpr const PoissonRatio& poisson_ratio() const noexcept {
    return poisson_ratio_;
  }

  constexpr ShearModulus shear_modulus() const {
    const double denominator{2.0 * (1.0 + poisson_ratio_.value())};
    if (denominator != 0.0) {
      return {young_modulus_.value() / denominator, standard_unit<Unit::Pressure>};
    } else {
      throw std::runtime_error{"Division of " + young_modulus_.print() + " by " + number_to_string(denominator) + "."};
    }
  }

  std::string print() const noexcept {
    return {"E = " + young_modulus_.print() + ", ν = " + poisson_ratio_.print()};
  }

  std::string json() const noexcept {
    return {"{\"type\": \"" + lowercase(abbreviation(type())) + "\", \"elastic_modulus\": " + young_modulus_.print() + ", \"poisson_ratio\": " + poisson_ratio_.print() + "}"};
  }

  std::string xml() const noexcept {
    return {"<type>" + lowercase(abbreviation(type())) + "</type><elastic_modulus>" + young_modulus_.print() + "</elastic_modulus><poisson_ratio>" + poisson_ratio_.print() + "</poisson_ratio>"};
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
