// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHQ_CONSTITUTIVE_MODEL_INCOMPRESSIBLE_NEWTONIAN_FLUID_HPP
#define PHQ_CONSTITUTIVE_MODEL_INCOMPRESSIBLE_NEWTONIAN_FLUID_HPP

#include <cstddef>
#include <functional>
#include <ostream>
#include <string>

#include "../Base.hpp"
#include "../ConstitutiveModel.hpp"
#include "../DynamicViscosity.hpp"
#include "../Strain.hpp"
#include "../StrainRate.hpp"
#include "../Stress.hpp"
#include "../Unit/Frequency.hpp"
#include "../Unit/Pressure.hpp"

namespace PhQ {

// Constitutive model for an incompressible Newtonian fluid. This is the simplest constitutive model
// for a fluid. The viscous stress tensor at a point is a linear function of only the local strain
// rate tensor at that point.
template <typename Number>
class ConstitutiveModel<Number>::IncompressibleNewtonianFluid : public ConstitutiveModel<Number> {
public:
  // Default constructor. Constructs an incompressible Newtonian fluid constitutive model with an
  // uninitialized dynamic viscosity.
  IncompressibleNewtonianFluid() = default;

  // Constructor. Constructs an incompressible Newtonian fluid constitutive model from a given
  // dynamic viscosity.
  explicit constexpr IncompressibleNewtonianFluid(const DynamicViscosity<Number>& dynamic_viscosity)
    : ConstitutiveModel<Number>(), dynamic_viscosity(dynamic_viscosity) {}

  // Destructor. Destroys this incompressible Newtonian fluid constitutive model.
  ~IncompressibleNewtonianFluid() noexcept override = default;

  // Copy constructor. Constructs an incompressible Newtonian fluid constitutive model by copying
  // another one.
  constexpr IncompressibleNewtonianFluid(const IncompressibleNewtonianFluid& other) = default;

  // Move constructor. Constructs an incompressible Newtonian fluid constitutive model by moving
  // another one.
  constexpr IncompressibleNewtonianFluid(IncompressibleNewtonianFluid&& other) noexcept = default;

  // Copy assignment operator. Assigns this incompressible Newtonian fluid constitutive model by
  // copying another one.
  IncompressibleNewtonianFluid& operator=(const IncompressibleNewtonianFluid& other) = default;

  // Move assignment operator. Assigns this incompressible Newtonian fluid constitutive model by
  // moving another one.
  IncompressibleNewtonianFluid& operator=(IncompressibleNewtonianFluid&& other) noexcept = default;

  // Dynamic viscosity of this incompressible Newtonian fluid constitutive model.
  [[nodiscard]] inline constexpr const PhQ::DynamicViscosity<Number>&
  DynamicViscosity() const noexcept {
    return dynamic_viscosity;
  }

  // Returns this constitutive model's type.
  [[nodiscard]] inline Type GetType() const noexcept override {
    return Type::IncompressibleNewtonianFluid;
  }

  // Returns the stress resulting from a given strain and strain rate. Since this is an
  // incompressible Newtonian fluid constitutive model, the strain does not contribute to the stress
  // and is ignored.
  [[nodiscard]] inline PhQ::Stress<Number> Stress(
      const PhQ::Strain<Number>& /*strain*/,
      const PhQ::StrainRate<Number>& strain_rate) const override {
    return Stress<Number>(strain_rate);
  }

  // Returns the stress resulting from a given strain. Since this is an incompressible Newtonian
  // fluid constitutive model, the strain does not contribute to the stress, so this always returns
  // a stress of zero.
  [[nodiscard]] inline PhQ::Stress<Number> Stress(
      const PhQ::Strain<Number>& /*strain*/) const override {
    return PhQ::Stress<Number>::Zero();
  }

  // Returns the stress resulting from a given strain rate.
  [[nodiscard]] inline PhQ::Stress<Number> Stress(
      const PhQ::StrainRate<Number>& strain_rate) const override {
    // stress = 2 * dynamic_viscosity * strain_rate
    return PhQ::Stress<Number>{
        {2.0 * dynamic_viscosity.Value() * strain_rate.Value()}, Standard<Unit::Pressure>};
  }

  // Returns the strain resulting from a given stress. Since this is an incompressible Newtonian
  // fluid constitutive model, stress does not depend on strain, so this always returns a strain of
  // zero.
  [[nodiscard]] inline PhQ::Strain<Number> Strain(
      const PhQ::Stress<Number>& /*stress*/) const override {
    return PhQ::Strain<Number>::Zero();
  }

  // Returns the strain rate resulting from a given stress.
  [[nodiscard]] inline PhQ::StrainRate<Number> StrainRate(
      const PhQ::Stress<Number>& stress) const override {
    // strain_rate = stress / (2 * dynamic_viscosity)
    return PhQ::StrainRate<Number>{
        {stress.Value() / (2.0 * dynamic_viscosity.Value())}, Standard<Unit::Frequency>};
  }
  // Prints this incompressible Newtonian fluid constitutive model as a string.
  [[nodiscard]] inline std::string Print() const override {
    return {"Type = " + std::string{Abbreviation(GetType())}
            + ", Dynamic Viscosity = " + dynamic_viscosity.Print()};
  }

  // Serializes this incompressible Newtonian fluid constitutive model as a JSON message.
  [[nodiscard]] inline std::string JSON() const override {
    return {R"({"type":")" + SnakeCaseCopy(Abbreviation(GetType())) + R"(","dynamic_viscosity":)"
            + dynamic_viscosity.JSON() + "}"};
  }

  // Serializes this incompressible Newtonian fluid constitutive model as an XML message.
  [[nodiscard]] inline std::string XML() const override {
    return {"<type>" + SnakeCaseCopy(Abbreviation(GetType())) + "</type><dynamic_viscosity>"
            + dynamic_viscosity.XML() + "</dynamic_viscosity>"};
  }

  // Serializes this incompressible Newtonian fluid constitutive model as a YAML message.
  [[nodiscard]] inline std::string YAML() const override {
    return {"{type:\"" + SnakeCaseCopy(Abbreviation(GetType()))
            + "\",dynamic_viscosity:" + dynamic_viscosity.YAML() + "}"};
  }

private:
  // Dynamic viscosity of this incompressible Newtonian fluid constitutive model.
  PhQ::DynamicViscosity<Number> dynamic_viscosity;
};

template <typename Number>
inline constexpr bool operator==(
    const typename ConstitutiveModel<Number>::IncompressibleNewtonianFluid& left,
    const typename ConstitutiveModel<Number>::IncompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() == right.DynamicViscosity();
}

template <typename Number>
inline constexpr bool operator!=(
    const typename ConstitutiveModel<Number>::IncompressibleNewtonianFluid& left,
    const typename ConstitutiveModel<Number>::IncompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() != right.DynamicViscosity();
}

template <typename Number>
inline constexpr bool operator<(
    const typename ConstitutiveModel<Number>::IncompressibleNewtonianFluid& left,
    const typename ConstitutiveModel<Number>::IncompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() < right.DynamicViscosity();
}

template <typename Number>
inline constexpr bool operator>(
    const typename ConstitutiveModel<Number>::IncompressibleNewtonianFluid& left,
    const typename ConstitutiveModel<Number>::IncompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() > right.DynamicViscosity();
}

template <typename Number>
inline constexpr bool operator<=(
    const typename ConstitutiveModel<Number>::IncompressibleNewtonianFluid& left,
    const typename ConstitutiveModel<Number>::IncompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() <= right.DynamicViscosity();
}

template <typename Number>
inline constexpr bool operator>=(
    const typename ConstitutiveModel<Number>::IncompressibleNewtonianFluid& left,
    const typename ConstitutiveModel<Number>::IncompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() >= right.DynamicViscosity();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream,
    const typename ConstitutiveModel<Number>::IncompressibleNewtonianFluid& model) {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<typename PhQ::ConstitutiveModel<Number>::IncompressibleNewtonianFluid> {
  size_t operator()(
      const PhQ::ConstitutiveModel<Number>::IncompressibleNewtonianFluid& model) const {
    return hash<PhQ::DynamicViscosity<Number>>()(model.DynamicViscosity());
  }
};

}  // namespace std

#endif  // PHQ_CONSTITUTIVE_MODEL_INCOMPRESSIBLE_NEWTONIAN_FLUID_HPP
