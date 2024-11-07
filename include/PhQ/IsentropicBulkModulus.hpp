// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef PHQ_ISENTROPIC_BULK_MODULUS_HPP
#define PHQ_ISENTROPIC_BULK_MODULUS_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Forward declaration for class PhQ::IsentropicBulkModulus.
template <typename NumericType>
class MassDensity;

// Forward declaration for class PhQ::IsentropicBulkModulus.
template <typename NumericType>
class SoundSpeed;

/// \brief Isentropic bulk modulus. Not to be confused with the isothermal bulk modulus; see
/// PhQ::IsothermalBulkModulus. Solid materials usually have very similar isentropic and isothermal
/// bulk moduli; however, in general, fluid materials have differing isentropic and isothermal bulk
/// moduli.
template <typename NumericType = double>
class IsentropicBulkModulus : public DimensionalScalar<Unit::Pressure, NumericType> {
public:
  /// \brief Default constructor. Constructs an isentropic bulk modulus with an uninitialized value.
  IsentropicBulkModulus() = default;

  /// \brief Constructor. Constructs an isentropic bulk modulus with a given value expressed in a
  /// given pressure unit.
  IsentropicBulkModulus(const NumericType value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs an isentropic bulk modulus from a given mass density and sound
  /// speed using the definition of the isentropic bulk modulus.
  constexpr IsentropicBulkModulus(
      const MassDensity<NumericType>& mass_density, const SoundSpeed<NumericType>& sound_speed);

  /// \brief Destructor. Destroys this isentropic bulk modulus.
  ~IsentropicBulkModulus() noexcept = default;

  /// \brief Copy constructor. Constructs an isentropic bulk modulus by copying another one.
  constexpr IsentropicBulkModulus(const IsentropicBulkModulus<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a isentropic bulk modulus by copying another one.
  template <typename OtherNumericType>
  explicit constexpr IsentropicBulkModulus(const IsentropicBulkModulus<OtherNumericType>& other)
    : IsentropicBulkModulus(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs an isentropic bulk modulus by moving another one.
  constexpr IsentropicBulkModulus(IsentropicBulkModulus<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this isentropic bulk modulus by copying another one.
  constexpr IsentropicBulkModulus<NumericType>& operator=(
      const IsentropicBulkModulus<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this isentropic bulk modulus by copying another one.
  template <typename OtherNumericType>
  constexpr IsentropicBulkModulus<NumericType>& operator=(
      const IsentropicBulkModulus<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this isentropic bulk modulus by moving another one.
  constexpr IsentropicBulkModulus<NumericType>& operator=(
      IsentropicBulkModulus<NumericType>&& other) noexcept = default;

  /// \brief Statically creates an isentropic bulk modulus of zero.
  [[nodiscard]] static constexpr IsentropicBulkModulus<NumericType> Zero() {
    return IsentropicBulkModulus<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates an isentropic bulk modulus with a given value expressed in a given
  /// pressure unit.
  template <Unit::Pressure Unit>
  [[nodiscard]] static constexpr IsentropicBulkModulus<NumericType> Create(
      const NumericType value) {
    return IsentropicBulkModulus<NumericType>{
      ConvertStatically<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr IsentropicBulkModulus<NumericType> operator+(
      const IsentropicBulkModulus<NumericType>& isentropic_bulk_modulus) const {
    return IsentropicBulkModulus<NumericType>{this->value + isentropic_bulk_modulus.value};
  }

  constexpr IsentropicBulkModulus<NumericType> operator-(
      const IsentropicBulkModulus<NumericType>& isentropic_bulk_modulus) const {
    return IsentropicBulkModulus<NumericType>{this->value - isentropic_bulk_modulus.value};
  }

  constexpr IsentropicBulkModulus<NumericType> operator*(const NumericType number) const {
    return IsentropicBulkModulus<NumericType>{this->value * number};
  }

  constexpr IsentropicBulkModulus<NumericType> operator/(const NumericType number) const {
    return IsentropicBulkModulus<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const IsentropicBulkModulus<NumericType>& isentropic_bulk_modulus) const noexcept {
    return this->value / isentropic_bulk_modulus.value;
  }

  constexpr void operator+=(
      const IsentropicBulkModulus<NumericType>& isentropic_bulk_modulus) noexcept {
    this->value += isentropic_bulk_modulus.value;
  }

  constexpr void operator-=(
      const IsentropicBulkModulus<NumericType>& isentropic_bulk_modulus) noexcept {
    this->value -= isentropic_bulk_modulus.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs an isentropic bulk modulus with a given value expressed in the
  /// standard pressure unit.
  explicit constexpr IsentropicBulkModulus(const NumericType value)
    : DimensionalScalar<Unit::Pressure, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const IsentropicBulkModulus<NumericType>& left,
                                 const IsentropicBulkModulus<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const IsentropicBulkModulus<NumericType>& left,
                                 const IsentropicBulkModulus<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const IsentropicBulkModulus<NumericType>& left,
                                const IsentropicBulkModulus<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const IsentropicBulkModulus<NumericType>& left,
                                const IsentropicBulkModulus<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const IsentropicBulkModulus<NumericType>& left,
                                 const IsentropicBulkModulus<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const IsentropicBulkModulus<NumericType>& left,
                                 const IsentropicBulkModulus<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const IsentropicBulkModulus<NumericType>& isentropic_bulk_modulus) {
  stream << isentropic_bulk_modulus.Print();
  return stream;
}

template <typename NumericType>
inline constexpr IsentropicBulkModulus<NumericType> operator*(
    const NumericType number, const IsentropicBulkModulus<NumericType>& isentropic_bulk_modulus) {
  return isentropic_bulk_modulus * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::IsentropicBulkModulus<NumericType>> {
  inline size_t operator()(
      const PhQ::IsentropicBulkModulus<NumericType>& isentropic_bulk_modulus) const {
    return hash<NumericType>()(isentropic_bulk_modulus.Value());
  }
};

}  // namespace std

#endif  // PHQ_ISENTROPIC_BULK_MODULUS_HPP
