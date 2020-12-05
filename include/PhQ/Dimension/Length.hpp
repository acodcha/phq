// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

namespace Dimension {

class Length : public Base {

public:

  constexpr Length(int_least8_t value = 0) noexcept : Base(value) {}

  std::string abbreviation() const noexcept {
    return "L";
  }

  std::string label() const noexcept {
    return "length";
  }

};

} // namespace Dimension

template <> constexpr bool sort(const Dimension::Length& length_1, const Dimension::Length& length_2) noexcept {
  return length_1 < length_2;
}

} // namespace PhQ

namespace std {

template <> struct hash<PhQ::Dimension::Length> {
  size_t operator()(const PhQ::Dimension::Length& length) const {
    return hash<double>()(length.value());
  }
};

} // namespace std
