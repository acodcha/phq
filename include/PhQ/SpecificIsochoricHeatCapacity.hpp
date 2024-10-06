// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

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

/// \brief Mass-specific isochoric heat capacity, also known as mass-specific heat capacity at
/// constant volume, or isochoric heat capacity per unit mass; see PhQ::IsochoricHeatCapacity and
/// PhQ::Mass.
template <typename NumericType = double>
class SpecificIsochoricHeatCapacity
  : public DimensionalScalar<Unit::SpecificHeatCapacity, NumericType> {
public:
  /// \brief Default constructor. Constructs a specific isochoric heat capacity with an
  /// uninitialized value.
  SpecificIsochoricHeatCapacity() = default;

  /// \brief Constructor. Constructs a specific isochoric heat capacity with a given value expressed
  /// in a given specific heat capacity unit.
  SpecificIsochoricHeatCapacity(const NumericType value, const Unit::SpecificHeatCapacity unit)
    : DimensionalScalar<Unit::SpecificHeatCapacity, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a specific isochoric heat capacity from a given specific gas
  /// constant and specific isobaric heat capacity using Mayer's relation.
  constexpr SpecificIsochoricHeatCapacity(
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity,
      const SpecificGasConstant<NumericType>& specific_gas_constant);

  /// \brief Constructor. Constructs a specific isochoric heat capacity from a given specific gas
  /// constant and heat capacity ratio using the definition of the heat capacity ratio and Mayer's
  /// relation.
  constexpr SpecificIsochoricHeatCapacity(
      const SpecificGasConstant<NumericType>& specific_gas_constant,
      const HeatCapacityRatio<NumericType>& heat_capacity_ratio);

  /// \brief Constructor. Constructs a specific isochoric heat capacity from a given specific
  /// isobaric heat capacity and heat capacity ratio using the definition of the heat capacity
  /// ratio.
  constexpr SpecificIsochoricHeatCapacity(
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity,
      const HeatCapacityRatio<NumericType>& heat_capacity_ratio);

  /// \brief Constructor. Constructs a specific isochoric heat capacity from a given isochoric heat
  /// capacity and mass using the definition of the specific isochoric heat capacity.
  constexpr SpecificIsochoricHeatCapacity(
      const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity,
      const Mass<NumericType>& mass)
    : SpecificIsochoricHeatCapacity<NumericType>(isochoric_heat_capacity.Value() / mass.Value()) {}

  /// \brief Destructor. Destroys this specific isochoric heat capacity.
  ~SpecificIsochoricHeatCapacity() noexcept = default;

  /// \brief Copy constructor. Constructs a specific isochoric heat capacity by copying another one.
  constexpr SpecificIsochoricHeatCapacity(
      const SpecificIsochoricHeatCapacity<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a specific isochoric heat capacity by copying another one.
  template <typename OtherNumericType>
  explicit constexpr SpecificIsochoricHeatCapacity(
      const SpecificIsochoricHeatCapacity<OtherNumericType>& other)
    : SpecificIsochoricHeatCapacity(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a specific isochoric heat capacity by moving another one.
  constexpr SpecificIsochoricHeatCapacity(
      SpecificIsochoricHeatCapacity<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this specific isochoric heat capacity by copying
  /// another one.
  constexpr SpecificIsochoricHeatCapacity<NumericType>& operator=(
      const SpecificIsochoricHeatCapacity<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this specific isochoric heat capacity by copying
  /// another one.
  template <typename OtherNumericType>
  constexpr SpecificIsochoricHeatCapacity<NumericType>& operator=(
      const SpecificIsochoricHeatCapacity<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this specific isochoric heat capacity by moving
  /// another one.
  constexpr SpecificIsochoricHeatCapacity<NumericType>& operator=(
      SpecificIsochoricHeatCapacity<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a specific isochoric heat capacity of zero.
  [[nodiscard]] static constexpr SpecificIsochoricHeatCapacity<NumericType> Zero() {
    return SpecificIsochoricHeatCapacity<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a specific isochoric heat capacity with a given value expressed in a
  /// given specific heat capacity unit.
  template <Unit::SpecificHeatCapacity Unit>
  [[nodiscard]] static constexpr SpecificIsochoricHeatCapacity<NumericType> Create(
      const NumericType value) {
    return SpecificIsochoricHeatCapacity<NumericType>{
      ConvertStatically<Unit::SpecificHeatCapacity, Unit, Standard<Unit::SpecificHeatCapacity>>(
          value)};
  }

  constexpr SpecificIsochoricHeatCapacity<NumericType> operator+(
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity) const {
    return SpecificIsochoricHeatCapacity<NumericType>{
      this->value + specific_isochoric_heat_capacity.value};
  }

  constexpr SpecificIsobaricHeatCapacity<NumericType> operator+(
      const SpecificGasConstant<NumericType>& specific_gas_constant) const;

  constexpr SpecificIsochoricHeatCapacity<NumericType> operator-(
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity) const {
    return SpecificIsochoricHeatCapacity<NumericType>{
      this->value - specific_isochoric_heat_capacity.value};
  }

  constexpr SpecificIsochoricHeatCapacity<NumericType> operator*(const NumericType number) const {
    return SpecificIsochoricHeatCapacity<NumericType>{this->value * number};
  }

  constexpr IsochoricHeatCapacity<NumericType> operator*(const Mass<NumericType>& mass) const {
    return IsochoricHeatCapacity<NumericType>{*this, mass};
  }

  constexpr SpecificIsobaricHeatCapacity<NumericType> operator*(
      const HeatCapacityRatio<NumericType>& heat_capacity_ratio) const;

  constexpr SpecificIsochoricHeatCapacity<NumericType> operator/(const NumericType number) const {
    return SpecificIsochoricHeatCapacity<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity)
      const noexcept {
    return this->value / specific_isochoric_heat_capacity.value;
  }

  constexpr void operator+=(
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity) noexcept {
    this->value += specific_isochoric_heat_capacity.value;
  }

  constexpr void operator-=(
      const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity) noexcept {
    this->value -= specific_isochoric_heat_capacity.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a specific isochoric heat capacity with a given value expressed
  /// in the standard specific heat capacity unit.
  explicit constexpr SpecificIsochoricHeatCapacity(const NumericType value)
    : DimensionalScalar<Unit::SpecificHeatCapacity, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const SpecificIsochoricHeatCapacity<NumericType>& left,
                                 const SpecificIsochoricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const SpecificIsochoricHeatCapacity<NumericType>& left,
                                 const SpecificIsochoricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const SpecificIsochoricHeatCapacity<NumericType>& left,
                                const SpecificIsochoricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const SpecificIsochoricHeatCapacity<NumericType>& left,
                                const SpecificIsochoricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const SpecificIsochoricHeatCapacity<NumericType>& left,
                                 const SpecificIsochoricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const SpecificIsochoricHeatCapacity<NumericType>& left,
                                 const SpecificIsochoricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream,
    const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity) {
  stream << specific_isochoric_heat_capacity.Print();
  return stream;
}

template <typename NumericType>
inline constexpr SpecificIsochoricHeatCapacity<NumericType> operator*(
    const NumericType number,
    const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity) {
  return specific_isochoric_heat_capacity * number;
}

template <typename NumericType>
inline constexpr Mass<NumericType>::Mass(
    const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity,
    const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity)
  : Mass<NumericType>(isochoric_heat_capacity.Value() / specific_isochoric_heat_capacity.Value()) {}

template <typename NumericType>
inline constexpr IsochoricHeatCapacity<NumericType>::IsochoricHeatCapacity(
    const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity,
    const Mass<NumericType>& mass)
  : IsochoricHeatCapacity<NumericType>(specific_isochoric_heat_capacity.Value() * mass.Value()) {}

template <typename NumericType>
inline constexpr IsochoricHeatCapacity<NumericType> Mass<NumericType>::operator*(
    const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity) const {
  return IsochoricHeatCapacity<NumericType>{specific_isochoric_heat_capacity, *this};
}

template <typename NumericType>
inline constexpr SpecificIsochoricHeatCapacity<NumericType> IsochoricHeatCapacity<NumericType>::
operator/(const Mass<NumericType>& mass) const {
  return SpecificIsochoricHeatCapacity<NumericType>{*this, mass};
}

template <typename NumericType>
inline constexpr Mass<NumericType> IsochoricHeatCapacity<NumericType>::operator/(
    const SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity) const {
  return Mass<NumericType>{*this, specific_isochoric_heat_capacity};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::SpecificIsochoricHeatCapacity<NumericType>> {
  inline size_t operator()(
      const PhQ::
          SpecificIsochoricHeatCapacity<NumericType>& specific_isochoric_heat_capacity) const {
    return hash<NumericType>()(specific_isochoric_heat_capacity.Value());
  }
};

}  // namespace std

#endif  // PHQ_SPECIFIC_ISOCHORIC_HEAT_CAPACITY_HPP
