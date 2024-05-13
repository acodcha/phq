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

#ifndef PHQ_ISOCHORIC_HEAT_CAPACITY_HPP
#define PHQ_ISOCHORIC_HEAT_CAPACITY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "HeatCapacityRatio.hpp"
#include "Unit/HeatCapacity.hpp"

namespace PhQ {

// Isochoric heat capacity, also known as heat capacity at constant volume.
template <typename Number = double>
class IsochoricHeatCapacity : public DimensionalScalar<Unit::HeatCapacity, Number> {
public:
  // Default constructor. Constructs an isochoric heat capacity with an uninitialized value.
  IsochoricHeatCapacity() = default;

  // Constructor. Constructs an isochoric heat capacity with a given value expressed in a given heat
  // capacity unit.
  IsochoricHeatCapacity(const Number value, const Unit::HeatCapacity unit)
    : DimensionalScalar<Unit::HeatCapacity, Number>(value, unit) {}

  // Constructor. Constructs an isochoric heat capacity from a given gas constant and isobaric heat
  // capacity using Mayer's relation.
  constexpr IsochoricHeatCapacity(const IsobaricHeatCapacity<Number>& isobaric_heat_capacity,
                                  const GasConstant<Number>& gas_constant);

  // Constructor. Constructs an isochoric heat capacity from a given gas constant and heat capacity
  // ratio using the definition of the specific heat ratio and Mayer's relation.
  constexpr IsochoricHeatCapacity(const GasConstant<Number>& gas_constant,
                                  const HeatCapacityRatio<Number>& heat_capacity_ratio);

  // Constructor. Constructs an isochoric heat capacity from a given isobaric heat capacity and heat
  // capacity ratio using the definition of the specific heat ratio.
  constexpr IsochoricHeatCapacity(const IsobaricHeatCapacity<Number>& isobaric_heat_capacity,
                                  const HeatCapacityRatio<Number>& heat_capacity_ratio);

  // Constructor. Constructs an isochoric heat capacity from a given specific isochoric heat
  // capacity and mass using the definition of the specific isochoric heat capacity.
  constexpr IsochoricHeatCapacity(
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity,
      const Mass<Number>& mass);

  // Destructor. Destroys this isochoric heat capacity.
  ~IsochoricHeatCapacity() noexcept = default;

  // Copy constructor. Constructs an isochoric heat capacity by copying another one.
  constexpr IsochoricHeatCapacity(const IsochoricHeatCapacity<Number>& other) = default;

  // Copy constructor. Constructs a isochoric heat capacity by copying another one.
  template <typename OtherNumber>
  explicit constexpr IsochoricHeatCapacity(const IsochoricHeatCapacity<OtherNumber>& other)
    : IsochoricHeatCapacity(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs an isochoric heat capacity by moving another one.
  constexpr IsochoricHeatCapacity(IsochoricHeatCapacity<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this isochoric heat capacity by copying another one.
  constexpr IsochoricHeatCapacity<Number>& operator=(
      const IsochoricHeatCapacity<Number>& other) = default;

  // Copy assignment operator. Assigns this isochoric heat capacity by copying another one.
  template <typename OtherNumber>
  constexpr IsochoricHeatCapacity<Number>& operator=(
      const IsochoricHeatCapacity<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this isochoric heat capacity by moving another one.
  constexpr IsochoricHeatCapacity<Number>& operator=(
      IsochoricHeatCapacity<Number>&& other) noexcept = default;

  // Statically creates an isochoric heat capacity of zero.
  static constexpr IsochoricHeatCapacity<Number> Zero() {
    return IsochoricHeatCapacity<Number>{static_cast<Number>(0)};
  }

  // Statically creates an isochoric heat capacity with a given value expressed in a given heat
  // capacity unit.
  template <Unit::HeatCapacity Unit>
  static constexpr IsochoricHeatCapacity<Number> Create(const Number value) {
    return IsochoricHeatCapacity<Number>{
        StaticConvertCopy<Unit::HeatCapacity, Unit, Standard<Unit::HeatCapacity>>(value)};
  }

  constexpr IsochoricHeatCapacity<Number> operator+(
      const IsochoricHeatCapacity<Number>& isochoric_heat_capacity) const {
    return IsochoricHeatCapacity<Number>{this->value + isochoric_heat_capacity.value};
  }

  constexpr IsobaricHeatCapacity<Number> operator+(const GasConstant<Number>& gas_constant) const;

  constexpr IsochoricHeatCapacity<Number> operator-(
      const IsochoricHeatCapacity<Number>& isochoric_heat_capacity) const {
    return IsochoricHeatCapacity<Number>{this->value - isochoric_heat_capacity.value};
  }

  constexpr IsochoricHeatCapacity<Number> operator*(const Number number) const {
    return IsochoricHeatCapacity<Number>{this->value * number};
  }

  constexpr IsobaricHeatCapacity<Number> operator*(
      const HeatCapacityRatio<Number>& heat_capacity_ratio) const;

  constexpr IsochoricHeatCapacity<Number> operator/(const Number number) const {
    return IsochoricHeatCapacity<Number>{this->value / number};
  }

  constexpr SpecificIsochoricHeatCapacity<Number> operator/(const Mass<Number>& mass) const;

  constexpr Mass<Number> operator/(
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) const;

  constexpr Number operator/(
      const IsochoricHeatCapacity<Number>& isochoric_heat_capacity) const noexcept {
    return this->value / isochoric_heat_capacity.value;
  }

  constexpr void operator+=(const IsochoricHeatCapacity<Number>& isochoric_heat_capacity) noexcept {
    this->value += isochoric_heat_capacity.value;
  }

  constexpr void operator-=(const IsochoricHeatCapacity<Number>& isochoric_heat_capacity) noexcept {
    this->value -= isochoric_heat_capacity.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs an isochoric heat capacity with a given value expressed in the standard
  // heat capacity unit.
  explicit constexpr IsochoricHeatCapacity(const Number value)
    : DimensionalScalar<Unit::HeatCapacity, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const IsochoricHeatCapacity<Number>& left,
                                 const IsochoricHeatCapacity<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const IsochoricHeatCapacity<Number>& left,
                                 const IsochoricHeatCapacity<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const IsochoricHeatCapacity<Number>& left,
                                const IsochoricHeatCapacity<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const IsochoricHeatCapacity<Number>& left,
                                const IsochoricHeatCapacity<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const IsochoricHeatCapacity<Number>& left,
                                 const IsochoricHeatCapacity<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const IsochoricHeatCapacity<Number>& left,
                                 const IsochoricHeatCapacity<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const IsochoricHeatCapacity<Number>& isochoric_heat_capacity) {
  stream << isochoric_heat_capacity.Print();
  return stream;
}

template <typename Number>
inline constexpr IsochoricHeatCapacity<Number> operator*(
    const Number number, const IsochoricHeatCapacity<Number>& isochoric_heat_capacity) {
  return isochoric_heat_capacity * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::IsochoricHeatCapacity<Number>> {
  inline size_t operator()(
      const PhQ::IsochoricHeatCapacity<Number>& isochoric_heat_capacity) const {
    return hash<Number>()(isochoric_heat_capacity.Value());
  }
};

}  // namespace std

#endif  // PHQ_ISOCHORIC_HEAT_CAPACITY_HPP
