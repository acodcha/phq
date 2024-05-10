// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

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

// Dynamic viscosity, also known as molecular dynamic viscosity. Dynamic viscosity is the
// relationship between the viscous stress of a material and its corresponding strain rate. Not to
// be confused with kinematic viscosity, which is dynamic viscosity divided by mass density.
template <typename Number = double>
class DynamicViscosity : public DimensionalScalar<Unit::DynamicViscosity, Number> {
public:
  // Default constructor. Constructs a dynamic viscosity with an uninitialized value.
  DynamicViscosity() = default;

  // Constructor. Constructs a dynamic viscosity with a given value expressed in a given dynamic
  // viscosity unit.
  DynamicViscosity(const Number value, const Unit::DynamicViscosity unit)
    : DimensionalScalar<Unit::DynamicViscosity, Number>(value, unit) {}

  // Constructor. Constructs a dynamic viscosity from a given mass density and kinematic viscosity
  // using the definition of kinematic viscosity.
  constexpr DynamicViscosity(const MassDensity<Number>& mass_density,
                             const KinematicViscosity<Number>& kinematic_viscosity)
    : DynamicViscosity<Number>(mass_density.Value() * kinematic_viscosity.Value()) {}

  // Constructor. Constructs a dynamic viscosity from a given mass density, speed, length, and
  // Reynolds number using the definition of the Reynolds number.
  constexpr DynamicViscosity(
      const MassDensity<Number>& mass_density, const Speed<Number>& speed,
      const Length<Number>& length, const ReynoldsNumber<Number>& reynolds_number);

  // Constructor. Constructs a dynamic viscosity from a given Prandtl number, scalar thermal
  // conductivity, and specific isobaric heat capacity using the definition of the Prandtl number.
  constexpr DynamicViscosity(
      const PrandtlNumber<Number>& prandtl_number,
      const ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity);

  // Destructor. Destroys this dynamic viscosity.
  ~DynamicViscosity() noexcept = default;

  // Copy constructor. Constructs a dynamic viscosity by copying another one.
  constexpr DynamicViscosity(const DynamicViscosity<Number>& other) = default;

  // Copy constructor. Constructs a dynamic viscosity by copying another one.
  template <typename OtherNumber>
  explicit constexpr DynamicViscosity(const DynamicViscosity<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a dynamic viscosity by moving another one.
  constexpr DynamicViscosity(DynamicViscosity<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this dynamic viscosity by copying another one.
  constexpr DynamicViscosity<Number>& operator=(const DynamicViscosity<Number>& other) = default;

  // Copy assignment operator. Assigns this dynamic viscosity by copying another one.
  template <typename OtherNumber>
  constexpr DynamicViscosity<Number>& operator=(const DynamicViscosity<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this dynamic viscosity by moving another one.
  constexpr DynamicViscosity<Number>& operator=(
      DynamicViscosity<Number>&& other) noexcept = default;

  // Statically creates a dynamic viscosity of zero.
  static constexpr DynamicViscosity<Number> Zero() {
    return DynamicViscosity<Number>{static_cast<Number>(0)};
  }

  // Statically creates a dynamic viscosity with a given value expressed in a given dynamic
  // viscosity unit.
  template <Unit::DynamicViscosity Unit>
  static constexpr DynamicViscosity<Number> Create(const Number value) {
    return DynamicViscosity<Number>{
        StaticConvertCopy<Unit::DynamicViscosity, Unit, Standard<Unit::DynamicViscosity>>(value)};
  }

  constexpr DynamicViscosity<Number> operator+(
      const DynamicViscosity<Number>& dynamic_viscosity) const {
    return DynamicViscosity<Number>{value + dynamic_viscosity.value};
  }

  constexpr DynamicViscosity<Number> operator-(
      const DynamicViscosity<Number>& dynamic_viscosity) const {
    return DynamicViscosity<Number>{value - dynamic_viscosity.value};
  }

  constexpr DynamicViscosity<Number> operator*(const Number number) const {
    return DynamicViscosity<Number>{value * number};
  }

  constexpr DynamicViscosity<Number> operator/(const Number number) const {
    return DynamicViscosity<Number>{value / number};
  }

  constexpr KinematicViscosity<Number> operator/(const MassDensity<Number>& mass_density) const {
    return KinematicViscosity<Number>{*this, mass_density};
  }

  constexpr MassDensity<Number> operator/(
      const KinematicViscosity<Number>& kinematic_viscosity) const {
    return MassDensity<Number>{*this, kinematic_viscosity};
  }

  constexpr Number operator/(const DynamicViscosity<Number>& dynamic_viscosity) const noexcept {
    return value / dynamic_viscosity.value;
  }

  constexpr void operator+=(const DynamicViscosity<Number>& dynamic_viscosity) noexcept {
    value += dynamic_viscosity.value;
  }

  constexpr void operator-=(const DynamicViscosity<Number>& dynamic_viscosity) noexcept {
    value -= dynamic_viscosity.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a dynamic viscosity with a given value expressed in the standard
  // dynamic viscosity unit.
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
