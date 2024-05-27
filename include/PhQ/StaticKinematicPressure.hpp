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

#ifndef PHQ_STATIC_KINEMATIC_PRESSURE_HPP
#define PHQ_STATIC_KINEMATIC_PRESSURE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "MassDensity.hpp"
#include "StaticPressure.hpp"
#include "Unit/SpecificEnergy.hpp"

namespace PhQ {

// Forward declaration for class PhQ::StaticKinematicPressure.
template <typename Number>
class DynamicKinematicPressure;

// Forward declaration for class PhQ::StaticKinematicPressure.
template <typename Number>
class TotalKinematicPressure;

/// \brief Static kinematic pressure, which is static pressure divided by mass density; see
/// PhQ::StaticPressure and PhQ::MassDensity.
template <typename Number = double>
class StaticKinematicPressure : public DimensionalScalar<Unit::SpecificEnergy, Number> {
public:
  /// \brief Default constructor. Constructs a static kinematic pressure with an uninitialized
  /// value.
  StaticKinematicPressure() = default;

  /// \brief Constructor. Constructs a static kinematic pressure with a given value expressed in a
  /// given specific energy unit.
  StaticKinematicPressure(const Number value, const Unit::SpecificEnergy unit)
    : DimensionalScalar<Unit::SpecificEnergy, Number>(value, unit) {}

  /// \brief Constructor. Constructs a static kinematic pressure from a given total kinematic
  /// pressure and dynamic kinematic pressure using the definition of total kinematic pressure.
  constexpr StaticKinematicPressure(
      const TotalKinematicPressure<Number>& total_kinematic_pressure,
      const DynamicKinematicPressure<Number>& dynamic_kinematic_pressure);

  /// \brief Constructor. Constructs a static kinematic pressure from a given static pressure and
  /// mass density using the definition of static kinematic pressure.
  constexpr StaticKinematicPressure(
      const StaticPressure<Number>& static_pressure, const MassDensity<Number>& mass_density)
    : StaticKinematicPressure<Number>(static_pressure.Value() / mass_density.Value()) {}

  /// \brief Destructor. Destroys this static kinematic pressure.
  ~StaticKinematicPressure() noexcept = default;

  /// \brief Copy constructor. Constructs a static kinematic pressure by copying another one.
  constexpr StaticKinematicPressure(const StaticKinematicPressure<Number>& other) = default;

  /// \brief Copy constructor. Constructs a static kinematic pressure by copying another one.
  template <typename OtherNumber>
  explicit constexpr StaticKinematicPressure(const StaticKinematicPressure<OtherNumber>& other)
    : StaticKinematicPressure(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a static kinematic pressure by moving another one.
  constexpr StaticKinematicPressure(StaticKinematicPressure<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this static kinematic pressure by copying another
  /// one.
  constexpr StaticKinematicPressure<Number>& operator=(
      const StaticKinematicPressure<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this static kinematic pressure by copying another
  /// one.
  template <typename OtherNumber>
  constexpr StaticKinematicPressure<Number>& operator=(
      const StaticKinematicPressure<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this static kinematic pressure by moving another one.
  constexpr StaticKinematicPressure<Number>& operator=(
      StaticKinematicPressure<Number>&& other) noexcept = default;

  /// \brief Statically creates a static kinematic pressure of zero.
  static constexpr StaticKinematicPressure<Number> Zero() {
    return StaticKinematicPressure<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a static kinematic pressure with a given value expressed in a given
  /// specific energy unit.
  template <Unit::SpecificEnergy Unit>
  static constexpr StaticKinematicPressure<Number> Create(const Number value) {
    return StaticKinematicPressure<Number>{
        StaticConvertCopy<Unit::SpecificEnergy, Unit, Standard<Unit::SpecificEnergy>>(value)};
  }

  constexpr StaticKinematicPressure<Number> operator+(
      const StaticKinematicPressure<Number>& other) const {
    return StaticKinematicPressure<Number>{this->value + other.value};
  }

  constexpr TotalKinematicPressure<Number> operator+(
      const DynamicKinematicPressure<Number>& dynamic_kinematic_pressure) const;

  constexpr StaticKinematicPressure<Number> operator-(
      const StaticKinematicPressure<Number>& other) const {
    return StaticKinematicPressure<Number>{this->value - other.value};
  }

  constexpr StaticKinematicPressure<Number> operator*(const Number number) const {
    return StaticKinematicPressure<Number>{this->value * number};
  }

  constexpr StaticPressure<Number> operator*(const MassDensity<Number>& mass_density) const {
    return StaticPressure<Number>{mass_density, *this};
  }

  constexpr StaticKinematicPressure<Number> operator/(const Number number) const {
    return StaticKinematicPressure<Number>{this->value / number};
  }

  constexpr Number operator/(const StaticKinematicPressure<Number>& other) const noexcept {
    return this->value / other.value;
  }

  constexpr void operator+=(const StaticKinematicPressure<Number>& other) noexcept {
    this->value += other.value;
  }

  constexpr void operator-=(const StaticKinematicPressure<Number>& other) noexcept {
    this->value -= other.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a static kinematic pressure with a given value expressed in the
  /// standard specific energy unit.
  explicit constexpr StaticKinematicPressure(const Number value)
    : DimensionalScalar<Unit::SpecificEnergy, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const StaticKinematicPressure<Number>& left,
                                 const StaticKinematicPressure<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const StaticKinematicPressure<Number>& left,
                                 const StaticKinematicPressure<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const StaticKinematicPressure<Number>& left,
                                const StaticKinematicPressure<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const StaticKinematicPressure<Number>& left,
                                const StaticKinematicPressure<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const StaticKinematicPressure<Number>& left,
                                 const StaticKinematicPressure<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const StaticKinematicPressure<Number>& left,
                                 const StaticKinematicPressure<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const StaticKinematicPressure<Number>& static_kinematic_pressure) {
  stream << static_kinematic_pressure.Print();
  return stream;
}

template <typename Number>
inline constexpr StaticKinematicPressure<Number> operator*(
    const Number number, const StaticKinematicPressure<Number>& static_kinematic_pressure) {
  return static_kinematic_pressure * number;
}

template <typename Number>
inline constexpr StaticPressure<Number>::StaticPressure(
    const MassDensity<Number>& mass_density,
    const StaticKinematicPressure<Number>& static_kinematic_pressure)
  : StaticPressure<Number>(mass_density.Value() * static_kinematic_pressure.Value()) {}

template <typename Number>
inline constexpr StaticKinematicPressure<Number> StaticPressure<Number>::operator/(
    const MassDensity<Number>& mass_density) const {
  return StaticKinematicPressure<Number>{*this, mass_density};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::StaticKinematicPressure<Number>> {
  inline size_t operator()(
      const PhQ::StaticKinematicPressure<Number>& static_kinematic_pressure) const {
    return hash<Number>()(static_kinematic_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_STATIC_KINEMATIC_PRESSURE_HPP
