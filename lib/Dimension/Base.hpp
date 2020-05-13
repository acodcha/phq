// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of PhysicalQuantities, a C++17 library of physical quantities, units of measure, and related concepts for scientific computation.
// PhysicalQuantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// PhysicalQuantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with PhysicalQuantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../Base/String.hpp"

namespace PhQ {

namespace Dimension {

class Base {

public:

  constexpr int_least8_t value() const noexcept {
    return value_;
  }

  virtual std::string abbreviation() const noexcept = 0;

  std::string print() const noexcept {
    if (value_ == 0) {
      return {};
    } else if (value_ == 1) {
      return abbreviation();
    } else if (value_ > 0) {
      return abbreviation() + "^" + std::to_string(value_);
    } else {
      return abbreviation() + "^(" + std::to_string(value_) + ")";
    }
  }

  constexpr bool operator==(const Base& base) const noexcept {
    return value_ == base.value_;
  }

  constexpr bool operator!=(const Base& base) const noexcept {
    return value_ != base.value_;
  }

  constexpr bool operator<(const Base& base) const noexcept {
    return value_ < base.value_;
  }

  constexpr bool operator<=(const Base& base) const noexcept {
    return value_ <= base.value_;
  }

  constexpr bool operator>(const Base& base) const noexcept {
    return value_ > base.value_;
  }

  constexpr bool operator>=(const Base& base) const noexcept {
    return value_ >= base.value_;
  }

protected:

  constexpr Base(int_least8_t value = 0) noexcept : value_(value) {}

  int_least8_t value_;

};

} // namespace Dimension

} // namespace PhQ

std::ostream& operator<<(std::ostream& output_stream, const PhQ::Dimension::Base& base) noexcept {
  output_stream << base.print();
  return output_stream;
}
