// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities (PhQ) is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or
// substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT
// NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
// NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
// DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM OUT
// OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef PHQ_ISOTHERMAL_BULK_MODULUS_HPP
#define PHQ_ISOTHERMAL_BULK_MODULUS_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

/// \brief Isothermal bulk modulus. Not to be confused with the isentropic bulk modulus. See also
/// PhQ::IsentropicBulkModulus.
template <typename Number = double>
class IsothermalBulkModulus : public DimensionalScalar<Unit::Pressure, Number> {
public:
  /// \brief Default constructor. Constructs an isothermal bulk modulus with an uninitialized value.
  IsothermalBulkModulus() = default;

  /// \brief Constructor. Constructs an isothermal bulk modulus with a given value expressed in a
  /// given pressure unit.
  IsothermalBulkModulus(const Number value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, Number>(value, unit) {}

  /// \brief Destructor. Destroys this isothermal bulk modulus.
  ~IsothermalBulkModulus() noexcept = default;

  /// \brief Copy constructor. Constructs an isothermal bulk modulus by copying another one.
  constexpr IsothermalBulkModulus(const IsothermalBulkModulus<Number>& other) = default;

  /// \brief Copy constructor. Constructs a isothermal bulk modulus by copying another one.
  template <typename OtherNumber>
  explicit constexpr IsothermalBulkModulus(const IsothermalBulkModulus<OtherNumber>& other)
    : IsothermalBulkModulus(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs an isothermal bulk modulus by moving another one.
  constexpr IsothermalBulkModulus(IsothermalBulkModulus<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this isothermal bulk modulus by copying another one.
  constexpr IsothermalBulkModulus<Number>& operator=(
      const IsothermalBulkModulus<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this isothermal bulk modulus by copying another one.
  template <typename OtherNumber>
  constexpr IsothermalBulkModulus<Number>& operator=(
      const IsothermalBulkModulus<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this isothermal bulk modulus by moving another one.
  constexpr IsothermalBulkModulus<Number>& operator=(
      IsothermalBulkModulus<Number>&& other) noexcept = default;

  /// \brief Statically creates an isothermal bulk modulus of zero.
  static constexpr IsothermalBulkModulus<Number> Zero() {
    return IsothermalBulkModulus<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates an isothermal bulk modulus with a given value expressed in a given
  /// pressure unit.
  template <Unit::Pressure Unit>
  static constexpr IsothermalBulkModulus<Number> Create(const Number value) {
    return IsothermalBulkModulus<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr IsothermalBulkModulus<Number> operator+(
      const IsothermalBulkModulus<Number>& isothermal_bulk_modulus) const {
    return IsothermalBulkModulus<Number>{this->value + isothermal_bulk_modulus.value};
  }

  constexpr IsothermalBulkModulus<Number> operator-(
      const IsothermalBulkModulus<Number>& isothermal_bulk_modulus) const {
    return IsothermalBulkModulus<Number>{this->value - isothermal_bulk_modulus.value};
  }

  constexpr IsothermalBulkModulus<Number> operator*(const Number number) const {
    return IsothermalBulkModulus<Number>{this->value * number};
  }

  constexpr IsothermalBulkModulus<Number> operator/(const Number number) const {
    return IsothermalBulkModulus<Number>{this->value / number};
  }

  constexpr Number operator/(
      const IsothermalBulkModulus<Number>& isothermal_bulk_modulus) const noexcept {
    return this->value / isothermal_bulk_modulus.value;
  }

  constexpr void operator+=(const IsothermalBulkModulus<Number>& isothermal_bulk_modulus) noexcept {
    this->value += isothermal_bulk_modulus.value;
  }

  constexpr void operator-=(const IsothermalBulkModulus<Number>& isothermal_bulk_modulus) noexcept {
    this->value -= isothermal_bulk_modulus.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs an isothermal bulk modulus with a given value expressed in the
  /// standard pressure unit.
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
