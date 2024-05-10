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

#ifndef PHQ_SPECIFIC_ISOBARIC_HEAT_CAPACITY_HPP
#define PHQ_SPECIFIC_ISOBARIC_HEAT_CAPACITY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "HeatCapacityRatio.hpp"
#include "IsobaricHeatCapacity.hpp"
#include "SpecificIsochoricHeatCapacity.hpp"
#include "Unit/SpecificHeatCapacity.hpp"

namespace PhQ {

// Forward declaration for class PhQ::SpecificIsobaricHeatCapacity.
template <typename Number>
class DynamicViscosity;

// Forward declaration for class PhQ::SpecificIsobaricHeatCapacity.
template <typename Number>
class MassDensity;

// Forward declaration for class PhQ::SpecificIsobaricHeatCapacity.
template <typename Number>
class PrandtlNumber;

// Forward declaration for class PhQ::SpecificIsobaricHeatCapacity.
template <typename Number>
class ScalarThermalConductivity;

// Forward declaration for class PhQ::SpecificIsobaricHeatCapacity.
template <typename Number>
class ThermalDiffusivity;

// Specific isobaric heat capacity. Isobaric heat capacity per unit mass.
template <typename Number = double>
class SpecificIsobaricHeatCapacity : public DimensionalScalar<Unit::SpecificHeatCapacity, Number> {
public:
  // Default constructor. Constructs a specific isobaric heat capacity with an uninitialized value.
  SpecificIsobaricHeatCapacity() = default;

  // Constructor. Constructs a specific isobaric heat capacity with a given value expressed in a
  // given specific heat capacity unit.
  SpecificIsobaricHeatCapacity(const Number value, const Unit::SpecificHeatCapacity unit)
    : DimensionalScalar<Unit::SpecificHeatCapacity, Number>(value, unit) {}

  // Constructor. Constructs a specific isobaric heat capacity from a given specific gas constant
  // and specific isochoric heat capacity using Mayer's relation.
  constexpr SpecificIsobaricHeatCapacity(
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity,
      const SpecificGasConstant<Number>& specific_gas_constant);

  // Constructor. Constructs a specific isobaric heat capacity from a given specific gas constant
  // and heat capacity ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr SpecificIsobaricHeatCapacity(const HeatCapacityRatio<Number>& heat_capacity_ratio,
                                         const SpecificGasConstant<Number>& specific_gas_constant);

  // Constructor. Constructs a specific isobaric heat capacity from a given specific isochoric heat
  // capacity and heat capacity ratio using the definition of the heat capacity ratio.
  constexpr SpecificIsobaricHeatCapacity(
      const HeatCapacityRatio<Number>& heat_capacity_ratio,
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity)
    : SpecificIsobaricHeatCapacity<Number>(
        heat_capacity_ratio.Value() * specific_isochoric_heat_capacity.Value()) {}

  // Constructor. Constructs a specific isobaric heat capacity from a given isobaric heat capacity
  // and mass using the definition of the specific isobaric heat capacity.
  constexpr SpecificIsobaricHeatCapacity(
      const IsobaricHeatCapacity<Number>& isobaric_heat_capacity, const Mass<Number>& mass)
    : SpecificIsobaricHeatCapacity<Number>(isobaric_heat_capacity.Value() / mass.Value()) {}

  // Constructor. Constructs a specific isobaric heat capacity from a given scalar thermal
  // conductivity mass density, and thermal diffusivity using the definition of the specific
  // isobaric heat capacity and Fourier's law of heat conduction.
  constexpr SpecificIsobaricHeatCapacity(
      const ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
      const MassDensity<Number>& mass_density,
      const ThermalDiffusivity<Number>& thermal_diffusivity);

  // Constructor. Constructs a specific isobaric heat capacity from a given Prandtl number, scalar
  // thermal conductivity, and dynamic viscosity using the definition of the Prandtl number.
  constexpr SpecificIsobaricHeatCapacity(
      const PrandtlNumber<Number>& prandtl_number,
      const ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
      const DynamicViscosity<Number>& dynamic_viscosity);

  // Destructor. Destroys this specific isobaric heat capacity.
  ~SpecificIsobaricHeatCapacity() noexcept = default;

  // Copy constructor. Constructs a specific isobaric heat capacity by copying another one.
  constexpr SpecificIsobaricHeatCapacity(
      const SpecificIsobaricHeatCapacity<Number>& other) = default;

  // Copy constructor. Constructs a specific isobaric heat capacity by copying another one.
  template <typename OtherNumber>
  explicit constexpr SpecificIsobaricHeatCapacity(
      const SpecificIsobaricHeatCapacity<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a specific isobaric heat capacity by moving another one.
  constexpr SpecificIsobaricHeatCapacity(
      SpecificIsobaricHeatCapacity<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this specific isobaric heat capacity by copying another one.
  constexpr SpecificIsobaricHeatCapacity<Number>& operator=(
      const SpecificIsobaricHeatCapacity<Number>& other) = default;

  // Copy assignment operator. Assigns this specific isobaric heat capacity by copying another one.
  template <typename OtherNumber>
  constexpr SpecificIsobaricHeatCapacity<Number>& operator=(
      const SpecificIsobaricHeatCapacity<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this specific isobaric heat capacity by moving another one.
  constexpr SpecificIsobaricHeatCapacity<Number>& operator=(
      SpecificIsobaricHeatCapacity<Number>&& other) noexcept = default;

  // Statically creates a specific isobaric heat capacity of zero.
  static constexpr SpecificIsobaricHeatCapacity<Number> Zero() {
    return SpecificIsobaricHeatCapacity<Number>{static_cast<Number>(0)};
  }

  // Statically creates a specific isobaric heat capacity with a given value expressed in a given
  // specific heat capacity unit.
  template <Unit::SpecificHeatCapacity Unit>
  static constexpr SpecificIsobaricHeatCapacity<Number> Create(const Number value) {
    return SpecificIsobaricHeatCapacity<Number>{
        StaticConvertCopy<Unit::SpecificHeatCapacity, Unit, Standard<Unit::SpecificHeatCapacity>>(
            value)};
  }

  constexpr SpecificIsobaricHeatCapacity<Number> operator+(
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity) const {
    return SpecificIsobaricHeatCapacity<Number>{value + specific_isobaric_heat_capacity.value};
  }

  constexpr SpecificIsobaricHeatCapacity<Number> operator-(
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity) const {
    return SpecificIsobaricHeatCapacity<Number>{value - specific_isobaric_heat_capacity.value};
  }

  constexpr SpecificGasConstant<Number> operator-(
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) const;

  constexpr SpecificIsochoricHeatCapacity<Number> operator-(
      const SpecificGasConstant<Number>& specific_gas_constant) const;

  constexpr SpecificIsobaricHeatCapacity<Number> operator*(const Number number) const {
    return SpecificIsobaricHeatCapacity<Number>{value * number};
  }

  constexpr IsobaricHeatCapacity<Number> operator*(const Mass<Number>& mass) const {
    return IsobaricHeatCapacity<Number>{*this, mass};
  }

  constexpr SpecificIsobaricHeatCapacity<Number> operator/(const Number number) const {
    return SpecificIsobaricHeatCapacity<Number>{value / number};
  }

  constexpr Number operator/(
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity) const noexcept {
    return value / specific_isobaric_heat_capacity.value;
  }

  constexpr HeatCapacityRatio<Number> operator/(
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) const {
    return HeatCapacityRatio<Number>{*this, specific_isochoric_heat_capacity};
  }

  constexpr SpecificIsochoricHeatCapacity<Number> operator/(
      const HeatCapacityRatio<Number>& heat_capacity_ratio) const {
    return SpecificIsochoricHeatCapacity<Number>{*this, heat_capacity_ratio};
  }

  constexpr void operator+=(
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity) noexcept {
    value += specific_isobaric_heat_capacity.value;
  }

  constexpr void operator-=(
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity) noexcept {
    value -= specific_isobaric_heat_capacity.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a specific isobaric heat capacity with a given value expressed in the
  // standard specific heat capacity unit.
  explicit constexpr SpecificIsobaricHeatCapacity(const Number value)
    : DimensionalScalar<Unit::SpecificHeatCapacity, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const SpecificIsobaricHeatCapacity<Number>& left,
                                 const SpecificIsobaricHeatCapacity<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const SpecificIsobaricHeatCapacity<Number>& left,
                                 const SpecificIsobaricHeatCapacity<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const SpecificIsobaricHeatCapacity<Number>& left,
                                const SpecificIsobaricHeatCapacity<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const SpecificIsobaricHeatCapacity<Number>& left,
                                const SpecificIsobaricHeatCapacity<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const SpecificIsobaricHeatCapacity<Number>& left,
                                 const SpecificIsobaricHeatCapacity<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const SpecificIsobaricHeatCapacity<Number>& left,
                                 const SpecificIsobaricHeatCapacity<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream,
    const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity) {
  stream << specific_isobaric_heat_capacity.Print();
  return stream;
}

template <typename Number>
inline constexpr SpecificIsobaricHeatCapacity<Number> operator*(
    const Number number,
    const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity) {
  return specific_isobaric_heat_capacity * number;
}

template <typename Number>
inline constexpr HeatCapacityRatio<Number>::HeatCapacityRatio(
    const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
    const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity)
  : HeatCapacityRatio<Number>(
      specific_isobaric_heat_capacity.Value() / specific_isochoric_heat_capacity.Value()) {}

template <typename Number>
inline constexpr Mass<Number>::Mass(
    const IsobaricHeatCapacity<Number>& isobaric_heat_capacity,
    const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity)
  : Mass<Number>(isobaric_heat_capacity.Value() / specific_isobaric_heat_capacity.Value()) {}

template <typename Number>
inline constexpr IsobaricHeatCapacity<Number>::IsobaricHeatCapacity(
    const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
    const Mass<Number>& mass)
  : IsobaricHeatCapacity<Number>(specific_isobaric_heat_capacity.Value() * mass.Value()) {}

template <typename Number>
inline constexpr SpecificIsochoricHeatCapacity<Number>::SpecificIsochoricHeatCapacity(
    const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
    const HeatCapacityRatio<Number>& heat_capacity_ratio)
  : SpecificIsochoricHeatCapacity<Number>(
      specific_isobaric_heat_capacity.Value() / heat_capacity_ratio.Value()) {}

template <typename Number>
inline constexpr IsobaricHeatCapacity<Number> Mass<Number>::operator*(
    const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity) const {
  return IsobaricHeatCapacity<Number>{specific_isobaric_heat_capacity, *this};
}

template <typename Number>
inline constexpr SpecificIsobaricHeatCapacity<Number> HeatCapacityRatio<Number>::operator*(
    const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) const {
  return SpecificIsobaricHeatCapacity<Number>{*this, specific_isochoric_heat_capacity};
}

template <typename Number>
inline constexpr SpecificIsobaricHeatCapacity<Number>
SpecificIsochoricHeatCapacity<Number>::operator*(
    const HeatCapacityRatio<Number>& heat_capacity_ratio) const {
  return SpecificIsobaricHeatCapacity<Number>{heat_capacity_ratio, *this};
}

template <typename Number>
inline constexpr SpecificIsobaricHeatCapacity<Number> IsobaricHeatCapacity<Number>::operator/(
    const Mass<Number>& mass) const {
  return SpecificIsobaricHeatCapacity<Number>{*this, mass};
}

template <typename Number>
inline constexpr Mass<Number> IsobaricHeatCapacity<Number>::operator/(
    const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity) const {
  return Mass<Number>{*this, specific_isobaric_heat_capacity};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::SpecificIsobaricHeatCapacity<Number>> {
  inline size_t operator()(
      const PhQ::SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity) const {
    return hash<Number>()(specific_isobaric_heat_capacity.Value());
  }
};

}  // namespace std

#endif  // PHQ_SPECIFIC_ISOBARIC_HEAT_CAPACITY_HPP
