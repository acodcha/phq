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

/// \brief Isothermal bulk modulus of a material. Not to be confused with the isentropic bulk
/// modulus; see PhQ::IsentropicBulkModulus. Solid materials usually have very similar isentropic
/// and isothermal bulk moduli; however, in general, fluid materials have differing isentropic and
/// isothermal bulk moduli.
template <typename NumericType = double>
class IsothermalBulkModulus : public DimensionalScalar<Unit::Pressure, NumericType> {
public:
  /// \brief Default constructor. Constructs an isothermal bulk modulus with an uninitialized value.
  IsothermalBulkModulus() = default;

  /// \brief Constructor. Constructs an isothermal bulk modulus with a given value expressed in a
  /// given pressure unit.
  IsothermalBulkModulus(const NumericType value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, NumericType>(value, unit) {}

  /// \brief Destructor. Destroys this isothermal bulk modulus.
  ~IsothermalBulkModulus() noexcept = default;

  /// \brief Copy constructor. Constructs an isothermal bulk modulus by copying another one.
  constexpr IsothermalBulkModulus(const IsothermalBulkModulus<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a isothermal bulk modulus by copying another one.
  template <typename OtherNumericType>
  explicit constexpr IsothermalBulkModulus(const IsothermalBulkModulus<OtherNumericType>& other)
    : IsothermalBulkModulus(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs an isothermal bulk modulus by moving another one.
  constexpr IsothermalBulkModulus(IsothermalBulkModulus<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this isothermal bulk modulus by copying another one.
  constexpr IsothermalBulkModulus<NumericType>& operator=(
      const IsothermalBulkModulus<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this isothermal bulk modulus by copying another one.
  template <typename OtherNumericType>
  constexpr IsothermalBulkModulus<NumericType>& operator=(
      const IsothermalBulkModulus<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this isothermal bulk modulus by moving another one.
  constexpr IsothermalBulkModulus<NumericType>& operator=(
      IsothermalBulkModulus<NumericType>&& other) noexcept = default;

  /// \brief Statically creates an isothermal bulk modulus of zero.
  static constexpr IsothermalBulkModulus<NumericType> Zero() {
    return IsothermalBulkModulus<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates an isothermal bulk modulus with a given value expressed in a given
  /// pressure unit.
  template <Unit::Pressure Unit>
  static constexpr IsothermalBulkModulus<NumericType> Create(const NumericType value) {
    return IsothermalBulkModulus<NumericType>{
        ConvertStatically<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr IsothermalBulkModulus<NumericType> operator+(
      const IsothermalBulkModulus<NumericType>& isothermal_bulk_modulus) const {
    return IsothermalBulkModulus<NumericType>{this->value + isothermal_bulk_modulus.value};
  }

  constexpr IsothermalBulkModulus<NumericType> operator-(
      const IsothermalBulkModulus<NumericType>& isothermal_bulk_modulus) const {
    return IsothermalBulkModulus<NumericType>{this->value - isothermal_bulk_modulus.value};
  }

  constexpr IsothermalBulkModulus<NumericType> operator*(const NumericType number) const {
    return IsothermalBulkModulus<NumericType>{this->value * number};
  }

  constexpr IsothermalBulkModulus<NumericType> operator/(const NumericType number) const {
    return IsothermalBulkModulus<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const IsothermalBulkModulus<NumericType>& isothermal_bulk_modulus) const noexcept {
    return this->value / isothermal_bulk_modulus.value;
  }

  constexpr void operator+=(
      const IsothermalBulkModulus<NumericType>& isothermal_bulk_modulus) noexcept {
    this->value += isothermal_bulk_modulus.value;
  }

  constexpr void operator-=(
      const IsothermalBulkModulus<NumericType>& isothermal_bulk_modulus) noexcept {
    this->value -= isothermal_bulk_modulus.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs an isothermal bulk modulus with a given value expressed in the
  /// standard pressure unit.
  explicit constexpr IsothermalBulkModulus(const NumericType value)
    : DimensionalScalar<Unit::Pressure, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const IsothermalBulkModulus<NumericType>& left,
                                 const IsothermalBulkModulus<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const IsothermalBulkModulus<NumericType>& left,
                                 const IsothermalBulkModulus<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const IsothermalBulkModulus<NumericType>& left,
                                const IsothermalBulkModulus<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const IsothermalBulkModulus<NumericType>& left,
                                const IsothermalBulkModulus<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const IsothermalBulkModulus<NumericType>& left,
                                 const IsothermalBulkModulus<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const IsothermalBulkModulus<NumericType>& left,
                                 const IsothermalBulkModulus<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const IsothermalBulkModulus<NumericType>& isothermal_bulk_modulus) {
  stream << isothermal_bulk_modulus.Print();
  return stream;
}

template <typename NumericType>
inline constexpr IsothermalBulkModulus<NumericType> operator*(
    const NumericType number, const IsothermalBulkModulus<NumericType>& isothermal_bulk_modulus) {
  return isothermal_bulk_modulus * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::IsothermalBulkModulus<NumericType>> {
  inline size_t operator()(
      const PhQ::IsothermalBulkModulus<NumericType>& isothermal_bulk_modulus) const {
    return hash<NumericType>()(isothermal_bulk_modulus.Value());
  }
};

}  // namespace std

#endif  // PHQ_ISOTHERMAL_BULK_MODULUS_HPP
