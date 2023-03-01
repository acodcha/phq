// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../DynamicViscosity.hpp"
#include "../StrainRate.hpp"
#include "../Stress.hpp"
#include "Base.hpp"

namespace PhQ {

namespace ConstitutiveModel {

class IncompressibleNewtonianFluid : public GenericConstitutiveModel<Type::IncompressibleNewtonianFluid> {

public:

  constexpr IncompressibleNewtonianFluid() noexcept : GenericConstitutiveModel<Type::IncompressibleNewtonianFluid>(), dynamic_viscosity_() {}

  constexpr IncompressibleNewtonianFluid(const DynamicViscosity& dynamic_viscosity) noexcept : GenericConstitutiveModel<Type::IncompressibleNewtonianFluid>(), dynamic_viscosity_(dynamic_viscosity) {}

  constexpr const DynamicViscosity& dynamic_viscosity() const noexcept {
    return dynamic_viscosity_;
  }

  Stress stress(const StrainRate& strain_rate) const noexcept {
    // stress = 2 * dynamic_viscosity * strain_rate
    return {{2.0 * dynamic_viscosity_.Value() * strain_rate.Value()}, StandardUnit<Unit::Pressure>};
  }

  StrainRate strain_rate(const Stress& stress) const noexcept {
    // strain_rate = stress / (2 * dynamic_viscosity)
    return {{stress.Value() / (2.0 * dynamic_viscosity_.Value())}, StandardUnit<Unit::Frequency>};
  }

  std::string Print() const noexcept override {
    return {"μ = " + dynamic_viscosity_.Print()};
  }

  std::string Json() const noexcept override {
    return {"{\"type\": \"" + LowerCaseCopy(Abbreviation(Type())) + "\", \"dynamic_viscosity\": " + dynamic_viscosity_.Json()+ "}"};
  }

  std::string Xml() const noexcept override {
    return {"<type>" + LowerCaseCopy(Abbreviation(Type())) + "</type><dynamic_viscosity>" + dynamic_viscosity_.Xml() + "</dynamic_viscosity>"};
  }

protected:

  DynamicViscosity dynamic_viscosity_;

};

} // namespace ConstitutiveModel

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::ConstitutiveModel::IncompressibleNewtonianFluid> {
  size_t operator()(const PhQ::ConstitutiveModel::IncompressibleNewtonianFluid& model) const {
    return hash<PhQ::DynamicViscosity>()(model.dynamic_viscosity());
  }
};

} // namespace std
