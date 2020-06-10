// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../BulkDynamicViscosity.hpp"
#include "../DynamicViscosity.hpp"
#include "../StrainRate.hpp"
#include "../Stress.hpp"
#include "Base.hpp"

namespace PhQ {

namespace ConstitutiveModel {

class CompressibleNewtonianFluid : public GenericConstitutiveModel<Type::CompressibleNewtonianFluid> {

public:

  constexpr CompressibleNewtonianFluid() noexcept : GenericConstitutiveModel<Type::CompressibleNewtonianFluid>(), dynamic_viscosity_(), bulk_dynamic_viscosity_() {}

  constexpr CompressibleNewtonianFluid(const DynamicViscosity& dynamic_viscosity) noexcept : GenericConstitutiveModel<Type::CompressibleNewtonianFluid>(), dynamic_viscosity_(dynamic_viscosity), bulk_dynamic_viscosity_({-2.0 / 3.0 * dynamic_viscosity.value(), standard_unit<Unit::DynamicViscosity>}) {}

  constexpr CompressibleNewtonianFluid(const DynamicViscosity& dynamic_viscosity, const BulkDynamicViscosity& bulk_dynamic_viscosity) noexcept : GenericConstitutiveModel<Type::CompressibleNewtonianFluid>(), dynamic_viscosity_(dynamic_viscosity), bulk_dynamic_viscosity_(bulk_dynamic_viscosity) {}

  constexpr const DynamicViscosity& dynamic_viscosity() const noexcept {
    return dynamic_viscosity_;
  }

  constexpr const BulkDynamicViscosity& bulk_dynamic_viscosity() const noexcept {
    return bulk_dynamic_viscosity_;
  }

  constexpr Stress stress(const StrainRate& strain_rate) const noexcept {
    // stress = a * strain_rate + b * trace(strain_rate) * identity_matrix
    // a = 2 * dynamic_viscosity
    // b = bulk_dynamic_viscosity
    const double temporary_1{2.0 * dynamic_viscosity_.value()};
    const double temporary_2{bulk_dynamic_viscosity_.value() * strain_rate.value().trace()};
    return {Value::SymmetricDyadic{temporary_1 * strain_rate.value()} + Value::SymmetricDyadic{temporary_2, 0.0, 0.0, temporary_2, 0.0, temporary_2}, standard_unit<Unit::Pressure>};
  }

  std::string print() const noexcept {
    return {"μ = " + dynamic_viscosity_.print() + ", μ_B = " + bulk_dynamic_viscosity_.print()};
  }

  std::string json() const noexcept {
    return {"{\"type\": \"" + lowercase(abbreviation(type())) + "\", \"dynamic_viscosity\": " + dynamic_viscosity_.json()+ "\", \"bulk_dynamic_viscosity\": " + bulk_dynamic_viscosity_.json() + "}"};
  }

  std::string xml() const noexcept {
    return {"<type>" + lowercase(abbreviation(type())) + "</type><dynamic_viscosity>" + dynamic_viscosity_.xml() + "</dynamic_viscosity><bulk_dynamic_viscosity>" + bulk_dynamic_viscosity_.xml() + "</bulk_dynamic_viscosity>"};
  }

protected:

  DynamicViscosity dynamic_viscosity_;

  BulkDynamicViscosity bulk_dynamic_viscosity_;

};

} // namespace ConstitutiveModel

constexpr bool sort(const ConstitutiveModel::CompressibleNewtonianFluid& model_1, const ConstitutiveModel::CompressibleNewtonianFluid& model_2) noexcept {
  if (model_1.dynamic_viscosity() == model_2.dynamic_viscosity()) {
    return model_1.bulk_dynamic_viscosity() < model_2.bulk_dynamic_viscosity();
  } else {
    return model_1.dynamic_viscosity() < model_2.dynamic_viscosity();
  }
}

} // namespace PhQ
