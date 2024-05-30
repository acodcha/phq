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

#ifndef PHQ_SCALAR_THERMAL_CONDUCTIVITY_HPP
#define PHQ_SCALAR_THERMAL_CONDUCTIVITY_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/ThermalConductivity.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ScalarThermalConductivity.
template <typename NumericType>
class DynamicViscosity;

// Forward declaration for class PhQ::ScalarThermalConductivity.
template <typename NumericType>
class MassDensity;

// Forward declaration for class PhQ::ScalarThermalConductivity.
template <typename NumericType>
class PrandtlNumber;

// Forward declaration for class PhQ::ScalarThermalConductivity.
template <typename NumericType>
class SpecificIsobaricHeatCapacity;

// Forward declaration for class PhQ::ScalarThermalConductivity.
template <typename NumericType>
class ThermalDiffusivity;

/// \brief Scalar component or resultant of a three-dimensional Euclidean thermal conductivity
/// symmetric dyadic tensor. In general, thermal conductivity is a tensor; however, in isotropic
/// materials, thermal conductivity simplifies to a scalar. For the related tensor, see
/// PhQ::ThermalConductivity.
template <typename NumericType = double>
class ScalarThermalConductivity : public DimensionalScalar<Unit::ThermalConductivity, NumericType> {
public:
  /// \brief Default constructor. Constructs a scalar thermal conductivity with an uninitialized
  /// value.
  ScalarThermalConductivity() = default;

  /// \brief Constructor. Constructs a scalar thermal conductivity with a given value expressed in a
  /// given thermal conductivity unit.
  ScalarThermalConductivity(const NumericType value, const Unit::ThermalConductivity unit)
    : DimensionalScalar<Unit::ThermalConductivity, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a scalar thermal conductivity from a given mass density,
  /// specific isobaric heat capacity, and thermal diffusivity using the definition of thermal
  /// diffusivity.
  constexpr ScalarThermalConductivity(
      const MassDensity<NumericType>& mass_density,
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity,
      const ThermalDiffusivity<NumericType>& thermal_diffusivity);

  /// \brief Constructor. Constructs a scalar thermal conductivity from a given specific isobaric
  /// heat capacity, dynamic viscosity, and Prandtl number using the definition of the Prandtl
  /// number.
  constexpr ScalarThermalConductivity(
      const SpecificIsobaricHeatCapacity<NumericType>& specific_isobaric_heat_capacity,
      const DynamicViscosity<NumericType>& dynamic_viscosity,
      const PrandtlNumber<NumericType>& prandtl_number);

  /// \brief Destructor. Destroys this scalar thermal conductivity.
  ~ScalarThermalConductivity() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar thermal conductivity by copying another one.
  constexpr ScalarThermalConductivity(
      const ScalarThermalConductivity<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a scalar thermal conductivity by copying another one.
  template <typename OtherNumericType>
  explicit constexpr ScalarThermalConductivity(
      const ScalarThermalConductivity<OtherNumericType>& other)
    : ScalarThermalConductivity(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar thermal conductivity by moving another one.
  constexpr ScalarThermalConductivity(
      ScalarThermalConductivity<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar thermal conductivity by copying another
  /// one.
  constexpr ScalarThermalConductivity<NumericType>& operator=(
      const ScalarThermalConductivity<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar thermal conductivity by copying another
  /// one.
  template <typename OtherNumericType>
  constexpr ScalarThermalConductivity<NumericType>& operator=(
      const ScalarThermalConductivity<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar thermal conductivity by moving another
  /// one.
  constexpr ScalarThermalConductivity<NumericType>& operator=(
      ScalarThermalConductivity<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a scalar thermal conductivity of zero.
  static constexpr ScalarThermalConductivity<NumericType> Zero() {
    return ScalarThermalConductivity<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a scalar thermal conductivity with a given value expressed in a
  /// given thermal conductivity unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ScalarThermalConductivity<NumericType> Create(const NumericType value) {
    return ScalarThermalConductivity<NumericType>{
        StaticConvertCopy<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            value)};
  }

  constexpr ScalarThermalConductivity<NumericType> operator+(
      const ScalarThermalConductivity<NumericType>& thermal_conductivity_scalar) const {
    return ScalarThermalConductivity<NumericType>{this->value + thermal_conductivity_scalar.value};
  }

  constexpr ScalarThermalConductivity<NumericType> operator-(
      const ScalarThermalConductivity<NumericType>& thermal_conductivity_scalar) const {
    return ScalarThermalConductivity<NumericType>{this->value - thermal_conductivity_scalar.value};
  }

  constexpr ScalarThermalConductivity<NumericType> operator*(const NumericType number) const {
    return ScalarThermalConductivity<NumericType>{this->value * number};
  }

  constexpr ScalarThermalConductivity<NumericType> operator/(const NumericType number) const {
    return ScalarThermalConductivity<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const ScalarThermalConductivity<NumericType>& thermal_conductivity_scalar) const noexcept {
    return this->value / thermal_conductivity_scalar.value;
  }

  constexpr void operator+=(
      const ScalarThermalConductivity<NumericType>& thermal_conductivity_scalar) noexcept {
    this->value += thermal_conductivity_scalar.value;
  }

  constexpr void operator-=(
      const ScalarThermalConductivity<NumericType>& thermal_conductivity_scalar) noexcept {
    this->value -= thermal_conductivity_scalar.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a scalar thermal conductivity with a given value expressed in
  /// the standard thermal conductivity unit.
  explicit constexpr ScalarThermalConductivity(const NumericType value)
    : DimensionalScalar<Unit::ThermalConductivity, NumericType>(value) {}

  template <typename OtherNumericType>
  friend class ThermalConductivity;
};

template <typename NumericType>
inline constexpr bool operator==(const ScalarThermalConductivity<NumericType>& left,
                                 const ScalarThermalConductivity<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const ScalarThermalConductivity<NumericType>& left,
                                 const ScalarThermalConductivity<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const ScalarThermalConductivity<NumericType>& left,
                                const ScalarThermalConductivity<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const ScalarThermalConductivity<NumericType>& left,
                                const ScalarThermalConductivity<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const ScalarThermalConductivity<NumericType>& left,
                                 const ScalarThermalConductivity<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const ScalarThermalConductivity<NumericType>& left,
                                 const ScalarThermalConductivity<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream,
    const ScalarThermalConductivity<NumericType>& thermal_conductivity_scalar) {
  stream << thermal_conductivity_scalar.Print();
  return stream;
}

template <typename NumericType>
inline constexpr ScalarThermalConductivity<NumericType> operator*(
    const NumericType number,
    const ScalarThermalConductivity<NumericType>& thermal_conductivity_scalar) {
  return thermal_conductivity_scalar * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::ScalarThermalConductivity<NumericType>> {
  inline size_t operator()(
      const PhQ::ScalarThermalConductivity<NumericType>& thermal_conductivity_scalar) const {
    return hash<NumericType>()(thermal_conductivity_scalar.Value());
  }
};

}  // namespace std

#endif  // PHQ_SCALAR_THERMAL_CONDUCTIVITY_HPP
