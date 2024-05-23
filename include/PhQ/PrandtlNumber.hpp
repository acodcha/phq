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

#ifndef PHQ_PRANDTL_NUMBER_HPP
#define PHQ_PRANDTL_NUMBER_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"
#include "DynamicViscosity.hpp"
#include "KinematicViscosity.hpp"
#include "ScalarThermalConductivity.hpp"
#include "SpecificIsobaricHeatCapacity.hpp"
#include "ThermalDiffusivity.hpp"

namespace PhQ {

/// \brief Prandtl number of a fluid.
template <typename Number = double>
class PrandtlNumber : public DimensionlessScalar<Number> {
public:
  /// \brief Default constructor. Constructs a Prandtl number with an uninitialized value.
  PrandtlNumber() = default;

  /// \brief Constructor. Constructs a Prandtl number with a given value.
  explicit constexpr PrandtlNumber(const Number value) : DimensionlessScalar<Number>(value) {}

  /// \brief Constructor. Constructs a Prandtl number from a given kinematic viscosity and thermal
  /// diffusivity using the definition of the Prandtl number.
  constexpr PrandtlNumber(const KinematicViscosity<Number>& kinematic_viscosity,
                          const ThermalDiffusivity<Number>& thermal_diffusivity)
    : PrandtlNumber<Number>(kinematic_viscosity.Value() / thermal_diffusivity.Value()) {}

  /// \brief Constructor. Constructs a Prandtl number from a given specific isobaric heat capacity,
  /// dynamic viscosity, and scalar thermal conductivity using the definition of the Prandtl number.
  constexpr PrandtlNumber(
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
      const DynamicViscosity<Number>& dynamic_viscosity,
      const ScalarThermalConductivity<Number>& scalar_thermal_conductivity)
    : PrandtlNumber<Number>(specific_isobaric_heat_capacity.Value() * dynamic_viscosity.Value()
                            / scalar_thermal_conductivity.Value()) {}

  /// \brief Destructor. Destroys this Prandtl number.
  ~PrandtlNumber() noexcept = default;

  /// \brief Copy constructor. Constructs a Prandtl number by copying another one.
  constexpr PrandtlNumber(const PrandtlNumber<Number>& other) = default;

  /// \brief Copy constructor. Constructs a Prandtl number by copying another one.
  template <typename OtherNumber>
  explicit constexpr PrandtlNumber(const PrandtlNumber<OtherNumber>& other)
    : PrandtlNumber(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a Prandtl number by moving another one.
  constexpr PrandtlNumber(PrandtlNumber<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this Prandtl number by copying another one.
  constexpr PrandtlNumber<Number>& operator=(const PrandtlNumber<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this Prandtl number by copying another one.
  template <typename OtherNumber>
  constexpr PrandtlNumber<Number>& operator=(const PrandtlNumber<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this Prandtl number by moving another one.
  constexpr PrandtlNumber<Number>& operator=(PrandtlNumber<Number>&& other) noexcept = default;

  /// \brief Statically creates a Prandtl number of zero.
  static constexpr PrandtlNumber<Number> Zero() {
    return PrandtlNumber<Number>{static_cast<Number>(0)};
  }

  [[nodiscard]] constexpr PhQ::DynamicViscosity<Number> DynamicViscosity(
      const PhQ::ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
      const PhQ::SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity) const {
    return PhQ::DynamicViscosity<Number>{
        *this, scalar_thermal_conductivity, specific_isobaric_heat_capacity};
  }

  [[nodiscard]] constexpr PhQ::KinematicViscosity<Number> KinematicViscosity(
      const PhQ::ThermalDiffusivity<Number>& thermal_diffusivity) const {
    return PhQ::KinematicViscosity<Number>{*this, thermal_diffusivity};
  }

  [[nodiscard]] constexpr PhQ::SpecificIsobaricHeatCapacity<Number> SpecificIsobaricHeatCapacity(
      const PhQ::ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
      const PhQ::DynamicViscosity<Number>& dynamic_viscosity) const {
    return PhQ::SpecificIsobaricHeatCapacity<Number>{
        *this, scalar_thermal_conductivity, dynamic_viscosity};
  }

  [[nodiscard]] constexpr PhQ::ScalarThermalConductivity<Number> ScalarThermalConductivity(
      const PhQ::SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
      const PhQ::DynamicViscosity<Number>& dynamic_viscosity) const {
    return PhQ::ScalarThermalConductivity<Number>{
        specific_isobaric_heat_capacity, dynamic_viscosity, *this};
  }

  [[nodiscard]] constexpr PhQ::ThermalDiffusivity<Number> ThermalDiffusivity(
      const PhQ::KinematicViscosity<Number>& kinematic_viscosity) const {
    return PhQ::ThermalDiffusivity<Number>{kinematic_viscosity, *this};
  }

  constexpr PrandtlNumber<Number> operator+(const PrandtlNumber<Number>& prandtl_number) const {
    return PrandtlNumber<Number>{this->value + prandtl_number.value};
  }

  constexpr PrandtlNumber<Number> operator-(const PrandtlNumber<Number>& prandtl_number) const {
    return PrandtlNumber<Number>{this->value - prandtl_number.value};
  }

  constexpr PrandtlNumber<Number> operator*(const Number number) const {
    return PrandtlNumber<Number>{this->value * number};
  }

  constexpr PrandtlNumber<Number> operator/(const Number number) const {
    return PrandtlNumber<Number>{this->value / number};
  }

  constexpr Number operator/(const PrandtlNumber<Number>& prandtl_number) const noexcept {
    return this->value / prandtl_number.value;
  }

  constexpr void operator+=(const PrandtlNumber<Number>& prandtl_number) noexcept {
    this->value += prandtl_number.value;
  }

  constexpr void operator-=(const PrandtlNumber<Number>& prandtl_number) noexcept {
    this->value -= prandtl_number.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }
};

template <typename Number>
inline constexpr bool operator==(
    const PrandtlNumber<Number>& left, const PrandtlNumber<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const PrandtlNumber<Number>& left, const PrandtlNumber<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const PrandtlNumber<Number>& left, const PrandtlNumber<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const PrandtlNumber<Number>& left, const PrandtlNumber<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const PrandtlNumber<Number>& left, const PrandtlNumber<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const PrandtlNumber<Number>& left, const PrandtlNumber<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const PrandtlNumber<Number>& prandtl_number) {
  stream << prandtl_number.Print();
  return stream;
}

template <typename Number>
inline constexpr PrandtlNumber<Number> operator*(
    const Number number, const PrandtlNumber<Number>& prandtl_number) {
  return PrandtlNumber<Number>{number * prandtl_number.Value()};
}

template <typename Number>
inline constexpr ThermalDiffusivity<Number>::ThermalDiffusivity(
    const KinematicViscosity<Number>& kinematic_viscosity,
    const PrandtlNumber<Number>& prandtl_number)
  : ThermalDiffusivity<Number>(kinematic_viscosity.Value() / prandtl_number.Value()) {}

template <typename Number>
inline constexpr ScalarThermalConductivity<Number>::ScalarThermalConductivity(
    const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
    const DynamicViscosity<Number>& dynamic_viscosity, const PrandtlNumber<Number>& prandtl_number)
  : ScalarThermalConductivity<Number>(specific_isobaric_heat_capacity.Value()
                                      * dynamic_viscosity.Value() / prandtl_number.Value()) {}

template <typename Number>
inline constexpr SpecificIsobaricHeatCapacity<Number>::SpecificIsobaricHeatCapacity(
    const PrandtlNumber<Number>& prandtl_number,
    const ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
    const DynamicViscosity<Number>& dynamic_viscosity)
  : SpecificIsobaricHeatCapacity<Number>(
      prandtl_number.Value() * scalar_thermal_conductivity.Value() / dynamic_viscosity.Value()) {}

template <typename Number>
inline constexpr DynamicViscosity<Number>::DynamicViscosity(
    const PrandtlNumber<Number>& prandtl_number,
    const ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
    const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity)
  : DynamicViscosity<Number>(prandtl_number.Value() * scalar_thermal_conductivity.Value()
                             / specific_isobaric_heat_capacity.Value()) {}

template <typename Number>
inline constexpr KinematicViscosity<Number>::KinematicViscosity(
    const PrandtlNumber<Number>& prandtl_number,
    const ThermalDiffusivity<Number>& thermal_diffusivity)
  : KinematicViscosity<Number>(prandtl_number.Value() * thermal_diffusivity.Value()) {}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::PrandtlNumber<Number>> {
  inline size_t operator()(const PhQ::PrandtlNumber<Number>& prandtl_number) const {
    return hash<Number>()(prandtl_number.Value());
  }
};

}  // namespace std

#endif  // PHQ_PRANDTL_NUMBER_HPP
