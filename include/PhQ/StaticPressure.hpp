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
template <typename Number>
class Direction;

// Forward declaration for class PhQ::StaticPressure.
template <typename Number>
class DynamicPressure;

// Forward declaration for class PhQ::StaticPressure.
template <typename Number>
class MassDensity;

// Forward declaration for class PhQ::StaticPressure.
template <typename Number>
class StaticKinematicPressure;

// Forward declaration for class PhQ::StaticPressure.
template <typename Number>
class Stress;

// Forward declaration for class PhQ::StaticPressure.
template <typename Number>
class TotalPressure;

// Forward declaration for class PhQ::StaticPressure.
template <typename Number>
class Traction;

// Static pressure. Pressure of a fluid at rest. Not to be confused with dynamic pressure, which is
// the additional pressure resulting from the kinetic energy of a flowing fluid, or total pressure,
// which is the sum of static pressure and dynamic pressure. Can represent either an absolute static
// pressure or a static pressure difference relative to another static pressure.
template <typename Number = double>
class StaticPressure : public DimensionalScalar<Unit::Pressure, Number> {
public:
  // Default constructor. Constructs a static pressure with an uninitialized value.
  StaticPressure() = default;

  // Constructor. Constructs a static pressure with a given value expressed in a given pressure
  // unit.
  StaticPressure(const Number value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, Number>(value, unit) {}

  // Constructor. Constructs a static pressure from a given scalar force magnitude and area using
  // the definition of pressure.
  constexpr StaticPressure(const ScalarForce<Number>& scalar_force, const Area<Number>& area)
    : StaticPressure<Number>(scalar_force.Value() / area.Value()) {}

  // Constructor. Constructs a static pressure from a given total pressure and dynamic pressure
  // using the definition of total pressure.
  constexpr StaticPressure(
      const TotalPressure<Number>& total_pressure, const DynamicPressure<Number>& dynamic_pressure);

  // Constructor. Constructs a static pressure from a given mass density and static kinematic
  // pressure using the definition of static kinematic pressure.
  constexpr StaticPressure(const MassDensity<Number>& mass_density,
                           const StaticKinematicPressure<Number>& static_kinematic_pressure);

  // Destructor. Destroys this static pressure.
  ~StaticPressure() noexcept = default;

  // Copy constructor. Constructs a static pressure by copying another one.
  constexpr StaticPressure(const StaticPressure<Number>& other) = default;

  // Copy constructor. Constructs a static pressure by copying another one.
  template <typename OtherNumber>
  explicit constexpr StaticPressure(const StaticPressure<OtherNumber>& other)
    : StaticPressure(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a static pressure by moving another one.
  constexpr StaticPressure(StaticPressure<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this static pressure by copying another one.
  constexpr StaticPressure<Number>& operator=(const StaticPressure<Number>& other) = default;

  // Copy assignment operator. Assigns this static pressure by copying another one.
  template <typename OtherNumber>
  constexpr StaticPressure<Number>& operator=(const StaticPressure<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this static pressure by moving another one.
  constexpr StaticPressure<Number>& operator=(StaticPressure<Number>&& other) noexcept = default;

  // Statically creates a static pressure of zero.
  static constexpr StaticPressure<Number> Zero() {
    return StaticPressure<Number>{static_cast<Number>(0)};
  }

  // Statically creates a static pressure with a given value expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr StaticPressure<Number> Create(const Number value) {
    return StaticPressure<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  [[nodiscard]] constexpr PhQ::Stress<Number> Stress() const;

  constexpr StaticPressure<Number> operator+(const StaticPressure<Number>& other) const {
    return StaticPressure<Number>{this->value + other.value};
  }

  constexpr TotalPressure<Number> operator+(const DynamicPressure<Number>& dynamic_pressure) const;

  constexpr StaticPressure<Number> operator-(const StaticPressure<Number>& other) const {
    return StaticPressure<Number>{this->value - other.value};
  }

  constexpr StaticPressure<Number> operator*(const Number number) const {
    return StaticPressure<Number>{this->value * number};
  }

  constexpr ScalarForce<Number> operator*(const Area<Number>& area) const {
    return ScalarForce<Number>{*this, area};
  }

  // Since pressure is compressive, the negative of this static pressure contributes to the
  // traction.
  constexpr Traction<Number> operator*(const Direction<Number>& direction) const;

  constexpr StaticPressure<Number> operator/(const Number number) const {
    return StaticPressure<Number>{this->value / number};
  }

  constexpr StaticKinematicPressure<Number> operator/(
      const MassDensity<Number>& mass_density) const;

  constexpr Number operator/(const StaticPressure<Number>& other) const noexcept {
    return this->value / other.value;
  }

  constexpr void operator+=(const StaticPressure<Number>& other) noexcept {
    this->value += other.value;
  }

  constexpr void operator-=(const StaticPressure<Number>& other) noexcept {
    this->value -= other.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a static pressure with a given value expressed in the standard pressure
  // unit.
  explicit constexpr StaticPressure(const Number value)
    : DimensionalScalar<Unit::Pressure, Number>(value) {}

  template <typename OtherNumber>
  friend class Traction;
};

template <typename Number>
inline constexpr bool operator==(
    const StaticPressure<Number>& left, const StaticPressure<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const StaticPressure<Number>& left, const StaticPressure<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const StaticPressure<Number>& left, const StaticPressure<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const StaticPressure<Number>& left, const StaticPressure<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const StaticPressure<Number>& left, const StaticPressure<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const StaticPressure<Number>& left, const StaticPressure<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const StaticPressure<Number>& static_pressure) {
  stream << static_pressure.Print();
  return stream;
}

template <typename Number>
inline constexpr StaticPressure<Number> operator*(
    const Number number, const StaticPressure<Number>& static_pressure) {
  return static_pressure * number;
}

template <typename Number>
inline constexpr Area<Number>::Area(
    const ScalarForce<Number>& scalar_force, const StaticPressure<Number>& static_pressure)
  : Area<Number>(scalar_force.Value() / static_pressure.Value()) {}

template <typename Number>
inline constexpr ScalarForce<Number>::ScalarForce(
    const StaticPressure<Number>& static_pressure, const Area<Number>& area)
  : ScalarForce<Number>(static_pressure.Value() * area.Value()) {}

template <typename Number>
inline constexpr ScalarForce<Number> Area<Number>::operator*(
    const StaticPressure<Number>& static_pressure) const {
  return ScalarForce<Number>{static_pressure, *this};
}

template <typename Number>
inline constexpr StaticPressure<Number> ScalarForce<Number>::operator/(
    const Area<Number>& area) const {
  return StaticPressure<Number>{*this, area};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::StaticPressure<Number>> {
  inline size_t operator()(const PhQ::StaticPressure<Number>& static_pressure) const {
    return hash<Number>()(static_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_STATIC_PRESSURE_HPP
