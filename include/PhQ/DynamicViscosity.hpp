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
template <typename NumericType>
class ReynoldsNumber;

// Forward declaration for class PhQ::DynamicViscosity.
template <typename NumericType>
class ScalarThermalConductivity;

// Forward declaration for class PhQ::DynamicViscosity.
template <typename NumericType>
class SpecificIsobaricHeatCapacity;

/// \brief Dynamic viscosity, also known as molecular dynamic viscosity. Dynamic viscosity is the
/// relationship between the viscous stress of a material and its corresponding strain rate. Not to
/// be confused with kinematic viscosity, which is dynamic viscosity divided by mass density; see
/// PhQ::KinematicViscosity and PhQ::MassDensity. Also not to be confused with bulk dynamic
/// viscosity; see PhQ::BulkDynamicViscosity.
template <typename NumericType = double>
class DynamicViscosity : public DimensionalScalar<Unit::DynamicViscosity, NumericType> {
public:
  /// \brief Default constructor. Constructs a dynamic viscosity with an uninitialized value.
  DynamicViscosity() = default;

  /// \brief Constructor. Constructs a dynamic viscosity with a given value expressed in a given
  /// dynamic viscosity unit.
  DynamicViscosity(const NumericType value, const Unit::DynamicViscosity unit)
    : DimensionalScalar<Unit::DynamicViscosity, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a dynamic viscosity from a given mass density and kinematic
  /// viscosity using the definition of kinematic viscosity.
  constexpr DynamicViscosity(const MassDensity<NumericType>& mass_density,
                             const KinematicViscosity<NumericType>& kinematic_viscosity)
    : DynamicViscosity<NumericType>(mass_density.Value() * kinematic_viscosity.Value()) {}

  /// \brief Constructor. Constructs a dynamic viscosity from a given mass density, speed, length,
  /// and Reynolds number using the definition of the Reynolds number.
  constexpr DynamicViscosity(
      const MassDensity<NumericType>& mass_density, const Speed<NumericType>& speed,
      const Length<NumericType>& length, const ReynoldsNumber<NumericType>& reynolds_number);

  /// \brief Constructor. Constructs a dynamic viscosity from a given Prandtl number, scalar thermal
  /// conductivity, and specific isobaric heat capacity using the definition of the Prandtl number.
  constexpr DynamicViscosity(
      const PrandtlNumber<NumericType>& prandtl_number,
      const ScalarThermalConductivity<NumericType>& scalar_thermal_conductivity,
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity);

  /// \brief Destructor. Destroys this dynamic viscosity.
  ~DynamicViscosity() noexcept = default;

  /// \brief Copy constructor. Constructs a dynamic viscosity by copying another one.
  constexpr DynamicViscosity(const DynamicViscosity<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a dynamic viscosity by copying another one.
  template <typename OtherNumericType>
  explicit constexpr DynamicViscosity(const DynamicViscosity<OtherNumericType>& other)
    : DynamicViscosity(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a dynamic viscosity by moving another one.
  constexpr DynamicViscosity(DynamicViscosity<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this dynamic viscosity by copying another one.
  constexpr DynamicViscosity<NumericType>& operator=(
      const DynamicViscosity<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this dynamic viscosity by copying another one.
  template <typename OtherNumericType>
  constexpr DynamicViscosity<NumericType>& operator=(
      const DynamicViscosity<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this dynamic viscosity by moving another one.
  constexpr DynamicViscosity<NumericType>& operator=(
      DynamicViscosity<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a dynamic viscosity of zero.
  static constexpr DynamicViscosity<NumericType> Zero() {
    return DynamicViscosity<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a dynamic viscosity with a given value expressed in a given dynamic
  /// viscosity unit.
  template <Unit::DynamicViscosity Unit>
  static constexpr DynamicViscosity<NumericType> Create(const NumericType value) {
    return DynamicViscosity<NumericType>{
        ConvertStatically<Unit::DynamicViscosity, Unit, Standard<Unit::DynamicViscosity>>(value)};
  }

  constexpr DynamicViscosity<NumericType> operator+(
      const DynamicViscosity<NumericType>& dynamic_viscosity) const {
    return DynamicViscosity<NumericType>{this->value + dynamic_viscosity.value};
  }

  constexpr DynamicViscosity<NumericType> operator-(
      const DynamicViscosity<NumericType>& dynamic_viscosity) const {
    return DynamicViscosity<NumericType>{this->value - dynamic_viscosity.value};
  }

  constexpr DynamicViscosity<NumericType> operator*(const NumericType number) const {
    return DynamicViscosity<NumericType>{this->value * number};
  }

  constexpr DynamicViscosity<NumericType> operator/(const NumericType number) const {
    return DynamicViscosity<NumericType>{this->value / number};
  }

  constexpr KinematicViscosity<NumericType> operator/(
      const MassDensity<NumericType>& mass_density) const {
    return KinematicViscosity<NumericType>{*this, mass_density};
  }

  constexpr MassDensity<NumericType> operator/(
      const KinematicViscosity<NumericType>& kinematic_viscosity) const {
    return MassDensity<NumericType>{*this, kinematic_viscosity};
  }

  constexpr NumericType operator/(
      const DynamicViscosity<NumericType>& dynamic_viscosity) const noexcept {
    return this->value / dynamic_viscosity.value;
  }

  constexpr void operator+=(const DynamicViscosity<NumericType>& dynamic_viscosity) noexcept {
    this->value += dynamic_viscosity.value;
  }

  constexpr void operator-=(const DynamicViscosity<NumericType>& dynamic_viscosity) noexcept {
    this->value -= dynamic_viscosity.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a dynamic viscosity with a given value expressed in the
  /// standard dynamic viscosity unit.
  explicit constexpr DynamicViscosity(const NumericType value)
    : DimensionalScalar<Unit::DynamicViscosity, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const DynamicViscosity<NumericType>& left,
                                 const DynamicViscosity<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const DynamicViscosity<NumericType>& left,
                                 const DynamicViscosity<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const DynamicViscosity<NumericType>& left,
                                const DynamicViscosity<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const DynamicViscosity<NumericType>& left,
                                const DynamicViscosity<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const DynamicViscosity<NumericType>& left,
                                 const DynamicViscosity<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const DynamicViscosity<NumericType>& left,
                                 const DynamicViscosity<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const DynamicViscosity<NumericType>& dynamic_viscosity) {
  stream << dynamic_viscosity.Print();
  return stream;
}

template <typename NumericType>
inline constexpr DynamicViscosity<NumericType> operator*(
    const NumericType number, const DynamicViscosity<NumericType>& dynamic_viscosity) {
  return dynamic_viscosity * number;
}

template <typename NumericType>
inline constexpr MassDensity<NumericType>::MassDensity(
    const DynamicViscosity<NumericType>& dynamic_viscosity,
    const KinematicViscosity<NumericType>& kinematic_viscosity)
  : MassDensity<NumericType>(dynamic_viscosity.Value() / kinematic_viscosity.Value()) {}

template <typename NumericType>
inline constexpr KinematicViscosity<NumericType>::KinematicViscosity(
    const DynamicViscosity<NumericType>& dynamic_viscosity,
    const MassDensity<NumericType>& mass_density)
  : KinematicViscosity<NumericType>(dynamic_viscosity.Value() / mass_density.Value()) {}

template <typename NumericType>
inline constexpr DynamicViscosity<NumericType> KinematicViscosity<NumericType>::operator*(
    const MassDensity<NumericType>& mass_density) const {
  return DynamicViscosity<NumericType>{mass_density, *this};
}

template <typename NumericType>
inline constexpr DynamicViscosity<NumericType> MassDensity<NumericType>::operator*(
    const KinematicViscosity<NumericType>& kinematic_viscosity) const {
  return DynamicViscosity<NumericType>{*this, kinematic_viscosity};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::DynamicViscosity<NumericType>> {
  inline size_t operator()(const PhQ::DynamicViscosity<NumericType>& dynamic_viscosity) const {
    return hash<NumericType>()(dynamic_viscosity.Value());
  }
};

}  // namespace std

#endif  // PHQ_DYNAMIC_VISCOSITY_HPP
