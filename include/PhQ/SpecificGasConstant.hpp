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

// Specific gas constant of a gas. Gas constant per unit mass.
template <typename Number = double>
class SpecificGasConstant : public DimensionalScalar<Unit::SpecificHeatCapacity, Number> {
public:
  // Default constructor. Constructs a specific gas constant with an uninitialized value.
  SpecificGasConstant() = default;

  // Constructor. Constructs a specific gas constant with a given value expressed in a given
  // specific heat capacity unit.
  SpecificGasConstant(const Number value, const Unit::SpecificHeatCapacity unit)
    : DimensionalScalar<Unit::SpecificHeatCapacity, Number>(value, unit) {}

  // Constructor. Constructs a specific gas constant from a given specific isobaric heat capacity
  // and specific isochoric heat capacity using Mayer's relation.
  constexpr SpecificGasConstant(
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity)
    : SpecificGasConstant<Number>(
        specific_isobaric_heat_capacity.Value() - specific_isochoric_heat_capacity.Value()) {}

  // Constructor. Constructs a specific gas constant from a given specific isobaric heat capacity
  // and heat capacity ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr SpecificGasConstant(
      const HeatCapacityRatio<Number>& heat_capacity_ratio,
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity)
    : SpecificGasConstant<Number>(
        (1.0 - 1.0 / heat_capacity_ratio.Value()) * specific_isobaric_heat_capacity.Value()) {}

  // Constructor. Constructs a specific gas constant from a given specific isochoric heat capacity
  // and heat capacity ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr SpecificGasConstant(
      const HeatCapacityRatio<Number>& heat_capacity_ratio,
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity)
    : SpecificGasConstant<Number>(
        (heat_capacity_ratio.Value() - 1.0) * specific_isochoric_heat_capacity.Value()) {}

  // Constructor. Constructs a specific gas constant from a given gas constant and mass using the
  // definition of the specific gas constant.
  constexpr SpecificGasConstant(const GasConstant<Number>& gas_constant, const Mass<Number>& mass)
    : SpecificGasConstant<Number>(gas_constant.Value() / mass.Value()) {}

  // Destructor. Destroys this specific gas constant.
  ~SpecificGasConstant() noexcept = default;

  // Copy constructor. Constructs a specific gas constant by copying another one.
  constexpr SpecificGasConstant(const SpecificGasConstant<Number>& other) = default;

  // Copy constructor. Constructs a specific gas constant by copying another one.
  template <typename OtherNumber>
  explicit constexpr SpecificGasConstant(const SpecificGasConstant<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a specific gas constant by moving another one.
  constexpr SpecificGasConstant(SpecificGasConstant<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this specific gas constant by copying another one.
  constexpr SpecificGasConstant<Number>& operator=(
      const SpecificGasConstant<Number>& other) = default;

  // Copy assignment operator. Assigns this specific gas constant by copying another one.
  template <typename OtherNumber>
  constexpr SpecificGasConstant<Number>& operator=(const SpecificGasConstant<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this specific gas constant by moving another one.
  constexpr SpecificGasConstant<Number>& operator=(
      SpecificGasConstant<Number>&& other) noexcept = default;

  // Statically creates a specific gas constant of zero.
  static constexpr SpecificGasConstant<Number> Zero() {
    return SpecificGasConstant<Number>{static_cast<Number>(0)};
  }

  // Statically creates a specific gas constant with a given value expressed in a given specific
  // heat capacity unit.
  template <Unit::SpecificHeatCapacity Unit>
  static constexpr SpecificGasConstant<Number> Create(const Number value) {
    return SpecificGasConstant<Number>{
        StaticConvertCopy<Unit::SpecificHeatCapacity, Unit, Standard<Unit::SpecificHeatCapacity>>(
            value)};
  }

  constexpr SpecificGasConstant<Number> operator+(
      const SpecificGasConstant<Number>& specific_gas_constant) const {
    return SpecificGasConstant<Number>{value + specific_gas_constant.value};
  }

  constexpr SpecificIsobaricHeatCapacity<Number> operator+(
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) const {
    return SpecificIsobaricHeatCapacity<Number>{specific_isochoric_heat_capacity, *this};
  }

  constexpr SpecificGasConstant<Number> operator-(
      const SpecificGasConstant<Number>& specific_gas_constant) const {
    return SpecificGasConstant<Number>{value - specific_gas_constant.value};
  }

  constexpr SpecificGasConstant<Number> operator*(const Number number) const {
    return SpecificGasConstant<Number>{value * number};
  }

  constexpr GasConstant<Number> operator*(const Mass<Number>& mass) const {
    return GasConstant<Number>{*this, mass};
  }

  constexpr SpecificGasConstant<Number> operator/(const Number number) const {
    return SpecificGasConstant<Number>{value / number};
  }

  constexpr Number operator/(
      const SpecificGasConstant<Number>& specific_gas_constant) const noexcept {
    return value / specific_gas_constant.value;
  }

  constexpr void operator+=(const SpecificGasConstant<Number>& specific_gas_constant) noexcept {
    value += specific_gas_constant.value;
  }

  constexpr void operator-=(const SpecificGasConstant<Number>& specific_gas_constant) noexcept {
    value -= specific_gas_constant.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a specific gas constant with a given value expressed in the standard
  // specific heat capacity unit.
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
  return {*this, mass};
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
