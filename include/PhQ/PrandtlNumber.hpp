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

// Prandtl number of a fluid.
template <typename Number = double>
class PrandtlNumber : public DimensionlessScalar<Number> {
public:
  // Default constructor. Constructs a Prandtl number with an uninitialized value.
  PrandtlNumber() = default;

  // Constructor. Constructs a Prandtl number with a given value.
  explicit constexpr PrandtlNumber(const Number value) : DimensionlessScalar<Number>(value) {}

  // Constructor. Constructs a Prandtl number from a given kinematic viscosity and thermal
  // diffusivity using the definition of the Prandtl number.
  constexpr PrandtlNumber(const KinematicViscosity<Number>& kinematic_viscosity,
                          const ThermalDiffusivity<Number>& thermal_diffusivity)
    : PrandtlNumber<Number>(kinematic_viscosity.Value() / thermal_diffusivity.Value()) {}

  // Constructor. Constructs a Prandtl number from a given specific isobaric heat capacity, dynamic
  // viscosity, and scalar thermal conductivity using the definition of the Prandtl number.
  constexpr PrandtlNumber(
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
      const DynamicViscosity<Number>& dynamic_viscosity,
      const ScalarThermalConductivity<Number>& scalar_thermal_conductivity)
    : PrandtlNumber<Number>(specific_isobaric_heat_capacity.Value() * dynamic_viscosity.Value()
                            / scalar_thermal_conductivity.Value()) {}

  // Destructor. Destroys this Prandtl number.
  ~PrandtlNumber() noexcept = default;

  // Copy constructor. Constructs a Prandtl number by copying another one.
  constexpr PrandtlNumber(const PrandtlNumber<Number>& other) = default;

  // Copy constructor. Constructs a Prandtl number by copying another one.
  template <typename OtherNumber>
  explicit constexpr PrandtlNumber(const PrandtlNumber<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a Prandtl number by moving another one.
  constexpr PrandtlNumber(PrandtlNumber<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this Prandtl number by copying another one.
  constexpr PrandtlNumber<Number>& operator=(const PrandtlNumber<Number>& other) = default;

  // Copy assignment operator. Assigns this Prandtl number by copying another one.
  template <typename OtherNumber>
  constexpr PrandtlNumber<Number>& operator=(const PrandtlNumber<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this Prandtl number by moving another one.
  constexpr PrandtlNumber<Number>& operator=(PrandtlNumber<Number>&& other) noexcept = default;

  // Statically creates a Prandtl number of zero.
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
    return PrandtlNumber<Number>{value + prandtl_number.value};
  }

  constexpr PrandtlNumber<Number> operator-(const PrandtlNumber<Number>& prandtl_number) const {
    return PrandtlNumber<Number>{value - prandtl_number.value};
  }

  constexpr PrandtlNumber<Number> operator*(const Number number) const {
    return PrandtlNumber<Number>{value * number};
  }

  constexpr PrandtlNumber<Number> operator/(const Number number) const {
    return PrandtlNumber<Number>{value / number};
  }

  constexpr Number operator/(const PrandtlNumber<Number>& prandtl_number) const noexcept {
    return value / prandtl_number.value;
  }

  constexpr void operator+=(const PrandtlNumber<Number>& prandtl_number) noexcept {
    value += prandtl_number.value;
  }

  constexpr void operator-=(const PrandtlNumber<Number>& prandtl_number) noexcept {
    value -= prandtl_number.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
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
