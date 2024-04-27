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
class ShearModulus : public DimensionalScalar<Unit::Pressure> {
public:
  // Default constructor. Constructs a shear modulus with an uninitialized value.
  ShearModulus() = default;

  // Constructor. Constructs a shear modulus with a given value expressed in a given pressure unit.
  ShearModulus(const double value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure>(value, unit) {}

  // Destructor. Destroys this shear modulus.
  ~ShearModulus() noexcept = default;

  // Copy constructor. Constructs a shear modulus by copying another one.
  constexpr ShearModulus(const ShearModulus& other) = default;

  // Move constructor. Constructs a shear modulus by moving another one.
  constexpr ShearModulus(ShearModulus&& other) noexcept = default;

  // Copy assignment operator. Assigns this shear modulus by copying another one.
  constexpr ShearModulus& operator=(const ShearModulus& other) = default;

  // Move assignment operator. Assigns this shear modulus by moving another one.
  constexpr ShearModulus& operator=(ShearModulus&& other) noexcept = default;

  // Statically creates a shear modulus of zero.
  static constexpr ShearModulus Zero() {
    return ShearModulus{0.0};
  }

  // Statically creates a shear modulus with a given value expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr ShearModulus Create(const double value) {
    return ShearModulus{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr ShearModulus operator+(const ShearModulus& shear_modulus) const {
    return ShearModulus{value + shear_modulus.value};
  }

  constexpr ShearModulus operator-(const ShearModulus& shear_modulus) const {
    return ShearModulus{value - shear_modulus.value};
  }

  constexpr ShearModulus operator*(const double number) const {
    return ShearModulus{value * number};
  }

  constexpr ShearModulus operator/(const double number) const {
    return ShearModulus{value / number};
  }

  constexpr double operator/(const ShearModulus& shear_modulus) const noexcept {
    return value / shear_modulus.value;
  }

  constexpr void operator+=(const ShearModulus& shear_modulus) noexcept {
    value += shear_modulus.value;
  }

  constexpr void operator-=(const ShearModulus& shear_modulus) noexcept {
    value -= shear_modulus.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a shear modulus with a given value expressed in the standard pressure
  // unit.
  explicit constexpr ShearModulus(const double value) : DimensionalScalar<Unit::Pressure>(value) {}

  friend class ConstitutiveModel;
};

inline constexpr bool operator==(const ShearModulus& left, const ShearModulus& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const ShearModulus& left, const ShearModulus& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const ShearModulus& left, const ShearModulus& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const ShearModulus& left, const ShearModulus& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const ShearModulus& left, const ShearModulus& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const ShearModulus& left, const ShearModulus& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const ShearModulus& shear_modulus) {
  stream << shear_modulus.Print();
  return stream;
}

inline constexpr ShearModulus operator*(const double number, const ShearModulus& shear_modulus) {
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

#endif  // PHQ_SHEAR_MODULUS_HPP
