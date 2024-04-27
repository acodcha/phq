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

#ifndef PHQ_DIMENSION_LUMINOUS_INTENSITY_HPP
#define PHQ_DIMENSION_LUMINOUS_INTENSITY_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <iostream>
#include <string>
#include <string_view>

namespace PhQ::Dimension {

// Base physical dimension of luminous intensity. Typically denoted "J". One of seven independent
// base physical dimensions that form the physical dimension set of any unit of measure or physical
// quantity.
class LuminousIntensity {
public:
  // Default constructor. Constructs a base physical dimension of luminous intensity with a value of
  // zero.
  constexpr LuminousIntensity() = default;

  // Constructor. Constructs a base physical dimension of luminous intensity with a given value.
  explicit constexpr LuminousIntensity(const int8_t value) : value(value) {}

  // Destructor. Destroys this base physical dimension of luminous intensity.
  ~LuminousIntensity() noexcept = default;

  // Copy constructor. Constructs a base physical dimension of luminous intensity by copying another
  // one.
  constexpr LuminousIntensity(const LuminousIntensity& other) = default;

  // Copy assignment operator. Assigns the value of this base physical dimension of luminous
  // intensity by copying from another one.
  constexpr LuminousIntensity& operator=(const LuminousIntensity& other) = default;

  // Move constructor. Constructs a base physical dimension of luminous intensity by moving another
  // one.
  constexpr LuminousIntensity(LuminousIntensity&& other) noexcept = default;

  // Move assignment operator. Assigns the value of this base physical dimension of luminous
  // intensity by moving another one.
  constexpr LuminousIntensity& operator=(LuminousIntensity&& other) noexcept = default;

  // Value of this base physical dimension.
  [[nodiscard]] constexpr int8_t Value() const noexcept {
    return value;
  }

  // Abbreviation of this base physical dimension.
  static std::string_view Abbreviation() noexcept {
    return "J";
  }

  // Label of this base physical dimension.
  static std::string_view Label() noexcept {
    return "Luminous Intensity";
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
    const LuminousIntensity& left, const LuminousIntensity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const LuminousIntensity& left, const LuminousIntensity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const LuminousIntensity& left, const LuminousIntensity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const LuminousIntensity& left, const LuminousIntensity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const LuminousIntensity& left, const LuminousIntensity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const LuminousIntensity& left, const LuminousIntensity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const LuminousIntensity& intensity) {
  stream << intensity.Print();
  return stream;
}

}  // namespace PhQ::Dimension

namespace std {

template <>
struct hash<PhQ::Dimension::LuminousIntensity> {
  inline size_t operator()(const PhQ::Dimension::LuminousIntensity& intensity) const {
    return hash<int8_t>()(intensity.Value());
  }
};

}  // namespace std

#endif  // PHQ_DIMENSION_LUMINOUS_INTENSITY_HPP
