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

/// \brief Thermal diffusivity of a material. Measures the rate of heat transfer inside a material.
/// Equals the scalar thermal conductivity divided by the mass density and specific isobaric heat
/// capacity; see PhQ::ScalarThermalConductivity, PhQ::MassDensity, and
/// PhQ::SpecificIsobaricHeatCapacity. Also appears in the definition of the Prandtl number; see
/// PhQ::PrandtlNumber and PhQ::KinematicViscosity.
template <typename Number = double>
class ThermalDiffusivity : public DimensionalScalar<Unit::Diffusivity, Number> {
public:
  /// \brief Default constructor. Constructs a thermal diffusivity with an uninitialized value.
  ThermalDiffusivity() = default;

  /// \brief Constructor. Constructs a thermal diffusivity with a given value expressed in a given
  /// diffusivity unit.
  ThermalDiffusivity(const Number value, const Unit::Diffusivity unit)
    : DimensionalScalar<Unit::Diffusivity, Number>(value, unit) {}

  /// \brief Constructor. Constructs a thermal diffusivity from a given scalar thermal conductivity,
  /// specific isobaric heat capacity, and mass density using the definition of the thermal
  /// diffusivity.
  constexpr ThermalDiffusivity(
      const ScalarThermalConductivity<Number>& scalar_thermal_conductivity,
      const MassDensity<Number>& mass_density,
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity)
    : ThermalDiffusivity<Number>(
        scalar_thermal_conductivity.Value()
        / (mass_density.Value() * specific_isobaric_heat_capacity.Value())) {}

  /// \brief Constructor. Constructs a thermal diffusivity from a given kinematic viscosity and
  /// Prandtl number using the definition of the Prandtl number.
  constexpr ThermalDiffusivity(const KinematicViscosity<Number>& kinematic_viscosity,
                               const PrandtlNumber<Number>& prandtl_number);

  /// \brief Destructor. Destroys this thermal diffusivity.
  ~ThermalDiffusivity() noexcept = default;

  /// \brief Copy constructor. Constructs a thermal diffusivity by copying another one.
  constexpr ThermalDiffusivity(const ThermalDiffusivity<Number>& other) = default;

  /// \brief Copy constructor. Constructs a thermal diffusivity by copying another one.
  template <typename OtherNumber>
  explicit constexpr ThermalDiffusivity(const ThermalDiffusivity<OtherNumber>& other)
    : ThermalDiffusivity(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a thermal diffusivity by moving another one.
  constexpr ThermalDiffusivity(ThermalDiffusivity<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this thermal diffusivity by copying another one.
  constexpr ThermalDiffusivity<Number>& operator=(
      const ThermalDiffusivity<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this thermal diffusivity by copying another one.
  template <typename OtherNumber>
  constexpr ThermalDiffusivity<Number>& operator=(const ThermalDiffusivity<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this thermal diffusivity by moving another one.
  constexpr ThermalDiffusivity<Number>& operator=(
      ThermalDiffusivity<Number>&& other) noexcept = default;

  /// \brief Statically creates a thermal diffusivity of zero.
  static constexpr ThermalDiffusivity<Number> Zero() {
    return ThermalDiffusivity<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a thermal diffusivity with a given value expressed in a given
  /// diffusivity unit.
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
  /// \brief Constructor. Constructs a thermal diffusivity with a given value expressed in the
  /// standard diffusivity unit.
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
