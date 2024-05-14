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

#ifndef PHQ_SPECIFIC_ISOCHORIC_HEAT_CAPACITY_HPP
#define PHQ_SPECIFIC_ISOCHORIC_HEAT_CAPACITY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "HeatCapacityRatio.hpp"
#include "IsochoricHeatCapacity.hpp"
#include "Mass.hpp"
#include "Unit/SpecificHeatCapacity.hpp"

namespace PhQ {

// Specific isochoric heat capacity. Isochoric heat capacity per unit mass.
template <typename Number = double>
class SpecificIsochoricHeatCapacity : public DimensionalScalar<Unit::SpecificHeatCapacity, Number> {
public:
  // Default constructor. Constructs a specific isochoric heat capacity with an uninitialized value.
  SpecificIsochoricHeatCapacity() = default;

  // Constructor. Constructs a specific isochoric heat capacity with a given value expressed in a
  // given specific heat capacity unit.
  SpecificIsochoricHeatCapacity(const Number value, const Unit::SpecificHeatCapacity unit)
    : DimensionalScalar<Unit::SpecificHeatCapacity, Number>(value, unit) {}

  // Constructor. Constructs a specific isochoric heat capacity from a given specific gas constant
  // and specific isobaric heat capacity using Mayer's relation.
  constexpr SpecificIsochoricHeatCapacity(
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
      const SpecificGasConstant<Number>& specific_gas_constant);

  // Constructor. Constructs a specific isochoric heat capacity from a given specific gas constant
  // and heat capacity ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr SpecificIsochoricHeatCapacity(const SpecificGasConstant<Number>& specific_gas_constant,
                                          const HeatCapacityRatio<Number>& heat_capacity_ratio);

  // Constructor. Constructs a specific isochoric heat capacity from a given specific isobaric heat
  // capacity and heat capacity ratio using the definition of the heat capacity ratio.
  constexpr SpecificIsochoricHeatCapacity(
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
      const HeatCapacityRatio<Number>& heat_capacity_ratio);

  // Constructor. Constructs a specific isochoric heat capacity from a given isochoric heat capacity
  // and mass using the definition of the specific isochoric heat capacity.
  constexpr SpecificIsochoricHeatCapacity(
      const IsochoricHeatCapacity<Number>& isochoric_heat_capacity, const Mass<Number>& mass)
    : SpecificIsochoricHeatCapacity<Number>(isochoric_heat_capacity.Value() / mass.Value()) {}

  // Destructor. Destroys this specific isochoric heat capacity.
  ~SpecificIsochoricHeatCapacity() noexcept = default;

  // Copy constructor. Constructs a specific isochoric heat capacity by copying another one.
  constexpr SpecificIsochoricHeatCapacity(
      const SpecificIsochoricHeatCapacity<Number>& other) = default;

  // Copy constructor. Constructs a specific isochoric heat capacity by copying another one.
  template <typename OtherNumber>
  explicit constexpr SpecificIsochoricHeatCapacity(
      const SpecificIsochoricHeatCapacity<OtherNumber>& other)
    : SpecificIsochoricHeatCapacity(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a specific isochoric heat capacity by moving another one.
  constexpr SpecificIsochoricHeatCapacity(
      SpecificIsochoricHeatCapacity<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this specific isochoric heat capacity by copying another one.
  constexpr SpecificIsochoricHeatCapacity<Number>& operator=(
      const SpecificIsochoricHeatCapacity<Number>& other) = default;

  // Copy assignment operator. Assigns this specific isochoric heat capacity by copying another one.
  template <typename OtherNumber>
  constexpr SpecificIsochoricHeatCapacity<Number>& operator=(
      const SpecificIsochoricHeatCapacity<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this specific isochoric heat capacity by moving another one.
  constexpr SpecificIsochoricHeatCapacity<Number>& operator=(
      SpecificIsochoricHeatCapacity<Number>&& other) noexcept = default;

  // Statically creates a specific isochoric heat capacity of zero.
  static constexpr SpecificIsochoricHeatCapacity<Number> Zero() {
    return SpecificIsochoricHeatCapacity<Number>{static_cast<Number>(0)};
  }

  // Statically creates a specific isochoric heat capacity with a given value expressed in a given
  // specific heat capacity unit.
  template <Unit::SpecificHeatCapacity Unit>
  static constexpr SpecificIsochoricHeatCapacity<Number> Create(const Number value) {
    return SpecificIsochoricHeatCapacity<Number>{
        StaticConvertCopy<Unit::SpecificHeatCapacity, Unit, Standard<Unit::SpecificHeatCapacity>>(
            value)};
  }

  constexpr SpecificIsochoricHeatCapacity<Number> operator+(
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) const {
    return SpecificIsochoricHeatCapacity<Number>{
        this->value + specific_isochoric_heat_capacity.value};
  }

  constexpr SpecificIsobaricHeatCapacity<Number> operator+(
      const SpecificGasConstant<Number>& specific_gas_constant) const;

  constexpr SpecificIsochoricHeatCapacity<Number> operator-(
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) const {
    return SpecificIsochoricHeatCapacity<Number>{
        this->value - specific_isochoric_heat_capacity.value};
  }

  constexpr SpecificIsochoricHeatCapacity<Number> operator*(const Number number) const {
    return SpecificIsochoricHeatCapacity<Number>{this->value * number};
  }

  constexpr IsochoricHeatCapacity<Number> operator*(const Mass<Number>& mass) const {
    return IsochoricHeatCapacity<Number>{*this, mass};
  }

  constexpr SpecificIsobaricHeatCapacity<Number> operator*(
      const HeatCapacityRatio<Number>& heat_capacity_ratio) const;

  constexpr SpecificIsochoricHeatCapacity<Number> operator/(const Number number) const {
    return SpecificIsochoricHeatCapacity<Number>{this->value / number};
  }

  constexpr Number operator/(
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity)
      const noexcept {
    return this->value / specific_isochoric_heat_capacity.value;
  }

  constexpr void operator+=(
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) noexcept {
    this->value += specific_isochoric_heat_capacity.value;
  }

  constexpr void operator-=(
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) noexcept {
    this->value -= specific_isochoric_heat_capacity.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a specific isochoric heat capacity with a given value expressed in the
  // standard specific heat capacity unit.
  explicit constexpr SpecificIsochoricHeatCapacity(const Number value)
    : DimensionalScalar<Unit::SpecificHeatCapacity, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const SpecificIsochoricHeatCapacity<Number>& left,
                                 const SpecificIsochoricHeatCapacity<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const SpecificIsochoricHeatCapacity<Number>& left,
                                 const SpecificIsochoricHeatCapacity<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const SpecificIsochoricHeatCapacity<Number>& left,
                                const SpecificIsochoricHeatCapacity<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const SpecificIsochoricHeatCapacity<Number>& left,
                                const SpecificIsochoricHeatCapacity<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const SpecificIsochoricHeatCapacity<Number>& left,
                                 const SpecificIsochoricHeatCapacity<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const SpecificIsochoricHeatCapacity<Number>& left,
                                 const SpecificIsochoricHeatCapacity<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream,
    const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) {
  stream << specific_isochoric_heat_capacity.Print();
  return stream;
}

template <typename Number>
inline constexpr SpecificIsochoricHeatCapacity<Number> operator*(
    const Number number,
    const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) {
  return specific_isochoric_heat_capacity * number;
}

template <typename Number>
inline constexpr Mass<Number>::Mass(
    const IsochoricHeatCapacity<Number>& isochoric_heat_capacity,
    const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity)
  : Mass<Number>(isochoric_heat_capacity.Value() / specific_isochoric_heat_capacity.Value()) {}

template <typename Number>
inline constexpr IsochoricHeatCapacity<Number>::IsochoricHeatCapacity(
    const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity,
    const Mass<Number>& mass)
  : IsochoricHeatCapacity<Number>(specific_isochoric_heat_capacity.Value() * mass.Value()) {}

template <typename Number>
inline constexpr IsochoricHeatCapacity<Number> Mass<Number>::operator*(
    const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) const {
  return IsochoricHeatCapacity<Number>{specific_isochoric_heat_capacity, *this};
}

template <typename Number>
inline constexpr SpecificIsochoricHeatCapacity<Number> IsochoricHeatCapacity<Number>::operator/(
    const Mass<Number>& mass) const {
  return SpecificIsochoricHeatCapacity<Number>{*this, mass};
}

template <typename Number>
inline constexpr Mass<Number> IsochoricHeatCapacity<Number>::operator/(
    const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) const {
  return Mass<Number>{*this, specific_isochoric_heat_capacity};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::SpecificIsochoricHeatCapacity<Number>> {
  inline size_t operator()(
      const PhQ::SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity) const {
    return hash<Number>()(specific_isochoric_heat_capacity.Value());
  }
};

}  // namespace std

#endif  // PHQ_SPECIFIC_ISOCHORIC_HEAT_CAPACITY_HPP
