// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

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

  CompressibleNewtonianFluid(const DynamicViscosity& dynamic_viscosity) noexcept : GenericConstitutiveModel<Type::CompressibleNewtonianFluid>(), dynamic_viscosity_(dynamic_viscosity), bulk_dynamic_viscosity_({-2.0 / 3.0 * dynamic_viscosity.Value(), StandardUnit<Unit::DynamicViscosity>}) {}

  constexpr CompressibleNewtonianFluid(const DynamicViscosity& dynamic_viscosity, const BulkDynamicViscosity& bulk_dynamic_viscosity) noexcept : GenericConstitutiveModel<Type::CompressibleNewtonianFluid>(), dynamic_viscosity_(dynamic_viscosity), bulk_dynamic_viscosity_(bulk_dynamic_viscosity) {}

  constexpr const DynamicViscosity& dynamic_viscosity() const noexcept {
    return dynamic_viscosity_;
  }

  constexpr const BulkDynamicViscosity& bulk_dynamic_viscosity() const noexcept {
    return bulk_dynamic_viscosity_;
  }

  Stress stress(const StrainRate& strain_rate) const noexcept {
    // stress = a * strain_rate + b * trace(strain_rate) * identity_matrix
    // a = 2 * dynamic_viscosity
    // b = bulk_dynamic_viscosity
    const double temporary_1{2.0 * dynamic_viscosity_.Value()};
    const double temporary_2{bulk_dynamic_viscosity_.Value() * strain_rate.Value().Trace()};
    return {Value::SymmetricDyad{temporary_1 * strain_rate.Value()} + Value::SymmetricDyad{temporary_2, 0.0, 0.0, temporary_2, 0.0, temporary_2}, StandardUnit<Unit::Pressure>};
  }

  std::string Print() const noexcept override {
    return {"μ = " + dynamic_viscosity_.Print() + ", μ_B = " + bulk_dynamic_viscosity_.Print()};
  }

  std::string Json() const noexcept override {
    return {"{\"type\": \"" + LowerCaseCopy(Abbreviation(Type())) + "\", \"dynamic_viscosity\": " + dynamic_viscosity_.Json()+ "\", \"bulk_dynamic_viscosity\": " + bulk_dynamic_viscosity_.Json() + "}"};
  }

  std::string Xml() const noexcept override {
    return {"<type>" + LowerCaseCopy(Abbreviation(Type())) + "</type><dynamic_viscosity>" + dynamic_viscosity_.Xml() + "</dynamic_viscosity><bulk_dynamic_viscosity>" + bulk_dynamic_viscosity_.Xml() + "</bulk_dynamic_viscosity>"};
  }

protected:

  DynamicViscosity dynamic_viscosity_;

  BulkDynamicViscosity bulk_dynamic_viscosity_;

};

} // namespace ConstitutiveModel

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::ConstitutiveModel::CompressibleNewtonianFluid> {
  size_t operator()(const PhQ::ConstitutiveModel::CompressibleNewtonianFluid& model) const {
    return hash<PhQ::DynamicViscosity>()(model.dynamic_viscosity()) ^ hash<PhQ::BulkDynamicViscosity>()(model.bulk_dynamic_viscosity());
  }
};

} // namespace std
