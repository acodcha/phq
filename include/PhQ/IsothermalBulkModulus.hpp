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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_ISOTHERMAL_BULK_MODULUS_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_ISOTHERMAL_BULK_MODULUS_HPP

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Isothermal bulk modulus. Not to be confused with the isentropic bulk modulus.
class IsothermalBulkModulus : public DimensionalScalarQuantity<Unit::Pressure> {
public:
  constexpr IsothermalBulkModulus() noexcept
    : DimensionalScalarQuantity<Unit::Pressure>() {}

  IsothermalBulkModulus(const double value, const Unit::Pressure unit) noexcept
    : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  static constexpr IsothermalBulkModulus Zero() noexcept {
    return IsothermalBulkModulus{0.0};
  }

  template<Unit::Pressure Unit>
  static constexpr IsothermalBulkModulus Create(const double value) noexcept {
    return IsothermalBulkModulus{
        StaticConvertCopy<Unit::Pressure, Unit, StandardUnit<Unit::Pressure>>(
            value)};
  }

  inline constexpr IsothermalBulkModulus operator+(
      const IsothermalBulkModulus& isothermal_bulk_modulus) const noexcept {
    return {value_ + isothermal_bulk_modulus.value_};
  }

  inline constexpr IsothermalBulkModulus operator-(
      const IsothermalBulkModulus& isothermal_bulk_modulus) const noexcept {
    return {value_ - isothermal_bulk_modulus.value_};
  }

  inline constexpr IsothermalBulkModulus operator*(
      const double number) const noexcept {
    return IsothermalBulkModulus{value_ * number};
  }

  inline constexpr IsothermalBulkModulus operator/(
      const double number) const noexcept {
    return IsothermalBulkModulus{value_ / number};
  }

  inline constexpr void operator+=(
      const IsothermalBulkModulus& isothermal_bulk_modulus) noexcept {
    value_ += isothermal_bulk_modulus.value_;
  }

  inline constexpr void operator-=(
      const IsothermalBulkModulus& isothermal_bulk_modulus) noexcept {
    value_ -= isothermal_bulk_modulus.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  constexpr IsothermalBulkModulus(const double value) noexcept
    : DimensionalScalarQuantity<Unit::Pressure>(value) {}
};

inline constexpr bool operator==(const IsothermalBulkModulus& left,
                                 const IsothermalBulkModulus& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const IsothermalBulkModulus& left,
                                 const IsothermalBulkModulus& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const IsothermalBulkModulus& left,
                                const IsothermalBulkModulus& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const IsothermalBulkModulus& left,
                                const IsothermalBulkModulus& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const IsothermalBulkModulus& left,
                                 const IsothermalBulkModulus& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const IsothermalBulkModulus& left,
                                 const IsothermalBulkModulus& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const IsothermalBulkModulus& isothermal_bulk_modulus) noexcept {
  stream << isothermal_bulk_modulus.Print();
  return stream;
}

inline constexpr IsothermalBulkModulus operator*(
    const double number,
    const IsothermalBulkModulus& isothermal_bulk_modulus) noexcept {
  return isothermal_bulk_modulus * number;
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::IsothermalBulkModulus> {
  size_t operator()(
      const PhQ::IsothermalBulkModulus& isothermal_bulk_modulus) const {
    return hash<double>()(isothermal_bulk_modulus.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_ISOTHERMAL_BULK_MODULUS_HPP
