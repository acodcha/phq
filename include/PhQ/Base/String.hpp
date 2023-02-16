// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

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

void lowercase(std::string& text) noexcept {
  std::transform(text.begin(), text.end(), text.begin(), [](int character) { return std::tolower(character); });
}

std::string lowercase_copy(const std::string_view text) noexcept {
  std::string result{text};
  std::transform(result.begin(), result.end(), result.begin(), [](int character) { return std::tolower(character); });
  return result;
}

std::string number_to_string(const double value) noexcept {
  if (value == 0.0) {
    return {"0"};
  } else {
    const double absolute_value{std::abs(value)};
    std::ostringstream stream;
    if (absolute_value >= 10000.0 || absolute_value < 0.001) {
      stream << std::scientific << value;
      return stream.str();
    } else if (absolute_value >= 1000.0) {
      stream << std::fixed << std::setprecision(3) << value;
      return stream.str();
    } else if (absolute_value >= 100.0) {
      stream << std::fixed << std::setprecision(4) << value;
      return stream.str();
    } else if (absolute_value >= 10.0) {
      stream << std::fixed << std::setprecision(5) << value;
      return stream.str();
    } else if (absolute_value >= 1.0) {
      stream << std::fixed << std::setprecision(6) << value;
      return stream.str();
    } else if (absolute_value >= 0.1) {
      stream << std::fixed << std::setprecision(7) << value;
      return stream.str();
    } else if (absolute_value >= 0.01) {
      stream << std::fixed << std::setprecision(8) << value;
      return stream.str();
    } else {
      stream << std::fixed << std::setprecision(9) << value;
      return stream.str();
    }
  }
}

void replace(std::string& text, const char from, const char to) noexcept {
  std::replace(text.begin(), text.end(), from, to);
}

std::string replace_copy(const std::string_view text, const char from, const char to) noexcept {
  std::string result{text};
  std::replace_copy(text.cbegin(), text.cend(), result.begin(), from, to);
  return result;
}

void snake_case(std::string& text) noexcept {
  lowercase(text);
  replace(text, ' ', '_');
}

std::string snake_case_copy(const std::string_view text) noexcept {
  return lowercase_copy(replace_copy(text, ' ', '_'));
}

std::vector<std::string> split_by_whitespace(const std::string& text) noexcept {
  std::istringstream stream{text};
  std::vector<std::string> words{std::istream_iterator<std::string>{stream}, std::istream_iterator<std::string>{}};
  return words;
}

std::optional<int_least64_t> string_to_integer_number(const std::string& text) noexcept {
  char* end = 0;
  const long long int value = std::strtoll(text.c_str(), &end, 10);
  if (end != text.c_str() && *end == '\0' && value != LLONG_MAX) {
    return {static_cast<int_least64_t>(value)};
  }
  return std::nullopt;
}

std::optional<double> string_to_real_number(const std::string& text) noexcept {
  char* end = 0;
  const double value = strtod(text.c_str(), &end);
  if (end != text.c_str() && *end == '\0' && value != HUGE_VAL && value != -HUGE_VAL) {
    return {value};
  }
  return std::nullopt;
}

void uppercase(std::string& text) noexcept {
  std::transform(text.begin(), text.end(), text.begin(), [](int character) { return std::toupper(character); });
}

std::string uppercase_copy(const std::string_view text) noexcept {
  std::string result{text};
  std::transform(result.begin(), result.end(), result.begin(), [](int character) { return std::toupper(character); });
  return result;
}

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_BASE_STRING_HPP
