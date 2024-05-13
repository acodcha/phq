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

#ifndef PHQ_THERMAL_CONDUCTIVITY_SCALAR_HPP
#define PHQ_THERMAL_CONDUCTIVITY_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/ThermalConductivity.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ScalarThermalConductivity.
template <typename Number>
class DynamicViscosity;

// Forward declaration for class PhQ::ScalarThermalConductivity.
template <typename Number>
class MassDensity;

// Forward declaration for class PhQ::ScalarThermalConductivity.
template <typename Number>
class PrandtlNumber;

// Forward declaration for class PhQ::ScalarThermalConductivity.
template <typename Number>
class SpecificIsobaricHeatCapacity;

// Forward declaration for class PhQ::ScalarThermalConductivity.
template <typename Number>
class ThermalDiffusivity;

// Scalar component or resultant of a thermal conductivity tensor. For materials that are isotropic,
// thermal conductivity can be represented by a scalar rather than a dyadic tensor. See also
// PhQ::ThermalConductivity.
template <typename Number = double>
class ScalarThermalConductivity : public DimensionalScalar<Unit::ThermalConductivity, Number> {
public:
  // Default constructor. Constructs a scalar thermal conductivity with an uninitialized value.
  ScalarThermalConductivity() = default;

  // Constructor. Constructs a scalar thermal conductivity with a given value expressed in a given
  // thermal conductivity unit.
  ScalarThermalConductivity(const Number value, const Unit::ThermalConductivity unit)
    : DimensionalScalar<Unit::ThermalConductivity, Number>(value, unit) {}

  // Constructor. Constructs a scalar thermal conductivity from a given mass density, specific
  // isobaric heat capacity, and thermal diffusivity using the definition of thermal diffusivity.
  constexpr ScalarThermalConductivity(
      const MassDensity<Number>& mass_density,
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
      const ThermalDiffusivity<Number>& thermal_diffusivity);

  // Constructor. Constructs a scalar thermal conductivity from a given specific isobaric heat
  // capacity, dynamic viscosity, and Prandtl number using the definition of the Prandtl number.
  constexpr ScalarThermalConductivity(
      const SpecificIsobaricHeatCapacity<Number>& specific_isobaric_heat_capacity,
      const DynamicViscosity<Number>& dynamic_viscosity,
      const PrandtlNumber<Number>& prandtl_number);

  // Destructor. Destroys this scalar thermal conductivity.
  ~ScalarThermalConductivity() noexcept = default;

  // Copy constructor. Constructs a scalar thermal conductivity by copying another one.
  constexpr ScalarThermalConductivity(const ScalarThermalConductivity<Number>& other) = default;

  // Copy constructor. Constructs a scalar thermal conductivity by copying another one.
  template <typename OtherNumber>
  explicit constexpr ScalarThermalConductivity(const ScalarThermalConductivity<OtherNumber>& other)
    : ScalarThermalConductivity(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a scalar thermal conductivity by moving another one.
  constexpr ScalarThermalConductivity(ScalarThermalConductivity<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar thermal conductivity by copying another one.
  constexpr ScalarThermalConductivity<Number>& operator=(
      const ScalarThermalConductivity<Number>& other) = default;

  // Copy assignment operator. Assigns this scalar thermal conductivity by copying another one.
  template <typename OtherNumber>
  constexpr ScalarThermalConductivity<Number>& operator=(
      const ScalarThermalConductivity<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this scalar thermal conductivity by moving another one.
  constexpr ScalarThermalConductivity<Number>& operator=(
      ScalarThermalConductivity<Number>&& other) noexcept = default;

  // Statically creates a scalar thermal conductivity of zero.
  static constexpr ScalarThermalConductivity<Number> Zero() {
    return ScalarThermalConductivity<Number>{static_cast<Number>(0)};
  }

  // Statically creates a scalar thermal conductivity with a given value expressed in a given
  // thermal conductivity unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ScalarThermalConductivity<Number> Create(const Number value) {
    return ScalarThermalConductivity<Number>{
        StaticConvertCopy<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            value)};
  }

  constexpr ScalarThermalConductivity<Number> operator+(
      const ScalarThermalConductivity<Number>& thermal_conductivity_scalar) const {
    return ScalarThermalConductivity<Number>{this->value + thermal_conductivity_scalar.value};
  }

  constexpr ScalarThermalConductivity<Number> operator-(
      const ScalarThermalConductivity<Number>& thermal_conductivity_scalar) const {
    return ScalarThermalConductivity<Number>{this->value - thermal_conductivity_scalar.value};
  }

  constexpr ScalarThermalConductivity<Number> operator*(const Number number) const {
    return ScalarThermalConductivity<Number>{this->value * number};
  }

  constexpr ScalarThermalConductivity<Number> operator/(const Number number) const {
    return ScalarThermalConductivity<Number>{this->value / number};
  }

  constexpr Number operator/(
      const ScalarThermalConductivity<Number>& thermal_conductivity_scalar) const noexcept {
    return this->value / thermal_conductivity_scalar.value;
  }

  constexpr void operator+=(
      const ScalarThermalConductivity<Number>& thermal_conductivity_scalar) noexcept {
    this->value += thermal_conductivity_scalar.value;
  }

  constexpr void operator-=(
      const ScalarThermalConductivity<Number>& thermal_conductivity_scalar) noexcept {
    this->value -= thermal_conductivity_scalar.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a scalar thermal conductivity with a given value expressed in the
  // standard thermal conductivity unit.
  explicit constexpr ScalarThermalConductivity(const Number value)
    : DimensionalScalar<Unit::ThermalConductivity, Number>(value) {}

  template <typename OtherNumber>
  friend class ThermalConductivity;
};

template <typename Number>
inline constexpr bool operator==(const ScalarThermalConductivity<Number>& left,
                                 const ScalarThermalConductivity<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const ScalarThermalConductivity<Number>& left,
                                 const ScalarThermalConductivity<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const ScalarThermalConductivity<Number>& left,
                                const ScalarThermalConductivity<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const ScalarThermalConductivity<Number>& left,
                                const ScalarThermalConductivity<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const ScalarThermalConductivity<Number>& left,
                                 const ScalarThermalConductivity<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const ScalarThermalConductivity<Number>& left,
                                 const ScalarThermalConductivity<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const ScalarThermalConductivity<Number>& thermal_conductivity_scalar) {
  stream << thermal_conductivity_scalar.Print();
  return stream;
}

template <typename Number>
inline constexpr ScalarThermalConductivity<Number> operator*(
    const Number number, const ScalarThermalConductivity<Number>& thermal_conductivity_scalar) {
  return thermal_conductivity_scalar * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ScalarThermalConductivity<Number>> {
  inline size_t operator()(
      const PhQ::ScalarThermalConductivity<Number>& thermal_conductivity_scalar) const {
    return hash<Number>()(thermal_conductivity_scalar.Value());
  }
};

}  // namespace std

#endif  // PHQ_THERMAL_CONDUCTIVITY_SCALAR_HPP
