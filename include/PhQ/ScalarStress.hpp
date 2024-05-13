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

#ifndef PHQ_STRESS_SCALAR_HPP
#define PHQ_STRESS_SCALAR_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declaration for class PhQ::ScalarStress.
template <typename Number>
class Stress;

// Scalar component or resultant of a Cauchy stress tensor. See also PhQ::Stress.
template <typename Number = double>
class ScalarStress : public DimensionalScalar<Unit::Pressure, Number> {
public:
  // Default constructor. Constructs a scalar stress with an uninitialized value.
  ScalarStress() = default;

  // Constructor. Constructs a scalar stress with a given value expressed in a given pressure unit.
  ScalarStress(const Number value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, Number>(value, unit) {}

  // Destructor. Destroys this scalar stress.
  ~ScalarStress() noexcept = default;

  // Copy constructor. Constructs a scalar stress by copying another one.
  constexpr ScalarStress(const ScalarStress<Number>& other) = default;

  // Copy constructor. Constructs a scalar stress by copying another one.
  template <typename OtherNumber>
  explicit constexpr ScalarStress(const ScalarStress<OtherNumber>& other)
    : ScalarStress(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a scalar stress by moving another one.
  constexpr ScalarStress(ScalarStress<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this scalar stress by copying another one.
  constexpr ScalarStress<Number>& operator=(const ScalarStress<Number>& other) = default;

  // Copy assignment operator. Assigns this scalar stress by copying another one.
  template <typename OtherNumber>
  constexpr ScalarStress<Number>& operator=(const ScalarStress<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this scalar stress by moving another one.
  constexpr ScalarStress<Number>& operator=(ScalarStress<Number>&& other) noexcept = default;

  // Statically creates a scalar stress of zero.
  static constexpr ScalarStress<Number> Zero() {
    return ScalarStress<Number>{static_cast<Number>(0)};
  }

  // Statically creates a scalar stress with a given value expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr ScalarStress<Number> Create(const Number value) {
    return ScalarStress<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr ScalarStress<Number> operator+(const ScalarStress<Number>& scalar_stress) const {
    return ScalarStress<Number>{this->value + scalar_stress.value};
  }

  constexpr ScalarStress<Number> operator-(const ScalarStress<Number>& scalar_stress) const {
    return ScalarStress<Number>{this->value - scalar_stress.value};
  }

  constexpr ScalarStress<Number> operator*(const Number number) const {
    return ScalarStress<Number>{this->value * number};
  }

  constexpr ScalarStress<Number> operator/(const Number number) const {
    return ScalarStress<Number>{this->value / number};
  }

  constexpr Number operator/(const ScalarStress<Number>& scalar_stress) const noexcept {
    return this->value / scalar_stress.value;
  }

  constexpr void operator+=(const ScalarStress<Number>& scalar_stress) noexcept {
    this->value += scalar_stress.value;
  }

  constexpr void operator-=(const ScalarStress<Number>& scalar_stress) noexcept {
    this->value -= scalar_stress.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a scalar stress with a given value expressed in the standard pressure
  // unit.
  explicit constexpr ScalarStress(const Number value)
    : DimensionalScalar<Unit::Pressure, Number>(value) {}

  template <typename OtherNumber>
  friend class Stress;
};

template <typename Number>
inline constexpr bool operator==(
    const ScalarStress<Number>& left, const ScalarStress<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const ScalarStress<Number>& left, const ScalarStress<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const ScalarStress<Number>& left, const ScalarStress<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const ScalarStress<Number>& left, const ScalarStress<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const ScalarStress<Number>& left, const ScalarStress<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const ScalarStress<Number>& left, const ScalarStress<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const ScalarStress<Number>& scalar_stress) {
  stream << scalar_stress.Print();
  return stream;
}

template <typename Number>
inline constexpr ScalarStress<Number> operator*(
    const Number number, const ScalarStress<Number>& scalar_stress) {
  return scalar_stress * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ScalarStress<Number>> {
  inline size_t operator()(const PhQ::ScalarStress<Number>& scalar_stress) const {
    return hash<Number>()(scalar_stress.Value());
  }
};

}  // namespace std

#endif  // PHQ_STRESS_SCALAR_HPP
