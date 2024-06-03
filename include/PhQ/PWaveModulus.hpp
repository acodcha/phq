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
template <typename NumericType = double>
class PWaveModulus : public DimensionalScalar<Unit::Pressure, NumericType> {
public:
  /// \brief Default constructor. Constructs a P-wave modulus with an uninitialized value.
  PWaveModulus() = default;

  /// \brief Constructor. Constructs a P-wave modulus with a given value expressed in a given
  /// pressure unit.
  PWaveModulus(const NumericType value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, NumericType>(value, unit) {}

  /// \brief Destructor. Destroys this P-wave modulus.
  ~PWaveModulus() noexcept = default;

  /// \brief Copy constructor. Constructs a P-wave modulus by copying another one.
  constexpr PWaveModulus(const PWaveModulus<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a P-wave modulus by copying another one.
  template <typename OtherNumericType>
  explicit constexpr PWaveModulus(const PWaveModulus<OtherNumericType>& other)
    : PWaveModulus(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a P-wave modulus by moving another one.
  constexpr PWaveModulus(PWaveModulus<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this P-wave modulus by copying another one.
  constexpr PWaveModulus<NumericType>& operator=(const PWaveModulus<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this P-wave modulus by copying another one.
  template <typename OtherNumericType>
  constexpr PWaveModulus<NumericType>& operator=(const PWaveModulus<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this P-wave modulus by moving another one.
  constexpr PWaveModulus<NumericType>& operator=(
      PWaveModulus<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a P-wave modulus of zero.
  [[nodiscard]] static constexpr PWaveModulus<NumericType> Zero() {
    return PWaveModulus<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a P-wave modulus with a given value expressed in a given pressure
  /// unit.
  template <Unit::Pressure Unit>
  [[nodiscard]] static constexpr PWaveModulus<NumericType> Create(const NumericType value) {
    return PWaveModulus<NumericType>{
        ConvertStatically<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr PWaveModulus<NumericType> operator+(
      const PWaveModulus<NumericType>& p_wave_modulus) const {
    return PWaveModulus<NumericType>{this->value + p_wave_modulus.value};
  }

  constexpr PWaveModulus<NumericType> operator-(
      const PWaveModulus<NumericType>& p_wave_modulus) const {
    return PWaveModulus<NumericType>{this->value - p_wave_modulus.value};
  }

  constexpr PWaveModulus<NumericType> operator*(const NumericType number) const {
    return PWaveModulus<NumericType>{this->value * number};
  }

  constexpr PWaveModulus<NumericType> operator/(const NumericType number) const {
    return PWaveModulus<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(const PWaveModulus<NumericType>& p_wave_modulus) const noexcept {
    return this->value / p_wave_modulus.value;
  }

  constexpr void operator+=(const PWaveModulus<NumericType>& p_wave_modulus) noexcept {
    this->value += p_wave_modulus.value;
  }

  constexpr void operator-=(const PWaveModulus<NumericType>& p_wave_modulus) noexcept {
    this->value -= p_wave_modulus.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a P-wave modulus with a given value expressed in the standard
  /// pressure unit.
  explicit constexpr PWaveModulus(const NumericType value)
    : DimensionalScalar<Unit::Pressure, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const PWaveModulus<NumericType>& left, const PWaveModulus<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const PWaveModulus<NumericType>& left, const PWaveModulus<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const PWaveModulus<NumericType>& left, const PWaveModulus<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const PWaveModulus<NumericType>& left, const PWaveModulus<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const PWaveModulus<NumericType>& left, const PWaveModulus<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const PWaveModulus<NumericType>& left, const PWaveModulus<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const PWaveModulus<NumericType>& p_wave_modulus) {
  stream << p_wave_modulus.Print();
  return stream;
}

template <typename NumericType>
inline constexpr PWaveModulus<NumericType> operator*(
    const NumericType number, const PWaveModulus<NumericType>& p_wave_modulus) {
  return p_wave_modulus * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::PWaveModulus<NumericType>> {
  inline size_t operator()(const PhQ::PWaveModulus<NumericType>& p_wave_modulus) const {
    return hash<NumericType>()(p_wave_modulus.Value());
  }
};

}  // namespace std

#endif  // PHQ_PWAVE_MODULUS_HPP
