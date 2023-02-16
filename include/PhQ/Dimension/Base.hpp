// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_BASE_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_BASE_HPP

#include <string>
#include <string_view>

namespace PhQ::Dimension {

class Base {
public:
  virtual ~Base() = default;

  inline constexpr int_least8_t value() const noexcept {
    return value_;
  }

  virtual std::string print() const noexcept = 0;

protected:
  explicit constexpr Base(const int_least8_t value = 0) noexcept : value_(value) {}

  std::string print(const std::string_view abbreviation) const noexcept {
    if (value_ == 0) {
      return {};
    }
    std::string text{abbreviation};
    if (value_ > 1) {
      text.append("^" + std::to_string(value_));
    } else if (value_ < 0) {
      text.append("^(" + std::to_string(value_) + ")");
    }
    return text;
  }

  int_least8_t value_;
};

}  // namespace PhQ::Dimension

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSION_BASE_HPP
