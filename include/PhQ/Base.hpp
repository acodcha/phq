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

#ifndef PHQ_BASE_HPP
#define PHQ_BASE_HPP

#include <algorithm>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iterator>
#include <limits>
#include <map>
#include <optional>
#include <sstream>
#include <string>
#include <string_view>
#include <type_traits>
#include <unordered_map>
#include <utility>
#include <vector>

/// \brief Namespace that encompasses all of the Physical Quantities library's content.
namespace PhQ {

/// \brief The mathematical constant π = 3.14...
template <typename Number = double>
inline constexpr Number Pi;

/// \brief The mathematical constant π = 3.14... expressed as a single-precision 32-bit binary
/// floating-point number.
template <>
inline constexpr float Pi<float>{3.1415927F};

/// \brief The mathematical constant π = 3.14... expressed as a double-precision 64-bit binary
/// floating-point number.
template <>
inline constexpr double Pi<double>{3.14159265358979323846};

/// \brief The mathematical constant π = 3.14... expressed as a "long double". The exact
/// implementation of the "long double" type varies by system; the most common implementations are
/// 64-bit, 80-bit, 96-bit, or 128-bit binary floating-point numbers.
template <>
inline constexpr const long double Pi<long double>{3.141592653589793238462643383279502884L};

/// @brief Namespace that contains base physical dimensions.
namespace Dimension {}

/// \brief Namespace that contains internal implementation details of the Physical Quantities
/// library. Contents within this namespace are not meant to be used except by the the Physical
/// Quantities library's own functions and classes.
namespace Internal {

/// \brief Map of enumerations to their corresponding abbreviations. This is an internal
/// implementation detail and is not intended to be used except by the PhQ::Abbreviation function.
template <typename Enumeration>
inline const std::map<Enumeration, std::string_view> Abbreviations;

}  // namespace Internal

/// \brief Returns the abbreviation of a given enumeration value. For example,
/// PhQ::Abbreviation(PhQ::Unit::Time::Hour) returns "hr".
template <typename Enumeration>
inline std::string_view Abbreviation(const Enumeration enumeration) {
  return Internal::Abbreviations<Enumeration>.find(enumeration)->second;
}

namespace Internal {

/// \brief Map of spellings to their corresponding enumeration values. This is an internal
/// implementation detail and is not intended to be used except by the PhQ::Parse function.
template <typename Enumeration>
inline const std::unordered_map<std::string_view, Enumeration> Spellings;

}  // namespace Internal

/// \brief Attempts to parse some given text into an enumeration. Returns the enumeration if one is
/// found, or std::nullopt otherwise. For example, PhQ::Parse<PhQ::Unit::Time>("hr") returns
/// PhQ::Unit::Time::Hour.
template <typename Enumeration>
std::optional<Enumeration> Parse(const std::string_view spelling) {
  const typename std::unordered_map<std::string_view, Enumeration>::const_iterator found{
      Internal::Spellings<Enumeration>.find(spelling)};
  if (found != Internal::Spellings<Enumeration>.cend()) {
    return found->second;
  }
  return std::nullopt;
}

/// \brief Transforms a given string such that all of its characters are lowercase.
inline void Lowercase(std::string& text) {
  std::transform(text.begin(), text.end(), text.begin(), [](int character) {
    return std::tolower(character);
  });
}

/// \brief Returns a copy of a given string where all characters are lowercase.
[[nodiscard]] inline std::string LowercaseCopy(const std::string_view text) {
  std::string result{text};
  std::transform(result.begin(), result.end(), result.begin(), [](int character) {
    return std::tolower(character);
  });
  return result;
}

template <typename Number = double>
[[nodiscard]] inline std::optional<Number> ParseToNumber(const std::string& text);

template <>
[[nodiscard]] inline std::optional<float> ParseToNumber(const std::string& text) {
  float number;
  try {
    number = std::stof(text);
  } catch (...) {
    return std::nullopt;
  }
  return number;
}

template <>
[[nodiscard]] inline std::optional<double> ParseToNumber(const std::string& text) {
  double number;
  try {
    number = std::stod(text);
  } catch (...) {
    return std::nullopt;
  }
  return number;
}

template <>
[[nodiscard]] inline std::optional<long double> ParseToNumber(const std::string& text) {
  long double number;
  try {
    number = std::stold(text);
  } catch (...) {
    return std::nullopt;
  }
  return number;
}

/// \brief Prints a given floating-point number as a string. Prints enough digits to represent the
/// number exactly. The printed number of digits depends on the type of the floating-point number.
template <typename Number>
[[nodiscard]] inline std::string Print(const Number value) {
  static_assert(
      std::is_floating_point<Number>::value,
      "The Number template parameter of PhQ::Print<Number> must be a floating-point number type.");
  const Number absolute{std::abs(value)};
  std::ostringstream stream;
  if (absolute < 1.0) {
    // Interval: [0, 1[
    if (absolute < 0.001) {
      // Interval: [0, 0.001[
      if (absolute == 0.0) {
        // Interval: [0, 0]
        stream << 0;
      } else {
        // Interval: ]0, 0.001[
        stream << std::scientific << std::setprecision(std::numeric_limits<Number>::max_digits10)
               << value;
      }
    } else {
      // Interval: [0.001, 1[
      if (absolute < 0.1) {
        // Interval: [0.001, 0.1[
        if (absolute < 0.01) {
          // Interval: [0.001, 0.01[
          stream << std::fixed << std::setprecision(std::numeric_limits<Number>::max_digits10 + 3)
                 << value;
        } else {
          // Interval: [0.01, 0.1[
          stream << std::fixed << std::setprecision(std::numeric_limits<Number>::max_digits10 + 2)
                 << value;
        }
      } else {
        // Interval: [0.1, 1[
        stream << std::fixed << std::setprecision(std::numeric_limits<Number>::max_digits10 + 1)
               << value;
      }
    }
  } else {
    // Interval: [1, +inf[
    if (absolute < 1000.0) {
      // Interval: [1, 1000[
      if (absolute < 10.0) {
        // Interval: [1, 10[
        stream << std::fixed << std::setprecision(std::numeric_limits<Number>::max_digits10)
               << value;
      } else {
        // Interval: [10, 1000[
        if (absolute < 100.0) {
          // Interval: [10, 100[
          stream << std::fixed << std::setprecision(std::numeric_limits<Number>::max_digits10 - 1)
                 << value;
        } else {
          // Interval: [100, 1000[
          stream << std::fixed << std::setprecision(std::numeric_limits<Number>::max_digits10 - 2)
                 << value;
        }
      }
    } else {
      // Interval: [1000, +inf[
      if (absolute < 10000.0) {
        // Interval: [1000, 10000[
        stream << std::fixed << std::setprecision(std::numeric_limits<Number>::max_digits10 - 3)
               << value;
      } else {
        // Interval: [10000, +inf[
        stream << std::scientific << std::setprecision(std::numeric_limits<Number>::max_digits10)
               << value;
      }
    }
  }
  return stream.str();
}

/// \brief Replaces all occurrences of a given character in a given string with a different given
/// character.
inline void Replace(std::string& text, const char from, const char to) {
  std::replace(text.begin(), text.end(), from, to);
}

/// \brief Returns a copy of a given string where all occurrences of a given character have been
/// replaced with a different given character.
[[nodiscard]] inline std::string ReplaceCopy(
    const std::string_view text, const char from, const char to) {
  std::string result{text};
  std::replace_copy(text.cbegin(), text.cend(), result.begin(), from, to);
  return result;
}

/// \brief Transforms a given string into snake case; that is, all characters are lowercase and all
/// spaces are replaced with underscores.
inline void SnakeCase(std::string& text) {
  Lowercase(text);
  Replace(text, ' ', '_');
}

/// \brief Returns a copy of a given string in snake case; that is, all characters are lowercase and
/// all spaces are replaced with underscores.
[[nodiscard]] inline std::string SnakeCaseCopy(const std::string_view text) {
  return LowercaseCopy(ReplaceCopy(text, ' ', '_'));
}

/// \brief Splits a given string by whitespace and returns the collection of resulting strings.
[[nodiscard]] inline std::vector<std::string> SplitByWhitespace(const std::string& text) {
  std::istringstream stream{text};
  std::vector<std::string> words{
      std::istream_iterator<std::string>{stream}, std::istream_iterator<std::string>{}};
  return words;
}

/// \brief Transforms a given string such that all of its characters are uppercase.
inline void Uppercase(std::string& text) {
  std::transform(text.begin(), text.end(), text.begin(), [](int character) {
    return std::toupper(character);
  });
}

/// \brief Returns a copy of a given string where all characters are uppercase.
[[nodiscard]] inline std::string UppercaseCopy(const std::string_view text) {
  std::string result{text};
  std::transform(result.begin(), result.end(), result.begin(), [](int character) {
    return std::toupper(character);
  });
  return result;
}

}  // namespace PhQ

#endif  // PHQ_BASE_HPP
