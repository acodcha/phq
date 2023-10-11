// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_ISOCHORIC_HEAT_CAPACITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_ISOCHORIC_HEAT_CAPACITY_HPP

#include "IsochoricHeatCapacity.hpp"
#include "Mass.hpp"
#include "Unit/SpecificHeatCapacity.hpp"

namespace PhQ {

// Specific isochoric heat capacity. Isochoric heat capacity per unit mass.
class SpecificIsochoricHeatCapacity
  : public DimensionalScalarQuantity<Unit::SpecificHeatCapacity> {
public:
  // Default constructor. Constructs a specific isochoric heat capacity with an
  // uninitialized value.
  SpecificIsochoricHeatCapacity() = default;

  // Constructor. Constructs a specific isochoric heat capacity with a given
  // value expressed in a given specific heat capacity unit.
  SpecificIsochoricHeatCapacity(
      const double value, const Unit::SpecificHeatCapacity unit)
    : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value, unit) {}

  // Constructor. Constructs a specific isochoric heat capacity from a given
  // specific gas constant and specific isobaric heat capacity using Mayer's
  // relation.
  constexpr SpecificIsochoricHeatCapacity(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const SpecificGasConstant& specific_gas_constant);

  // Constructor. Constructs a specific isochoric heat capacity from a given
  // specific gas constant and heat capacity ratio using the definition of the
  // heat capacity ratio and Mayer's relation.
  constexpr SpecificIsochoricHeatCapacity(
      const SpecificGasConstant& specific_gas_constant,
      const HeatCapacityRatio& heat_capacity_ratio);

  // Constructor. Constructs a specific isochoric heat capacity from a given
  // specific isobaric heat capacity and heat capacity ratio using the
  // definition of the heat capacity ratio.
  constexpr SpecificIsochoricHeatCapacity(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const HeatCapacityRatio& heat_capacity_ratio);

  // Constructor. Constructs a specific isochoric heat capacity from a given
  // isochoric heat capacity and mass using the definition of the specific
  // isochoric heat capacity.
  constexpr SpecificIsochoricHeatCapacity(
      const IsochoricHeatCapacity& isochoric_heat_capacity, const Mass& mass)
    : SpecificIsochoricHeatCapacity(
        isochoric_heat_capacity.Value() / mass.Value()) {}

  // Destructor. Destroys this specific isochoric heat capacity.
  ~SpecificIsochoricHeatCapacity() noexcept = default;

  // Copy constructor. Constructs a specific isochoric heat capacity by copying
  // another one.
  constexpr SpecificIsochoricHeatCapacity(
      const SpecificIsochoricHeatCapacity& other) = default;

  // Move constructor. Constructs a specific isochoric heat capacity by moving
  // another one.
  constexpr SpecificIsochoricHeatCapacity(
      SpecificIsochoricHeatCapacity&& other) noexcept = default;

  // Copy assignment operator. Assigns this specific isochoric heat capacity by
  // copying another one.
  constexpr SpecificIsochoricHeatCapacity& operator=(
      const SpecificIsochoricHeatCapacity& other) = default;

  // Move assignment operator. Assigns this specific isochoric heat capacity by
  // moving another one.
  constexpr SpecificIsochoricHeatCapacity& operator=(
      SpecificIsochoricHeatCapacity&& other) noexcept = default;

  // Statically creates a specific isochoric heat capacity of zero.
  static constexpr SpecificIsochoricHeatCapacity Zero() {
    return SpecificIsochoricHeatCapacity{0.0};
  }

  // Statically creates a specific isochoric heat capacity with a given value
  // expressed in a given specific heat capacity unit.
  template <Unit::SpecificHeatCapacity Unit>
  static constexpr SpecificIsochoricHeatCapacity Create(const double value) {
    return SpecificIsochoricHeatCapacity{
        StaticConvertCopy<Unit::SpecificHeatCapacity, Unit,
                          Standard<Unit::SpecificHeatCapacity>>(value)};
  }

  constexpr SpecificIsochoricHeatCapacity operator+(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
      const {
    return SpecificIsochoricHeatCapacity{
        value_ + specific_isochoric_heat_capacity.value_};
  }

  constexpr SpecificIsobaricHeatCapacity operator+(
      const SpecificGasConstant& specific_gas_constant) const;

  constexpr SpecificIsochoricHeatCapacity operator-(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
      const {
    return SpecificIsochoricHeatCapacity{
        value_ - specific_isochoric_heat_capacity.value_};
  }

  constexpr SpecificIsochoricHeatCapacity operator*(const double number) const {
    return SpecificIsochoricHeatCapacity{value_ * number};
  }

  constexpr IsochoricHeatCapacity operator*(const Mass& mass) const {
    return {*this, mass};
  }

  constexpr SpecificIsobaricHeatCapacity operator*(
      const HeatCapacityRatio& heat_capacity_ratio) const;

  constexpr SpecificIsochoricHeatCapacity operator/(const double number) const {
    return SpecificIsochoricHeatCapacity{value_ / number};
  }

  constexpr double operator/(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
      const noexcept {
    return value_ / specific_isochoric_heat_capacity.value_;
  }

  constexpr void operator+=(const SpecificIsochoricHeatCapacity&
                                specific_isochoric_heat_capacity) noexcept {
    value_ += specific_isochoric_heat_capacity.value_;
  }

  constexpr void operator-=(const SpecificIsochoricHeatCapacity&
                                specific_isochoric_heat_capacity) noexcept {
    value_ -= specific_isochoric_heat_capacity.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a specific isochoric heat capacity with a given
  // value expressed in the standard specific heat capacity unit.
  explicit constexpr SpecificIsochoricHeatCapacity(const double value)
    : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value) {}
};

inline constexpr bool operator==(
    const SpecificIsochoricHeatCapacity& left,
    const SpecificIsochoricHeatCapacity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const SpecificIsochoricHeatCapacity& left,
    const SpecificIsochoricHeatCapacity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const SpecificIsochoricHeatCapacity& left,
    const SpecificIsochoricHeatCapacity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const SpecificIsochoricHeatCapacity& left,
    const SpecificIsochoricHeatCapacity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const SpecificIsochoricHeatCapacity& left,
    const SpecificIsochoricHeatCapacity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const SpecificIsochoricHeatCapacity& left,
    const SpecificIsochoricHeatCapacity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) {
  stream << specific_isochoric_heat_capacity.Print();
  return stream;
}

inline constexpr SpecificIsochoricHeatCapacity operator*(
    const double number,
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity) {
  return specific_isochoric_heat_capacity * number;
}

inline constexpr Mass::Mass(
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity,
    const IsochoricHeatCapacity& isochoric_heat_capacity)
  : Mass(isochoric_heat_capacity.Value()
         / specific_isochoric_heat_capacity.Value()) {}

inline constexpr IsochoricHeatCapacity::IsochoricHeatCapacity(
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity,
    const Mass& mass)
  : IsochoricHeatCapacity(
      specific_isochoric_heat_capacity.Value() * mass.Value()) {}

inline constexpr IsochoricHeatCapacity Mass::operator*(
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
    const {
  return {specific_isochoric_heat_capacity, *this};
}

inline constexpr SpecificIsochoricHeatCapacity IsochoricHeatCapacity::operator/(
    const Mass& mass) const {
  return {*this, mass};
}

inline constexpr Mass IsochoricHeatCapacity::operator/(
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
    const {
  return {specific_isochoric_heat_capacity, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::SpecificIsochoricHeatCapacity> {
  inline size_t operator()(const PhQ::SpecificIsochoricHeatCapacity&
                               specific_isochoric_heat_capacity) const {
    return hash<double>()(specific_isochoric_heat_capacity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_ISOCHORIC_HEAT_CAPACITY_HPP
