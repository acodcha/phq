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

#ifndef PHQ_HEAT_CAPACITY_RATIO_HPP
#define PHQ_HEAT_CAPACITY_RATIO_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"

namespace PhQ {

// Forward declaration for class PhQ::HeatCapacityRatio.
template <typename Number>
class GasConstant;

// Forward declaration for class PhQ::HeatCapacityRatio.
template <typename Number>
class IsobaricHeatCapacity;

// Forward declaration for class PhQ::HeatCapacityRatio.
template <typename Number>
class IsochoricHeatCapacity;

// Forward declaration for class PhQ::HeatCapacityRatio.
template <typename Number>
class Mass;

// Forward declaration for class PhQ::HeatCapacityRatio.
template <typename Number>
class SpecificGasConstant;

// Forward declaration for class PhQ::HeatCapacityRatio.
template <typename Number>
class SpecificIsobaricHeatCapacity;

// Forward declaration for class PhQ::HeatCapacityRatio.
template <typename Number>
class SpecificIsochoricHeatCapacity;

// Heat capacity ratio, also known as ratio of specific heats, adiabatic index, or Laplace's
// coefficient. The heat capacity ratio is the ratio of the isobaric heat capacity of a material to
// its isochoric heat capacity.
template <typename Number = double>
class HeatCapacityRatio : public DimensionlessScalar<Number> {
public:
  // Default constructor. Constructs a heat capacity ratio ratio with an uninitialized value.
  HeatCapacityRatio() = default;

  // Constructor. Constructs a heat capacity ratio with a given value.
  explicit constexpr HeatCapacityRatio(const Number value) : DimensionlessScalar<Number>(value) {}

  // Constructor. Constructs a heat capacity ratio from a given specific gas constant and specific
  // isobaric heat capacity using Mayer's relation and the definition of the heat capacity ratio.
  constexpr HeatCapacityRatio(
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
      const SpecificGasConstant<Number>& specific_gas_constant);

  // Constructor. Constructs a heat capacity ratio from a given specific gas constant and specific
  // isochoric heat capacity using Mayer's relation and the definition of the heat capacity ratio.
  constexpr HeatCapacityRatio(
      const SpecificGasConstant<Number>& specific_gas_constant,
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity);

  // Constructor. Constructs a heat capacity ratio from a given specific isobaric heat capacity and
  // specific isochoric heat capacity using the definition of the heat capacity ratio.
  constexpr HeatCapacityRatio(
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity);

  // Constructor. Constructs a heat capacity ratio from a given gas constant and isobaric heat
  // capacity using Mayer's relation and the definition of the heat capacity ratio.
  constexpr HeatCapacityRatio(const IsobaricHeatCapacity<Number>& isobaric_heat_capacity,
                              const GasConstant<Number>& gas_constant);

  // Constructor. Constructs a heat capacity ratio from a given gas constant and isochoric heat
  // capacity using Mayer's relation and the definition of the heat capacity ratio.
  constexpr HeatCapacityRatio(const GasConstant<Number>& gas_constant,
                              const IsochoricHeatCapacity<Number>& isochoric_heat_capacity);

  // Constructor. Constructs a heat capacity ratio from a given isobaric heat capacity and isochoric
  // heat capacity using the definition of the specific heat ratio.
  constexpr HeatCapacityRatio(const IsobaricHeatCapacity<Number>& isobaric_heat_capacity,
                              const IsochoricHeatCapacity<Number>& isochoric_heat_capacity);

  // Destructor. Destroys this heat capacity ratio.
  ~HeatCapacityRatio() noexcept = default;

  // Copy constructor. Constructs a heat capacity ratio by copying another one.
  constexpr HeatCapacityRatio(const HeatCapacityRatio<Number>& other) = default;

  // Copy constructor. Constructs a heat capacity ratio by copying another one.
  template <typename OtherNumber>
  explicit constexpr HeatCapacityRatio(const HeatCapacityRatio<OtherNumber>& other)
    : HeatCapacityRatio(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a heat capacity ratio by moving another one.
  constexpr HeatCapacityRatio(HeatCapacityRatio<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this heat capacity ratio by copying another one.
  constexpr HeatCapacityRatio<Number>& operator=(const HeatCapacityRatio<Number>& other) = default;

  // Copy assignment operator. Assigns this heat capacity ratio by copying another one.
  template <typename OtherNumber>
  constexpr HeatCapacityRatio<Number>& operator=(const HeatCapacityRatio<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this heat capacity ratio by moving another one.
  constexpr HeatCapacityRatio<Number>& operator=(
      HeatCapacityRatio<Number>&& other) noexcept = default;

  // Statically creates a heat capacity ratio of zero.
  static constexpr HeatCapacityRatio<Number> Zero() {
    return HeatCapacityRatio<Number>{static_cast<Number>(0)};
  }

  constexpr HeatCapacityRatio<Number> operator+(
      const HeatCapacityRatio<Number>& heat_capacity_ratio) const {
    return HeatCapacityRatio<Number>{this->value + heat_capacity_ratio.value};
  }

  constexpr HeatCapacityRatio<Number> operator-(
      const HeatCapacityRatio<Number>& heat_capacity_ratio) const {
    return HeatCapacityRatio<Number>{this->value - heat_capacity_ratio.value};
  }

  constexpr HeatCapacityRatio<Number> operator*(const Number number) const {
    return HeatCapacityRatio<Number>{this->value * number};
  }

  constexpr IsobaricHeatCapacity<Number> operator*(
      const IsochoricHeatCapacity<Number>& isochoric_heat_capacity) const;

  constexpr SpecificIsobaricHeatCapacity<Number> operator*(
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) const;

  constexpr HeatCapacityRatio<Number> operator/(const Number number) const {
    return HeatCapacityRatio<Number>{this->value / number};
  }

  constexpr Number operator/(const HeatCapacityRatio<Number>& heat_capacity_ratio) const noexcept {
    return this->value / heat_capacity_ratio.value;
  }

  constexpr void operator+=(const HeatCapacityRatio<Number>& heat_capacity_ratio) noexcept {
    this->value += heat_capacity_ratio.value;
  }

  constexpr void operator-=(const HeatCapacityRatio<Number>& heat_capacity_ratio) noexcept {
    this->value -= heat_capacity_ratio.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }
};

template <typename Number>
inline constexpr bool operator==(
    const HeatCapacityRatio<Number>& left, const HeatCapacityRatio<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const HeatCapacityRatio<Number>& left, const HeatCapacityRatio<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const HeatCapacityRatio<Number>& left, const HeatCapacityRatio<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const HeatCapacityRatio<Number>& left, const HeatCapacityRatio<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const HeatCapacityRatio<Number>& left, const HeatCapacityRatio<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const HeatCapacityRatio<Number>& left, const HeatCapacityRatio<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const HeatCapacityRatio<Number>& heat_capacity_ratio) {
  stream << heat_capacity_ratio.Print();
  return stream;
}

template <typename Number>
inline constexpr HeatCapacityRatio<Number> operator*(
    const Number number, const HeatCapacityRatio<Number>& heat_capacity_ratio) {
  return HeatCapacityRatio<Number>{number * heat_capacity_ratio.Value()};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::HeatCapacityRatio<Number>> {
  inline size_t operator()(const PhQ::HeatCapacityRatio<Number>& heat_capacity_ratio) const {
    return hash<Number>()(heat_capacity_ratio.Value());
  }
};

}  // namespace std

#endif  // PHQ_HEAT_CAPACITY_RATIO_HPP
