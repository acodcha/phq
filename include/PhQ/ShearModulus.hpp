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

#ifndef PHQ_SHEAR_MODULUS_HPP
#define PHQ_SHEAR_MODULUS_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

/// \brief Shear modulus of elasticity of a deformable solid material. A measure of a deformable
/// solid material's elastic modulus. For other measures of a material's elastic modulus, see
/// PhQ::YoungModulus, PhQ::IsentropicBulkModulus, PhQ::IsothermalBulkModulus,
/// PhQ::LameFirstModulus, PhQ::PWaveModulus, and PhQ::PoissonRatio.
template <typename NumericType = double>
class ShearModulus : public DimensionalScalar<Unit::Pressure, NumericType> {
public:
  /// \brief Default constructor. Constructs a shear modulus with an uninitialized value.
  ShearModulus() = default;

  /// \brief Constructor. Constructs a shear modulus with a given value expressed in a given
  /// pressure unit.
  ShearModulus(const NumericType value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, NumericType>(value, unit) {}

  /// \brief Destructor. Destroys this shear modulus.
  ~ShearModulus() noexcept = default;

  /// \brief Copy constructor. Constructs a shear modulus by copying another one.
  constexpr ShearModulus(const ShearModulus<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a shear modulus by copying another one.
  template <typename OtherNumericType>
  explicit constexpr ShearModulus(const ShearModulus<OtherNumericType>& other)
    : ShearModulus(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a shear modulus by moving another one.
  constexpr ShearModulus(ShearModulus<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this shear modulus by copying another one.
  constexpr ShearModulus<NumericType>& operator=(const ShearModulus<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this shear modulus by copying another one.
  template <typename OtherNumericType>
  constexpr ShearModulus<NumericType>& operator=(const ShearModulus<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this shear modulus by moving another one.
  constexpr ShearModulus<NumericType>& operator=(
      ShearModulus<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a shear modulus of zero.
  [[nodiscard]] static constexpr ShearModulus<NumericType> Zero() {
    return ShearModulus<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a shear modulus with a given value expressed in a given pressure
  /// unit.
  template <Unit::Pressure Unit>
  [[nodiscard]] static constexpr ShearModulus<NumericType> Create(const NumericType value) {
    return ShearModulus<NumericType>{
      ConvertStatically<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr ShearModulus<NumericType> operator+(
      const ShearModulus<NumericType>& shear_modulus) const {
    return ShearModulus<NumericType>{this->value + shear_modulus.value};
  }

  constexpr ShearModulus<NumericType> operator-(
      const ShearModulus<NumericType>& shear_modulus) const {
    return ShearModulus<NumericType>{this->value - shear_modulus.value};
  }

  constexpr ShearModulus<NumericType> operator*(const NumericType number) const {
    return ShearModulus<NumericType>{this->value * number};
  }

  constexpr ShearModulus<NumericType> operator/(const NumericType number) const {
    return ShearModulus<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(const ShearModulus<NumericType>& shear_modulus) const noexcept {
    return this->value / shear_modulus.value;
  }

  constexpr void operator+=(const ShearModulus<NumericType>& shear_modulus) noexcept {
    this->value += shear_modulus.value;
  }

  constexpr void operator-=(const ShearModulus<NumericType>& shear_modulus) noexcept {
    this->value -= shear_modulus.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a shear modulus with a given value expressed in the standard
  /// pressure unit.
  explicit constexpr ShearModulus(const NumericType value)
    : DimensionalScalar<Unit::Pressure, NumericType>(value) {}

  friend class ConstitutiveModel;
};

template <typename NumericType>
inline constexpr bool operator==(
    const ShearModulus<NumericType>& left, const ShearModulus<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const ShearModulus<NumericType>& left, const ShearModulus<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const ShearModulus<NumericType>& left, const ShearModulus<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const ShearModulus<NumericType>& left, const ShearModulus<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const ShearModulus<NumericType>& left, const ShearModulus<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const ShearModulus<NumericType>& left, const ShearModulus<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const ShearModulus<NumericType>& shear_modulus) {
  stream << shear_modulus.Print();
  return stream;
}

template <typename NumericType>
inline constexpr ShearModulus<NumericType> operator*(
    const NumericType number, const ShearModulus<NumericType>& shear_modulus) {
  return shear_modulus * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::ShearModulus<NumericType>> {
  inline size_t operator()(const PhQ::ShearModulus<NumericType>& shear_modulus) const {
    return hash<NumericType>()(shear_modulus.Value());
  }
};

}  // namespace std

#endif  // PHQ_SHEAR_MODULUS_HPP
