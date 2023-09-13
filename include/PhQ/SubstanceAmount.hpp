// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_SUBSTANCE_AMOUNT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_SUBSTANCE_AMOUNT_HPP

#include "DimensionalScalarQuantity.hpp"
#include "Unit/SubstanceAmount.hpp"

namespace PhQ {

// Amount of substance scalar quantity.
class SubstanceAmount
  : public DimensionalScalarQuantity<Unit::SubstanceAmount> {
public:
  constexpr SubstanceAmount() noexcept
    : DimensionalScalarQuantity<Unit::SubstanceAmount>() {}

  SubstanceAmount(const double value, const Unit::SubstanceAmount unit) noexcept
    : DimensionalScalarQuantity<Unit::SubstanceAmount>(value, unit) {}

  static constexpr SubstanceAmount Zero() noexcept {
    return SubstanceAmount{0.0};
  }

  template <Unit::SubstanceAmount Unit>
  static constexpr SubstanceAmount Create(const double value) noexcept {
    return SubstanceAmount{
        StaticConvertCopy<Unit::SubstanceAmount, Unit,
                          Standard<Unit::SubstanceAmount>>(value)};
  }

  constexpr SubstanceAmount operator+(
      const SubstanceAmount& substance_amount) const noexcept {
    return SubstanceAmount{value_ + substance_amount.value_};
  }

  constexpr SubstanceAmount operator-(
      const SubstanceAmount& substance_amount) const noexcept {
    return SubstanceAmount{value_ - substance_amount.value_};
  }

  constexpr SubstanceAmount operator*(const double number) const noexcept {
    return SubstanceAmount{value_ * number};
  }

  constexpr SubstanceAmount operator/(const double number) const noexcept {
    return SubstanceAmount{value_ / number};
  }

  constexpr double operator/(
      const SubstanceAmount& substance_amount) const noexcept {
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
  explicit constexpr SubstanceAmount(const double value) noexcept
    : DimensionalScalarQuantity<Unit::SubstanceAmount>(value) {}
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

inline std::ostream& operator<<(
    std::ostream& stream, const SubstanceAmount& substance_amount) noexcept {
  stream << substance_amount.Print();
  return stream;
}

inline constexpr SubstanceAmount operator*(
    const double number, const SubstanceAmount& substance_amount) noexcept {
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

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_SUBSTANCE_AMOUNT_HPP
