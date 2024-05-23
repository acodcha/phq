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

#ifndef PHQ_KINEMATIC_VISCOSITY_HPP
#define PHQ_KINEMATIC_VISCOSITY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Diffusivity.hpp"

namespace PhQ {

// Forward declaration for class PhQ::KinematicViscosity.
template <typename Number>
class DynamicViscosity;

// Forward declaration for class PhQ::KinematicViscosity.
template <typename Number>
class Length;

// Forward declaration for class PhQ::KinematicViscosity.
template <typename Number>
class MassDensity;

// Forward declaration for class PhQ::KinematicViscosity.
template <typename Number>
class PrandtlNumber;

// Forward declaration for class PhQ::KinematicViscosity.
template <typename Number>
class ReynoldsNumber;

// Forward declaration for class PhQ::KinematicViscosity.
template <typename Number>
class Speed;

// Forward declaration for class PhQ::KinematicViscosity.
template <typename Number>
class ThermalDiffusivity;

/// \brief Kinematic viscosity, also known as molecular kinematic viscosity. Kinematic viscosity is
/// defined as dynamic viscosity divided by mass density.
template <typename Number = double>
class KinematicViscosity : public DimensionalScalar<Unit::Diffusivity, Number> {
public:
  /// \brief Default constructor. Constructs a kinematic viscosity with an uninitialized value.
  KinematicViscosity() = default;

  /// \brief Constructor. Constructs a kinematic viscosity with a given value expressed in a given
  /// diffusivity unit.
  KinematicViscosity(const Number value, const Unit::Diffusivity unit)
    : DimensionalScalar<Unit::Diffusivity, Number>(value, unit) {}

  /// \brief Constructor. Constructs a kinematic viscosity from a given dynamic viscosity and mass
  /// density using the definition of kinematic viscosity.
  constexpr KinematicViscosity(
      const DynamicViscosity<Number>& dynamic_viscosity, const MassDensity<Number>& mass_density);

  /// \brief Constructor. Constructs a kinematic viscosity from a given speed, length, and Reynolds
  /// number using the definition of the Reynolds number.
  constexpr KinematicViscosity(const Speed<Number>& speed, const Length<Number>& length,
                               const ReynoldsNumber<Number>& reynolds_number);

  /// \brief Constructor. Constructs a kinematic viscosity from a given Prandtl number and thermal
  /// diffusivity using the definition of Prandtl number.
  constexpr KinematicViscosity(const PrandtlNumber<Number>& prandtl_number,
                               const ThermalDiffusivity<Number>& thermal_diffusivity);

  /// \brief Destructor. Destroys this kinematic viscosity.
  ~KinematicViscosity() noexcept = default;

  /// \brief Copy constructor. Constructs a kinematic viscosity by copying another one.
  constexpr KinematicViscosity(const KinematicViscosity<Number>& other) = default;

  /// \brief Copy constructor. Constructs a kinematic viscosity by copying another one.
  template <typename OtherNumber>
  explicit constexpr KinematicViscosity(const KinematicViscosity<OtherNumber>& other)
    : KinematicViscosity(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a kinematic viscosity by moving another one.
  constexpr KinematicViscosity(KinematicViscosity<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this kinematic viscosity by copying another one.
  constexpr KinematicViscosity<Number>& operator=(
      const KinematicViscosity<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this kinematic viscosity by copying another one.
  template <typename OtherNumber>
  constexpr KinematicViscosity<Number>& operator=(const KinematicViscosity<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this kinematic viscosity by moving another one.
  constexpr KinematicViscosity<Number>& operator=(
      KinematicViscosity<Number>&& other) noexcept = default;

  /// \brief Statically creates a kinematic viscosity of zero.
  static constexpr KinematicViscosity<Number> Zero() {
    return KinematicViscosity<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a kinematic viscosity with a given value expressed in a given
  /// diffusivity unit.
  template <Unit::Diffusivity Unit>
  static constexpr KinematicViscosity<Number> Create(const Number value) {
    return KinematicViscosity<Number>{
        StaticConvertCopy<Unit::Diffusivity, Unit, Standard<Unit::Diffusivity>>(value)};
  }

  constexpr KinematicViscosity<Number> operator+(
      const KinematicViscosity<Number>& kinematic_viscosity) const {
    return KinematicViscosity<Number>{this->value + kinematic_viscosity.value};
  }

  constexpr KinematicViscosity<Number> operator-(
      const KinematicViscosity<Number>& kinematic_viscosity) const {
    return KinematicViscosity<Number>{this->value - kinematic_viscosity.value};
  }

  constexpr KinematicViscosity<Number> operator*(const Number number) const {
    return KinematicViscosity<Number>{this->value * number};
  }

  constexpr DynamicViscosity<Number> operator*(const MassDensity<Number>& mass_density) const;

  constexpr KinematicViscosity<Number> operator/(const Number number) const {
    return KinematicViscosity<Number>{this->value / number};
  }

  constexpr Number operator/(const KinematicViscosity<Number>& kinematic_viscosity) const noexcept {
    return this->value / kinematic_viscosity.value;
  }

  constexpr void operator+=(const KinematicViscosity<Number>& kinematic_viscosity) noexcept {
    this->value += kinematic_viscosity.value;
  }

  constexpr void operator-=(const KinematicViscosity<Number>& kinematic_viscosity) noexcept {
    this->value -= kinematic_viscosity.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a kinematic viscosity with a given value expressed in the
  /// standard diffusivity unit.
  explicit constexpr KinematicViscosity(const Number value)
    : DimensionalScalar<Unit::Diffusivity, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const KinematicViscosity<Number>& left, const KinematicViscosity<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const KinematicViscosity<Number>& left, const KinematicViscosity<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const KinematicViscosity<Number>& left, const KinematicViscosity<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const KinematicViscosity<Number>& left, const KinematicViscosity<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const KinematicViscosity<Number>& left, const KinematicViscosity<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const KinematicViscosity<Number>& left, const KinematicViscosity<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const KinematicViscosity<Number>& kinematic_viscosity) {
  stream << kinematic_viscosity.Print();
  return stream;
}

template <typename Number>
inline constexpr KinematicViscosity<Number> operator*(
    const Number number, const KinematicViscosity<Number>& kinematic_viscosity) {
  return kinematic_viscosity * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::KinematicViscosity<Number>> {
  inline size_t operator()(const PhQ::KinematicViscosity<Number>& kinematic_viscosity) const {
    return hash<Number>()(kinematic_viscosity.Value());
  }
};

}  // namespace std

#endif  // PHQ_KINEMATIC_VISCOSITY_HPP
