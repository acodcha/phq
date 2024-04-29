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

#ifndef PHQ_BASE_HPP
#define PHQ_BASE_HPP

#include <algorithm>
#include <climits>
#include <cmath>
#include <concepts>
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
#include <unordered_map>
#include <utility>
#include <vector>

// Namespace that encompasses all of the Physical Quantities library's content.
namespace PhQ {

// Namespace that contains internal implementation details of the Physical Quantities library.
// Contents within this namespace are not meant to be used except by the the Physical Quantities
// library's own functions and classes.
namespace Internal {

// Map of enumerations to their corresponding abbreviations. This is an internal implementation
// detail and is not intended to be used except by the PhQ::Abbreviation function.
template <typename Enumeration>
inline const std::map<Enumeration, std::string_view> Abbreviations;

}  // namespace Internal

// Returns the abbreviation of a given enumeration value. For example,
// PhQ::Abbreviation(PhQ::Unit::Time::Hour) returns "hr".
template <typename Enumeration>
inline std::string_view Abbreviation(const Enumeration enumeration) {
  return Internal::Abbreviations<Enumeration>.find(enumeration)->second;
}

namespace Internal {

// Map of spellings to their corresponding enumeration values. This is an internal implementation
// detail and is not intended to be used except by the PhQ::Parse function.
template <typename Enumeration>
inline const std::unordered_map<std::string_view, Enumeration> Spellings;

}  // namespace Internal

// Attempts to parse some given text into an enumeration. Returns the enumeration if one is found,
// or std::nullopt otherwise. For example, PhQ::Parse<PhQ::Unit::Time>("hr") returns
// PhQ::Unit::Time::Hour.
template <typename Enumeration>
std::optional<Enumeration> Parse(const std::string_view spelling) {
  const typename std::unordered_map<std::string_view, Enumeration>::const_iterator found{
      Internal::Spellings<Enumeration>.find(spelling)};
  if (found != Internal::Spellings<Enumeration>.cend()) {
    return found->second;
  }
  return std::nullopt;
}

// Precision used when printing a floating-point number as a string. This library supports
// computations using various floating-point number types. When printing a floating-point number as
// a string, it may be printed as a different type for convenience.
enum class Precision : int8_t {
  // Single floating-point precision. Corresponds to a 32-bit binary floating-point number, such as
  // "float". Results in 6 decimal digits of precision.
  Single,

  // Double floating-point precision. Corresponds to a 64-bit binary floating-point number, such as
  // "double". Results in 15 decimal digits of precision.
  Double,

  // Triple floating-point precision. Corresponds to an 80-bit binary floating-point number, such as
  // "long double" on certain systems. Results in 18 decimal digits of precision.
  Triple,

  // Quadruple floating-point precision. Corresponds to a 128-bit binary floating-point number, such
  // as "long double" on certain systems. Results in 33 decimal digits of precision.
  Quadruple,
};

namespace Internal {

template <>
inline const std::map<Precision, std::string_view> Abbreviations<Precision>{
    {Precision::Single,    "Single"   },
    {Precision::Double,    "Double"   },
    {Precision::Triple,    "Triple"   },
    {Precision::Quadruple, "Quadruple"},
};

template <>
inline const std::unordered_map<std::string_view, Precision> Spellings<Precision>{
    {"SINGLE",    Precision::Single   },
    {"Single",    Precision::Single   },
    {"single",    Precision::Single   },
    {"DOUBLE",    Precision::Double   },
    {"Double",    Precision::Double   },
    {"double",    Precision::Double   },
    {"TRIPLE",    Precision::Triple   },
    {"Triple",    Precision::Triple   },
    {"triple",    Precision::Triple   },
    {"QUADRUPLE", Precision::Quadruple},
    {"Quadruple", Precision::Quadruple},
    {"quadruple", Precision::Quadruple},
};

}  // namespace Internal

// Transforms a given string such that all of its characters are lowercase.
inline void Lowercase(std::string& text) {
  std::transform(text.begin(), text.end(), text.begin(), [](int character) {
    return std::tolower(character);
  });
}

// Returns a copy of a given string where all characters are lowercase.
[[nodiscard]] inline std::string LowercaseCopy(const std::string_view text) {
  std::string result{text};
  std::transform(result.begin(), result.end(), result.begin(), [](int character) {
    return std::tolower(character);
  });
  return result;
}

template <typename Type>
concept NumericType = std::integral<Type> || std::floating_point<Type>;

template <NumericType Number>
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

// Prints a given floating-point number as a string. Prints enough digits to represent the number
// exactly. The printed number of digits depends on the type of the floating-point number.
template <std::floating_point FloatingPointType>
[[nodiscard]] inline std::string Print(const FloatingPointType value) {
  const FloatingPointType absolute{std::abs(value)};
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
        stream << std::scientific
               << std::setprecision(std::numeric_limits<FloatingPointType>::max_digits10) << value;
      }
    } else {
      // Interval: [0.001, 1[
      if (absolute < 0.1) {
        // Interval: [0.001, 0.1[
        if (absolute < 0.01) {
          // Interval: [0.001, 0.01[
          stream << std::fixed
                 << std::setprecision(std::numeric_limits<FloatingPointType>::max_digits10 + 3)
                 << value;
        } else {
          // Interval: [0.01, 0.1[
          stream << std::fixed
                 << std::setprecision(std::numeric_limits<FloatingPointType>::max_digits10 + 2)
                 << value;
        }
      } else {
        // Interval: [0.1, 1[
        stream
            << std::fixed
            << std::setprecision(std::numeric_limits<FloatingPointType>::max_digits10 + 1) << value;
      }
    }
  } else {
    // Interval: [1, +inf[
    if (absolute < 1000.0) {
      // Interval: [1, 1000[
      if (absolute < 10.0) {
        // Interval: [1, 10[
        stream << std::fixed
               << std::setprecision(std::numeric_limits<FloatingPointType>::max_digits10) << value;
      } else {
        // Interval: [10, 1000[
        if (absolute < 100.0) {
          // Interval: [10, 100[
          stream << std::fixed
                 << std::setprecision(std::numeric_limits<FloatingPointType>::max_digits10 - 1)
                 << value;
        } else {
          // Interval: [100, 1000[
          stream << std::fixed
                 << std::setprecision(std::numeric_limits<FloatingPointType>::max_digits10 - 2)
                 << value;
        }
      }
    } else {
      // Interval: [1000, +inf[
      if (absolute < 10000.0) {
        // Interval: [1000, 10000[
        stream
            << std::fixed
            << std::setprecision(std::numeric_limits<FloatingPointType>::max_digits10 - 3) << value;
      } else {
        // Interval: [10000, +inf[
        stream << std::scientific
               << std::setprecision(std::numeric_limits<FloatingPointType>::max_digits10) << value;
      }
    }
  }
  return stream.str();
}

// Replaces all occurrences of a given character in a given string with a different given character.
inline void Replace(std::string& text, const char from, const char to) {
  std::replace(text.begin(), text.end(), from, to);
}

// Returns a copy of a given string where all occurrences of a given character have been replaced
// with a different given character.
[[nodiscard]] inline std::string ReplaceCopy(
    const std::string_view text, const char from, const char to) {
  std::string result{text};
  std::replace_copy(text.cbegin(), text.cend(), result.begin(), from, to);
  return result;
}

// Transforms a given string into snake case; that is, all characters are lowercase and all spaces
// are replaced with underscores.
inline void SnakeCase(std::string& text) {
  Lowercase(text);
  Replace(text, ' ', '_');
}

// Returns a copy of a given string in snake case; that is, all characters are lowercase and all
// spaces are replaced with underscores.
[[nodiscard]] inline std::string SnakeCaseCopy(const std::string_view text) {
  return LowercaseCopy(ReplaceCopy(text, ' ', '_'));
}

// Splits a given string by whitespace and returns the collection of resulting strings.
[[nodiscard]] inline std::vector<std::string> SplitByWhitespace(const std::string& text) {
  std::istringstream stream{text};
  std::vector<std::string> words{
      std::istream_iterator<std::string>{stream}, std::istream_iterator<std::string>{}};
  return words;
}

// Transforms a given string such that all of its characters are uppercase.
inline void Uppercase(std::string& text) {
  std::transform(text.begin(), text.end(), text.begin(), [](int character) {
    return std::toupper(character);
  });
}

// Returns a copy of a given string where all characters are uppercase.
[[nodiscard]] inline std::string UppercaseCopy(const std::string_view text) {
  std::string result{text};
  std::transform(result.begin(), result.end(), result.begin(), [](int character) {
    return std::toupper(character);
  });
  return result;
}

}  // namespace PhQ

#endif  // PHQ_BASE_HPP
