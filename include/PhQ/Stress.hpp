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
class Stress : public DimensionalSymmetricDyad<Unit::Pressure> {
public:
  // Default constructor. Constructs a stress tensor with an uninitialized value.
  Stress() = default;

  // Constructor. Constructs a stress tensor with a given value expressed in a given pressure unit.
  Stress(const SymmetricDyad& value, const Unit::Pressure unit)
    : DimensionalSymmetricDyad<Unit::Pressure>(value, unit) {}

  // Constructor. Constructs a stress tensor from a given static pressure using the definition of
  // stress due to pressure. Since pressure is compressive, the negative of the static pressure
  // contributes to the stress.
  constexpr explicit Stress(const StaticPressure& static_pressure)
    : Stress({-1.0 * static_pressure.Value(), 0.0, 0.0, -1.0 * static_pressure.Value(), 0.0,
              -1.0 * static_pressure.Value()}) {}

  // Destructor. Destroys this stress tensor.
  ~Stress() noexcept = default;

  // Copy constructor. Constructs a stress tensor by copying another one.
  constexpr Stress(const Stress& other) = default;

  // Move constructor. Constructs a stress tensor by moving another one.
  constexpr Stress(Stress&& other) noexcept = default;

  // Copy assignment operator. Assigns this stress tensor by copying another one.
  constexpr Stress& operator=(const Stress& other) = default;

  // Move assignment operator. Assigns this stress tensor by moving another one.
  constexpr Stress& operator=(Stress&& other) noexcept = default;

  // Statically creates a stress tensor of zero.
  static constexpr Stress Zero() {
    return Stress{SymmetricDyad::Zero()};
  }

  // Statically creates a stress tensor from the given xx, xy, xz, yy, yz, and zz Cartesian
  // components expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Stress Create(const double xx, const double xy, const double xz, const double yy,
                                 const double yz, const double zz) {
    return Stress{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
        SymmetricDyad{xx, xy, xz, yy, yz, zz})};
  }

  // Statically creates a stress tensor from the given xx, xy, xz, yy, yz, and zz Cartesian
  // components expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Stress Create(const std::array<double, 6>& xx_xy_xz_yy_yz_zz) {
    return Stress{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
        SymmetricDyad{xx_xy_xz_yy_yz_zz})};
  }

  // Statically creates a stress tensor with a given value expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Stress Create(const SymmetricDyad& value) {
    return Stress{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  // Returns the xx Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress xx() const noexcept {
    return ScalarStress{value_.xx()};
  }

  // Returns the xy = yx Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress xy() const noexcept {
    return ScalarStress{value_.xy()};
  }

  // Returns the xz = zx Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress xz() const noexcept {
    return ScalarStress{value_.xz()};
  }

  // Returns the yx = xy Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress yx() const noexcept {
    return ScalarStress{value_.yx()};
  }

  // Returns the yy Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress yy() const noexcept {
    return ScalarStress{value_.yy()};
  }

  // Returns the yz = zy Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress yz() const noexcept {
    return ScalarStress{value_.yz()};
  }

  // Returns the zx = xz Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress zx() const noexcept {
    return ScalarStress{value_.zx()};
  }

  // Returns the zy = yz Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress zy() const noexcept {
    return ScalarStress{value_.zy()};
  }

  // Returns the zz Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress zz() const noexcept {
    return ScalarStress{value_.zz()};
  }

  // Creates a traction from this stress tensor using the definition of traction.
  [[nodiscard]] constexpr PhQ::Traction Traction(const Direction& direction) const {
    return {*this, direction};
  }

  // Computes the von Mises stress of this stress tensor using the von Mises yield criterion.
  [[nodiscard]] constexpr ScalarStress VonMises() const {
    return ScalarStress{std::sqrt(
        0.5
        * (std::pow(value_.xx() - value_.yy(), 2) + std::pow(value_.yy() - value_.zz(), 2)
           + std::pow(value_.zz() - value_.xx(), 2)
           + 6.0
                 * (std::pow(value_.xy(), 2) + std::pow(value_.xz(), 2)
                    + std::pow(value_.yz(), 2))))};
  }

  constexpr Stress operator+(const Stress& stress) const {
    return Stress{value_ + stress.value_};
  }

  constexpr Stress operator-(const Stress& stress) const {
    return Stress{value_ - stress.value_};
  }

  constexpr Stress operator*(const double number) const {
    return Stress{value_ * number};
  }

  constexpr Stress operator/(const double number) const {
    return Stress{value_ / number};
  }

  constexpr void operator+=(const Stress& stress) noexcept {
    value_ += stress.value_;
  }

  constexpr void operator-=(const Stress& stress) noexcept {
    value_ -= stress.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a stress tensor with a given value expressed in the standard pressure
  // unit.
  explicit constexpr Stress(const SymmetricDyad& value)
    : DimensionalSymmetricDyad<Unit::Pressure>(value) {}
};

inline constexpr bool operator==(const Stress& left, const Stress& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const Stress& left, const Stress& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const Stress& left, const Stress& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const Stress& left, const Stress& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const Stress& left, const Stress& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const Stress& left, const Stress& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(std::ostream& stream, const Stress& stress) {
  stream << stress.Print();
  return stream;
}

inline constexpr Stress operator*(const double number, const Stress& stress) {
  return stress * number;
}

inline constexpr Traction::Traction(const Stress& stress, const PhQ::Direction& direction)
  : Traction({stress.Value() * direction}) {}

inline constexpr PhQ::Stress StaticPressure::Stress() const {
  return PhQ::Stress{*this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::Stress> {
  inline size_t operator()(const PhQ::Stress& stress) const {
    return hash<PhQ::SymmetricDyad>()(stress.Value());
  }
};

}  // namespace std

#endif  // PHQ_STRESS_HPP
