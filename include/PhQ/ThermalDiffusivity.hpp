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

#ifndef PHQ_THERMAL_DIFFUSIVITY_HPP
#define PHQ_THERMAL_DIFFUSIVITY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "MassDensity.hpp"
#include "ScalarThermalConductivity.hpp"
#include "SpecificIsobaricHeatCapacity.hpp"
#include "Unit/Diffusivity.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ThermalDiffusivity.
template <typename Number>
class PrandtlNumber;

// Thermal diffusivity.
template <typename Number = double>
class ThermalDiffusivity : public DimensionalScalar<Unit::Diffusivity, Number> {
public:
  // Default constructor. Constructs a thermal diffusivity with an uninitialized value.
  ThermalDiffusivity() = default;

  // Constructor. Constructs a thermal diffusivity with a given value expressed in a given
  // diffusivity unit.
  ThermalDiffusivity(const Number value, const Unit::Diffusivity unit)
    : DimensionalScalar<Unit::Diffusivity, Number>(value, unit) {}

  // Constructor. Constructs a thermal diffusivity from a given scalar thermal conductivity,
  // specific isobaric heat capacity, and mass density using the definition of the thermal
  // diffusivity.
  constexpr ThermalDiffusivity(
      const ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
      const MassDensity<Number>& mass_density,
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity)
    : ThermalDiffusivity<Number>(
        scalar_thermal_conductivity.Value()
        / (mass_density.Value() * specific_isobaric_heat_capacity.Value())) {}

  // Constructor. Constructs a thermal diffusivity from a given kinematic viscosity and Prandtl
  // number using the definition of the Prandtl number.
  constexpr ThermalDiffusivity(const KinematicViscosity<Number>& kinematic_viscosity,
                               const PrandtlNumber<Number>& prandtl_number);

  // Destructor. Destroys this thermal diffusivity.
  ~ThermalDiffusivity() noexcept = default;

  // Copy constructor. Constructs a thermal diffusivity by copying another one.
  constexpr ThermalDiffusivity(const ThermalDiffusivity<Number>& other) = default;

  // Copy constructor. Constructs a thermal diffusivity by copying another one.
  template <typename OtherNumber>
  explicit constexpr ThermalDiffusivity(const ThermalDiffusivity<OtherNumber>& other)
    : ThermalDiffusivity(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a thermal diffusivity by moving another one.
  constexpr ThermalDiffusivity(ThermalDiffusivity<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this thermal diffusivity by copying another one.
  constexpr ThermalDiffusivity<Number>& operator=(
      const ThermalDiffusivity<Number>& other) = default;

  // Copy assignment operator. Assigns this thermal diffusivity by copying another one.
  template <typename OtherNumber>
  constexpr ThermalDiffusivity<Number>& operator=(const ThermalDiffusivity<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this thermal diffusivity by moving another one.
  constexpr ThermalDiffusivity<Number>& operator=(
      ThermalDiffusivity<Number>&& other) noexcept = default;

  // Statically creates a thermal diffusivity of zero.
  static constexpr ThermalDiffusivity<Number> Zero() {
    return ThermalDiffusivity<Number>{static_cast<Number>(0)};
  }

  // Statically creates a thermal diffusivity with a given value expressed in a given diffusivity
  // unit.
  template <Unit::Diffusivity Unit>
  static constexpr ThermalDiffusivity<Number> Create(const Number value) {
    return ThermalDiffusivity<Number>{
        StaticConvertCopy<Unit::Diffusivity, Unit, Standard<Unit::Diffusivity>>(value)};
  }

  constexpr ThermalDiffusivity<Number> operator+(
      const ThermalDiffusivity<Number>& thermal_diffusivity) const {
    return ThermalDiffusivity<Number>{this->value + thermal_diffusivity.value};
  }

  constexpr ThermalDiffusivity<Number> operator-(
      const ThermalDiffusivity<Number>& thermal_diffusivity) const {
    return ThermalDiffusivity<Number>{this->value - thermal_diffusivity.value};
  }

  constexpr ThermalDiffusivity<Number> operator*(const Number number) const {
    return ThermalDiffusivity<Number>{this->value * number};
  }

  constexpr ThermalDiffusivity<Number> operator/(const Number number) const {
    return ThermalDiffusivity<Number>{this->value / number};
  }

  constexpr Number operator/(const ThermalDiffusivity<Number>& thermal_diffusivity) const noexcept {
    return this->value / thermal_diffusivity.value;
  }

  constexpr void operator+=(const ThermalDiffusivity<Number>& thermal_diffusivity) noexcept {
    this->value += thermal_diffusivity.value;
  }

  constexpr void operator-=(const ThermalDiffusivity<Number>& thermal_diffusivity) noexcept {
    this->value -= thermal_diffusivity.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a thermal diffusivity with a given value expressed in the standard
  // diffusivity unit.
  explicit constexpr ThermalDiffusivity(const Number value)
    : DimensionalScalar<Unit::Diffusivity, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const ThermalDiffusivity<Number>& left, const ThermalDiffusivity<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const ThermalDiffusivity<Number>& left, const ThermalDiffusivity<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const ThermalDiffusivity<Number>& left, const ThermalDiffusivity<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const ThermalDiffusivity<Number>& left, const ThermalDiffusivity<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const ThermalDiffusivity<Number>& left, const ThermalDiffusivity<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const ThermalDiffusivity<Number>& left, const ThermalDiffusivity<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const ThermalDiffusivity<Number>& thermal_diffusivity) {
  stream << thermal_diffusivity.Print();
  return stream;
}

template <typename Number>
inline constexpr ThermalDiffusivity<Number> operator*(
    const Number number, const ThermalDiffusivity<Number>& thermal_diffusivity) {
  return thermal_diffusivity * number;
}

template <typename Number>
inline constexpr ScalarThermalConductivity<Number>::ScalarThermalConductivity(
    const MassDensity<Number>& mass_density,
    const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
    const ThermalDiffusivity<Number>& thermal_diffusivity)
  : ScalarThermalConductivity<Number>(mass_density.Value() * specific_isobaric_heat_capacity.Value()
                                      * thermal_diffusivity.Value()) {}

template <typename Number>
inline constexpr MassDensity<Number>::MassDensity(
    const ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
    const ThermalDiffusivity<Number>& thermal_diffusivity,
    const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity)
  : MassDensity<Number>(scalar_thermal_conductivity.Value()
                        / (thermal_diffusivity.Value() * specific_isobaric_heat_capacity.Value())) {
}

template <typename Number>
inline constexpr SpecificIsobaricHeatCapacity<Number>::SpecificIsobaricHeatCapacity(
    const ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
    const MassDensity<Number>& mass_density, const ThermalDiffusivity<Number>& thermal_diffusivity)
  : SpecificIsobaricHeatCapacity<Number>(
      scalar_thermal_conductivity.Value() / (mass_density.Value() * thermal_diffusivity.Value())) {}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ThermalDiffusivity<Number>> {
  inline size_t operator()(const PhQ::ThermalDiffusivity<Number>& thermal_diffusivity) const {
    return hash<Number>()(thermal_diffusivity.Value());
  }
};

}  // namespace std

#endif  // PHQ_THERMAL_DIFFUSIVITY_HPP
