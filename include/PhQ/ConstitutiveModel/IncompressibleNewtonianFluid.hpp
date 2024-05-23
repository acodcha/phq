// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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
#include "../SymmetricDyad.hpp"
#include "../Unit/Frequency.hpp"
#include "../Unit/Pressure.hpp"

namespace PhQ {

/// \brief Constitutive model for an incompressible Newtonian fluid. This is the simplest
/// constitutive model for a fluid. The viscous stress tensor at a point is a linear function of
/// only the local strain rate tensor at that point.
template <typename Number = double>
class ConstitutiveModel::IncompressibleNewtonianFluid : public ConstitutiveModel {
public:
  /// \brief Default constructor. Constructs an incompressible Newtonian fluid constitutive model
  /// with an uninitialized dynamic viscosity.
  IncompressibleNewtonianFluid() : ConstitutiveModel() {}

  /// \brief Constructor. Constructs an incompressible Newtonian fluid constitutive model from a
  /// given dynamic viscosity.
  explicit constexpr IncompressibleNewtonianFluid(const DynamicViscosity<Number>& dynamic_viscosity)
    : ConstitutiveModel(), dynamic_viscosity(dynamic_viscosity) {}

  /// \brief Destructor. Destroys this incompressible Newtonian fluid constitutive model.
  ~IncompressibleNewtonianFluid() noexcept override = default;

  /// \brief Copy constructor. Constructs an incompressible Newtonian fluid constitutive model by
  /// copying another one.
  constexpr IncompressibleNewtonianFluid(const IncompressibleNewtonianFluid& other) = default;

  /// \brief Move constructor. Constructs an incompressible Newtonian fluid constitutive model by
  /// moving another one.
  constexpr IncompressibleNewtonianFluid(IncompressibleNewtonianFluid&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this incompressible Newtonian fluid constitutive
  /// model by copying another one.
  IncompressibleNewtonianFluid& operator=(const IncompressibleNewtonianFluid& other) = default;

  /// \brief Move assignment operator. Assigns this incompressible Newtonian fluid constitutive
  /// model by moving another one.
  IncompressibleNewtonianFluid& operator=(IncompressibleNewtonianFluid&& other) noexcept = default;

  /// \brief Dynamic viscosity of this incompressible Newtonian fluid constitutive model.
  [[nodiscard]] inline constexpr const PhQ::DynamicViscosity<Number>&
  DynamicViscosity() const noexcept {
    return dynamic_viscosity;
  }

  /// \brief Returns this constitutive model's type.
  [[nodiscard]] inline ConstitutiveModel::Type GetType() const noexcept override {
    return ConstitutiveModel::Type::IncompressibleNewtonianFluid;
  }

  /// \brief Returns the stress resulting from a given strain and strain rate. Since this is an
  /// incompressible Newtonian fluid constitutive model, the strain does not contribute to the
  /// stress and is ignored.
  [[nodiscard]] inline PhQ::Stress<float> Stress(
      const PhQ::Strain<float>& /*strain*/,
      const PhQ::StrainRate<float>& strain_rate) const override {
    return this->Stress(strain_rate);
  }

  /// \brief Returns the stress resulting from a given strain and strain rate. Since this is an
  /// incompressible Newtonian fluid constitutive model, the strain does not contribute to the
  /// stress and is ignored.
  [[nodiscard]] inline PhQ::Stress<double> Stress(
      const PhQ::Strain<double>& /*strain*/,
      const PhQ::StrainRate<double>& strain_rate) const override {
    return this->Stress(strain_rate);
  }

  /// \brief Returns the stress resulting from a given strain and strain rate. Since this is an
  /// incompressible Newtonian fluid constitutive model, the strain does not contribute to the
  /// stress and is ignored.
  [[nodiscard]] inline PhQ::Stress<long double> Stress(
      const PhQ::Strain<long double>& /*strain*/,
      const PhQ::StrainRate<long double>& strain_rate) const override {
    return this->Stress(strain_rate);
  }

  /// \brief Returns the stress resulting from a given strain. Since this is an incompressible
  /// Newtonian fluid constitutive model, the strain does not contribute to the stress, so this
  /// always returns a stress of zero.
  [[nodiscard]] inline PhQ::Stress<float> Stress(
      const PhQ::Strain<float>& /*strain*/) const override {
    return PhQ::Stress<float>::Zero();
  }

  /// \brief Returns the stress resulting from a given strain. Since this is an incompressible
  /// Newtonian fluid constitutive model, the strain does not contribute to the stress, so this
  /// always returns a stress of zero.
  [[nodiscard]] inline PhQ::Stress<double> Stress(
      const PhQ::Strain<double>& /*strain*/) const override {
    return PhQ::Stress<double>::Zero();
  }

  /// \brief Returns the stress resulting from a given strain. Since this is an incompressible
  /// Newtonian fluid constitutive model, the strain does not contribute to the stress, so this
  /// always returns a stress of zero.
  [[nodiscard]] inline PhQ::Stress<long double> Stress(
      const PhQ::Strain<long double>& /*strain*/) const override {
    return PhQ::Stress<long double>::Zero();
  }

  /// \brief Returns the stress resulting from a given strain rate.
  [[nodiscard]] inline PhQ::Stress<float> Stress(
      const PhQ::StrainRate<float>& strain_rate) const override {
    // stress = 2 * dynamic_viscosity * strain_rate
    return PhQ::Stress<float>{{static_cast<float>(2) * static_cast<float>(dynamic_viscosity.Value())
                               * static_cast<PhQ::SymmetricDyad<float>>(strain_rate.Value())},
                              Standard<PhQ::Unit::Pressure>};
  }

  /// \brief Returns the stress resulting from a given strain rate.
  [[nodiscard]] inline PhQ::Stress<double> Stress(
      const PhQ::StrainRate<double>& strain_rate) const override {
    // stress = 2 * dynamic_viscosity * strain_rate
    return PhQ::Stress<double>{
        {static_cast<double>(2) * static_cast<double>(dynamic_viscosity.Value())
         * static_cast<PhQ::SymmetricDyad<double>>(strain_rate.Value())},
        Standard<PhQ::Unit::Pressure>};
  }

  /// \brief Returns the stress resulting from a given strain rate.
  [[nodiscard]] inline PhQ::Stress<long double> Stress(
      const PhQ::StrainRate<long double>& strain_rate) const override {
    // stress = 2 * dynamic_viscosity * strain_rate
    return PhQ::Stress<long double>{
        {static_cast<long double>(2) * static_cast<long double>(dynamic_viscosity.Value())
         * static_cast<PhQ::SymmetricDyad<long double>>(strain_rate.Value())},
        Standard<PhQ::Unit::Pressure>};
  }

  /// \brief Returns the strain resulting from a given stress. Since this is an incompressible
  /// Newtonian fluid constitutive model, stress does not depend on strain, so this always returns a
  /// strain of zero.
  [[nodiscard]] inline PhQ::Strain<float> Strain(
      const PhQ::Stress<float>& /*stress*/) const override {
    return PhQ::Strain<float>::Zero();
  }

  /// \brief Returns the strain resulting from a given stress. Since this is an incompressible
  /// Newtonian fluid constitutive model, stress does not depend on strain, so this always returns a
  /// strain of zero.
  [[nodiscard]] inline PhQ::Strain<double> Strain(
      const PhQ::Stress<double>& /*stress*/) const override {
    return PhQ::Strain<double>::Zero();
  }

  /// \brief Returns the strain resulting from a given stress. Since this is an incompressible
  /// Newtonian fluid constitutive model, stress does not depend on strain, so this always returns a
  /// strain of zero.
  [[nodiscard]] inline PhQ::Strain<long double> Strain(
      const PhQ::Stress<long double>& /*stress*/) const override {
    return PhQ::Strain<long double>::Zero();
  }

  /// \brief Returns the strain rate resulting from a given stress.
  [[nodiscard]] inline PhQ::StrainRate<float> StrainRate(
      const PhQ::Stress<float>& stress) const override {
    // strain_rate = stress / (2 * dynamic_viscosity)
    return PhQ::StrainRate<float>{
        {static_cast<PhQ::SymmetricDyad<float>>(stress.Value())
         / (static_cast<float>(2) * static_cast<float>(dynamic_viscosity.Value()))},
        Standard<PhQ::Unit::Frequency>};
  }

  /// \brief Returns the strain rate resulting from a given stress.
  [[nodiscard]] inline PhQ::StrainRate<double> StrainRate(
      const PhQ::Stress<double>& stress) const override {
    // strain_rate = stress / (2 * dynamic_viscosity)
    return PhQ::StrainRate<double>{
        {static_cast<PhQ::SymmetricDyad<double>>(stress.Value())
         / (static_cast<double>(2) * static_cast<double>(dynamic_viscosity.Value()))},
        Standard<PhQ::Unit::Frequency>};
  }

  /// \brief Returns the strain rate resulting from a given stress.
  [[nodiscard]] inline PhQ::StrainRate<long double> StrainRate(
      const PhQ::Stress<long double>& stress) const override {
    // strain_rate = stress / (2 * dynamic_viscosity)
    return PhQ::StrainRate<long double>{
        {static_cast<PhQ::SymmetricDyad<long double>>(stress.Value())
         / (static_cast<long double>(2) * static_cast<long double>(dynamic_viscosity.Value()))},
        Standard<PhQ::Unit::Frequency>};
  }

  /// \brief Prints this incompressible Newtonian fluid constitutive model as a string.
  [[nodiscard]] inline std::string Print() const override {
    return {"Type = " + std::string{Abbreviation(this->GetType())}
            + ", Dynamic Viscosity = " + dynamic_viscosity.Print()};
  }

  /// \brief Serializes this incompressible Newtonian fluid constitutive model as a JSON message.
  [[nodiscard]] inline std::string JSON() const override {
    return {R"({"type":")" + SnakeCaseCopy(Abbreviation(this->GetType()))
            + R"(","dynamic_viscosity":)" + dynamic_viscosity.JSON() + "}"};
  }

  /// \brief Serializes this incompressible Newtonian fluid constitutive model as an XML message.
  [[nodiscard]] inline std::string XML() const override {
    return {"<type>" + SnakeCaseCopy(Abbreviation(this->GetType())) + "</type><dynamic_viscosity>"
            + dynamic_viscosity.XML() + "</dynamic_viscosity>"};
  }

  /// \brief Serializes this incompressible Newtonian fluid constitutive model as a YAML message.
  [[nodiscard]] inline std::string YAML() const override {
    return {"{type:\"" + SnakeCaseCopy(Abbreviation(this->GetType()))
            + "\",dynamic_viscosity:" + dynamic_viscosity.YAML() + "}"};
  }

private:
  /// \brief Dynamic viscosity of this incompressible Newtonian fluid constitutive model.
  PhQ::DynamicViscosity<Number> dynamic_viscosity;
};

template <typename Number>
inline constexpr bool operator==(
    const typename ConstitutiveModel::IncompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel::IncompressibleNewtonianFluid<Number>& right) noexcept {
  return left.DynamicViscosity() == right.DynamicViscosity();
}

template <typename Number>
inline constexpr bool operator!=(
    const typename ConstitutiveModel::IncompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel::IncompressibleNewtonianFluid<Number>& right) noexcept {
  return left.DynamicViscosity() != right.DynamicViscosity();
}

template <typename Number>
inline constexpr bool operator<(
    const typename ConstitutiveModel::IncompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel::IncompressibleNewtonianFluid<Number>& right) noexcept {
  return left.DynamicViscosity() < right.DynamicViscosity();
}

template <typename Number>
inline constexpr bool operator>(
    const typename ConstitutiveModel::IncompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel::IncompressibleNewtonianFluid<Number>& right) noexcept {
  return left.DynamicViscosity() > right.DynamicViscosity();
}

template <typename Number>
inline constexpr bool operator<=(
    const typename ConstitutiveModel::IncompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel::IncompressibleNewtonianFluid<Number>& right) noexcept {
  return left.DynamicViscosity() <= right.DynamicViscosity();
}

template <typename Number>
inline constexpr bool operator>=(
    const typename ConstitutiveModel::IncompressibleNewtonianFluid<Number>& left,
    const typename ConstitutiveModel::IncompressibleNewtonianFluid<Number>& right) noexcept {
  return left.DynamicViscosity() >= right.DynamicViscosity();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream,
    const typename ConstitutiveModel::IncompressibleNewtonianFluid<Number>& model) {
  stream << model.Print();
  return stream;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<typename PhQ::ConstitutiveModel::IncompressibleNewtonianFluid<Number>> {
  size_t operator()(
      const typename PhQ::ConstitutiveModel::IncompressibleNewtonianFluid<Number>& model) const {
    return hash<PhQ::DynamicViscosity<Number>>()(model.DynamicViscosity());
  }
};

}  // namespace std

#endif  // PHQ_CONSTITUTIVE_MODEL_INCOMPRESSIBLE_NEWTONIAN_FLUID_HPP
