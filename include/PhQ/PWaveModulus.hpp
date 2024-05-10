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

#ifndef PHQ_PWAVE_MODULUS_HPP
#define PHQ_PWAVE_MODULUS_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// P-wave modulus of elasticity of a deformable solid material. A measure of a deformable solid
// material's elastic modulus.
template <typename Number = double>
class PWaveModulus : public DimensionalScalar<Unit::Pressure, Number> {
public:
  // Default constructor. Constructs a P-wave modulus with an uninitialized value.
  PWaveModulus() = default;

  // Constructor. Constructs a P-wave modulus with a given value expressed in a given pressure unit.
  PWaveModulus(const Number value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure, Number>(value, unit) {}

  // Destructor. Destroys this P-wave modulus.
  ~PWaveModulus() noexcept = default;

  // Copy constructor. Constructs a P-wave modulus by copying another one.
  constexpr PWaveModulus(const PWaveModulus<Number>& other) = default;

  // Copy constructor. Constructs a P-wave modulus by copying another one.
  template <typename OtherNumber>
  explicit constexpr PWaveModulus(const PWaveModulus<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a P-wave modulus by moving another one.
  constexpr PWaveModulus(PWaveModulus<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this P-wave modulus by copying another one.
  constexpr PWaveModulus<Number>& operator=(const PWaveModulus<Number>& other) = default;

  // Copy assignment operator. Assigns this P-wave modulus by copying another one.
  template <typename OtherNumber>
  constexpr PWaveModulus<Number>& operator=(const PWaveModulus<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this P-wave modulus by moving another one.
  constexpr PWaveModulus<Number>& operator=(PWaveModulus<Number>&& other) noexcept = default;

  // Statically creates a P-wave modulus of zero.
  static constexpr PWaveModulus<Number> Zero() {
    return PWaveModulus<Number>{static_cast<Number>(0)};
  }

  // Statically creates a P-wave modulus with a given value expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr PWaveModulus<Number> Create(const Number value) {
    return PWaveModulus<Number>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr PWaveModulus<Number> operator+(const PWaveModulus<Number>& p_wave_modulus) const {
    return PWaveModulus<Number>{value + p_wave_modulus.value};
  }

  constexpr PWaveModulus<Number> operator-(const PWaveModulus<Number>& p_wave_modulus) const {
    return PWaveModulus<Number>{value - p_wave_modulus.value};
  }

  constexpr PWaveModulus<Number> operator*(const Number number) const {
    return PWaveModulus<Number>{value * number};
  }

  constexpr PWaveModulus<Number> operator/(const Number number) const {
    return PWaveModulus<Number>{value / number};
  }

  constexpr Number operator/(const PWaveModulus<Number>& p_wave_modulus) const noexcept {
    return value / p_wave_modulus.value;
  }

  constexpr void operator+=(const PWaveModulus<Number>& p_wave_modulus) noexcept {
    value += p_wave_modulus.value;
  }

  constexpr void operator-=(const PWaveModulus<Number>& p_wave_modulus) noexcept {
    value -= p_wave_modulus.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a P-wave modulus with a given value expressed in the standard pressure
  // unit.
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
