// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Include.hpp"

namespace PhQ {

std::string number_to_string(double value) noexcept {
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

std::optional<uint_least64_t> string_to_natural_number(const std::string& text) noexcept {
  char* end = 0;
  const unsigned long long int value = std::strtoull(text.c_str(), &end, 10);
  if (end != text.c_str() && *end == '\0' && value != ULLONG_MAX) {
    return {(uint_least64_t)(value)};
  }
  const std::optional<uint_least64_t> no_value;
  return no_value;
}

std::optional<int_least64_t> string_to_integer_number(const std::string& text) noexcept {
  char* end = 0;
  const long long int value = std::strtoll(text.c_str(), &end, 10);
  if (end != text.c_str() && *end == '\0' && value != LLONG_MAX) {
    return {(int_least64_t)(value)};
  }
  const std::optional<int_least64_t> no_value;
  return no_value;
}

std::optional<double> string_to_real_number(const std::string& text) noexcept {
  char* end = 0;
  const double value = strtod(text.c_str(), &end);
  if (end != text.c_str() && *end == '\0' && value != HUGE_VAL && value != -HUGE_VAL) {
    return {value};
  }
  const std::optional<double> no_value;
  return no_value;
}

std::string lowercase(const std::string& text) noexcept {
  std::string data{text};
  std::transform(data.begin(), data.end(), data.begin(), [](unsigned char character){return std::tolower(character);});
  return data;
}

std::string uppercase(const std::string& text) noexcept {
  std::string data{text};
  std::transform(data.begin(), data.end(), data.begin(), [](unsigned char character){return std::toupper(character);});
  return data;
}

std::vector<std::string> split_by_whitespace(const std::string& text) noexcept {
  std::istringstream stream{text};
  std::vector<std::string> words{std::istream_iterator<std::string>{stream}, std::istream_iterator<std::string>{}};
  return words;
}

} // namespace PhQ
