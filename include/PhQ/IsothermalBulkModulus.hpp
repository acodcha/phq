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
template <typename Number = double>
class IsothermalBulkModulus : public DimensionalScalar<Unit::Pressure, Number> {
public:
  // Default constructor. Constructs an isothermal bulk modulus with an uninitialized value.
  IsothermalBulkModulus() = default;

  // Constructor. Constructs an isothermal bulk modulus with a given value expressed in a given
  // pressure unit.
  IsothermalBulkModulus(const Number value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, Number>(value, unit) {}

  // Destructor. Destroys this isothermal bulk modulus.
  ~IsothermalBulkModulus() noexcept = default;

  // Copy constructor. Constructs an isothermal bulk modulus by copying another one.
  constexpr IsothermalBulkModulus(const IsothermalBulkModulus<Number>& other) = default;

  // Copy constructor. Constructs a isothermal bulk modulus by copying another one.
  template <typename OtherNumber>
  explicit constexpr IsothermalBulkModulus(const IsothermalBulkModulus<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs an isothermal bulk modulus by moving another one.
  constexpr IsothermalBulkModulus(IsothermalBulkModulus<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this isothermal bulk modulus by copying another one.
  constexpr IsothermalBulkModulus<Number>& operator=(
      const IsothermalBulkModulus<Number>& other) = default;

  // Copy assignment operator. Assigns this isothermal bulk modulus by copying another one.
  template <typename OtherNumber>
  constexpr IsothermalBulkModulus<Number>& operator=(
      const IsothermalBulkModulus<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this isothermal bulk modulus by moving another one.
  constexpr IsothermalBulkModulus<Number>& operator=(
      IsothermalBulkModulus<Number>&& other) noexcept = default;

  // Statically creates an isothermal bulk modulus of zero.
  static constexpr IsothermalBulkModulus<Number> Zero() {
    return IsothermalBulkModulus<Number>{static_cast<Number>(0)};
  }

  // Statically creates an isothermal bulk modulus with a given value expressed in a given pressure
  // unit.
  template <Unit::Pressure Unit>
  static constexpr IsothermalBulkModulus<Number> Create(const Number value) {
    return IsothermalBulkModulus<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr IsothermalBulkModulus<Number> operator+(
      const IsothermalBulkModulus<Number>& isothermal_bulk_modulus) const {
    return IsothermalBulkModulus<Number>{value + isothermal_bulk_modulus.value};
  }

  constexpr IsothermalBulkModulus<Number> operator-(
      const IsothermalBulkModulus<Number>& isothermal_bulk_modulus) const {
    return IsothermalBulkModulus<Number>{value - isothermal_bulk_modulus.value};
  }

  constexpr IsothermalBulkModulus<Number> operator*(const Number number) const {
    return IsothermalBulkModulus<Number>{value * number};
  }

  constexpr IsothermalBulkModulus<Number> operator/(const Number number) const {
    return IsothermalBulkModulus<Number>{value / number};
  }

  constexpr Number operator/(
      const IsothermalBulkModulus<Number>& isothermal_bulk_modulus) const noexcept {
    return value / isothermal_bulk_modulus.value;
  }

  constexpr void operator+=(const IsothermalBulkModulus<Number>& isothermal_bulk_modulus) noexcept {
    value += isothermal_bulk_modulus.value;
  }

  constexpr void operator-=(const IsothermalBulkModulus<Number>& isothermal_bulk_modulus) noexcept {
    value -= isothermal_bulk_modulus.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs an isothermal bulk modulus with a given value expressed in the standard
  // pressure unit.
  explicit constexpr IsothermalBulkModulus(const Number value)
    : DimensionalScalar<Unit::Pressure, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const IsothermalBulkModulus<Number>& left,
                                 const IsothermalBulkModulus<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const IsothermalBulkModulus<Number>& left,
                                 const IsothermalBulkModulus<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const IsothermalBulkModulus<Number>& left,
                                const IsothermalBulkModulus<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const IsothermalBulkModulus<Number>& left,
                                const IsothermalBulkModulus<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const IsothermalBulkModulus<Number>& left,
                                 const IsothermalBulkModulus<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const IsothermalBulkModulus<Number>& left,
                                 const IsothermalBulkModulus<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const IsothermalBulkModulus<Number>& isothermal_bulk_modulus) {
  stream << isothermal_bulk_modulus.Print();
  return stream;
}

template <typename Number>
inline constexpr IsothermalBulkModulus<Number> operator*(
    const Number number, const IsothermalBulkModulus<Number>& isothermal_bulk_modulus) {
  return isothermal_bulk_modulus * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::IsothermalBulkModulus<Number>> {
  inline size_t operator()(
      const PhQ::IsothermalBulkModulus<Number>& isothermal_bulk_modulus) const {
    return hash<Number>()(isothermal_bulk_modulus.Value());
  }
};

}  // namespace std

#endif  // PHQ_ISOTHERMAL_BULK_MODULUS_HPP
