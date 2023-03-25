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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_INCOMPRESSIBLE_NEWTONIAN_FLUID_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_INCOMPRESSIBLE_NEWTONIAN_FLUID_HPP

#include "../DynamicViscosity.hpp"
#include "Base.hpp"

namespace PhQ {

class IncompressibleNewtonianFluid : public ConstitutiveModel {
public:
  constexpr IncompressibleNewtonianFluid() noexcept
      : ConstitutiveModel(), dynamic_viscosity_() {}

  constexpr IncompressibleNewtonianFluid(
      const DynamicViscosity& dynamic_viscosity) noexcept
      : ConstitutiveModel(), dynamic_viscosity_(dynamic_viscosity) {}

  inline constexpr const PhQ::DynamicViscosity& DynamicViscosity()
      const noexcept {
    return dynamic_viscosity_;
  }

  inline Type GetType() const noexcept override {
    return Type::IncompressibleNewtonianFluid;
  }

  inline PhQ::Stress Stress(
      const PhQ::Strain& strain,
      const PhQ::StrainRate& strain_rate) const noexcept override {
    // stress = 2 * dynamic_viscosity * strain_rate
    return {{2.0 * dynamic_viscosity_.Value() * strain_rate.Value()},
            StandardUnit<Unit::Pressure>};
  }

  inline PhQ::StrainRate StrainRate(const PhQ::Stress& stress) const noexcept {
    // strain_rate = stress / (2 * dynamic_viscosity)
    return {{stress.Value() / (2.0 * dynamic_viscosity_.Value())},
            StandardUnit<Unit::Frequency>};
  }

  inline std::string Print() const noexcept override {
    return {"Type = " + LowerCaseCopy(Abbreviation(GetType())) +
            ", Dynamic Viscosity = " + dynamic_viscosity_.Print()};
  }

  inline std::string Json() const noexcept override {
    return {"{\"type\": \"" + LowerCaseCopy(Abbreviation(GetType())) +
            "\", \"dynamic_viscosity\": " + dynamic_viscosity_.Json() + "}"};
  }

  inline std::string Xml() const noexcept override {
    return {"<type>" + LowerCaseCopy(Abbreviation(GetType())) +
            "</type><dynamic_viscosity>" + dynamic_viscosity_.Xml() +
            "</dynamic_viscosity>"};
  }

  inline std::string Yaml() const noexcept override {
    return {"{type: \"" + LowerCaseCopy(Abbreviation(GetType())) +
            "\", dynamic_viscosity: " + dynamic_viscosity_.Json() + "}"};
  }

private:
  PhQ::DynamicViscosity dynamic_viscosity_;
};

inline bool operator==(const IncompressibleNewtonianFluid& left,
                       const IncompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() == right.DynamicViscosity();
}

inline bool operator!=(const IncompressibleNewtonianFluid& left,
                       const IncompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() != right.DynamicViscosity();
}

inline std::ostream& operator<<(
    std::ostream& stream, const IncompressibleNewtonianFluid& model) noexcept {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::IncompressibleNewtonianFluid> {
  size_t operator()(const PhQ::IncompressibleNewtonianFluid& model) const {
    return hash<PhQ::DynamicViscosity>()(model.DynamicViscosity());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_INCOMPRESSIBLE_NEWTONIAN_FLUID_HPP
