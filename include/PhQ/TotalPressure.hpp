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

#ifndef PHQ_TOTAL_PRESSURE_HPP
#define PHQ_TOTAL_PRESSURE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "DynamicPressure.hpp"
#include "MassDensity.hpp"
#include "StaticPressure.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declaration for class PhQ::TotalPressure.
template <typename NumericType>
class TotalKinematicPressure;

/// \brief Total pressure, which is the sum of static pressure and dynamic pressure; see
/// PhQ::StaticPressure and PhQ::DynamicPressure. For total kinematic pressure, see
/// PhQ::TotalKinematicPressure.
template <typename NumericType = double>
class TotalPressure : public DimensionalScalar<Unit::Pressure, NumericType> {
public:
  /// \brief Default constructor. Constructs a total pressure with an uninitialized value.
  TotalPressure() = default;

  /// \brief Constructor. Constructs a total pressure with a given value expressed in a given
  /// pressure unit.
  TotalPressure(const NumericType value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a total pressure from a given static pressure and dynamic
  /// pressure using the definition of total pressure.
  constexpr TotalPressure(const StaticPressure<NumericType>& static_pressure,
                          const DynamicPressure<NumericType>& dynamic_pressure)
    : TotalPressure<NumericType>(static_pressure.Value() + dynamic_pressure.Value()) {}

  /// \brief Constructor. Constructs a total pressure from a given mass density and total kinematic
  /// pressure using the definition of total kinematic pressure.
  constexpr TotalPressure(const MassDensity<NumericType>& mass_density,
                          const TotalKinematicPressure<NumericType>& total_kinematic_pressure);

  /// \brief Destructor. Destroys this total pressure.
  ~TotalPressure() noexcept = default;

  /// \brief Copy constructor. Constructs a total pressure by copying another one.
  constexpr TotalPressure(const TotalPressure<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a total pressure by copying another one.
  template <typename OtherNumericType>
  explicit constexpr TotalPressure(const TotalPressure<OtherNumericType>& other)
    : TotalPressure(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a total pressure by moving another one.
  constexpr TotalPressure(TotalPressure<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this total pressure by copying another one.
  constexpr TotalPressure<NumericType>& operator=(
      const TotalPressure<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this total pressure by copying another one.
  template <typename OtherNumericType>
  constexpr TotalPressure<NumericType>& operator=(const TotalPressure<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this total pressure by moving another one.
  constexpr TotalPressure<NumericType>& operator=(
      TotalPressure<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a total pressure of zero.
  static constexpr TotalPressure<NumericType> Zero() {
    return TotalPressure<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a total pressure with a given value expressed in a given pressure
  /// unit.
  template <Unit::Pressure Unit>
  static constexpr TotalPressure<NumericType> Create(const NumericType value) {
    return TotalPressure<NumericType>{
        ConvertStatically<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr TotalPressure<NumericType> operator+(
      const TotalPressure<NumericType>& total_pressure) const {
    return TotalPressure<NumericType>{this->value + total_pressure.value};
  }

  constexpr TotalPressure<NumericType> operator-(
      const TotalPressure<NumericType>& total_pressure) const {
    return TotalPressure<NumericType>{this->value - total_pressure.value};
  }

  constexpr DynamicPressure<NumericType> operator-(
      const StaticPressure<NumericType>& static_pressure) const {
    return DynamicPressure<NumericType>{*this, static_pressure};
  }

  constexpr StaticPressure<NumericType> operator-(
      const DynamicPressure<NumericType>& dynamic_pressure) const {
    return StaticPressure<NumericType>{*this, dynamic_pressure};
  }

  constexpr TotalPressure<NumericType> operator*(const NumericType number) const {
    return TotalPressure<NumericType>{this->value * number};
  }

  constexpr TotalPressure<NumericType> operator/(const NumericType number) const {
    return TotalPressure<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(const TotalPressure<NumericType>& total_pressure) const noexcept {
    return this->value / total_pressure.value;
  }

  constexpr TotalKinematicPressure<NumericType> operator/(
      const MassDensity<NumericType>& mass_density) const;

  constexpr void operator+=(const TotalPressure<NumericType>& total_pressure) noexcept {
    this->value += total_pressure.value;
  }

  constexpr void operator-=(const TotalPressure<NumericType>& total_pressure) noexcept {
    this->value -= total_pressure.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a total pressure with a given value expressed in the standard
  /// pressure unit.
  explicit constexpr TotalPressure(const NumericType value)
    : DimensionalScalar<Unit::Pressure, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const TotalPressure<NumericType>& left, const TotalPressure<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const TotalPressure<NumericType>& left, const TotalPressure<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const TotalPressure<NumericType>& left, const TotalPressure<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const TotalPressure<NumericType>& left, const TotalPressure<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const TotalPressure<NumericType>& left, const TotalPressure<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const TotalPressure<NumericType>& left, const TotalPressure<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const TotalPressure<NumericType>& total_pressure) {
  stream << total_pressure.Print();
  return stream;
}

template <typename NumericType>
inline constexpr TotalPressure<NumericType> operator*(
    const NumericType number, const TotalPressure<NumericType>& total_pressure) {
  return total_pressure * number;
}

template <typename NumericType>
inline constexpr StaticPressure<NumericType>::StaticPressure(
    const TotalPressure<NumericType>& total_pressure,
    const DynamicPressure<NumericType>& dynamic_pressure)
  : StaticPressure<NumericType>(total_pressure.Value() - dynamic_pressure.Value()) {}

template <typename NumericType>
inline constexpr DynamicPressure<NumericType>::DynamicPressure(
    const TotalPressure<NumericType>& total_pressure,
    const StaticPressure<NumericType>& static_pressure)
  : DynamicPressure<NumericType>(total_pressure.Value() - static_pressure.Value()) {}

template <typename NumericType>
inline constexpr TotalPressure<NumericType> StaticPressure<NumericType>::operator+(
    const DynamicPressure<NumericType>& dynamic_pressure) const {
  return TotalPressure<NumericType>{*this, dynamic_pressure};
}

template <typename NumericType>
inline constexpr TotalPressure<NumericType> DynamicPressure<NumericType>::operator+(
    const StaticPressure<NumericType>& static_pressure) const {
  return TotalPressure<NumericType>{static_pressure, *this};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::TotalPressure<NumericType>> {
  inline size_t operator()(const PhQ::TotalPressure<NumericType>& total_pressure) const {
    return hash<NumericType>()(total_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_TOTAL_PRESSURE_HPP
