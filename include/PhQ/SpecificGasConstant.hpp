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
class SpecificGasConstant : public DimensionalScalar<Unit::SpecificHeatCapacity> {
public:
  // Default constructor. Constructs a specific gas constant with an uninitialized value.
  SpecificGasConstant() = default;

  // Constructor. Constructs a specific gas constant with a given value expressed in a given
  // specific heat capacity unit.
  SpecificGasConstant(const double value, const Unit::SpecificHeatCapacity unit)
    : DimensionalScalar<Unit::SpecificHeatCapacity>(value, unit) {}

  // Constructor. Constructs a specific gas constant from a given specific isobaric heat capacity
  // and specific isochoric heat capacity using Mayer's relation.
  constexpr SpecificGasConstant(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
    : SpecificGasConstant(
        specific_isobaric_heat_capacity.Value() - specific_isochoric_heat_capacity.Value()) {}

  // Constructor. Constructs a specific gas constant from a given specific isobaric heat capacity
  // and heat capacity ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr SpecificGasConstant(const HeatCapacityRatio& heat_capacity_ratio,
                                const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity)
    : SpecificGasConstant(
        (1.0 - 1.0 / heat_capacity_ratio.Value()) * specific_isobaric_heat_capacity.Value()) {}

  // Constructor. Constructs a specific gas constant from a given specific isochoric heat capacity
  // and heat capacity ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr SpecificGasConstant(
      const HeatCapacityRatio& heat_capacity_ratio,
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
    : SpecificGasConstant(
        (heat_capacity_ratio.Value() - 1.0) * specific_isochoric_heat_capacity.Value()) {}

  // Constructor. Constructs a specific gas constant from a given gas constant and mass using the
  // definition of the specific gas constant.
  constexpr SpecificGasConstant(const GasConstant& gas_constant, const Mass& mass)
    : SpecificGasConstant(gas_constant.Value() / mass.Value()) {}

  // Destructor. Destroys this specific gas constant.
  ~SpecificGasConstant() noexcept = default;

  // Copy constructor. Constructs a specific gas constant by copying another one.
  constexpr SpecificGasConstant(const SpecificGasConstant& other) = default;

  // Move constructor. Constructs a specific gas constant by moving another one.
  constexpr SpecificGasConstant(SpecificGasConstant&& other) noexcept = default;

  // Copy assignment operator. Assigns this specific gas constant by copying another one.
  constexpr SpecificGasConstant& operator=(const SpecificGasConstant& other) = default;

  // Move assignment operator. Assigns this specific gas constant by moving another one.
  constexpr SpecificGasConstant& operator=(SpecificGasConstant&& other) noexcept = default;

  // Statically creates a specific gas constant of zero.
  static constexpr SpecificGasConstant Zero() {
    return SpecificGasConstant{0.0};
  }

  // Statically creates a specific gas constant with a given value expressed in a given specific
  // heat capacity unit.
  template <Unit::SpecificHeatCapacity Unit>
  static constexpr SpecificGasConstant Create(const double value) {
    return SpecificGasConstant{
        StaticConvertCopy<Unit::SpecificHeatCapacity, Unit, Standard<Unit::SpecificHeatCapacity>>(
            value)};
  }

  constexpr SpecificGasConstant operator+(const SpecificGasConstant& specific_gas_constant) const {
    return SpecificGasConstant{value_ + specific_gas_constant.value_};
  }

  constexpr SpecificIsobaricHeatCapacity operator+(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const {
    return {specific_isochoric_heat_capacity, *this};
  }

  constexpr SpecificGasConstant operator-(const SpecificGasConstant& specific_gas_constant) const {
    return SpecificGasConstant{value_ - specific_gas_constant.value_};
  }

  constexpr SpecificGasConstant operator*(const double number) const {
    return SpecificGasConstant{value_ * number};
  }

  constexpr GasConstant operator*(const Mass& mass) const {
    return {*this, mass};
  }

  constexpr SpecificGasConstant operator/(const double number) const {
    return SpecificGasConstant{value_ / number};
  }

  constexpr double operator/(const SpecificGasConstant& specific_gas_constant) const noexcept {
    return value_ / specific_gas_constant.value_;
  }

  constexpr void operator+=(const SpecificGasConstant& specific_gas_constant) noexcept {
    value_ += specific_gas_constant.value_;
  }

  constexpr void operator-=(const SpecificGasConstant& specific_gas_constant) noexcept {
    value_ -= specific_gas_constant.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a specific gas constant with a given value expressed in the standard
  // specific heat capacity unit.
  explicit constexpr SpecificGasConstant(const double value)
    : DimensionalScalar<Unit::SpecificHeatCapacity>(value) {}
};

inline constexpr bool operator==(
    const SpecificGasConstant& left, const SpecificGasConstant& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const SpecificGasConstant& left, const SpecificGasConstant& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const SpecificGasConstant& left, const SpecificGasConstant& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const SpecificGasConstant& left, const SpecificGasConstant& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const SpecificGasConstant& left, const SpecificGasConstant& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const SpecificGasConstant& left, const SpecificGasConstant& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const SpecificGasConstant& specific_gas_constant) {
  stream << specific_gas_constant.Print();
  return stream;
}

inline constexpr SpecificGasConstant operator*(
    const double number, const SpecificGasConstant& specific_gas_constant) {
  return specific_gas_constant * number;
}

inline constexpr HeatCapacityRatio::HeatCapacityRatio(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
    const SpecificGasConstant& specific_gas_constant)
  : HeatCapacityRatio(specific_isobaric_heat_capacity.Value()
                      / (specific_isobaric_heat_capacity.Value() - specific_gas_constant.Value())) {
}

inline constexpr HeatCapacityRatio::HeatCapacityRatio(
    const SpecificGasConstant& specific_gas_constant,
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
  : HeatCapacityRatio(
      specific_gas_constant.Value() / specific_isochoric_heat_capacity.Value() + 1.0) {}

inline constexpr Mass::Mass(
    const GasConstant& gas_constant, const SpecificGasConstant& specific_gas_constant)
  : Mass(gas_constant.Value() / specific_gas_constant.Value()) {}

inline constexpr GasConstant::GasConstant(
    const SpecificGasConstant& specific_gas_constant, const Mass& mass)
  : GasConstant(specific_gas_constant.Value() * mass.Value()) {}

inline constexpr SpecificIsochoricHeatCapacity::SpecificIsochoricHeatCapacity(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
    const SpecificGasConstant& specific_gas_constant)
  : SpecificIsochoricHeatCapacity(
      specific_isobaric_heat_capacity.Value() - specific_gas_constant.Value()) {}

inline constexpr SpecificIsochoricHeatCapacity::SpecificIsochoricHeatCapacity(
    const SpecificGasConstant& specific_gas_constant, const HeatCapacityRatio& heat_capacity_ratio)
  : SpecificIsochoricHeatCapacity(
      specific_gas_constant.Value() / (heat_capacity_ratio.Value() - 1.0)) {}

inline constexpr SpecificIsobaricHeatCapacity::SpecificIsobaricHeatCapacity(
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity,
    const SpecificGasConstant& specific_gas_constant)
  : SpecificIsobaricHeatCapacity(
      specific_isochoric_heat_capacity.Value() + specific_gas_constant.Value()) {}

inline constexpr SpecificIsobaricHeatCapacity::SpecificIsobaricHeatCapacity(
    const HeatCapacityRatio& heat_capacity_ratio, const SpecificGasConstant& specific_gas_constant)
  : SpecificIsobaricHeatCapacity(heat_capacity_ratio.Value() * specific_gas_constant.Value()
                                 / (heat_capacity_ratio.Value() - 1.0)) {}

inline constexpr SpecificIsobaricHeatCapacity SpecificIsochoricHeatCapacity::operator+(
    const SpecificGasConstant& specific_gas_constant) const {
  return {*this, specific_gas_constant};
}

inline constexpr SpecificGasConstant SpecificIsobaricHeatCapacity::operator-(
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) const {
  return {*this, specific_isochoric_heat_capacity};
}

inline constexpr SpecificIsochoricHeatCapacity SpecificIsobaricHeatCapacity::operator-(
    const SpecificGasConstant& specific_gas_constant) const {
  return {*this, specific_gas_constant};
}

inline constexpr GasConstant Mass::operator*(
    const SpecificGasConstant& specific_gas_constant) const {
  return {specific_gas_constant, *this};
}

inline constexpr SpecificGasConstant GasConstant::operator/(const Mass& mass) const {
  return {*this, mass};
}

inline constexpr Mass GasConstant::operator/(
    const SpecificGasConstant& specific_gas_constant) const {
  return {*this, specific_gas_constant};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::SpecificGasConstant> {
  inline size_t operator()(const PhQ::SpecificGasConstant& specific_gas_constant) const {
    return hash<double>()(specific_gas_constant.Value());
  }
};

}  // namespace std

#endif  // PHQ_SPECIFIC_GAS_CONSTANT_HPP
