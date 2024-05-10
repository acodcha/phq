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

// Kinematic viscosity, also known as molecular kinematic viscosity. Kinematic viscosity is defined
// as dynamic viscosity divided by mass density.
template <typename Number = double>
class KinematicViscosity : public DimensionalScalar<Unit::Diffusivity, Number> {
public:
  // Default constructor. Constructs a kinematic viscosity with an uninitialized value.
  KinematicViscosity() = default;

  // Constructor. Constructs a kinematic viscosity with a given value expressed in a given
  // diffusivity unit.
  KinematicViscosity(const Number value, const Unit::Diffusivity unit)
    : DimensionalScalar<Unit::Diffusivity, Number>(value, unit) {}

  // Constructor. Constructs a kinematic viscosity from a given dynamic viscosity and mass density
  // using the definition of kinematic viscosity.
  constexpr KinematicViscosity(
      const DynamicViscosity<Number>& dynamic_viscosity, const MassDensity<Number>& mass_density);

  // Constructor. Constructs a kinematic viscosity from a given speed, length, and Reynolds number
  // using the definition of the Reynolds number.
  constexpr KinematicViscosity(const Speed<Number>& speed, const Length<Number>& length,
                               const ReynoldsNumber<Number>& reynolds_number);

  // Constructor. Constructs a kinematic viscosity from a given Prandtl number and thermal
  // diffusivity using the definition of Prandtl number.
  constexpr KinematicViscosity(const PrandtlNumber<Number>& prandtl_number,
                               const ThermalDiffusivity<Number>& thermal_diffusivity);

  // Destructor. Destroys this kinematic viscosity.
  ~KinematicViscosity() noexcept = default;

  // Copy constructor. Constructs a kinematic viscosity by copying another one.
  constexpr KinematicViscosity(const KinematicViscosity<Number>& other) = default;

  // Copy constructor. Constructs a kinematic viscosity by copying another one.
  template <typename OtherNumber>
  explicit constexpr KinematicViscosity(const KinematicViscosity<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a kinematic viscosity by moving another one.
  constexpr KinematicViscosity(KinematicViscosity<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this kinematic viscosity by copying another one.
  constexpr KinematicViscosity<Number>& operator=(
      const KinematicViscosity<Number>& other) = default;

  // Copy assignment operator. Assigns this kinematic viscosity by copying another one.
  template <typename OtherNumber>
  constexpr KinematicViscosity<Number>& operator=(const KinematicViscosity<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this kinematic viscosity by moving another one.
  constexpr KinematicViscosity<Number>& operator=(
      KinematicViscosity<Number>&& other) noexcept = default;

  // Statically creates a kinematic viscosity of zero.
  static constexpr KinematicViscosity<Number> Zero() {
    return KinematicViscosity<Number>{static_cast<Number>(0)};
  }

  // Statically creates a kinematic viscosity with a given value expressed in a given diffusivity
  // unit.
  template <Unit::Diffusivity Unit>
  static constexpr KinematicViscosity<Number> Create(const Number value) {
    return KinematicViscosity<Number>{
        StaticConvertCopy<Unit::Diffusivity, Unit, Standard<Unit::Diffusivity>>(value)};
  }

  constexpr KinematicViscosity<Number> operator+(
      const KinematicViscosity<Number>& kinematic_viscosity) const {
    return KinematicViscosity<Number>{value + kinematic_viscosity.value};
  }

  constexpr KinematicViscosity<Number> operator-(
      const KinematicViscosity<Number>& kinematic_viscosity) const {
    return KinematicViscosity<Number>{value - kinematic_viscosity.value};
  }

  constexpr KinematicViscosity<Number> operator*(const Number number) const {
    return KinematicViscosity<Number>{value * number};
  }

  constexpr DynamicViscosity<Number> operator*(const MassDensity<Number>& mass_density) const;

  constexpr KinematicViscosity<Number> operator/(const Number number) const {
    return KinematicViscosity<Number>{value / number};
  }

  constexpr Number operator/(const KinematicViscosity<Number>& kinematic_viscosity) const noexcept {
    return value / kinematic_viscosity.value;
  }

  constexpr void operator+=(const KinematicViscosity<Number>& kinematic_viscosity) noexcept {
    value += kinematic_viscosity.value;
  }

  constexpr void operator-=(const KinematicViscosity<Number>& kinematic_viscosity) noexcept {
    value -= kinematic_viscosity.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a kinematic viscosity with a given value expressed in the standard
  // diffusivity unit.
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
