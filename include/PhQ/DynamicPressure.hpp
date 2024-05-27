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
template <typename Number>
class DynamicKinematicPressure;

/// \brief Dynamic pressure, which is the additional pressure arising from a flowing fluid's kinetic
/// energy. Dynamic pressure can be thought of as a flowing fluid's kinetic energy per unit volume.
/// Not to be confused with static pressure or total pressure; see PhQ::StaticPressure and
/// PhQ::TotalPressure. For dynamic kinematic pressure, see PhQ::DynamicKinematicPressure.
template <typename Number = double>
class DynamicPressure : public DimensionalScalar<Unit::Pressure, Number> {
public:
  /// \brief Default constructor. Constructs a dynamic pressure with an uninitialized value.
  DynamicPressure() = default;

  /// \brief Constructor. Constructs a dynamic pressure with a given value expressed in a given
  /// pressure unit.
  DynamicPressure(const Number value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, Number>(value, unit) {}

  /// \brief Constructor. Constructs a dynamic pressure from a given mass density and speed using
  /// the definition of dynamic pressure.
  constexpr DynamicPressure(const MassDensity<Number>& mass_density, const Speed<Number>& speed)
    : DynamicPressure<Number>(0.5 * mass_density.Value() * std::pow(speed.Value(), 2)) {}

  /// \brief Constructor. Constructs a dynamic pressure from a given total pressure and static
  /// pressure using the definition of total pressure.
  constexpr DynamicPressure(
      const TotalPressure<Number>& total_pressure, const StaticPressure<Number>& static_pressure);

  /// \brief Constructor. Constructs a dynamic pressure from a given mass density and dynamic
  /// kinematic pressure using the definition of dynamic kinematic pressure.
  constexpr DynamicPressure(const MassDensity<Number>& mass_density,
                            const DynamicKinematicPressure<Number>& dynamic_kinematic_pressure);

  /// \brief Destructor. Destroys this dynamic pressure.
  ~DynamicPressure() noexcept = default;

  /// \brief Copy constructor. Constructs a dynamic pressure by copying another one.
  constexpr DynamicPressure(const DynamicPressure<Number>& other) = default;

  /// \brief Copy constructor. Constructs a dynamic pressure by copying another one.
  template <typename OtherNumber>
  explicit constexpr DynamicPressure(const DynamicPressure<OtherNumber>& other)
    : DynamicPressure(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a dynamic pressure by moving another one.
  constexpr DynamicPressure(DynamicPressure<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this dynamic pressure by copying another one.
  constexpr DynamicPressure<Number>& operator=(const DynamicPressure<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this dynamic pressure by copying another one.
  template <typename OtherNumber>
  constexpr DynamicPressure<Number>& operator=(const DynamicPressure<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this dynamic pressure by moving another one.
  constexpr DynamicPressure<Number>& operator=(DynamicPressure<Number>&& other) noexcept = default;

  /// \brief Statically creates a dynamic pressure of zero.
  static constexpr DynamicPressure<Number> Zero() {
    return DynamicPressure<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a dynamic pressure with a given value expressed in a given pressure
  /// unit.
  template <Unit::Pressure Unit>
  static constexpr DynamicPressure<Number> Create(const Number value) {
    return DynamicPressure<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr DynamicPressure<Number> operator+(
      const DynamicPressure<Number>& dynamic_pressure) const {
    return DynamicPressure<Number>{this->value + dynamic_pressure.value};
  }

  constexpr TotalPressure<Number> operator+(const StaticPressure<Number>& static_pressure) const;

  constexpr DynamicPressure<Number> operator-(
      const DynamicPressure<Number>& dynamic_pressure) const {
    return DynamicPressure<Number>{this->value - dynamic_pressure.value};
  }

  constexpr DynamicPressure<Number> operator*(const Number number) const {
    return DynamicPressure<Number>{this->value * number};
  }

  constexpr DynamicPressure<Number> operator/(const Number number) const {
    return DynamicPressure<Number>{this->value / number};
  }

  constexpr Number operator/(const DynamicPressure<Number>& dynamic_pressure) const noexcept {
    return this->value / dynamic_pressure.value;
  }

  constexpr DynamicKinematicPressure<Number> operator/(
      const MassDensity<Number>& mass_density) const;

  constexpr void operator+=(const DynamicPressure<Number>& dynamic_pressure) noexcept {
    this->value += dynamic_pressure.value;
  }

  constexpr void operator-=(const DynamicPressure<Number>& dynamic_pressure) noexcept {
    this->value -= dynamic_pressure.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a dynamic pressure with a given value expressed in the standard
  /// pressure unit.
  explicit constexpr DynamicPressure(const Number value)
    : DimensionalScalar<Unit::Pressure, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const DynamicPressure<Number>& left, const DynamicPressure<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const DynamicPressure<Number>& left, const DynamicPressure<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const DynamicPressure<Number>& left, const DynamicPressure<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const DynamicPressure<Number>& left, const DynamicPressure<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const DynamicPressure<Number>& left, const DynamicPressure<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const DynamicPressure<Number>& left, const DynamicPressure<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const DynamicPressure<Number>& dynamic_pressure) {
  stream << dynamic_pressure.Print();
  return stream;
}

template <typename Number>
inline constexpr DynamicPressure<Number> operator*(
    const Number number, const DynamicPressure<Number>& dynamic_pressure) {
  return dynamic_pressure * number;
}

template <typename Number>
inline constexpr MassDensity<Number>::MassDensity(
    const DynamicPressure<Number>& dynamic_pressure, const Speed<Number>& speed)
  : MassDensity<Number>(2.0 * dynamic_pressure.Value() / (speed.Value() * speed.Value())) {}

template <typename Number>
inline Speed<Number>::Speed(
    const DynamicPressure<Number>& dynamic_pressure, const MassDensity<Number>& mass_density)
  : Speed<Number>(std::sqrt(2.0 * dynamic_pressure.Value() / mass_density.Value())) {}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::DynamicPressure<Number>> {
  inline size_t operator()(const PhQ::DynamicPressure<Number>& dynamic_pressure) const {
    return hash<Number>()(dynamic_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_DYNAMIC_PRESSURE_HPP
