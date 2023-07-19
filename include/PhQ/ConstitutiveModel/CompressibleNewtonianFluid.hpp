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
    return Stress(strain_rate);
  }

  inline PhQ::Stress Stress(const PhQ::Strain& strain) const noexcept override {
    return {
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0},
        StandardUnit<Unit::Pressure>
    };
  }

  inline PhQ::Stress Stress(
      const PhQ::StrainRate& strain_rate) const noexcept override {
    // stress = a * strain_rate + b * trace(strain_rate) * identity_matrix
    // a = 2 * dynamic_viscosity
    // b = bulk_dynamic_viscosity
    const double a = 2.0 * dynamic_viscosity_.Value();
    const double b =
        bulk_dynamic_viscosity_.Value() * strain_rate.Value().Trace();
    return {
        Value::SymmetricDyad{a * strain_rate.Value()}
            + Value::SymmetricDyad{b, 0.0, 0.0, b, 0.0, b},
        StandardUnit<Unit::Pressure>
    };
  }

  inline PhQ::Strain Strain(const PhQ::Stress& stress) const noexcept override {
    return PhQ::Strain{
        {0.0, 0.0, 0.0, 0.0, 0.0, 0.0}
    };
  }

  inline PhQ::StrainRate StrainRate(
      const PhQ::Stress& stress) const noexcept override {
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
        StandardUnit<Unit::Frequency>
    };
  }

  inline std::string Print() const noexcept override {
    return {"Type = " + std::string{Abbreviation(GetType())}
            + ", Dynamic Viscosity = " + dynamic_viscosity_.Print()
            + ", Bulk Dynamic Viscosity = " + bulk_dynamic_viscosity_.Print()};
  }

  inline std::string JSON() const noexcept override {
    return {"{\"type\":\"" + SnakeCaseCopy(Abbreviation(GetType()))
            + "\",\"dynamic_viscosity\":" + dynamic_viscosity_.JSON()
            + ",\"bulk_dynamic_viscosity\":" + bulk_dynamic_viscosity_.JSON()
            + "}"};
  }

  inline std::string XML() const noexcept override {
    return {"<type>" + SnakeCaseCopy(Abbreviation(GetType()))
            + "</type><dynamic_viscosity>" + dynamic_viscosity_.XML()
            + "</dynamic_viscosity><bulk_dynamic_viscosity>"
            + bulk_dynamic_viscosity_.XML() + "</bulk_dynamic_viscosity>"};
  }

  inline std::string YAML() const noexcept override {
    return {"{type:\"" + SnakeCaseCopy(Abbreviation(GetType()))
            + "\",dynamic_viscosity:" + dynamic_viscosity_.YAML()
            + ",bulk_dynamic_viscosity:" + bulk_dynamic_viscosity_.YAML()
            + "}"};
  }

private:
  PhQ::DynamicViscosity dynamic_viscosity_;

  PhQ::BulkDynamicViscosity bulk_dynamic_viscosity_;
};

inline constexpr bool operator==(
    const CompressibleNewtonianFluid& left,
    const CompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() == right.DynamicViscosity()
         && left.BulkDynamicViscosity() == right.BulkDynamicViscosity();
}

inline constexpr bool operator!=(
    const CompressibleNewtonianFluid& left,
    const CompressibleNewtonianFluid& right) noexcept {
  return left.DynamicViscosity() != right.DynamicViscosity()
         || left.BulkDynamicViscosity() != right.BulkDynamicViscosity();
}

inline constexpr bool operator<(
    const CompressibleNewtonianFluid& left,
    const CompressibleNewtonianFluid& right) noexcept {
  if (left.DynamicViscosity() != right.DynamicViscosity()) {
    return left.DynamicViscosity() < right.DynamicViscosity();
  }
  return left.BulkDynamicViscosity() < right.BulkDynamicViscosity();
}

inline constexpr bool operator>(
    const CompressibleNewtonianFluid& left,
    const CompressibleNewtonianFluid& right) noexcept {
  if (left.DynamicViscosity() != right.DynamicViscosity()) {
    return left.DynamicViscosity() > right.DynamicViscosity();
  }
  return left.BulkDynamicViscosity() > right.BulkDynamicViscosity();
}

inline constexpr bool operator<=(
    const CompressibleNewtonianFluid& left,
    const CompressibleNewtonianFluid& right) noexcept {
  return !(left > right);
}

inline constexpr bool operator>=(
    const CompressibleNewtonianFluid& left,
    const CompressibleNewtonianFluid& right) noexcept {
  return !(left < right);
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
