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

#ifndef PHQ_GAS_CONSTANT_HPP
#define PHQ_GAS_CONSTANT_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "HeatCapacityRatio.hpp"
#include "IsobaricHeatCapacity.hpp"
#include "IsochoricHeatCapacity.hpp"
#include "Unit/HeatCapacity.hpp"

namespace PhQ {

// Forward declaration for class PhQ::GasConstant.
template <typename NumericType>
class SpecificGasConstant;

/// \brief Gas constant of a gas. For the mass-specific gas constant, see PhQ::SpecificGasConstant.
template <typename NumericType = double>
class GasConstant : public DimensionalScalar<Unit::HeatCapacity, NumericType> {
public:
  /// \brief Default constructor. Constructs a gas constant with an uninitialized value.
  GasConstant() = default;

  /// \brief Constructor. Constructs a gas constant with a given value expressed in a given heat
  /// capacity unit.
  GasConstant(const NumericType value, const Unit::HeatCapacity unit)
    : DimensionalScalar<Unit::HeatCapacity, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a gas constant from a given isobaric heat capacity and
  /// isochoric heat capacity using Mayer's relation.
  constexpr GasConstant(const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity,
                        const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity)
    : GasConstant<NumericType>(isobaric_heat_capacity.Value() - isochoric_heat_capacity.Value()) {}

  /// \brief Constructor. Constructs a gas constant from a given isobaric heat capacity and heat
  /// capacity ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr GasConstant(const HeatCapacityRatio<NumericType>& heat_capacity_ratio,
                        const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity)
    : GasConstant<NumericType>(
        (1.0 - 1.0 / heat_capacity_ratio.Value()) * isobaric_heat_capacity.Value()) {}

  /// \brief Constructor. Constructs a gas constant from a given isochoric heat capacity and heat
  /// capacity ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr GasConstant(const HeatCapacityRatio<NumericType>& heat_capacity_ratio,
                        const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity)
    : GasConstant<NumericType>(
        (heat_capacity_ratio.Value() - 1.0) * isochoric_heat_capacity.Value()) {}

  /// \brief Constructor. Constructs a gas constant from a given specific gas constant and mass
  /// using the definition of the specific gas constant.
  constexpr GasConstant(
      const SpecificGasConstant<NumericType>& specific_gas_constant, const Mass<NumericType>& mass);

  /// \brief Destructor. Destroys this gas constant.
  ~GasConstant() noexcept = default;

  /// \brief Copy constructor. Constructs a gas constant by copying another one.
  constexpr GasConstant(const GasConstant<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a gas constant by copying another one.
  template <typename OtherNumericType>
  explicit constexpr GasConstant(const GasConstant<OtherNumericType>& other)
    : GasConstant(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a gas constant by moving another one.
  constexpr GasConstant(GasConstant<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this gas constant by copying another one.
  constexpr GasConstant<NumericType>& operator=(const GasConstant<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this gas constant by copying another one.
  template <typename OtherNumericType>
  constexpr GasConstant<NumericType>& operator=(const GasConstant<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this gas constant by moving another one.
  constexpr GasConstant<NumericType>& operator=(
      GasConstant<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a gas constant of zero.
  static constexpr GasConstant<NumericType> Zero() {
    return GasConstant<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a gas constant with a given value expressed in a given heat capacity
  /// unit.
  template <Unit::HeatCapacity Unit>
  static constexpr GasConstant<NumericType> Create(const NumericType value) {
    return GasConstant<NumericType>{
        ConvertStatically<Unit::HeatCapacity, Unit, Standard<Unit::HeatCapacity>>(value)};
  }

  constexpr GasConstant<NumericType> operator+(const GasConstant<NumericType>& gas_constant) const {
    return GasConstant<NumericType>{this->value + gas_constant.value};
  }

  constexpr IsobaricHeatCapacity<NumericType> operator+(
      const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity) const {
    return IsobaricHeatCapacity<NumericType>{isochoric_heat_capacity, *this};
  }

  constexpr GasConstant<NumericType> operator-(const GasConstant<NumericType>& gas_constant) const {
    return GasConstant<NumericType>{this->value - gas_constant.value};
  }

  constexpr GasConstant<NumericType> operator*(const NumericType number) const {
    return GasConstant<NumericType>{this->value * number};
  }

  constexpr GasConstant<NumericType> operator/(const NumericType number) const {
    return GasConstant<NumericType>{this->value / number};
  }

  constexpr SpecificGasConstant<NumericType> operator/(const Mass<NumericType>& mass) const;

  constexpr Mass<NumericType> operator/(
      const SpecificGasConstant<NumericType>& specific_gas_constant) const;

  constexpr NumericType operator/(const GasConstant<NumericType>& gas_constant) const noexcept {
    return this->value / gas_constant.value;
  }

  constexpr void operator+=(const GasConstant<NumericType>& gas_constant) noexcept {
    this->value += gas_constant.value;
  }

  constexpr void operator-=(const GasConstant<NumericType>& gas_constant) noexcept {
    this->value -= gas_constant.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a gas constant with a given value expressed in the standard
  /// heat capacity unit.
  explicit constexpr GasConstant(const NumericType value)
    : DimensionalScalar<Unit::HeatCapacity, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const GasConstant<NumericType>& left, const GasConstant<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const GasConstant<NumericType>& left, const GasConstant<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const GasConstant<NumericType>& left, const GasConstant<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const GasConstant<NumericType>& left, const GasConstant<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const GasConstant<NumericType>& left, const GasConstant<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const GasConstant<NumericType>& left, const GasConstant<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const GasConstant<NumericType>& gas_constant) {
  stream << gas_constant.Print();
  return stream;
}

template <typename NumericType>
inline constexpr GasConstant<NumericType> operator*(
    const NumericType number, const GasConstant<NumericType>& gas_constant) {
  return gas_constant * number;
}

template <typename NumericType>
inline constexpr HeatCapacityRatio<NumericType>::HeatCapacityRatio(
    const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity,
    const GasConstant<NumericType>& gas_constant)
  : HeatCapacityRatio<NumericType>(
      isobaric_heat_capacity.Value() / (isobaric_heat_capacity.Value() - gas_constant.Value())) {}

template <typename NumericType>
inline constexpr HeatCapacityRatio<NumericType>::HeatCapacityRatio(
    const GasConstant<NumericType>& gas_constant,
    const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity)
  : HeatCapacityRatio<NumericType>(gas_constant.Value() / isochoric_heat_capacity.Value() + 1.0) {}

template <typename NumericType>
inline constexpr IsochoricHeatCapacity<NumericType>::IsochoricHeatCapacity(
    const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity,
    const GasConstant<NumericType>& gas_constant)
  : IsochoricHeatCapacity<NumericType>(isobaric_heat_capacity.Value() - gas_constant.Value()) {}

template <typename NumericType>
inline constexpr IsochoricHeatCapacity<NumericType>::IsochoricHeatCapacity(
    const GasConstant<NumericType>& gas_constant,
    const HeatCapacityRatio<NumericType>& heat_capacity_ratio)
  : IsochoricHeatCapacity<NumericType>(gas_constant.Value() / (heat_capacity_ratio.Value() - 1.0)) {
}

template <typename NumericType>
inline constexpr IsobaricHeatCapacity<NumericType>::IsobaricHeatCapacity(
    const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity,
    const GasConstant<NumericType>& gas_constant)
  : IsobaricHeatCapacity<NumericType>(isochoric_heat_capacity.Value() + gas_constant.Value()) {}

template <typename NumericType>
inline constexpr IsobaricHeatCapacity<NumericType>::IsobaricHeatCapacity(
    const HeatCapacityRatio<NumericType>& heat_capacity_ratio,
    const GasConstant<NumericType>& gas_constant)
  : IsobaricHeatCapacity<NumericType>(
      heat_capacity_ratio.Value() * gas_constant.Value() / (heat_capacity_ratio.Value() - 1.0)) {}

template <typename NumericType>
inline constexpr IsobaricHeatCapacity<NumericType> IsochoricHeatCapacity<NumericType>::operator+(
    const GasConstant<NumericType>& gas_constant) const {
  return IsobaricHeatCapacity<NumericType>{*this, gas_constant};
}

template <typename NumericType>
inline constexpr GasConstant<NumericType> IsobaricHeatCapacity<NumericType>::operator-(
    const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity) const {
  return GasConstant<NumericType>{*this, isochoric_heat_capacity};
}

template <typename NumericType>
inline constexpr IsochoricHeatCapacity<NumericType> IsobaricHeatCapacity<NumericType>::operator-(
    const GasConstant<NumericType>& gas_constant) const {
  return IsochoricHeatCapacity<NumericType>{*this, gas_constant};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::GasConstant<NumericType>> {
  inline size_t operator()(const PhQ::GasConstant<NumericType>& gas_constant) const {
    return hash<NumericType>()(gas_constant.Value());
  }
};

}  // namespace std

#endif  // PHQ_GAS_CONSTANT_HPP
