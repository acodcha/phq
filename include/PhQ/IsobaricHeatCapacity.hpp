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

#ifndef PHQ_ISOBARIC_HEAT_CAPACITY_HPP
#define PHQ_ISOBARIC_HEAT_CAPACITY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "HeatCapacityRatio.hpp"
#include "IsochoricHeatCapacity.hpp"
#include "Unit/HeatCapacity.hpp"

namespace PhQ {

// Isobaric heat capacity, also known as heat capacity at constant pressure.
class IsobaricHeatCapacity : public DimensionalScalar<Unit::HeatCapacity> {
public:
  // Default constructor. Constructs an isobaric heat capacity with an uninitialized value.
  IsobaricHeatCapacity() = default;

  // Constructor. Constructs an isobaric heat capacity with a given value expressed in a given heat
  // capacity unit.
  IsobaricHeatCapacity(const double value, const Unit::HeatCapacity unit)
    : DimensionalScalar<Unit::HeatCapacity>(value, unit) {}

  // Constructor. Constructs an isobaric heat capacity from a given gas constant and isochoric heat
  // capacity using Mayer's relation.
  constexpr IsobaricHeatCapacity(
      const IsochoricHeatCapacity& isochoric_heat_capacity, const GasConstant& gas_constant);

  // Constructor. Constructs an isobaric heat capacity from a given gas constant and heat capacity
  // ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr IsobaricHeatCapacity(
      const HeatCapacityRatio& heat_capacity_ratio, const GasConstant& gas_constant);

  // Constructor. Constructs an isobaric heat capacity from a given isochoric heat capacity and heat
  // capacity ratio using the definition of the specific heat ratio.
  constexpr IsobaricHeatCapacity(const HeatCapacityRatio& heat_capacity_ratio,
                                 const IsochoricHeatCapacity& isochoric_heat_capacity)
    : IsobaricHeatCapacity(heat_capacity_ratio.Value() * isochoric_heat_capacity.Value()) {}

  // Constructor. Constructs an isobaric heat capacity from a given specific isobaric heat capacity
  // and mass using the definition of the specific isobaric heat capacity.
  constexpr IsobaricHeatCapacity(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity, const Mass& mass);

  // Destructor. Destroys this isobaric heat capacity.
  ~IsobaricHeatCapacity() noexcept = default;

  // Copy constructor. Constructs an isobaric heat capacity by copying another one.
  constexpr IsobaricHeatCapacity(const IsobaricHeatCapacity& other) = default;

  // Move constructor. Constructs an isobaric heat capacity by moving another one.
  constexpr IsobaricHeatCapacity(IsobaricHeatCapacity&& other) noexcept = default;

  // Copy assignment operator. Assigns this isobaric heat capacity by copying another one.
  constexpr IsobaricHeatCapacity& operator=(const IsobaricHeatCapacity& other) = default;

  // Move assignment operator. Assigns this isobaric heat capacity by moving another one.
  constexpr IsobaricHeatCapacity& operator=(IsobaricHeatCapacity&& other) noexcept = default;

  // Statically creates an isobaric heat capacity of zero.
  static constexpr IsobaricHeatCapacity Zero() {
    return IsobaricHeatCapacity{0.0};
  }

  // Statically creates an isobaric heat capacity with a given value expressed in a given heat
  // capacity unit.
  template <Unit::HeatCapacity Unit>
  static constexpr IsobaricHeatCapacity Create(const double value) {
    return IsobaricHeatCapacity{
        StaticConvertCopy<Unit::HeatCapacity, Unit, Standard<Unit::HeatCapacity>>(value)};
  }

  constexpr IsobaricHeatCapacity operator+(
      const IsobaricHeatCapacity& isobaric_heat_capacity) const {
    return IsobaricHeatCapacity{value + isobaric_heat_capacity.value};
  }

  constexpr IsobaricHeatCapacity operator-(
      const IsobaricHeatCapacity& isobaric_heat_capacity) const {
    return IsobaricHeatCapacity{value - isobaric_heat_capacity.value};
  }

  constexpr GasConstant operator-(const IsochoricHeatCapacity& isochoric_heat_capacity) const;

  constexpr IsochoricHeatCapacity operator-(const GasConstant& gas_constant) const;

  constexpr IsobaricHeatCapacity operator*(const double number) const {
    return IsobaricHeatCapacity{value * number};
  }

  constexpr IsobaricHeatCapacity operator/(const double number) const {
    return IsobaricHeatCapacity{value / number};
  }

  constexpr double operator/(const IsobaricHeatCapacity& isobaric_heat_capacity) const noexcept {
    return value / isobaric_heat_capacity.value;
  }

  constexpr SpecificIsobaricHeatCapacity operator/(const Mass& mass) const;

  constexpr Mass operator/(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const;

  constexpr HeatCapacityRatio operator/(
      const IsochoricHeatCapacity& isochoric_heat_capacity) const {
    return {*this, isochoric_heat_capacity};
  }

  constexpr IsochoricHeatCapacity operator/(const HeatCapacityRatio& heat_capacity_ratio) const {
    return {*this, heat_capacity_ratio};
  }

  constexpr void operator+=(const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept {
    value += isobaric_heat_capacity.value;
  }

  constexpr void operator-=(const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept {
    value -= isobaric_heat_capacity.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs an isobaric heat capacity with a given value expressed in the standard
  // heat capacity unit.
  explicit constexpr IsobaricHeatCapacity(const double value)
    : DimensionalScalar<Unit::HeatCapacity>(value) {}
};

inline constexpr bool operator==(
    const IsobaricHeatCapacity& left, const IsobaricHeatCapacity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const IsobaricHeatCapacity& left, const IsobaricHeatCapacity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const IsobaricHeatCapacity& left, const IsobaricHeatCapacity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const IsobaricHeatCapacity& left, const IsobaricHeatCapacity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const IsobaricHeatCapacity& left, const IsobaricHeatCapacity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const IsobaricHeatCapacity& left, const IsobaricHeatCapacity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const IsobaricHeatCapacity& isobaric_heat_capacity) {
  stream << isobaric_heat_capacity.Print();
  return stream;
}

inline constexpr IsobaricHeatCapacity operator*(
    const double number, const IsobaricHeatCapacity& isobaric_heat_capacity) {
  return isobaric_heat_capacity * number;
}

inline constexpr HeatCapacityRatio::HeatCapacityRatio(
    const IsobaricHeatCapacity& isobaric_heat_capacity,
    const IsochoricHeatCapacity& isochoric_heat_capacity)
  : HeatCapacityRatio(isobaric_heat_capacity.Value() / isochoric_heat_capacity.Value()) {}

inline constexpr IsochoricHeatCapacity::IsochoricHeatCapacity(
    const IsobaricHeatCapacity& isobaric_heat_capacity,
    const HeatCapacityRatio& heat_capacity_ratio)
  : IsochoricHeatCapacity(isobaric_heat_capacity.Value() / heat_capacity_ratio.Value()) {}

inline constexpr IsobaricHeatCapacity HeatCapacityRatio::operator*(
    const IsochoricHeatCapacity& isochoric_heat_capacity) const {
  return {*this, isochoric_heat_capacity};
}

inline constexpr IsobaricHeatCapacity IsochoricHeatCapacity::operator*(
    const HeatCapacityRatio& heat_capacity_ratio) const {
  return {heat_capacity_ratio, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::IsobaricHeatCapacity> {
  inline size_t operator()(const PhQ::IsobaricHeatCapacity& isobaric_heat_capacity) const {
    return hash<double>()(isobaric_heat_capacity.Value());
  }
};

}  // namespace std

#endif  // PHQ_ISOBARIC_HEAT_CAPACITY_HPP
