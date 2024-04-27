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

#ifndef PHQ_DIMENSION_MASS_HPP
#define PHQ_DIMENSION_MASS_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <iostream>
#include <string>
#include <string_view>

namespace PhQ::Dimension {

// Base physical dimension of mass. Typically denoted "M". One of seven independent base physical
// dimensions that form the physical dimension set of any unit of measure or physical quantity.
class Mass {
public:
  // Default constructor. Constructs a base physical dimension of mass with a value of zero.
  constexpr Mass() = default;

  // Constructor. Constructs a base physical dimension of mass with a given value.
  explicit constexpr Mass(const int8_t value) : value(value) {}

  // Destructor. Destroys this base physical dimension of mass.
  ~Mass() noexcept = default;

  // Copy constructor. Constructs a base physical dimension of mass by copying another one.
  constexpr Mass(const Mass& other) = default;

  // Copy assignment operator. Assigns the value of this base physical dimension of mass by copying
  // from another one.
  constexpr Mass& operator=(const Mass& other) = default;

  // Move constructor. Constructs a base physical dimension of mass by moving another one.
  constexpr Mass(Mass&& other) noexcept = default;

  // Move assignment operator. Assigns the value of this base physical dimension of mass by moving
  // another one.
  constexpr Mass& operator=(Mass&& other) noexcept = default;

  // Value of this base physical dimension.
  [[nodiscard]] constexpr int8_t Value() const noexcept {
    return value;
  }

  // Abbreviation of this base physical dimension.
  static std::string_view Abbreviation() noexcept {
    return "M";
  }

  // Label of this base physical dimension.
  static std::string_view Label() noexcept {
    return "Mass";
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

inline constexpr bool operator==(const Mass& left, const Mass& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Mass& left, const Mass& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Mass& left, const Mass& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Mass& left, const Mass& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Mass& left, const Mass& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Mass& left, const Mass& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Mass& mass) {
  stream << mass.Print();
  return stream;
}

}  // namespace PhQ::Dimension

namespace std {

template <>
struct hash<PhQ::Dimension::Mass> {
  inline size_t operator()(const PhQ::Dimension::Mass& mass) const {
    return hash<int8_t>()(mass.Value());
  }
};

}  // namespace std

#endif  // PHQ_DIMENSION_MASS_HPP
