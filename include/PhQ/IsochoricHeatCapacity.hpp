// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
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

/// \brief Isochoric heat capacity, also known as heat capacity at constant volume. For the
/// mass-specific isochoric heat capacity, see PhQ::SpecificIsochoricHeatCapacity.
template <typename NumericType = double>
class IsochoricHeatCapacity : public DimensionalScalar<Unit::HeatCapacity, NumericType> {
public:
  /// \brief Default constructor. Constructs an isochoric heat capacity with an uninitialized value.
  IsochoricHeatCapacity() = default;

  /// \brief Constructor. Constructs an isochoric heat capacity with a given value expressed in a
  /// given heat capacity unit.
  IsochoricHeatCapacity(const NumericType value, const Unit::HeatCapacity unit)
    : DimensionalScalar<Unit::HeatCapacity, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs an isochoric heat capacity from a given gas constant and
  /// isobaric heat capacity using Mayer's relation.
  constexpr IsochoricHeatCapacity(const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity,
                                  const GasConstant<NumericType>& gas_constant);

  /// \brief Constructor. Constructs an isochoric heat capacity from a given gas constant and heat
  /// capacity ratio using the definition of the specific heat ratio and Mayer's relation.
  constexpr IsochoricHeatCapacity(const GasConstant<NumericType>& gas_constant,
                                  const HeatCapacityRatio<NumericType>& heat_capacity_ratio);

  /// \brief Constructor. Constructs an isochoric heat capacity from a given isobaric heat capacity
  /// and heat capacity ratio using the definition of the specific heat ratio.
  constexpr IsochoricHeatCapacity(const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity,
                                  const HeatCapacityRatio<NumericType>& heat_capacity_ratio);

  /// \brief Constructor. Constructs an isochoric heat capacity from a given specific isochoric heat
  /// capacity and mass using the definition of the specific isochoric heat capacity.
  constexpr IsochoricHeatCapacity(
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity,
      const Mass<NumericType>& mass);

  /// \brief Destructor. Destroys this isochoric heat capacity.
  ~IsochoricHeatCapacity() noexcept = default;

  /// \brief Copy constructor. Constructs an isochoric heat capacity by copying another one.
  constexpr IsochoricHeatCapacity(const IsochoricHeatCapacity<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a isochoric heat capacity by copying another one.
  template <typename OtherNumericType>
  explicit constexpr IsochoricHeatCapacity(const IsochoricHeatCapacity<OtherNumericType>& other)
    : IsochoricHeatCapacity(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs an isochoric heat capacity by moving another one.
  constexpr IsochoricHeatCapacity(IsochoricHeatCapacity<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this isochoric heat capacity by copying another one.
  constexpr IsochoricHeatCapacity<NumericType>& operator=(
      const IsochoricHeatCapacity<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this isochoric heat capacity by copying another one.
  template <typename OtherNumericType>
  constexpr IsochoricHeatCapacity<NumericType>& operator=(
      const IsochoricHeatCapacity<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this isochoric heat capacity by moving another one.
  constexpr IsochoricHeatCapacity<NumericType>& operator=(
      IsochoricHeatCapacity<NumericType>&& other) noexcept = default;

  /// \brief Statically creates an isochoric heat capacity of zero.
  static constexpr IsochoricHeatCapacity<NumericType> Zero() {
    return IsochoricHeatCapacity<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates an isochoric heat capacity with a given value expressed in a given
  /// heat capacity unit.
  template <Unit::HeatCapacity Unit>
  static constexpr IsochoricHeatCapacity<NumericType> Create(const NumericType value) {
    return IsochoricHeatCapacity<NumericType>{
        ConvertStatically<Unit::HeatCapacity, Unit, Standard<Unit::HeatCapacity>>(value)};
  }

  constexpr IsochoricHeatCapacity<NumericType> operator+(
      const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity) const {
    return IsochoricHeatCapacity<NumericType>{this->value + isochoric_heat_capacity.value};
  }

  constexpr IsobaricHeatCapacity<NumericType> operator+(
      const GasConstant<NumericType>& gas_constant) const;

  constexpr IsochoricHeatCapacity<NumericType> operator-(
      const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity) const {
    return IsochoricHeatCapacity<NumericType>{this->value - isochoric_heat_capacity.value};
  }

  constexpr IsochoricHeatCapacity<NumericType> operator*(const NumericType number) const {
    return IsochoricHeatCapacity<NumericType>{this->value * number};
  }

  constexpr IsobaricHeatCapacity<NumericType> operator*(
      const HeatCapacityRatio<NumericType>& heat_capacity_ratio) const;

  constexpr IsochoricHeatCapacity<NumericType> operator/(const NumericType number) const {
    return IsochoricHeatCapacity<NumericType>{this->value / number};
  }

  constexpr SpecificIsochoricHeatCapacity<NumericType> operator/(
      const Mass<NumericType>& mass) const;

  constexpr Mass<NumericType> operator/(
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity) const;

  constexpr NumericType operator/(
      const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity) const noexcept {
    return this->value / isochoric_heat_capacity.value;
  }

  constexpr void operator+=(
      const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity) noexcept {
    this->value += isochoric_heat_capacity.value;
  }

  constexpr void operator-=(
      const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity) noexcept {
    this->value -= isochoric_heat_capacity.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs an isochoric heat capacity with a given value expressed in the
  /// standard heat capacity unit.
  explicit constexpr IsochoricHeatCapacity(const NumericType value)
    : DimensionalScalar<Unit::HeatCapacity, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const IsochoricHeatCapacity<NumericType>& left,
                                 const IsochoricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const IsochoricHeatCapacity<NumericType>& left,
                                 const IsochoricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const IsochoricHeatCapacity<NumericType>& left,
                                const IsochoricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const IsochoricHeatCapacity<NumericType>& left,
                                const IsochoricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const IsochoricHeatCapacity<NumericType>& left,
                                 const IsochoricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const IsochoricHeatCapacity<NumericType>& left,
                                 const IsochoricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity) {
  stream << isochoric_heat_capacity.Print();
  return stream;
}

template <typename NumericType>
inline constexpr IsochoricHeatCapacity<NumericType> operator*(
    const NumericType number, const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity) {
  return isochoric_heat_capacity * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::IsochoricHeatCapacity<NumericType>> {
  inline size_t operator()(
      const PhQ::IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity) const {
    return hash<NumericType>()(isochoric_heat_capacity.Value());
  }
};

}  // namespace std

#endif  // PHQ_ISOCHORIC_HEAT_CAPACITY_HPP
