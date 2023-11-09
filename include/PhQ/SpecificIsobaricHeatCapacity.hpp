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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_ISOBARIC_HEAT_CAPACITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_ISOBARIC_HEAT_CAPACITY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalarQuantity.hpp"
#include "HeatCapacityRatio.hpp"
#include "IsobaricHeatCapacity.hpp"
#include "SpecificIsochoricHeatCapacity.hpp"
#include "Unit/SpecificHeatCapacity.hpp"

namespace PhQ {

// Forward declarations for class SpecificIsobaricHeatCapacity.
class DynamicViscosity;
class MassDensity;
class PrandtlNumber;
class ThermalConductivityScalar;
class ThermalDiffusivity;

// Specific isobaric heat capacity. Isobaric heat capacity per unit mass.
class SpecificIsobaricHeatCapacity : public DimensionalScalarQuantity<Unit::SpecificHeatCapacity> {
public:
  // Default constructor. Constructs a specific isobaric heat capacity with an uninitialized value.
  SpecificIsobaricHeatCapacity() = default;

  // Constructor. Constructs a specific isobaric heat capacity with a given value expressed in a
  // given specific heat capacity unit.
  SpecificIsobaricHeatCapacity(const double value, const Unit::SpecificHeatCapacity unit)
    : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value, unit) {}

  // Constructor. Constructs a specific isobaric heat capacity from a given specific gas constant
  // and specific isochoric heat capacity using Mayer's relation.
  constexpr SpecificIsobaricHeatCapacity(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity,
      const SpecificGasConstant& specific_gas_constant);

  // Constructor. Constructs a specific isobaric heat capacity from a given specific gas constant
  // and heat capacity ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr SpecificIsobaricHeatCapacity(const HeatCapacityRatio& heat_capacity_ratio,
                                         const SpecificGasConstant& specific_gas_constant);

  // Constructor. Constructs a specific isobaric heat capacity from a given specific isochoric heat
  // capacity and heat capacity ratio using the definition of the heat capacity ratio.
  constexpr SpecificIsobaricHeatCapacity(
      const HeatCapacityRatio& heat_capacity_ratio,
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
    : SpecificIsobaricHeatCapacity(
        heat_capacity_ratio.Value() * specific_isochoric_heat_capacity.Value()) {}

  // Constructor. Constructs a specific isobaric heat capacity from a given isobaric heat capacity
  // and mass using the definition of the specific isobaric heat capacity.
  constexpr SpecificIsobaricHeatCapacity(
      const IsobaricHeatCapacity& isobaric_heat_capacity, const Mass& mass)
    : SpecificIsobaricHeatCapacity(isobaric_heat_capacity.Value() / mass.Value()) {}

  // Constructor. Constructs a specific isobaric heat capacity from a given thermal conductivity
  // scalar, mass density, and thermal diffusivity using the definition of the specific isobaric
  // heat capacity and Fourier's law of heat conduction.
  constexpr SpecificIsobaricHeatCapacity(
      const ThermalConductivityScalar& thermal_conductivity_scalar, const MassDensity& mass_density,
      const ThermalDiffusivity& thermal_diffusivity);

  // Constructor. Constructs a specific isobaric heat capacity from a given Prandtl number, thermal
  // conductivity scalar, and dynamic viscosity using the definition of the Prandtl number.
  constexpr SpecificIsobaricHeatCapacity(
      const PrandtlNumber& prandtl_number,
      const ThermalConductivityScalar& thermal_conductivity_scalar,
      const DynamicViscosity& dynamic_viscosity);

  // Destructor. Destroys this specific isobaric heat capacity.
  ~SpecificIsobaricHeatCapacity() noexcept = default;

  // Copy constructor. Constructs a specific isobaric heat capacity by copying another one.
  constexpr SpecificIsobaricHeatCapacity(const SpecificIsobaricHeatCapacity& other) = default;

  // Move constructor. Constructs a specific isobaric heat capacity by moving another one.
  constexpr SpecificIsobaricHeatCapacity(SpecificIsobaricHeatCapacity&& other) noexcept = default;

  // Copy assignment operator. Assigns this specific isobaric heat capacity by copying another one.
  constexpr SpecificIsobaricHeatCapacity& operator=(
      const SpecificIsobaricHeatCapacity& other) = default;

  // Move assignment operator. Assigns this specific isobaric heat capacity by moving another one.
  constexpr SpecificIsobaricHeatCapacity& operator=(
      SpecificIsobaricHeatCapacity&& other) noexcept = default;

  // Statically creates a specific isobaric heat capacity of zero.
  static constexpr SpecificIsobaricHeatCapacity Zero() {
    return SpecificIsobaricHeatCapacity{0.0};
  }

  // Statically creates a specific isobaric heat capacity with a given value expressed in a given
  // specific heat capacity unit.
  template <Unit::SpecificHeatCapacity Unit>
  static constexpr SpecificIsobaricHeatCapacity Create(const double value) {
    return SpecificIsobaricHeatCapacity{
        StaticConvertCopy<Unit::SpecificHeatCapacity, Unit, Standard<Unit::SpecificHeatCapacity>>(
            value)};
  }

  constexpr SpecificIsobaricHeatCapacity operator+(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const {
    return SpecificIsobaricHeatCapacity{value_ + specific_isobaric_heat_capacity.value_};
  }

  constexpr SpecificIsobaricHeatCapacity operator-(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const {
    return SpecificIsobaricHeatCapacity{value_ - specific_isobaric_heat_capacity.value_};
  }

  constexpr SpecificGasConstant operator-(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const;

  constexpr SpecificIsochoricHeatCapacity operator-(
      const SpecificGasConstant& specific_gas_constant) const;

  constexpr SpecificIsobaricHeatCapacity operator*(const double number) const {
    return SpecificIsobaricHeatCapacity{value_ * number};
  }

  constexpr IsobaricHeatCapacity operator*(const Mass& mass) const {
    return {*this, mass};
  }

  constexpr SpecificIsobaricHeatCapacity operator/(const double number) const {
    return SpecificIsobaricHeatCapacity{value_ / number};
  }

  constexpr double operator/(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const noexcept {
    return value_ / specific_isobaric_heat_capacity.value_;
  }

  constexpr HeatCapacityRatio operator/(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const {
    return {*this, specific_isochoric_heat_capacity};
  }

  constexpr SpecificIsochoricHeatCapacity operator/(
      const HeatCapacityRatio& heat_capacity_ratio) const {
    return {*this, heat_capacity_ratio};
  }

  constexpr void operator+=(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept {
    value_ += specific_isobaric_heat_capacity.value_;
  }

  constexpr void operator-=(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) noexcept {
    value_ -= specific_isobaric_heat_capacity.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a specific isobaric heat capacity with a given value expressed in the
  // standard specific heat capacity unit.
  explicit constexpr SpecificIsobaricHeatCapacity(const double value)
    : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value) {}
};

inline constexpr bool operator==(
    const SpecificIsobaricHeatCapacity& left, const SpecificIsobaricHeatCapacity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const SpecificIsobaricHeatCapacity& left, const SpecificIsobaricHeatCapacity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const SpecificIsobaricHeatCapacity& left, const SpecificIsobaricHeatCapacity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const SpecificIsobaricHeatCapacity& left, const SpecificIsobaricHeatCapacity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const SpecificIsobaricHeatCapacity& left, const SpecificIsobaricHeatCapacity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const SpecificIsobaricHeatCapacity& left, const SpecificIsobaricHeatCapacity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) {
  stream << specific_isobaric_heat_capacity.Print();
  return stream;
}

inline constexpr SpecificIsobaricHeatCapacity operator*(
    const double number, const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) {
  return specific_isobaric_heat_capacity * number;
}

inline constexpr HeatCapacityRatio::HeatCapacityRatio(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
  : HeatCapacityRatio(
      specific_isobaric_heat_capacity.Value() / specific_isochoric_heat_capacity.Value()) {}

inline constexpr Mass::Mass(const IsobaricHeatCapacity& isobaric_heat_capacity,
                            const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity)
  : Mass(isobaric_heat_capacity.Value() / specific_isobaric_heat_capacity.Value()) {}

inline constexpr IsobaricHeatCapacity::IsobaricHeatCapacity(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const Mass& mass)
  : IsobaricHeatCapacity(specific_isobaric_heat_capacity.Value() * mass.Value()) {}

inline constexpr SpecificIsochoricHeatCapacity::SpecificIsochoricHeatCapacity(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
    const HeatCapacityRatio& heat_capacity_ratio)
  : SpecificIsochoricHeatCapacity(
      specific_isobaric_heat_capacity.Value() / heat_capacity_ratio.Value()) {}

inline constexpr IsobaricHeatCapacity Mass::operator*(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const {
  return {specific_isobaric_heat_capacity, *this};
}

inline constexpr SpecificIsobaricHeatCapacity HeatCapacityRatio::operator*(
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const {
  return {*this, specific_isochoric_heat_capacity};
}

inline constexpr SpecificIsobaricHeatCapacity SpecificIsochoricHeatCapacity::operator*(
    const HeatCapacityRatio& heat_capacity_ratio) const {
  return {heat_capacity_ratio, *this};
}

inline constexpr SpecificIsobaricHeatCapacity IsobaricHeatCapacity::operator/(
    const Mass& mass) const {
  return {*this, mass};
}

inline constexpr Mass IsobaricHeatCapacity::operator/(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const {
  return {*this, specific_isobaric_heat_capacity};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::SpecificIsobaricHeatCapacity> {
  inline size_t operator()(
      const PhQ::SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const {
    return hash<double>()(specific_isobaric_heat_capacity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_ISOBARIC_HEAT_CAPACITY_HPP
