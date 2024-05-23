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

#ifndef PHQ_STRAIN_SCALAR_HPP
#define PHQ_STRAIN_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionlessScalar.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ScalarStrain.
template <typename Number>
class Frequency;

// Forward declaration for class PhQ::ScalarStrain.
template <typename Number>
class LinearThermalExpansionCoefficient;

// Forward declaration for class PhQ::ScalarStrain.
template <typename Number>
class ScalarStrainRate;

// Forward declaration for class PhQ::ScalarStrain.
template <typename Number>
class TemperatureDifference;

// Forward declaration for class PhQ::ScalarStrain.
template <typename Number>
class Time;

/// \brief Scalar component or resultant of a strain tensor. See also PhQ::Strain and
/// PhQ::ScalarStrainRate.
template <typename Number = double>
class ScalarStrain : public DimensionlessScalar<Number> {
public:
  /// \brief Default constructor. Constructs a scalar strain with an uninitialized value.
  ScalarStrain() = default;

  /// \brief Constructor. Constructs a scalar strain with a given value.
  explicit constexpr ScalarStrain(const Number value) : DimensionlessScalar<Number>(value) {}

  /// \brief Constructor. Constructs a scalar strain from a given scalar strain rate and time using
  /// the definition of strain rate.
  constexpr ScalarStrain(
      const ScalarStrainRate<Number>& scalar_strain_rate, const Time<Number>& time);

  /// \brief Constructor. Constructs a scalar strain from a given scalar strain rate and frequency
  /// using the definition of strain rate.
  constexpr ScalarStrain(
      const ScalarStrainRate<Number>& scalar_strain_rate, const Frequency<Number>& frequency);

  /// \brief Constructor. Constructs a scalar strain from a given linear thermal expansion
  /// coefficient and temperature difference using the definition of the linear thermal expansion
  /// coefficient.
  constexpr ScalarStrain(
      const LinearThermalExpansionCoefficient<Number>& linear_thermal_expansion_coefficient,
      const TemperatureDifference<Number>& temperature_difference);

  /// \brief Destructor. Destroys this scalar strain.
  ~ScalarStrain() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar strain by copying another one.
  constexpr ScalarStrain(const ScalarStrain<Number>& other) = default;

  /// \brief Copy constructor. Constructs a scalar strain by copying another one.
  template <typename OtherNumber>
  explicit constexpr ScalarStrain(const ScalarStrain<OtherNumber>& other)
    : ScalarStrain(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar strain by moving another one.
  constexpr ScalarStrain(ScalarStrain<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar strain by copying another one.
  constexpr ScalarStrain<Number>& operator=(const ScalarStrain<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar strain by copying another one.
  template <typename OtherNumber>
  constexpr ScalarStrain<Number>& operator=(const ScalarStrain<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar strain by moving another one.
  constexpr ScalarStrain<Number>& operator=(ScalarStrain<Number>&& other) noexcept = default;

  /// \brief Statically creates a scalar strain of zero.
  static constexpr ScalarStrain<Number> Zero() {
    return ScalarStrain<Number>{static_cast<Number>(0)};
  }

  constexpr ScalarStrain<Number> operator+(const ScalarStrain<Number>& scalar_strain) const {
    return ScalarStrain<Number>{this->value + scalar_strain.value};
  }

  constexpr ScalarStrain<Number> operator-(const ScalarStrain<Number>& scalar_strain) const {
    return ScalarStrain<Number>{this->value - scalar_strain.value};
  }

  constexpr ScalarStrain<Number> operator*(const Number number) const {
    return ScalarStrain<Number>{this->value * number};
  }

  constexpr ScalarStrainRate<Number> operator*(const Frequency<Number>& frequency) const;

  constexpr ScalarStrain<Number> operator/(const Number number) const {
    return ScalarStrain<Number>{this->value / number};
  }

  constexpr ScalarStrainRate<Number> operator/(const Time<Number>& time) const;

  constexpr Number operator/(const ScalarStrain<Number>& scalar_strain) const noexcept {
    return this->value / scalar_strain.value;
  }

  constexpr void operator+=(const ScalarStrain<Number>& scalar_strain) noexcept {
    this->value += scalar_strain.value;
  }

  constexpr void operator-=(const ScalarStrain<Number>& scalar_strain) noexcept {
    this->value -= scalar_strain.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }
};

template <typename Number>
inline constexpr bool operator==(
    const ScalarStrain<Number>& left, const ScalarStrain<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const ScalarStrain<Number>& left, const ScalarStrain<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const ScalarStrain<Number>& left, const ScalarStrain<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const ScalarStrain<Number>& left, const ScalarStrain<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const ScalarStrain<Number>& left, const ScalarStrain<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const ScalarStrain<Number>& left, const ScalarStrain<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const ScalarStrain<Number>& scalar_strain) {
  stream << scalar_strain.Print();
  return stream;
}

template <typename Number>
inline constexpr ScalarStrain<Number> operator*(
    const Number number, const ScalarStrain<Number>& scalar_strain) {
  return ScalarStrain<Number>{number * scalar_strain.Value()};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ScalarStrain<Number>> {
  inline size_t operator()(const PhQ::ScalarStrain<Number>& scalar_strain) const {
    return hash<Number>()(scalar_strain.Value());
  }
};

}  // namespace std

#endif  // PHQ_STRAIN_SCALAR_HPP
