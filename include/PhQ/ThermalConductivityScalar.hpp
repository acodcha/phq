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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMAL_CONDUCTIVITY_SCALAR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMAL_CONDUCTIVITY_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/ThermalConductivity.hpp"

namespace PhQ {

// Forward declarations for class ThermalConductivityScalar.
class DynamicViscosity;
class MassDensity;
class PrandtlNumber;
class SpecificIsobaricHeatCapacity;
class ThermalDiffusivity;

// Thermal conductivity scalar. For materials that are isotropic, thermal conductivity can be
// represented by a scalar rather than a dyadic tensor.
class ThermalConductivityScalar : public DimensionalScalar<Unit::ThermalConductivity> {
public:
  // Default constructor. Constructs a thermal conductivity scalar with an uninitialized value.
  ThermalConductivityScalar() = default;

  // Constructor. Constructs a thermal conductivity scalar with a given value expressed in a given
  // thermal conductivity unit.
  ThermalConductivityScalar(const double value, const Unit::ThermalConductivity unit)
    : DimensionalScalar<Unit::ThermalConductivity>(value, unit) {}

  // Constructor. Constructs a thermal conductivity scalar from a given mass density, specific
  // isobaric heat capacity, and thermal diffusivity using the definition of thermal diffusivity.
  constexpr ThermalConductivityScalar(
      const MassDensity& mass_density,
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const ThermalDiffusivity& thermal_diffusivity);

  // Constructor. Constructs a thermal conductivity scalar from a given specific isobaric heat
  // capacity, dynamic viscosity, and Prandtl number using the definition of the Prandtl number.
  constexpr ThermalConductivityScalar(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const DynamicViscosity& dynamic_viscosity, const PrandtlNumber& prandtl_number);

  // Destructor. Destroys this thermal conductivity scalar.
  ~ThermalConductivityScalar() noexcept = default;

  // Copy constructor. Constructs a thermal conductivity scalar by copying another one.
  constexpr ThermalConductivityScalar(const ThermalConductivityScalar& other) = default;

  // Move constructor. Constructs a thermal conductivity scalar by moving another one.
  constexpr ThermalConductivityScalar(ThermalConductivityScalar&& other) noexcept = default;

  // Copy assignment operator. Assigns this thermal conductivity scalar by copying another one.
  constexpr ThermalConductivityScalar& operator=(const ThermalConductivityScalar& other) = default;

  // Move assignment operator. Assigns this thermal conductivity scalar by moving another one.
  constexpr ThermalConductivityScalar& operator=(
      ThermalConductivityScalar&& other) noexcept = default;

  // Statically creates a thermal conductivity scalar of zero.
  static constexpr ThermalConductivityScalar Zero() {
    return ThermalConductivityScalar{0.0};
  }

  // Statically creates a thermal conductivity scalar with a given value expressed in a given
  // thermal conductivity unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivityScalar Create(const double value) {
    return ThermalConductivityScalar{
        StaticConvertCopy<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            value)};
  }

  constexpr ThermalConductivityScalar operator+(
      const ThermalConductivityScalar& thermal_conductivity_scalar) const {
    return ThermalConductivityScalar{value_ + thermal_conductivity_scalar.value_};
  }

  constexpr ThermalConductivityScalar operator-(
      const ThermalConductivityScalar& thermal_conductivity_scalar) const {
    return ThermalConductivityScalar{value_ - thermal_conductivity_scalar.value_};
  }

  constexpr ThermalConductivityScalar operator*(const double number) const {
    return ThermalConductivityScalar{value_ * number};
  }

  constexpr ThermalConductivityScalar operator/(const double number) const {
    return ThermalConductivityScalar{value_ / number};
  }

  constexpr double operator/(
      const ThermalConductivityScalar& thermal_conductivity_scalar) const noexcept {
    return value_ / thermal_conductivity_scalar.value_;
  }

  constexpr void operator+=(const ThermalConductivityScalar& thermal_conductivity_scalar) noexcept {
    value_ += thermal_conductivity_scalar.value_;
  }

  constexpr void operator-=(const ThermalConductivityScalar& thermal_conductivity_scalar) noexcept {
    value_ -= thermal_conductivity_scalar.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a thermal conductivity scalar with a given value expressed in the
  // standard thermal conductivity unit.
  explicit constexpr ThermalConductivityScalar(const double value)
    : DimensionalScalar<Unit::ThermalConductivity>(value) {}

  friend class ThermalConductivity;
};

inline constexpr bool operator==(
    const ThermalConductivityScalar& left, const ThermalConductivityScalar& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const ThermalConductivityScalar& left, const ThermalConductivityScalar& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const ThermalConductivityScalar& left, const ThermalConductivityScalar& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const ThermalConductivityScalar& left, const ThermalConductivityScalar& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const ThermalConductivityScalar& left, const ThermalConductivityScalar& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const ThermalConductivityScalar& left, const ThermalConductivityScalar& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const ThermalConductivityScalar& thermal_conductivity_scalar) {
  stream << thermal_conductivity_scalar.Print();
  return stream;
}

inline constexpr ThermalConductivityScalar operator*(
    const double number, const ThermalConductivityScalar& thermal_conductivity_scalar) {
  return thermal_conductivity_scalar * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ThermalConductivityScalar> {
  inline size_t operator()(
      const PhQ::ThermalConductivityScalar& thermal_conductivity_scalar) const {
    return hash<double>()(thermal_conductivity_scalar.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMAL_CONDUCTIVITY_SCALAR_HPP
