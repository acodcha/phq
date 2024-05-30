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

#ifndef PHQ_LAME_FIRST_MODULUS_HPP
#define PHQ_LAME_FIRST_MODULUS_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

/// \brief Lamé's first modulus of elasticity of a deformable solid material. First of the two Lamé
/// parameters. A measure of a deformable solid material's elastic modulus. For other measures of a
/// material's elastic modulus, see PhQ::YoungModulus, PhQ::ShearModulus,
/// PhQ::IsentropicBulkModulus, PhQ::IsothermalBulkModulus, PhQ::PWaveModulus, and
/// PhQ::PoissonRatio.
template <typename NumericType = double>
class LameFirstModulus : public DimensionalScalar<Unit::Pressure, NumericType> {
public:
  /// \brief Default constructor. Constructs a Lamé's first modulus with an uninitialized value.
  LameFirstModulus() = default;

  /// \brief Constructor. Constructs a Lamé's first modulus with a given value expressed in a given
  /// pressure unit.
  LameFirstModulus(const NumericType value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, NumericType>(value, unit) {}

  /// \brief Destructor. Destroys this Lamé's first modulus.
  ~LameFirstModulus() noexcept = default;

  /// \brief Copy constructor. Constructs a Lamé's first modulus by copying another one.
  constexpr LameFirstModulus(const LameFirstModulus<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a Lamé's first modulus by copying another one.
  template <typename OtherNumericType>
  explicit constexpr LameFirstModulus(const LameFirstModulus<OtherNumericType>& other)
    : LameFirstModulus(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a Lamé's first modulus by moving another one.
  constexpr LameFirstModulus(LameFirstModulus<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this Lamé's first modulus by copying another one.
  constexpr LameFirstModulus<NumericType>& operator=(
      const LameFirstModulus<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this Lamé's first modulus by copying another one.
  template <typename OtherNumericType>
  constexpr LameFirstModulus<NumericType>& operator=(
      const LameFirstModulus<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this Lamé's first modulus by moving another one.
  constexpr LameFirstModulus<NumericType>& operator=(
      LameFirstModulus<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a Lamé's first modulus of zero.
  static constexpr LameFirstModulus<NumericType> Zero() {
    return LameFirstModulus<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a Lamé's first modulus with a given value expressed in a given
  /// pressure unit.
  template <Unit::Pressure Unit>
  static constexpr LameFirstModulus<NumericType> Create(const NumericType value) {
    return LameFirstModulus<NumericType>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr LameFirstModulus<NumericType> operator+(
      const LameFirstModulus<NumericType>& lame_first_modulus) const {
    return LameFirstModulus<NumericType>{this->value + lame_first_modulus.value};
  }

  constexpr LameFirstModulus<NumericType> operator-(
      const LameFirstModulus<NumericType>& lame_first_modulus) const {
    return LameFirstModulus<NumericType>{this->value - lame_first_modulus.value};
  }

  constexpr LameFirstModulus<NumericType> operator*(const NumericType number) const {
    return LameFirstModulus<NumericType>{this->value * number};
  }

  constexpr LameFirstModulus<NumericType> operator/(const NumericType number) const {
    return LameFirstModulus<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(
      const LameFirstModulus<NumericType>& lame_first_modulus) const noexcept {
    return this->value / lame_first_modulus.value;
  }

  constexpr void operator+=(const LameFirstModulus<NumericType>& lame_first_modulus) noexcept {
    this->value += lame_first_modulus.value;
  }

  constexpr void operator-=(const LameFirstModulus<NumericType>& lame_first_modulus) noexcept {
    this->value -= lame_first_modulus.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a Lamé's first modulus with a given value expressed in the
  /// standard pressure unit.
  explicit constexpr LameFirstModulus(const NumericType value)
    : DimensionalScalar<Unit::Pressure, NumericType>(value) {}

  friend class ConstitutiveModel;
};

template <typename NumericType>
inline constexpr bool operator==(const LameFirstModulus<NumericType>& left,
                                 const LameFirstModulus<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const LameFirstModulus<NumericType>& left,
                                 const LameFirstModulus<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const LameFirstModulus<NumericType>& left,
                                const LameFirstModulus<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const LameFirstModulus<NumericType>& left,
                                const LameFirstModulus<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const LameFirstModulus<NumericType>& left,
                                 const LameFirstModulus<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const LameFirstModulus<NumericType>& left,
                                 const LameFirstModulus<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const LameFirstModulus<NumericType>& lame_first_modulus) {
  stream << lame_first_modulus.Print();
  return stream;
}

template <typename NumericType>
inline constexpr LameFirstModulus<NumericType> operator*(
    const NumericType number, const LameFirstModulus<NumericType>& lame_first_modulus) {
  return lame_first_modulus * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::LameFirstModulus<NumericType>> {
  inline size_t operator()(const PhQ::LameFirstModulus<NumericType>& lame_first_modulus) const {
    return hash<NumericType>()(lame_first_modulus.Value());
  }
};

}  // namespace std

#endif  // PHQ_LAME_FIRST_MODULUS_HPP
