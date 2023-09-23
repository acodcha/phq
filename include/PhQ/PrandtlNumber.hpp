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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_PRANDTL_NUMBER_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_PRANDTL_NUMBER_HPP

#include "DimensionlessScalarQuantity.hpp"
#include "DynamicViscosity.hpp"
#include "ThermalDiffusivity.hpp"

namespace PhQ {

// Prandtl number of a fluid.
class PrandtlNumber : public DimensionlessScalarQuantity {
public:
  // Default constructor. Constructs a Prandtl number with an uninitialized
  // value.
  constexpr PrandtlNumber() : DimensionlessScalarQuantity() {}

  // Constructor. Constructs a Prandtl number with a given value.
  explicit constexpr PrandtlNumber(const double value)
    : DimensionlessScalarQuantity(value) {}

  // Constructor. Constructs a Prandtl number from a given kinematic viscosity
  // and thermal diffusivity using the definition of the Prandtl number.
  constexpr PrandtlNumber(const KinematicViscosity& kinematic_viscosity,
                          const ThermalDiffusivity& thermal_diffusivity)
    : PrandtlNumber(kinematic_viscosity.Value() / thermal_diffusivity.Value()) {
  }

  // Constructor. Constructs a Prandtl number from a given dynamic viscosity,
  // specific isobaric heat capacity, and thermal conductivity using the
  // definition of the Prandtl number.
  constexpr PrandtlNumber(
      const DynamicViscosity& dynamic_viscosity,
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const ThermalConductivityScalar& thermal_conductivity_scalar)
    : PrandtlNumber(
        dynamic_viscosity.Value() * specific_isobaric_heat_capacity.Value()
        / thermal_conductivity_scalar.Value()) {}

  // Destructor. Destroys a Prandtl number.
  ~PrandtlNumber() noexcept = default;

  // Copy constructor. Constructs a Prandtl number by copying another one.
  constexpr PrandtlNumber(const PrandtlNumber& other) = default;

  // Move constructor. Constructs a Prandtl number by moving another one.
  constexpr PrandtlNumber(PrandtlNumber&& other) noexcept = default;

  // Copy assignment operator. Assigns this Prandtl number by copying another
  // one.
  constexpr PrandtlNumber& operator=(const PrandtlNumber& other) = default;

  // Move assignment operator. Assigns this Prandtl number by moving another
  // one.
  constexpr PrandtlNumber& operator=(PrandtlNumber&& other) noexcept = default;

  // Returns a Prandtl number of zero.
  static constexpr PrandtlNumber Zero() {
    return PrandtlNumber{0.0};
  }

  constexpr PhQ::ThermalDiffusivity ThermalDiffusivity(
      const PhQ::KinematicViscosity& kinematic_viscosity) const {
    return {*this, kinematic_viscosity};
  }

  constexpr PhQ::ThermalConductivityScalar ThermalConductivityScalar(
      const PhQ::SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const PhQ::DynamicViscosity& dynamic_viscosity) const {
    return {*this, specific_isobaric_heat_capacity, dynamic_viscosity};
  }

  constexpr PhQ::SpecificIsobaricHeatCapacity SpecificIsobaricHeatCapacity(
      const PhQ::ThermalConductivityScalar& thermal_conductivity_scalar,
      const PhQ::DynamicViscosity& dynamic_viscosity) const {
    return {*this, thermal_conductivity_scalar, dynamic_viscosity};
  }

  constexpr PhQ::DynamicViscosity DynamicViscosity(
      const PhQ::ThermalConductivityScalar& thermal_conductivity_scalar,
      PhQ::SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity)
      const {
    return {
        *this, thermal_conductivity_scalar, specific_isobaric_heat_capacity};
  }

  constexpr PhQ::KinematicViscosity KinematicViscosity(
      const PhQ::ThermalDiffusivity& thermal_diffusivity) const {
    return {*this, thermal_diffusivity};
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

  constexpr double operator/(
      const PrandtlNumber& prandtl_number) const noexcept {
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

inline constexpr bool operator==(
    const PrandtlNumber& left, const PrandtlNumber& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const PrandtlNumber& left, const PrandtlNumber& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const PrandtlNumber& left, const PrandtlNumber& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const PrandtlNumber& left, const PrandtlNumber& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const PrandtlNumber& left, const PrandtlNumber& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const PrandtlNumber& left, const PrandtlNumber& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const PrandtlNumber& prandtl_number) {
  stream << prandtl_number.Print();
  return stream;
}

inline constexpr PrandtlNumber operator+(
    const double number, const PrandtlNumber& prandtl_number) {
  return PrandtlNumber{number + prandtl_number.Value()};
}

inline constexpr PrandtlNumber operator-(
    const double number, const PrandtlNumber& prandtl_number) {
  return PrandtlNumber{number - prandtl_number.Value()};
}

inline constexpr PrandtlNumber operator*(
    const double number, const PrandtlNumber& prandtl_number) {
  return PrandtlNumber{number * prandtl_number.Value()};
}

inline constexpr double operator/(
    const double number, const PrandtlNumber& prandtl_number) noexcept {
  return number / prandtl_number.Value();
}

inline constexpr ThermalDiffusivity::ThermalDiffusivity(
    const PrandtlNumber& prandtl_number,
    const KinematicViscosity& kinematic_viscosity)
  : ThermalDiffusivity(kinematic_viscosity.Value() / prandtl_number.Value()) {}

inline constexpr ThermalConductivityScalar::ThermalConductivityScalar(
    const PrandtlNumber& prandtl_number,
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
    const DynamicViscosity& dynamic_viscosity)
  : ThermalConductivityScalar(
      specific_isobaric_heat_capacity.Value() * dynamic_viscosity.Value()
      / prandtl_number.Value()) {}

inline constexpr SpecificIsobaricHeatCapacity::SpecificIsobaricHeatCapacity(
    const PrandtlNumber& prandtl_number,
    const ThermalConductivityScalar& thermal_conductivity_scalar,
    const DynamicViscosity& dynamic_viscosity)
  : SpecificIsobaricHeatCapacity(
      prandtl_number.Value() * thermal_conductivity_scalar.Value()
      / dynamic_viscosity.Value()) {}

inline constexpr DynamicViscosity::DynamicViscosity(
    const PrandtlNumber& prandtl_number,
    const ThermalConductivityScalar& thermal_conductivity_scalar,
    SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity)
  : DynamicViscosity(
      prandtl_number.Value() * thermal_conductivity_scalar.Value()
      / specific_isobaric_heat_capacity.Value()) {}

inline constexpr KinematicViscosity::KinematicViscosity(
    const PrandtlNumber& prandtl_number,
    const ThermalDiffusivity& thermal_diffusivity)
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
