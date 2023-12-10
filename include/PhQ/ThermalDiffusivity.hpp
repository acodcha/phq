// Copyright 2020-2023 Alexandre Coderre-Chabot
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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMAL_DIFFUSIVITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMAL_DIFFUSIVITY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "MassDensity.hpp"
#include "ScalarThermalConductivity.hpp"
#include "SpecificIsobaricHeatCapacity.hpp"
#include "Unit/Diffusivity.hpp"

namespace PhQ {

// Forward declaration for class ThermalDiffusivity.
class PrandtlNumber;

// Thermal diffusivity.
class ThermalDiffusivity : public DimensionalScalar<Unit::Diffusivity> {
public:
  // Default constructor. Constructs a thermal diffusivity with an uninitialized value.
  ThermalDiffusivity() = default;

  // Constructor. Constructs a thermal diffusivity with a given value expressed in a given
  // diffusivity unit.
  ThermalDiffusivity(const double value, const Unit::Diffusivity unit)
    : DimensionalScalar<Unit::Diffusivity>(value, unit) {}

  // Constructor. Constructs a thermal diffusivity from a given scalar thermal conductivity,
  // specific isobaric heat capacity, and mass density using the definition of the thermal
  // diffusivity.
  constexpr ThermalDiffusivity(
      const ScalarThermalConductivity& scalar_thermal_conductivity, const MassDensity& mass_density,
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity)
    : ThermalDiffusivity(scalar_thermal_conductivity.Value()
                         / (mass_density.Value() * specific_isobaric_heat_capacity.Value())) {}

  // Constructor. Constructs a thermal diffusivity from a given kinematic viscosity and Prandtl
  // number using the definition of the Prandtl number.
  constexpr ThermalDiffusivity(
      const KinematicViscosity& kinematic_viscosity, const PrandtlNumber& prandtl_number);

  // Destructor. Destroys this thermal diffusivity.
  ~ThermalDiffusivity() noexcept = default;

  // Copy constructor. Constructs a thermal diffusivity by copying another one.
  constexpr ThermalDiffusivity(const ThermalDiffusivity& other) = default;

  // Move constructor. Constructs a thermal diffusivity by moving another one.
  constexpr ThermalDiffusivity(ThermalDiffusivity&& other) noexcept = default;

  // Copy assignment operator. Assigns this thermal diffusivity by copying another one.
  constexpr ThermalDiffusivity& operator=(const ThermalDiffusivity& other) = default;

  // Move assignment operator. Assigns this thermal diffusivity by moving another one.
  constexpr ThermalDiffusivity& operator=(ThermalDiffusivity&& other) noexcept = default;

  // Statically creates a thermal diffusivity of zero.
  static constexpr ThermalDiffusivity Zero() {
    return ThermalDiffusivity{0.0};
  }

  // Statically creates a thermal diffusivity with a given value expressed in a given diffusivity
  // unit.
  template <Unit::Diffusivity Unit>
  static constexpr ThermalDiffusivity Create(const double value) {
    return ThermalDiffusivity{
        StaticConvertCopy<Unit::Diffusivity, Unit, Standard<Unit::Diffusivity>>(value)};
  }

  constexpr ThermalDiffusivity operator+(const ThermalDiffusivity& thermal_diffusivity) const {
    return ThermalDiffusivity{value_ + thermal_diffusivity.value_};
  }

  constexpr ThermalDiffusivity operator-(const ThermalDiffusivity& thermal_diffusivity) const {
    return ThermalDiffusivity{value_ - thermal_diffusivity.value_};
  }

  constexpr ThermalDiffusivity operator*(const double number) const {
    return ThermalDiffusivity{value_ * number};
  }

  constexpr ThermalDiffusivity operator/(const double number) const {
    return ThermalDiffusivity{value_ / number};
  }

  constexpr double operator/(const ThermalDiffusivity& thermal_diffusivity) const noexcept {
    return value_ / thermal_diffusivity.value_;
  }

  constexpr void operator+=(const ThermalDiffusivity& thermal_diffusivity) noexcept {
    value_ += thermal_diffusivity.value_;
  }

  constexpr void operator-=(const ThermalDiffusivity& thermal_diffusivity) noexcept {
    value_ -= thermal_diffusivity.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a thermal diffusivity with a given value expressed in the standard
  // diffusivity unit.
  explicit constexpr ThermalDiffusivity(const double value)
    : DimensionalScalar<Unit::Diffusivity>(value) {}
};

inline constexpr bool operator==(
    const ThermalDiffusivity& left, const ThermalDiffusivity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const ThermalDiffusivity& left, const ThermalDiffusivity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const ThermalDiffusivity& left, const ThermalDiffusivity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const ThermalDiffusivity& left, const ThermalDiffusivity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const ThermalDiffusivity& left, const ThermalDiffusivity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const ThermalDiffusivity& left, const ThermalDiffusivity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const ThermalDiffusivity& thermal_diffusivity) {
  stream << thermal_diffusivity.Print();
  return stream;
}

inline constexpr ThermalDiffusivity operator*(
    const double number, const ThermalDiffusivity& thermal_diffusivity) {
  return thermal_diffusivity * number;
}

inline constexpr ScalarThermalConductivity::ScalarThermalConductivity(
    const MassDensity& mass_density,
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
    const ThermalDiffusivity& thermal_diffusivity)
  : ScalarThermalConductivity(mass_density.Value() * specific_isobaric_heat_capacity.Value()
                              * thermal_diffusivity.Value()) {}

inline constexpr MassDensity::MassDensity(
    const ScalarThermalConductivity& scalar_thermal_conductivity,
    const ThermalDiffusivity& thermal_diffusivity,
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity)
  : MassDensity(scalar_thermal_conductivity.Value()
                / (thermal_diffusivity.Value() * specific_isobaric_heat_capacity.Value())) {}

inline constexpr SpecificIsobaricHeatCapacity::SpecificIsobaricHeatCapacity(
    const ScalarThermalConductivity& scalar_thermal_conductivity, const MassDensity& mass_density,
    const ThermalDiffusivity& thermal_diffusivity)
  : SpecificIsobaricHeatCapacity(
      scalar_thermal_conductivity.Value() / (mass_density.Value() * thermal_diffusivity.Value())) {}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ThermalDiffusivity> {
  inline size_t operator()(const PhQ::ThermalDiffusivity& thermal_diffusivity) const {
    return hash<double>()(thermal_diffusivity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMAL_DIFFUSIVITY_HPP
