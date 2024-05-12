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

#ifndef PHQ_CONSTITUTIVE_MODEL_COMPRESSIBLE_NEWTONIAN_FLUID_HPP
#define PHQ_CONSTITUTIVE_MODEL_COMPRESSIBLE_NEWTONIAN_FLUID_HPP

#include <cstddef>
#include <functional>
#include <ostream>
#include <string>

#include "../Base.hpp"
#include "../BulkDynamicViscosity.hpp"
#include "../ConstitutiveModel.hpp"
#include "../DynamicViscosity.hpp"
#include "../Strain.hpp"
#include "../StrainRate.hpp"
#include "../Stress.hpp"
#include "../SymmetricDyad.hpp"
#include "../Unit/Frequency.hpp"
#include "../Unit/Pressure.hpp"

namespace PhQ {

// Constitutive model for a compressible Newtonian fluid. This is the simplest constitutive model
// for a compressible fluid. It is similar to the model for an incompressible Newtonian fluid, but
// also includes the effect of the volumetric component of the strain rate tensor in addition to its
// deviatoric component.
template <typename Number>
class ConstitutiveModel<Number>::CompressibleNewtonianFluid : public ConstitutiveModel<Number> {
public:
  // Default constructor. Constructs a compressible Newtonian fluid constitutive model with an
  // uninitialized dynamic viscosity and bulk dynamic viscosity.
  CompressibleNewtonianFluid() : ConstitutiveModel<Number>() {}

  // Constructor. Constructs a compressible Newtonian fluid constitutive model from a given dynamic
  // viscosity. Initializes the bulk dynamic viscosity as -2/3 of the dynamic viscosity.
  explicit constexpr CompressibleNewtonianFluid(const DynamicViscosity<Number>& dynamic_viscosity)
    : ConstitutiveModel<Number>(), dynamic_viscosity(dynamic_viscosity),
      bulk_dynamic_viscosity(-2.0 / 3.0 * dynamic_viscosity.Value()) {}

  // Constructor. Constructs a compressible Newtonian fluid constitutive model from a given dynamic
  // viscosity and bulk dynamic viscosity.
  constexpr CompressibleNewtonianFluid(const DynamicViscosity<Number>& dynamic_viscosity,
                                       const BulkDynamicViscosity<Number>& bulk_dynamic_viscosity)
    : ConstitutiveModel<Number>(), dynamic_viscosity(dynamic_viscosity),
      bulk_dynamic_viscosity(bulk_dynamic_viscosity) {}

  // Destructor. Destroys this compressible Newtonian fluid constitutive model.
  ~CompressibleNewtonianFluid() noexcept override = default;

  // Copy constructor. Constructs a compressible Newtonian fluid constitutive model by copying
  // another one.
  constexpr CompressibleNewtonianFluid(const CompressibleNewtonianFluid& other) = default;

  // Move constructor. Constructs a compressible Newtonian fluid constitutive model by moving
  // another one.
  constexpr CompressibleNewtonianFluid(CompressibleNewtonianFluid&& other) noexcept = default;

  // Copy assignment operator. Assigns this compressible Newtonian fluid constitutive model by
  // copying another one.
  CompressibleNewtonianFluid& operator=(const CompressibleNewtonianFluid& other) = default;

  // Move assignment operator. Assigns this compressible Newtonian fluid constitutive model by
  // moving another one.
  CompressibleNewtonianFluid& operator=(CompressibleNewtonianFluid&& other) noexcept = default;

  // Dynamic viscosity of this compressible Newtonian fluid constitutive model.
  [[nodiscard]] inline constexpr const PhQ::DynamicViscosity<Number>&
  DynamicViscosity() const noexcept {
    return dynamic_viscosity;
  }

  // Bulk dynamic viscosity of this compressible Newtonian fluid constitutive model.
  [[nodiscard]] inline constexpr const PhQ::BulkDynamicViscosity<Number>&
  BulkDynamicViscosity() const noexcept {
    return bulk_dynamic_viscosity;
  }

  // Returns this constitutive model's type.
  [[nodiscard]] inline ConstitutiveModelType Type() const noexcept override {
    return ConstitutiveModelType::CompressibleNewtonianFluid;
  }

  // Returns the stress resulting from a given strain and strain rate. Since this is a compressible
  // Newtonian fluid constitutive model, the strain does not contribute to the stress and is
  // ignored.
  [[nodiscard]] inline PhQ::Stress<Number> Stress(
      const PhQ::Strain<Number>& /*strain*/,
      const PhQ::StrainRate<Number>& strain_rate) const override {
    return Stress(strain_rate);
  }

  // Returns the stress resulting from a given strain. Since this is a compressible Newtonian fluid
  // constitutive model, the strain does not contribute to the stress, so this always returns a
  // stress of zero.
  [[nodiscard]] inline PhQ::Stress<Number> Stress(
      const PhQ::Strain<Number>& /*strain*/) const override {
    return PhQ::Stress<Number>::Zero();
  }

  // Returns the stress resulting from a given strain rate.
  [[nodiscard]] inline PhQ::Stress<Number> Stress(
      const PhQ::StrainRate<Number>& strain_rate) const override {
    // stress = a * strain_rate + b * trace(strain_rate) * identity_matrix
    // a = 2 * dynamic_viscosity
    // b = bulk_dynamic_viscosity
    const double a{2.0 * dynamic_viscosity.Value()};
    const double b{bulk_dynamic_viscosity.Value() * strain_rate.Value().Trace()};
    return PhQ::Stress<Number>{
        SymmetricDyad<Number>{a * strain_rate.Value()}
            + SymmetricDyad<Number>{ b, 0.0, 0.0, b, 0.0, b},
        Standard<Unit::Pressure>
    };
  }

  // Returns the strain resulting from a given stress. Since this is a compressible Newtonian fluid
  // constitutive model, stress does not depend on strain, so this always returns a strain of zero.
  [[nodiscard]] inline PhQ::Strain<Number> Strain(
      const PhQ::Stress<Number>& /*stress*/) const override {
    return PhQ::Strain<Number>::Zero();
  }

  // Returns the strain rate resulting from a given stress.
  [[nodiscard]] inline PhQ::StrainRate<Number> StrainRate(
      const PhQ::Stress<Number>& stress) const override {
    // strain_rate = a * stress + b * trace(stress) * identity_matrix
    // a = 1 / (2 * dynamic_viscosity)
    // b = -1 * bulk_dynamic_viscosity /
    //     (2 * dynamic_viscosity * (2 * dynamic_viscosity + 3 * bulk_dynamic_viscosity))
    const double a{1.0 / (2.0 * dynamic_viscosity.Value())};
    const double b{-bulk_dynamic_viscosity.Value()
                   / (2.0 * dynamic_viscosity.Value()
                      * (2.0 * dynamic_viscosity.Value() + 3.0 * bulk_dynamic_viscosity.Value()))};
    const double temporary{b * stress.Value().Trace()};
    return PhQ::StrainRate<Number>{
        a * stress.Value() + SymmetricDyad<Number>{temporary, 0.0, 0.0, temporary, 0.0, temporary},
        Standard<Unit::Frequency>
    };
  }

  // Prints this compressible Newtonian fluid constitutive model as a string.
  [[nodiscard]] inline std::string Print() const override {
    return {"Type = " + std::string{Abbreviation(Type())}
            + ", Dynamic Viscosity = " + dynamic_viscosity.Print()
            + ", Bulk Dynamic Viscosity = " + bulk_dynamic_viscosity.Print()};
  }

  // Serializes this compressible Newtonian fluid constitutive model as a JSON message.
  [[nodiscard]] inline std::string JSON() const override {
    return {R"({"type":")" + SnakeCaseCopy(Abbreviation(Type())) + R"(","dynamic_viscosity":)"
            + dynamic_viscosity.JSON()
            + ",\"bulk_dynamic_viscosity\":" + bulk_dynamic_viscosity.JSON() + "}"};
  }

  // Serializes this compressible Newtonian fluid constitutive model as an XML message.
  [[nodiscard]] inline std::string XML() const override {
    return {"<type>" + SnakeCaseCopy(Abbreviation(Type())) + "</type><dynamic_viscosity>"
            + dynamic_viscosity.XML() + "</dynamic_viscosity><bulk_dynamic_viscosity>"
            + bulk_dynamic_viscosity.XML() + "</bulk_dynamic_viscosity>"};
  }

  // Serializes this compressible Newtonian fluid constitutive model as a YAML message.
  [[nodiscard]] inline std::string YAML() const override {
    return {"{type:\"" + SnakeCaseCopy(Abbreviation(Type()))
            + "\",dynamic_viscosity:" + dynamic_viscosity.YAML()
            + ",bulk_dynamic_viscosity:" + bulk_dynamic_viscosity.YAML() + "}"};
  }

private:
  // Dynamic viscosity of this compressible Newtonian fluid constitutive model.
  PhQ::DynamicViscosity<Number> dynamic_viscosity;

  // Bulk dynamic viscosity of this compressible Newtonian fluid constitutive model.
  PhQ::BulkDynamicViscosity<Number> bulk_dynamic_viscosity;
};

template <typename Number>
inline constexpr bool operator==(
    const typename ConstitutiveModel<Number>::CompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel<Number>::CompressibleNewtonianFluid<Number>& right) noexcept {
  return left.DynamicViscosity() == right.DynamicViscosity()
         && left.BulkDynamicViscosity() == right.BulkDynamicViscosity();
}

template <typename Number>
inline constexpr bool operator!=(
    const typename ConstitutiveModel<Number>::CompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel<Number>::CompressibleNewtonianFluid<Number>& right) noexcept {
  return left.DynamicViscosity() != right.DynamicViscosity()
         || left.BulkDynamicViscosity() != right.BulkDynamicViscosity();
}

template <typename Number>
inline constexpr bool operator<(
    const typename ConstitutiveModel<Number>::CompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel<Number>::CompressibleNewtonianFluid<Number>& right) noexcept {
  if (left.DynamicViscosity() != right.DynamicViscosity()) {
    return left.DynamicViscosity() < right.DynamicViscosity();
  }
  return left.BulkDynamicViscosity() < right.BulkDynamicViscosity();
}

template <typename Number>
inline constexpr bool operator>(
    const typename ConstitutiveModel<Number>::CompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel<Number>::CompressibleNewtonianFluid<Number>& right) noexcept {
  if (left.DynamicViscosity() != right.DynamicViscosity()) {
    return left.DynamicViscosity() > right.DynamicViscosity();
  }
  return left.BulkDynamicViscosity() > right.BulkDynamicViscosity();
}

template <typename Number>
inline constexpr bool operator<=(
    const typename ConstitutiveModel<Number>::CompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel<Number>::CompressibleNewtonianFluid<Number>& right) noexcept {
  return !(left > right);
}

template <typename Number>
inline constexpr bool operator>=(
    const typename ConstitutiveModel<Number>::CompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel<Number>::CompressibleNewtonianFluid<Number>& right) noexcept {
  return !(left < right);
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream,
    const typename ConstitutiveModel<Number>::CompressibleNewtonianFluid<Number>& model) {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<typename PhQ::ConstitutiveModel<Number>::CompressibleNewtonianFluid<Number>> {
  size_t operator()(
      const typename PhQ::ConstitutiveModel<Number>::CompressibleNewtonianFluid<Number>& model)
      const {
    size_t result{17};
    result = 31 * result + hash<PhQ::DynamicViscosity<Number>>()(model.DynamicViscosity());
    result = 31 * result + hash<PhQ::BulkDynamicViscosity<Number>>()(model.BulkDynamicViscosity());
    return result;
  }
};

}  // namespace std

#endif  // PHQ_CONSTITUTIVE_MODEL_COMPRESSIBLE_NEWTONIAN_FLUID_HPP
