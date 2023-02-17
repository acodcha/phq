// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_TEMPERATURE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_TEMPERATURE_HPP

#include <iostream>

#include "Base.hpp"

namespace PhQ::Dimension {

class Temperature : public Base {
public:
  constexpr Temperature() noexcept : Base() {}

  explicit constexpr Temperature(const int_least8_t value) noexcept : Base(value) {}

  static std::string_view abbreviation() noexcept {
    return "Θ";
  }

  static std::string_view label() noexcept {
    return "Temperature";
  }

  std::string print() const noexcept override {
    return Base::print(abbreviation());
  }
};

inline constexpr bool operator==(const Temperature& left, const Temperature& right) noexcept {
  return left.value() == right.value();
}

inline constexpr bool operator!=(const Temperature& left, const Temperature& right) noexcept {
  return left.value() != right.value();
}

inline constexpr bool operator<(const Temperature& left, const Temperature& right) noexcept {
  return left.value() < right.value();
}

inline constexpr bool operator>(const Temperature& left, const Temperature& right) noexcept {
  return left.value() > right.value();
}

inline constexpr bool operator<=(const Temperature& left, const Temperature& right) noexcept {
  return left.value() <= right.value();
}

inline constexpr bool operator>=(const Temperature& left, const Temperature& right) noexcept {
  return left.value() >= right.value();
}

inline std::ostream& operator<<(std::ostream& output_stream, const Temperature& temperature) noexcept {
  output_stream << temperature.print();
  return output_stream;
}

}  // namespace PhQ::Dimension

namespace std {

template <> struct hash<PhQ::Dimension::Temperature> {
  size_t operator()(const PhQ::Dimension::Temperature& temperature) const {
    return hash<int_least8_t>()(temperature.value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_TEMPERATURE_HPP
