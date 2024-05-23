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
/// parameters. A measure of a deformable solid material's elastic modulus.
template <typename Number = double>
class LameFirstModulus : public DimensionalScalar<Unit::Pressure, Number> {
public:
  /// \brief Default constructor. Constructs a Lamé's first modulus with an uninitialized value.
  LameFirstModulus() = default;

  /// \brief Constructor. Constructs a Lamé's first modulus with a given value expressed in a given
  /// pressure unit.
  LameFirstModulus(const Number value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, Number>(value, unit) {}

  /// \brief Destructor. Destroys this Lamé's first modulus.
  ~LameFirstModulus() noexcept = default;

  /// \brief Copy constructor. Constructs a Lamé's first modulus by copying another one.
  constexpr LameFirstModulus(const LameFirstModulus<Number>& other) = default;

  /// \brief Copy constructor. Constructs a Lamé's first modulus by copying another one.
  template <typename OtherNumber>
  explicit constexpr LameFirstModulus(const LameFirstModulus<OtherNumber>& other)
    : LameFirstModulus(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a Lamé's first modulus by moving another one.
  constexpr LameFirstModulus(LameFirstModulus<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this Lamé's first modulus by copying another one.
  constexpr LameFirstModulus<Number>& operator=(const LameFirstModulus<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this Lamé's first modulus by copying another one.
  template <typename OtherNumber>
  constexpr LameFirstModulus<Number>& operator=(const LameFirstModulus<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this Lamé's first modulus by moving another one.
  constexpr LameFirstModulus<Number>& operator=(
      LameFirstModulus<Number>&& other) noexcept = default;

  /// \brief Statically creates a Lamé's first modulus of zero.
  static constexpr LameFirstModulus<Number> Zero() {
    return LameFirstModulus<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a Lamé's first modulus with a given value expressed in a given
  /// pressure unit.
  template <Unit::Pressure Unit>
  static constexpr LameFirstModulus<Number> Create(const Number value) {
    return LameFirstModulus<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr LameFirstModulus<Number> operator+(
      const LameFirstModulus<Number>& lame_first_modulus) const {
    return LameFirstModulus<Number>{this->value + lame_first_modulus.value};
  }

  constexpr LameFirstModulus<Number> operator-(
      const LameFirstModulus<Number>& lame_first_modulus) const {
    return LameFirstModulus<Number>{this->value - lame_first_modulus.value};
  }

  constexpr LameFirstModulus<Number> operator*(const Number number) const {
    return LameFirstModulus<Number>{this->value * number};
  }

  constexpr LameFirstModulus<Number> operator/(const Number number) const {
    return LameFirstModulus<Number>{this->value / number};
  }

  constexpr Number operator/(const LameFirstModulus<Number>& lame_first_modulus) const noexcept {
    return this->value / lame_first_modulus.value;
  }

  constexpr void operator+=(const LameFirstModulus<Number>& lame_first_modulus) noexcept {
    this->value += lame_first_modulus.value;
  }

  constexpr void operator-=(const LameFirstModulus<Number>& lame_first_modulus) noexcept {
    this->value -= lame_first_modulus.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a Lamé's first modulus with a given value expressed in the
  /// standard pressure unit.
  explicit constexpr LameFirstModulus(const Number value)
    : DimensionalScalar<Unit::Pressure, Number>(value) {}

  friend class ConstitutiveModel;
};

template <typename Number>
inline constexpr bool operator==(
    const LameFirstModulus<Number>& left, const LameFirstModulus<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const LameFirstModulus<Number>& left, const LameFirstModulus<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const LameFirstModulus<Number>& left, const LameFirstModulus<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const LameFirstModulus<Number>& left, const LameFirstModulus<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const LameFirstModulus<Number>& left, const LameFirstModulus<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const LameFirstModulus<Number>& left, const LameFirstModulus<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const LameFirstModulus<Number>& lame_first_modulus) {
  stream << lame_first_modulus.Print();
  return stream;
}

template <typename Number>
inline constexpr LameFirstModulus<Number> operator*(
    const Number number, const LameFirstModulus<Number>& lame_first_modulus) {
  return lame_first_modulus * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::LameFirstModulus<Number>> {
  inline size_t operator()(const PhQ::LameFirstModulus<Number>& lame_first_modulus) const {
    return hash<Number>()(lame_first_modulus.Value());
  }
};

}  // namespace std

#endif  // PHQ_LAME_FIRST_MODULUS_HPP
