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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_COMPRESSIBLE_NEWTONIAN_FLUID_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_COMPRESSIBLE_NEWTONIAN_FLUID_HPP

#include "../BulkDynamicViscosity.hpp"
#include "../ConstitutiveModel.hpp"
#include "../DynamicViscosity.hpp"

namespace PhQ {

// Constitutive model for a compressible Newtonian fluid. This is the simplest
// constitutive model for a compressible fluid. It is similar to the model for
// an incompressible Newtonian fluid, but also includes the effect of the
// volumetric component of the strain rate tensor in addition to its deviatoric
// component.
class ConstitutiveModel::CompressibleNewtonianFluid : public ConstitutiveModel {
public:
  // Default constructor. Constructs a compressible Newtonian fluid constitutive
  // model with an uninitialized dynamic viscosity and bulk dynamic viscosity.
  CompressibleNewtonianFluid() = default;

  // Constructor. Constructs a compressible Newtonian fluid constitutive model
  // from a given dynamic viscosity. Initializes the bulk dynamic viscosity as
  // -2/3 of the dynamic viscosity.
  constexpr CompressibleNewtonianFluid(
      const DynamicViscosity& dynamic_viscosity)
    : ConstitutiveModel(), dynamic_viscosity_(dynamic_viscosity),
      bulk_dynamic_viscosity_(-2.0 / 3.0 * dynamic_viscosity.Value()) {}

  // Constructor. Constructs a compressible Newtonian fluid constitutive model
  // from a given dynamic viscosity and bulk dynamic viscosity.
  constexpr CompressibleNewtonianFluid(
      const DynamicViscosity& dynamic_viscosity,
      const BulkDynamicViscosity& bulk_dynamic_viscosity)
    : ConstitutiveModel(), dynamic_viscosity_(dynamic_viscosity),
      bulk_dynamic_viscosity_(bulk_dynamic_viscosity) {}

  // Destructor. Destroys this compressible Newtonian fluid constitutive model.
  ~CompressibleNewtonianFluid() noexcept = default;

  // Copy constructor. Constructs a compressible Newtonian fluid constitutive
  // model by copying another one.
  constexpr CompressibleNewtonianFluid(
      const CompressibleNewtonianFluid& other) = default;

  // Move constructor. Constructs a compressible Newtonian fluid constitutive
  // model by moving another one.
  constexpr CompressibleNewtonianFluid(
      CompressibleNewtonianFluid&& other) noexcept = default;

  // Copy assignment operator. Assigns this compressible Newtonian fluid
  // constitutive model by copying another one.
  CompressibleNewtonianFluid& operator=(
      const CompressibleNewtonianFluid& other) = default;

  // Move assignment operator. Assigns this compressible Newtonian fluid
  // constitutive model by moving another one.
  CompressibleNewtonianFluid& operator=(
      CompressibleNewtonianFluid&& other) noexcept = default;

  // Dynamic viscosity of this compressible Newtonian fluid constitutive model.
  inline constexpr const PhQ::DynamicViscosity&
  DynamicViscosity() const noexcept {
    return dynamic_viscosity_;
  }

  // Bulk dynamic viscosity of this compressible Newtonian fluid constitutive
  // model.
  inline constexpr const PhQ::BulkDynamicViscosity&
  BulkDynamicViscosity() const noexcept {
    return bulk_dynamic_viscosity_;
  }

  // Returns this constitutive model's type.
  inline Type GetType() const noexcept override {
    return Type::CompressibleNewtonianFluid;
  }

  // Returns the stress resulting from a given strain and strain rate. Since
  // this is a compressible Newtonian fluid constitutive model, the strain does
  // not contribute to the stress and is ignored.
  inline PhQ::Stress Stress(
      const PhQ::Strain&, const PhQ::StrainRate& strain_rate) const override {
    return Stress(strain_rate);
  }

  // Returns the stress resulting from a given strain. Since this is a
  // compressible Newtonian fluid constitutive model, the strain does not
  // contribute to the stress, so this always returns a stress of zero.
  inline PhQ::Stress Stress(const PhQ::Strain&) const override {
    return PhQ::Stress::Zero();
  }

  // Returns the stress resulting from a given strain rate.
  inline PhQ::Stress Stress(const PhQ::StrainRate& strain_rate) const override {
    // stress = a * strain_rate + b * trace(strain_rate) * identity_matrix
    // a = 2 * dynamic_viscosity
    // b = bulk_dynamic_viscosity
    const double a = 2.0 * dynamic_viscosity_.Value();
    const double b =
        bulk_dynamic_viscosity_.Value() * strain_rate.Value().Trace();
    return {
        Value::SymmetricDyad{a * strain_rate.Value()}
            + Value::SymmetricDyad{ b, 0.0, 0.0, b, 0.0, b},
        Standard<Unit::Pressure>
    };
  }

  // Returns the strain resulting from a given stress. Since this is a
  // compressible Newtonian fluid constitutive model, stress does not depend on
  // strain, so this always returns a strain of zero.
  inline PhQ::Strain Strain(const PhQ::Stress&) const override {
    return PhQ::Strain::Zero();
  }

  // Returns the strain rate resulting from a given stress.
  inline PhQ::StrainRate StrainRate(const PhQ::Stress& stress) const override {
    // strain_rate = a * stress + b * trace(stress) * identity_matrix
    // a = 1 / (2 * dynamic_viscosity)
    // b = -1 * bulk_dynamic_viscosity / (2 * dynamic_viscosity * (2 *
    //     dynamic_viscosity + 3 * bulk_dynamic_viscosity))
    const double a = 1.0 / (2.0 * dynamic_viscosity_.Value());
    const double b = -bulk_dynamic_viscosity_.Value()
                     / (2.0 * dynamic_viscosity_.Value()
                        * (2.0 * dynamic_viscosity_.Value()
                           + 3.0 * bulk_dynamic_viscosity_.Value()));
    const double temporary = b * stress.Value().Trace();
    return {
        a * stress.Value()
            + Value::SymmetricDyad{temporary, 0.0, 0.0, temporary, 0.0,
                                   temporary},
        Standard<Unit::Frequency>
    };
  }

  // Prints this compressible Newtonian fluid constitutive model as a string.
  inline std::string Print() const override {
    return {"Type = " + std::string{Abbreviation(GetType())}
            + ", Dynamic Viscosity = " + dynamic_viscosity_.Print()
            + ", Bulk Dynamic Viscosity = " + bulk_dynamic_viscosity_.Print()};
  }

  // Serializes this compressible Newtonian fluid constitutive model as a JSON
  // message.
  inline std::string JSON() const override {
    return {"{\"type\":\"" + SnakeCaseCopy(Abbreviation(GetType()))
            + "\",\"dynamic_viscosity\":" + dynamic_viscosity_.JSON()
            + ",\"bulk_dynamic_viscosity\":" + bulk_dynamic_viscosity_.JSON()
            + "}"};
  }

  // Serializes this compressible Newtonian fluid constitutive model as an XML
  // message.
  inline std::string XML() const override {
    return {"<type>" + SnakeCaseCopy(Abbreviation(GetType()))
            + "</type><dynamic_viscosity>" + dynamic_viscosity_.XML()
            + "</dynamic_viscosity><bulk_dynamic_viscosity>"
            + bulk_dynamic_viscosity_.XML() + "</bulk_dynamic_viscosity>"};
  }

  // Serializes this compressible Newtonian fluid constitutive model as a YAML
  // message.
  inline std::string YAML() const override {
    return {"{type:\"" + SnakeCaseCopy(Abbreviation(GetType()))
            + "\",dynamic_viscosity:" + dynamic_viscosity_.YAML()
            + ",bulk_dynamic_viscosity:" + bulk_dynamic_viscosity_.YAML()
            + "}"};
  }

private:
  // Dynamic viscosity of this compressible Newtonian fluid constitutive model.
  PhQ::DynamicViscosity dynamic_viscosity_;

  // Bulk dynamic viscosity of this compressible Newtonian fluid constitutive
  // model.
  PhQ::BulkDynamicViscosity bulk_dynamic_viscosity_;
};

inline constexpr bool operator==(
    const ConstitutiveModel::CompressibleNewtonianFluid& left,
    const ConstitutiveModel::CompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() == right.DynamicViscosity()
         && left.BulkDynamicViscosity() == right.BulkDynamicViscosity();
}

inline constexpr bool operator!=(
    const ConstitutiveModel::CompressibleNewtonianFluid& left,
    const ConstitutiveModel::CompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() != right.DynamicViscosity()
         || left.BulkDynamicViscosity() != right.BulkDynamicViscosity();
}

inline constexpr bool operator<(
    const ConstitutiveModel::CompressibleNewtonianFluid& left,
    const ConstitutiveModel::CompressibleNewtonianFluid& right) noexcept {
  if (left.DynamicViscosity() != right.DynamicViscosity()) {
    return left.DynamicViscosity() < right.DynamicViscosity();
  }
  return left.BulkDynamicViscosity() < right.BulkDynamicViscosity();
}

inline constexpr bool operator>(
    const ConstitutiveModel::CompressibleNewtonianFluid& left,
    const ConstitutiveModel::CompressibleNewtonianFluid& right) noexcept {
  if (left.DynamicViscosity() != right.DynamicViscosity()) {
    return left.DynamicViscosity() > right.DynamicViscosity();
  }
  return left.BulkDynamicViscosity() > right.BulkDynamicViscosity();
}

inline constexpr bool operator<=(
    const ConstitutiveModel::CompressibleNewtonianFluid& left,
    const ConstitutiveModel::CompressibleNewtonianFluid& right) noexcept {
  return !(left > right);
}

inline constexpr bool operator>=(
    const ConstitutiveModel::CompressibleNewtonianFluid& left,
    const ConstitutiveModel::CompressibleNewtonianFluid& right) noexcept {
  return !(left < right);
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const ConstitutiveModel::CompressibleNewtonianFluid& model) {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ConstitutiveModel::CompressibleNewtonianFluid> {
  size_t operator()(
      const PhQ::ConstitutiveModel::CompressibleNewtonianFluid& model) const {
    size_t result = 17;
    result =
        31 * result + hash<PhQ::DynamicViscosity>()(model.DynamicViscosity());
    result = 31 * result
             + hash<PhQ::BulkDynamicViscosity>()(model.BulkDynamicViscosity());
    return result;
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_COMPRESSIBLE_NEWTONIAN_FLUID_HPP
