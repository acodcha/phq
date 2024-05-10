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

// Gas constant of a gas. Not to be confused with the molar gas constant or the specific gas
// constant.
template <typename Number = double>
class GasConstant : public DimensionalScalar<Unit::HeatCapacity, Number> {
public:
  // Default constructor. Constructs a gas constant with an uninitialized value.
  GasConstant() = default;

  // Constructor. Constructs a gas constant with a given value expressed in a given heat capacity
  // unit.
  GasConstant(const Number value, const Unit::HeatCapacity unit)
    : DimensionalScalar<Unit::HeatCapacity, Number>(value, unit) {}

  // Constructor. Constructs a gas constant from a given isobaric heat capacity and isochoric heat
  // capacity using Mayer's relation.
  constexpr GasConstant(const IsobaricHeatCapacity<Number>& isobaric_heat_capacity,
                        const IsochoricHeatCapacity<Number>& isochoric_heat_capacity)
    : GasConstant<Number>(isobaric_heat_capacity.Value() - isochoric_heat_capacity.Value()) {}

  // Constructor. Constructs a gas constant from a given isobaric heat capacity and heat capacity
  // ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr GasConstant(const HeatCapacityRatio<Number>& heat_capacity_ratio,
                        const IsobaricHeatCapacity<Number>& isobaric_heat_capacity)
    : GasConstant<Number>(
        (1.0 - 1.0 / heat_capacity_ratio.Value()) * isobaric_heat_capacity.Value()) {}

  // Constructor. Constructs a gas constant from a given isochoric heat capacity and heat capacity
  // ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr GasConstant(const HeatCapacityRatio<Number>& heat_capacity_ratio,
                        const IsochoricHeatCapacity<Number>& isochoric_heat_capacity)
    : GasConstant<Number>((heat_capacity_ratio.Value() - 1.0) * isochoric_heat_capacity.Value()) {}

  // Constructor. Constructs a gas constant from a given specific gas constant and mass using the
  // definition of the specific gas constant.
  constexpr GasConstant(
      const SpecificGasConstant<Number>& specific_gas_constant, const Mass<Number>& mass);

  // Destructor. Destroys this gas constant.
  ~GasConstant() noexcept = default;

  // Copy constructor. Constructs a gas constant by copying another one.
  constexpr GasConstant(const GasConstant<Number>& other) = default;

  // Copy constructor. Constructs a gas constant by copying another one.
  template <typename OtherNumber>
  explicit constexpr GasConstant(const GasConstant<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a gas constant by moving another one.
  constexpr GasConstant(GasConstant<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this gas constant by copying another one.
  constexpr GasConstant<Number>& operator=(const GasConstant<Number>& other) = default;

  // Copy assignment operator. Assigns this gas constant by copying another one.
  template <typename OtherNumber>
  constexpr GasConstant<Number>& operator=(const GasConstant<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this gas constant by moving another one.
  constexpr GasConstant<Number>& operator=(GasConstant<Number>&& other) noexcept = default;

  // Statically creates a gas constant of zero.
  static constexpr GasConstant<Number> Zero() {
    return GasConstant<Number>{static_cast<Number>(0)};
  }

  // Statically creates a gas constant with a given value expressed in a given heat capacity unit.
  template <Unit::HeatCapacity Unit>
  static constexpr GasConstant<Number> Create(const Number value) {
    return GasConstant<Number>{
        StaticConvertCopy<Unit::HeatCapacity, Unit, Standard<Unit::HeatCapacity>>(value)};
  }

  constexpr GasConstant<Number> operator+(const GasConstant<Number>& gas_constant) const {
    return GasConstant<Number>{value + gas_constant.value};
  }

  constexpr IsobaricHeatCapacity<Number> operator+(
      const IsochoricHeatCapacity<Number>& isochoric_heat_capacity) const {
    return IsobaricHeatCapacity<Number>{isochoric_heat_capacity, *this};
  }

  constexpr GasConstant<Number> operator-(const GasConstant<Number>& gas_constant) const {
    return GasConstant<Number>{value - gas_constant.value};
  }

  constexpr GasConstant<Number> operator*(const Number number) const {
    return GasConstant<Number>{value * number};
  }

  constexpr GasConstant<Number> operator/(const Number number) const {
    return GasConstant<Number>{value / number};
  }

  constexpr SpecificGasConstant<Number> operator/(const Mass<Number>& mass) const;

  constexpr Mass<Number> operator/(const SpecificGasConstant<Number>& specific_gas_constant) const;

  constexpr Number operator/(const GasConstant<Number>& gas_constant) const noexcept {
    return value / gas_constant.value;
  }

  constexpr void operator+=(const GasConstant<Number>& gas_constant) noexcept {
    value += gas_constant.value;
  }

  constexpr void operator-=(const GasConstant<Number>& gas_constant) noexcept {
    value -= gas_constant.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a gas constant with a given value expressed in the standard heat
  // capacity unit.
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
  return IsochoricHeatCapacity<Number>{*this, isochoric_heat_capacity};
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
