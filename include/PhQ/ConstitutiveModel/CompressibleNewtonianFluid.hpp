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
#include "../StrainRate.hpp"
#include "../Stress.hpp"
#include "Base.hpp"

namespace PhQ::ConstitutiveModel {

class CompressibleNewtonianFluid
    : public GenericConstitutiveModel<Type::CompressibleNewtonianFluid> {
public:
  constexpr CompressibleNewtonianFluid() noexcept
      : GenericConstitutiveModel<Type::CompressibleNewtonianFluid>(),
        dynamic_viscosity_(),
        bulk_dynamic_viscosity_() {}

  CompressibleNewtonianFluid(const DynamicViscosity& dynamic_viscosity) noexcept
      : GenericConstitutiveModel<Type::CompressibleNewtonianFluid>(),
        dynamic_viscosity_(dynamic_viscosity),
        bulk_dynamic_viscosity_({-2.0 / 3.0 * dynamic_viscosity.Value(),
                                 StandardUnit<Unit::DynamicViscosity>}) {}

  constexpr CompressibleNewtonianFluid(
      const DynamicViscosity& dynamic_viscosity,
      const BulkDynamicViscosity& bulk_dynamic_viscosity) noexcept
      : GenericConstitutiveModel<Type::CompressibleNewtonianFluid>(),
        dynamic_viscosity_(dynamic_viscosity),
        bulk_dynamic_viscosity_(bulk_dynamic_viscosity) {}

  inline constexpr const PhQ::DynamicViscosity& DynamicViscosity()
      const noexcept {
    return dynamic_viscosity_;
  }

  inline constexpr const PhQ::BulkDynamicViscosity& BulkDynamicViscosity()
      const noexcept {
    return bulk_dynamic_viscosity_;
  }

  inline PhQ::Stress Stress(const PhQ::StrainRate& strain_rate) const noexcept {
    // stress = a * strain_rate + b * trace(strain_rate) * identity_matrix
    // a = 2 * dynamic_viscosity
    // b = bulk_dynamic_viscosity
    const double temporary_1{2.0 * dynamic_viscosity_.Value()};
    const double temporary_2{bulk_dynamic_viscosity_.Value() *
                             strain_rate.Value().Trace()};
    return {Value::SymmetricDyad{temporary_1 * strain_rate.Value()} +
                Value::SymmetricDyad{temporary_2, 0.0, 0.0, temporary_2, 0.0,
                                     temporary_2},
            StandardUnit<Unit::Pressure>};
  }

  inline std::string Print() const noexcept override {
    return {"Dynamic Viscosity = " + dynamic_viscosity_.Print() +
            ", Bulk Dynamic Viscosity = " + bulk_dynamic_viscosity_.Print()};
  }

  inline std::string Json() const noexcept override {
    return {"{\"type\": \"" + LowerCaseCopy(Abbreviation(Type())) +
            "\", \"dynamic_viscosity\": " + dynamic_viscosity_.Json() +
            "\", \"bulk_dynamic_viscosity\": " +
            bulk_dynamic_viscosity_.Json() + "}"};
  }

  inline std::string Xml() const noexcept override {
    return {"<type>" + LowerCaseCopy(Abbreviation(Type())) +
            "</type><dynamic_viscosity>" + dynamic_viscosity_.Xml() +
            "</dynamic_viscosity><bulk_dynamic_viscosity>" +
            bulk_dynamic_viscosity_.Xml() + "</bulk_dynamic_viscosity>"};
  }

  inline std::string Yaml() const noexcept override {
    return {"{type: \"" + LowerCaseCopy(Abbreviation(Type())) +
            "\", dynamic_viscosity: " + dynamic_viscosity_.Json() +
            "\", bulk_dynamic_viscosity: " + bulk_dynamic_viscosity_.Json() +
            "}"};
  }

private:
  PhQ::DynamicViscosity dynamic_viscosity_;

  PhQ::BulkDynamicViscosity bulk_dynamic_viscosity_;
};

inline bool operator==(const CompressibleNewtonianFluid& left,
                       const CompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() == right.DynamicViscosity() &&
         left.BulkDynamicViscosity() == right.BulkDynamicViscosity();
}

inline bool operator!=(const CompressibleNewtonianFluid& left,
                       const CompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() != right.DynamicViscosity() ||
         left.BulkDynamicViscosity() != right.BulkDynamicViscosity();
}

inline std::ostream& operator<<(
    std::ostream& stream, const CompressibleNewtonianFluid& model) noexcept {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ::ConstitutiveModel

namespace std {

template <>
struct hash<PhQ::ConstitutiveModel::CompressibleNewtonianFluid> {
  size_t operator()(
      const PhQ::ConstitutiveModel::CompressibleNewtonianFluid& model) const {
    size_t result = 17;
    result =
        31 * result + hash<PhQ::DynamicViscosity>()(model.DynamicViscosity());
    result = 31 * result +
             hash<PhQ::BulkDynamicViscosity>()(model.BulkDynamicViscosity());
    return result;
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_CONSTITUTIVE_MODEL_COMPRESSIBLE_NEWTONIAN_FLUID_HPP
