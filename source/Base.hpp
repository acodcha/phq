#pragma once

#include <algorithm>
#include <array>
#include <cctype>
#include <climits>
#include <chrono>
#include <cmath>
#include <cstdlib>
#include <experimental/filesystem>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <optional>
#include <random>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <thread>
#include <unordered_map>
#include <vector>

// Define M_PI if it has not been defined by the compiler.
#ifndef M_PI
  #define M_PI (3.14159265358979323846)
#endif

namespace PhQ {

std::string real_number_to_string(double value) noexcept {
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
