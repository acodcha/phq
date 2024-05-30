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

#ifndef PHQ_DYNAMIC_PRESSURE_HPP
#define PHQ_DYNAMIC_PRESSURE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "MassDensity.hpp"
#include "Speed.hpp"
#include "StaticPressure.hpp"

namespace PhQ {

// Forward declaration for class PhQ::DynamicPressure.
template <typename NumericType>
class DynamicKinematicPressure;

/// \brief Dynamic pressure, which is the additional pressure arising from a flowing fluid's kinetic
/// energy. Dynamic pressure can be thought of as a flowing fluid's kinetic energy per unit volume.
/// Not to be confused with static pressure or total pressure; see PhQ::StaticPressure and
/// PhQ::TotalPressure. For dynamic kinematic pressure, see PhQ::DynamicKinematicPressure.
template <typename NumericType = double>
class DynamicPressure : public DimensionalScalar<Unit::Pressure, NumericType> {
public:
  /// \brief Default constructor. Constructs a dynamic pressure with an uninitialized value.
  DynamicPressure() = default;

  /// \brief Constructor. Constructs a dynamic pressure with a given value expressed in a given
  /// pressure unit.
  DynamicPressure(const NumericType value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a dynamic pressure from a given mass density and speed using
  /// the definition of dynamic pressure.
  constexpr DynamicPressure(
      const MassDensity<NumericType>& mass_density, const Speed<NumericType>& speed)
    : DynamicPressure<NumericType>(0.5 * mass_density.Value() * std::pow(speed.Value(), 2)) {}

  /// \brief Constructor. Constructs a dynamic pressure from a given total pressure and static
  /// pressure using the definition of total pressure.
  constexpr DynamicPressure(const TotalPressure<NumericType>& total_pressure,
                            const StaticPressure<NumericType>& static_pressure);

  /// \brief Constructor. Constructs a dynamic pressure from a given mass density and dynamic
  /// kinematic pressure using the definition of dynamic kinematic pressure.
  constexpr DynamicPressure(
      const MassDensity<NumericType>& mass_density,
      const DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure);

  /// \brief Destructor. Destroys this dynamic pressure.
  ~DynamicPressure() noexcept = default;

  /// \brief Copy constructor. Constructs a dynamic pressure by copying another one.
  constexpr DynamicPressure(const DynamicPressure<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a dynamic pressure by copying another one.
  template <typename OtherNumericType>
  explicit constexpr DynamicPressure(const DynamicPressure<OtherNumericType>& other)
    : DynamicPressure(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a dynamic pressure by moving another one.
  constexpr DynamicPressure(DynamicPressure<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this dynamic pressure by copying another one.
  constexpr DynamicPressure<NumericType>& operator=(
      const DynamicPressure<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this dynamic pressure by copying another one.
  template <typename OtherNumericType>
  constexpr DynamicPressure<NumericType>& operator=(
      const DynamicPressure<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this dynamic pressure by moving another one.
  constexpr DynamicPressure<NumericType>& operator=(
      DynamicPressure<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a dynamic pressure of zero.
  static constexpr DynamicPressure<NumericType> Zero() {
    return DynamicPressure<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a dynamic pressure with a given value expressed in a given pressure
  /// unit.
  template <Unit::Pressure Unit>
  static constexpr DynamicPressure<NumericType> Create(const NumericType value) {
    return DynamicPressure<NumericType>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr DynamicPressure<NumericType> operator+(
      const DynamicPressure<NumericType>& dynamic_pressure) const {
    return DynamicPressure<NumericType>{this->value + dynamic_pressure.value};
  }

  constexpr TotalPressure<NumericType> operator+(
      const StaticPressure<NumericType>& static_pressure) const;

  constexpr DynamicPressure<NumericType> operator-(
      const DynamicPressure<NumericType>& dynamic_pressure) const {
    return DynamicPressure<NumericType>{this->value - dynamic_pressure.value};
  }

  constexpr DynamicPressure<NumericType> operator*(const NumericType number) const {
    return DynamicPressure<NumericType>{this->value * number};
  }

  constexpr DynamicPressure<NumericType> operator/(const NumericType number) const {
    return DynamicPressure<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const DynamicPressure<NumericType>& dynamic_pressure) const noexcept {
    return this->value / dynamic_pressure.value;
  }

  constexpr DynamicKinematicPressure<NumericType> operator/(
      const MassDensity<NumericType>& mass_density) const;

  constexpr void operator+=(const DynamicPressure<NumericType>& dynamic_pressure) noexcept {
    this->value += dynamic_pressure.value;
  }

  constexpr void operator-=(const DynamicPressure<NumericType>& dynamic_pressure) noexcept {
    this->value -= dynamic_pressure.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a dynamic pressure with a given value expressed in the standard
  /// pressure unit.
  explicit constexpr DynamicPressure(const NumericType value)
    : DimensionalScalar<Unit::Pressure, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const DynamicPressure<NumericType>& left, const DynamicPressure<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const DynamicPressure<NumericType>& left, const DynamicPressure<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const DynamicPressure<NumericType>& left, const DynamicPressure<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const DynamicPressure<NumericType>& left, const DynamicPressure<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const DynamicPressure<NumericType>& left, const DynamicPressure<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const DynamicPressure<NumericType>& left, const DynamicPressure<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const DynamicPressure<NumericType>& dynamic_pressure) {
  stream << dynamic_pressure.Print();
  return stream;
}

template <typename NumericType>
inline constexpr DynamicPressure<NumericType> operator*(
    const NumericType number, const DynamicPressure<NumericType>& dynamic_pressure) {
  return dynamic_pressure * number;
}

template <typename NumericType>
inline constexpr MassDensity<NumericType>::MassDensity(
    const DynamicPressure<NumericType>& dynamic_pressure, const Speed<NumericType>& speed)
  : MassDensity<NumericType>(2.0 * dynamic_pressure.Value() / (speed.Value() * speed.Value())) {}

template <typename NumericType>
inline Speed<NumericType>::Speed(const DynamicPressure<NumericType>& dynamic_pressure,
                                 const MassDensity<NumericType>& mass_density)
  : Speed<NumericType>(std::sqrt(2.0 * dynamic_pressure.Value() / mass_density.Value())) {}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::DynamicPressure<NumericType>> {
  inline size_t operator()(const PhQ::DynamicPressure<NumericType>& dynamic_pressure) const {
    return hash<NumericType>()(dynamic_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_DYNAMIC_PRESSURE_HPP
