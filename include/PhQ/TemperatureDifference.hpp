// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
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

#ifndef PHQ_TEMPERATURE_DIFFERENCE_HPP
#define PHQ_TEMPERATURE_DIFFERENCE_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/TemperatureDifference.hpp"

namespace PhQ {

// Forward declaration for class PhQ::TemperatureDifference.
template <typename NumericType>
class Length;

// Forward declaration for class PhQ::TemperatureDifference.
template <typename NumericType>
class LinearThermalExpansionCoefficient;

// Forward declaration for class PhQ::TemperatureDifference.
template <typename NumericType>
class ScalarStrain;

// Forward declaration for class PhQ::TemperatureDifference.
template <typename NumericType>
class ScalarTemperatureGradient;

// Forward declaration for class PhQ::TemperatureDifference.
template <typename NumericType>
class Strain;

// Forward declaration for class PhQ::TemperatureDifference.
template <typename NumericType>
class Temperature;

// Forward declaration for class PhQ::TemperatureDifference.
template <typename NumericType>
class VolumetricThermalExpansionCoefficient;

/// \brief Temperature difference. Not to be confused with temperature; see PhQ::Temperature. For
/// example, a temperature difference of 20 kelvin is very different from a temperature of 20
/// kelvin.
template <typename NumericType = double>
class TemperatureDifference : public DimensionalScalar<Unit::TemperatureDifference, NumericType> {
public:
  /// \brief Default constructor. Constructs a temperature difference with an uninitialized value.
  TemperatureDifference() = default;

  /// \brief Constructor. Constructs a temperature difference with a given value expressed in a
  /// given temperature unit.
  TemperatureDifference(const NumericType value, const Unit::TemperatureDifference unit)
    : DimensionalScalar<Unit::TemperatureDifference, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a temperature difference from a given scalar temperature
  /// gradient and length using the definition of temperature gradient.
  constexpr TemperatureDifference(
      const ScalarTemperatureGradient<NumericType>& scalar_temperature_gradient,
      const Length<NumericType>& length);

  /// \brief Destructor. Destroys this temperature difference.
  ~TemperatureDifference() noexcept = default;

  /// \brief Copy constructor. Constructs a temperature difference by copying another one.
  constexpr TemperatureDifference(const TemperatureDifference<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a temperature difference by copying another one.
  template <typename OtherNumericType>
  explicit constexpr TemperatureDifference(const TemperatureDifference<OtherNumericType>& other)
    : TemperatureDifference(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a temperature difference by moving another one.
  constexpr TemperatureDifference(TemperatureDifference<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this temperature difference by copying another one.
  constexpr TemperatureDifference<NumericType>& operator=(
      const TemperatureDifference<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this temperature difference by copying another one.
  template <typename OtherNumericType>
  constexpr TemperatureDifference<NumericType>& operator=(
      const TemperatureDifference<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this temperature difference by moving another one.
  constexpr TemperatureDifference<NumericType>& operator=(
      TemperatureDifference<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a temperature difference of absolute zero.
  static constexpr TemperatureDifference<NumericType> Zero() {
    return TemperatureDifference<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a temperature difference with a given value expressed in a given
  /// temperature unit.
  template <Unit::TemperatureDifference Unit>
  static constexpr TemperatureDifference<NumericType> Create(const NumericType value) {
    return TemperatureDifference<NumericType>{
        ConvertStatically<Unit::TemperatureDifference, Unit, Standard<Unit::TemperatureDifference>>(
            value)};
  }

  constexpr Temperature<NumericType> operator+(const Temperature<NumericType>& temperature) const;

  constexpr TemperatureDifference<NumericType> operator+(
      const TemperatureDifference<NumericType>& temperature_difference) const {
    return TemperatureDifference<NumericType>{this->value + temperature_difference.value};
  }

  constexpr Temperature<NumericType> operator-(const Temperature<NumericType>& temperature) const;

  constexpr TemperatureDifference<NumericType> operator-(
      const TemperatureDifference<NumericType>& temperature_difference) const {
    return TemperatureDifference<NumericType>{this->value - temperature_difference.value};
  }

  constexpr TemperatureDifference<NumericType> operator*(const NumericType number) const {
    return TemperatureDifference<NumericType>{this->value * number};
  }

  constexpr ScalarStrain<NumericType> operator*(
      const LinearThermalExpansionCoefficient<NumericType>& linear_thermal_expansion_coefficient)
      const;

  constexpr Strain<NumericType> operator*(const VolumetricThermalExpansionCoefficient<NumericType>&
                                              volumetric_thermal_expansion_coefficient) const;

  constexpr TemperatureDifference<NumericType> operator/(const NumericType number) const {
    return TemperatureDifference<NumericType>{this->value / number};
  }

  constexpr ScalarTemperatureGradient<NumericType> operator/(
      const Length<NumericType>& length) const;

  constexpr NumericType operator/(
      const TemperatureDifference<NumericType>& temperature_difference) const noexcept {
    return this->value / temperature_difference.value;
  }

  constexpr void operator+=(
      const TemperatureDifference<NumericType>& temperature_difference) noexcept {
    this->value += temperature_difference.value;
  }

  constexpr void operator-=(
      const TemperatureDifference<NumericType>& temperature_difference) noexcept {
    this->value -= temperature_difference.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a temperature difference with a given value expressed in the
  /// standard temperature difference unit.
  explicit constexpr TemperatureDifference(const NumericType value)
    : DimensionalScalar<Unit::TemperatureDifference, NumericType>(value) {}

  template <typename OtherNumericType>
  friend class Temperature;
};

template <typename NumericType>
inline constexpr bool operator==(const TemperatureDifference<NumericType>& left,
                                 const TemperatureDifference<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const TemperatureDifference<NumericType>& left,
                                 const TemperatureDifference<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const TemperatureDifference<NumericType>& left,
                                const TemperatureDifference<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const TemperatureDifference<NumericType>& left,
                                const TemperatureDifference<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const TemperatureDifference<NumericType>& left,
                                 const TemperatureDifference<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const TemperatureDifference<NumericType>& left,
                                 const TemperatureDifference<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const TemperatureDifference<NumericType>& temperature_difference) {
  stream << temperature_difference.Print();
  return stream;
}

template <typename NumericType>
inline constexpr TemperatureDifference<NumericType> operator*(
    const NumericType number, const TemperatureDifference<NumericType>& temperature_difference) {
  return temperature_difference * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::TemperatureDifference<NumericType>> {
  inline size_t operator()(
      const PhQ::TemperatureDifference<NumericType>& temperature_difference) const {
    return hash<NumericType>()(temperature_difference.Value());
  }
};

}  // namespace std

#endif  // PHQ_TEMPERATURE_DIFFERENCE_HPP
