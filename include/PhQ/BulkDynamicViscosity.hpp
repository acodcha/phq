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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_BULK_DYNAMIC_VISCOSITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_BULK_DYNAMIC_VISCOSITY_HPP

#include "DimensionalScalarQuantity.hpp"
#include "Unit/DynamicViscosity.hpp"

namespace PhQ {

// Bulk dynamic viscosity, also known as volume dynamic viscosity or
// dilatational dynamic viscosity.
class BulkDynamicViscosity
  : public DimensionalScalarQuantity<Unit::DynamicViscosity> {
public:
  constexpr BulkDynamicViscosity()
    : DimensionalScalarQuantity<Unit::DynamicViscosity>() {}

  BulkDynamicViscosity(const double value, const Unit::DynamicViscosity unit)
    : DimensionalScalarQuantity<Unit::DynamicViscosity>(value, unit) {}

  static constexpr BulkDynamicViscosity Zero() {
    return BulkDynamicViscosity{0.0};
  }

  template <Unit::DynamicViscosity Unit>
  static constexpr BulkDynamicViscosity Create(const double value) {
    return BulkDynamicViscosity{
        StaticConvertCopy<Unit::DynamicViscosity, Unit,
                          Standard<Unit::DynamicViscosity>>(value)};
  }

  constexpr BulkDynamicViscosity operator+(
      const BulkDynamicViscosity& bulk_dynamic_viscosity) const {
    return BulkDynamicViscosity{value_ + bulk_dynamic_viscosity.value_};
  }

  constexpr BulkDynamicViscosity operator-(
      const BulkDynamicViscosity& bulk_dynamic_viscosity) const {
    return BulkDynamicViscosity{value_ - bulk_dynamic_viscosity.value_};
  }

  constexpr BulkDynamicViscosity operator*(const double number) const {
    return BulkDynamicViscosity{value_ * number};
  }

  constexpr BulkDynamicViscosity operator/(const double number) const {
    return BulkDynamicViscosity{value_ / number};
  }

  constexpr double operator/(
      const BulkDynamicViscosity& bulk_dynamic_viscosity) const noexcept {
    return value_ / bulk_dynamic_viscosity.value_;
  }

  constexpr void operator+=(
      const BulkDynamicViscosity& bulk_dynamic_viscosity) noexcept {
    value_ += bulk_dynamic_viscosity.value_;
  }

  constexpr void operator-=(
      const BulkDynamicViscosity& bulk_dynamic_viscosity) noexcept {
    value_ -= bulk_dynamic_viscosity.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr BulkDynamicViscosity(const double value)
    : DimensionalScalarQuantity<Unit::DynamicViscosity>(value) {}
};

inline constexpr bool operator==(const BulkDynamicViscosity& left,
                                 const BulkDynamicViscosity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const BulkDynamicViscosity& left,
                                 const BulkDynamicViscosity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const BulkDynamicViscosity& left,
                                const BulkDynamicViscosity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const BulkDynamicViscosity& left,
                                const BulkDynamicViscosity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const BulkDynamicViscosity& left,
                                 const BulkDynamicViscosity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const BulkDynamicViscosity& left,
                                 const BulkDynamicViscosity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const BulkDynamicViscosity& mass_density) {
  stream << mass_density.Print();
  return stream;
}

inline constexpr BulkDynamicViscosity operator*(
    const double number, const BulkDynamicViscosity& mass_density) {
  return mass_density * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::BulkDynamicViscosity> {
  inline size_t operator()(
      const PhQ::BulkDynamicViscosity& bulk_dynamic_viscosity) const {
    return hash<double>()(bulk_dynamic_viscosity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_BULK_DYNAMIC_VISCOSITY_HPP
