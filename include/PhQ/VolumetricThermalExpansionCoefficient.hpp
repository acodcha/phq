// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef PHQ_VOLUMETRIC_THERMAL_EXPANSION_COEFFICIENT_HPP
#define PHQ_VOLUMETRIC_THERMAL_EXPANSION_COEFFICIENT_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Strain.hpp"
#include "TemperatureDifference.hpp"
#include "Unit/ReciprocalTemperature.hpp"

namespace PhQ {

/// \brief Volumetric thermal expansion coefficient. Not to be confused with the linear thermal
/// expansion coefficient; see PhQ::LinearThermalExpansionCoefficient. For isotropic materials, the
/// volumetric thermal expansion coefficient is usually three times the linear thermal expansion
/// coefficient.
template <typename NumericType = double>
class VolumetricThermalExpansionCoefficient
  : public DimensionalScalar<Unit::ReciprocalTemperature, NumericType> {
public:
  /// \brief Default constructor. Constructs a volumetric thermal expansion coefficient with an
  /// uninitialized value.
  VolumetricThermalExpansionCoefficient() = default;

  /// \brief Constructor. Constructs a volumetric thermal expansion coefficient with a given value
  /// expressed in a given thermal expansion unit.
  VolumetricThermalExpansionCoefficient(
      const NumericType value, const Unit::ReciprocalTemperature unit)
    : DimensionalScalar<Unit::ReciprocalTemperature, NumericType>(value, unit) {}

  /// \brief Destructor. Destroys this volumetric thermal expansion coefficient.
  ~VolumetricThermalExpansionCoefficient() noexcept = default;

  /// \brief Copy constructor. Constructs a volumetric thermal expansion coefficient by copying
  /// another one.
  constexpr VolumetricThermalExpansionCoefficient(
      const VolumetricThermalExpansionCoefficient<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a volumetric thermal expansion coefficient by copying
  /// another one.
  template <typename OtherNumericType>
  explicit constexpr VolumetricThermalExpansionCoefficient(
      const VolumetricThermalExpansionCoefficient<OtherNumericType>& other)
    : VolumetricThermalExpansionCoefficient(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a volumetric thermal expansion coefficient by moving
  /// another one.
  constexpr VolumetricThermalExpansionCoefficient(
      VolumetricThermalExpansionCoefficient<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this volumetric thermal expansion coefficient by
  /// copying another one.
  constexpr VolumetricThermalExpansionCoefficient<NumericType>& operator=(
      const VolumetricThermalExpansionCoefficient<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this volumetric thermal expansion coefficient by
  /// copying another one.
  template <typename OtherNumericType>
  constexpr VolumetricThermalExpansionCoefficient<NumericType>& operator=(
      const VolumetricThermalExpansionCoefficient<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this volumetric thermal expansion coefficient by
  /// moving another one.
  constexpr VolumetricThermalExpansionCoefficient<NumericType>& operator=(
      VolumetricThermalExpansionCoefficient<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a volumetric thermal expansion coefficient of zero.
  [[nodiscard]] static constexpr VolumetricThermalExpansionCoefficient<NumericType> Zero() {
    return VolumetricThermalExpansionCoefficient<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a volumetric thermal expansion coefficient with a given value
  /// expressed in a given thermal expansion unit.
  template <Unit::ReciprocalTemperature Unit>
  [[nodiscard]] static constexpr VolumetricThermalExpansionCoefficient<NumericType> Create(
      const NumericType value) {
    return VolumetricThermalExpansionCoefficient<NumericType>{
        ConvertStatically<Unit::ReciprocalTemperature, Unit, Standard<Unit::ReciprocalTemperature>>(
            value)};
  }

  constexpr VolumetricThermalExpansionCoefficient<NumericType> operator+(
      const VolumetricThermalExpansionCoefficient<NumericType>&
          volumetric_thermal_expansion_coefficient) const {
    return VolumetricThermalExpansionCoefficient<NumericType>{
        this->value + volumetric_thermal_expansion_coefficient.value};
  }

  constexpr VolumetricThermalExpansionCoefficient<NumericType> operator-(
      const VolumetricThermalExpansionCoefficient<NumericType>&
          volumetric_thermal_expansion_coefficient) const {
    return VolumetricThermalExpansionCoefficient<NumericType>{
        this->value - volumetric_thermal_expansion_coefficient.value};
  }

  constexpr VolumetricThermalExpansionCoefficient<NumericType> operator*(
      const NumericType number) const {
    return VolumetricThermalExpansionCoefficient<NumericType>{this->value * number};
  }

  constexpr Strain<NumericType> operator*(
      const TemperatureDifference<NumericType>& temperature_difference) const {
    return Strain<NumericType>{*this, temperature_difference};
  }

  constexpr VolumetricThermalExpansionCoefficient<NumericType> operator/(
      const NumericType number) const {
    return VolumetricThermalExpansionCoefficient<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(const VolumetricThermalExpansionCoefficient<NumericType>&
                                      volumetric_thermal_expansion_coefficient) const noexcept {
    return this->value / volumetric_thermal_expansion_coefficient.value;
  }

  constexpr void operator+=(const VolumetricThermalExpansionCoefficient<NumericType>&
                                volumetric_thermal_expansion_coefficient) noexcept {
    this->value += volumetric_thermal_expansion_coefficient.value;
  }

  constexpr void operator-=(const VolumetricThermalExpansionCoefficient<NumericType>&
                                volumetric_thermal_expansion_coefficient) noexcept {
    this->value -= volumetric_thermal_expansion_coefficient.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a volumetric thermal expansion coefficient with a given value
  /// expressed in the standard thermal expansion unit.
  explicit constexpr VolumetricThermalExpansionCoefficient(const NumericType value)
    : DimensionalScalar<Unit::ReciprocalTemperature, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const VolumetricThermalExpansionCoefficient<NumericType>& left,
    const VolumetricThermalExpansionCoefficient<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const VolumetricThermalExpansionCoefficient<NumericType>& left,
    const VolumetricThermalExpansionCoefficient<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const VolumetricThermalExpansionCoefficient<NumericType>& left,
    const VolumetricThermalExpansionCoefficient<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const VolumetricThermalExpansionCoefficient<NumericType>& left,
    const VolumetricThermalExpansionCoefficient<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const VolumetricThermalExpansionCoefficient<NumericType>& left,
    const VolumetricThermalExpansionCoefficient<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const VolumetricThermalExpansionCoefficient<NumericType>& left,
    const VolumetricThermalExpansionCoefficient<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const VolumetricThermalExpansionCoefficient<NumericType>&
                              volumetric_thermal_expansion_coefficient) {
  stream << volumetric_thermal_expansion_coefficient.Print();
  return stream;
}

template <typename NumericType>
inline constexpr VolumetricThermalExpansionCoefficient<NumericType> operator*(
    const NumericType number, const VolumetricThermalExpansionCoefficient<NumericType>&
                                  volumetric_thermal_expansion_coefficient) {
  return volumetric_thermal_expansion_coefficient * number;
}

template <typename NumericType>
inline constexpr PhQ::Strain<NumericType>::Strain(
    const VolumetricThermalExpansionCoefficient<NumericType>&
        volumetric_thermal_expansion_coefficient,
    const TemperatureDifference<NumericType>& temperature_difference)
  : Strain<NumericType>(
      volumetric_thermal_expansion_coefficient.Value() * temperature_difference.Value()
          / static_cast<NumericType>(3),
      static_cast<NumericType>(0), static_cast<NumericType>(0),
      volumetric_thermal_expansion_coefficient.Value() * temperature_difference.Value()
          / static_cast<NumericType>(3),
      static_cast<NumericType>(0),
      volumetric_thermal_expansion_coefficient.Value() * temperature_difference.Value()
          / static_cast<NumericType>(3)) {}

template <typename NumericType>
inline constexpr Strain<NumericType> TemperatureDifference<NumericType>::operator*(
    const VolumetricThermalExpansionCoefficient<NumericType>&
        volumetric_thermal_expansion_coefficient) const {
  return Strain<NumericType>{volumetric_thermal_expansion_coefficient, *this};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::VolumetricThermalExpansionCoefficient<NumericType>> {
  inline size_t operator()(const PhQ::VolumetricThermalExpansionCoefficient<NumericType>&
                               volumetric_thermal_expansion_coefficient) const {
    return hash<NumericType>()(volumetric_thermal_expansion_coefficient.Value());
  }
};

}  // namespace std

#endif  // PHQ_VOLUMETRIC_THERMAL_EXPANSION_COEFFICIENT_HPP
