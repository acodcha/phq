// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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

#ifndef PHQ_REYNOLDS_NUMBER_HPP
#define PHQ_REYNOLDS_NUMBER_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"
#include "DynamicViscosity.hpp"
#include "KinematicViscosity.hpp"
#include "Length.hpp"
#include "MassDensity.hpp"
#include "Speed.hpp"

namespace PhQ {

/// \brief Reynolds number of a fluid flow. Measures the local turbulence of a fluid flow.
/// Represents the ratio of local inertial forces to local viscous forces in a fluid flow. See also
/// PhQ::MassDensity, PhQ::Speed, PhQ::Length, PhQ::DynamicViscosity, and PhQ::KinematicViscosity.
template <typename NumericType = double>
class ReynoldsNumber : public DimensionlessScalar<NumericType> {
public:
  /// \brief Default constructor. Constructs a Reynolds number with an uninitialized value.
  ReynoldsNumber() = default;

  /// \brief Constructor. Constructs a Reynolds number with a given value.
  explicit constexpr ReynoldsNumber(const NumericType value)
    : DimensionlessScalar<NumericType>(value) {}

  /// \brief Constructor. Constructs a Reynolds number from a given mass density, speed, length, and
  /// dynamic viscosity using the definition of the Reynolds number.
  constexpr ReynoldsNumber(
      const MassDensity<NumericType>& mass_density, const Speed<NumericType>& speed,
      const Length<NumericType>& length, const DynamicViscosity<NumericType>& dynamic_viscosity)
    : ReynoldsNumber<NumericType>(
        mass_density.Value() * speed.Value() * length.Value() / dynamic_viscosity.Value()) {}

  /// \brief Constructor. Constructs a Reynolds number from a given speed, length, and kinematic
  /// viscosity using the definition of the Reynolds number.
  constexpr ReynoldsNumber(const Speed<NumericType>& speed, const Length<NumericType>& length,
                           const KinematicViscosity<NumericType>& kinematic_viscosity)
    : ReynoldsNumber<NumericType>(speed.Value() * length.Value() / kinematic_viscosity.Value()) {}

  /// \brief Destructor. Destroys this Reynolds number.
  ~ReynoldsNumber() noexcept = default;

  /// \brief Copy constructor. Constructs a Reynolds number by copying another one.
  constexpr ReynoldsNumber(const ReynoldsNumber<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a Reynolds number by copying another one.
  template <typename OtherNumericType>
  explicit constexpr ReynoldsNumber(const ReynoldsNumber<OtherNumericType>& other)
    : ReynoldsNumber(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a Reynolds number by moving another one.
  constexpr ReynoldsNumber(ReynoldsNumber<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this Reynolds number by copying another one.
  constexpr ReynoldsNumber<NumericType>& operator=(
      const ReynoldsNumber<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this Reynolds number by copying another one.
  template <typename OtherNumericType>
  constexpr ReynoldsNumber<NumericType>& operator=(const ReynoldsNumber<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this Reynolds number by moving another one.
  constexpr ReynoldsNumber<NumericType>& operator=(
      ReynoldsNumber<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a Reynolds number of zero.
  static constexpr ReynoldsNumber<NumericType> Zero() {
    return ReynoldsNumber<NumericType>{static_cast<NumericType>(0)};
  }

  [[nodiscard]] constexpr PhQ::DynamicViscosity<NumericType> DynamicViscosity(
      const PhQ::MassDensity<NumericType>& mass_density, const PhQ::Speed<NumericType>& speed,
      const PhQ::Length<NumericType>& length) const {
    return PhQ::DynamicViscosity<NumericType>{mass_density, speed, length, *this};
  }

  [[nodiscard]] constexpr PhQ::KinematicViscosity<NumericType> KinematicViscosity(
      const PhQ::Speed<NumericType>& speed, const PhQ::Length<NumericType>& length) const {
    return PhQ::KinematicViscosity<NumericType>{speed, length, *this};
  }

  [[nodiscard]] constexpr PhQ::Length<NumericType> Length(
      const PhQ::DynamicViscosity<NumericType>& dynamic_viscosity,
      const PhQ::MassDensity<NumericType>& mass_density,
      const PhQ::Speed<NumericType>& speed) const {
    return PhQ::Length<NumericType>{*this, dynamic_viscosity, mass_density, speed};
  }

  [[nodiscard]] constexpr PhQ::Length<NumericType> Length(
      const PhQ::KinematicViscosity<NumericType>& kinematic_viscosity,
      const PhQ::Speed<NumericType>& speed) const {
    return PhQ::Length<NumericType>{*this, kinematic_viscosity, speed};
  }

  [[nodiscard]] constexpr PhQ::MassDensity<NumericType> MassDensity(
      const PhQ::DynamicViscosity<NumericType>& dynamic_viscosity,
      const PhQ::Speed<NumericType>& speed, const PhQ::Length<NumericType>& length) const {
    return PhQ::MassDensity<NumericType>{*this, dynamic_viscosity, speed, length};
  }

  [[nodiscard]] constexpr PhQ::Speed<NumericType> Speed(
      const PhQ::DynamicViscosity<NumericType>& dynamic_viscosity,
      const PhQ::MassDensity<NumericType>& mass_density,
      const PhQ::Length<NumericType>& length) const {
    return PhQ::Speed<NumericType>{*this, dynamic_viscosity, mass_density, length};
  }

  [[nodiscard]] constexpr PhQ::Speed<NumericType> Speed(
      const PhQ::KinematicViscosity<NumericType>& kinematic_viscosity,
      const PhQ::Length<NumericType>& length) const {
    return PhQ::Speed<NumericType>{*this, kinematic_viscosity, length};
  }

  constexpr ReynoldsNumber<NumericType> operator+(
      const ReynoldsNumber<NumericType>& reynolds_number) const {
    return ReynoldsNumber<NumericType>{this->value + reynolds_number.value};
  }

  constexpr ReynoldsNumber<NumericType> operator-(
      const ReynoldsNumber<NumericType>& reynolds_number) const {
    return ReynoldsNumber<NumericType>{this->value - reynolds_number.value};
  }

  constexpr ReynoldsNumber<NumericType> operator*(const NumericType number) const {
    return ReynoldsNumber<NumericType>{this->value * number};
  }

  constexpr ReynoldsNumber<NumericType> operator/(const NumericType number) const {
    return ReynoldsNumber<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const ReynoldsNumber<NumericType>& reynolds_number) const noexcept {
    return this->value / reynolds_number.value;
  }

  constexpr void operator+=(const ReynoldsNumber<NumericType>& reynolds_number) noexcept {
    this->value += reynolds_number.value;
  }

  constexpr void operator-=(const ReynoldsNumber<NumericType>& reynolds_number) noexcept {
    this->value -= reynolds_number.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }
};

template <typename NumericType>
inline constexpr bool operator==(
    const ReynoldsNumber<NumericType>& left, const ReynoldsNumber<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const ReynoldsNumber<NumericType>& left, const ReynoldsNumber<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const ReynoldsNumber<NumericType>& left, const ReynoldsNumber<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const ReynoldsNumber<NumericType>& left, const ReynoldsNumber<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const ReynoldsNumber<NumericType>& left, const ReynoldsNumber<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const ReynoldsNumber<NumericType>& left, const ReynoldsNumber<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const ReynoldsNumber<NumericType>& reynolds_number) {
  stream << reynolds_number.Print();
  return stream;
}

template <typename NumericType>
inline constexpr ReynoldsNumber<NumericType> operator*(
    const NumericType number, const ReynoldsNumber<NumericType>& reynolds_number) {
  return ReynoldsNumber<NumericType>{number * reynolds_number.Value()};
}

template <typename NumericType>
inline constexpr Length<NumericType>::Length(
    const ReynoldsNumber<NumericType>& reynolds_number,
    const DynamicViscosity<NumericType>& dynamic_viscosity,
    const MassDensity<NumericType>& mass_density, const Speed<NumericType>& speed)
  : Length<NumericType>(reynolds_number.Value() * dynamic_viscosity.Value()
                        / (mass_density.Value() * speed.Value())) {}

template <typename NumericType>
inline constexpr Length<NumericType>::Length(
    const ReynoldsNumber<NumericType>& reynolds_number,
    const KinematicViscosity<NumericType>& kinematic_viscosity, const Speed<NumericType>& speed)
  : Length<NumericType>(reynolds_number.Value() * kinematic_viscosity.Value() / speed.Value()) {}

template <typename NumericType>
inline constexpr Speed<NumericType>::Speed(
    const ReynoldsNumber<NumericType>& reynolds_number,
    const DynamicViscosity<NumericType>& dynamic_viscosity,
    const MassDensity<NumericType>& mass_density, const Length<NumericType>& length)
  : Speed<NumericType>(reynolds_number.Value() * dynamic_viscosity.Value()
                       / (mass_density.Value() * length.Value())) {}

template <typename NumericType>
inline constexpr Speed<NumericType>::Speed(
    const ReynoldsNumber<NumericType>& reynolds_number,
    const KinematicViscosity<NumericType>& kinematic_viscosity, const Length<NumericType>& length)
  : Speed<NumericType>(reynolds_number.Value() * kinematic_viscosity.Value() / length.Value()) {}

template <typename NumericType>
inline constexpr MassDensity<NumericType>::MassDensity(
    const ReynoldsNumber<NumericType>& reynolds_number,
    const DynamicViscosity<NumericType>& dynamic_viscosity, const Speed<NumericType>& speed,
    const Length<NumericType>& length)
  : MassDensity<NumericType>(
      reynolds_number.Value() * dynamic_viscosity.Value() / (speed.Value() * length.Value())) {}

template <typename NumericType>
inline constexpr KinematicViscosity<NumericType>::KinematicViscosity(
    const Speed<NumericType>& speed, const Length<NumericType>& length,
    const ReynoldsNumber<NumericType>& reynolds_number)
  : KinematicViscosity<NumericType>(speed.Value() * length.Value() / reynolds_number.Value()) {}

template <typename NumericType>
inline constexpr DynamicViscosity<NumericType>::DynamicViscosity(
    const MassDensity<NumericType>& mass_density, const Speed<NumericType>& speed,
    const Length<NumericType>& length, const ReynoldsNumber<NumericType>& reynolds_number)
  : DynamicViscosity<NumericType>(
      mass_density.Value() * speed.Value() * length.Value() / reynolds_number.Value()) {}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::ReynoldsNumber<NumericType>> {
  inline size_t operator()(const PhQ::ReynoldsNumber<NumericType>& reynolds_number) const {
    return hash<NumericType>()(reynolds_number.Value());
  }
};

}  // namespace std

#endif  // PHQ_REYNOLDS_NUMBER_HPP
