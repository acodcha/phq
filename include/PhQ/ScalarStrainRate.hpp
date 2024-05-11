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

#ifndef PHQ_STRAIN_RATE_SCALAR_HPP
#define PHQ_STRAIN_RATE_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Frequency.hpp"
#include "ScalarStrain.hpp"
#include "Time.hpp"
#include "Unit/Frequency.hpp"

namespace PhQ {

// Scalar component or resultant of a strain rate tensor. Time rate of change of a scalar strain.
// See also PhQ::StrainRate and PhQ::ScalarStrain.
template <typename Number = double>
class ScalarStrainRate : public DimensionalScalar<Unit::Frequency, Number> {
public:
  // Default constructor. Constructs a scalar strain rate with an uninitialized value.
  ScalarStrainRate() = default;

  // Constructor. Constructs a scalar strain rate with a given value expressed in a given frequency
  // unit.
  ScalarStrainRate(const Number value, const Unit::Frequency unit)
    : DimensionalScalar<Unit::Frequency, Number>(value, unit) {}

  // Constructor. Constructs a scalar strain rate from a given scalar strain and time using the
  // definition of strain rate.
  constexpr ScalarStrainRate(const ScalarStrain<Number>& scalar_strain, const Time<Number>& time)
    : ScalarStrainRate<Number>(scalar_strain.Value() / time.Value()) {}

  // Constructor. Constructs a scalar strain rate from a given scalar strain and frequency using the
  // definition of strain rate.
  constexpr ScalarStrainRate(
      const ScalarStrain<Number>& scalar_strain, const Frequency<Number>& frequency)
    : ScalarStrainRate<Number>(scalar_strain.Value() * frequency.Value()) {}

  // Destructor. Destroys this scalar strain rate.
  ~ScalarStrainRate() noexcept = default;

  // Copy constructor. Constructs a scalar strain rate by copying another one.
  constexpr ScalarStrainRate(const ScalarStrainRate<Number>& other) = default;

  // Copy constructor. Constructs a scalar strain rate by copying another one.
  template <typename OtherNumber>
  explicit constexpr ScalarStrainRate(const ScalarStrainRate<OtherNumber>& other)
    : ScalarStrainRate(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a scalar strain rate by moving another one.
  constexpr ScalarStrainRate(ScalarStrainRate<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar strain rate by copying another one.
  constexpr ScalarStrainRate<Number>& operator=(const ScalarStrainRate<Number>& other) = default;

  // Copy assignment operator. Assigns this scalar strain rate by copying another one.
  template <typename OtherNumber>
  constexpr ScalarStrainRate<Number>& operator=(const ScalarStrainRate<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this scalar strain rate by moving another one.
  constexpr ScalarStrainRate<Number>& operator=(
      ScalarStrainRate<Number>&& other) noexcept = default;

  // Statically creates a scalar strain rate of zero.
  static constexpr ScalarStrainRate<Number> Zero() {
    return ScalarStrainRate<Number>{static_cast<Number>(0)};
  }

  // Statically creates a scalar strain rate with a given value expressed in a given frequency unit.
  template <Unit::Frequency Unit>
  static constexpr ScalarStrainRate<Number> Create(const Number value) {
    return ScalarStrainRate<Number>{
        StaticConvertCopy<Unit::Frequency, Unit, Standard<Unit::Frequency>>(value)};
  }

  constexpr ScalarStrainRate<Number> operator+(const ScalarStrainRate<Number>& other) const {
    return ScalarStrainRate<Number>{this->value + other.value};
  }

  constexpr ScalarStrainRate<Number> operator-(const ScalarStrainRate<Number>& other) const {
    return ScalarStrainRate<Number>{this->value - other.value};
  }

  constexpr ScalarStrainRate<Number> operator*(const Number number) const {
    return ScalarStrainRate<Number>{this->value * number};
  }

  constexpr ScalarStrainRate<Number> operator/(const Number number) const {
    return ScalarStrainRate<Number>{this->value / number};
  }

  constexpr ScalarStrain<Number> operator*(const Time<Number>& time) const {
    return ScalarStrain<Number>{*this, time};
  }

  constexpr Number operator/(const ScalarStrainRate<Number>& other) const noexcept {
    return this->value / other.value;
  }

  constexpr ScalarStrain<Number> operator/(const Frequency<Number>& frequency) const {
    return ScalarStrain<Number>{*this, frequency};
  }

  constexpr void operator+=(const ScalarStrainRate<Number>& other) noexcept {
    this->value += other.value;
  }

  constexpr void operator-=(const ScalarStrainRate<Number>& other) noexcept {
    this->value -= other.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a scalar strain rate with a given value expressed in the standard
  // frequency unit.
  explicit constexpr ScalarStrainRate(const Number value)
    : DimensionalScalar<Unit::Frequency, Number>(value) {}

  template <typename OtherNumber>
  friend class StrainRate;
};

template <typename Number>
inline constexpr bool operator==(
    const ScalarStrainRate<Number>& left, const ScalarStrainRate<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const ScalarStrainRate<Number>& left, const ScalarStrainRate<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const ScalarStrainRate<Number>& left, const ScalarStrainRate<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const ScalarStrainRate<Number>& left, const ScalarStrainRate<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const ScalarStrainRate<Number>& left, const ScalarStrainRate<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const ScalarStrainRate<Number>& left, const ScalarStrainRate<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const ScalarStrainRate<Number>& scalar_strain_rate) {
  stream << scalar_strain_rate.Print();
  return stream;
}

template <typename Number>
inline constexpr ScalarStrainRate<Number> operator*(
    const Number number, const ScalarStrainRate<Number>& scalar_strain_rate) {
  return scalar_strain_rate * number;
}

template <typename Number>
inline constexpr ScalarStrain<Number>::ScalarStrain(
    const ScalarStrainRate<Number>& scalar_strain_rate, const Time<Number>& time)
  : ScalarStrain<Number>(scalar_strain_rate.Value() * time.Value()) {}

template <typename Number>
inline constexpr ScalarStrain<Number>::ScalarStrain(
    const ScalarStrainRate<Number>& scalar_strain_rate, const Frequency<Number>& frequency)
  : ScalarStrain<Number>(scalar_strain_rate.Value() / frequency.Value()) {}

template <typename Number>
inline constexpr ScalarStrainRate<Number> ScalarStrain<Number>::operator*(
    const Frequency<Number>& frequency) const {
  return ScalarStrainRate<Number>{*this, frequency};
}

template <typename Number>
inline constexpr ScalarStrainRate<Number> ScalarStrain<Number>::operator/(
    const Time<Number>& time) const {
  return ScalarStrainRate<Number>{*this, time};
}

template <typename Number>
inline constexpr ScalarStrain<Number> Time<Number>::operator*(
    const ScalarStrainRate<Number>& scalar_strain_rate) const {
  return ScalarStrain<Number>{scalar_strain_rate, *this};
}

template <typename Number>
inline constexpr ScalarStrainRate<Number> Frequency<Number>::operator*(
    const ScalarStrain<Number>& scalar_strain) const {
  return ScalarStrainRate<Number>{scalar_strain, *this};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ScalarStrainRate<Number>> {
  inline size_t operator()(const PhQ::ScalarStrainRate<Number>& scalar_strain_rate) const {
    return hash<Number>()(scalar_strain_rate.Value());
  }
};

}  // namespace std

#endif  // PHQ_STRAIN_RATE_SCALAR_HPP
