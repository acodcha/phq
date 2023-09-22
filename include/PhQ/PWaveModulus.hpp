// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_PWAVE_MODULUS_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_PWAVE_MODULUS_HPP

#include "DimensionalScalarQuantity.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// P-wave modulus of elasticity of a deformable solid material. A measure of a
// deformable solid material's elastic modulus.
class PWaveModulus : public DimensionalScalarQuantity<Unit::Pressure> {
public:
  constexpr PWaveModulus() : DimensionalScalarQuantity<Unit::Pressure>() {}

  PWaveModulus(const double value, const Unit::Pressure unit)
    : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  static constexpr PWaveModulus Zero() {
    return PWaveModulus{0.0};
  }

  template <Unit::Pressure Unit>
  static constexpr PWaveModulus Create(const double value) {
    return PWaveModulus{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
            value)};
  }

  constexpr PWaveModulus operator+(const PWaveModulus& p_wave_modulus) const {
    return PWaveModulus{value_ + p_wave_modulus.value_};
  }

  constexpr PWaveModulus operator-(const PWaveModulus& p_wave_modulus) const {
    return PWaveModulus{value_ - p_wave_modulus.value_};
  }

  constexpr PWaveModulus operator*(const double number) const {
    return PWaveModulus{value_ * number};
  }

  constexpr PWaveModulus operator/(const double number) const {
    return PWaveModulus{value_ / number};
  }

  constexpr double operator/(
      const PWaveModulus& p_wave_modulus) const noexcept {
    return value_ / p_wave_modulus.value_;
  }

  constexpr void operator+=(const PWaveModulus& p_wave_modulus) noexcept {
    value_ += p_wave_modulus.value_;
  }

  constexpr void operator-=(const PWaveModulus& p_wave_modulus) noexcept {
    value_ -= p_wave_modulus.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr PWaveModulus(const double value)
    : DimensionalScalarQuantity<Unit::Pressure>(value) {}
};

inline constexpr bool operator==(
    const PWaveModulus& left, const PWaveModulus& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const PWaveModulus& left, const PWaveModulus& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const PWaveModulus& left, const PWaveModulus& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const PWaveModulus& left, const PWaveModulus& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const PWaveModulus& left, const PWaveModulus& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const PWaveModulus& left, const PWaveModulus& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const PWaveModulus& p_wave_modulus) {
  stream << p_wave_modulus.Print();
  return stream;
}

inline constexpr PWaveModulus operator*(
    const double number, const PWaveModulus& p_wave_modulus) {
  return p_wave_modulus * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::PWaveModulus> {
  inline size_t operator()(const PhQ::PWaveModulus& p_wave_modulus) const {
    return hash<double>()(p_wave_modulus.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_PWAVE_MODULUS_HPP
