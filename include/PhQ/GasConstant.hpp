// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
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
template <typename Number>
class SpecificGasConstant;

/// \brief Gas constant of a gas. Not to be confused with the molar gas constant or the specific gas
/// constant.
template <typename Number = double>
class GasConstant : public DimensionalScalar<Unit::HeatCapacity, Number> {
public:
  /// \brief Default constructor. Constructs a gas constant with an uninitialized value.
  GasConstant() = default;

  /// \brief Constructor. Constructs a gas constant with a given value expressed in a given heat
  /// capacity unit.
  GasConstant(const Number value, const Unit::HeatCapacity unit)
    : DimensionalScalar<Unit::HeatCapacity, Number>(value, unit) {}

  /// \brief Constructor. Constructs a gas constant from a given isobaric heat capacity and
  /// isochoric heat capacity using Mayer's relation.
  constexpr GasConstant(const IsobaricHeatCapacity<Number>& isobaric_heat_capacity,
                        const IsochoricHeatCapacity<Number>& isochoric_heat_capacity)
    : GasConstant<Number>(isobaric_heat_capacity.Value() - isochoric_heat_capacity.Value()) {}

  /// \brief Constructor. Constructs a gas constant from a given isobaric heat capacity and heat
  /// capacity ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr GasConstant(const HeatCapacityRatio<Number>& heat_capacity_ratio,
                        const IsobaricHeatCapacity<Number>& isobaric_heat_capacity)
    : GasConstant<Number>(
        (1.0 - 1.0 / heat_capacity_ratio.Value()) * isobaric_heat_capacity.Value()) {}

  /// \brief Constructor. Constructs a gas constant from a given isochoric heat capacity and heat
  /// capacity ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr GasConstant(const HeatCapacityRatio<Number>& heat_capacity_ratio,
                        const IsochoricHeatCapacity<Number>& isochoric_heat_capacity)
    : GasConstant<Number>((heat_capacity_ratio.Value() - 1.0) * isochoric_heat_capacity.Value()) {}

  /// \brief Constructor. Constructs a gas constant from a given specific gas constant and mass
  /// using the definition of the specific gas constant.
  constexpr GasConstant(
      const SpecificGasConstant<Number>& specific_gas_constant, const Mass<Number>& mass);

  /// \brief Destructor. Destroys this gas constant.
  ~GasConstant() noexcept = default;

  /// \brief Copy constructor. Constructs a gas constant by copying another one.
  constexpr GasConstant(const GasConstant<Number>& other) = default;

  /// \brief Copy constructor. Constructs a gas constant by copying another one.
  template <typename OtherNumber>
  explicit constexpr GasConstant(const GasConstant<OtherNumber>& other)
    : GasConstant(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a gas constant by moving another one.
  constexpr GasConstant(GasConstant<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this gas constant by copying another one.
  constexpr GasConstant<Number>& operator=(const GasConstant<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this gas constant by copying another one.
  template <typename OtherNumber>
  constexpr GasConstant<Number>& operator=(const GasConstant<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this gas constant by moving another one.
  constexpr GasConstant<Number>& operator=(GasConstant<Number>&& other) noexcept = default;

  /// \brief Statically creates a gas constant of zero.
  static constexpr GasConstant<Number> Zero() {
    return GasConstant<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a gas constant with a given value expressed in a given heat capacity
  /// unit.
  template <Unit::HeatCapacity Unit>
  static constexpr GasConstant<Number> Create(const Number value) {
    return GasConstant<Number>{
        StaticConvertCopy<Unit::HeatCapacity, Unit, Standard<Unit::HeatCapacity>>(value)};
  }

  constexpr GasConstant<Number> operator+(const GasConstant<Number>& gas_constant) const {
    return GasConstant<Number>{this->value + gas_constant.value};
  }

  constexpr IsobaricHeatCapacity<Number> operator+(
      const IsochoricHeatCapacity<Number>& isochoric_heat_capacity) const {
    return IsobaricHeatCapacity<Number>{isochoric_heat_capacity, *this};
  }

  constexpr GasConstant<Number> operator-(const GasConstant<Number>& gas_constant) const {
    return GasConstant<Number>{this->value - gas_constant.value};
  }

  constexpr GasConstant<Number> operator*(const Number number) const {
    return GasConstant<Number>{this->value * number};
  }

  constexpr GasConstant<Number> operator/(const Number number) const {
    return GasConstant<Number>{this->value / number};
  }

  constexpr SpecificGasConstant<Number> operator/(const Mass<Number>& mass) const;

  constexpr Mass<Number> operator/(const SpecificGasConstant<Number>& specific_gas_constant) const;

  constexpr Number operator/(const GasConstant<Number>& gas_constant) const noexcept {
    return this->value / gas_constant.value;
  }

  constexpr void operator+=(const GasConstant<Number>& gas_constant) noexcept {
    this->value += gas_constant.value;
  }

  constexpr void operator-=(const GasConstant<Number>& gas_constant) noexcept {
    this->value -= gas_constant.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a gas constant with a given value expressed in the standard
  /// heat capacity unit.
  explicit constexpr GasConstant(const Number value)
    : DimensionalScalar<Unit::HeatCapacity, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const GasConstant<Number>& left, const GasConstant<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const GasConstant<Number>& left, const GasConstant<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const GasConstant<Number>& left, const GasConstant<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const GasConstant<Number>& left, const GasConstant<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const GasConstant<Number>& left, const GasConstant<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const GasConstant<Number>& left, const GasConstant<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const GasConstant<Number>& gas_constant) {
  stream << gas_constant.Print();
  return stream;
}

template <typename Number>
inline constexpr GasConstant<Number> operator*(
    const Number number, const GasConstant<Number>& gas_constant) {
  return gas_constant * number;
}

template <typename Number>
inline constexpr HeatCapacityRatio<Number>::HeatCapacityRatio(
    const IsobaricHeatCapacity<Number>& isobaric_heat_capacity,
    const GasConstant<Number>& gas_constant)
  : HeatCapacityRatio<Number>(
      isobaric_heat_capacity.Value() / (isobaric_heat_capacity.Value() - gas_constant.Value())) {}

template <typename Number>
inline constexpr HeatCapacityRatio<Number>::HeatCapacityRatio(
    const GasConstant<Number>& gas_constant,
    const IsochoricHeatCapacity<Number>& isochoric_heat_capacity)
  : HeatCapacityRatio<Number>(gas_constant.Value() / isochoric_heat_capacity.Value() + 1.0) {}

template <typename Number>
inline constexpr IsochoricHeatCapacity<Number>::IsochoricHeatCapacity(
    const IsobaricHeatCapacity<Number>& isobaric_heat_capacity,
    const GasConstant<Number>& gas_constant)
  : IsochoricHeatCapacity<Number>(isobaric_heat_capacity.Value() - gas_constant.Value()) {}

template <typename Number>
inline constexpr IsochoricHeatCapacity<Number>::IsochoricHeatCapacity(
    const GasConstant<Number>& gas_constant, const HeatCapacityRatio<Number>& heat_capacity_ratio)
  : IsochoricHeatCapacity<Number>(gas_constant.Value() / (heat_capacity_ratio.Value() - 1.0)) {}

template <typename Number>
inline constexpr IsobaricHeatCapacity<Number>::IsobaricHeatCapacity(
    const IsochoricHeatCapacity<Number>& isochoric_heat_capacity,
    const GasConstant<Number>& gas_constant)
  : IsobaricHeatCapacity<Number>(isochoric_heat_capacity.Value() + gas_constant.Value()) {}

template <typename Number>
inline constexpr IsobaricHeatCapacity<Number>::IsobaricHeatCapacity(
    const HeatCapacityRatio<Number>& heat_capacity_ratio, const GasConstant<Number>& gas_constant)
  : IsobaricHeatCapacity<Number>(
      heat_capacity_ratio.Value() * gas_constant.Value() / (heat_capacity_ratio.Value() - 1.0)) {}

template <typename Number>
inline constexpr IsobaricHeatCapacity<Number> IsochoricHeatCapacity<Number>::operator+(
    const GasConstant<Number>& gas_constant) const {
  return IsobaricHeatCapacity<Number>{*this, gas_constant};
}

template <typename Number>
inline constexpr GasConstant<Number> IsobaricHeatCapacity<Number>::operator-(
    const IsochoricHeatCapacity<Number>& isochoric_heat_capacity) const {
  return GasConstant<Number>{*this, isochoric_heat_capacity};
}

template <typename Number>
inline constexpr IsochoricHeatCapacity<Number> IsobaricHeatCapacity<Number>::operator-(
    const GasConstant<Number>& gas_constant) const {
  return IsochoricHeatCapacity<Number>{*this, gas_constant};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::GasConstant<Number>> {
  inline size_t operator()(const PhQ::GasConstant<Number>& gas_constant) const {
    return hash<Number>()(gas_constant.Value());
  }
};

}  // namespace std

#endif  // PHQ_GAS_CONSTANT_HPP
