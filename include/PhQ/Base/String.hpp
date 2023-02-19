// Copyright 2020 Alexandre Coderre-Chabot
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

namespace PhQ {

void LowerCase(std::string& text) noexcept {
  std::transform(text.begin(), text.end(), text.begin(),
                 [](int character) { return std::tolower(character); });
}

std::string LowerCaseCopy(const std::string_view text) noexcept {
  std::string result{text};
  std::transform(result.begin(), result.end(), result.begin(),
                 [](int character) { return std::tolower(character); });
  return result;
}

std::optional<int_least64_t> ParseToInteger(const std::string& text) noexcept {
  char* end = 0;
  const long long int value = std::strtoll(text.c_str(), &end, 10);
  if (end != text.c_str() && *end == '\0' && value != LLONG_MAX) {
    return {static_cast<int_least64_t>(value)};
  }
  return std::nullopt;
}

std::optional<double> ParseToDouble(const std::string& text) noexcept {
  char* end = 0;
  const double value = strtod(text.c_str(), &end);
  if (end != text.c_str() && *end == '\0' && value != HUGE_VAL &&
      value != -HUGE_VAL) {
    return {value};
  }
  return std::nullopt;
}

std::string Print(const double value) noexcept {
  if (value == 0.0) {
    return "0";
  }
  const double absolute{std::abs(value)};
  std::ostringstream stream;
  if (absolute >= 10000.0 || absolute < 0.001) {
    stream << std::scientific << std::setprecision(6) << value;
  } else if (absolute >= 1000.0) {
    stream << std::fixed << std::setprecision(3) << value;
  } else if (absolute >= 100.0) {
    stream << std::fixed << std::setprecision(4) << value;
  } else if (absolute >= 10.0) {
    stream << std::fixed << std::setprecision(5) << value;
  } else if (absolute >= 1.0) {
    stream << std::fixed << std::setprecision(6) << value;
  } else if (absolute >= 0.1) {
    stream << std::fixed << std::setprecision(7) << value;
  } else if (absolute >= 0.01) {
    stream << std::fixed << std::setprecision(8) << value;
  } else {
    stream << std::fixed << std::setprecision(9) << value;
  }
  return stream.str();
}

void Replace(std::string& text, const char from, const char to) noexcept {
  std::replace(text.begin(), text.end(), from, to);
}

std::string ReplaceCopy(const std::string_view text, const char from,
                        const char to) noexcept {
  std::string result{text};
  std::replace_copy(text.cbegin(), text.cend(), result.begin(), from, to);
  return result;
}

void SnakeCase(std::string& text) noexcept {
  LowerCase(text);
  Replace(text, ' ', '_');
}

std::string SnakeCaseCopy(const std::string_view text) noexcept {
  return LowerCaseCopy(ReplaceCopy(text, ' ', '_'));
}

std::vector<std::string> SplitByWhitespace(const std::string& text) noexcept {
  std::istringstream stream{text};
  std::vector<std::string> words{std::istream_iterator<std::string>{stream},
                                 std::istream_iterator<std::string>{}};
  return words;
}

void UpperCase(std::string& text) noexcept {
  std::transform(text.begin(), text.end(), text.begin(),
                 [](int character) { return std::toupper(character); });
}

std::string UpperCaseCopy(const std::string_view text) noexcept {
  std::string result{text};
  std::transform(result.begin(), result.end(), result.begin(),
                 [](int character) { return std::toupper(character); });
  return result;
}

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_STRING_HPP
