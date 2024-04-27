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

#ifndef PHQ_DIMENSION_ELECTRIC_CURRENT_HPP
#define PHQ_DIMENSION_ELECTRIC_CURRENT_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <iostream>
#include <string>
#include <string_view>

namespace PhQ::Dimension {

// Base physical dimension of electric current. Typically denoted "I". One of seven independent base
// physical dimensions that form the physical dimension set of any unit of measure or physical
// quantity.
class ElectricCurrent {
public:
  // Default constructor. Constructs a base physical dimension of electric current with a value of
  // zero.
  constexpr ElectricCurrent() = default;

  // Constructor. Constructs a base physical dimension of electric current with a given value.
  explicit constexpr ElectricCurrent(const int8_t value) : value(value) {}

  // Destructor. Destroys this base physical dimension of electric current.
  ~ElectricCurrent() noexcept = default;

  // Copy constructor. Constructs a base physical dimension of electric current by copying another
  // one.
  constexpr ElectricCurrent(const ElectricCurrent& other) = default;

  // Copy assignment operator. Assigns the value of this base physical dimension of electric current
  // by copying from another one.
  constexpr ElectricCurrent& operator=(const ElectricCurrent& other) = default;

  // Move constructor. Constructs a base physical dimension of electric current by moving another
  // one.
  constexpr ElectricCurrent(ElectricCurrent&& other) noexcept = default;

  // Move assignment operator. Assigns the value of this base physical dimension of electric current
  // by moving another one.
  constexpr ElectricCurrent& operator=(ElectricCurrent&& other) noexcept = default;

  // Value of this base physical dimension.
  [[nodiscard]] constexpr int8_t Value() const noexcept {
    return value;
  }

  // Abbreviation of this base physical dimension.
  static std::string_view Abbreviation() noexcept {
    return "I";
  }

  // Label of this base physical dimension.
  static std::string_view Label() noexcept {
    return "Electric Current";
  }

  // Prints this base physical dimension as a string.
  [[nodiscard]] std::string Print() const noexcept {
    if (value == 0) {
      return {};
    }
    std::string text{Abbreviation()};
    if (value >= 2) {
      text.append("^" + std::to_string(value));
    } else if (value <= -1) {
      text.append("^(" + std::to_string(value) + ")");
    }
    return text;
  }

private:
  // Value of this base physical dimension.
  int8_t value{0};
};

inline constexpr bool operator==(
    const ElectricCurrent& left, const ElectricCurrent& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const ElectricCurrent& left, const ElectricCurrent& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const ElectricCurrent& left, const ElectricCurrent& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const ElectricCurrent& left, const ElectricCurrent& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const ElectricCurrent& left, const ElectricCurrent& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const ElectricCurrent& left, const ElectricCurrent& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const ElectricCurrent& current) {
  stream << current.Print();
  return stream;
}

}  // namespace PhQ::Dimension

namespace std {

template <>
struct hash<PhQ::Dimension::ElectricCurrent> {
  inline size_t operator()(const PhQ::Dimension::ElectricCurrent& current) const {
    return hash<int8_t>()(current.Value());
  }
};

}  // namespace std

#endif  // PHQ_DIMENSION_ELECTRIC_CURRENT_HPP
