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

#ifndef PHQ_SUBSTANCE_AMOUNT_HPP
#define PHQ_SUBSTANCE_AMOUNT_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/SubstanceAmount.hpp"

namespace PhQ {

/// \brief Amount of substance. Typically measured in moles (mol).
template <typename NumericType = double>
class SubstanceAmount : public DimensionalScalar<Unit::SubstanceAmount, NumericType> {
public:
  /// \brief Default constructor. Constructs a substance amount with an uninitialized value.
  SubstanceAmount() = default;

  /// \brief Constructor. Constructs a substance amount with a given value expressed in a given
  /// substance amount unit.
  SubstanceAmount(const NumericType value, const Unit::SubstanceAmount unit)
    : DimensionalScalar<Unit::SubstanceAmount, NumericType>(value, unit) {}

  /// \brief Destructor. Destroys this substance amount.
  ~SubstanceAmount() noexcept = default;

  /// \brief Copy constructor. Constructs a substance amount by copying another one.
  constexpr SubstanceAmount(const SubstanceAmount<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a substance amount by copying another one.
  template <typename OtherNumericType>
  explicit constexpr SubstanceAmount(const SubstanceAmount<OtherNumericType>& other)
    : SubstanceAmount(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a substance amount by moving another one.
  constexpr SubstanceAmount(SubstanceAmount<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this substance amount by copying another one.
  constexpr SubstanceAmount<NumericType>& operator=(
      const SubstanceAmount<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this substance amount by copying another one.
  template <typename OtherNumericType>
  constexpr SubstanceAmount<NumericType>& operator=(
      const SubstanceAmount<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this substance amount by moving another one.
  constexpr SubstanceAmount<NumericType>& operator=(
      SubstanceAmount<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a substance amount of zero.
  static constexpr SubstanceAmount<NumericType> Zero() {
    return SubstanceAmount<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a substance amount with a given value expressed in a given substance
  /// amount unit.
  template <Unit::SubstanceAmount Unit>
  static constexpr SubstanceAmount<NumericType> Create(const NumericType value) {
    return SubstanceAmount<NumericType>{
        ConvertStatically<Unit::SubstanceAmount, Unit, Standard<Unit::SubstanceAmount>>(value)};
  }

  constexpr SubstanceAmount<NumericType> operator+(
      const SubstanceAmount<NumericType>& substance_amount) const {
    return SubstanceAmount<NumericType>{this->value + substance_amount.value};
  }

  constexpr SubstanceAmount<NumericType> operator-(
      const SubstanceAmount<NumericType>& substance_amount) const {
    return SubstanceAmount<NumericType>{this->value - substance_amount.value};
  }

  constexpr SubstanceAmount<NumericType> operator*(const NumericType number) const {
    return SubstanceAmount<NumericType>{this->value * number};
  }

  constexpr SubstanceAmount<NumericType> operator/(const NumericType number) const {
    return SubstanceAmount<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const SubstanceAmount<NumericType>& substance_amount) const noexcept {
    return this->value / substance_amount.value;
  }

  constexpr void operator+=(const SubstanceAmount<NumericType>& substance_amount) noexcept {
    this->value += substance_amount.value;
  }

  constexpr void operator-=(const SubstanceAmount<NumericType>& substance_amount) noexcept {
    this->value -= substance_amount.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a substance amount with a given value expressed in the standard
  /// substance amount unit.
  explicit constexpr SubstanceAmount(const NumericType value)
    : DimensionalScalar<Unit::SubstanceAmount, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const SubstanceAmount<NumericType>& left, const SubstanceAmount<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const SubstanceAmount<NumericType>& left, const SubstanceAmount<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const SubstanceAmount<NumericType>& left, const SubstanceAmount<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const SubstanceAmount<NumericType>& left, const SubstanceAmount<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const SubstanceAmount<NumericType>& left, const SubstanceAmount<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const SubstanceAmount<NumericType>& left, const SubstanceAmount<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const SubstanceAmount<NumericType>& substance_amount) {
  stream << substance_amount.Print();
  return stream;
}

template <typename NumericType>
inline constexpr SubstanceAmount<NumericType> operator*(
    const NumericType number, const SubstanceAmount<NumericType>& substance_amount) {
  return substance_amount * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::SubstanceAmount<NumericType>> {
  inline size_t operator()(const PhQ::SubstanceAmount<NumericType>& substance_amount) const {
    return hash<NumericType>()(substance_amount.Value());
  }
};

}  // namespace std

#endif  // PHQ_SUBSTANCE_AMOUNT_HPP
