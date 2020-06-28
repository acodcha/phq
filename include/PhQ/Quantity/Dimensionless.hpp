// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Base.hpp"

namespace PhQ {

class DimensionlessQuantity : public Quantity {

public:

  constexpr Dimension::Set dimension() const noexcept {
    return {};
  }

  virtual std::string print() const noexcept = 0;

  virtual std::string json() const noexcept = 0;

  virtual std::string xml() const noexcept = 0;

protected:

  constexpr DimensionlessQuantity() noexcept : Quantity() {}

};

std::ostream& operator<<(std::ostream& stream, const DimensionlessQuantity& quantity) noexcept {
  stream << quantity.print();
  return stream;
}

} // namespace PhQ
