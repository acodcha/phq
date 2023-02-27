// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONAL_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONAL_HPP

#include "../Unit/Base.hpp"
#include "Base.hpp"

namespace PhQ {

template <typename Unit>
class DimensionalQuantity : public Quantity {
public:
  virtual ~DimensionalQuantity() noexcept = default;

  static constexpr const Dimension::Set& Dimension() const noexcept {
    return Dimensions<Unit>;
  }

  static constexpr Unit Unit() const noexcept { return StandardUnit<Unit>; }

  virtual std::string Print() const noexcept = 0;

  virtual std::string Print(const Unit unit) const noexcept = 0;

  virtual std::string Json() const noexcept = 0;

  virtual std::string Json(const Unit unit) const noexcept = 0;

  virtual std::string Xml() const noexcept = 0;

  virtual std::string Xml(const Unit unit) const noexcept = 0;

  virtual std::string Yaml() const noexcept = 0;

  virtual std::string Yaml(const Unit unit) const noexcept = 0;

protected:
  constexpr DimensionalQuantity() noexcept : Quantity() {}
};

template <typename Unit>
std::ostream& operator<<(std::ostream& stream,
                         const DimensionalQuantity<Unit>& quantity) noexcept {
  stream << quantity.Print();
  return stream;
}

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_DIMENSIONAL_HPP
