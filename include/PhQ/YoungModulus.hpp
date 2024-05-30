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

#ifndef PHQ_YOUNG_MODULUS_HPP
#define PHQ_YOUNG_MODULUS_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

/// \brief Young's modulus of elasticity of a deformable solid material. A measure of a deformable
/// solid material's elastic modulus. For other measures of a material's elastic modulus, see
/// PhQ::ShearModulus, PhQ::IsentropicBulkModulus, PhQ::IsothermalBulkModulus, PhQ::LameModulus,
/// PhQ::PWaveModulus, and PhQ::PoissonRatio.
template <typename NumericType = double>
class YoungModulus : public DimensionalScalar<Unit::Pressure, NumericType> {
public:
  /// \brief Default constructor. Constructs a Young's modulus with an uninitialized value.
  YoungModulus() = default;

  /// \brief Constructor. Constructs a Young's modulus with a given value expressed in a given
  /// pressure unit.
  YoungModulus(const NumericType value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, NumericType>(value, unit) {}

  /// \brief Destructor. Destroys this Young's modulus.
  ~YoungModulus() noexcept = default;

  /// \brief Copy constructor. Constructs a Young's modulus by copying another one.
  constexpr YoungModulus(const YoungModulus<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a Young's modulus by copying another one.
  template <typename OtherNumericType>
  explicit constexpr YoungModulus(const YoungModulus<OtherNumericType>& other)
    : YoungModulus(static_cast<NumericType>(other.Value())) {}

  /// \brief Move constructor. Constructs a Young's modulus by moving another one.
  constexpr YoungModulus(YoungModulus<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this Young's modulus by copying another one.
  constexpr YoungModulus<NumericType>& operator=(const YoungModulus<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this Young's modulus by copying another one.
  template <typename OtherNumericType>
  constexpr YoungModulus<NumericType>& operator=(const YoungModulus<OtherNumericType>& other) {
    this->value = static_cast<NumericType>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this Young's modulus by moving another one.
  constexpr YoungModulus<NumericType>& operator=(
      YoungModulus<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a Young's modulus of zero.
  static constexpr YoungModulus<NumericType> Zero() {
    return YoungModulus<NumericType>{static_cast<NumericType>(0)};
  }

  /// \brief Statically creates a Young's modulus with a given value expressed in a given pressure
  /// unit.
  template <Unit::Pressure Unit>
  static constexpr YoungModulus<NumericType> Create(const NumericType value) {
    return YoungModulus<NumericType>{
        ConvertStatically<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr YoungModulus<NumericType> operator+(
      const YoungModulus<NumericType>& young_modulus) const {
    return YoungModulus<NumericType>{this->value + young_modulus.value};
  }

  constexpr YoungModulus<NumericType> operator-(
      const YoungModulus<NumericType>& young_modulus) const {
    return YoungModulus<NumericType>{this->value - young_modulus.value};
  }

  constexpr YoungModulus<NumericType> operator*(const NumericType number) const {
    return YoungModulus<NumericType>{this->value * number};
  }

  constexpr YoungModulus<NumericType> operator/(const NumericType number) const {
    return YoungModulus<NumericType>{this->value / number};
  }

  constexpr NumericType operator/(const YoungModulus<NumericType>& young_modulus) const noexcept {
    return this->value / young_modulus.value;
  }

  constexpr void operator+=(const YoungModulus<NumericType>& young_modulus) noexcept {
    this->value += young_modulus.value;
  }

  constexpr void operator-=(const YoungModulus<NumericType>& young_modulus) noexcept {
    this->value -= young_modulus.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a Young's modulus with a given value expressed in the standard
  /// pressure unit.
  explicit constexpr YoungModulus(const NumericType value)
    : DimensionalScalar<Unit::Pressure, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const YoungModulus<NumericType>& left, const YoungModulus<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const YoungModulus<NumericType>& left, const YoungModulus<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const YoungModulus<NumericType>& left, const YoungModulus<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const YoungModulus<NumericType>& left, const YoungModulus<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const YoungModulus<NumericType>& left, const YoungModulus<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const YoungModulus<NumericType>& left, const YoungModulus<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const YoungModulus<NumericType>& young_modulus) {
  stream << young_modulus.Print();
  return stream;
}

template <typename NumericType>
inline constexpr YoungModulus<NumericType> operator*(
    const NumericType number, const YoungModulus<NumericType>& young_modulus) {
  return young_modulus * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::YoungModulus<NumericType>> {
  inline size_t operator()(const PhQ::YoungModulus<NumericType>& young_modulus) const {
    return hash<NumericType>()(young_modulus.Value());
  }
};

}  // namespace std

#endif  // PHQ_YOUNG_MODULUS_HPP
