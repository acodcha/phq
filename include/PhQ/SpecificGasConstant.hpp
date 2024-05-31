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

#ifndef PHQ_SPECIFIC_GAS_CONSTANT_HPP
#define PHQ_SPECIFIC_GAS_CONSTANT_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "GasConstant.hpp"
#include "HeatCapacityRatio.hpp"
#include "Mass.hpp"
#include "SpecificIsobaricHeatCapacity.hpp"
#include "SpecificIsochoricHeatCapacity.hpp"
#include "Unit/SpecificHeatCapacity.hpp"

namespace PhQ {

/// \brief Mass-specific gas constant of a gas. Gas constant per unit mass; see PhQ::GasConstant and
/// PhQ::Mass. PhQ::Mass.
template <typename NumericType = double>
class SpecificGasConstant : public DimensionalScalar<Unit::SpecificHeatCapacity, NumericType> {
public:
  /// \brief Default constructor. Constructs a specific gas constant with an uninitialized value.
  SpecificGasConstant() = default;

  /// \brief Constructor. Constructs a specific gas constant with a given value expressed in a given
  /// specific heat capacity unit.
  SpecificGasConstant(const NumericType value, const Unit::SpecificHeatCapacity unit)
    : DimensionalScalar<Unit::SpecificHeatCapacity, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a specific gas constant from a given specific isobaric heat
  /// capacity and specific isochoric heat capacity using Mayer's relation.
  constexpr SpecificGasConstant(
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity,
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity)
    : SpecificGasConstant<NumericType>(
        specific_isobaric_heat_capacity.Value() - specific_isochoric_heat_capacity.Value()) {}

  /// \brief Constructor. Constructs a specific gas constant from a given specific isobaric heat
  /// capacity and heat capacity ratio using the definition of the heat capacity ratio and Mayer's
  /// relation.
  constexpr SpecificGasConstant(
      const HeatCapacityRatio<NumericType>& heat_capacity_ratio,
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity)
    : SpecificGasConstant<NumericType>(
        (1.0 - 1.0 / heat_capacity_ratio.Value()) * specific_isobaric_heat_capacity.Value()) {}

  /// \brief Constructor. Constructs a specific gas constant from a given specific isochoric heat
  /// capacity and heat capacity ratio using the definition of the heat capacity ratio and Mayer's
  /// relation.
  constexpr SpecificGasConstant(
      const HeatCapacityRatio<NumericType>& heat_capacity_ratio,
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity)
    : SpecificGasConstant<NumericType>(
        (heat_capacity_ratio.Value() - 1.0) * specific_isochoric_heat_capacity.Value()) {}

  /// \brief Constructor. Constructs a specific gas constant from a given gas constant and mass
  /// using the definition of the specific gas constant.
  constexpr SpecificGasConstant(
      const GasConstant<NumericType>& gas_constant, const Mass<NumericType>& mass)
    : SpecificGasConstant<NumericType>(gas_constant.Value() / mass.Value()) {}

  /// \brief Destructor. Destroys this specific gas constant.
  ~SpecificGasConstant() noexcept = default;

  /// \brief Copy constructor. Constructs a specific gas constant by copying another one.
  constexpr SpecificGasConstant(const SpecificGasConstant<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a specific gas constant by copying another one.
  template <typename OtherNumericType>
  explicit constexpr SpecificGasConstant(const SpecificGasConstant<OtherNumericType>& other)
    : SpecificGasConstant(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a specific gas constant by moving another one.
  constexpr SpecificGasConstant(SpecificGasConstant<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this specific gas constant by copying another one.
  constexpr SpecificGasConstant<NumericType>& operator=(
      const SpecificGasConstant<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this specific gas constant by copying another one.
  template <typename OtherNumericType>
  constexpr SpecificGasConstant<NumericType>& operator=(
      const SpecificGasConstant<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this specific gas constant by moving another one.
  constexpr SpecificGasConstant<NumericType>& operator=(
      SpecificGasConstant<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a specific gas constant of zero.
  static constexpr SpecificGasConstant<NumericType> Zero() {
    return SpecificGasConstant<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a specific gas constant with a given value expressed in a given
  /// specific heat capacity unit.
  template <Unit::SpecificHeatCapacity Unit>
  static constexpr SpecificGasConstant<NumericType> Create(const NumericType value) {
    return SpecificGasConstant<NumericType>{
        ConvertStatically<Unit::SpecificHeatCapacity, Unit, Standard<Unit::SpecificHeatCapacity>>(
            value)};
  }

  constexpr SpecificGasConstant<NumericType> operator+(
      const SpecificGasConstant<NumericType>& specific_gas_constant) const {
    return SpecificGasConstant<NumericType>{this->value + specific_gas_constant.value};
  }

  constexpr SpecificIsobaricHeatCapacity<NumericType> operator+(
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity) const {
    return SpecificIsobaricHeatCapacity<NumericType>{specific_isochoric_heat_capacity, *this};
  }

  constexpr SpecificGasConstant<NumericType> operator-(
      const SpecificGasConstant<NumericType>& specific_gas_constant) const {
    return SpecificGasConstant<NumericType>{this->value - specific_gas_constant.value};
  }

  constexpr SpecificGasConstant<NumericType> operator*(const NumericType number) const {
    return SpecificGasConstant<NumericType>{this->value * number};
  }

  constexpr GasConstant<NumericType> operator*(const Mass<NumericType>& mass) const {
    return GasConstant<NumericType>{*this, mass};
  }

  constexpr SpecificGasConstant<NumericType> operator/(const NumericType number) const {
    return SpecificGasConstant<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const SpecificGasConstant<NumericType>& specific_gas_constant) const noexcept {
    return this->value / specific_gas_constant.value;
  }

  constexpr void operator+=(
      const SpecificGasConstant<NumericType>& specific_gas_constant) noexcept {
    this->value += specific_gas_constant.value;
  }

  constexpr void operator-=(
      const SpecificGasConstant<NumericType>& specific_gas_constant) noexcept {
    this->value -= specific_gas_constant.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a specific gas constant with a given value expressed in the
  /// standard specific heat capacity unit.
  explicit constexpr SpecificGasConstant(const NumericType value)
    : DimensionalScalar<Unit::SpecificHeatCapacity, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const SpecificGasConstant<NumericType>& left,
                                 const SpecificGasConstant<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const SpecificGasConstant<NumericType>& left,
                                 const SpecificGasConstant<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const SpecificGasConstant<NumericType>& left,
                                const SpecificGasConstant<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const SpecificGasConstant<NumericType>& left,
                                const SpecificGasConstant<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const SpecificGasConstant<NumericType>& left,
                                 const SpecificGasConstant<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const SpecificGasConstant<NumericType>& left,
                                 const SpecificGasConstant<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const SpecificGasConstant<NumericType>& specific_gas_constant) {
  stream << specific_gas_constant.Print();
  return stream;
}

template <typename NumericType>
inline constexpr SpecificGasConstant<NumericType> operator*(
    const NumericType number, const SpecificGasConstant<NumericType>& specific_gas_constant) {
  return specific_gas_constant * number;
}

template <typename NumericType>
inline constexpr HeatCapacityRatio<NumericType>::HeatCapacityRatio(
    const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity,
    const SpecificGasConstant<NumericType>& specific_gas_constant)
  : HeatCapacityRatio<NumericType>(
      specific_isobaric_heat_capacity.Value()
      / (specific_isobaric_heat_capacity.Value() - specific_gas_constant.Value())) {}

template <typename NumericType>
inline constexpr HeatCapacityRatio<NumericType>::HeatCapacityRatio(
    const SpecificGasConstant<NumericType>& specific_gas_constant,
    const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity)
  : HeatCapacityRatio<NumericType>(
      specific_gas_constant.Value() / specific_isochoric_heat_capacity.Value() + 1.0) {}

template <typename NumericType>
inline constexpr Mass<NumericType>::Mass(
    const GasConstant<NumericType>& gas_constant,
    const SpecificGasConstant<NumericType>& specific_gas_constant)
  : Mass<NumericType>(gas_constant.Value() / specific_gas_constant.Value()) {}

template <typename NumericType>
inline constexpr GasConstant<NumericType>::GasConstant(
    const SpecificGasConstant<NumericType>& specific_gas_constant, const Mass<NumericType>& mass)
  : GasConstant<NumericType>(specific_gas_constant.Value() * mass.Value()) {}

template <typename NumericType>
inline constexpr SpecificIsochoricHeatCapacity<NumericType>::SpecificIsochoricHeatCapacity(
    const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity,
    const SpecificGasConstant<NumericType>& specific_gas_constant)
  : SpecificIsochoricHeatCapacity<NumericType>(
      specific_isobaric_heat_capacity.Value() - specific_gas_constant.Value()) {}

template <typename NumericType>
inline constexpr SpecificIsochoricHeatCapacity<NumericType>::SpecificIsochoricHeatCapacity(
    const SpecificGasConstant<NumericType>& specific_gas_constant,
    const HeatCapacityRatio<NumericType>& heat_capacity_ratio)
  : SpecificIsochoricHeatCapacity<NumericType>(
      specific_gas_constant.Value() / (heat_capacity_ratio.Value() - 1.0)) {}

template <typename NumericType>
inline constexpr SpecificIsobaricHeatCapacity<NumericType>::SpecificIsobaricHeatCapacity(
    const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity,
    const SpecificGasConstant<NumericType>& specific_gas_constant)
  : SpecificIsobaricHeatCapacity<NumericType>(
      specific_isochoric_heat_capacity.Value() + specific_gas_constant.Value()) {}

template <typename NumericType>
inline constexpr SpecificIsobaricHeatCapacity<NumericType>::SpecificIsobaricHeatCapacity(
    const HeatCapacityRatio<NumericType>& heat_capacity_ratio,
    const SpecificGasConstant<NumericType>& specific_gas_constant)
  : SpecificIsobaricHeatCapacity<NumericType>(
      heat_capacity_ratio.Value() * specific_gas_constant.Value()
      / (heat_capacity_ratio.Value() - 1.0)) {}

template <typename NumericType>
inline constexpr SpecificIsobaricHeatCapacity<NumericType>
SpecificIsochoricHeatCapacity<NumericType>::operator+(
    const SpecificGasConstant<NumericType>& specific_gas_constant) const {
  return SpecificIsobaricHeatCapacity<NumericType>{*this, specific_gas_constant};
}

template <typename NumericType>
inline constexpr SpecificGasConstant<NumericType>
SpecificIsobaricHeatCapacity<NumericType>::operator-(
    const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity) const {
  return SpecificGasConstant<NumericType>{*this, specific_isochoric_heat_capacity};
}

template <typename NumericType>
inline constexpr SpecificIsochoricHeatCapacity<NumericType>
SpecificIsobaricHeatCapacity<NumericType>::operator-(
    const SpecificGasConstant<NumericType>& specific_gas_constant) const {
  return SpecificIsochoricHeatCapacity<NumericType>{*this, specific_gas_constant};
}

template <typename NumericType>
inline constexpr GasConstant<NumericType> Mass<NumericType>::operator*(
    const SpecificGasConstant<NumericType>& specific_gas_constant) const {
  return GasConstant<NumericType>{specific_gas_constant, *this};
}

template <typename NumericType>
inline constexpr SpecificGasConstant<NumericType> GasConstant<NumericType>::operator/(
    const Mass<NumericType>& mass) const {
  return SpecificGasConstant<NumericType>{*this, mass};
}

template <typename NumericType>
inline constexpr Mass<NumericType> GasConstant<NumericType>::operator/(
    const SpecificGasConstant<NumericType>& specific_gas_constant) const {
  return Mass<NumericType>{*this, specific_gas_constant};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::SpecificGasConstant<NumericType>> {
  inline size_t operator()(
      const PhQ::SpecificGasConstant<NumericType>& specific_gas_constant) const {
    return hash<NumericType>()(specific_gas_constant.Value());
  }
};

}  // namespace std

#endif  // PHQ_SPECIFIC_GAS_CONSTANT_HPP
