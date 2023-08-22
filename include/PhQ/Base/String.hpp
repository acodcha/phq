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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_STRING_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_STRING_HPP

#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
#include <iterator>
#include <optional>
#include <sstream>
#include <string>
#include <string_view>
#include <vector>

#include "Precision.hpp"

namespace PhQ {

// Transforms a given string such that all of its characters are lowercase.
inline void Lowercase(std::string& text) noexcept {
  std::transform(text.begin(), text.end(), text.begin(),
                 [](int character) { return std::tolower(character); });
}

// Returns a copy of a given string where all characters are lowercase.
inline std::string LowercaseCopy(const std::string_view text) noexcept {
  std::string result{text};
  std::transform(result.begin(), result.end(), result.begin(),
                 [](int character) { return std::tolower(character); });
  return result;
}

// Parses a given string into an integer. Returns the integer, or std::nullopt
// if the string cannot be parsed into an integer.
inline std::optional<int_least64_t> ParseToInteger(
    const std::string& text) noexcept {
  char* end = 0;
  const long long int value = std::strtoll(text.c_str(), &end, 10);
  if (end != text.c_str() && *end == '\0' && value != LLONG_MAX
      && value != LLONG_MIN) {
    return {static_cast<int_least64_t>(value)};
  }
  return std::nullopt;
}

// Parses a given string into a double-precision floating-point number. Returns
// the number, or std::nullopt if the string cannot be parsed into a
// double-precision floating-point number.
inline std::optional<double> ParseToDouble(const std::string& text) noexcept {
  char* end = 0;
  const double value = strtod(text.c_str(), &end);
  if (end != text.c_str() && *end == '\0' && value != HUGE_VAL
      && value != -HUGE_VAL) {
    return {value};
  }
  return std::nullopt;
}

// Prints a given double-precision floating point number as a string to a given
// precision.
inline std::string Print(
    const double value,
    const Precision precision = Precision::Double) noexcept {
  const double absolute{std::abs(value)};
  std::ostringstream stream;
  if (absolute < 1.0) {
    // Interval: [0, 1[
    if (absolute < 0.001) {
      // Interval: [0, 0.001[
      if (absolute == 0.0) {
        // Interval: [0, 0]
        return "0";
      } else {
        // Interval: ]0, 0.001[
        if (precision == Precision::Double) {
          stream << std::scientific << std::setprecision(15) << value;
        } else {
          stream << std::scientific << std::setprecision(6) << value;
        }
      }
    } else {
      // Interval: [0.001, 1[
      if (absolute < 0.1) {
        // Interval: [0.001, 0.1[
        if (absolute < 0.01) {
          // Interval: [0.001, 0.01[
          if (precision == Precision::Double) {
            stream << std::fixed << std::setprecision(18) << value;
          } else {
            stream << std::fixed << std::setprecision(9) << value;
          }
        } else {
          // Interval: [0.01, 0.1[
          if (precision == Precision::Double) {
            stream << std::fixed << std::setprecision(17) << value;
          } else {
            stream << std::fixed << std::setprecision(8) << value;
          }
        }
      } else {
        // Interval: [0.1, 1[
        if (precision == Precision::Double) {
          stream << std::fixed << std::setprecision(16) << value;
        } else {
          stream << std::fixed << std::setprecision(7) << value;
        }
      }
    }
  } else {
    // Interval: [1, +inf[
    if (absolute < 1000.0) {
      // Interval: [1, 1000[
      if (absolute < 10.0) {
        // Interval: [1, 10[
        if (precision == Precision::Double) {
          stream << std::fixed << std::setprecision(15) << value;
        } else {
          stream << std::fixed << std::setprecision(6) << value;
        }
      } else {
        // Interval: [10, 1000[
        if (absolute < 100.0) {
          // Interval: [10, 100[
          if (precision == Precision::Double) {
            stream << std::fixed << std::setprecision(14) << value;
          } else {
            stream << std::fixed << std::setprecision(5) << value;
          }
        } else {
          // Interval: [100, 1000[
          if (precision == Precision::Double) {
            stream << std::fixed << std::setprecision(13) << value;
          } else {
            stream << std::fixed << std::setprecision(4) << value;
          }
        }
      }
    } else {
      // Interval: [1000, +inf[
      if (absolute < 10000.0) {
        // Interval: [1000, 10000[
        if (precision == Precision::Double) {
          stream << std::fixed << std::setprecision(12) << value;
        } else {
          stream << std::fixed << std::setprecision(3) << value;
        }
      } else {
        // Interval: [10000, +inf[
        if (precision == Precision::Double) {
          stream << std::scientific << std::setprecision(15) << value;
        } else {
          stream << std::scientific << std::setprecision(6) << value;
        }
      }
    }
  }
  return stream.str();
}

// Replaces all occurrences of a given character in a given string with a
// different given character.
inline void Replace(
    std::string& text, const char from, const char to) noexcept {
  std::replace(text.begin(), text.end(), from, to);
}

// Returns a copy of a given string where all occurrences of a given character
// have been replaced with a different given character.
inline std::string ReplaceCopy(
    const std::string_view text, const char from, const char to) noexcept {
  std::string result{text};
  std::replace_copy(text.cbegin(), text.cend(), result.begin(), from, to);
  return result;
}

// Transforms a given string into snake case; that is, all characters are
// lowercase and all spaces are replaced with underscores.
inline void SnakeCase(std::string& text) noexcept {
  Lowercase(text);
  Replace(text, ' ', '_');
}

// Returns a copy of a given string in snake case; that is, all characters are
// lowercase and all spaces are replaced with underscores.
inline std::string SnakeCaseCopy(const std::string_view text) noexcept {
  return LowercaseCopy(ReplaceCopy(text, ' ', '_'));
}

// Splits a given string by whitespace and returns the collection of resulting
// strings.
inline std::vector<std::string> SplitByWhitespace(
    const std::string& text) noexcept {
  std::istringstream stream{text};
  std::vector<std::string> words{std::istream_iterator<std::string>{stream},
                                 std::istream_iterator<std::string>{}};
  return words;
}

// Transforms a given string such that all of its characters are uppercase.
inline void Uppercase(std::string& text) noexcept {
  std::transform(text.begin(), text.end(), text.begin(),
                 [](int character) { return std::toupper(character); });
}

// Returns a copy of a given string where all characters are uppercase.
inline std::string UppercaseCopy(const std::string_view text) noexcept {
  std::string result{text};
  std::transform(result.begin(), result.end(), result.begin(),
                 [](int character) { return std::toupper(character); });
  return result;
}

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_STRING_HPP
