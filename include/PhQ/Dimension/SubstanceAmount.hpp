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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_SUBSTANCE_AMOUNT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_SUBSTANCE_AMOUNT_HPP

#include <iostream>
#include <string>
#include <string_view>

#include "../Base.hpp"

namespace PhQ::Dimension {

// Base physical dimension of amount of substance. Typically denoted "N". One of
// seven independent base physical dimensions that form the physical dimension
// set of any unit of measure or physical quantity.
class SubstanceAmount {
public:
  // Default constructor. Constructs a base physical dimension of amount of
  // substance with a value of zero.
  constexpr SubstanceAmount() : value_(0) {}

  // Constructor. Constructs a base physical dimension of amount of substance
  // with a given value.
  explicit constexpr SubstanceAmount(const int8_t value) : value_(value) {}

  // Destructor. Destroys this base physical dimension.
  ~SubstanceAmount() noexcept = default;

  // Copy constructor. Constructs a base physical dimension of amount of
  // substance by copying another one.
  constexpr SubstanceAmount(const SubstanceAmount& other) = default;

  // Copy assignment operator. Assigns the value of this base physical dimension
  // of amount of substance by copying from another one.
  constexpr SubstanceAmount& operator=(const SubstanceAmount& other) = default;

  // Move constructor. Constructs a base physical dimension of amount of
  // substance by moving another one.
  constexpr SubstanceAmount(SubstanceAmount&& other) noexcept = default;

  // Move assignment operator. Assigns the value of this base physical dimension
  // of amount of substance by moving another one.
  constexpr SubstanceAmount& operator=(
      SubstanceAmount&& other) noexcept = default;

  // Value of this base physical dimension.
  constexpr int8_t Value() const noexcept {
    return value_;
  }

  // Abbreviation of this base physical dimension.
  static std::string_view Abbreviation() noexcept {
    return "N";
  }

  // Label of this base physical dimension.
  static std::string_view Label() noexcept {
    return "Substance Amount";
  }

  // Prints this base physical dimension as a string.
  std::string Print() const noexcept {
    if (value_ == 0) {
      return {};
    }
    std::string text{Abbreviation()};
    if (value_ >= 2) {
      text.append("^" + std::to_string(value_));
    } else if (value_ <= -1) {
      text.append("^(" + std::to_string(value_) + ")");
    }
    return text;
  }

private:
  int8_t value_;
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
    std::ostream& stream, const SubstanceAmount& amount) {
  stream << amount.Print();
  return stream;
}

}  // namespace PhQ::Dimension

namespace std {

template <>
struct hash<PhQ::Dimension::SubstanceAmount> {
  inline size_t operator()(
      const PhQ::Dimension::SubstanceAmount& amount) const {
    return hash<int8_t>()(amount.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_SUBSTANCE_AMOUNT_HPP
