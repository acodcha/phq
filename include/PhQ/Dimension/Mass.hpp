// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_MASS_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_MASS_HPP

#include <iostream>

#include "Base.hpp"

namespace PhQ::Dimension {

class Mass : public Base {
public:
  constexpr Mass() noexcept : Base() {}

  explicit constexpr Mass(const int_least8_t value) noexcept : Base(value) {}

  static std::string_view abbreviation() noexcept {
    return "M";
  }

  static std::string_view label() noexcept {
    return "Mass";
  }

  std::string print() const noexcept override {
    return Base::print(abbreviation());
  }
};

inline constexpr bool operator==(const Mass& left, const Mass& right) noexcept {
  return left.value() == right.value();
}

inline constexpr bool operator!=(const Mass& left, const Mass& right) noexcept {
  return left.value() != right.value();
}

inline constexpr bool operator<(const Mass& left, const Mass& right) noexcept {
  return left.value() < right.value();
}

inline constexpr bool operator>(const Mass& left, const Mass& right) noexcept {
  return left.value() > right.value();
}

inline constexpr bool operator<=(const Mass& left, const Mass& right) noexcept {
  return left.value() <= right.value();
}

inline constexpr bool operator>=(const Mass& left, const Mass& right) noexcept {
  return left.value() >= right.value();
}

inline std::ostream& operator<<(std::ostream& output_stream, const Mass& mass) noexcept {
  output_stream << mass.print();
  return output_stream;
}

}  // namespace PhQ::Dimension

namespace std {

template <> struct hash<PhQ::Dimension::Mass> {
  size_t operator()(const PhQ::Dimension::Mass& mass) const {
    return hash<int_least8_t>()(mass.value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_MASS_HPP
