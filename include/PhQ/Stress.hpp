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

#ifndef PHQ_STRESS_HPP
#define PHQ_STRESS_HPP

#include <array>
#include <cmath>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalSymmetricDyad.hpp"
#include "Direction.hpp"
#include "ScalarStress.hpp"
#include "StaticPressure.hpp"
#include "SymmetricDyad.hpp"
#include "Traction.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

// Cauchy stress symmetric dyadic tensor. See also PhQ::ScalarStress.
template <typename Number = double>
class Stress : public DimensionalSymmetricDyad<Unit::Pressure, Number> {
public:
  // Default constructor. Constructs a stress tensor with an uninitialized value.
  Stress() = default;

  // Constructor. Constructs a stress tensor with a given value expressed in a given pressure unit.
  Stress(const SymmetricDyad<Number>& value, const Unit::Pressure unit)
    : DimensionalSymmetricDyad<Unit::Pressure, Number>(value, unit) {}

  // Constructor. Constructs a stress tensor from a given static pressure using the definition of
  // stress due to pressure. Since pressure is compressive, the negative of the static pressure
  // contributes to the stress.
  constexpr explicit Stress(const StaticPressure<Number>& static_pressure)
    : Stress<Number>({-1.0 * static_pressure.Value(), 0.0, 0.0, -1.0 * static_pressure.Value(), 0.0,
                      -1.0 * static_pressure.Value()}) {}

  // Destructor. Destroys this stress tensor.
  ~Stress() noexcept = default;

  // Copy constructor. Constructs a stress tensor by copying another one.
  constexpr Stress(const Stress<Number>& other) = default;

  // Copy constructor. Constructs a stress tensor by copying another one.
  template <typename OtherNumber>
  explicit constexpr Stress(const Stress<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a stress tensor by moving another one.
  constexpr Stress(Stress<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this stress tensor by copying another one.
  constexpr Stress<Number>& operator=(const Stress<Number>& other) = default;

  // Copy assignment operator. Assigns this stress tensor by copying another one.
  template <typename OtherNumber>
  constexpr Stress<Number>& operator=(const Stress<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this stress tensor by moving another one.
  constexpr Stress<Number>& operator=(Stress<Number>&& other) noexcept = default;

  // Statically creates a stress tensor of zero.
  static constexpr Stress<Number> Zero() {
    return Stress<Number>{SymmetricDyad<Number>::Zero()};
  }

  // Statically creates a stress tensor from the given xx, xy, xz, yy, yz, and zz Cartesian
  // components expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Stress<Number> Create(const Number xx, const Number xy, const Number xz,
                                         const Number yy, const Number yz, const Number zz) {
    return Stress<Number>{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
        SymmetricDyad<Number>{xx, xy, xz, yy, yz, zz})};
  }

  // Statically creates a stress tensor from the given xx, xy, xz, yy, yz, and zz Cartesian
  // components expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Stress<Number> Create(const std::array<Number, 6>& xx_xy_xz_yy_yz_zz) {
    return Stress<Number>{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
        SymmetricDyad<Number>{xx_xy_xz_yy_yz_zz})};
  }

  // Statically creates a stress tensor with a given value expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Stress<Number> Create(const SymmetricDyad<Number>& value) {
    return Stress<Number>{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  // Returns the xx Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> xx() const noexcept {
    return ScalarStress<Number>{value.xx()};
  }

  // Returns the xy = yx Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> xy() const noexcept {
    return ScalarStress<Number>{value.xy()};
  }

  // Returns the xz = zx Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> xz() const noexcept {
    return ScalarStress<Number>{value.xz()};
  }

  // Returns the yx = xy Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> yx() const noexcept {
    return ScalarStress<Number>{value.yx()};
  }

  // Returns the yy Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> yy() const noexcept {
    return ScalarStress<Number>{value.yy()};
  }

  // Returns the yz = zy Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> yz() const noexcept {
    return ScalarStress<Number>{value.yz()};
  }

  // Returns the zx = xz Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> zx() const noexcept {
    return ScalarStress<Number>{value.zx()};
  }

  // Returns the zy = yz Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> zy() const noexcept {
    return ScalarStress<Number>{value.zy()};
  }

  // Returns the zz Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> zz() const noexcept {
    return ScalarStress<Number>{value.zz()};
  }

  // Creates a traction from this stress tensor using the definition of traction.
  [[nodiscard]] constexpr PhQ::Traction<Number> Traction(const Direction<Number>& direction) const {
    return PhQ::Traction<Number>{*this, direction};
  }

  // Computes the von Mises stress of this stress tensor using the von Mises yield criterion.
  [[nodiscard]] constexpr ScalarStress<Number> VonMises() const {
    return ScalarStress<Number>{std::sqrt(
        0.5
        * (std::pow(value.xx() - value.yy(), 2) + std::pow(value.yy() - value.zz(), 2)
           + std::pow(value.zz() - value.xx(), 2)
           + 6.0 * (std::pow(value.xy(), 2) + std::pow(value.xz(), 2) + std::pow(value.yz(), 2))))};
  }

  constexpr Stress<Number> operator+(const Stress<Number>& stress) const {
    return Stress<Number>{value + stress.value};
  }

  constexpr Stress<Number> operator-(const Stress<Number>& stress) const {
    return Stress<Number>{value - stress.value};
  }

  constexpr Stress<Number> operator*(const Number number) const {
    return Stress<Number>{value * number};
  }

  constexpr Stress<Number> operator/(const Number number) const {
    return Stress<Number>{value / number};
  }

  constexpr void operator+=(const Stress<Number>& stress) noexcept {
    value += stress.value;
  }

  constexpr void operator-=(const Stress<Number>& stress) noexcept {
    value -= stress.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a stress tensor with a given value expressed in the standard pressure
  // unit.
  explicit constexpr Stress(const SymmetricDyad<Number>& value)
    : DimensionalSymmetricDyad<Unit::Pressure>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const Stress<Number>& left, const Stress<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const Stress<Number>& left, const Stress<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const Stress<Number>& left, const Stress<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const Stress<Number>& left, const Stress<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const Stress<Number>& left, const Stress<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const Stress<Number>& left, const Stress<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(std::ostream& stream, const Stress<Number>& stress) {
  stream << stress.Print();
  return stream;
}

template <typename Number>
inline constexpr Stress<Number> operator*(const Number number, const Stress<Number>& stress) {
  return stress * number;
}

template <typename Number>
inline constexpr Traction<Number>::Traction(
    const Stress<Number>& stress, const PhQ::Direction<Number>& direction)
  : Traction<Number>({stress.Value() * direction}) {}

template <typename Number>
inline constexpr PhQ::Stress<Number> StaticPressure<Number>::Stress() const {
  return PhQ::Stress<Number>{*this};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::Stress<Number>> {
  inline size_t operator()(const PhQ::Stress<Number>& stress) const {
    return hash<PhQ::SymmetricDyad<Number>>()(stress.Value());
  }
};

}  // namespace std

#endif  // PHQ_STRESS_HPP
