// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHQ_ISOTHERMAL_BULK_MODULUS_HPP
#define PHQ_ISOTHERMAL_BULK_MODULUS_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Isothermal bulk modulus. Not to be confused with the isentropic bulk modulus.
class IsothermalBulkModulus : public DimensionalScalar<Unit::Pressure, double> {
public:
  // Default constructor. Constructs an isothermal bulk modulus with an uninitialized value.
  IsothermalBulkModulus() = default;

  // Constructor. Constructs an isothermal bulk modulus with a given value expressed in a given
  // pressure unit.
  IsothermalBulkModulus(const double value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure>(value, unit) {}

  // Destructor. Destroys this isothermal bulk modulus.
  ~IsothermalBulkModulus() noexcept = default;

  // Copy constructor. Constructs an isothermal bulk modulus by copying another one.
  constexpr IsothermalBulkModulus(const IsothermalBulkModulus& other) = default;

  // Move constructor. Constructs an isothermal bulk modulus by moving another one.
  constexpr IsothermalBulkModulus(IsothermalBulkModulus&& other) noexcept = default;

  // Copy assignment operator. Assigns this isothermal bulk modulus by copying another one.
  constexpr IsothermalBulkModulus& operator=(const IsothermalBulkModulus& other) = default;

  // Move assignment operator. Assigns this isothermal bulk modulus by moving another one.
  constexpr IsothermalBulkModulus& operator=(IsothermalBulkModulus&& other) noexcept = default;

  // Statically creates an isothermal bulk modulus of zero.
  static constexpr IsothermalBulkModulus Zero() {
    return IsothermalBulkModulus{0.0};
  }

  // Statically creates an isothermal bulk modulus with a given value expressed in a given pressure
  // unit.
  template <Unit::Pressure Unit>
  static constexpr IsothermalBulkModulus Create(const double value) {
    return IsothermalBulkModulus{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr IsothermalBulkModulus operator+(
      const IsothermalBulkModulus& isothermal_bulk_modulus) const {
    return IsothermalBulkModulus{value + isothermal_bulk_modulus.value};
  }

  constexpr IsothermalBulkModulus operator-(
      const IsothermalBulkModulus& isothermal_bulk_modulus) const {
    return IsothermalBulkModulus{value - isothermal_bulk_modulus.value};
  }

  constexpr IsothermalBulkModulus operator*(const double number) const {
    return IsothermalBulkModulus{value * number};
  }

  constexpr IsothermalBulkModulus operator/(const double number) const {
    return IsothermalBulkModulus{value / number};
  }

  constexpr double operator/(const IsothermalBulkModulus& isothermal_bulk_modulus) const noexcept {
    return value / isothermal_bulk_modulus.value;
  }

  constexpr void operator+=(const IsothermalBulkModulus& isothermal_bulk_modulus) noexcept {
    value += isothermal_bulk_modulus.value;
  }

  constexpr void operator-=(const IsothermalBulkModulus& isothermal_bulk_modulus) noexcept {
    value -= isothermal_bulk_modulus.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs an isothermal bulk modulus with a given value expressed in the standard
  // pressure unit.
  explicit constexpr IsothermalBulkModulus(const double value)
    : DimensionalScalar<Unit::Pressure>(value) {}
};

inline constexpr bool operator==(
    const IsothermalBulkModulus& left, const IsothermalBulkModulus& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const IsothermalBulkModulus& left, const IsothermalBulkModulus& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const IsothermalBulkModulus& left, const IsothermalBulkModulus& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const IsothermalBulkModulus& left, const IsothermalBulkModulus& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const IsothermalBulkModulus& left, const IsothermalBulkModulus& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const IsothermalBulkModulus& left, const IsothermalBulkModulus& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const IsothermalBulkModulus& isothermal_bulk_modulus) {
  stream << isothermal_bulk_modulus.Print();
  return stream;
}

inline constexpr IsothermalBulkModulus operator*(
    const double number, const IsothermalBulkModulus& isothermal_bulk_modulus) {
  return isothermal_bulk_modulus * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::IsothermalBulkModulus> {
  inline size_t operator()(const PhQ::IsothermalBulkModulus& isothermal_bulk_modulus) const {
    return hash<double>()(isothermal_bulk_modulus.Value());
  }
};

}  // namespace std

#endif  // PHQ_ISOTHERMAL_BULK_MODULUS_HPP
