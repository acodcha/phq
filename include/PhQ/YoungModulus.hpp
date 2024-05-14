// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/physical-quantities
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

// Young's modulus of elasticity of a deformable solid material. A measure of a deformable solid
// material's elastic modulus.
template <typename Number = double>
class YoungModulus : public DimensionalScalar<Unit::Pressure, Number> {
public:
  // Default constructor. Constructs a Young's modulus with an uninitialized value.
  YoungModulus() = default;

  // Constructor. Constructs a Young's modulus with a given value expressed in a given pressure
  // unit.
  YoungModulus(const Number value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, Number>(value, unit) {}

  // Destructor. Destroys this Young's modulus.
  ~YoungModulus() noexcept = default;

  // Copy constructor. Constructs a Young's modulus by copying another one.
  constexpr YoungModulus(const YoungModulus<Number>& other) = default;

  // Copy constructor. Constructs a Young's modulus by copying another one.
  template <typename OtherNumber>
  explicit constexpr YoungModulus(const YoungModulus<OtherNumber>& other)
    : YoungModulus(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a Young's modulus by moving another one.
  constexpr YoungModulus(YoungModulus<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this Young's modulus by copying another one.
  constexpr YoungModulus<Number>& operator=(const YoungModulus<Number>& other) = default;

  // Copy assignment operator. Assigns this Young's modulus by copying another one.
  template <typename OtherNumber>
  constexpr YoungModulus<Number>& operator=(const YoungModulus<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this Young's modulus by moving another one.
  constexpr YoungModulus<Number>& operator=(YoungModulus<Number>&& other) noexcept = default;

  // Statically creates a Young's modulus of zero.
  static constexpr YoungModulus<Number> Zero() {
    return YoungModulus<Number>{static_cast<Number>(0)};
  }

  // Statically creates a Young's modulus with a given value expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr YoungModulus<Number> Create(const Number value) {
    return YoungModulus<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr YoungModulus<Number> operator+(const YoungModulus<Number>& young_modulus) const {
    return YoungModulus<Number>{this->value + young_modulus.value};
  }

  constexpr YoungModulus<Number> operator-(const YoungModulus<Number>& young_modulus) const {
    return YoungModulus<Number>{this->value - young_modulus.value};
  }

  constexpr YoungModulus<Number> operator*(const Number number) const {
    return YoungModulus<Number>{this->value * number};
  }

  constexpr YoungModulus<Number> operator/(const Number number) const {
    return YoungModulus<Number>{this->value / number};
  }

  constexpr Number operator/(const YoungModulus<Number>& young_modulus) const noexcept {
    return this->value / young_modulus.value;
  }

  constexpr void operator+=(const YoungModulus<Number>& young_modulus) noexcept {
    this->value += young_modulus.value;
  }

  constexpr void operator-=(const YoungModulus<Number>& young_modulus) noexcept {
    this->value -= young_modulus.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a Young's modulus with a given value expressed in the standard pressure
  // unit.
  explicit constexpr YoungModulus(const Number value)
    : DimensionalScalar<Unit::Pressure, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const YoungModulus<Number>& left, const YoungModulus<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const YoungModulus<Number>& left, const YoungModulus<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const YoungModulus<Number>& left, const YoungModulus<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const YoungModulus<Number>& left, const YoungModulus<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const YoungModulus<Number>& left, const YoungModulus<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const YoungModulus<Number>& left, const YoungModulus<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const YoungModulus<Number>& young_modulus) {
  stream << young_modulus.Print();
  return stream;
}

template <typename Number>
inline constexpr YoungModulus<Number> operator*(
    const Number number, const YoungModulus<Number>& young_modulus) {
  return young_modulus * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::YoungModulus<Number>> {
  inline size_t operator()(const PhQ::YoungModulus<Number>& young_modulus) const {
    return hash<Number>()(young_modulus.Value());
  }
};

}  // namespace std

#endif  // PHQ_YOUNG_MODULUS_HPP
