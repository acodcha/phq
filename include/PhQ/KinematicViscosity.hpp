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

#ifndef PHQ_KINEMATIC_VISCOSITY_HPP
#define PHQ_KINEMATIC_VISCOSITY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Diffusivity.hpp"

namespace PhQ {

// Forward declarations for class KinematicViscosity.
class DynamicViscosity;
class Length;
class MassDensity;
class PrandtlNumber;
class ReynoldsNumber;
class Speed;
class ThermalDiffusivity;

// Kinematic viscosity, also known as molecular kinematic viscosity. Kinematic viscosity is defined
// as dynamic viscosity divided by mass density.
class KinematicViscosity : public DimensionalScalar<Unit::Diffusivity, double> {
public:
  // Default constructor. Constructs a kinematic viscosity with an uninitialized value.
  KinematicViscosity() = default;

  // Constructor. Constructs a kinematic viscosity with a given value expressed in a given
  // diffusivity unit.
  KinematicViscosity(const double value, const Unit::Diffusivity unit)
    : DimensionalScalar<Unit::Diffusivity>(value, unit) {}

  // Constructor. Constructs a kinematic viscosity from a given dynamic viscosity and mass density
  // using the definition of kinematic viscosity.
  constexpr KinematicViscosity(
      const DynamicViscosity& dynamic_viscosity, const MassDensity& mass_density);

  // Constructor. Constructs a kinematic viscosity from a given speed, length, and Reynolds number
  // using the definition of the Reynolds number.
  constexpr KinematicViscosity(
      const Speed& speed, const Length& length, const ReynoldsNumber& reynolds_number);

  // Constructor. Constructs a kinematic viscosity from a given Prandtl number and thermal
  // diffusivity using the definition of Prandtl number.
  constexpr KinematicViscosity(
      const PrandtlNumber& prandtl_number, const ThermalDiffusivity& thermal_diffusivity);

  // Destructor. Destroys this kinematic viscosity.
  ~KinematicViscosity() noexcept = default;

  // Copy constructor. Constructs a kinematic viscosity by copying another one.
  constexpr KinematicViscosity(const KinematicViscosity& other) = default;

  // Move constructor. Constructs a kinematic viscosity by moving another one.
  constexpr KinematicViscosity(KinematicViscosity&& other) noexcept = default;

  // Copy assignment operator. Assigns this kinematic viscosity by copying another one.
  constexpr KinematicViscosity& operator=(const KinematicViscosity& other) = default;

  // Move assignment operator. Assigns this kinematic viscosity by moving another one.
  constexpr KinematicViscosity& operator=(KinematicViscosity&& other) noexcept = default;

  // Statically creates a kinematic viscosity of zero.
  static constexpr KinematicViscosity Zero() {
    return KinematicViscosity{0.0};
  }

  // Statically creates a kinematic viscosity with a given value expressed in a given diffusivity
  // unit.
  template <Unit::Diffusivity Unit>
  static constexpr KinematicViscosity Create(const double value) {
    return KinematicViscosity{
        StaticConvertCopy<Unit::Diffusivity, Unit, Standard<Unit::Diffusivity>>(value)};
  }

  constexpr KinematicViscosity operator+(const KinematicViscosity& kinematic_viscosity) const {
    return KinematicViscosity{value + kinematic_viscosity.value};
  }

  constexpr KinematicViscosity operator-(const KinematicViscosity& kinematic_viscosity) const {
    return KinematicViscosity{value - kinematic_viscosity.value};
  }

  constexpr KinematicViscosity operator*(const double number) const {
    return KinematicViscosity{value * number};
  }

  constexpr DynamicViscosity operator*(const MassDensity& mass_density) const;

  constexpr KinematicViscosity operator/(const double number) const {
    return KinematicViscosity{value / number};
  }

  constexpr double operator/(const KinematicViscosity& kinematic_viscosity) const noexcept {
    return value / kinematic_viscosity.value;
  }

  constexpr void operator+=(const KinematicViscosity& kinematic_viscosity) noexcept {
    value += kinematic_viscosity.value;
  }

  constexpr void operator-=(const KinematicViscosity& kinematic_viscosity) noexcept {
    value -= kinematic_viscosity.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a kinematic viscosity with a given value expressed in the standard
  // diffusivity unit.
  explicit constexpr KinematicViscosity(const double value)
    : DimensionalScalar<Unit::Diffusivity>(value) {}
};

inline constexpr bool operator==(
    const KinematicViscosity& left, const KinematicViscosity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const KinematicViscosity& left, const KinematicViscosity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const KinematicViscosity& left, const KinematicViscosity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const KinematicViscosity& left, const KinematicViscosity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const KinematicViscosity& left, const KinematicViscosity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const KinematicViscosity& left, const KinematicViscosity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const KinematicViscosity& kinematic_viscosity) {
  stream << kinematic_viscosity.Print();
  return stream;
}

inline constexpr KinematicViscosity operator*(
    const double number, const KinematicViscosity& kinematic_viscosity) {
  return kinematic_viscosity * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::KinematicViscosity> {
  inline size_t operator()(const PhQ::KinematicViscosity& kinematic_viscosity) const {
    return hash<double>()(kinematic_viscosity.Value());
  }
};

}  // namespace std

#endif  // PHQ_KINEMATIC_VISCOSITY_HPP
