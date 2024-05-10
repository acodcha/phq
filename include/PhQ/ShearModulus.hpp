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

#ifndef PHQ_SHEAR_MODULUS_HPP
#define PHQ_SHEAR_MODULUS_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Shear modulus of elasticity of a deformable solid material. A measure of a deformable solid
// material's elastic modulus.
template <typename Number = double>
class ShearModulus : public DimensionalScalar<Unit::Pressure, Number> {
public:
  // Default constructor. Constructs a shear modulus with an uninitialized value.
  ShearModulus() = default;

  // Constructor. Constructs a shear modulus with a given value expressed in a given pressure unit.
  ShearModulus(const Number value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, Number>(value, unit) {}

  // Destructor. Destroys this shear modulus.
  ~ShearModulus() noexcept = default;

  // Copy constructor. Constructs a shear modulus by copying another one.
  constexpr ShearModulus(const ShearModulus<Number>& other) = default;

  // Copy constructor. Constructs a shear modulus by copying another one.
  template <typename OtherNumber>
  explicit constexpr ShearModulus(const ShearModulus<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a shear modulus by moving another one.
  constexpr ShearModulus(ShearModulus<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this shear modulus by copying another one.
  constexpr ShearModulus<Number>& operator=(const ShearModulus<Number>& other) = default;

  // Copy assignment operator. Assigns this shear modulus by copying another one.
  template <typename OtherNumber>
  constexpr ShearModulus<Number>& operator=(const ShearModulus<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this shear modulus by moving another one.
  constexpr ShearModulus<Number>& operator=(ShearModulus<Number>&& other) noexcept = default;

  // Statically creates a shear modulus of zero.
  static constexpr ShearModulus<Number> Zero() {
    return ShearModulus<Number>{static_cast<Number>(0)};
  }

  // Statically creates a shear modulus with a given value expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr ShearModulus<Number> Create(const Number value) {
    return ShearModulus<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr ShearModulus<Number> operator+(const ShearModulus<Number>& shear_modulus) const {
    return ShearModulus<Number>{value + shear_modulus.value};
  }

  constexpr ShearModulus<Number> operator-(const ShearModulus<Number>& shear_modulus) const {
    return ShearModulus<Number>{value - shear_modulus.value};
  }

  constexpr ShearModulus<Number> operator*(const Number number) const {
    return ShearModulus<Number>{value * number};
  }

  constexpr ShearModulus<Number> operator/(const Number number) const {
    return ShearModulus<Number>{value / number};
  }

  constexpr Number operator/(const ShearModulus<Number>& shear_modulus) const noexcept {
    return value / shear_modulus.value;
  }

  constexpr void operator+=(const ShearModulus<Number>& shear_modulus) noexcept {
    value += shear_modulus.value;
  }

  constexpr void operator-=(const ShearModulus<Number>& shear_modulus) noexcept {
    value -= shear_modulus.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a shear modulus with a given value expressed in the standard pressure
  // unit.
  explicit constexpr ShearModulus(const Number value)
    : DimensionalScalar<Unit::Pressure, Number>(value) {}

  template <typename OtherNumber>
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
