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
template <typename Number = double>
class IsobaricHeatCapacity : public DimensionalScalar<Unit::HeatCapacity, Number> {
public:
  // Default constructor. Constructs an isobaric heat capacity with an uninitialized value.
  IsobaricHeatCapacity() = default;

  // Constructor. Constructs an isobaric heat capacity with a given value expressed in a given heat
  // capacity unit.
  IsobaricHeatCapacity(const Number value, const Unit::HeatCapacity unit)
    : DimensionalScalar<Unit::HeatCapacity, Number>(value, unit) {}

  // Constructor. Constructs an isobaric heat capacity from a given gas constant and isochoric heat
  // capacity using Mayer's relation.
  constexpr IsobaricHeatCapacity(const IsochoricHeatCapacity<Number>& isochoric_heat_capacity,
                                 const GasConstant<Number>& gas_constant);

  // Constructor. Constructs an isobaric heat capacity from a given gas constant and heat capacity
  // ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr IsobaricHeatCapacity(const HeatCapacityRatio<Number>& heat_capacity_ratio,
                                 const GasConstant<Number>& gas_constant);

  // Constructor. Constructs an isobaric heat capacity from a given isochoric heat capacity and heat
  // capacity ratio using the definition of the specific heat ratio.
  constexpr IsobaricHeatCapacity(const HeatCapacityRatio<Number>& heat_capacity_ratio,
                                 const IsochoricHeatCapacity<Number>& isochoric_heat_capacity)
    : IsobaricHeatCapacity<Number>(heat_capacity_ratio.Value() * isochoric_heat_capacity.Value()) {}

  // Constructor. Constructs an isobaric heat capacity from a given specific isobaric heat capacity
  // and mass using the definition of the specific isobaric heat capacity.
  constexpr IsobaricHeatCapacity(
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
      const Mass<Number>& mass);

  // Destructor. Destroys this isobaric heat capacity.
  ~IsobaricHeatCapacity() noexcept = default;

  // Copy constructor. Constructs an isobaric heat capacity by copying another one.
  constexpr IsobaricHeatCapacity(const IsobaricHeatCapacity<Number>& other) = default;

  // Copy constructor. Constructs a isobaric heat capacity by copying another one.
  template <typename OtherNumber>
  explicit constexpr IsobaricHeatCapacity(const IsobaricHeatCapacity<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs an isobaric heat capacity by moving another one.
  constexpr IsobaricHeatCapacity(IsobaricHeatCapacity<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this isobaric heat capacity by copying another one.
  constexpr IsobaricHeatCapacity<Number>& operator=(
      const IsobaricHeatCapacity<Number>& other) = default;

  // Copy assignment operator. Assigns this isobaric heat capacity by copying another one.
  template <typename OtherNumber>
  constexpr IsobaricHeatCapacity<Number>& operator=(
      const IsobaricHeatCapacity<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this isobaric heat capacity by moving another one.
  constexpr IsobaricHeatCapacity<Number>& operator=(
      IsobaricHeatCapacity<Number>&& other) noexcept = default;

  // Statically creates an isobaric heat capacity of zero.
  static constexpr IsobaricHeatCapacity<Number> Zero() {
    return IsobaricHeatCapacity<Number>{static_cast<Number>(0)};
  }

  // Statically creates an isobaric heat capacity with a given value expressed in a given heat
  // capacity unit.
  template <Unit::HeatCapacity Unit>
  static constexpr IsobaricHeatCapacity<Number> Create(const Number value) {
    return IsobaricHeatCapacity<Number>{
        StaticConvertCopy<Unit::HeatCapacity, Unit, Standard<Unit::HeatCapacity>>(value)};
  }

  constexpr IsobaricHeatCapacity<Number> operator+(
      const IsobaricHeatCapacity<Number>& isobaric_heat_capacity) const {
    return IsobaricHeatCapacity<Number>{value + isobaric_heat_capacity.value};
  }

  constexpr IsobaricHeatCapacity<Number> operator-(
      const IsobaricHeatCapacity<Number>& isobaric_heat_capacity) const {
    return IsobaricHeatCapacity<Number>{value - isobaric_heat_capacity.value};
  }

  constexpr GasConstant<Number> operator-(
      const IsochoricHeatCapacity<Number>& isochoric_heat_capacity) const;

  constexpr IsochoricHeatCapacity<Number> operator-(const GasConstant<Number>& gas_constant) const;

  constexpr IsobaricHeatCapacity<Number> operator*(const Number number) const {
    return IsobaricHeatCapacity<Number>{value * number};
  }

  constexpr IsobaricHeatCapacity<Number> operator/(const Number number) const {
    return IsobaricHeatCapacity<Number>{value / number};
  }

  constexpr Number operator/(
      const IsobaricHeatCapacity<Number>& isobaric_heat_capacity) const noexcept {
    return value / isobaric_heat_capacity.value;
  }

  constexpr SpecificIsobaricHeatCapacity<Number> operator/(const Mass<Number>& mass) const;

  constexpr Mass<Number> operator/(
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity) const;

  constexpr HeatCapacityRatio<Number> operator/(
      const IsochoricHeatCapacity<Number>& isochoric_heat_capacity) const {
    return HeatCapacityRatio<Number>{*this, isochoric_heat_capacity};
  }

  constexpr IsochoricHeatCapacity<Number> operator/(
      const HeatCapacityRatio<Number>& heat_capacity_ratio) const {
    return IsochoricHeatCapacity<Number>{*this, heat_capacity_ratio};
  }

  constexpr void operator+=(const IsobaricHeatCapacity<Number>& isobaric_heat_capacity) noexcept {
    value += isobaric_heat_capacity.value;
  }

  constexpr void operator-=(const IsobaricHeatCapacity<Number>& isobaric_heat_capacity) noexcept {
    value -= isobaric_heat_capacity.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs an isobaric heat capacity with a given value expressed in the standard
  // heat capacity unit.
  explicit constexpr IsobaricHeatCapacity(const Number value)
    : DimensionalScalar<Unit::HeatCapacity, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const IsobaricHeatCapacity<Number>& left, const IsobaricHeatCapacity<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const IsobaricHeatCapacity<Number>& left, const IsobaricHeatCapacity<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const IsobaricHeatCapacity<Number>& left, const IsobaricHeatCapacity<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const IsobaricHeatCapacity<Number>& left, const IsobaricHeatCapacity<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const IsobaricHeatCapacity<Number>& left, const IsobaricHeatCapacity<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const IsobaricHeatCapacity<Number>& left, const IsobaricHeatCapacity<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const IsobaricHeatCapacity<Number>& isobaric_heat_capacity) {
  stream << isobaric_heat_capacity.Print();
  return stream;
}

template <typename Number>
inline constexpr IsobaricHeatCapacity<Number> operator*(
    const Number number, const IsobaricHeatCapacity<Number>& isobaric_heat_capacity) {
  return isobaric_heat_capacity * number;
}

template <typename Number>
inline constexpr HeatCapacityRatio<Number>::HeatCapacityRatio(
    const IsobaricHeatCapacity<Number>& isobaric_heat_capacity,
    const IsochoricHeatCapacity<Number>& isochoric_heat_capacity)
  : HeatCapacityRatio<Number>(isobaric_heat_capacity.Value() / isochoric_heat_capacity.Value()) {}

template <typename Number>
inline constexpr IsochoricHeatCapacity<Number>::IsochoricHeatCapacity(
    const IsobaricHeatCapacity<Number>& isobaric_heat_capacity,
    const HeatCapacityRatio<Number>& heat_capacity_ratio)
  : IsochoricHeatCapacity<Number>(isobaric_heat_capacity.Value() / heat_capacity_ratio.Value()) {}

template <typename Number>
inline constexpr IsobaricHeatCapacity<Number> HeatCapacityRatio<Number>::operator*(
    const IsochoricHeatCapacity<Number>& isochoric_heat_capacity) const {
  return IsobaricHeatCapacity<Number>{*this, isochoric_heat_capacity};
}

template <typename Number>
inline constexpr IsobaricHeatCapacity<Number> IsochoricHeatCapacity<Number>::operator*(
    const HeatCapacityRatio<Number>& heat_capacity_ratio) const {
  return IsobaricHeatCapacity<Number>{heat_capacity_ratio, *this};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::IsobaricHeatCapacity<Number>> {
  inline size_t operator()(const PhQ::IsobaricHeatCapacity<Number>& isobaric_heat_capacity) const {
    return hash<Number>()(isobaric_heat_capacity.Value());
  }
};

}  // namespace std

#endif  // PHQ_ISOBARIC_HEAT_CAPACITY_HPP
