// Copyright 2020-2023 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "../Unit/Base.hpp"
#include "Base.hpp"

namespace PhQ {

template <typename Unit> class DimensionalQuantity : public Quantity {

public:

  constexpr Dimension::Set dimension() const noexcept {
    return PhQ::dimension<Unit>;
  }

  constexpr Unit unit() const noexcept {
    return standard_unit<Unit>;
  }

  virtual std::string print() const noexcept = 0;

  virtual std::string print(Unit unit) const noexcept = 0;

  virtual std::string print(System system) const noexcept = 0;

  virtual std::string json() const noexcept = 0;

  virtual std::string json(Unit unit) const noexcept = 0;

  virtual std::string json(System system) const noexcept = 0;

  virtual std::string xml() const noexcept = 0;

  virtual std::string xml(Unit unit) const noexcept = 0;

  virtual std::string xml(System system) const noexcept = 0;

protected:

  constexpr DimensionalQuantity() noexcept : Quantity() {}

};

template <typename Unit> std::ostream& operator<<(std::ostream& stream, const DimensionalQuantity<Unit>& quantity) noexcept {
  stream << quantity.print();
  return stream;
}

} // namespace PhQ
