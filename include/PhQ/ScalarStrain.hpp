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

#ifndef PHQ_SCALAR_STRAIN_HPP
#define PHQ_SCALAR_STRAIN_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ScalarStrain.
template <typename NumericType>
class Frequency;

// Forward declaration for class PhQ::ScalarStrain.
template <typename NumericType>
class LinearThermalExpansionCoefficient;

// Forward declaration for class PhQ::ScalarStrain.
template <typename NumericType>
class ScalarStrainRate;

// Forward declaration for class PhQ::ScalarStrain.
template <typename NumericType>
class TemperatureDifference;

// Forward declaration for class PhQ::ScalarStrain.
template <typename NumericType>
class Time;

/// \brief Scalar component or resultant of a three-dimensional Euclidean strain symmetric dyadic
/// tensor. For the related tensor, see PhQ::Strain. For the time rate of change of scalar strain,
/// see PhQ::ScalarStrainRate, PhQ::Time, and PhQ::Frequency.
template <typename NumericType = double>
class ScalarStrain : public DimensionlessScalar<NumericType> {
public:
  /// \brief Default constructor. Constructs a scalar strain with an uninitialized value.
  ScalarStrain() = default;

  /// \brief Constructor. Constructs a scalar strain with a given value.
  explicit constexpr ScalarStrain(const NumericType value)
    : DimensionlessScalar<NumericType>(value) {}

  /// \brief Constructor. Constructs a scalar strain from a given scalar strain rate and time using
  /// the definition of strain rate.
  constexpr ScalarStrain(
      const ScalarStrainRate<NumericType>& scalar_strain_rate, const Time<NumericType>& time);

  /// \brief Constructor. Constructs a scalar strain from a given scalar strain rate and frequency
  /// using the definition of strain rate.
  constexpr ScalarStrain(const ScalarStrainRate<NumericType>& scalar_strain_rate,
                         const Frequency<NumericType>& frequency);

  /// \brief Constructor. Constructs a scalar strain from a given linear thermal expansion
  /// coefficient and temperature difference using the definition of the linear thermal expansion
  /// coefficient.
  constexpr ScalarStrain(
      const LinearThermalExpansionCoefficient<NumericType>& linear_thermal_expansion_coefficient,
      const TemperatureDifference<NumericType>& temperature_difference);

  /// \brief Destructor. Destroys this scalar strain.
  ~ScalarStrain() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar strain by copying another one.
  constexpr ScalarStrain(const ScalarStrain<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a scalar strain by copying another one.
  template <typename OtherNumericType>
  explicit constexpr ScalarStrain(const ScalarStrain<OtherNumericType>& other)
    : ScalarStrain(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar strain by moving another one.
  constexpr ScalarStrain(ScalarStrain<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar strain by copying another one.
  constexpr ScalarStrain<NumericType>& operator=(const ScalarStrain<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar strain by copying another one.
  template <typename OtherNumericType>
  constexpr ScalarStrain<NumericType>& operator=(const ScalarStrain<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar strain by moving another one.
  constexpr ScalarStrain<NumericType>& operator=(
      ScalarStrain<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a scalar strain of zero.
  static constexpr ScalarStrain<NumericType> Zero() {
    return ScalarStrain<NumericType>{static_cast<NumericType>(0)};
  }

  constexpr ScalarStrain<NumericType> operator+(
      const ScalarStrain<NumericType>& scalar_strain) const {
    return ScalarStrain<NumericType>{this->value + scalar_strain.value};
  }

  constexpr ScalarStrain<NumericType> operator-(
      const ScalarStrain<NumericType>& scalar_strain) const {
    return ScalarStrain<NumericType>{this->value - scalar_strain.value};
  }

  constexpr ScalarStrain<NumericType> operator*(const NumericType number) const {
    return ScalarStrain<NumericType>{this->value * number};
  }

  constexpr ScalarStrainRate<NumericType> operator*(const Frequency<NumericType>& frequency) const;

  constexpr ScalarStrain<NumericType> operator/(const NumericType number) const {
    return ScalarStrain<NumericType>{this->value / number};
  }

  constexpr ScalarStrainRate<NumericType> operator/(const Time<NumericType>& time) const;

  constexpr NumericType operator/(const ScalarStrain<NumericType>& scalar_strain) const noexcept {
    return this->value / scalar_strain.value;
  }

  constexpr void operator+=(const ScalarStrain<NumericType>& scalar_strain) noexcept {
    this->value += scalar_strain.value;
  }

  constexpr void operator-=(const ScalarStrain<NumericType>& scalar_strain) noexcept {
    this->value -= scalar_strain.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }
};

template <typename NumericType>
inline constexpr bool operator==(
    const ScalarStrain<NumericType>& left, const ScalarStrain<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const ScalarStrain<NumericType>& left, const ScalarStrain<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const ScalarStrain<NumericType>& left, const ScalarStrain<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const ScalarStrain<NumericType>& left, const ScalarStrain<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const ScalarStrain<NumericType>& left, const ScalarStrain<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const ScalarStrain<NumericType>& left, const ScalarStrain<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const ScalarStrain<NumericType>& scalar_strain) {
  stream << scalar_strain.Print();
  return stream;
}

template <typename NumericType>
inline constexpr ScalarStrain<NumericType> operator*(
    const NumericType number, const ScalarStrain<NumericType>& scalar_strain) {
  return ScalarStrain<NumericType>{number * scalar_strain.Value()};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::ScalarStrain<NumericType>> {
  inline size_t operator()(const PhQ::ScalarStrain<NumericType>& scalar_strain) const {
    return hash<NumericType>()(scalar_strain.Value());
  }
};

}  // namespace std

#endif  // PHQ_SCALAR_STRAIN_HPP
