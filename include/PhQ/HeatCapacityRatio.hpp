// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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

#ifndef PHQ_HEAT_CAPACITY_RATIO_HPP
#define PHQ_HEAT_CAPACITY_RATIO_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"

namespace PhQ {

// Forward declaration for class PhQ::HeatCapacityRatio.
template <typename NumericType>
class GasConstant;

// Forward declaration for class PhQ::HeatCapacityRatio.
template <typename NumericType>
class IsobaricHeatCapacity;

// Forward declaration for class PhQ::HeatCapacityRatio.
template <typename NumericType>
class IsochoricHeatCapacity;

// Forward declaration for class PhQ::HeatCapacityRatio.
template <typename NumericType>
class Mass;

// Forward declaration for class PhQ::HeatCapacityRatio.
template <typename NumericType>
class SpecificGasConstant;

// Forward declaration for class PhQ::HeatCapacityRatio.
template <typename NumericType>
class SpecificIsobaricHeatCapacity;

// Forward declaration for class PhQ::HeatCapacityRatio.
template <typename NumericType>
class SpecificIsochoricHeatCapacity;

/// \brief Heat capacity ratio, also known as ratio of specific heats, adiabatic index, or Laplace's
/// coefficient. A material's heat capacity ratio is the ratio of its isobaric heat capacity to its
/// isochoric heat capacity; see PhQ::IsobaricHeatCapacity and PhQ::IsochoricHeatCapacity.
template <typename NumericType = double>
class HeatCapacityRatio : public DimensionlessScalar<NumericType> {
public:
  /// \brief Default constructor. Constructs a heat capacity ratio ratio with an uninitialized
  /// value.
  HeatCapacityRatio() = default;

  /// \brief Constructor. Constructs a heat capacity ratio with a given value.
  explicit constexpr HeatCapacityRatio(const NumericType value)
    : DimensionlessScalar<NumericType>(value) {}

  /// \brief Constructor. Constructs a heat capacity ratio from a given specific gas constant and
  /// specific isobaric heat capacity using Mayer's relation and the definition of the heat capacity
  /// ratio.
  constexpr HeatCapacityRatio(
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity,
      const SpecificGasConstant<NumericType>& specific_gas_constant);

  /// \brief Constructor. Constructs a heat capacity ratio from a given specific gas constant and
  /// specific isochoric heat capacity using Mayer's relation and the definition of the heat
  /// capacity ratio.
  constexpr HeatCapacityRatio(
      const SpecificGasConstant<NumericType>& specific_gas_constant,
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity);

  /// \brief Constructor. Constructs a heat capacity ratio from a given specific isobaric heat
  /// capacity and specific isochoric heat capacity using the definition of the heat capacity ratio.
  constexpr HeatCapacityRatio(
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity,
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity);

  /// \brief Constructor. Constructs a heat capacity ratio from a given gas constant and isobaric
  /// heat capacity using Mayer's relation and the definition of the heat capacity ratio.
  constexpr HeatCapacityRatio(const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity,
                              const GasConstant<NumericType>& gas_constant);

  /// \brief Constructor. Constructs a heat capacity ratio from a given gas constant and isochoric
  /// heat capacity using Mayer's relation and the definition of the heat capacity ratio.
  constexpr HeatCapacityRatio(const GasConstant<NumericType>& gas_constant,
                              const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity);

  /// \brief Constructor. Constructs a heat capacity ratio from a given isobaric heat capacity and
  /// isochoric heat capacity using the definition of the specific heat ratio.
  constexpr HeatCapacityRatio(const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity,
                              const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity);

  /// \brief Destructor. Destroys this heat capacity ratio.
  ~HeatCapacityRatio() noexcept = default;

  /// \brief Copy constructor. Constructs a heat capacity ratio by copying another one.
  constexpr HeatCapacityRatio(const HeatCapacityRatio<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a heat capacity ratio by copying another one.
  template <typename OtherNumericType>
  explicit constexpr HeatCapacityRatio(const HeatCapacityRatio<OtherNumericType>& other)
    : HeatCapacityRatio(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a heat capacity ratio by moving another one.
  constexpr HeatCapacityRatio(HeatCapacityRatio<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this heat capacity ratio by copying another one.
  constexpr HeatCapacityRatio<NumericType>& operator=(
      const HeatCapacityRatio<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this heat capacity ratio by copying another one.
  template <typename OtherNumericType>
  constexpr HeatCapacityRatio<NumericType>& operator=(
      const HeatCapacityRatio<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this heat capacity ratio by moving another one.
  constexpr HeatCapacityRatio<NumericType>& operator=(
      HeatCapacityRatio<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a heat capacity ratio of zero.
  static constexpr HeatCapacityRatio<NumericType> Zero() {
    return HeatCapacityRatio<NumericType>{static_cast<NumericType>(0)};
  }

  constexpr HeatCapacityRatio<NumericType> operator+(
      const HeatCapacityRatio<NumericType>& heat_capacity_ratio) const {
    return HeatCapacityRatio<NumericType>{this->value + heat_capacity_ratio.value};
  }

  constexpr HeatCapacityRatio<NumericType> operator-(
      const HeatCapacityRatio<NumericType>& heat_capacity_ratio) const {
    return HeatCapacityRatio<NumericType>{this->value - heat_capacity_ratio.value};
  }

  constexpr HeatCapacityRatio<NumericType> operator*(const NumericType number) const {
    return HeatCapacityRatio<NumericType>{this->value * number};
  }

  constexpr IsobaricHeatCapacity<NumericType> operator*(
      const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity) const;

  constexpr SpecificIsobaricHeatCapacity<NumericType> operator*(
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity) const;

  constexpr HeatCapacityRatio<NumericType> operator/(const NumericType number) const {
    return HeatCapacityRatio<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const HeatCapacityRatio<NumericType>& heat_capacity_ratio) const noexcept {
    return this->value / heat_capacity_ratio.value;
  }

  constexpr void operator+=(const HeatCapacityRatio<NumericType>& heat_capacity_ratio) noexcept {
    this->value += heat_capacity_ratio.value;
  }

  constexpr void operator-=(const HeatCapacityRatio<NumericType>& heat_capacity_ratio) noexcept {
    this->value -= heat_capacity_ratio.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }
};

template <typename NumericType>
inline constexpr bool operator==(const HeatCapacityRatio<NumericType>& left,
                                 const HeatCapacityRatio<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const HeatCapacityRatio<NumericType>& left,
                                 const HeatCapacityRatio<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const HeatCapacityRatio<NumericType>& left,
                                const HeatCapacityRatio<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const HeatCapacityRatio<NumericType>& left,
                                const HeatCapacityRatio<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const HeatCapacityRatio<NumericType>& left,
                                 const HeatCapacityRatio<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const HeatCapacityRatio<NumericType>& left,
                                 const HeatCapacityRatio<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const HeatCapacityRatio<NumericType>& heat_capacity_ratio) {
  stream << heat_capacity_ratio.Print();
  return stream;
}

template <typename NumericType>
inline constexpr HeatCapacityRatio<NumericType> operator*(
    const NumericType number, const HeatCapacityRatio<NumericType>& heat_capacity_ratio) {
  return HeatCapacityRatio<NumericType>{number * heat_capacity_ratio.Value()};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::HeatCapacityRatio<NumericType>> {
  inline size_t operator()(const PhQ::HeatCapacityRatio<NumericType>& heat_capacity_ratio) const {
    return hash<NumericType>()(heat_capacity_ratio.Value());
  }
};

}  // namespace std

#endif  // PHQ_HEAT_CAPACITY_RATIO_HPP
