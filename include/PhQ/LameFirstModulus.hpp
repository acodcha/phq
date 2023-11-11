// Copyright 2020-2023 Alexandre Coderre-Chabot
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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_LAME_FIRST_MODULUS_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_LAME_FIRST_MODULUS_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Lamé's first modulus of elasticity of a deformable solid material. First of the two Lamé
// parameters. A measure of a deformable solid material's elastic modulus.
class LameFirstModulus : public DimensionalScalar<Unit::Pressure> {
public:
  // Default constructor. Constructs a Lamé's first modulus with an uninitialized value.
  LameFirstModulus() = default;

  // Constructor. Constructs a Lamé's first modulus with a given value expressed in a given pressure
  // unit.
  LameFirstModulus(const double value, const Unit::Pressure unit)
    : DimensionalScalar<Unit::Pressure>(value, unit) {}

  // Destructor. Destroys this Lamé's first modulus.
  ~LameFirstModulus() noexcept = default;

  // Copy constructor. Constructs a Lamé's first modulus by copying another one.
  constexpr LameFirstModulus(const LameFirstModulus& other) = default;

  // Move constructor. Constructs a Lamé's first modulus by moving another one.
  constexpr LameFirstModulus(LameFirstModulus&& other) noexcept = default;

  // Copy assignment operator. Assigns this Lamé's first modulus by copying another one.
  constexpr LameFirstModulus& operator=(const LameFirstModulus& other) = default;

  // Move assignment operator. Assigns this Lamé's first modulus by moving another one.
  constexpr LameFirstModulus& operator=(LameFirstModulus&& other) noexcept = default;

  // Statically creates a Lamé's first modulus of zero.
  static constexpr LameFirstModulus Zero() {
    return LameFirstModulus{0.0};
  }

  // Statically creates a Lamé's first modulus with a given value expressed in a given pressure
  // unit.
  template <Unit::Pressure Unit>
  static constexpr LameFirstModulus Create(const double value) {
    return LameFirstModulus{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  constexpr LameFirstModulus operator+(const LameFirstModulus& lame_first_modulus) const {
    return LameFirstModulus{value_ + lame_first_modulus.value_};
  }

  constexpr LameFirstModulus operator-(const LameFirstModulus& lame_first_modulus) const {
    return LameFirstModulus{value_ - lame_first_modulus.value_};
  }

  constexpr LameFirstModulus operator*(const double number) const {
    return LameFirstModulus{value_ * number};
  }

  constexpr LameFirstModulus operator/(const double number) const {
    return LameFirstModulus{value_ / number};
  }

  constexpr double operator/(const LameFirstModulus& lame_first_modulus) const noexcept {
    return value_ / lame_first_modulus.value_;
  }

  constexpr void operator+=(const LameFirstModulus& lame_first_modulus) noexcept {
    value_ += lame_first_modulus.value_;
  }

  constexpr void operator-=(const LameFirstModulus& lame_first_modulus) noexcept {
    value_ -= lame_first_modulus.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a Lamé's first modulus with a given value expressed in the standard
  // pressure unit.
  explicit constexpr LameFirstModulus(const double value)
    : DimensionalScalar<Unit::Pressure>(value) {}

  friend class ConstitutiveModel;
};

inline constexpr bool operator==(
    const LameFirstModulus& left, const LameFirstModulus& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const LameFirstModulus& left, const LameFirstModulus& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const LameFirstModulus& left, const LameFirstModulus& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const LameFirstModulus& left, const LameFirstModulus& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const LameFirstModulus& left, const LameFirstModulus& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const LameFirstModulus& left, const LameFirstModulus& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const LameFirstModulus& lame_first_modulus) {
  stream << lame_first_modulus.Print();
  return stream;
}

inline constexpr LameFirstModulus operator*(
    const double number, const LameFirstModulus& lame_first_modulus) {
  return lame_first_modulus * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::LameFirstModulus> {
  inline size_t operator()(const PhQ::LameFirstModulus& lame_first_modulus) const {
    return hash<double>()(lame_first_modulus.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_LAME_FIRST_MODULUS_HPP
