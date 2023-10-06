// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DYNAMIC_VISCOSITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DYNAMIC_VISCOSITY_HPP

#include "KinematicViscosity.hpp"
#include "MassDensity.hpp"
#include "Unit/DynamicViscosity.hpp"

namespace PhQ {

// Forward declarations for class DynamicViscosity.
class ReynoldsNumber;
class ThermalConductivityScalar;
class SpecificIsobaricHeatCapacity;

// Dynamic viscosity, also known as molecular dynamic viscosity. Dynamic
// viscosity is the relationship between the viscous stress of a material and
// its corresponding strain rate. Not to be confused with kinematic viscosity,
// which is dynamic viscosity divided by mass density.
class DynamicViscosity
  : public DimensionalScalarQuantity<Unit::DynamicViscosity> {
public:
  // Default constructor. Constructs a dynamic viscosity with an uninitialized
  // value.
  DynamicViscosity() = default;

  // Constructor. Constructs a dynamic viscosity with a given value expressed in
  // a given dynamic viscosity unit.
  DynamicViscosity(const double value, const Unit::DynamicViscosity unit)
    : DimensionalScalarQuantity<Unit::DynamicViscosity>(value, unit) {}

  // Constructor. Constructs a dynamic viscosity from a given mass density and
  // kinematic viscosity using the definition of kinematic viscosity.
  constexpr DynamicViscosity(const MassDensity& mass_density,
                             const KinematicViscosity& kinematic_viscosity)
    : DynamicViscosity(mass_density.Value() * kinematic_viscosity.Value()) {}

  // Constructor. Constructs a dynamic viscosity from a given mass density,
  // speed, length, and Reynolds number using the definition of the Reynolds
  // number.
  constexpr DynamicViscosity(
      const MassDensity& mass_density, const Speed& speed, const Length& length,
      const ReynoldsNumber& reynolds_number);

  // Constructor. Constructs a dynamic viscosity from a given Prandtl number,
  // thermal conductivity, and specific isobaric heat capacity using the
  // definition of the Prandtl number.
  constexpr DynamicViscosity(
      const PrandtlNumber& prandtl_number,
      const ThermalConductivityScalar& thermal_conductivity_scalar,
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity);

  // Destructor. Destroys this dynamic viscosity.
  ~DynamicViscosity() noexcept = default;

  // Copy constructor. Constructs a dynamic viscosity by copying another one.
  constexpr DynamicViscosity(const DynamicViscosity& other) = default;

  // Move constructor. Constructs a dynamic viscosity by moving another one.
  constexpr DynamicViscosity(DynamicViscosity&& other) noexcept = default;

  // Copy assignment operator. Assigns this dynamic viscosity by copying another
  // one.
  constexpr DynamicViscosity& operator=(
      const DynamicViscosity& other) = default;

  // Move assignment operator. Assigns this dynamic viscosity by moving another
  // one.
  constexpr DynamicViscosity& operator=(
      DynamicViscosity&& other) noexcept = default;

  // Statically creates a dynamic viscosity of zero.
  static constexpr DynamicViscosity Zero() {
    return DynamicViscosity{0.0};
  }

  // Statically creates a dynamic viscosity with a given value expressed in a
  // given dynamic viscosity unit.
  template <Unit::DynamicViscosity Unit>
  static constexpr DynamicViscosity Create(const double value) {
    return DynamicViscosity{
        StaticConvertCopy<Unit::DynamicViscosity, Unit,
                          Standard<Unit::DynamicViscosity>>(value)};
  }

  constexpr DynamicViscosity operator+(
      const DynamicViscosity& dynamic_viscosity) const {
    return DynamicViscosity{value_ + dynamic_viscosity.value_};
  }

  constexpr DynamicViscosity operator-(
      const DynamicViscosity& dynamic_viscosity) const {
    return DynamicViscosity{value_ - dynamic_viscosity.value_};
  }

  constexpr DynamicViscosity operator*(const double number) const {
    return DynamicViscosity{value_ * number};
  }

  constexpr DynamicViscosity operator/(const double number) const {
    return DynamicViscosity{value_ / number};
  }

  constexpr KinematicViscosity operator/(
      const MassDensity& mass_density) const {
    return {*this, mass_density};
  }

  constexpr MassDensity operator/(
      const KinematicViscosity& kinematic_viscosity) const {
    return {*this, kinematic_viscosity};
  }

  constexpr double operator/(
      const DynamicViscosity& dynamic_viscosity) const noexcept {
    return value_ / dynamic_viscosity.value_;
  }

  constexpr void operator+=(
      const DynamicViscosity& dynamic_viscosity) noexcept {
    value_ += dynamic_viscosity.value_;
  }

  constexpr void operator-=(
      const DynamicViscosity& dynamic_viscosity) noexcept {
    value_ -= dynamic_viscosity.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a dynamic viscosity with a given value expressed in
  // the standard dynamic viscosity unit.
  explicit constexpr DynamicViscosity(const double value)
    : DimensionalScalarQuantity<Unit::DynamicViscosity>(value) {}
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

inline std::ostream& operator<<(
    std::ostream& stream, const DynamicViscosity& dynamic_viscosity) {
  stream << dynamic_viscosity.Print();
  return stream;
}

inline constexpr DynamicViscosity operator*(
    const double number, const DynamicViscosity& dynamic_viscosity) {
  return dynamic_viscosity * number;
}

inline constexpr MassDensity::MassDensity(
    const DynamicViscosity& dynamic_viscosity,
    const KinematicViscosity& kinematic_viscosity)
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
  inline size_t operator()(
      const PhQ::DynamicViscosity& dynamic_viscosity) const {
    return hash<double>()(dynamic_viscosity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DYNAMIC_VISCOSITY_HPP
