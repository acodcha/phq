// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
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

#ifndef PHQ_DIMENSION_ELECTRIC_CURRENT_HPP
#define PHQ_DIMENSION_ELECTRIC_CURRENT_HPP

#include <cstddef>
#include <cstdint>
#include <functional>
#include <iostream>
#include <string>
#include <string_view>

namespace PhQ::Dimension {

/// \brief Base physical dimension of electric current. Typically denoted "I". One of seven
/// independent base physical dimensions that form the physical dimension set of any unit of measure
/// or physical quantity.
class ElectricCurrent {
public:
  /// \brief Default constructor. Constructs a base physical dimension of electric current with a
  /// value of zero.
  constexpr ElectricCurrent() = default;

  /// \brief Constructor. Constructs a base physical dimension of electric current with a given
  /// value.
  explicit constexpr ElectricCurrent(const int8_t value) : value(value) {}

  /// \brief Destructor. Destroys this base physical dimension of electric current.
  ~ElectricCurrent() noexcept = default;

  /// \brief Copy constructor. Constructs a base physical dimension of electric current by copying
  /// another one.
  constexpr ElectricCurrent(const ElectricCurrent& other) = default;

  /// \brief Copy assignment operator. Assigns the value of this base physical dimension of electric
  /// current by copying from another one.
  constexpr ElectricCurrent& operator=(const ElectricCurrent& other) = default;

  /// \brief Move constructor. Constructs a base physical dimension of electric current by moving
  /// another one.
  constexpr ElectricCurrent(ElectricCurrent&& other) noexcept = default;

  /// \brief Move assignment operator. Assigns the value of this base physical dimension of electric
  /// current by moving another one.
  constexpr ElectricCurrent& operator=(ElectricCurrent&& other) noexcept = default;

  /// \brief Value of this base physical dimension.
  [[nodiscard]] constexpr int8_t Value() const noexcept {
    return value;
  }

  /// \brief Abbreviation of this base physical dimension.
  static std::string_view Abbreviation() noexcept {
    return "I";
  }

  /// \brief Label of this base physical dimension.
  static std::string_view Label() noexcept {
    return "Electric Current";
  }

  /// \brief Prints this base physical dimension as a string.
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
  /// \brief Value of this base physical dimension.
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
