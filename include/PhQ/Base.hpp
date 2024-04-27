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
#include <cstddef>
#include <cstdint>
#include <iomanip>
#include <iterator>
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

// The mathematical constant π = 3.14... expressed as a double-precision floating-point number. This
// value is as accurate as possible given the IEEE 754 floating-point arithmetic standard.
inline constexpr double Pi{3.14159265358979323846};

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

// Precision used when printing a floating-point number as a string. All floating-point numbers in
// this library use double precision. However, when printing a floating-point number as a string,
// double precision is not always needed; sometimes, single precision is sufficient.
enum class Precision : int8_t {
  // Double floating point precision
  Double,

  // Single floating point precision
  Single,
};

namespace Internal {

template <>
inline const std::map<Precision, std::string_view> Abbreviations<Precision>{
    {Precision::Double, "Double"},
    {Precision::Single, "Single"},
};

template <>
inline const std::unordered_map<std::string_view, Precision> Spellings<Precision>{
    {"DOUBLE", Precision::Double},
    {"Double", Precision::Double},
    {"double", Precision::Double},
    {"SINGLE", Precision::Single},
    {"Single", Precision::Single},
    {"single", Precision::Single},
};

}  // namespace Internal

// Transforms a given string such that all of its characters are lowercase.
inline void Lowercase(std::string& text) {
  std::transform(text.begin(), text.end(), text.begin(), [](int character) {
    return std::tolower(character);
  });
}

// Returns a copy of a given string where all characters are lowercase.
inline std::string LowercaseCopy(const std::string_view text) {
  std::string result{text};
  std::transform(result.begin(), result.end(), result.begin(), [](int character) {
    return std::tolower(character);
  });
  return result;
}

// Parses a given string into an integer. Returns the integer, or std::nullopt if the string cannot
// be parsed into an integer.
inline std::optional<int64_t> ParseToInteger(const std::string& text) {
  char* end{nullptr};
  const int64_t value{std::strtoll(text.c_str(), &end, 10)};
  if (end != text.c_str() && *end == '\0' && value != LLONG_MAX && value != LLONG_MIN) {
    return {static_cast<int64_t>(value)};
  }
  return std::nullopt;
}

// Parses a given string into a double-precision floating-point number. Returns the number, or
// std::nullopt if the string cannot be parsed into a double-precision floating-point number.
inline std::optional<double> ParseToDouble(const std::string& text) {
  char* end{nullptr};
  const double value{strtod(text.c_str(), &end)};
  if (end != text.c_str() && *end == '\0' && value != HUGE_VAL && value != -HUGE_VAL) {
    return {value};
  }
  return std::nullopt;
}

// Prints a given floating point number as a string to a given floating point precision. If no
// precision is specified, double precision is used by default.
inline std::string Print(const double value, const Precision precision = Precision::Double) {
  const double absolute{std::abs(value)};
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

// Replaces all occurrences of a given character in a given string with a different given character.
inline void Replace(std::string& text, const char from, const char to) {
  std::replace(text.begin(), text.end(), from, to);
}

// Returns a copy of a given string where all occurrences of a given character have been replaced
// with a different given character.
inline std::string ReplaceCopy(const std::string_view text, const char from, const char to) {
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
inline std::string SnakeCaseCopy(const std::string_view text) {
  return LowercaseCopy(ReplaceCopy(text, ' ', '_'));
}

// Splits a given string by whitespace and returns the collection of resulting strings.
inline std::vector<std::string> SplitByWhitespace(const std::string& text) {
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
inline std::string UppercaseCopy(const std::string_view text) {
  std::string result{text};
  std::transform(result.begin(), result.end(), result.begin(), [](int character) {
    return std::toupper(character);
  });
  return result;
}

}  // namespace PhQ

#endif  // PHQ_BASE_HPP
