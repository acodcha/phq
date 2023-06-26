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
#include "../DynamicViscosity.hpp"
#include "Base.hpp"

namespace PhQ {

class CompressibleNewtonianFluid : public ConstitutiveModel {
public:
  constexpr CompressibleNewtonianFluid() noexcept
    : ConstitutiveModel(), dynamic_viscosity_(), bulk_dynamic_viscosity_() {}

  CompressibleNewtonianFluid(const DynamicViscosity& dynamic_viscosity) noexcept
    : ConstitutiveModel(), dynamic_viscosity_(dynamic_viscosity),
      bulk_dynamic_viscosity_({-2.0 / 3.0 * dynamic_viscosity.Value(),
                               StandardUnit<Unit::DynamicViscosity>}) {}

  constexpr CompressibleNewtonianFluid(
      const DynamicViscosity& dynamic_viscosity,
      const BulkDynamicViscosity& bulk_dynamic_viscosity) noexcept
    : ConstitutiveModel(), dynamic_viscosity_(dynamic_viscosity),
      bulk_dynamic_viscosity_(bulk_dynamic_viscosity) {}

  inline constexpr const PhQ::DynamicViscosity&
  DynamicViscosity() const noexcept {
    return dynamic_viscosity_;
  }

  inline constexpr const PhQ::BulkDynamicViscosity&
  BulkDynamicViscosity() const noexcept {
    return bulk_dynamic_viscosity_;
  }

  inline Type GetType() const noexcept override {
    return Type::CompressibleNewtonianFluid;
  }

  inline PhQ::Stress Stress(
      const PhQ::Strain& strain,
      const PhQ::StrainRate& strain_rate) const noexcept override {
    // stress = a * strain_rate + b * trace(strain_rate) * identity_matrix
    // a = 2 * dynamic_viscosity
    // b = bulk_dynamic_viscosity

    const double temporary1{2.0 * dynamic_viscosity_.Value()};

    const double temporary2{
        bulk_dynamic_viscosity_.Value() * strain_rate.Value().Trace()};

    return {
        Value::SymmetricDyad{temporary1 * strain_rate.Value()}
            + Value::SymmetricDyad{temporary2, 0.0, 0.0, temporary2, 0.0,
                             temporary2},
        StandardUnit<Unit::Pressure>
    };
  }

  inline std::string Print() const noexcept override {
    return {"Type = " + LowerCaseCopy(Abbreviation(GetType()))
            + ", Dynamic Viscosity = " + dynamic_viscosity_.Print()
            + ", Bulk Dynamic Viscosity = " + bulk_dynamic_viscosity_.Print()};
  }

  inline std::string JSON() const noexcept override {
    return {"{\"type\": \"" + LowerCaseCopy(Abbreviation(GetType()))
            + "\", \"dynamic_viscosity\": " + dynamic_viscosity_.JSON()
            + "\", \"bulk_dynamic_viscosity\": "
            + bulk_dynamic_viscosity_.JSON() + "}"};
  }

  inline std::string XML() const noexcept override {
    return {"<type>" + LowerCaseCopy(Abbreviation(GetType()))
            + "</type><dynamic_viscosity>" + dynamic_viscosity_.XML()
            + "</dynamic_viscosity><bulk_dynamic_viscosity>"
            + bulk_dynamic_viscosity_.XML() + "</bulk_dynamic_viscosity>"};
  }

  inline std::string YAML() const noexcept override {
    return {"{type: \"" + LowerCaseCopy(Abbreviation(GetType()))
            + "\", dynamic_viscosity: " + dynamic_viscosity_.JSON()
            + "\", bulk_dynamic_viscosity: " + bulk_dynamic_viscosity_.JSON()
            + "}"};
  }

private:
  PhQ::DynamicViscosity dynamic_viscosity_;

  PhQ::BulkDynamicViscosity bulk_dynamic_viscosity_;
};

inline bool operator==(const CompressibleNewtonianFluid& left,
                       const CompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() == right.DynamicViscosity()
         && left.BulkDynamicViscosity() == right.BulkDynamicViscosity();
}

inline bool operator!=(const CompressibleNewtonianFluid& left,
                       const CompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() != right.DynamicViscosity()
         || left.BulkDynamicViscosity() != right.BulkDynamicViscosity();
}

inline std::ostream& operator<<(
    std::ostream& stream, const CompressibleNewtonianFluid& model) noexcept {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::CompressibleNewtonianFluid> {
  size_t operator()(const PhQ::CompressibleNewtonianFluid& model) const {
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
