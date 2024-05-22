// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
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

/// \brief Scalar component or resultant of a Cauchy stress tensor. See also PhQ::Stress.
template <typename Number = double>
class ScalarStress : public DimensionalScalar<Unit::Pressure, Number> {
public:
  /// \brief Default constructor. Constructs a scalar stress with an uninitialized value.
  ScalarStress() = default;

  /// \brief Constructor. Constructs a scalar stress with a given value expressed in a given
  /// pressure unit.
  ScalarStress(const Number value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, Number>(value, unit) {}

  /// \brief Destructor. Destroys this scalar stress.
  ~ScalarStress() noexcept = default;

  /// \brief Copy constructor. Constructs a scalar stress by copying another one.
  constexpr ScalarStress(const ScalarStress<Number>& other) = default;

  /// \brief Copy constructor. Constructs a scalar stress by copying another one.
  template <typename OtherNumber>
  explicit constexpr ScalarStress(const ScalarStress<OtherNumber>& other)
    : ScalarStress(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a scalar stress by moving another one.
  constexpr ScalarStress(ScalarStress<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this scalar stress by copying another one.
  constexpr ScalarStress<Number>& operator=(const ScalarStress<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this scalar stress by copying another one.
  template <typename OtherNumber>
  constexpr ScalarStress<Number>& operator=(const ScalarStress<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this scalar stress by moving another one.
  constexpr ScalarStress<Number>& operator=(ScalarStress<Number>&& other) noexcept = default;

  /// \brief Statically creates a scalar stress of zero.
  static constexpr ScalarStress<Number> Zero() {
    return ScalarStress<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a scalar stress with a given value expressed in a given pressure
  /// unit.
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
  /// \brief Constructor. Constructs a scalar stress with a given value expressed in the standard
  /// pressure unit.
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
