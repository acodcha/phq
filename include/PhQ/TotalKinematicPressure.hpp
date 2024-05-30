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

/// \brief Total kinematic pressure, which is total pressure divided by mass density; see
/// PhQ::TotalPressure and PhQ::MassDensity.
template <typename NumericType = double>
class TotalKinematicPressure : public DimensionalScalar<Unit::SpecificEnergy, NumericType> {
public:
  /// \brief Default constructor. Constructs a total kinematic pressure with an uninitialized value.
  TotalKinematicPressure() = default;

  /// \brief Constructor. Constructs a total kinematic pressure with a given value expressed in a
  /// given specific energy unit.
  TotalKinematicPressure(const NumericType value, const Unit::SpecificEnergy unit)
    : DimensionalScalar<Unit::SpecificEnergy, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a total kinematic pressure from a given static kinematic
  /// pressure and dynamic kinematic pressure using the definition of total kinematic pressure.
  constexpr TotalKinematicPressure(
      const StaticKinematicPressure<NumericType>& static_kinematic_pressure,
      const DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure)
    : TotalKinematicPressure<NumericType>(
        static_kinematic_pressure.Value() + dynamic_kinematic_pressure.Value()) {}

  /// \brief Constructor. Constructs a total kinematic pressure from a given total pressure and mass
  /// density using the definition of total kinematic pressure.
  constexpr TotalKinematicPressure(const TotalPressure<NumericType>& total_pressure,
                                   const MassDensity<NumericType>& mass_density)
    : TotalKinematicPressure<NumericType>(total_pressure.Value() / mass_density.Value()) {}

  /// \brief Destructor. Destroys this total kinematic pressure.
  ~TotalKinematicPressure() noexcept = default;

  /// \brief Copy constructor. Constructs a total kinematic pressure by copying another one.
  constexpr TotalKinematicPressure(const TotalKinematicPressure<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a total kinematic pressure by copying another one.
  template <typename OtherNumericType>
  explicit constexpr TotalKinematicPressure(const TotalKinematicPressure<OtherNumericType>& other)
    : TotalKinematicPressure(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a total kinematic pressure by moving another one.
  constexpr TotalKinematicPressure(TotalKinematicPressure<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this total kinematic pressure by copying another one.
  constexpr TotalKinematicPressure<NumericType>& operator=(
      const TotalKinematicPressure<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this total kinematic pressure by copying another one.
  template <typename OtherNumericType>
  constexpr TotalKinematicPressure<NumericType>& operator=(
      const TotalKinematicPressure<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this total kinematic pressure by moving another one.
  constexpr TotalKinematicPressure<NumericType>& operator=(
      TotalKinematicPressure<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a total kinematic pressure of zero.
  static constexpr TotalKinematicPressure<NumericType> Zero() {
    return TotalKinematicPressure<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a total kinematic pressure with a given value expressed in a given
  /// specific energy unit.
  template <Unit::SpecificEnergy Unit>
  static constexpr TotalKinematicPressure<NumericType> Create(const NumericType value) {
    return TotalKinematicPressure<NumericType>{
        ConvertStatically<Unit::SpecificEnergy, Unit, Standard<Unit::SpecificEnergy>>(value)};
  }

  constexpr TotalKinematicPressure<NumericType> operator+(
      const TotalKinematicPressure<NumericType>& total_kinematic_pressure) const {
    return TotalKinematicPressure<NumericType>{this->value + total_kinematic_pressure.value};
  }

  constexpr TotalKinematicPressure<NumericType> operator-(
      const TotalKinematicPressure<NumericType>& total_kinematic_pressure) const {
    return TotalKinematicPressure<NumericType>{this->value - total_kinematic_pressure.value};
  }

  constexpr DynamicKinematicPressure<NumericType> operator-(
      const StaticKinematicPressure<NumericType>& static_kinematic_pressure) const {
    return DynamicKinematicPressure<NumericType>{*this, static_kinematic_pressure};
  }

  constexpr StaticKinematicPressure<NumericType> operator-(
      const DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure) const {
    return StaticKinematicPressure<NumericType>{*this, dynamic_kinematic_pressure};
  }

  constexpr TotalKinematicPressure<NumericType> operator*(const NumericType number) const {
    return TotalKinematicPressure<NumericType>{this->value * number};
  }

  constexpr TotalKinematicPressure<NumericType> operator/(const NumericType number) const {
    return TotalKinematicPressure<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const TotalKinematicPressure<NumericType>& total_kinematic_pressure) const noexcept {
    return this->value / total_kinematic_pressure.value;
  }

  constexpr void operator+=(
      const TotalKinematicPressure<NumericType>& total_kinematic_pressure) noexcept {
    this->value += total_kinematic_pressure.value;
  }

  constexpr void operator-=(
      const TotalKinematicPressure<NumericType>& total_kinematic_pressure) noexcept {
    this->value -= total_kinematic_pressure.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a total kinematic pressure with a given value expressed in the
  /// standard specific energy unit.
  explicit constexpr TotalKinematicPressure(const NumericType value)
    : DimensionalScalar<Unit::SpecificEnergy, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const TotalKinematicPressure<NumericType>& left,
                                 const TotalKinematicPressure<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const TotalKinematicPressure<NumericType>& left,
                                 const TotalKinematicPressure<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const TotalKinematicPressure<NumericType>& left,
                                const TotalKinematicPressure<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const TotalKinematicPressure<NumericType>& left,
                                const TotalKinematicPressure<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const TotalKinematicPressure<NumericType>& left,
                                 const TotalKinematicPressure<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const TotalKinematicPressure<NumericType>& left,
                                 const TotalKinematicPressure<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const TotalKinematicPressure<NumericType>& total_kinematic_pressure) {
  stream << total_kinematic_pressure.Print();
  return stream;
}

template <typename NumericType>
inline constexpr TotalKinematicPressure<NumericType> operator*(
    const NumericType number, const TotalKinematicPressure<NumericType>& total_kinematic_pressure) {
  return total_kinematic_pressure * number;
}

template <typename NumericType>
inline constexpr TotalPressure<NumericType>::TotalPressure(
    const MassDensity<NumericType>& mass_density,
    const TotalKinematicPressure<NumericType>& total_kinematic_pressure)
  : TotalPressure<NumericType>(mass_density.Value() * total_kinematic_pressure.Value()) {}

template <typename NumericType>
inline constexpr StaticKinematicPressure<NumericType>::StaticKinematicPressure(
    const TotalKinematicPressure<NumericType>& total_kinematic_pressure,
    const DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure)
  : StaticKinematicPressure<NumericType>(
      total_kinematic_pressure.Value() - dynamic_kinematic_pressure.Value()) {}

template <typename NumericType>
inline constexpr DynamicKinematicPressure<NumericType>::DynamicKinematicPressure(
    const TotalKinematicPressure<NumericType>& total_kinematic_pressure,
    const StaticKinematicPressure<NumericType>& static_kinematic_pressure)
  : DynamicKinematicPressure<NumericType>(
      total_kinematic_pressure.Value() - static_kinematic_pressure.Value()) {}

template <typename NumericType>
inline constexpr TotalKinematicPressure<NumericType>
StaticKinematicPressure<NumericType>::operator+(
    const DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure) const {
  return TotalKinematicPressure<NumericType>{*this, dynamic_kinematic_pressure};
}

template <typename NumericType>
inline constexpr TotalKinematicPressure<NumericType>
DynamicKinematicPressure<NumericType>::operator+(
    const StaticKinematicPressure<NumericType>& static_kinematic_pressure) const {
  return TotalKinematicPressure<NumericType>{static_kinematic_pressure, *this};
}

template <typename NumericType>
inline constexpr TotalKinematicPressure<NumericType> TotalPressure<NumericType>::operator/(
    const MassDensity<NumericType>& mass_density) const {
  return TotalKinematicPressure<NumericType>{*this, mass_density};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::TotalKinematicPressure<NumericType>> {
  inline size_t operator()(
      const PhQ::TotalKinematicPressure<NumericType>& total_kinematic_pressure) const {
    return hash<NumericType>()(total_kinematic_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_TOTAL_KINEMATIC_PRESSURE_HPP
