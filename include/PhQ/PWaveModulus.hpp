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

#ifndef PHQ_PWAVE_MODULUS_HPP
#define PHQ_PWAVE_MODULUS_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

/// \brief P-wave modulus of elasticity of a deformable solid material. A measure of a deformable
/// solid material's elastic modulus. For other measures of a material's elastic modulus, see
/// PhQ::YoungModulus, PhQ::ShearModulus, PhQ::IsentropicBulkModulus, PhQ::IsothermalBulkModulus,
/// PhQ::LameModulus, and PhQ::PoissonRatio.
template <typename Number = double>
class PWaveModulus : public DimensionalScalar<Unit::Pressure, Number> {
public:
  /// \brief Default constructor. Constructs a P-wave modulus with an uninitialized value.
  PWaveModulus() = default;

  /// \brief Constructor. Constructs a P-wave modulus with a given value expressed in a given
  /// pressure unit.
  PWaveModulus(const Number value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, Number>(value, unit) {}

  /// \brief Destructor. Destroys this P-wave modulus.
  ~PWaveModulus() noexcept = default;

  /// \brief Copy constructor. Constructs a P-wave modulus by copying another one.
  constexpr PWaveModulus(const PWaveModulus<Number>& other) = default;

  /// \brief Copy constructor. Constructs a P-wave modulus by copying another one.
  template <typename OtherNumber>
  explicit constexpr PWaveModulus(const PWaveModulus<OtherNumber>& other)
    : PWaveModulus(static_cast<Number>(other.Value())) {}

  /// \brief Move constructor. Constructs a P-wave modulus by moving another one.
  constexpr PWaveModulus(PWaveModulus<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this P-wave modulus by copying another one.
  constexpr PWaveModulus<Number>& operator=(const PWaveModulus<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this P-wave modulus by copying another one.
  template <typename OtherNumber>
  constexpr PWaveModulus<Number>& operator=(const PWaveModulus<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this P-wave modulus by moving another one.
  constexpr PWaveModulus<Number>& operator=(PWaveModulus<Number>&& other) noexcept = default;

  /// \brief Statically creates a P-wave modulus of zero.
  static constexpr PWaveModulus<Number> Zero() {
    return PWaveModulus<Number>{static_cast<Number>(0)};
  }

  /// \brief Statically creates a P-wave modulus with a given value expressed in a given pressure
  /// unit.
  template <Unit::Pressure Unit>
  static constexpr PWaveModulus<Number> Create(const Number value) {
    return PWaveModulus<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr PWaveModulus<Number> operator+(const PWaveModulus<Number>& p_wave_modulus) const {
    return PWaveModulus<Number>{this->value + p_wave_modulus.value};
  }

  constexpr PWaveModulus<Number> operator-(const PWaveModulus<Number>& p_wave_modulus) const {
    return PWaveModulus<Number>{this->value - p_wave_modulus.value};
  }

  constexpr PWaveModulus<Number> operator*(const Number number) const {
    return PWaveModulus<Number>{this->value * number};
  }

  constexpr PWaveModulus<Number> operator/(const Number number) const {
    return PWaveModulus<Number>{this->value / number};
  }

  constexpr Number operator/(const PWaveModulus<Number>& p_wave_modulus) const noexcept {
    return this->value / p_wave_modulus.value;
  }

  constexpr void operator+=(const PWaveModulus<Number>& p_wave_modulus) noexcept {
    this->value += p_wave_modulus.value;
  }

  constexpr void operator-=(const PWaveModulus<Number>& p_wave_modulus) noexcept {
    this->value -= p_wave_modulus.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a P-wave modulus with a given value expressed in the standard
  /// pressure unit.
  explicit constexpr PWaveModulus(const Number value)
    : DimensionalScalar<Unit::Pressure, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const PWaveModulus<Number>& left, const PWaveModulus<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const PWaveModulus<Number>& left, const PWaveModulus<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const PWaveModulus<Number>& left, const PWaveModulus<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const PWaveModulus<Number>& left, const PWaveModulus<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const PWaveModulus<Number>& left, const PWaveModulus<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const PWaveModulus<Number>& left, const PWaveModulus<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const PWaveModulus<Number>& p_wave_modulus) {
  stream << p_wave_modulus.Print();
  return stream;
}

template <typename Number>
inline constexpr PWaveModulus<Number> operator*(
    const Number number, const PWaveModulus<Number>& p_wave_modulus) {
  return p_wave_modulus * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::PWaveModulus<Number>> {
  inline size_t operator()(const PhQ::PWaveModulus<Number>& p_wave_modulus) const {
    return hash<Number>()(p_wave_modulus.Value());
  }
};

}  // namespace std

#endif  // PHQ_PWAVE_MODULUS_HPP
