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

// Scalar component or resultant of a strain tensor. See also PhQ::Strain and PhQ::ScalarStrainRate.
template <typename Number = double>
class ScalarStrain : public DimensionlessScalar<Number> {
public:
  // Default constructor. Constructs a scalar strain with an uninitialized value.
  ScalarStrain() = default;

  // Constructor. Constructs a scalar strain with a given value.
  explicit constexpr ScalarStrain(const Number value) : DimensionlessScalar<Number>(value) {}

  // Constructor. Constructs a scalar strain from a given scalar strain rate and time using the
  // definition of strain rate.
  constexpr ScalarStrain(
      const ScalarStrainRate<Number>& scalar_strain_rate, const Time<Number>& time);

  // Constructor. Constructs a scalar strain from a given scalar strain rate and frequency using the
  // definition of strain rate.
  constexpr ScalarStrain(
      const ScalarStrainRate<Number>& scalar_strain_rate, const Frequency<Number>& frequency);

  // Constructor. Constructs a scalar strain from a given linear thermal expansion coefficient and
  // temperature difference using the definition of the linear thermal expansion coefficient.
  constexpr ScalarStrain(
      const LinearThermalExpansionCoefficient<Number>& linear_thermal_expansion_coefficient,
      const TemperatureDifference<Number>& temperature_difference);

  // Destructor. Destroys this scalar strain.
  ~ScalarStrain() noexcept = default;

  // Copy constructor. Constructs a scalar strain by copying another one.
  constexpr ScalarStrain(const ScalarStrain<Number>& other) = default;

  // Copy constructor. Constructs a scalar strain by copying another one.
  template <typename OtherNumber>
  explicit constexpr ScalarStrain(const ScalarStrain<OtherNumber>& other)
    : ScalarStrain(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a scalar strain by moving another one.
  constexpr ScalarStrain(ScalarStrain<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar strain by copying another one.
  constexpr ScalarStrain<Number>& operator=(const ScalarStrain<Number>& other) = default;

  // Copy assignment operator. Assigns this scalar strain by copying another one.
  template <typename OtherNumber>
  constexpr ScalarStrain<Number>& operator=(const ScalarStrain<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this scalar strain by moving another one.
  constexpr ScalarStrain<Number>& operator=(ScalarStrain<Number>&& other) noexcept = default;

  // Statically creates a scalar strain of zero.
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
