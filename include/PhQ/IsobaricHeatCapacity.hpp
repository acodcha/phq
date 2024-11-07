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

/// \brief Isobaric heat capacity, also known as heat capacity at constant pressure. For the
/// mass-specific isobaric heat capacity, see PhQ::SpecificIsobaricHeatCapacity.
template <typename NumericType = double>
class IsobaricHeatCapacity : public DimensionalScalar<Unit::HeatCapacity, NumericType> {
public:
  /// \brief Default constructor. Constructs an isobaric heat capacity with an uninitialized value.
  IsobaricHeatCapacity() = default;

  /// \brief Constructor. Constructs an isobaric heat capacity with a given value expressed in a
  /// given heat capacity unit.
  IsobaricHeatCapacity(const NumericType value, const Unit::HeatCapacity unit)
    : DimensionalScalar<Unit::HeatCapacity, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs an isobaric heat capacity from a given gas constant and
  /// isochoric heat capacity using Mayer's relation.
  constexpr IsobaricHeatCapacity(const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity,
                                 const GasConstant<NumericType>& gas_constant);

  /// \brief Constructor. Constructs an isobaric heat capacity from a given gas constant and heat
  /// capacity ratio using the definition of the heat capacity ratio and Mayer's relation.
  constexpr IsobaricHeatCapacity(const HeatCapacityRatio<NumericType>& heat_capacity_ratio,
                                 const GasConstant<NumericType>& gas_constant);

  /// \brief Constructor. Constructs an isobaric heat capacity from a given isochoric heat capacity
  /// and heat capacity ratio using the definition of the specific heat ratio.
  constexpr IsobaricHeatCapacity(const HeatCapacityRatio<NumericType>& heat_capacity_ratio,
                                 const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity)
    : IsobaricHeatCapacity<NumericType>(
          heat_capacity_ratio.Value() * isochoric_heat_capacity.Value()) {}

  /// \brief Constructor. Constructs an isobaric heat capacity from a given specific isobaric heat
  /// capacity and mass using the definition of the specific isobaric heat capacity.
  constexpr IsobaricHeatCapacity(
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity,
      const Mass<NumericType>& mass);

  /// \brief Destructor. Destroys this isobaric heat capacity.
  ~IsobaricHeatCapacity() noexcept = default;

  /// \brief Copy constructor. Constructs an isobaric heat capacity by copying another one.
  constexpr IsobaricHeatCapacity(const IsobaricHeatCapacity<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a isobaric heat capacity by copying another one.
  template <typename OtherNumericType>
  explicit constexpr IsobaricHeatCapacity(const IsobaricHeatCapacity<OtherNumericType>& other)
    : IsobaricHeatCapacity(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs an isobaric heat capacity by moving another one.
  constexpr IsobaricHeatCapacity(IsobaricHeatCapacity<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this isobaric heat capacity by copying another one.
  constexpr IsobaricHeatCapacity<NumericType>& operator=(
      const IsobaricHeatCapacity<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this isobaric heat capacity by copying another one.
  template <typename OtherNumericType>
  constexpr IsobaricHeatCapacity<NumericType>& operator=(
      const IsobaricHeatCapacity<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this isobaric heat capacity by moving another one.
  constexpr IsobaricHeatCapacity<NumericType>& operator=(
      IsobaricHeatCapacity<NumericType>&& other) noexcept = default;

  /// \brief Statically creates an isobaric heat capacity of zero.
  [[nodiscard]] static constexpr IsobaricHeatCapacity<NumericType> Zero() {
    return IsobaricHeatCapacity<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates an isobaric heat capacity with a given value expressed in a given
  /// heat capacity unit.
  template <Unit::HeatCapacity Unit>
  [[nodiscard]] static constexpr IsobaricHeatCapacity<NumericType> Create(const NumericType value) {
    return IsobaricHeatCapacity<NumericType>{
      ConvertStatically<Unit::HeatCapacity, Unit, Standard<Unit::HeatCapacity>>(value)};
  }

  constexpr IsobaricHeatCapacity<NumericType> operator+(
      const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity) const {
    return IsobaricHeatCapacity<NumericType>{this->value + isobaric_heat_capacity.value};
  }

  constexpr IsobaricHeatCapacity<NumericType> operator-(
      const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity) const {
    return IsobaricHeatCapacity<NumericType>{this->value - isobaric_heat_capacity.value};
  }

  constexpr GasConstant<NumericType> operator-(
      const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity) const;

  constexpr IsochoricHeatCapacity<NumericType> operator-(
      const GasConstant<NumericType>& gas_constant) const;

  constexpr IsobaricHeatCapacity<NumericType> operator*(const NumericType number) const {
    return IsobaricHeatCapacity<NumericType>{this->value * number};
  }

  constexpr IsobaricHeatCapacity<NumericType> operator/(const NumericType number) const {
    return IsobaricHeatCapacity<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity) const noexcept {
    return this->value / isobaric_heat_capacity.value;
  }

  constexpr SpecificIsobaricHeatCapacity<NumericType> operator/(
      const Mass<NumericType>& mass) const;

  constexpr Mass<NumericType> operator/(
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity) const;

  constexpr HeatCapacityRatio<NumericType> operator/(
      const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity) const {
    return HeatCapacityRatio<NumericType>{*this, isochoric_heat_capacity};
  }

  constexpr IsochoricHeatCapacity<NumericType> operator/(
      const HeatCapacityRatio<NumericType>& heat_capacity_ratio) const {
    return IsochoricHeatCapacity<NumericType>{*this, heat_capacity_ratio};
  }

  constexpr void operator+=(
      const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity) noexcept {
    this->value += isobaric_heat_capacity.value;
  }

  constexpr void operator-=(
      const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity) noexcept {
    this->value -= isobaric_heat_capacity.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs an isobaric heat capacity with a given value expressed in the
  /// standard heat capacity unit.
  explicit constexpr IsobaricHeatCapacity(const NumericType value)
    : DimensionalScalar<Unit::HeatCapacity, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const IsobaricHeatCapacity<NumericType>& left,
                                 const IsobaricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const IsobaricHeatCapacity<NumericType>& left,
                                 const IsobaricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const IsobaricHeatCapacity<NumericType>& left,
                                const IsobaricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const IsobaricHeatCapacity<NumericType>& left,
                                const IsobaricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const IsobaricHeatCapacity<NumericType>& left,
                                 const IsobaricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const IsobaricHeatCapacity<NumericType>& left,
                                 const IsobaricHeatCapacity<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity) {
  stream << isobaric_heat_capacity.Print();
  return stream;
}

template <typename NumericType>
inline constexpr IsobaricHeatCapacity<NumericType> operator*(
    const NumericType number, const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity) {
  return isobaric_heat_capacity * number;
}

template <typename NumericType>
inline constexpr HeatCapacityRatio<NumericType>::HeatCapacityRatio(
    const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity,
    const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity)
  : HeatCapacityRatio<NumericType>(
        isobaric_heat_capacity.Value() / isochoric_heat_capacity.Value()) {}

template <typename NumericType>
inline constexpr IsochoricHeatCapacity<NumericType>::IsochoricHeatCapacity(
    const IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity,
    const HeatCapacityRatio<NumericType>& heat_capacity_ratio)
  : IsochoricHeatCapacity<NumericType>(
        isobaric_heat_capacity.Value() / heat_capacity_ratio.Value()) {}

template <typename NumericType>
inline constexpr IsobaricHeatCapacity<NumericType> HeatCapacityRatio<NumericType>::operator*(
    const IsochoricHeatCapacity<NumericType>& isochoric_heat_capacity) const {
  return IsobaricHeatCapacity<NumericType>{*this, isochoric_heat_capacity};
}

template <typename NumericType>
inline constexpr IsobaricHeatCapacity<NumericType> IsochoricHeatCapacity<NumericType>::operator*(
    const HeatCapacityRatio<NumericType>& heat_capacity_ratio) const {
  return IsobaricHeatCapacity<NumericType>{heat_capacity_ratio, *this};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::IsobaricHeatCapacity<NumericType>> {
  inline size_t operator()(
      const PhQ::IsobaricHeatCapacity<NumericType>& isobaric_heat_capacity) const {
    return hash<NumericType>()(isobaric_heat_capacity.Value());
  }
};

}  // namespace std

#endif  // PHQ_ISOBARIC_HEAT_CAPACITY_HPP
