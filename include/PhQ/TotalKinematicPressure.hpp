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

#ifndef PHQ_TOTAL_KINEMATIC_PRESSURE_HPP
#define PHQ_TOTAL_KINEMATIC_PRESSURE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "DynamicKinematicPressure.hpp"
#include "MassDensity.hpp"
#include "StaticKinematicPressure.hpp"
#include "TotalPressure.hpp"
#include "Unit/SpecificEnergy.hpp"

namespace PhQ {

// Total kinematic pressure, which is the sum of static kinematic pressure and dynamic kinematic
// pressure.
template <typename Number = double>
class TotalKinematicPressure : public DimensionalScalar<Unit::SpecificEnergy, Number> {
public:
  // Default constructor. Constructs a total kinematic pressure with an uninitialized value.
  TotalKinematicPressure() = default;

  // Constructor. Constructs a total kinematic pressure with a given value expressed in a given
  // specific energy unit.
  TotalKinematicPressure(const Number value, const Unit::SpecificEnergy unit)
    : DimensionalScalar<Unit::SpecificEnergy, Number>(value, unit) {}

  // Constructor. Constructs a total kinematic pressure from a given static kinematic pressure and
  // dynamic kinematic pressure using the definition of total kinematic pressure.
  constexpr TotalKinematicPressure(
      const StaticKinematicPressure<Number>& static_kinematic_pressure,
      const DynamicKinematicPressure<Number>& dynamic_kinematic_pressure)
    : TotalKinematicPressure<Number>(
        static_kinematic_pressure.Value() + dynamic_kinematic_pressure.Value()) {}

  // Constructor. Constructs a total kinematic pressure from a given total pressure and mass density
  // using the definition of total kinematic pressure.
  constexpr TotalKinematicPressure(
      const TotalPressure<Number>& total_pressure, const MassDensity<Number>& mass_density)
    : TotalKinematicPressure<Number>(total_pressure.Value() / mass_density.Value()) {}

  // Destructor. Destroys this total kinematic pressure.
  ~TotalKinematicPressure() noexcept = default;

  // Copy constructor. Constructs a total kinematic pressure by copying another one.
  constexpr TotalKinematicPressure(const TotalKinematicPressure<Number>& other) = default;

  // Copy constructor. Constructs a total kinematic pressure by copying another one.
  template <typename OtherNumber>
  explicit constexpr TotalKinematicPressure(const TotalKinematicPressure<OtherNumber>& other)
    : TotalKinematicPressure(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a total kinematic pressure by moving another one.
  constexpr TotalKinematicPressure(TotalKinematicPressure<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this total kinematic pressure by copying another one.
  constexpr TotalKinematicPressure<Number>& operator=(
      const TotalKinematicPressure<Number>& other) = default;

  // Copy assignment operator. Assigns this total kinematic pressure by copying another one.
  template <typename OtherNumber>
  constexpr TotalKinematicPressure<Number>& operator=(
      const TotalKinematicPressure<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this total kinematic pressure by moving another one.
  constexpr TotalKinematicPressure<Number>& operator=(
      TotalKinematicPressure<Number>&& other) noexcept = default;

  // Statically creates a total kinematic pressure of zero.
  static constexpr TotalKinematicPressure<Number> Zero() {
    return TotalKinematicPressure<Number>{static_cast<Number>(0)};
  }

  // Statically creates a total kinematic pressure with a given value expressed in a given specific
  // energy unit.
  template <Unit::SpecificEnergy Unit>
  static constexpr TotalKinematicPressure<Number> Create(const Number value) {
    return TotalKinematicPressure<Number>{
        StaticConvertCopy<Unit::SpecificEnergy, Unit, Standard<Unit::SpecificEnergy>>(value)};
  }

  constexpr TotalKinematicPressure<Number> operator+(
      const TotalKinematicPressure<Number>& total_kinematic_pressure) const {
    return TotalKinematicPressure<Number>{this->value + total_kinematic_pressure.value};
  }

  constexpr TotalKinematicPressure<Number> operator-(
      const TotalKinematicPressure<Number>& total_kinematic_pressure) const {
    return TotalKinematicPressure<Number>{this->value - total_kinematic_pressure.value};
  }

  constexpr DynamicKinematicPressure<Number> operator-(
      const StaticKinematicPressure<Number>& static_kinematic_pressure) const {
    return DynamicKinematicPressure<Number>{*this, static_kinematic_pressure};
  }

  constexpr StaticKinematicPressure<Number> operator-(
      const DynamicKinematicPressure<Number>& dynamic_kinematic_pressure) const {
    return StaticKinematicPressure<Number>{*this, dynamic_kinematic_pressure};
  }

  constexpr TotalKinematicPressure<Number> operator*(const Number number) const {
    return TotalKinematicPressure<Number>{this->value * number};
  }

  constexpr TotalKinematicPressure<Number> operator/(const Number number) const {
    return TotalKinematicPressure<Number>{this->value / number};
  }

  constexpr Number operator/(
      const TotalKinematicPressure<Number>& total_kinematic_pressure) const noexcept {
    return this->value / total_kinematic_pressure.value;
  }

  constexpr void operator+=(
      const TotalKinematicPressure<Number>& total_kinematic_pressure) noexcept {
    this->value += total_kinematic_pressure.value;
  }

  constexpr void operator-=(
      const TotalKinematicPressure<Number>& total_kinematic_pressure) noexcept {
    this->value -= total_kinematic_pressure.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a total kinematic pressure with a given value expressed in the standard
  // specific energy unit.
  explicit constexpr TotalKinematicPressure(const Number value)
    : DimensionalScalar<Unit::SpecificEnergy, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const TotalKinematicPressure<Number>& left,
                                 const TotalKinematicPressure<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const TotalKinematicPressure<Number>& left,
                                 const TotalKinematicPressure<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const TotalKinematicPressure<Number>& left,
                                const TotalKinematicPressure<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const TotalKinematicPressure<Number>& left,
                                const TotalKinematicPressure<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const TotalKinematicPressure<Number>& left,
                                 const TotalKinematicPressure<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const TotalKinematicPressure<Number>& left,
                                 const TotalKinematicPressure<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const TotalKinematicPressure<Number>& total_kinematic_pressure) {
  stream << total_kinematic_pressure.Print();
  return stream;
}

template <typename Number>
inline constexpr TotalKinematicPressure<Number> operator*(
    const Number number, const TotalKinematicPressure<Number>& total_kinematic_pressure) {
  return total_kinematic_pressure * number;
}

template <typename Number>
inline constexpr TotalPressure<Number>::TotalPressure(
    const MassDensity<Number>& mass_density,
    const TotalKinematicPressure<Number>& total_kinematic_pressure)
  : TotalPressure<Number>(mass_density.Value() * total_kinematic_pressure.Value()) {}

template <typename Number>
inline constexpr StaticKinematicPressure<Number>::StaticKinematicPressure(
    const TotalKinematicPressure<Number>& total_kinematic_pressure,
    const DynamicKinematicPressure<Number>& dynamic_kinematic_pressure)
  : StaticKinematicPressure<Number>(
      total_kinematic_pressure.Value() - dynamic_kinematic_pressure.Value()) {}

template <typename Number>
inline constexpr DynamicKinematicPressure<Number>::DynamicKinematicPressure(
    const TotalKinematicPressure<Number>& total_kinematic_pressure,
    const StaticKinematicPressure<Number>& static_kinematic_pressure)
  : DynamicKinematicPressure<Number>(
      total_kinematic_pressure.Value() - static_kinematic_pressure.Value()) {}

template <typename Number>
inline constexpr TotalKinematicPressure<Number> StaticKinematicPressure<Number>::operator+(
    const DynamicKinematicPressure<Number>& dynamic_kinematic_pressure) const {
  return TotalKinematicPressure<Number>{*this, dynamic_kinematic_pressure};
}

template <typename Number>
inline constexpr TotalKinematicPressure<Number> DynamicKinematicPressure<Number>::operator+(
    const StaticKinematicPressure<Number>& static_kinematic_pressure) const {
  return TotalKinematicPressure<Number>{static_kinematic_pressure, *this};
}

template <typename Number>
inline constexpr TotalKinematicPressure<Number> TotalPressure<Number>::operator/(
    const MassDensity<Number>& mass_density) const {
  return TotalKinematicPressure<Number>{*this, mass_density};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::TotalKinematicPressure<Number>> {
  inline size_t operator()(
      const PhQ::TotalKinematicPressure<Number>& total_kinematic_pressure) const {
    return hash<Number>()(total_kinematic_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_TOTAL_KINEMATIC_PRESSURE_HPP
