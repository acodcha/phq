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

#ifndef PHQ_DYNAMIC_KINEMATIC_PRESSURE_HPP
#define PHQ_DYNAMIC_KINEMATIC_PRESSURE_HPP

#include <cmath>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "DynamicPressure.hpp"
#include "MassDensity.hpp"
#include "Speed.hpp"
#include "StaticKinematicPressure.hpp"
#include "Unit/SpecificEnergy.hpp"

namespace PhQ {

/// \brief Dynamic kinematic pressure, which is dynamic pressure divided by mass density; see
/// PhQ::DynamicPressure and PhQ::MassDensity.
template <typename NumericType = double>
class DynamicKinematicPressure : public DimensionalScalar<Unit::SpecificEnergy, NumericType> {
public:
  /// \brief Default constructor. Constructs a dynamic kinematic pressure with an uninitialized
  /// value.
  DynamicKinematicPressure() = default;

  /// \brief Constructor. Constructs a dynamic kinematic pressure with a given value expressed in a
  /// given specific energy unit.
  DynamicKinematicPressure(const NumericType value, const Unit::SpecificEnergy unit)
    : DimensionalScalar<Unit::SpecificEnergy, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a dynamic kinematic pressure from a given speed using the
  /// definition of dynamic kinematic pressure.
  explicit constexpr DynamicKinematicPressure(const Speed<NumericType>& speed)
    : DynamicKinematicPressure<NumericType>(0.5 * std::pow(speed.Value(), 2)) {}

  /// \brief Constructor. Constructs a dynamic kinematic pressure from a given total kinematic
  /// pressure and static kinematic pressure using the definition of total kinematic pressure.
  constexpr DynamicKinematicPressure(
      const TotalKinematicPressure<NumericType>& total_kinematic_pressure,
      const StaticKinematicPressure<NumericType>& static_kinematic_pressure);

  /// \brief Constructor. Constructs a dynamic kinematic pressure from a given dynamic pressure and
  /// mass density using the definition of dynamic kinematic pressure.
  constexpr DynamicKinematicPressure(const DynamicPressure<NumericType>& dynamic_pressure,
                                     const MassDensity<NumericType>& mass_density)
    : DynamicKinematicPressure<NumericType>(dynamic_pressure.Value() / mass_density.Value()) {}

  /// \brief Destructor. Destroys this dynamic kinematic pressure.
  ~DynamicKinematicPressure() noexcept = default;

  /// \brief Copy constructor. Constructs a dynamic kinematic pressure by copying another one.
  constexpr DynamicKinematicPressure(const DynamicKinematicPressure<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a dynamic kinematic pressure by copying another one.
  template <typename OtherNumericType>
  explicit constexpr DynamicKinematicPressure(
      const DynamicKinematicPressure<OtherNumericType>& other)
    : DynamicKinematicPressure(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a dynamic kinematic pressure by moving another one.
  constexpr DynamicKinematicPressure(
      DynamicKinematicPressure<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this dynamic kinematic pressure by copying another
  /// one.
  constexpr DynamicKinematicPressure<NumericType>& operator=(
      const DynamicKinematicPressure<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this dynamic kinematic pressure by copying another
  /// one.
  template <typename OtherNumericType>
  constexpr DynamicKinematicPressure<NumericType>& operator=(
      const DynamicKinematicPressure<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this dynamic kinematic pressure by moving another
  /// one.
  constexpr DynamicKinematicPressure<NumericType>& operator=(
      DynamicKinematicPressure<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a dynamic kinematic pressure of zero.
  static constexpr DynamicKinematicPressure<NumericType> Zero() {
    return DynamicKinematicPressure<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a dynamic kinematic pressure with a given value expressed in a given
  /// specific energy unit.
  template <Unit::SpecificEnergy Unit>
  static constexpr DynamicKinematicPressure<NumericType> Create(const NumericType value) {
    return DynamicKinematicPressure<NumericType>{
        ConvertStatically<Unit::SpecificEnergy, Unit, Standard<Unit::SpecificEnergy>>(value)};
  }

  constexpr DynamicKinematicPressure<NumericType> operator+(
      const DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure) const {
    return DynamicKinematicPressure<NumericType>{this->value + dynamic_kinematic_pressure.value};
  }

  constexpr TotalKinematicPressure<NumericType> operator+(
      const StaticKinematicPressure<NumericType>& static_kinematic_pressure) const;

  constexpr DynamicKinematicPressure<NumericType> operator-(
      const DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure) const {
    return DynamicKinematicPressure<NumericType>{this->value - dynamic_kinematic_pressure.value};
  }

  constexpr DynamicKinematicPressure<NumericType> operator*(const NumericType number) const {
    return DynamicKinematicPressure<NumericType>{this->value * number};
  }

  constexpr DynamicKinematicPressure<NumericType> operator/(const NumericType number) const {
    return DynamicKinematicPressure<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure) const noexcept {
    return this->value / dynamic_kinematic_pressure.value;
  }

  constexpr void operator+=(
      const DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure) noexcept {
    this->value += dynamic_kinematic_pressure.value;
  }

  constexpr void operator-=(
      const DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure) noexcept {
    this->value -= dynamic_kinematic_pressure.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a dynamic kinematic pressure with a given value expressed in
  /// the standard specific energy unit.
  explicit constexpr DynamicKinematicPressure(const NumericType value)
    : DimensionalScalar<Unit::SpecificEnergy, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const DynamicKinematicPressure<NumericType>& left,
                                 const DynamicKinematicPressure<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const DynamicKinematicPressure<NumericType>& left,
                                 const DynamicKinematicPressure<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const DynamicKinematicPressure<NumericType>& left,
                                const DynamicKinematicPressure<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const DynamicKinematicPressure<NumericType>& left,
                                const DynamicKinematicPressure<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const DynamicKinematicPressure<NumericType>& left,
                                 const DynamicKinematicPressure<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const DynamicKinematicPressure<NumericType>& left,
                                 const DynamicKinematicPressure<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure) {
  stream << dynamic_kinematic_pressure.Print();
  return stream;
}

template <typename NumericType>
inline constexpr DynamicKinematicPressure<NumericType> operator*(
    const NumericType number,
    const DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure) {
  return dynamic_kinematic_pressure * number;
}

template <typename NumericType>
inline Speed<NumericType>::Speed(
    const DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure)
  : Speed<NumericType>(std::sqrt(2.0 * dynamic_kinematic_pressure.Value())) {}

template <typename NumericType>
inline constexpr DynamicPressure<NumericType>::DynamicPressure(
    const MassDensity<NumericType>& mass_density,
    const DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure)
  : DynamicPressure<NumericType>(mass_density.Value() * dynamic_kinematic_pressure.Value()) {}

template <typename NumericType>
inline constexpr DynamicKinematicPressure<NumericType> DynamicPressure<NumericType>::operator/(
    const MassDensity<NumericType>& mass_density) const {
  return DynamicKinematicPressure<NumericType>{*this, mass_density};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::DynamicKinematicPressure<NumericType>> {
  inline size_t operator()(
      const PhQ::DynamicKinematicPressure<NumericType>& dynamic_kinematic_pressure) const {
    return hash<NumericType>()(dynamic_kinematic_pressure.Value());
  }
};

}  // namespace std

#endif  // PHQ_DYNAMIC_KINEMATIC_PRESSURE_HPP
