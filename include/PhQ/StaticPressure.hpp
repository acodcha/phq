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

#ifndef PHQ_STATIC_PRESSURE_HPP
#define PHQ_STATIC_PRESSURE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "Area.hpp"
#include "DimensionalScalar.hpp"
#include "ScalarForce.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declaration for class PhQ::StaticPressure.
template <typename NumericType>
class Direction;

// Forward declaration for class PhQ::StaticPressure.
template <typename NumericType>
class DynamicPressure;

// Forward declaration for class PhQ::StaticPressure.
template <typename NumericType>
class MassDensity;

// Forward declaration for class PhQ::StaticPressure.
template <typename NumericType>
class StaticKinematicPressure;

// Forward declaration for class PhQ::StaticPressure.
template <typename NumericType>
class Stress;

// Forward declaration for class PhQ::StaticPressure.
template <typename NumericType>
class TotalPressure;

/// \brief Static pressure. Pressure of a fluid at rest. Not to be confused with dynamic pressure,
/// which is the additional pressure resulting from the kinetic energy of a flowing fluid, or total
/// pressure, which is the sum of static pressure and dynamic pressure. See PhQ::DynamicPressure and
/// PhQ::TotalPressure. Can represent either an absolute static pressure or a static pressure
/// difference relative to another static pressure. For static kinematic pressure, see
/// PhQ::StaticKinematicPressure.
template <typename NumericType = double>
class StaticPressure : public DimensionalScalar<Unit::Pressure, NumericType> {
public:
  /// \brief Default constructor. Constructs a static pressure with an uninitialized value.
  StaticPressure() = default;

  /// \brief Constructor. Constructs a static pressure with a given value expressed in a given
  /// pressure unit.
  StaticPressure(const NumericType value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a static pressure from a given scalar force magnitude and area
  /// using the definition of pressure.
  constexpr StaticPressure(
      const ScalarForce<NumericType>& scalar_force, const Area<NumericType>& area)
    : StaticPressure<NumericType>(scalar_force.Value() / area.Value()) {}

  /// \brief Constructor. Constructs a static pressure from a given total pressure and dynamic
  /// pressure using the definition of total pressure.
  constexpr StaticPressure(const TotalPressure<NumericType>& total_pressure,
                           const DynamicPressure<NumericType>& dynamic_pressure);

  /// \brief Constructor. Constructs a static pressure from a given mass density and static
  /// kinematic pressure using the definition of static kinematic pressure.
  constexpr StaticPressure(const MassDensity<NumericType>& mass_density,
                           const StaticKinematicPressure<NumericType>& static_kinematic_pressure);

  /// \brief Destructor. Destroys this static pressure.
  ~StaticPressure() noexcept = default;

  /// \brief Copy constructor. Constructs a static pressure by copying another one.
  constexpr StaticPressure(const StaticPressure<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a static pressure by copying another one.
  template <typename OtherNumericType>
  explicit constexpr StaticPressure(const StaticPressure<OtherNumericType>& other)
    : StaticPressure(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a static pressure by moving another one.
  constexpr StaticPressure(StaticPressure<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this static pressure by copying another one.
  constexpr StaticPressure<NumericType>& operator=(
      const StaticPressure<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this static pressure by copying another one.
  template <typename OtherNumericType>
  constexpr StaticPressure<NumericType>& operator=(const StaticPressure<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this static pressure by moving another one.
  constexpr StaticPressure<NumericType>& operator=(
      StaticPressure<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a static pressure of zero.
  static constexpr StaticPressure<NumericType> Zero() {
    return StaticPressure<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a static pressure with a given value expressed in a given pressure
  /// unit.
  template <Unit::Pressure Unit>
  static constexpr StaticPressure<NumericType> Create(const NumericType value) {
    return StaticPressure<NumericType>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  [[nodiscard]] constexpr PhQ::Stress<NumericType> Stress() const;

  constexpr StaticPressure<NumericType> operator+(const StaticPressure<NumericType>& other) const {
    return StaticPressure<NumericType>{this->value + other.value};
  }

  constexpr TotalPressure<NumericType> operator+(
      const DynamicPressure<NumericType>& dynamic_pressure) const;

  constexpr StaticPressure<NumericType> operator-(const StaticPressure<NumericType>& other) const {
    return StaticPressure<NumericType>{this->value - other.value};
  }

  constexpr StaticPressure<NumericType> operator*(const NumericType number) const {
    return StaticPressure<NumericType>{this->value * number};
  }

  constexpr ScalarForce<NumericType> operator*(const Area<NumericType>& area) const {
    return ScalarForce<NumericType>{*this, area};
  }

  constexpr StaticPressure<NumericType> operator/(const NumericType number) const {
    return StaticPressure<NumericType>{this->value / number};
  }

  constexpr StaticKinematicPressure<NumericType> operator/(
      const MassDensity<NumericType>& mass_density) const;

  constexpr NumericType operator/(const StaticPressure<NumericType>& other) const noexcept {
    return this->value / other.value;
  }

  constexpr void operator+=(const StaticPressure<NumericType>& other) noexcept {
    this->value += other.value;
  }

  constexpr void operator-=(const StaticPressure<NumericType>& other) noexcept {
    this->value -= other.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a static pressure with a given value expressed in the standard
  /// pressure unit.
  explicit constexpr StaticPressure(const NumericType value)
    : DimensionalScalar<Unit::Pressure, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const StaticPressure<NumericType>& left, const StaticPressure<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const StaticPressure<NumericType>& left, const StaticPressure<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const StaticPressure<NumericType>& left, const StaticPressure<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const StaticPressure<NumericType>& left, const StaticPressure<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const StaticPressure<NumericType>& left, const StaticPressure<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const StaticPressure<NumericType>& left, const StaticPressure<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const StaticPressure<NumericType>& static_pressure) {
  stream << static_pressure.Print();
  return stream;
}

template <typename NumericType>
inline constexpr StaticPressure<NumericType> operator*(
    const NumericType number, const StaticPressure<NumericType>& static_pressure) {
  return static_pressure * number;
}

template <typename NumericType>
inline constexpr Area<NumericType>::Area(const ScalarForce<NumericType>& scalar_force,
                                         const StaticPressure<NumericType>& static_pressure)
  : Area<NumericType>(scalar_force.Value() / static_pressure.Value()) {}

template <typename NumericType>
inline constexpr ScalarForce<NumericType>::ScalarForce(
    const StaticPressure<NumericType>& static_pressure, const Area<NumericType>& area)
  : ScalarForce<NumericType>(static_pressure.Value() * area.Value()) {}

template <typename NumericType>
inline constexpr ScalarForce<NumericType> Area<NumericType>::operator*(
    const StaticPressure<NumericType>& static_pressure) const {
  return ScalarForce<NumericType>{static_pressure, *this};
}

template <typename NumericType>
inline constexpr StaticPressure<NumericType> ScalarForce<NumericType>::operator/(
    const Area<NumericType>& area) const {
  return StaticPressure<NumericType>{*this, area};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::StaticPressure<NumericType>> {
  inline size_t operator()(const PhQ::StaticPressure<NumericType>& static_pressure) const {
    return hash<NumericType>()(static_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_STATIC_PRESSURE_HPP
