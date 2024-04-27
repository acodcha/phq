// Copyright 2020-2023 Alexandre Coderre-Chabot
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
class SubstanceAmount : public DimensionalScalar<Unit::SubstanceAmount> {
public:
  // Default constructor. Constructs a substance amount with an uninitialized value.
  SubstanceAmount() = default;

  // Constructor. Constructs a substance amount with a given value expressed in a given substance
  // amount unit.
  SubstanceAmount(const double value, const Unit::SubstanceAmount unit)
    : DimensionalScalar<Unit::SubstanceAmount>(value, unit) {}

  // Destructor. Destroys this substance amount.
  ~SubstanceAmount() noexcept = default;

  // Copy constructor. Constructs a substance amount by copying another one.
  constexpr SubstanceAmount(const SubstanceAmount& other) = default;

  // Move constructor. Constructs a substance amount by moving another one.
  constexpr SubstanceAmount(SubstanceAmount&& other) noexcept = default;

  // Copy assignment operator. Assigns this substance amount by copying another one.
  constexpr SubstanceAmount& operator=(const SubstanceAmount& other) = default;

  // Move assignment operator. Assigns this substance amount by moving another one.
  constexpr SubstanceAmount& operator=(SubstanceAmount&& other) noexcept = default;

  // Statically creates a substance amount of zero.
  static constexpr SubstanceAmount Zero() {
    return SubstanceAmount{0.0};
  }

  // Statically creates a substance amount with a given value expressed in a given substance amount
  // unit.
  template <Unit::SubstanceAmount Unit>
  static constexpr SubstanceAmount Create(const double value) {
    return SubstanceAmount{
        StaticConvertCopy<Unit::SubstanceAmount, Unit, Standard<Unit::SubstanceAmount>>(value)};
  }

  constexpr SubstanceAmount operator+(const SubstanceAmount& substance_amount) const {
    return SubstanceAmount{value_ + substance_amount.value_};
  }

  constexpr SubstanceAmount operator-(const SubstanceAmount& substance_amount) const {
    return SubstanceAmount{value_ - substance_amount.value_};
  }

  constexpr SubstanceAmount operator*(const double number) const {
    return SubstanceAmount{value_ * number};
  }

  constexpr SubstanceAmount operator/(const double number) const {
    return SubstanceAmount{value_ / number};
  }

  constexpr double operator/(const SubstanceAmount& substance_amount) const noexcept {
    return value_ / substance_amount.value_;
  }

  constexpr void operator+=(const SubstanceAmount& substance_amount) noexcept {
    value_ += substance_amount.value_;
  }

  constexpr void operator-=(const SubstanceAmount& substance_amount) noexcept {
    value_ -= substance_amount.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a substance amount with a given value expressed in the standard
  // substance amount unit.
  explicit constexpr SubstanceAmount(const double value)
    : DimensionalScalar<Unit::SubstanceAmount>(value) {}
};

inline constexpr bool operator==(
    const SubstanceAmount& left, const SubstanceAmount& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const SubstanceAmount& left, const SubstanceAmount& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const SubstanceAmount& left, const SubstanceAmount& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const SubstanceAmount& left, const SubstanceAmount& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const SubstanceAmount& left, const SubstanceAmount& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const SubstanceAmount& left, const SubstanceAmount& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const SubstanceAmount& substance_amount) {
  stream << substance_amount.Print();
  return stream;
}

inline constexpr SubstanceAmount operator*(
    const double number, const SubstanceAmount& substance_amount) {
  return substance_amount * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::SubstanceAmount> {
  inline size_t operator()(const PhQ::SubstanceAmount& substance_amount) const {
    return hash<double>()(substance_amount.Value());
  }
};

}  // namespace std

#endif  // PHQ_SUBSTANCE_AMOUNT_HPP
