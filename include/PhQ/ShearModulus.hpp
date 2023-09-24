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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_SHEAR_MODULUS_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_SHEAR_MODULUS_HPP

#include "DimensionalScalarQuantity.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Shear modulus of elasticity of a deformable solid material. A measure of a
// deformable solid material's elastic modulus.
class ShearModulus : public DimensionalScalarQuantity<Unit::Pressure> {
public:
  // Default constructor. Constructs a shear modulus with an uninitialized
  // value.
  ShearModulus() = default;

  // Constructor. Constructs a shear modulus with a given value expressed in a
  // given pressure unit.
  ShearModulus(const double value, const Unit::Pressure unit)
    : DimensionalScalarQuantity<Unit::Pressure>(value, unit) {}

  // Destructor. Destroys this shear modulus.
  ~ShearModulus() noexcept = default;

  // Copy constructor. Constructs a shear modulus by copying another one.
  constexpr ShearModulus(const ShearModulus& other) = default;

  // Move constructor. Constructs a shear modulus by moving another one.
  constexpr ShearModulus(ShearModulus&& other) noexcept = default;

  // Copy assignment operator. Assigns this shear modulus by copying another
  // one.
  constexpr ShearModulus& operator=(const ShearModulus& other) = default;

  // Move assignment operator. Assigns this shear modulus by moving another one.
  constexpr ShearModulus& operator=(ShearModulus&& other) noexcept = default;

  // Statically creates a shear modulus of zero.
  static constexpr ShearModulus Zero() {
    return ShearModulus{0.0};
  }

  // Statically creates a shear modulus with a given value expressed in a given
  // pressure unit.
  template <Unit::Pressure Unit>
  static constexpr ShearModulus Create(const double value) {
    return ShearModulus{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
            value)};
  }

  constexpr ShearModulus operator+(const ShearModulus& shear_modulus) const {
    return ShearModulus{value_ + shear_modulus.value_};
  }

  constexpr ShearModulus operator-(const ShearModulus& shear_modulus) const {
    return ShearModulus{value_ - shear_modulus.value_};
  }

  constexpr ShearModulus operator*(const double number) const {
    return ShearModulus{value_ * number};
  }

  constexpr ShearModulus operator/(const double number) const {
    return ShearModulus{value_ / number};
  }

  constexpr double operator/(const ShearModulus& shear_modulus) const noexcept {
    return value_ / shear_modulus.value_;
  }

  constexpr void operator+=(const ShearModulus& shear_modulus) noexcept {
    value_ += shear_modulus.value_;
  }

  constexpr void operator-=(const ShearModulus& shear_modulus) noexcept {
    value_ -= shear_modulus.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a shear modulus with a given value expressed in the
  // standard pressure unit.
  explicit constexpr ShearModulus(const double value)
    : DimensionalScalarQuantity<Unit::Pressure>(value) {}

  friend class ConstitutiveModel;
};

inline constexpr bool operator==(
    const ShearModulus& left, const ShearModulus& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const ShearModulus& left, const ShearModulus& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const ShearModulus& left, const ShearModulus& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const ShearModulus& left, const ShearModulus& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const ShearModulus& left, const ShearModulus& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const ShearModulus& left, const ShearModulus& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const ShearModulus& shear_modulus) {
  stream << shear_modulus.Print();
  return stream;
}

inline constexpr ShearModulus operator*(
    const double number, const ShearModulus& shear_modulus) {
  return shear_modulus * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ShearModulus> {
  inline size_t operator()(const PhQ::ShearModulus& shear_modulus) const {
    return hash<double>()(shear_modulus.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_SHEAR_MODULUS_HPP
