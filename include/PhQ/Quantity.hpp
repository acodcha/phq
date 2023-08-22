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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_HPP

#include "Base/Precision.hpp"

namespace PhQ {

// Abstract base class that represents any physical quantity.
class Quantity {
public:
  virtual std::string Print() const noexcept = 0;

  virtual std::string Print(const Precision precision) const noexcept = 0;

  virtual std::string JSON() const noexcept = 0;

  virtual std::string XML() const noexcept = 0;

  virtual std::string YAML() const noexcept = 0;

protected:
  constexpr Quantity() noexcept = default;

  ~Quantity() noexcept = default;
};

}  // namespace PhQ

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_QUANTITY_HPP
