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

#ifndef PHQ_SHEAR_MODULUS_HPP
#define PHQ_SHEAR_MODULUS_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

/// \brief Shear modulus of elasticity of a deformable solid material. A measure of a deformable
/// solid material's elastic modulus.
template <typename Number = double>
class ShearModulus : public DimensionalScalar<Unit::Pressure, Number> {
public:
  /// \brief Default constructor. Constructs a shear modulus with an uninitialized value.
  ShearModulus() = default;

  /// \brief Constructor. Constructs a shear modulus with a given value expressed in a given
  /// pressure unit.
  ShearModulus(const Number value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, Number>(value, unit) {}

  /// \brief Destructor. Destroys this shear modulus.
  ~ShearModulus() noexcept = default;

  /// \brief Copy constructor. Constructs a shear modulus by copying another one.
  constexpr ShearModulus(const ShearModulus<Number>& other) = default;

  /// \brief Copy constructor. Constructs a shear modulus by copying another one.
  template <typename OtherNumber>
  explicit constexpr ShearModulus(const ShearModulus<OtherNumber>& other)
    : ShearModulus(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a shear modulus by moving another one.
  constexpr ShearModulus(ShearModulus<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this shear modulus by copying another one.
  constexpr ShearModulus<Number>& operator=(const ShearModulus<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this shear modulus by copying another one.
  template <typename OtherNumber>
  constexpr ShearModulus<Number>& operator=(const ShearModulus<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this shear modulus by moving another one.
  constexpr ShearModulus<Number>& operator=(ShearModulus<Number>&& other) noexcept = default;

  /// \brief Statically creates a shear modulus of zero.
  static constexpr ShearModulus<Number> Zero() {
    return ShearModulus<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a shear modulus with a given value expressed in a given pressure
  /// unit.
  template <Unit::Pressure Unit>
  static constexpr ShearModulus<Number> Create(const Number value) {
    return ShearModulus<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr ShearModulus<Number> operator+(const ShearModulus<Number>& shear_modulus) const {
    return ShearModulus<Number>{this->value + shear_modulus.value};
  }

  constexpr ShearModulus<Number> operator-(const ShearModulus<Number>& shear_modulus) const {
    return ShearModulus<Number>{this->value - shear_modulus.value};
  }

  constexpr ShearModulus<Number> operator*(const Number number) const {
    return ShearModulus<Number>{this->value * number};
  }

  constexpr ShearModulus<Number> operator/(const Number number) const {
    return ShearModulus<Number>{this->value / number};
  }

  constexpr Number operator/(const ShearModulus<Number>& shear_modulus) const noexcept {
    return this->value / shear_modulus.value;
  }

  constexpr void operator+=(const ShearModulus<Number>& shear_modulus) noexcept {
    this->value += shear_modulus.value;
  }

  constexpr void operator-=(const ShearModulus<Number>& shear_modulus) noexcept {
    this->value -= shear_modulus.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a shear modulus with a given value expressed in the standard
  /// pressure unit.
  explicit constexpr ShearModulus(const Number value)
    : DimensionalScalar<Unit::Pressure, Number>(value) {}

  friend class ConstitutiveModel;
};

template <typename Number>
inline constexpr bool operator==(
    const ShearModulus<Number>& left, const ShearModulus<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const ShearModulus<Number>& left, const ShearModulus<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const ShearModulus<Number>& left, const ShearModulus<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const ShearModulus<Number>& left, const ShearModulus<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const ShearModulus<Number>& left, const ShearModulus<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const ShearModulus<Number>& left, const ShearModulus<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const ShearModulus<Number>& shear_modulus) {
  stream << shear_modulus.Print();
  return stream;
}

template <typename Number>
inline constexpr ShearModulus<Number> operator*(
    const Number number, const ShearModulus<Number>& shear_modulus) {
  return shear_modulus * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ShearModulus<Number>> {
  inline size_t operator()(const PhQ::ShearModulus<Number>& shear_modulus) const {
    return hash<Number>()(shear_modulus.Value());
  }
};

}  // namespace std

#endif  // PHQ_SHEAR_MODULUS_HPP
