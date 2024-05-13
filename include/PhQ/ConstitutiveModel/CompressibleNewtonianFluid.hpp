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
template <typename Number = double>
class ConstitutiveModel::CompressibleNewtonianFluid : public ConstitutiveModel {
public:
  // Default constructor. Constructs a compressible Newtonian fluid constitutive model with an
  // uninitialized dynamic viscosity and bulk dynamic viscosity.
  CompressibleNewtonianFluid() : ConstitutiveModel() {}

  // Constructor. Constructs a compressible Newtonian fluid constitutive model from a given dynamic
  // viscosity. Initializes the bulk dynamic viscosity as -2/3 of the dynamic viscosity.
  explicit constexpr CompressibleNewtonianFluid(const DynamicViscosity<Number>& dynamic_viscosity)
    : ConstitutiveModel(), dynamic_viscosity(dynamic_viscosity),
      bulk_dynamic_viscosity(
          static_cast<Number>(-2) / static_cast<Number>(3) * dynamic_viscosity.Value()) {}

  // Constructor. Constructs a compressible Newtonian fluid constitutive model from a given dynamic
  // viscosity and bulk dynamic viscosity.
  constexpr CompressibleNewtonianFluid(const DynamicViscosity<Number>& dynamic_viscosity,
                                       const BulkDynamicViscosity<Number>& bulk_dynamic_viscosity)
    : ConstitutiveModel(), dynamic_viscosity(dynamic_viscosity),
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
  [[nodiscard]] inline ConstitutiveModel::Type GetType() const noexcept override {
    return ConstitutiveModel::Type::CompressibleNewtonianFluid;
  }

  // Returns the stress resulting from a given strain and strain rate. Since this is a compressible
  // Newtonian fluid constitutive model, the strain does not contribute to the stress and is
  // ignored.
  [[nodiscard]] inline PhQ::Stress<float> Stress(
      const PhQ::Strain<float>& /*strain*/,
      const PhQ::StrainRate<float>& strain_rate) const override {
    return this->Stress(strain_rate);
  }

  // Returns the stress resulting from a given strain and strain rate. Since this is a compressible
  // Newtonian fluid constitutive model, the strain does not contribute to the stress and is
  // ignored.
  [[nodiscard]] inline PhQ::Stress<double> Stress(
      const PhQ::Strain<double>& /*strain*/,
      const PhQ::StrainRate<double>& strain_rate) const override {
    return this->Stress(strain_rate);
  }

  // Returns the stress resulting from a given strain and strain rate. Since this is a compressible
  // Newtonian fluid constitutive model, the strain does not contribute to the stress and is
  // ignored.
  [[nodiscard]] inline PhQ::Stress<long double> Stress(
      const PhQ::Strain<long double>& /*strain*/,
      const PhQ::StrainRate<long double>& strain_rate) const override {
    return this->Stress(strain_rate);
  }

  // Returns the stress resulting from a given strain. Since this is a compressible Newtonian fluid
  // constitutive model, the strain does not contribute to the stress, so this always returns a
  // stress of zero.
  [[nodiscard]] inline PhQ::Stress<float> Stress(
      const PhQ::Strain<float>& /*strain*/) const override {
    return PhQ::Stress<float>::Zero();
  }

  // Returns the stress resulting from a given strain. Since this is a compressible Newtonian fluid
  // constitutive model, the strain does not contribute to the stress, so this always returns a
  // stress of zero.
  [[nodiscard]] inline PhQ::Stress<double> Stress(
      const PhQ::Strain<double>& /*strain*/) const override {
    return PhQ::Stress<double>::Zero();
  }

  // Returns the stress resulting from a given strain. Since this is a compressible Newtonian fluid
  // constitutive model, the strain does not contribute to the stress, so this always returns a
  // stress of zero.
  [[nodiscard]] inline PhQ::Stress<long double> Stress(
      const PhQ::Strain<long double>& /*strain*/) const override {
    return PhQ::Stress<long double>::Zero();
  }

  // Returns the stress resulting from a given strain rate.
  [[nodiscard]] inline PhQ::Stress<float> Stress(
      const PhQ::StrainRate<float>& strain_rate) const override {
    // stress = a * strain_rate + b * trace(strain_rate) * identity_matrix
    // a = 2 * dynamic_viscosity
    // b = bulk_dynamic_viscosity
    const float a{static_cast<float>(2) * static_cast<float>(dynamic_viscosity.Value())};
    const float b{static_cast<float>(bulk_dynamic_viscosity.Value())
                  * static_cast<float>(strain_rate.Value().Trace())};
    return PhQ::Stress<float>{
        SymmetricDyad<float>{a * static_cast<SymmetricDyad<float>>(strain_rate.Value())}
            + SymmetricDyad<float>{ b, static_cast<float>(0), static_cast<float>(0), b,
                             static_cast<float>(0), b},
        Standard<Unit::Pressure>
    };
  }

  // Returns the stress resulting from a given strain rate.
  [[nodiscard]] inline PhQ::Stress<double> Stress(
      const PhQ::StrainRate<double>& strain_rate) const override {
    // stress = a * strain_rate + b * trace(strain_rate) * identity_matrix
    // a = 2 * dynamic_viscosity
    // b = bulk_dynamic_viscosity
    const double a{static_cast<double>(2) * static_cast<double>(dynamic_viscosity.Value())};
    const double b{static_cast<double>(bulk_dynamic_viscosity.Value())
                   * static_cast<double>(strain_rate.Value().Trace())};
    return PhQ::Stress<double>{
        SymmetricDyad<double>{a * static_cast<SymmetricDyad<double>>(strain_rate.Value())}
            + SymmetricDyad<double>{ b, static_cast<double>(0), static_cast<double>(0), b,
                              static_cast<double>(0), b},
        Standard<Unit::Pressure>
    };
  }

  // Returns the stress resulting from a given strain rate.
  [[nodiscard]] inline PhQ::Stress<long double> Stress(
      const PhQ::StrainRate<long double>& strain_rate) const override {
    // stress = a * strain_rate + b * trace(strain_rate) * identity_matrix
    // a = 2 * dynamic_viscosity
    // b = bulk_dynamic_viscosity
    const long double a{
        static_cast<long double>(2) * static_cast<long double>(dynamic_viscosity.Value())};
    const long double b{static_cast<long double>(bulk_dynamic_viscosity.Value())
                        * static_cast<long double>(strain_rate.Value().Trace())};
    return PhQ::Stress<long double>{
        SymmetricDyad<long double>{a * static_cast<SymmetricDyad<long double>>(strain_rate.Value())}
            + SymmetricDyad<long double>{ b, static_cast<long double>(0),
                                   static_cast<long double>(0), b,
                                   static_cast<long double>(0), b},
        Standard<Unit::Pressure>
    };
  }

  // Returns the strain resulting from a given stress. Since this is a compressible Newtonian fluid
  // constitutive model, stress does not depend on strain, so this always returns a strain of zero.
  [[nodiscard]] inline PhQ::Strain<float> Strain(
      const PhQ::Stress<float>& /*stress*/) const override {
    return PhQ::Strain<float>::Zero();
  }

  // Returns the strain resulting from a given stress. Since this is a compressible Newtonian fluid
  // constitutive model, stress does not depend on strain, so this always returns a strain of zero.
  [[nodiscard]] inline PhQ::Strain<double> Strain(
      const PhQ::Stress<double>& /*stress*/) const override {
    return PhQ::Strain<double>::Zero();
  }

  // Returns the strain resulting from a given stress. Since this is a compressible Newtonian fluid
  // constitutive model, stress does not depend on strain, so this always returns a strain of zero.
  [[nodiscard]] inline PhQ::Strain<long double> Strain(
      const PhQ::Stress<long double>& /*stress*/) const override {
    return PhQ::Strain<long double>::Zero();
  }

  // Returns the strain rate resulting from a given stress.
  [[nodiscard]] inline PhQ::StrainRate<float> StrainRate(
      const PhQ::Stress<float>& stress) const override {
    // strain_rate = a * stress + b * trace(stress) * identity_matrix
    // a = 1 / (2 * dynamic_viscosity)
    // b = -1 * bulk_dynamic_viscosity /
    //     (2 * dynamic_viscosity * (2 * dynamic_viscosity + 3 * bulk_dynamic_viscosity))
    const float a{static_cast<float>(1)
                  / (static_cast<float>(2) * static_cast<float>(dynamic_viscosity.Value()))};
    const float b{
        static_cast<float>(-bulk_dynamic_viscosity.Value())
        / (static_cast<float>(2) * static_cast<float>(dynamic_viscosity.Value())
           * (static_cast<float>(2) * static_cast<float>(dynamic_viscosity.Value())
              + static_cast<float>(3) * static_cast<float>(bulk_dynamic_viscosity.Value())))};
    const float c{b * static_cast<float>(stress.Value().Trace())};
    return PhQ::StrainRate<float>{
        a * static_cast<SymmetricDyad<float>>(stress.Value())
            + SymmetricDyad<float>{c, static_cast<float>(0), static_cast<float>(0), c,
                                   static_cast<float>(0), c},
        Standard<Unit::Frequency>
    };
  }

  // Returns the strain rate resulting from a given stress.
  [[nodiscard]] inline PhQ::StrainRate<double> StrainRate(
      const PhQ::Stress<double>& stress) const override {
    // strain_rate = a * stress + b * trace(stress) * identity_matrix
    // a = 1 / (2 * dynamic_viscosity)
    // b = -1 * bulk_dynamic_viscosity /
    //     (2 * dynamic_viscosity * (2 * dynamic_viscosity + 3 * bulk_dynamic_viscosity))
    const double a{static_cast<double>(1)
                   / (static_cast<double>(2) * static_cast<double>(dynamic_viscosity.Value()))};
    const double b{
        static_cast<double>(-bulk_dynamic_viscosity.Value())
        / (static_cast<double>(2) * static_cast<double>(dynamic_viscosity.Value())
           * (static_cast<double>(2) * static_cast<double>(dynamic_viscosity.Value())
              + static_cast<double>(3) * static_cast<double>(bulk_dynamic_viscosity.Value())))};
    const double c{b * static_cast<double>(stress.Value().Trace())};
    return PhQ::StrainRate<double>{
        a * static_cast<SymmetricDyad<double>>(stress.Value())
            + SymmetricDyad<double>{c, static_cast<double>(0), static_cast<double>(0), c,
                                    static_cast<double>(0), c},
        Standard<Unit::Frequency>
    };
  }
  // Returns the strain rate resulting from a given stress.
  [[nodiscard]] inline PhQ::StrainRate<long double> StrainRate(
      const PhQ::Stress<long double>& stress) const override {
    // strain_rate = a * stress + b * trace(stress) * identity_matrix
    // a = 1 / (2 * dynamic_viscosity)
    // b = -1 * bulk_dynamic_viscosity /
    //     (2 * dynamic_viscosity * (2 * dynamic_viscosity + 3 * bulk_dynamic_viscosity))
    const long double a{
        static_cast<long double>(1)
        / (static_cast<long double>(2) * static_cast<long double>(dynamic_viscosity.Value()))};
    const long double b{
        static_cast<long double>(-bulk_dynamic_viscosity.Value())
        / (static_cast<long double>(2) * static_cast<long double>(dynamic_viscosity.Value())
           * (static_cast<long double>(2) * static_cast<long double>(dynamic_viscosity.Value())
              + static_cast<long double>(3)
                    * static_cast<long double>(bulk_dynamic_viscosity.Value())))};
    const long double c{b * static_cast<long double>(stress.Value().Trace())};
    return PhQ::StrainRate<long double>{
        a * static_cast<SymmetricDyad<long double>>(stress.Value())
            + SymmetricDyad<long double>{c, static_cast<long double>(0),
                                         static_cast<long double>(0), c,
                                         static_cast<long double>(0), c},
        Standard<Unit::Frequency>
    };
  }

  // Prints this compressible Newtonian fluid constitutive model as a string.
  [[nodiscard]] inline std::string Print() const override {
    return {"Type = " + std::string{Abbreviation(this->GetType())}
            + ", Dynamic Viscosity = " + dynamic_viscosity.Print()
            + ", Bulk Dynamic Viscosity = " + bulk_dynamic_viscosity.Print()};
  }

  // Serializes this compressible Newtonian fluid constitutive model as a JSON message.
  [[nodiscard]] inline std::string JSON() const override {
    return {R"({"type":")" + SnakeCaseCopy(Abbreviation(this->GetType()))
            + R"(","dynamic_viscosity":)" + dynamic_viscosity.JSON()
            + ",\"bulk_dynamic_viscosity\":" + bulk_dynamic_viscosity.JSON() + "}"};
  }

  // Serializes this compressible Newtonian fluid constitutive model as an XML message.
  [[nodiscard]] inline std::string XML() const override {
    return {"<type>" + SnakeCaseCopy(Abbreviation(this->GetType())) + "</type><dynamic_viscosity>"
            + dynamic_viscosity.XML() + "</dynamic_viscosity><bulk_dynamic_viscosity>"
            + bulk_dynamic_viscosity.XML() + "</bulk_dynamic_viscosity>"};
  }

  // Serializes this compressible Newtonian fluid constitutive model as a YAML message.
  [[nodiscard]] inline std::string YAML() const override {
    return {"{type:\"" + SnakeCaseCopy(Abbreviation(this->GetType()))
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
    const typename ConstitutiveModel::CompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel::CompressibleNewtonianFluid<Number>& right) noexcept {
  return left.DynamicViscosity() == right.DynamicViscosity()
         && left.BulkDynamicViscosity() == right.BulkDynamicViscosity();
}

template <typename Number>
inline constexpr bool operator!=(
    const typename ConstitutiveModel::CompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel::CompressibleNewtonianFluid<Number>& right) noexcept {
  return left.DynamicViscosity() != right.DynamicViscosity()
         || left.BulkDynamicViscosity() != right.BulkDynamicViscosity();
}

template <typename Number>
inline constexpr bool operator<(
    const typename ConstitutiveModel::CompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel::CompressibleNewtonianFluid<Number>& right) noexcept {
  if (left.DynamicViscosity() != right.DynamicViscosity()) {
    return left.DynamicViscosity() < right.DynamicViscosity();
  }
  return left.BulkDynamicViscosity() < right.BulkDynamicViscosity();
}

template <typename Number>
inline constexpr bool operator>(
    const typename ConstitutiveModel::CompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel::CompressibleNewtonianFluid<Number>& right) noexcept {
  if (left.DynamicViscosity() != right.DynamicViscosity()) {
    return left.DynamicViscosity() > right.DynamicViscosity();
  }
  return left.BulkDynamicViscosity() > right.BulkDynamicViscosity();
}

template <typename Number>
inline constexpr bool operator<=(
    const typename ConstitutiveModel::CompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel::CompressibleNewtonianFluid<Number>& right) noexcept {
  return !(left > right);
}

template <typename Number>
inline constexpr bool operator>=(
    const typename ConstitutiveModel::CompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel::CompressibleNewtonianFluid<Number>& right) noexcept {
  return !(left < right);
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream,
    const typename ConstitutiveModel::CompressibleNewtonianFluid<Number>& model) {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<typename PhQ::ConstitutiveModel::CompressibleNewtonianFluid<Number>> {
  size_t operator()(
      const typename PhQ::ConstitutiveModel::CompressibleNewtonianFluid<Number>& model) const {
    size_t result{17};
    result = static_cast<size_t>(31) * result
             + hash<PhQ::DynamicViscosity<Number>>()(model.DynamicViscosity());
    result = static_cast<size_t>(31) * result
             + hash<PhQ::BulkDynamicViscosity<Number>>()(model.BulkDynamicViscosity());
    return result;
  }
};

}  // namespace std

#endif  // PHQ_CONSTITUTIVE_MODEL_COMPRESSIBLE_NEWTONIAN_FLUID_HPP
