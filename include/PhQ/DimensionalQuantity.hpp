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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONAL_QUANTITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONAL_QUANTITY_HPP

#include "Quantity.hpp"
#include "Unit/Base.hpp"

namespace PhQ {

// Abstract base class that represents any dimensional physical quantity.
template<typename U> class DimensionalQuantity : public Quantity {
public:
  static constexpr const Dimension::Set& Dimension() noexcept {
    return Dimensions<U>;
  }

  static constexpr U Unit() noexcept { return Standard<U>; }

  virtual std::string Print(const U unit) const noexcept = 0;

  virtual std::string Print(
      const U unit, const Precision precision) const noexcept = 0;

  virtual std::string JSON(const U unit) const noexcept = 0;

  virtual std::string XML(const U unit) const noexcept = 0;

  virtual std::string YAML(const U unit) const noexcept = 0;

protected:
  constexpr DimensionalQuantity() noexcept : Quantity() {}

  ~DimensionalQuantity() noexcept = default;
};

template<typename U> inline std::ostream& operator<<(
    std::ostream& stream, const DimensionalQuantity<U>& quantity) noexcept {
  stream << quantity.Print();
  return stream;
}

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_DIMENSIONAL_QUANTITY_HPP
