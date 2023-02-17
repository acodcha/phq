// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_LUMINOUSINTENSITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_LUMINOUSINTENSITY_HPP

#include <iostream>

#include "Base.hpp"

namespace PhQ::Dimension {

class LuminousIntensity : public Base {
public:
  constexpr LuminousIntensity() noexcept : Base() {}

  explicit constexpr LuminousIntensity(const int_least8_t value) noexcept : Base(value) {}

  static std::string_view abbreviation() noexcept {
    return "J";
  }

  static std::string_view label() noexcept {
    return "Luminous Intensity";
  }

  std::string print() const noexcept override {
    return Base::print(abbreviation());
  }
};

inline constexpr bool operator==(const LuminousIntensity& left, const LuminousIntensity& right) noexcept {
  return left.value() == right.value();
}

inline constexpr bool operator!=(const LuminousIntensity& left, const LuminousIntensity& right) noexcept {
  return left.value() != right.value();
}

inline constexpr bool operator<(const LuminousIntensity& left, const LuminousIntensity& right) noexcept {
  return left.value() < right.value();
}

inline constexpr bool operator>(const LuminousIntensity& left, const LuminousIntensity& right) noexcept {
  return left.value() > right.value();
}

inline constexpr bool operator<=(const LuminousIntensity& left, const LuminousIntensity& right) noexcept {
  return left.value() <= right.value();
}

inline constexpr bool operator>=(const LuminousIntensity& left, const LuminousIntensity& right) noexcept {
  return left.value() >= right.value();
}

inline std::ostream& operator<<(std::ostream& output_stream, const LuminousIntensity& luminous_intensity) noexcept {
  output_stream << luminous_intensity.print();
  return output_stream;
}

}  // namespace PhQ::Dimension

namespace std {

template <> struct hash<PhQ::Dimension::LuminousIntensity> {
  size_t operator()(const PhQ::Dimension::LuminousIntensity& luminous_intensity) const {
    return hash<int_least8_t>()(luminous_intensity.value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_LUMINOUSINTENSITY_HPP
