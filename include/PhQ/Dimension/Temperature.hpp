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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_TEMPERATURE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_TEMPERATURE_HPP

#include <iostream>
#include <string>
#include <string_view>

#include "../Base.hpp"

namespace PhQ::Dimension {

// Base physical dimension of temperature. Typically denoted "Θ". One of seven
// independent base physical dimensions that form the physical dimension set of
// any unit of measure or physical quantity.
class Temperature {
public:
  constexpr Temperature() noexcept : value_(0) {}

  explicit constexpr Temperature(const int8_t value) noexcept : value_(value) {}

  constexpr int8_t Value() const noexcept { return value_; }

  static std::string_view Abbreviation() noexcept { return "Θ"; }

  static std::string_view Label() noexcept { return "Temperature"; }

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
    const Temperature& left, const Temperature& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const Temperature& left, const Temperature& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const Temperature& left, const Temperature& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const Temperature& left, const Temperature& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const Temperature& left, const Temperature& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const Temperature& left, const Temperature& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const Temperature& temperature) noexcept {
  stream << temperature.Print();
  return stream;
}

}  // namespace PhQ::Dimension

namespace std {

template<> struct hash<PhQ::Dimension::Temperature> {
  inline size_t operator()(
      const PhQ::Dimension::Temperature& temperature) const {
    return hash<int8_t>()(temperature.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_TEMPERATURE_HPP
