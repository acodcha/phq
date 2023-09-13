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

#include "../ConstitutiveModel.hpp"
#include "../DynamicViscosity.hpp"

namespace PhQ {

// Constitutive model for an incompressible Newtonian fluid. This is the
// simplest constitutive model for a fluid. The viscous stress tensor at a point
// is a linear function of only the local strain rate tensor at that point.
class ConstitutiveModel::IncompressibleNewtonianFluid
  : public ConstitutiveModel {
public:
  constexpr IncompressibleNewtonianFluid() noexcept
    : ConstitutiveModel(), dynamic_viscosity_() {}

  constexpr IncompressibleNewtonianFluid(
      const DynamicViscosity& dynamic_viscosity) noexcept
    : ConstitutiveModel(), dynamic_viscosity_(dynamic_viscosity) {}

  inline constexpr const PhQ::DynamicViscosity&
  DynamicViscosity() const noexcept {
    return dynamic_viscosity_;
  }

  inline Type GetType() const noexcept override {
    return Type::IncompressibleNewtonianFluid;
  }

  inline PhQ::Stress Stress(
      const PhQ::Strain& strain,
      const PhQ::StrainRate& strain_rate) const noexcept override {
    return Stress(strain_rate);
  }

  inline PhQ::Stress Stress(const PhQ::Strain& strain) const noexcept override {
    return {
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        Standard<Unit::Pressure>
    };
  }

  inline PhQ::Stress Stress(
      const PhQ::StrainRate& strain_rate) const noexcept override {
    // stress = 2 * dynamic_viscosity * strain_rate
    return {{2.0 * dynamic_viscosity_.Value() * strain_rate.Value()},
            Standard<Unit::Pressure>};
  }

  inline PhQ::Strain Strain(const PhQ::Stress& stress) const noexcept override {
    return PhQ::Strain{
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
    };
  }

  inline PhQ::StrainRate StrainRate(
      const PhQ::Stress& stress) const noexcept override {
    // strain_rate = stress / (2 * dynamic_viscosity)
    return {{stress.Value() / (2.0 * dynamic_viscosity_.Value())},
            Standard<Unit::Frequency>};
  }

  inline std::string Print() const noexcept override {
    return {"Type = " + std::string{Abbreviation(GetType())}
            + ", Dynamic Viscosity = " + dynamic_viscosity_.Print()};
  }

  inline std::string JSON() const noexcept override {
    return {"{\"type\":\"" + SnakeCaseCopy(Abbreviation(GetType()))
            + "\",\"dynamic_viscosity\":" + dynamic_viscosity_.JSON() + "}"};
  }

  inline std::string XML() const noexcept override {
    return {"<type>" + SnakeCaseCopy(Abbreviation(GetType()))
            + "</type><dynamic_viscosity>" + dynamic_viscosity_.XML()
            + "</dynamic_viscosity>"};
  }

  inline std::string YAML() const noexcept override {
    return {"{type:\"" + SnakeCaseCopy(Abbreviation(GetType()))
            + "\",dynamic_viscosity:" + dynamic_viscosity_.YAML() + "}"};
  }

private:
  PhQ::DynamicViscosity dynamic_viscosity_;
};

inline constexpr bool operator==(
    const ConstitutiveModel::IncompressibleNewtonianFluid& left,
    const ConstitutiveModel::IncompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() == right.DynamicViscosity();
}

inline constexpr bool operator!=(
    const ConstitutiveModel::IncompressibleNewtonianFluid& left,
    const ConstitutiveModel::IncompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() != right.DynamicViscosity();
}

inline constexpr bool operator<(
    const ConstitutiveModel::IncompressibleNewtonianFluid& left,
    const ConstitutiveModel::IncompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() < right.DynamicViscosity();
}

inline constexpr bool operator>(
    const ConstitutiveModel::IncompressibleNewtonianFluid& left,
    const ConstitutiveModel::IncompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() > right.DynamicViscosity();
}

inline constexpr bool operator<=(
    const ConstitutiveModel::IncompressibleNewtonianFluid& left,
    const ConstitutiveModel::IncompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() <= right.DynamicViscosity();
}

inline constexpr bool operator>=(
    const ConstitutiveModel::IncompressibleNewtonianFluid& left,
    const ConstitutiveModel::IncompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() >= right.DynamicViscosity();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const ConstitutiveModel::IncompressibleNewtonianFluid& model) noexcept {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ConstitutiveModel::IncompressibleNewtonianFluid> {
  size_t operator()(
      const PhQ::ConstitutiveModel::IncompressibleNewtonianFluid& model) const {
    return hash<PhQ::DynamicViscosity>()(model.DynamicViscosity());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_INCOMPRESSIBLE_NEWTONIAN_FLUID_HPP
