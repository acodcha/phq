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

#ifndef PHQ_DYNAMIC_VISCOSITY_HPP
#define PHQ_DYNAMIC_VISCOSITY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "KinematicViscosity.hpp"
#include "MassDensity.hpp"
#include "Unit/DynamicViscosity.hpp"

namespace PhQ {

// Forward declaration for class PhQ::DynamicViscosity.
template <typename Number>
class ReynoldsNumber;

// Forward declaration for class PhQ::DynamicViscosity.
template <typename Number>
class ScalarThermalConductivity;

// Forward declaration for class PhQ::DynamicViscosity.
template <typename Number>
class SpecificIsobaricHeatCapacity;

/// \brief Dynamic viscosity, also known as molecular dynamic viscosity. Dynamic viscosity is the
/// relationship between the viscous stress of a material and its corresponding strain rate. Not to
/// be confused with kinematic viscosity, which is dynamic viscosity divided by mass density.
template <typename Number = double>
class DynamicViscosity : public DimensionalScalar<Unit::DynamicViscosity, Number> {
public:
  /// \brief Default constructor. Constructs a dynamic viscosity with an uninitialized value.
  DynamicViscosity() = default;

  /// \brief Constructor. Constructs a dynamic viscosity with a given value expressed in a given
  /// dynamic viscosity unit.
  DynamicViscosity(const Number value, const Unit::DynamicViscosity unit)
    : DimensionalScalar<Unit::DynamicViscosity, Number>(value, unit) {}

  /// \brief Constructor. Constructs a dynamic viscosity from a given mass density and kinematic
  /// viscosity using the definition of kinematic viscosity.
  constexpr DynamicViscosity(const MassDensity<Number>& mass_density,
                             const KinematicViscosity<Number>& kinematic_viscosity)
    : DynamicViscosity<Number>(mass_density.Value() * kinematic_viscosity.Value()) {}

  /// \brief Constructor. Constructs a dynamic viscosity from a given mass density, speed, length,
  /// and Reynolds number using the definition of the Reynolds number.
  constexpr DynamicViscosity(
      const MassDensity<Number>& mass_density, const Speed<Number>& speed,
      const Length<Number>& length, const ReynoldsNumber<Number>& reynolds_number);

  /// \brief Constructor. Constructs a dynamic viscosity from a given Prandtl number, scalar thermal
  /// conductivity, and specific isobaric heat capacity using the definition of the Prandtl number.
  constexpr DynamicViscosity(
      const PrandtlNumber<Number>& prandtl_number,
      const ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity);

  /// \brief Destructor. Destroys this dynamic viscosity.
  ~DynamicViscosity() noexcept = default;

  /// \brief Copy constructor. Constructs a dynamic viscosity by copying another one.
  constexpr DynamicViscosity(const DynamicViscosity<Number>& other) = default;

  /// \brief Copy constructor. Constructs a dynamic viscosity by copying another one.
  template <typename OtherNumber>
  explicit constexpr DynamicViscosity(const DynamicViscosity<OtherNumber>& other)
    : DynamicViscosity(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a dynamic viscosity by moving another one.
  constexpr DynamicViscosity(DynamicViscosity<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this dynamic viscosity by copying another one.
  constexpr DynamicViscosity<Number>& operator=(const DynamicViscosity<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this dynamic viscosity by copying another one.
  template <typename OtherNumber>
  constexpr DynamicViscosity<Number>& operator=(const DynamicViscosity<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this dynamic viscosity by moving another one.
  constexpr DynamicViscosity<Number>& operator=(
      DynamicViscosity<Number>&& other) noexcept = default;

  /// \brief Statically creates a dynamic viscosity of zero.
  static constexpr DynamicViscosity<Number> Zero() {
    return DynamicViscosity<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a dynamic viscosity with a given value expressed in a given dynamic
  /// viscosity unit.
  template <Unit::DynamicViscosity Unit>
  static constexpr DynamicViscosity<Number> Create(const Number value) {
    return DynamicViscosity<Number>{
        StaticConvertCopy<Unit::DynamicViscosity, Unit, Standard<Unit::DynamicViscosity>>(value)};
  }

  constexpr DynamicViscosity<Number> operator+(
      const DynamicViscosity<Number>& dynamic_viscosity) const {
    return DynamicViscosity<Number>{this->value + dynamic_viscosity.value};
  }

  constexpr DynamicViscosity<Number> operator-(
      const DynamicViscosity<Number>& dynamic_viscosity) const {
    return DynamicViscosity<Number>{this->value - dynamic_viscosity.value};
  }

  constexpr DynamicViscosity<Number> operator*(const Number number) const {
    return DynamicViscosity<Number>{this->value * number};
  }

  constexpr DynamicViscosity<Number> operator/(const Number number) const {
    return DynamicViscosity<Number>{this->value / number};
  }

  constexpr KinematicViscosity<Number> operator/(const MassDensity<Number>& mass_density) const {
    return KinematicViscosity<Number>{*this, mass_density};
  }

  constexpr MassDensity<Number> operator/(
      const KinematicViscosity<Number>& kinematic_viscosity) const {
    return MassDensity<Number>{*this, kinematic_viscosity};
  }

  constexpr Number operator/(const DynamicViscosity<Number>& dynamic_viscosity) const noexcept {
    return this->value / dynamic_viscosity.value;
  }

  constexpr void operator+=(const DynamicViscosity<Number>& dynamic_viscosity) noexcept {
    this->value += dynamic_viscosity.value;
  }

  constexpr void operator-=(const DynamicViscosity<Number>& dynamic_viscosity) noexcept {
    this->value -= dynamic_viscosity.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a dynamic viscosity with a given value expressed in the
  /// standard dynamic viscosity unit.
  explicit constexpr DynamicViscosity(const Number value)
    : DimensionalScalar<Unit::DynamicViscosity, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const DynamicViscosity<Number>& left, const DynamicViscosity<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const DynamicViscosity<Number>& left, const DynamicViscosity<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const DynamicViscosity<Number>& left, const DynamicViscosity<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const DynamicViscosity<Number>& left, const DynamicViscosity<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const DynamicViscosity<Number>& left, const DynamicViscosity<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const DynamicViscosity<Number>& left, const DynamicViscosity<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const DynamicViscosity<Number>& dynamic_viscosity) {
  stream << dynamic_viscosity.Print();
  return stream;
}

template <typename Number>
inline constexpr DynamicViscosity<Number> operator*(
    const Number number, const DynamicViscosity<Number>& dynamic_viscosity) {
  return dynamic_viscosity * number;
}

template <typename Number>
inline constexpr MassDensity<Number>::MassDensity(
    const DynamicViscosity<Number>& dynamic_viscosity,
    const KinematicViscosity<Number>& kinematic_viscosity)
  : MassDensity<Number>(dynamic_viscosity.Value() / kinematic_viscosity.Value()) {}

template <typename Number>
inline constexpr KinematicViscosity<Number>::KinematicViscosity(
    const DynamicViscosity<Number>& dynamic_viscosity, const MassDensity<Number>& mass_density)
  : KinematicViscosity<Number>(dynamic_viscosity.Value() / mass_density.Value()) {}

template <typename Number>
inline constexpr DynamicViscosity<Number> KinematicViscosity<Number>::operator*(
    const MassDensity<Number>& mass_density) const {
  return DynamicViscosity<Number>{mass_density, *this};
}

template <typename Number>
inline constexpr DynamicViscosity<Number> MassDensity<Number>::operator*(
    const KinematicViscosity<Number>& kinematic_viscosity) const {
  return DynamicViscosity<Number>{*this, kinematic_viscosity};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::DynamicViscosity<Number>> {
  inline size_t operator()(const PhQ::DynamicViscosity<Number>& dynamic_viscosity) const {
    return hash<Number>()(dynamic_viscosity.Value());
  }
};

}  // namespace std

#endif  // PHQ_DYNAMIC_VISCOSITY_HPP
