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

#ifndef PHQ_SUBSTANCE_AMOUNT_HPP
#define PHQ_SUBSTANCE_AMOUNT_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/SubstanceAmount.hpp"

namespace PhQ {

/// \brief Amount of substance scalar quantity. Typically measured in moles (mol).
template <typename Number = double>
class SubstanceAmount : public DimensionalScalar<Unit::SubstanceAmount, Number> {
public:
  /// \brief Default constructor. Constructs a substance amount with an uninitialized value.
  SubstanceAmount() = default;

  /// \brief Constructor. Constructs a substance amount with a given value expressed in a given
  /// substance amount unit.
  SubstanceAmount(const Number value, const Unit::SubstanceAmount unit)
    : DimensionalScalar<Unit::SubstanceAmount, Number>(value, unit) {}

  /// \brief Destructor. Destroys this substance amount.
  ~SubstanceAmount() noexcept = default;

  /// \brief Copy constructor. Constructs a substance amount by copying another one.
  constexpr SubstanceAmount(const SubstanceAmount<Number>& other) = default;

  /// \brief Copy constructor. Constructs a substance amount by copying another one.
  template <typename OtherNumber>
  explicit constexpr SubstanceAmount(const SubstanceAmount<OtherNumber>& other)
    : SubstanceAmount(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a substance amount by moving another one.
  constexpr SubstanceAmount(SubstanceAmount<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this substance amount by copying another one.
  constexpr SubstanceAmount<Number>& operator=(const SubstanceAmount<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this substance amount by copying another one.
  template <typename OtherNumber>
  constexpr SubstanceAmount<Number>& operator=(const SubstanceAmount<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this substance amount by moving another one.
  constexpr SubstanceAmount<Number>& operator=(SubstanceAmount<Number>&& other) noexcept = default;

  /// \brief Statically creates a substance amount of zero.
  static constexpr SubstanceAmount<Number> Zero() {
    return SubstanceAmount<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a substance amount with a given value expressed in a given substance
  /// amount unit.
  template <Unit::SubstanceAmount Unit>
  static constexpr SubstanceAmount<Number> Create(const Number value) {
    return SubstanceAmount<Number>{
        StaticConvertCopy<Unit::SubstanceAmount, Unit, Standard<Unit::SubstanceAmount>>(value)};
  }

  constexpr SubstanceAmount<Number> operator+(
      const SubstanceAmount<Number>& substance_amount) const {
    return SubstanceAmount<Number>{this->value + substance_amount.value};
  }

  constexpr SubstanceAmount<Number> operator-(
      const SubstanceAmount<Number>& substance_amount) const {
    return SubstanceAmount<Number>{this->value - substance_amount.value};
  }

  constexpr SubstanceAmount<Number> operator*(const Number number) const {
    return SubstanceAmount<Number>{this->value * number};
  }

  constexpr SubstanceAmount<Number> operator/(const Number number) const {
    return SubstanceAmount<Number>{this->value / number};
  }

  constexpr Number operator/(const SubstanceAmount<Number>& substance_amount) const noexcept {
    return this->value / substance_amount.value;
  }

  constexpr void operator+=(const SubstanceAmount<Number>& substance_amount) noexcept {
    this->value += substance_amount.value;
  }

  constexpr void operator-=(const SubstanceAmount<Number>& substance_amount) noexcept {
    this->value -= substance_amount.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a substance amount with a given value expressed in the standard
  /// substance amount unit.
  explicit constexpr SubstanceAmount(const Number value)
    : DimensionalScalar<Unit::SubstanceAmount, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const SubstanceAmount<Number>& left, const SubstanceAmount<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const SubstanceAmount<Number>& left, const SubstanceAmount<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const SubstanceAmount<Number>& left, const SubstanceAmount<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const SubstanceAmount<Number>& left, const SubstanceAmount<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const SubstanceAmount<Number>& left, const SubstanceAmount<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const SubstanceAmount<Number>& left, const SubstanceAmount<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const SubstanceAmount<Number>& substance_amount) {
  stream << substance_amount.Print();
  return stream;
}

template <typename Number>
inline constexpr SubstanceAmount<Number> operator*(
    const Number number, const SubstanceAmount<Number>& substance_amount) {
  return substance_amount * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::SubstanceAmount<Number>> {
  inline size_t operator()(const PhQ::SubstanceAmount<Number>& substance_amount) const {
    return hash<Number>()(substance_amount.Value());
  }
};

}  // namespace std

#endif  // PHQ_SUBSTANCE_AMOUNT_HPP
