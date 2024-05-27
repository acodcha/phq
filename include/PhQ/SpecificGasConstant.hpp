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
template <typename Number = double>
class SpecificGasConstant : public DimensionalScalar<Unit::SpecificHeatCapacity, Number> {
public:
  /// \brief Default constructor. Constructs a specific gas constant with an uninitialized value.
  SpecificGasConstant() = default;

  /// \brief Constructor. Constructs a specific gas constant with a given value expressed in a given
  /// specific heat capacity unit.
  SpecificGasConstant(const Number value, const Unit::SpecificHeatCapacity unit)
    : DimensionalScalar<Unit::SpecificHeatCapacity, Number>(value, unit) {}

  /// \brief Constructor. Constructs a specific gas constant from a given specific isobaric heat
  /// capacity and specific isochoric heat capacity using Mayer's relation.
  constexpr SpecificGasConstant(
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity)
    : SpecificGasConstant<Number>(
        specific_isobaric_heat_capacity.Value() - specific_isochoric_heat_capacity.Value()) {}

  /// \brief Constructor. Constructs a specific gas constant from a given specific isobaric heat
  /// capacity and heat capacity ratio using the definition of the heat capacity ratio and Mayer's
  /// relation.
  constexpr SpecificGasConstant(
      const HeatCapacityRatio<Number>& heat_capacity_ratio,
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity)
    : SpecificGasConstant<Number>(
        (1.0 - 1.0 / heat_capacity_ratio.Value()) * specific_isobaric_heat_capacity.Value()) {}

  /// \brief Constructor. Constructs a specific gas constant from a given specific isochoric heat
  /// capacity and heat capacity ratio using the definition of the heat capacity ratio and Mayer's
  /// relation.
  constexpr SpecificGasConstant(
      const HeatCapacityRatio<Number>& heat_capacity_ratio,
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity)
    : SpecificGasConstant<Number>(
        (heat_capacity_ratio.Value() - 1.0) * specific_isochoric_heat_capacity.Value()) {}

  /// \brief Constructor. Constructs a specific gas constant from a given gas constant and mass
  /// using the definition of the specific gas constant.
  constexpr SpecificGasConstant(const GasConstant<Number>& gas_constant, const Mass<Number>& mass)
    : SpecificGasConstant<Number>(gas_constant.Value() / mass.Value()) {}

  /// \brief Destructor. Destroys this specific gas constant.
  ~SpecificGasConstant() noexcept = default;

  /// \brief Copy constructor. Constructs a specific gas constant by copying another one.
  constexpr SpecificGasConstant(const SpecificGasConstant<Number>& other) = default;

  /// \brief Copy constructor. Constructs a specific gas constant by copying another one.
  template <typename OtherNumber>
  explicit constexpr SpecificGasConstant(const SpecificGasConstant<OtherNumber>& other)
    : SpecificGasConstant(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a specific gas constant by moving another one.
  constexpr SpecificGasConstant(SpecificGasConstant<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this specific gas constant by copying another one.
  constexpr SpecificGasConstant<Number>& operator=(
      const SpecificGasConstant<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this specific gas constant by copying another one.
  template <typename OtherNumber>
  constexpr SpecificGasConstant<Number>& operator=(const SpecificGasConstant<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this specific gas constant by moving another one.
  constexpr SpecificGasConstant<Number>& operator=(
      SpecificGasConstant<Number>&& other) noexcept = default;

  /// \brief Statically creates a specific gas constant of zero.
  static constexpr SpecificGasConstant<Number> Zero() {
    return SpecificGasConstant<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a specific gas constant with a given value expressed in a given
  /// specific heat capacity unit.
  template <Unit::SpecificHeatCapacity Unit>
  static constexpr SpecificGasConstant<Number> Create(const Number value) {
    return SpecificGasConstant<Number>{
        StaticConvertCopy<Unit::SpecificHeatCapacity, Unit, Standard<Unit::SpecificHeatCapacity>>(
            value)};
  }

  constexpr SpecificGasConstant<Number> operator+(
      const SpecificGasConstant<Number>& specific_gas_constant) const {
    return SpecificGasConstant<Number>{this->value + specific_gas_constant.value};
  }

  constexpr SpecificIsobaricHeatCapacity<Number> operator+(
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) const {
    return SpecificIsobaricHeatCapacity<Number>{specific_isochoric_heat_capacity, *this};
  }

  constexpr SpecificGasConstant<Number> operator-(
      const SpecificGasConstant<Number>& specific_gas_constant) const {
    return SpecificGasConstant<Number>{this->value - specific_gas_constant.value};
  }

  constexpr SpecificGasConstant<Number> operator*(const Number number) const {
    return SpecificGasConstant<Number>{this->value * number};
  }

  constexpr GasConstant<Number> operator*(const Mass<Number>& mass) const {
    return GasConstant<Number>{*this, mass};
  }

  constexpr SpecificGasConstant<Number> operator/(const Number number) const {
    return SpecificGasConstant<Number>{this->value / number};
  }

  constexpr Number operator/(
      const SpecificGasConstant<Number>& specific_gas_constant) const noexcept {
    return this->value / specific_gas_constant.value;
  }

  constexpr void operator+=(const SpecificGasConstant<Number>& specific_gas_constant) noexcept {
    this->value += specific_gas_constant.value;
  }

  constexpr void operator-=(const SpecificGasConstant<Number>& specific_gas_constant) noexcept {
    this->value -= specific_gas_constant.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a specific gas constant with a given value expressed in the
  /// standard specific heat capacity unit.
  explicit constexpr SpecificGasConstant(const Number value)
    : DimensionalScalar<Unit::SpecificHeatCapacity, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const SpecificGasConstant<Number>& left, const SpecificGasConstant<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const SpecificGasConstant<Number>& left, const SpecificGasConstant<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const SpecificGasConstant<Number>& left, const SpecificGasConstant<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const SpecificGasConstant<Number>& left, const SpecificGasConstant<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const SpecificGasConstant<Number>& left, const SpecificGasConstant<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const SpecificGasConstant<Number>& left, const SpecificGasConstant<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const SpecificGasConstant<Number>& specific_gas_constant) {
  stream << specific_gas_constant.Print();
  return stream;
}

template <typename Number>
inline constexpr SpecificGasConstant<Number> operator*(
    const Number number, const SpecificGasConstant<Number>& specific_gas_constant) {
  return specific_gas_constant * number;
}

template <typename Number>
inline constexpr HeatCapacityRatio<Number>::HeatCapacityRatio(
    const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
    const SpecificGasConstant<Number>& specific_gas_constant)
  : HeatCapacityRatio<Number>(
      specific_isobaric_heat_capacity.Value()
      / (specific_isobaric_heat_capacity.Value() - specific_gas_constant.Value())) {}

template <typename Number>
inline constexpr HeatCapacityRatio<Number>::HeatCapacityRatio(
    const SpecificGasConstant<Number>& specific_gas_constant,
    const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity)
  : HeatCapacityRatio<Number>(
      specific_gas_constant.Value() / specific_isochoric_heat_capacity.Value() + 1.0) {}

template <typename Number>
inline constexpr Mass<Number>::Mass(const GasConstant<Number>& gas_constant,
                                    const SpecificGasConstant<Number>& specific_gas_constant)
  : Mass<Number>(gas_constant.Value() / specific_gas_constant.Value()) {}

template <typename Number>
inline constexpr GasConstant<Number>::GasConstant(
    const SpecificGasConstant<Number>& specific_gas_constant, const Mass<Number>& mass)
  : GasConstant<Number>(specific_gas_constant.Value() * mass.Value()) {}

template <typename Number>
inline constexpr SpecificIsochoricHeatCapacity<Number>::SpecificIsochoricHeatCapacity(
    const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
    const SpecificGasConstant<Number>& specific_gas_constant)
  : SpecificIsochoricHeatCapacity<Number>(
      specific_isobaric_heat_capacity.Value() - specific_gas_constant.Value()) {}

template <typename Number>
inline constexpr SpecificIsochoricHeatCapacity<Number>::SpecificIsochoricHeatCapacity(
    const SpecificGasConstant<Number>& specific_gas_constant,
    const HeatCapacityRatio<Number>& heat_capacity_ratio)
  : SpecificIsochoricHeatCapacity<Number>(
      specific_gas_constant.Value() / (heat_capacity_ratio.Value() - 1.0)) {}

template <typename Number>
inline constexpr SpecificIsobaricHeatCapacity<Number>::SpecificIsobaricHeatCapacity(
    const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity,
    const SpecificGasConstant<Number>& specific_gas_constant)
  : SpecificIsobaricHeatCapacity<Number>(
      specific_isochoric_heat_capacity.Value() + specific_gas_constant.Value()) {}

template <typename Number>
inline constexpr SpecificIsobaricHeatCapacity<Number>::SpecificIsobaricHeatCapacity(
    const HeatCapacityRatio<Number>& heat_capacity_ratio,
    const SpecificGasConstant<Number>& specific_gas_constant)
  : SpecificIsobaricHeatCapacity<Number>(heat_capacity_ratio.Value() * specific_gas_constant.Value()
                                         / (heat_capacity_ratio.Value() - 1.0)) {}

template <typename Number>
inline constexpr SpecificIsobaricHeatCapacity<Number>
SpecificIsochoricHeatCapacity<Number>::operator+(
    const SpecificGasConstant<Number>& specific_gas_constant) const {
  return SpecificIsobaricHeatCapacity<Number>{*this, specific_gas_constant};
}

template <typename Number>
inline constexpr SpecificGasConstant<Number> SpecificIsobaricHeatCapacity<Number>::operator-(
    const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) const {
  return SpecificGasConstant<Number>{*this, specific_isochoric_heat_capacity};
}

template <typename Number>
inline constexpr SpecificIsochoricHeatCapacity<Number>
SpecificIsobaricHeatCapacity<Number>::operator-(
    const SpecificGasConstant<Number>& specific_gas_constant) const {
  return SpecificIsochoricHeatCapacity<Number>{*this, specific_gas_constant};
}

template <typename Number>
inline constexpr GasConstant<Number> Mass<Number>::operator*(
    const SpecificGasConstant<Number>& specific_gas_constant) const {
  return GasConstant<Number>{specific_gas_constant, *this};
}

template <typename Number>
inline constexpr SpecificGasConstant<Number> GasConstant<Number>::operator/(
    const Mass<Number>& mass) const {
  return SpecificGasConstant<Number>{*this, mass};
}

template <typename Number>
inline constexpr Mass<Number> GasConstant<Number>::operator/(
    const SpecificGasConstant<Number>& specific_gas_constant) const {
  return Mass<Number>{*this, specific_gas_constant};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::SpecificGasConstant<Number>> {
  inline size_t operator()(const PhQ::SpecificGasConstant<Number>& specific_gas_constant) const {
    return hash<Number>()(specific_gas_constant.Value());
  }
};

}  // namespace std

#endif  // PHQ_SPECIFIC_GAS_CONSTANT_HPP
