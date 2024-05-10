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

#ifndef PHQ_SUBSTANCE_AMOUNT_HPP
#define PHQ_SUBSTANCE_AMOUNT_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/SubstanceAmount.hpp"

namespace PhQ {

// Amount of substance scalar quantity.
template <typename Number = double>
class SubstanceAmount : public DimensionalScalar<Unit::SubstanceAmount, Number> {
public:
  // Default constructor. Constructs a substance amount with an uninitialized value.
  SubstanceAmount() = default;

  // Constructor. Constructs a substance amount with a given value expressed in a given substance
  // amount unit.
  SubstanceAmount(const Number value, const Unit::SubstanceAmount unit)
    : DimensionalScalar<Unit::SubstanceAmount, Number>(value, unit) {}

  // Destructor. Destroys this substance amount.
  ~SubstanceAmount() noexcept = default;

  // Copy constructor. Constructs a substance amount by copying another one.
  constexpr SubstanceAmount(const SubstanceAmount<Number>& other) = default;

  // Copy constructor. Constructs a substance amount by copying another one.
  template <typename OtherNumber>
  explicit constexpr SubstanceAmount(const SubstanceAmount<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a substance amount by moving another one.
  constexpr SubstanceAmount(SubstanceAmount<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this substance amount by copying another one.
  constexpr SubstanceAmount<Number>& operator=(const SubstanceAmount<Number>& other) = default;

  // Copy assignment operator. Assigns this substance amount by copying another one.
  template <typename OtherNumber>
  constexpr SubstanceAmount<Number>& operator=(const SubstanceAmount<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this substance amount by moving another one.
  constexpr SubstanceAmount<Number>& operator=(SubstanceAmount<Number>&& other) noexcept = default;

  // Statically creates a substance amount of zero.
  static constexpr SubstanceAmount<Number> Zero() {
    return SubstanceAmount<Number>{static_cast<Number>(0)};
  }

  // Statically creates a substance amount with a given value expressed in a given substance amount
  // unit.
  template <Unit::SubstanceAmount Unit>
  static constexpr SubstanceAmount<Number> Create(const Number value) {
    return SubstanceAmount<Number>{
        StaticConvertCopy<Unit::SubstanceAmount, Unit, Standard<Unit::SubstanceAmount>>(value)};
  }

  constexpr SubstanceAmount<Number> operator+(
      const SubstanceAmount<Number>& substance_amount) const {
    return SubstanceAmount<Number>{value + substance_amount.value};
  }

  constexpr SubstanceAmount<Number> operator-(
      const SubstanceAmount<Number>& substance_amount) const {
    return SubstanceAmount<Number>{value - substance_amount.value};
  }

  constexpr SubstanceAmount<Number> operator*(const Number number) const {
    return SubstanceAmount<Number>{value * number};
  }

  constexpr SubstanceAmount<Number> operator/(const Number number) const {
    return SubstanceAmount<Number>{value / number};
  }

  constexpr Number operator/(const SubstanceAmount<Number>& substance_amount) const noexcept {
    return value / substance_amount.value;
  }

  constexpr void operator+=(const SubstanceAmount<Number>& substance_amount) noexcept {
    value += substance_amount.value;
  }

  constexpr void operator-=(const SubstanceAmount<Number>& substance_amount) noexcept {
    value -= substance_amount.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a substance amount with a given value expressed in the standard
  // substance amount unit.
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
