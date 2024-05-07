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

// Forward declarations for class DynamicViscosity.
class ReynoldsNumber;
class ScalarThermalConductivity;
class SpecificIsobaricHeatCapacity;

// Dynamic viscosity, also known as molecular dynamic viscosity. Dynamic viscosity is the
// relationship between the viscous stress of a material and its corresponding strain rate. Not to
// be confused with kinematic viscosity, which is dynamic viscosity divided by mass density.
class DynamicViscosity : public DimensionalScalar<Unit::DynamicViscosity, double> {
public:
  // Default constructor. Constructs a dynamic viscosity with an uninitialized value.
  DynamicViscosity() = default;

  // Constructor. Constructs a dynamic viscosity with a given value expressed in a given dynamic
  // viscosity unit.
  DynamicViscosity(const double value, const Unit::DynamicViscosity unit)
    : DimensionalScalar<Unit::DynamicViscosity>(value, unit) {}

  // Constructor. Constructs a dynamic viscosity from a given mass density and kinematic viscosity
  // using the definition of kinematic viscosity.
  constexpr DynamicViscosity(
      const MassDensity& mass_density, const KinematicViscosity& kinematic_viscosity)
    : DynamicViscosity(mass_density.Value() * kinematic_viscosity.Value()) {}

  // Constructor. Constructs a dynamic viscosity from a given mass density, speed, length, and
  // Reynolds number using the definition of the Reynolds number.
  constexpr DynamicViscosity(const MassDensity& mass_density, const Speed& speed,
                             const Length& length, const ReynoldsNumber& reynolds_number);

  // Constructor. Constructs a dynamic viscosity from a given Prandtl number, scalar thermal
  // conductivity, and specific isobaric heat capacity using the definition of the Prandtl number.
  constexpr DynamicViscosity(const PrandtlNumber& prandtl_number,
                             const ScalarThermalConductivity& scalar_thermal_conductivity,
                             const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity);

  // Destructor. Destroys this dynamic viscosity.
  ~DynamicViscosity() noexcept = default;

  // Copy constructor. Constructs a dynamic viscosity by copying another one.
  constexpr DynamicViscosity(const DynamicViscosity& other) = default;

  // Move constructor. Constructs a dynamic viscosity by moving another one.
  constexpr DynamicViscosity(DynamicViscosity&& other) noexcept = default;

  // Copy assignment operator. Assigns this dynamic viscosity by copying another one.
  constexpr DynamicViscosity& operator=(const DynamicViscosity& other) = default;

  // Move assignment operator. Assigns this dynamic viscosity by moving another one.
  constexpr DynamicViscosity& operator=(DynamicViscosity&& other) noexcept = default;

  // Statically creates a dynamic viscosity of zero.
  static constexpr DynamicViscosity Zero() {
    return DynamicViscosity{0.0};
  }

  // Statically creates a dynamic viscosity with a given value expressed in a given dynamic
  // viscosity unit.
  template <Unit::DynamicViscosity Unit>
  static constexpr DynamicViscosity Create(const double value) {
    return DynamicViscosity{
        StaticConvertCopy<Unit::DynamicViscosity, Unit, Standard<Unit::DynamicViscosity>>(value)};
  }

  constexpr DynamicViscosity operator+(const DynamicViscosity& dynamic_viscosity) const {
    return DynamicViscosity{value + dynamic_viscosity.value};
  }

  constexpr DynamicViscosity operator-(const DynamicViscosity& dynamic_viscosity) const {
    return DynamicViscosity{value - dynamic_viscosity.value};
  }

  constexpr DynamicViscosity operator*(const double number) const {
    return DynamicViscosity{value * number};
  }

  constexpr DynamicViscosity operator/(const double number) const {
    return DynamicViscosity{value / number};
  }

  constexpr KinematicViscosity operator/(const MassDensity& mass_density) const {
    return {*this, mass_density};
  }

  constexpr MassDensity operator/(const KinematicViscosity& kinematic_viscosity) const {
    return {*this, kinematic_viscosity};
  }

  constexpr double operator/(const DynamicViscosity& dynamic_viscosity) const noexcept {
    return value / dynamic_viscosity.value;
  }

  constexpr void operator+=(const DynamicViscosity& dynamic_viscosity) noexcept {
    value += dynamic_viscosity.value;
  }

  constexpr void operator-=(const DynamicViscosity& dynamic_viscosity) noexcept {
    value -= dynamic_viscosity.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a dynamic viscosity with a given value expressed in the standard
  // dynamic viscosity unit.
  explicit constexpr DynamicViscosity(const double value)
    : DimensionalScalar<Unit::DynamicViscosity>(value) {}
};

inline constexpr bool operator==(
    const DynamicViscosity& left, const DynamicViscosity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const DynamicViscosity& left, const DynamicViscosity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const DynamicViscosity& left, const DynamicViscosity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const DynamicViscosity& left, const DynamicViscosity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const DynamicViscosity& left, const DynamicViscosity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const DynamicViscosity& left, const DynamicViscosity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const DynamicViscosity& dynamic_viscosity) {
  stream << dynamic_viscosity.Print();
  return stream;
}

inline constexpr DynamicViscosity operator*(
    const double number, const DynamicViscosity& dynamic_viscosity) {
  return dynamic_viscosity * number;
}

inline constexpr MassDensity::MassDensity(
    const DynamicViscosity& dynamic_viscosity, const KinematicViscosity& kinematic_viscosity)
  : MassDensity(dynamic_viscosity.Value() / kinematic_viscosity.Value()) {}

inline constexpr KinematicViscosity::KinematicViscosity(
    const DynamicViscosity& dynamic_viscosity, const MassDensity& mass_density)
  : KinematicViscosity(dynamic_viscosity.Value() / mass_density.Value()) {}

inline constexpr DynamicViscosity KinematicViscosity::operator*(
    const MassDensity& mass_density) const {
  return {mass_density, *this};
}

inline constexpr DynamicViscosity MassDensity::operator*(
    const KinematicViscosity& kinematic_viscosity) const {
  return {*this, kinematic_viscosity};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::DynamicViscosity> {
  inline size_t operator()(const PhQ::DynamicViscosity& dynamic_viscosity) const {
    return hash<double>()(dynamic_viscosity.Value());
  }
};

}  // namespace std

#endif  // PHQ_DYNAMIC_VISCOSITY_HPP
