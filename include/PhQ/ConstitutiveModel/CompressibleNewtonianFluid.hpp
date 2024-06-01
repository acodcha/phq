// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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

/// \brief Constitutive model for a compressible Newtonian fluid. This is the simplest constitutive
/// model for a compressible fluid. It is similar to the model for an incompressible Newtonian
/// fluid, but also includes the effect of the volumetric component of the strain rate tensor in
/// addition to its deviatoric component.
template <typename NumericType = double>
class ConstitutiveModel::CompressibleNewtonianFluid : public ConstitutiveModel {
public:
  /// \brief Default constructor. Constructs a compressible Newtonian fluid constitutive model with
  /// an uninitialized dynamic viscosity and bulk dynamic viscosity.
  CompressibleNewtonianFluid() : ConstitutiveModel() {}

  /// \brief Constructor. Constructs a compressible Newtonian fluid constitutive model from a given
  /// dynamic viscosity. Initializes the bulk dynamic viscosity to zero.
  explicit constexpr CompressibleNewtonianFluid(
      const DynamicViscosity<NumericType>& dynamic_viscosity)
    : ConstitutiveModel(), dynamic_viscosity(dynamic_viscosity),
      bulk_dynamic_viscosity(PhQ::BulkDynamicViscosity<NumericType>::Zero()) {}

  /// \brief Constructor. Constructs a compressible Newtonian fluid constitutive model from a given
  /// dynamic viscosity and bulk dynamic viscosity.
  constexpr CompressibleNewtonianFluid(
      const DynamicViscosity<NumericType>& dynamic_viscosity,
      const BulkDynamicViscosity<NumericType>& bulk_dynamic_viscosity)
    : ConstitutiveModel(), dynamic_viscosity(dynamic_viscosity),
      bulk_dynamic_viscosity(bulk_dynamic_viscosity) {}

  /// \brief Destructor. Destroys this compressible Newtonian fluid constitutive model.
  ~CompressibleNewtonianFluid() noexcept override = default;

  /// \brief Copy constructor. Constructs a compressible Newtonian fluid constitutive model by
  /// copying another one.
  constexpr CompressibleNewtonianFluid(const CompressibleNewtonianFluid& other) = default;

  /// \brief Move constructor. Constructs a compressible Newtonian fluid constitutive model by
  /// moving another one.
  constexpr CompressibleNewtonianFluid(CompressibleNewtonianFluid&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this compressible Newtonian fluid constitutive model
  /// by copying another one.
  CompressibleNewtonianFluid& operator=(const CompressibleNewtonianFluid& other) = default;

  /// \brief Move assignment operator. Assigns this compressible Newtonian fluid constitutive model
  /// by moving another one.
  CompressibleNewtonianFluid& operator=(CompressibleNewtonianFluid&& other) noexcept = default;

  /// \brief Dynamic viscosity of this compressible Newtonian fluid constitutive model.
  [[nodiscard]] inline constexpr const PhQ::DynamicViscosity<NumericType>&
  DynamicViscosity() const noexcept {
    return dynamic_viscosity;
  }

  /// \brief Bulk dynamic viscosity of this compressible Newtonian fluid constitutive model.
  [[nodiscard]] inline constexpr const PhQ::BulkDynamicViscosity<NumericType>&
  BulkDynamicViscosity() const noexcept {
    return bulk_dynamic_viscosity;
  }

  /// \brief Returns this constitutive model's type.
  [[nodiscard]] inline ConstitutiveModel::Type GetType() const noexcept override {
    return ConstitutiveModel::Type::CompressibleNewtonianFluid;
  }

  /// \brief Returns the stress resulting from a given strain and strain rate. Since this is a
  /// compressible Newtonian fluid constitutive model, the strain does not contribute to the stress
  /// and is ignored.
  [[nodiscard]] inline PhQ::Stress<float> Stress(
      const PhQ::Strain<float>& /*strain*/,
      const PhQ::StrainRate<float>& strain_rate) const override {
    return this->Stress(strain_rate);
  }

  /// \brief Returns the stress resulting from a given strain and strain rate. Since this is a
  /// compressible Newtonian fluid constitutive model, the strain does not contribute to the stress
  /// and is ignored.
  [[nodiscard]] inline PhQ::Stress<double> Stress(
      const PhQ::Strain<double>& /*strain*/,
      const PhQ::StrainRate<double>& strain_rate) const override {
    return this->Stress(strain_rate);
  }

  /// \brief Returns the stress resulting from a given strain and strain rate. Since this is a
  /// compressible Newtonian fluid constitutive model, the strain does not contribute to the stress
  /// and is ignored.
  [[nodiscard]] inline PhQ::Stress<long double> Stress(
      const PhQ::Strain<long double>& /*strain*/,
      const PhQ::StrainRate<long double>& strain_rate) const override {
    return this->Stress(strain_rate);
  }

  /// \brief Returns the stress resulting from a given strain. Since this is a compressible
  /// Newtonian fluid constitutive model, the strain does not contribute to the stress, so this
  /// always returns a stress of zero.
  [[nodiscard]] inline PhQ::Stress<float> Stress(
      const PhQ::Strain<float>& /*strain*/) const override {
    return PhQ::Stress<float>::Zero();
  }

  /// \brief Returns the stress resulting from a given strain. Since this is a compressible
  /// Newtonian fluid constitutive model, the strain does not contribute to the stress, so this
  /// always returns a stress of zero.
  [[nodiscard]] inline PhQ::Stress<double> Stress(
      const PhQ::Strain<double>& /*strain*/) const override {
    return PhQ::Stress<double>::Zero();
  }

  /// \brief Returns the stress resulting from a given strain. Since this is a compressible
  /// Newtonian fluid constitutive model, the strain does not contribute to the stress, so this
  /// always returns a stress of zero.
  [[nodiscard]] inline PhQ::Stress<long double> Stress(
      const PhQ::Strain<long double>& /*strain*/) const override {
    return PhQ::Stress<long double>::Zero();
  }

  /// \brief Returns the stress resulting from a given strain rate.
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

  /// \brief Returns the stress resulting from a given strain rate.
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

  /// \brief Returns the stress resulting from a given strain rate.
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

  /// \brief Returns the strain resulting from a given stress. Since this is a compressible
  /// Newtonian fluid constitutive model, stress does not depend on strain, so this always returns a
  /// strain of zero.
  [[nodiscard]] inline PhQ::Strain<float> Strain(
      const PhQ::Stress<float>& /*stress*/) const override {
    return PhQ::Strain<float>::Zero();
  }

  /// \brief Returns the strain resulting from a given stress. Since this is a compressible
  /// Newtonian fluid constitutive model, stress does not depend on strain, so this always returns a
  /// strain of zero.
  [[nodiscard]] inline PhQ::Strain<double> Strain(
      const PhQ::Stress<double>& /*stress*/) const override {
    return PhQ::Strain<double>::Zero();
  }

  /// \brief Returns the strain resulting from a given stress. Since this is a compressible
  /// Newtonian fluid constitutive model, stress does not depend on strain, so this always returns a
  /// strain of zero.
  [[nodiscard]] inline PhQ::Strain<long double> Strain(
      const PhQ::Stress<long double>& /*stress*/) const override {
    return PhQ::Strain<long double>::Zero();
  }

  /// \brief Returns the strain rate resulting from a given stress.
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

  /// \brief Returns the strain rate resulting from a given stress.
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

  /// \brief Returns the strain rate resulting from a given stress.
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

  /// \brief Prints this compressible Newtonian fluid constitutive model as a string.
  [[nodiscard]] inline std::string Print() const override {
    return {"Type = " + std::string{Abbreviation(this->GetType())}
            + ", Dynamic Viscosity = " + dynamic_viscosity.Print()
            + ", Bulk Dynamic Viscosity = " + bulk_dynamic_viscosity.Print()};
  }

  /// \brief Serializes this compressible Newtonian fluid constitutive model as a JSON message.
  [[nodiscard]] inline std::string JSON() const override {
    return {R"({"type":")" + SnakeCase(Abbreviation(this->GetType())) + R"(","dynamic_viscosity":)"
            + dynamic_viscosity.JSON()
            + ",\"bulk_dynamic_viscosity\":" + bulk_dynamic_viscosity.JSON() + "}"};
  }

  /// \brief Serializes this compressible Newtonian fluid constitutive model as an XML message.
  [[nodiscard]] inline std::string XML() const override {
    return {"<type>" + SnakeCase(Abbreviation(this->GetType())) + "</type><dynamic_viscosity>"
            + dynamic_viscosity.XML() + "</dynamic_viscosity><bulk_dynamic_viscosity>"
            + bulk_dynamic_viscosity.XML() + "</bulk_dynamic_viscosity>"};
  }

  /// \brief Serializes this compressible Newtonian fluid constitutive model as a YAML message.
  [[nodiscard]] inline std::string YAML() const override {
    return {"{type:\"" + SnakeCase(Abbreviation(this->GetType()))
            + "\",dynamic_viscosity:" + dynamic_viscosity.YAML()
            + ",bulk_dynamic_viscosity:" + bulk_dynamic_viscosity.YAML() + "}"};
  }

private:
  /// \brief Dynamic viscosity of this compressible Newtonian fluid constitutive model.
  PhQ::DynamicViscosity<NumericType> dynamic_viscosity;

  /// \brief Bulk dynamic viscosity of this compressible Newtonian fluid constitutive model.
  PhQ::BulkDynamicViscosity<NumericType> bulk_dynamic_viscosity;
};

template <typename NumericType>
inline constexpr bool operator==(
    const typename ConstitutiveModel::CompressibleNewtonianFluid<NumericType>& left,
    const typename ConstitutiveModel::CompressibleNewtonianFluid<NumericType>& right) noexcept {
  return left.DynamicViscosity() == right.DynamicViscosity()
         && left.BulkDynamicViscosity() == right.BulkDynamicViscosity();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const typename ConstitutiveModel::CompressibleNewtonianFluid<NumericType>& left,
    const typename ConstitutiveModel::CompressibleNewtonianFluid<NumericType>& right) noexcept {
  return left.DynamicViscosity() != right.DynamicViscosity()
         || left.BulkDynamicViscosity() != right.BulkDynamicViscosity();
}

template <typename NumericType>
inline constexpr bool operator<(
    const typename ConstitutiveModel::CompressibleNewtonianFluid<NumericType>& left,
    const typename ConstitutiveModel::CompressibleNewtonianFluid<NumericType>& right) noexcept {
  if (left.DynamicViscosity() != right.DynamicViscosity()) {
    return left.DynamicViscosity() < right.DynamicViscosity();
  }
  return left.BulkDynamicViscosity() < right.BulkDynamicViscosity();
}

template <typename NumericType>
inline constexpr bool operator>(
    const typename ConstitutiveModel::CompressibleNewtonianFluid<NumericType>& left,
    const typename ConstitutiveModel::CompressibleNewtonianFluid<NumericType>& right) noexcept {
  if (left.DynamicViscosity() != right.DynamicViscosity()) {
    return left.DynamicViscosity() > right.DynamicViscosity();
  }
  return left.BulkDynamicViscosity() > right.BulkDynamicViscosity();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const typename ConstitutiveModel::CompressibleNewtonianFluid<NumericType>& left,
    const typename ConstitutiveModel::CompressibleNewtonianFluid<NumericType>& right) noexcept {
  return !(left > right);
}

template <typename NumericType>
inline constexpr bool operator>=(
    const typename ConstitutiveModel::CompressibleNewtonianFluid<NumericType>& left,
    const typename ConstitutiveModel::CompressibleNewtonianFluid<NumericType>& right) noexcept {
  return !(left < right);
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream,
    const typename ConstitutiveModel::CompressibleNewtonianFluid<NumericType>& model) {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<typename PhQ::ConstitutiveModel::CompressibleNewtonianFluid<NumericType>> {
  size_t operator()(
      const typename PhQ::ConstitutiveModel::CompressibleNewtonianFluid<NumericType>& model) const {
    size_t result{17};
    result = static_cast<size_t>(31) * result
             + hash<PhQ::DynamicViscosity<NumericType>>()(model.DynamicViscosity());
    result = static_cast<size_t>(31) * result
             + hash<PhQ::BulkDynamicViscosity<NumericType>>()(model.BulkDynamicViscosity());
    return result;
  }
};

}  // namespace std

#endif  // PHQ_CONSTITUTIVE_MODEL_COMPRESSIBLE_NEWTONIAN_FLUID_HPP
