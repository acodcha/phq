// Copyright 2020 Alexandre Coderre-Chabot
// This file is part of Physical Quantities (PhQ), a C++17 header-only library of physical quantities, physical models, and units of measure for scientific computation.
// Physical Quantities is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
// Physical Quantities is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.
// You should have received a copy of the GNU Lesser General Public License along with Physical Quantities. If not, see <https://www.gnu.org/licenses/>.

#pragma once

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/DynamicViscosity.hpp"

namespace PhQ {

class BulkDynamicViscosity : public DimensionalScalarQuantity<Unit::DynamicViscosity> {

public:

  constexpr BulkDynamicViscosity() noexcept : DimensionalScalarQuantity<Unit::DynamicViscosity>() {}

  constexpr BulkDynamicViscosity(double value, Unit::DynamicViscosity unit) noexcept : DimensionalScalarQuantity<Unit::DynamicViscosity>(value, unit) {}

  constexpr bool operator==(const BulkDynamicViscosity& bulk_dynamic_viscosity) const noexcept {
    return value_ == bulk_dynamic_viscosity.value_;
  }

  constexpr bool operator!=(const BulkDynamicViscosity& bulk_dynamic_viscosity) const noexcept {
    return value_ != bulk_dynamic_viscosity.value_;
  }

  constexpr bool operator<(const BulkDynamicViscosity& bulk_dynamic_viscosity) const noexcept {
    return value_ < bulk_dynamic_viscosity.value_;
  }

  constexpr bool operator<=(const BulkDynamicViscosity& bulk_dynamic_viscosity) const noexcept {
    return value_ <= bulk_dynamic_viscosity.value_;
  }

  constexpr bool operator>(const BulkDynamicViscosity& bulk_dynamic_viscosity) const noexcept {
    return value_ > bulk_dynamic_viscosity.value_;
  }

  constexpr bool operator>=(const BulkDynamicViscosity& bulk_dynamic_viscosity) const noexcept {
    return value_ >= bulk_dynamic_viscosity.value_;
  }

  constexpr BulkDynamicViscosity operator+(const BulkDynamicViscosity& bulk_dynamic_viscosity) const noexcept {
    return {value_ + bulk_dynamic_viscosity.value_};
  }

  constexpr void operator+=(const BulkDynamicViscosity& bulk_dynamic_viscosity) noexcept {
    value_ += bulk_dynamic_viscosity.value_;
  }

  constexpr BulkDynamicViscosity operator-(const BulkDynamicViscosity& bulk_dynamic_viscosity) const noexcept {
    return {value_ - bulk_dynamic_viscosity.value_};
  }

  constexpr void operator-=(const BulkDynamicViscosity& bulk_dynamic_viscosity) noexcept {
    value_ -= bulk_dynamic_viscosity.value_;
  }

protected:

  constexpr BulkDynamicViscosity(double value) noexcept : DimensionalScalarQuantity<Unit::DynamicViscosity>(value) {}

};

template <> constexpr bool sort(const BulkDynamicViscosity& bulk_dynamic_viscosity_1, const BulkDynamicViscosity& bulk_dynamic_viscosity_2) noexcept {
  return sort(bulk_dynamic_viscosity_1.value(), bulk_dynamic_viscosity_2.value());
}

} // namespace PhQ
