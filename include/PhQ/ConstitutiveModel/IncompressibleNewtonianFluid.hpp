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
  // Default constructor. Constructs an incompressible Newtonian fluid
  // constitutive model with an uninitialized dynamic viscosity.
  IncompressibleNewtonianFluid() = default;

  // Constructor. Constructs an incompressible Newtonian fluid constitutive
  // model from a given dynamic viscosity.
  constexpr IncompressibleNewtonianFluid(
      const DynamicViscosity& dynamic_viscosity)
    : ConstitutiveModel(), dynamic_viscosity_(dynamic_viscosity) {}

  // Destructor. Destroys this incompressible Newtonian fluid constitutive
  // model.
  ~IncompressibleNewtonianFluid() noexcept = default;

  // Copy constructor. Constructs an incompressible Newtonian fluid constitutive
  // model by copying another one.
  constexpr IncompressibleNewtonianFluid(
      const IncompressibleNewtonianFluid& other) = default;

  // Move constructor. Constructs an incompressible Newtonian fluid constitutive
  // model by moving another one.
  constexpr IncompressibleNewtonianFluid(
      IncompressibleNewtonianFluid&& other) noexcept = default;

  // Copy assignment operator. Assigns this incompressible Newtonian fluid
  // constitutive model by copying another one.
  IncompressibleNewtonianFluid& operator=(
      const IncompressibleNewtonianFluid& other) = default;

  // Move assignment operator. Assigns this incompressible Newtonian fluid
  // constitutive model by moving another one.
  IncompressibleNewtonianFluid& operator=(
      IncompressibleNewtonianFluid&& other) noexcept = default;

  // Dynamic viscosity of this incompressible Newtonian fluid constitutive
  // model.
  inline constexpr const PhQ::DynamicViscosity&
  DynamicViscosity() const noexcept {
    return dynamic_viscosity_;
  }

  // Returns this constitutive model's type.
  inline Type GetType() const noexcept override {
    return Type::IncompressibleNewtonianFluid;
  }

  // Returns the stress resulting from a given strain and strain rate. Since
  // this is an incompressible Newtonian fluid constitutive model, the strain
  // does not contribute to the stress and is ignored.
  inline PhQ::Stress Stress(
      const PhQ::Strain&, const PhQ::StrainRate& strain_rate) const override {
    return Stress(strain_rate);
  }

  // Returns the stress resulting from a given strain. Since this is an
  // incompressible Newtonian fluid constitutive model, the strain does not
  // contribute to the stress, so this always returns a stress of zero.
  inline PhQ::Stress Stress(const PhQ::Strain&) const override {
    return PhQ::Stress::Zero();
  }

  // Returns the stress resulting from a given strain rate.
  inline PhQ::Stress Stress(const PhQ::StrainRate& strain_rate) const override {
    // stress = 2 * dynamic_viscosity * strain_rate
    return {{2.0 * dynamic_viscosity_.Value() * strain_rate.Value()},
            Standard<Unit::Pressure>};
  }

  // Returns the strain resulting from a given stress. Since this is an
  // incompressible Newtonian fluid constitutive model, stress does not depend
  // on strain, so this always returns a strain of zero.
  inline PhQ::Strain Strain(const PhQ::Stress&) const override {
    return PhQ::Strain::Zero();
  }

  // Returns the strain rate resulting from a given stress.
  inline PhQ::StrainRate StrainRate(const PhQ::Stress& stress) const override {
    // strain_rate = stress / (2 * dynamic_viscosity)
    return {{stress.Value() / (2.0 * dynamic_viscosity_.Value())},
            Standard<Unit::Frequency>};
  }
  // Prints this incompressible Newtonian fluid constitutive model as a string.
  inline std::string Print() const override {
    return {"Type = " + std::string{Abbreviation(GetType())}
            + ", Dynamic Viscosity = " + dynamic_viscosity_.Print()};
  }

  // Serializes this incompressible Newtonian fluid constitutive model as a JSON
  // message.
  inline std::string JSON() const override {
    return {"{\"type\":\"" + SnakeCaseCopy(Abbreviation(GetType()))
            + "\",\"dynamic_viscosity\":" + dynamic_viscosity_.JSON() + "}"};
  }

  // Serializes this incompressible Newtonian fluid constitutive model as an XML
  // message.
  inline std::string XML() const override {
    return {"<type>" + SnakeCaseCopy(Abbreviation(GetType()))
            + "</type><dynamic_viscosity>" + dynamic_viscosity_.XML()
            + "</dynamic_viscosity>"};
  }

  // Serializes this incompressible Newtonian fluid constitutive model as a YAML
  // message.
  inline std::string YAML() const override {
    return {"{type:\"" + SnakeCaseCopy(Abbreviation(GetType()))
            + "\",dynamic_viscosity:" + dynamic_viscosity_.YAML() + "}"};
  }

private:
  // Dynamic viscosity of this incompressible Newtonian fluid constitutive
  // model.
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
    const ConstitutiveModel::IncompressibleNewtonianFluid& model) {
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
