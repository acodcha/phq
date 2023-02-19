// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_ELECTRICCURRENT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_ELECTRICCURRENT_HPP

#include <iostream>
#include <string>
#include <string_view>

namespace PhQ::Dimension {

class ElectricCurrent {
public:
  constexpr ElectricCurrent() noexcept : value_(0) {}

  explicit constexpr ElectricCurrent(const int_least8_t value) noexcept : value_(value) {}

  inline constexpr int_least8_t value() const noexcept {
    return value_;
  }

  static std::string_view abbreviation() noexcept {
    return "I";
  }

  static std::string_view label() noexcept {
    return "Electric Current";
  }

  std::string print() const noexcept {
    if (value_ == 0) {
      return {};
    }
    std::string text{abbreviation()};
    if (value_ >= 2) {
      text.append("^" + std::to_string(value_));
    } else if (value_ <= -1) {
      text.append("^(" + std::to_string(value_) + ")");
    }
    return text;
  }

private:
  int_least8_t value_;
};

inline constexpr bool operator==(const ElectricCurrent& left, const ElectricCurrent& right) noexcept {
  return left.value() == right.value();
}

inline constexpr bool operator!=(const ElectricCurrent& left, const ElectricCurrent& right) noexcept {
  return left.value() != right.value();
}

inline constexpr bool operator<(const ElectricCurrent& left, const ElectricCurrent& right) noexcept {
  return left.value() < right.value();
}

inline constexpr bool operator>(const ElectricCurrent& left, const ElectricCurrent& right) noexcept {
  return left.value() > right.value();
}

inline constexpr bool operator<=(const ElectricCurrent& left, const ElectricCurrent& right) noexcept {
  return left.value() <= right.value();
}

inline constexpr bool operator>=(const ElectricCurrent& left, const ElectricCurrent& right) noexcept {
  return left.value() >= right.value();
}

inline std::ostream& operator<<(std::ostream& output_stream, const ElectricCurrent& electric_current) noexcept {
  output_stream << electric_current.print();
  return output_stream;
}

}  // namespace PhQ::Dimension

namespace std {

template <> struct hash<PhQ::Dimension::ElectricCurrent> {
  size_t operator()(const PhQ::Dimension::ElectricCurrent& electric_current) const {
    return hash<int_least8_t>()(electric_current.value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_ELECTRICCURRENT_HPP
