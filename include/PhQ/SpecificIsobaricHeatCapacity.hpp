// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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
template <typename NumericType>
class DynamicViscosity;

// Forward declaration for class PhQ::SpecificIsobaricHeatCapacity.
template <typename NumericType>
class MassDensity;

// Forward declaration for class PhQ::SpecificIsobaricHeatCapacity.
template <typename NumericType>
class PrandtlNumber;

// Forward declaration for class PhQ::SpecificIsobaricHeatCapacity.
template <typename NumericType>
class ScalarThermalConductivity;

// Forward declaration for class PhQ::SpecificIsobaricHeatCapacity.
template <typename NumericType>
class ThermalDiffusivity;

/// \brief Mass-specific isobaric heat capacity, also known as mass-specific heat capacity at
/// constant pressure, or isobaric heat capacity per unit mass; see PhQ::IsobaricHeatCapacity and
/// PhQ::Mass.
template <typename NumericType = double>
class SpecificIsobaricHeatCapacity
  : public DimensionalScalar<Unit::SpecificHeatCapacity, NumericType> {
public:
  /// \brief Default constructor. Constructs a specific isobaric heat capacity with an uninitialized
  /// value.
  SpecificIsobaricHeatCapacity() = default;

  /// \brief Constructor. Constructs a specific isobaric heat capacity with a given value expressed
  /// in a given specific heat capacity unit.
  SpecificIsobaricHeatCapacity(const NumericType value, const Unit::SpecificHeatCapacity unit)
    : DimensionalScalar<Unit::SpecificHeatCapacity, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a specific isobaric heat capacity from a given specific gas
  /// constant and specific isochoric heat capacity using Mayer's relation.
  constexpr SpecificIsobaricHeatCapacity(
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity,
      const SpecificGasConstant<NumericType>& specific_gas_constant);

  /// \brief Constructor. Constructs a specific isobaric heat capacity from a given specific gas
  /// constant and heat capacity ratio using the definition of the heat capacity ratio and Mayer's
  /// relation.
  constexpr SpecificIsobaricHeatCapacity(
      const HeatCapacityRatio<NumericType>& heat_capacity_ratio,
      const SpecificGasConstant<NumericType>& specific_gas_constant);

  /// \brief Constructor. Constructs a specific isobaric heat capacity from a given specific
  /// isochoric heat capacity and heat capacity ratio using the definition of the heat capacity
  /// ratio.
  constexpr SpecificIsobaricHeatCapacity(
      const HeatCapacityRatio<NumericType>& heat_capacity_ratio,
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity)
    : SpecificIsobaricHeatCapacity<NumericType>(
        heat_capacity_ratio.Value() * specific_isochoric_heat_capacity.Value()) {}

  /// \brief Constructor. Constructs a specific isobaric heat capacity from a given isobaric heat
  /// capacity and mass using the definition of the specific isobaric heat capacity.
  constexpr SpecificIsobaricHeatCapacity(
      const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity,
      const Mass<NumericType>& mass)
    : SpecificIsobaricHeatCapacity<NumericType>(isobaric_heat_capacity.Value() / mass.Value()) {}

  /// \brief Constructor. Constructs a specific isobaric heat capacity from a given scalar thermal
  /// conductivity mass density, and thermal diffusivity using the definition of the specific
  /// isobaric heat capacity and Fourier's law of heat conduction.
  constexpr SpecificIsobaricHeatCapacity(
      const ScalarThermalConductivity<NumericType>& scalar_thermal_conductivity,
      const MassDensity<NumericType>& mass_density,
      const ThermalDiffusivity<NumericType>& thermal_diffusivity);

  /// \brief Constructor. Constructs a specific isobaric heat capacity from a given Prandtl number,
  /// scalar thermal conductivity, and dynamic viscosity using the definition of the Prandtl number.
  constexpr SpecificIsobaricHeatCapacity(
      const PrandtlNumber<NumericType>& prandtl_number,
      const ScalarThermalConductivity<NumericType>& scalar_thermal_conductivity,
      const DynamicViscosity<NumericType>& dynamic_viscosity);

  /// \brief Destructor. Destroys this specific isobaric heat capacity.
  ~SpecificIsobaricHeatCapacity() noexcept = default;

  /// \brief Copy constructor. Constructs a specific isobaric heat capacity by copying another one.
  constexpr SpecificIsobaricHeatCapacity(
      const SpecificIsobaricHeatCapacity<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a specific isobaric heat capacity by copying another one.
  template <typename OtherNumericType>
  explicit constexpr SpecificIsobaricHeatCapacity(
      const SpecificIsobaricHeatCapacity<OtherNumericType>& other)
    : SpecificIsobaricHeatCapacity(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a specific isobaric heat capacity by moving another one.
  constexpr SpecificIsobaricHeatCapacity(
      SpecificIsobaricHeatCapacity<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this specific isobaric heat capacity by copying
  /// another one.
  constexpr SpecificIsobaricHeatCapacity<NumericType>& operator=(
      const SpecificIsobaricHeatCapacity<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this specific isobaric heat capacity by copying
  /// another one.
  template <typename OtherNumericType>
  constexpr SpecificIsobaricHeatCapacity<NumericType>& operator=(
      const SpecificIsobaricHeatCapacity<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this specific isobaric heat capacity by moving
  /// another one.
  constexpr SpecificIsobaricHeatCapacity<NumericType>& operator=(
      SpecificIsobaricHeatCapacity<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a specific isobaric heat capacity of zero.
  static constexpr SpecificIsobaricHeatCapacity<NumericType> Zero() {
    return SpecificIsobaricHeatCapacity<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a specific isobaric heat capacity with a given value expressed in a
  /// given specific heat capacity unit.
  template <Unit::SpecificHeatCapacity Unit>
  static constexpr SpecificIsobaricHeatCapacity<NumericType> Create(const NumericType value) {
    return SpecificIsobaricHeatCapacity<NumericType>{
        ConvertStatically<Unit::SpecificHeatCapacity, Unit, Standard<Unit::SpecificHeatCapacity>>(
            value)};
  }

  constexpr SpecificIsobaricHeatCapacity<NumericType> operator+(
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity) const {
    return SpecificIsobaricHeatCapacity<NumericType>{
        this->value + specific_isobaric_heat_capacity.value};
  }

  constexpr SpecificIsobaricHeatCapacity<NumericType> operator-(
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity) const {
    return SpecificIsobaricHeatCapacity<NumericType>{
        this->value - specific_isobaric_heat_capacity.value};
  }

  constexpr SpecificGasConstant<NumericType> operator-(
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity) const;

  constexpr SpecificIsochoricHeatCapacity<NumericType> operator-(
      const SpecificGasConstant<NumericType>& specific_gas_constant) const;

  constexpr SpecificIsobaricHeatCapacity<NumericType> operator*(const NumericType number) const {
    return SpecificIsobaricHeatCapacity<NumericType>{this->value * number};
  }

  constexpr IsobaricHeatCapacity<NumericType> operator*(const Mass<NumericType>& mass) const {
    return IsobaricHeatCapacity<NumericType>{*this, mass};
  }

  constexpr SpecificIsobaricHeatCapacity<NumericType> operator/(const NumericType number) const {
    return SpecificIsobaricHeatCapacity<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity)
      const noexcept {
    return this->value / specific_isobaric_heat_capacity.value;
  }

  constexpr HeatCapacityRatio<NumericType> operator/(
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity) const {
    return HeatCapacityRatio<NumericType>{*this, specific_isochoric_heat_capacity};
  }

  constexpr SpecificIsochoricHeatCapacity<NumericType> operator/(
      const HeatCapacityRatio<NumericType>& heat_capacity_ratio) const {
    return SpecificIsochoricHeatCapacity<NumericType>{*this, heat_capacity_ratio};
  }

  constexpr void operator+=(
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity) noexcept {
    this->value += specific_isobaric_heat_capacity.value;
  }

  constexpr void operator-=(
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity) noexcept {
    this->value -= specific_isobaric_heat_capacity.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a specific isobaric heat capacity with a given value expressed
  /// in the standard specific heat capacity unit.
  explicit constexpr SpecificIsobaricHeatCapacity(const NumericType value)
    : DimensionalScalar<Unit::SpecificHeatCapacity, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const SpecificIsobaricHeatCapacity<NumericType>& left,
                                 const SpecificIsobaricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const SpecificIsobaricHeatCapacity<NumericType>& left,
                                 const SpecificIsobaricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const SpecificIsobaricHeatCapacity<NumericType>& left,
                                const SpecificIsobaricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const SpecificIsobaricHeatCapacity<NumericType>& left,
                                const SpecificIsobaricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const SpecificIsobaricHeatCapacity<NumericType>& left,
                                 const SpecificIsobaricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const SpecificIsobaricHeatCapacity<NumericType>& left,
                                 const SpecificIsobaricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream,
    const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity) {
  stream << specific_isobaric_heat_capacity.Print();
  return stream;
}

template <typename NumericType>
inline constexpr SpecificIsobaricHeatCapacity<NumericType> operator*(
    const NumericType number,
    const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity) {
  return specific_isobaric_heat_capacity * number;
}

template <typename NumericType>
inline constexpr HeatCapacityRatio<NumericType>::HeatCapacityRatio(
    const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity,
    const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity)
  : HeatCapacityRatio<NumericType>(
      specific_isobaric_heat_capacity.Value() / specific_isochoric_heat_capacity.Value()) {}

template <typename NumericType>
inline constexpr Mass<NumericType>::Mass(
    const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity,
    const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity)
  : Mass<NumericType>(isobaric_heat_capacity.Value() / specific_isobaric_heat_capacity.Value()) {}

template <typename NumericType>
inline constexpr IsobaricHeatCapacity<NumericType>::IsobaricHeatCapacity(
    const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity,
    const Mass<NumericType>& mass)
  : IsobaricHeatCapacity<NumericType>(specific_isobaric_heat_capacity.Value() * mass.Value()) {}

template <typename NumericType>
inline constexpr SpecificIsochoricHeatCapacity<NumericType>::SpecificIsochoricHeatCapacity(
    const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity,
    const HeatCapacityRatio<NumericType>& heat_capacity_ratio)
  : SpecificIsochoricHeatCapacity<NumericType>(
      specific_isobaric_heat_capacity.Value() / heat_capacity_ratio.Value()) {}

template <typename NumericType>
inline constexpr IsobaricHeatCapacity<NumericType> Mass<NumericType>::operator*(
    const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity) const {
  return IsobaricHeatCapacity<NumericType>{specific_isobaric_heat_capacity, *this};
}

template <typename NumericType>
inline constexpr SpecificIsobaricHeatCapacity<NumericType>
HeatCapacityRatio<NumericType>::operator*(
    const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity) const {
  return SpecificIsobaricHeatCapacity<NumericType>{*this, specific_isochoric_heat_capacity};
}

template <typename NumericType>
inline constexpr SpecificIsobaricHeatCapacity<NumericType>
SpecificIsochoricHeatCapacity<NumericType>::operator*(
    const HeatCapacityRatio<NumericType>& heat_capacity_ratio) const {
  return SpecificIsobaricHeatCapacity<NumericType>{heat_capacity_ratio, *this};
}

template <typename NumericType>
inline constexpr SpecificIsobaricHeatCapacity<NumericType>
IsobaricHeatCapacity<NumericType>::operator/(const Mass<NumericType>& mass) const {
  return SpecificIsobaricHeatCapacity<NumericType>{*this, mass};
}

template <typename NumericType>
inline constexpr Mass<NumericType> IsobaricHeatCapacity<NumericType>::operator/(
    const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity) const {
  return Mass<NumericType>{*this, specific_isobaric_heat_capacity};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::SpecificIsobaricHeatCapacity<NumericType>> {
  inline size_t operator()(
      const PhQ::SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity) const {
    return hash<NumericType>()(specific_isobaric_heat_capacity.Value());
  }
};

}  // namespace std

#endif  // PHQ_SPECIFIC_ISOBARIC_HEAT_CAPACITY_HPP
