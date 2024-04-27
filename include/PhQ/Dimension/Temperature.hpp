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

#ifndef PHQ_DIMENSION_TEMPERATURE_HPP
#define PHQ_DIMENSION_TEMPERATURE_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <iostream>
#include <string>
#include <string_view>

namespace PhQ::Dimension {

// Base physical dimension of temperature. Typically denoted "Θ". One of seven independent base
// physical dimensions that form the physical dimension set of any unit of measure or physical
// quantity.
class Temperature {
public:
  // Default constructor. Constructs a base physical dimension of temperature with a value of zero.
  constexpr Temperature() = default;

  // Constructor. Constructs a base physical dimension of temperature with a given value.
  explicit constexpr Temperature(const int8_t value) : value(value) {}

  // Destructor. Destroys this base physical dimension of temperature.
  ~Temperature() noexcept = default;

  // Copy constructor. Constructs a base physical dimension of temperature by copying another one.
  constexpr Temperature(const Temperature& other) = default;

  // Copy assignment operator. Assigns the value of this base physical dimension of temperature by
  // copying from another one.
  constexpr Temperature& operator=(const Temperature& other) = default;

  // Move constructor. Constructs a base physical dimension of temperature by moving another one.
  constexpr Temperature(Temperature&& other) noexcept = default;

  // Move assignment operator. Assigns the value of this base physical dimension of temperature by
  // moving another one.
  constexpr Temperature& operator=(Temperature&& other) noexcept = default;

  // Value of this base physical dimension.
  [[nodiscard]] constexpr int8_t Value() const noexcept {
    return value;
  }

  // Abbreviation of this base physical dimension.
  static std::string_view Abbreviation() noexcept {
    return "Θ";
  }

  // Label of this base physical dimension.
  static std::string_view Label() noexcept {
    return "Temperature";
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

inline constexpr bool operator==(const Temperature& left, const Temperature& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Temperature& left, const Temperature& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Temperature& left, const Temperature& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Temperature& left, const Temperature& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Temperature& left, const Temperature& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Temperature& left, const Temperature& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Temperature& temperature) {
  stream << temperature.Print();
  return stream;
}

}  // namespace PhQ::Dimension

namespace std {

template <>
struct hash<PhQ::Dimension::Temperature> {
  inline size_t operator()(const PhQ::Dimension::Temperature& temperature) const {
    return hash<int8_t>()(temperature.Value());
  }
};

}  // namespace std

#endif  // PHQ_DIMENSION_TEMPERATURE_HPP
