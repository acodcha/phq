// Copyright 2020-2023 Alexandre Coderre-Chabot
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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_PRANDTL_NUMBER_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_PRANDTL_NUMBER_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"
#include "DynamicViscosity.hpp"
#include "KinematicViscosity.hpp"
#include "SpecificIsobaricHeatCapacity.hpp"
#include "ThermalConductivityScalar.hpp"
#include "ThermalDiffusivity.hpp"

namespace PhQ {

// Prandtl number of a fluid.
class PrandtlNumber : public DimensionlessScalar {
public:
  // Default constructor. Constructs a Prandtl number with an uninitialized value.
  PrandtlNumber() = default;

  // Constructor. Constructs a Prandtl number with a given value.
  explicit constexpr PrandtlNumber(const double value) : DimensionlessScalar(value) {}

  // Constructor. Constructs a Prandtl number from a given kinematic viscosity and thermal
  // diffusivity using the definition of the Prandtl number.
  constexpr PrandtlNumber(
      const KinematicViscosity& kinematic_viscosity, const ThermalDiffusivity& thermal_diffusivity)
    : PrandtlNumber(kinematic_viscosity.Value() / thermal_diffusivity.Value()) {}

  // Constructor. Constructs a Prandtl number from a given specific isobaric heat capacity, dynamic
  // viscosity, and thermal conductivity using the definition of the Prandtl number.
  constexpr PrandtlNumber(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
                          const DynamicViscosity& dynamic_viscosity,
                          const ThermalConductivityScalar& thermal_conductivity_scalar)
    : PrandtlNumber(specific_isobaric_heat_capacity.Value() * dynamic_viscosity.Value()
                    / thermal_conductivity_scalar.Value()) {}

  // Destructor. Destroys this Prandtl number.
  ~PrandtlNumber() noexcept = default;

  // Copy constructor. Constructs a Prandtl number by copying another one.
  constexpr PrandtlNumber(const PrandtlNumber& other) = default;

  // Move constructor. Constructs a Prandtl number by moving another one.
  constexpr PrandtlNumber(PrandtlNumber&& other) noexcept = default;

  // Copy assignment operator. Assigns this Prandtl number by copying another one.
  constexpr PrandtlNumber& operator=(const PrandtlNumber& other) = default;

  // Move assignment operator. Assigns this Prandtl number by moving another one.
  constexpr PrandtlNumber& operator=(PrandtlNumber&& other) noexcept = default;

  // Statically creates a Prandtl number of zero.
  static constexpr PrandtlNumber Zero() {
    return PrandtlNumber{0.0};
  }

  [[nodiscard]] constexpr PhQ::DynamicViscosity DynamicViscosity(
      const PhQ::ThermalConductivityScalar& thermal_conductivity_scalar,
      const PhQ::SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const {
    return {*this, thermal_conductivity_scalar, specific_isobaric_heat_capacity};
  }

  [[nodiscard]] constexpr PhQ::KinematicViscosity KinematicViscosity(
      const PhQ::ThermalDiffusivity& thermal_diffusivity) const {
    return {*this, thermal_diffusivity};
  }

  [[nodiscard]] constexpr PhQ::SpecificIsobaricHeatCapacity SpecificIsobaricHeatCapacity(
      const PhQ::ThermalConductivityScalar& thermal_conductivity_scalar,
      const PhQ::DynamicViscosity& dynamic_viscosity) const {
    return {*this, thermal_conductivity_scalar, dynamic_viscosity};
  }

  [[nodiscard]] constexpr PhQ::ThermalConductivityScalar ThermalConductivityScalar(
      const PhQ::SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const PhQ::DynamicViscosity& dynamic_viscosity) const {
    return {specific_isobaric_heat_capacity, dynamic_viscosity, *this};
  }

  [[nodiscard]] constexpr PhQ::ThermalDiffusivity ThermalDiffusivity(
      const PhQ::KinematicViscosity& kinematic_viscosity) const {
    return {kinematic_viscosity, *this};
  }

  constexpr PrandtlNumber operator+(const PrandtlNumber& prandtl_number) const {
    return PrandtlNumber{value_ + prandtl_number.value_};
  }

  constexpr PrandtlNumber operator-(const PrandtlNumber& prandtl_number) const {
    return PrandtlNumber{value_ - prandtl_number.value_};
  }

  constexpr PrandtlNumber operator*(const double number) const {
    return PrandtlNumber{value_ * number};
  }

  constexpr PrandtlNumber operator/(const double number) const {
    return PrandtlNumber{value_ / number};
  }

  constexpr double operator/(const PrandtlNumber& prandtl_number) const noexcept {
    return value_ / prandtl_number.value_;
  }

  constexpr void operator+=(const PrandtlNumber& prandtl_number) noexcept {
    value_ += prandtl_number.value_;
  }

  constexpr void operator-=(const PrandtlNumber& prandtl_number) noexcept {
    value_ -= prandtl_number.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }
};

inline constexpr bool operator==(const PrandtlNumber& left, const PrandtlNumber& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const PrandtlNumber& left, const PrandtlNumber& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const PrandtlNumber& left, const PrandtlNumber& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const PrandtlNumber& left, const PrandtlNumber& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const PrandtlNumber& left, const PrandtlNumber& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const PrandtlNumber& left, const PrandtlNumber& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const PrandtlNumber& prandtl_number) {
  stream << prandtl_number.Print();
  return stream;
}

inline constexpr PrandtlNumber operator*(const double number, const PrandtlNumber& prandtl_number) {
  return PrandtlNumber{number * prandtl_number.Value()};
}

inline constexpr ThermalDiffusivity::ThermalDiffusivity(
    const KinematicViscosity& kinematic_viscosity, const PrandtlNumber& prandtl_number)
  : ThermalDiffusivity(kinematic_viscosity.Value() / prandtl_number.Value()) {}

inline constexpr ThermalConductivityScalar::ThermalConductivityScalar(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
    const DynamicViscosity& dynamic_viscosity, const PrandtlNumber& prandtl_number)
  : ThermalConductivityScalar(specific_isobaric_heat_capacity.Value() * dynamic_viscosity.Value()
                              / prandtl_number.Value()) {}

inline constexpr SpecificIsobaricHeatCapacity::SpecificIsobaricHeatCapacity(
    const PrandtlNumber& prandtl_number,
    const ThermalConductivityScalar& thermal_conductivity_scalar,
    const DynamicViscosity& dynamic_viscosity)
  : SpecificIsobaricHeatCapacity(
      prandtl_number.Value() * thermal_conductivity_scalar.Value() / dynamic_viscosity.Value()) {}

inline constexpr DynamicViscosity::DynamicViscosity(
    const PrandtlNumber& prandtl_number,
    const ThermalConductivityScalar& thermal_conductivity_scalar,
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity)
  : DynamicViscosity(prandtl_number.Value() * thermal_conductivity_scalar.Value()
                     / specific_isobaric_heat_capacity.Value()) {}

inline constexpr KinematicViscosity::KinematicViscosity(
    const PrandtlNumber& prandtl_number, const ThermalDiffusivity& thermal_diffusivity)
  : KinematicViscosity(prandtl_number.Value() * thermal_diffusivity.Value()) {}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::PrandtlNumber> {
  inline size_t operator()(const PhQ::PrandtlNumber& prandtl_number) const {
    return hash<double>()(prandtl_number.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_PRANDTL_NUMBER_HPP
