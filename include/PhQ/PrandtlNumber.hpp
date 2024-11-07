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

/// \brief Prandtl number of a fluid. Represents the ratio of the momentum diffusivity to the
/// thermal diffusivity of a fluid. See also PhQ::KinematicViscosity,
/// PhQ::SpecificIsobaricHeatCapacity, PhQ::DynamicViscosity, PhQ::ScalarThermalConductivity, and
/// PhQ::ThermalDiffusivity.
template <typename NumericType = double>
class PrandtlNumber : public DimensionlessScalar<NumericType> {
public:
  /// \brief Default constructor. Constructs a Prandtl number with an uninitialized value.
  PrandtlNumber() = default;

  /// \brief Constructor. Constructs a Prandtl number with a given value.
  explicit constexpr PrandtlNumber(const NumericType value)
    : DimensionlessScalar<NumericType>(value) {}

  /// \brief Constructor. Constructs a Prandtl number from a given kinematic viscosity and thermal
  /// diffusivity using the definition of the Prandtl number.
  constexpr PrandtlNumber(const KinematicViscosity<NumericType>& kinematic_viscosity,
                          const ThermalDiffusivity<NumericType>& thermal_diffusivity)
    : PrandtlNumber<NumericType>(kinematic_viscosity.Value() / thermal_diffusivity.Value()) {}

  /// \brief Constructor. Constructs a Prandtl number from a given specific isobaric heat capacity,
  /// dynamic viscosity, and scalar thermal conductivity using the definition of the Prandtl number.
  constexpr PrandtlNumber(
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity,
      const DynamicViscosity<NumericType>& dynamic_viscosity,
      const ScalarThermalConductivity<NumericType>& scalar_thermal_conductivity)
    : PrandtlNumber<NumericType>(specific_isobaric_heat_capacity.Value() * dynamic_viscosity.Value()
                                 / scalar_thermal_conductivity.Value()) {}

  /// \brief Destructor. Destroys this Prandtl number.
  ~PrandtlNumber() noexcept = default;

  /// \brief Copy constructor. Constructs a Prandtl number by copying another one.
  constexpr PrandtlNumber(const PrandtlNumber<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a Prandtl number by copying another one.
  template <typename OtherNumericType>
  explicit constexpr PrandtlNumber(const PrandtlNumber<OtherNumericType>& other)
    : PrandtlNumber(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a Prandtl number by moving another one.
  constexpr PrandtlNumber(PrandtlNumber<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this Prandtl number by copying another one.
  constexpr PrandtlNumber<NumericType>& operator=(
      const PrandtlNumber<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this Prandtl number by copying another one.
  template <typename OtherNumericType>
  constexpr PrandtlNumber<NumericType>& operator=(const PrandtlNumber<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this Prandtl number by moving another one.
  constexpr PrandtlNumber<NumericType>& operator=(
      PrandtlNumber<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a Prandtl number of zero.
  [[nodiscard]] static constexpr PrandtlNumber<NumericType> Zero() {
    return PrandtlNumber<NumericType>{static_cast<NumericType>(0)};
  }

  [[nodiscard]] constexpr PhQ::DynamicViscosity<NumericType> DynamicViscosity(
      const PhQ::ScalarThermalConductivity<NumericType>& scalar_thermal_conductivity,
      const PhQ::SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity) const {
    return PhQ::DynamicViscosity<NumericType>{
      *this, scalar_thermal_conductivity, specific_isobaric_heat_capacity};
  }

  [[nodiscard]] constexpr PhQ::KinematicViscosity<NumericType> KinematicViscosity(
      const PhQ::ThermalDiffusivity<NumericType>& thermal_diffusivity) const {
    return PhQ::KinematicViscosity<NumericType>{*this, thermal_diffusivity};
  }

  [[nodiscard]] constexpr PhQ::SpecificIsobaricHeatCapacity<NumericType>
  SpecificIsobaricHeatCapacity(
      const PhQ::ScalarThermalConductivity<NumericType>& scalar_thermal_conductivity,
      const PhQ::DynamicViscosity<NumericType>& dynamic_viscosity) const {
    return PhQ::SpecificIsobaricHeatCapacity<NumericType>{
      *this, scalar_thermal_conductivity, dynamic_viscosity};
  }

  [[nodiscard]] constexpr PhQ::ScalarThermalConductivity<NumericType> ScalarThermalConductivity(
      const PhQ::SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity,
      const PhQ::DynamicViscosity<NumericType>& dynamic_viscosity) const {
    return PhQ::ScalarThermalConductivity<NumericType>{
      specific_isobaric_heat_capacity, dynamic_viscosity, *this};
  }

  [[nodiscard]] constexpr PhQ::ThermalDiffusivity<NumericType> ThermalDiffusivity(
      const PhQ::KinematicViscosity<NumericType>& kinematic_viscosity) const {
    return PhQ::ThermalDiffusivity<NumericType>{kinematic_viscosity, *this};
  }

  constexpr PrandtlNumber<NumericType> operator+(
      const PrandtlNumber<NumericType>& prandtl_number) const {
    return PrandtlNumber<NumericType>{this->value + prandtl_number.value};
  }

  constexpr PrandtlNumber<NumericType> operator-(
      const PrandtlNumber<NumericType>& prandtl_number) const {
    return PrandtlNumber<NumericType>{this->value - prandtl_number.value};
  }

  constexpr PrandtlNumber<NumericType> operator*(const NumericType number) const {
    return PrandtlNumber<NumericType>{this->value * number};
  }

  constexpr PrandtlNumber<NumericType> operator/(const NumericType number) const {
    return PrandtlNumber<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(const PrandtlNumber<NumericType>& prandtl_number) const noexcept {
    return this->value / prandtl_number.value;
  }

  constexpr void operator+=(const PrandtlNumber<NumericType>& prandtl_number) noexcept {
    this->value += prandtl_number.value;
  }

  constexpr void operator-=(const PrandtlNumber<NumericType>& prandtl_number) noexcept {
    this->value -= prandtl_number.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }
};

template <typename NumericType>
inline constexpr bool operator==(
    const PrandtlNumber<NumericType>& left, const PrandtlNumber<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const PrandtlNumber<NumericType>& left, const PrandtlNumber<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const PrandtlNumber<NumericType>& left, const PrandtlNumber<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const PrandtlNumber<NumericType>& left, const PrandtlNumber<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const PrandtlNumber<NumericType>& left, const PrandtlNumber<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const PrandtlNumber<NumericType>& left, const PrandtlNumber<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const PrandtlNumber<NumericType>& prandtl_number) {
  stream << prandtl_number.Print();
  return stream;
}

template <typename NumericType>
inline constexpr PrandtlNumber<NumericType> operator*(
    const NumericType number, const PrandtlNumber<NumericType>& prandtl_number) {
  return PrandtlNumber<NumericType>{number * prandtl_number.Value()};
}

template <typename NumericType>
inline constexpr ThermalDiffusivity<NumericType>::ThermalDiffusivity(
    const KinematicViscosity<NumericType>& kinematic_viscosity,
    const PrandtlNumber<NumericType>& prandtl_number)
  : ThermalDiffusivity<NumericType>(kinematic_viscosity.Value() / prandtl_number.Value()) {}

template <typename NumericType>
inline constexpr ScalarThermalConductivity<NumericType>::ScalarThermalConductivity(
    const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity,
    const DynamicViscosity<NumericType>& dynamic_viscosity,
    const PrandtlNumber<NumericType>& prandtl_number)
  : ScalarThermalConductivity<NumericType>(specific_isobaric_heat_capacity.Value()
                                           * dynamic_viscosity.Value() / prandtl_number.Value()) {}

template <typename NumericType>
inline constexpr SpecificIsobaricHeatCapacity<NumericType>::SpecificIsobaricHeatCapacity(
    const PrandtlNumber<NumericType>& prandtl_number,
    const ScalarThermalConductivity<NumericType>& scalar_thermal_conductivity,
    const DynamicViscosity<NumericType>& dynamic_viscosity)
  : SpecificIsobaricHeatCapacity<NumericType>(
        prandtl_number.Value() * scalar_thermal_conductivity.Value() / dynamic_viscosity.Value()) {}

template <typename NumericType>
inline constexpr DynamicViscosity<NumericType>::DynamicViscosity(
    const PrandtlNumber<NumericType>& prandtl_number,
    const ScalarThermalConductivity<NumericType>& scalar_thermal_conductivity,
    const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity)
  : DynamicViscosity<NumericType>(prandtl_number.Value() * scalar_thermal_conductivity.Value()
                                  / specific_isobaric_heat_capacity.Value()) {}

template <typename NumericType>
inline constexpr KinematicViscosity<NumericType>::KinematicViscosity(
    const PrandtlNumber<NumericType>& prandtl_number,
    const ThermalDiffusivity<NumericType>& thermal_diffusivity)
  : KinematicViscosity<NumericType>(prandtl_number.Value() * thermal_diffusivity.Value()) {}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::PrandtlNumber<NumericType>> {
  inline size_t operator()(const PhQ::PrandtlNumber<NumericType>& prandtl_number) const {
    return hash<NumericType>()(prandtl_number.Value());
  }
};

}  // namespace std

#endif  // PHQ_PRANDTL_NUMBER_HPP
