// Copyright 2020-2024 Alexandre Coderre-Chabot
//
// Physical Quantities (PhQ): A C++ library of physical quantities, physical models, and units of
// measure for scientific computation. https://github.com/acodcha/physical-quantities
//
// Physical Quantities (PhQ) is free software: you can redistribute it and/or modify it under the
// terms of the GNU Lesser General Public License as published by the Free Software Foundation,
// either version 3 of the License, or (at your option) any later version. Physical Quantities (PhQ)
// is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the
// implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser
// General Public License for more details. You should have received a copy of the GNU Lesser
// General Public License along with Physical Quantities (PhQ). https://www.gnu.org/licenses

#ifndef PHQ_LAME_FIRST_MODULUS_HPP
#define PHQ_LAME_FIRST_MODULUS_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Lamé's first modulus of elasticity of a deformable solid material. First of the two Lamé
// parameters. A measure of a deformable solid material's elastic modulus.
template <typename Number = double>
class LameFirstModulus : public DimensionalScalar<Unit::Pressure, Number> {
public:
  // Default constructor. Constructs a Lamé's first modulus with an uninitialized value.
  LameFirstModulus() = default;

  // Constructor. Constructs a Lamé's first modulus with a given value expressed in a given pressure
  // unit.
  LameFirstModulus(const Number value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, Number>(value, unit) {}

  // Destructor. Destroys this Lamé's first modulus.
  ~LameFirstModulus() noexcept = default;

  // Copy constructor. Constructs a Lamé's first modulus by copying another one.
  constexpr LameFirstModulus(const LameFirstModulus<Number>& other) = default;

  // Copy constructor. Constructs a Lamé's first modulus by copying another one.
  template <typename OtherNumber>
  explicit constexpr LameFirstModulus(const LameFirstModulus<OtherNumber>& other)
    : LameFirstModulus(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a Lamé's first modulus by moving another one.
  constexpr LameFirstModulus(LameFirstModulus<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this Lamé's first modulus by copying another one.
  constexpr LameFirstModulus<Number>& operator=(const LameFirstModulus<Number>& other) = default;

  // Copy assignment operator. Assigns this Lamé's first modulus by copying another one.
  template <typename OtherNumber>
  constexpr LameFirstModulus<Number>& operator=(const LameFirstModulus<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this Lamé's first modulus by moving another one.
  constexpr LameFirstModulus<Number>& operator=(
      LameFirstModulus<Number>&& other) noexcept = default;

  // Statically creates a Lamé's first modulus of zero.
  static constexpr LameFirstModulus<Number> Zero() {
    return LameFirstModulus<Number>{static_cast<Number>(0)};
  }

  // Statically creates a Lamé's first modulus with a given value expressed in a given pressure
  // unit.
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
  // Constructor. Constructs a Lamé's first modulus with a given value expressed in the standard
  // pressure unit.
  explicit constexpr LameFirstModulus(const Number value)
    : DimensionalScalar<Unit::Pressure, Number>(value) {}

  template <typename OtherNumber>
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
