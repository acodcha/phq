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

#ifndef PHQ_VOLUMETRIC_THERMAL_EXPANSION_COEFFICIENT_HPP
#define PHQ_VOLUMETRIC_THERMAL_EXPANSION_COEFFICIENT_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Strain.hpp"
#include "TemperatureDifference.hpp"
#include "Unit/ThermalExpansion.hpp"

namespace PhQ {

/// \brief Volumetric thermal expansion coefficient. Not to be confused with the linear thermal
/// expansion coefficient. For isotropic materials, the volumetric thermal expansion coefficient is
/// usually three times the linear thermal expansion coefficient.
template <typename Number = double>
class VolumetricThermalExpansionCoefficient
  : public DimensionalScalar<Unit::ThermalExpansion, Number> {
public:
  /// \brief Default constructor. Constructs a volumetric thermal expansion coefficient with an
  /// uninitialized value.
  VolumetricThermalExpansionCoefficient() = default;

  /// \brief Constructor. Constructs a volumetric thermal expansion coefficient with a given value
  /// expressed in a given thermal expansion unit.
  VolumetricThermalExpansionCoefficient(const Number value, const Unit::ThermalExpansion unit)
    : DimensionalScalar<Unit::ThermalExpansion, Number>(value, unit) {}

  /// \brief Destructor. Destroys this volumetric thermal expansion coefficient.
  ~VolumetricThermalExpansionCoefficient() noexcept = default;

  /// \brief Copy constructor. Constructs a volumetric thermal expansion coefficient by copying
  /// another one.
  constexpr VolumetricThermalExpansionCoefficient(
      const VolumetricThermalExpansionCoefficient<Number>& other) = default;

  /// \brief Copy constructor. Constructs a volumetric thermal expansion coefficient by copying
  /// another one.
  template <typename OtherNumber>
  explicit constexpr VolumetricThermalExpansionCoefficient(
      const VolumetricThermalExpansionCoefficient<OtherNumber>& other)
    : VolumetricThermalExpansionCoefficient(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a volumetric thermal expansion coefficient by moving
  /// another one.
  constexpr VolumetricThermalExpansionCoefficient(
      VolumetricThermalExpansionCoefficient<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this volumetric thermal expansion coefficient by
  /// copying another one.
  constexpr VolumetricThermalExpansionCoefficient<Number>& operator=(
      const VolumetricThermalExpansionCoefficient<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this volumetric thermal expansion coefficient by
  /// copying another one.
  template <typename OtherNumber>
  constexpr VolumetricThermalExpansionCoefficient<Number>& operator=(
      const VolumetricThermalExpansionCoefficient<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this volumetric thermal expansion coefficient by
  /// moving another one.
  constexpr VolumetricThermalExpansionCoefficient<Number>& operator=(
      VolumetricThermalExpansionCoefficient<Number>&& other) noexcept = default;

  /// \brief Statically creates a volumetric thermal expansion coefficient of zero.
  static constexpr VolumetricThermalExpansionCoefficient<Number> Zero() {
    return VolumetricThermalExpansionCoefficient<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a volumetric thermal expansion coefficient with a given value
  /// expressed in a given thermal expansion unit.
  template <Unit::ThermalExpansion Unit>
  static constexpr VolumetricThermalExpansionCoefficient<Number> Create(const Number value) {
    return VolumetricThermalExpansionCoefficient<Number>{
        StaticConvertCopy<Unit::ThermalExpansion, Unit, Standard<Unit::ThermalExpansion>>(value)};
  }

  constexpr VolumetricThermalExpansionCoefficient<Number> operator+(
      const VolumetricThermalExpansionCoefficient<Number>& volumetric_thermal_expansion_coefficient)
      const {
    return VolumetricThermalExpansionCoefficient<Number>{
        this->value + volumetric_thermal_expansion_coefficient.value};
  }

  constexpr VolumetricThermalExpansionCoefficient<Number> operator-(
      const VolumetricThermalExpansionCoefficient<Number>& volumetric_thermal_expansion_coefficient)
      const {
    return VolumetricThermalExpansionCoefficient<Number>{
        this->value - volumetric_thermal_expansion_coefficient.value};
  }

  constexpr VolumetricThermalExpansionCoefficient<Number> operator*(const Number number) const {
    return VolumetricThermalExpansionCoefficient<Number>{this->value * number};
  }

  constexpr Strain<Number> operator*(
      const TemperatureDifference<Number>& temperature_difference) const {
    return Strain<Number>{*this, temperature_difference};
  }

  constexpr VolumetricThermalExpansionCoefficient<Number> operator/(const Number number) const {
    return VolumetricThermalExpansionCoefficient<Number>{this->value / number};
  }

  constexpr Number operator/(
      const VolumetricThermalExpansionCoefficient<Number>& volumetric_thermal_expansion_coefficient)
      const noexcept {
    return this->value / volumetric_thermal_expansion_coefficient.value;
  }

  constexpr void operator+=(const VolumetricThermalExpansionCoefficient<Number>&
                                volumetric_thermal_expansion_coefficient) noexcept {
    this->value += volumetric_thermal_expansion_coefficient.value;
  }

  constexpr void operator-=(const VolumetricThermalExpansionCoefficient<Number>&
                                volumetric_thermal_expansion_coefficient) noexcept {
    this->value -= volumetric_thermal_expansion_coefficient.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a volumetric thermal expansion coefficient with a given value
  /// expressed in the standard thermal expansion unit.
  explicit constexpr VolumetricThermalExpansionCoefficient(const Number value)
    : DimensionalScalar<Unit::ThermalExpansion, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const VolumetricThermalExpansionCoefficient<Number>& left,
    const VolumetricThermalExpansionCoefficient<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const VolumetricThermalExpansionCoefficient<Number>& left,
    const VolumetricThermalExpansionCoefficient<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const VolumetricThermalExpansionCoefficient<Number>& left,
    const VolumetricThermalExpansionCoefficient<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const VolumetricThermalExpansionCoefficient<Number>& left,
    const VolumetricThermalExpansionCoefficient<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const VolumetricThermalExpansionCoefficient<Number>& left,
    const VolumetricThermalExpansionCoefficient<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const VolumetricThermalExpansionCoefficient<Number>& left,
    const VolumetricThermalExpansionCoefficient<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream,
    const VolumetricThermalExpansionCoefficient<Number>& volumetric_thermal_expansion_coefficient) {
  stream << volumetric_thermal_expansion_coefficient.Print();
  return stream;
}

template <typename Number>
inline constexpr VolumetricThermalExpansionCoefficient<Number> operator*(
    const Number number,
    const VolumetricThermalExpansionCoefficient<Number>& volumetric_thermal_expansion_coefficient) {
  return volumetric_thermal_expansion_coefficient * number;
}

template <typename Number>
inline constexpr PhQ::Strain<Number>::Strain(
    const VolumetricThermalExpansionCoefficient<Number>& volumetric_thermal_expansion_coefficient,
    const TemperatureDifference<Number>& temperature_difference)
  : Strain<Number>(
      volumetric_thermal_expansion_coefficient.Value() * temperature_difference.Value()
          / static_cast<Number>(3),
      static_cast<Number>(0), static_cast<Number>(0),
      volumetric_thermal_expansion_coefficient.Value() * temperature_difference.Value()
          / static_cast<Number>(3),
      static_cast<Number>(0),
      volumetric_thermal_expansion_coefficient.Value() * temperature_difference.Value()
          / static_cast<Number>(3)) {}

template <typename Number>
inline constexpr Strain<Number> TemperatureDifference<Number>::operator*(
    const VolumetricThermalExpansionCoefficient<Number>& volumetric_thermal_expansion_coefficient)
    const {
  return Strain<Number>{volumetric_thermal_expansion_coefficient, *this};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::VolumetricThermalExpansionCoefficient<Number>> {
  inline size_t operator()(const PhQ::VolumetricThermalExpansionCoefficient<Number>&
                               volumetric_thermal_expansion_coefficient) const {
    return hash<Number>()(volumetric_thermal_expansion_coefficient.Value());
  }
};

}  // namespace std

#endif  // PHQ_VOLUMETRIC_THERMAL_EXPANSION_COEFFICIENT_HPP
