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

#ifndef PHQ_ISOCHORIC_HEAT_CAPACITY_HPP
#define PHQ_ISOCHORIC_HEAT_CAPACITY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "HeatCapacityRatio.hpp"
#include "Unit/HeatCapacity.hpp"

namespace PhQ {

/// \brief Isochoric heat capacity, also known as heat capacity at constant volume.
template <typename Number = double>
class IsochoricHeatCapacity : public DimensionalScalar<Unit::HeatCapacity, Number> {
public:
  /// \brief Default constructor. Constructs an isochoric heat capacity with an uninitialized value.
  IsochoricHeatCapacity() = default;

  /// \brief Constructor. Constructs an isochoric heat capacity with a given value expressed in a
  /// given heat capacity unit.
  IsochoricHeatCapacity(const Number value, const Unit::HeatCapacity unit)
    : DimensionalScalar<Unit::HeatCapacity, Number>(value, unit) {}

  /// \brief Constructor. Constructs an isochoric heat capacity from a given gas constant and
  /// isobaric heat capacity using Mayer's relation.
  constexpr IsochoricHeatCapacity(const IsobaricHeatCapacity<Number>& isobaric_heat_capacity,
                                  const GasConstant<Number>& gas_constant);

  /// \brief Constructor. Constructs an isochoric heat capacity from a given gas constant and heat
  /// capacity ratio using the definition of the specific heat ratio and Mayer's relation.
  constexpr IsochoricHeatCapacity(const GasConstant<Number>& gas_constant,
                                  const HeatCapacityRatio<Number>& heat_capacity_ratio);

  /// \brief Constructor. Constructs an isochoric heat capacity from a given isobaric heat capacity
  /// and heat capacity ratio using the definition of the specific heat ratio.
  constexpr IsochoricHeatCapacity(const IsobaricHeatCapacity<Number>& isobaric_heat_capacity,
                                  const HeatCapacityRatio<Number>& heat_capacity_ratio);

  /// \brief Constructor. Constructs an isochoric heat capacity from a given specific isochoric heat
  /// capacity and mass using the definition of the specific isochoric heat capacity.
  constexpr IsochoricHeatCapacity(
      const SpecificIsochoricHeatCapacity<Number>& specific_isochoric_heat_capacity,
      const Mass<Number>& mass);

  /// \brief Destructor. Destroys this isochoric heat capacity.
  ~IsochoricHeatCapacity() noexcept = default;

  /// \brief Copy constructor. Constructs an isochoric heat capacity by copying another one.
  constexpr IsochoricHeatCapacity(const IsochoricHeatCapacity<Number>& other) = default;

  /// \brief Copy constructor. Constructs a isochoric heat capacity by copying another one.
  template <typename OtherNumber>
  explicit constexpr IsochoricHeatCapacity(const IsochoricHeatCapacity<OtherNumber>& other)
    : IsochoricHeatCapacity(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs an isochoric heat capacity by moving another one.
  constexpr IsochoricHeatCapacity(IsochoricHeatCapacity<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this isochoric heat capacity by copying another one.
  constexpr IsochoricHeatCapacity<Number>& operator=(
      const IsochoricHeatCapacity<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this isochoric heat capacity by copying another one.
  template <typename OtherNumber>
  constexpr IsochoricHeatCapacity<Number>& operator=(
      const IsochoricHeatCapacity<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this isochoric heat capacity by moving another one.
  constexpr IsochoricHeatCapacity<Number>& operator=(
      IsochoricHeatCapacity<Number>&& other) noexcept = default;

  /// \brief Statically creates an isochoric heat capacity of zero.
  static constexpr IsochoricHeatCapacity<Number> Zero() {
    return IsochoricHeatCapacity<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates an isochoric heat capacity with a given value expressed in a given
  /// heat capacity unit.
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
  /// \brief Constructor. Constructs an isochoric heat capacity with a given value expressed in the
  /// standard heat capacity unit.
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
