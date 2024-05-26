// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computation.
//
// Physical Quantities (PhQ) is hosted at:
//     https://github.com/acodcha/phq
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

#ifndef PHQ_STRESS_HPP
#define PHQ_STRESS_HPP

#include <array>
#include <cmath>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalSymmetricDyad.hpp"
#include "Direction.hpp"
#include "PlanarDirection.hpp"
#include "PlanarTraction.hpp"
#include "ScalarStress.hpp"
#include "StaticPressure.hpp"
#include "SymmetricDyad.hpp"
#include "Traction.hpp"
#include "Unit/Pressure.hpp"

namespace PhQ {

/// \brief Cauchy stress symmetric dyadic tensor. See also PhQ::ScalarStress.
template <typename Number = double>
class Stress : public DimensionalSymmetricDyad<Unit::Pressure, Number> {
public:
  /// \brief Default constructor. Constructs a stress tensor with an uninitialized value.
  Stress() = default;

  /// \brief Constructor. Constructs a stress tensor with a given value expressed in a given
  /// pressure unit.
  Stress(const SymmetricDyad<Number>& value, const Unit::Pressure unit)
    : DimensionalSymmetricDyad<Unit::Pressure, Number>(value, unit) {}

  /// \brief Constructor. Constructs a stress tensor from a given static pressure using the
  /// definition of stress due to pressure. Since pressure is compressive, the negative of the
  /// static pressure contributes to the stress.
  constexpr explicit Stress(const StaticPressure<Number>& static_pressure)
    : Stress<Number>(
        {static_cast<Number>(-1.0) * static_pressure.Value(), static_cast<Number>(0.0),
         static_cast<Number>(0.0), static_cast<Number>(-1.0) * static_pressure.Value(),
         static_cast<Number>(0.0), static_cast<Number>(-1.0) * static_pressure.Value()}) {}

  /// \brief Destructor. Destroys this stress tensor.
  ~Stress() noexcept = default;

  /// \brief Copy constructor. Constructs a stress tensor by copying another one.
  constexpr Stress(const Stress<Number>& other) = default;

  /// \brief Copy constructor. Constructs a stress tensor by copying another one.
  template <typename OtherNumber>
  explicit constexpr Stress(const Stress<OtherNumber>& other)
    : Stress(static_cast<SymmetricDyad<Number>>(other.Value())) {}

  /// \brief Move constructor. Constructs a stress tensor by moving another one.
  constexpr Stress(Stress<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this stress tensor by copying another one.
  constexpr Stress<Number>& operator=(const Stress<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this stress tensor by copying another one.
  template <typename OtherNumber>
  constexpr Stress<Number>& operator=(const Stress<OtherNumber>& other) {
    this->value = static_cast<SymmetricDyad<Number>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this stress tensor by moving another one.
  constexpr Stress<Number>& operator=(Stress<Number>&& other) noexcept = default;

  /// \brief Statically creates a stress tensor of zero.
  static constexpr Stress<Number> Zero() {
    return Stress<Number>{SymmetricDyad<Number>::Zero()};
  }

  /// \brief Statically creates a stress tensor from the given xx, xy, xz, yy, yz, and zz Cartesian
  /// components expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Stress<Number> Create(const Number xx, const Number xy, const Number xz,
                                         const Number yy, const Number yz, const Number zz) {
    return Stress<Number>{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
        SymmetricDyad<Number>{xx, xy, xz, yy, yz, zz})};
  }

  /// \brief Statically creates a stress tensor from the given xx, xy, xz, yy, yz, and zz Cartesian
  /// components expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Stress<Number> Create(const std::array<Number, 6>& xx_xy_xz_yy_yz_zz) {
    return Stress<Number>{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
        SymmetricDyad<Number>{xx_xy_xz_yy_yz_zz})};
  }

  /// \brief Statically creates a stress tensor with a given value expressed in a given pressure
  /// unit.
  template <Unit::Pressure Unit>
  static constexpr Stress<Number> Create(const SymmetricDyad<Number>& value) {
    return Stress<Number>{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  /// \brief Returns the xx Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> xx() const noexcept {
    return ScalarStress<Number>{this->value.xx()};
  }

  /// \brief Returns the xy = yx Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> xy() const noexcept {
    return ScalarStress<Number>{this->value.xy()};
  }

  /// \brief Returns the xz = zx Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> xz() const noexcept {
    return ScalarStress<Number>{this->value.xz()};
  }

  /// \brief Returns the yx = xy Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> yx() const noexcept {
    return ScalarStress<Number>{this->value.yx()};
  }

  /// \brief Returns the yy Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> yy() const noexcept {
    return ScalarStress<Number>{this->value.yy()};
  }

  /// \brief Returns the yz = zy Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> yz() const noexcept {
    return ScalarStress<Number>{this->value.yz()};
  }

  /// \brief Returns the zx = xz Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> zx() const noexcept {
    return ScalarStress<Number>{this->value.zx()};
  }

  /// \brief Returns the zy = yz Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> zy() const noexcept {
    return ScalarStress<Number>{this->value.zy()};
  }

  /// \brief Returns the zz Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<Number> zz() const noexcept {
    return ScalarStress<Number>{this->value.zz()};
  }

  /// \brief Creates a planar traction vector from this stress tensor and a given planar direction
  /// using the definition of traction.
  [[nodiscard]] constexpr PhQ::PlanarTraction<Number> PlanarTraction(
      const PlanarDirection<Number>& direction) const {
    return PhQ::PlanarTraction<Number>{*this, direction};
  }

  /// \brief Creates a traction vector from this stress tensor and a given direction using the
  /// definition of traction.
  [[nodiscard]] constexpr PhQ::Traction<Number> Traction(const Direction<Number>& direction) const {
    return PhQ::Traction<Number>{*this, direction};
  }

  /// \brief Computes the von Mises stress of this stress tensor using the von Mises yield
  /// criterion.
  [[nodiscard]] constexpr ScalarStress<Number> VonMises() const {
    return ScalarStress<Number>{std::sqrt(
        0.5
        * (std::pow(this->value.xx() - this->value.yy(), 2)
           + std::pow(this->value.yy() - this->value.zz(), 2)
           + std::pow(this->value.zz() - this->value.xx(), 2)
           + 6.0
                 * (std::pow(this->value.xy(), 2) + std::pow(this->value.xz(), 2)
                    + std::pow(this->value.yz(), 2))))};
  }

  constexpr Stress<Number> operator+(const Stress<Number>& stress) const {
    return Stress<Number>{this->value + stress.value};
  }

  constexpr Stress<Number> operator-(const Stress<Number>& stress) const {
    return Stress<Number>{this->value - stress.value};
  }

  constexpr Stress<Number> operator*(const Number number) const {
    return Stress<Number>{this->value * number};
  }

  constexpr Stress<Number> operator/(const Number number) const {
    return Stress<Number>{this->value / number};
  }

  constexpr void operator+=(const Stress<Number>& stress) noexcept {
    this->value += stress.value;
  }

  constexpr void operator-=(const Stress<Number>& stress) noexcept {
    this->value -= stress.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a stress tensor with a given value expressed in the standard
  /// pressure unit.
  explicit constexpr Stress(const SymmetricDyad<Number>& value)
    : DimensionalSymmetricDyad<Unit::Pressure, Number>(value) {}
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
inline constexpr PlanarTraction<Number>::PlanarTraction(
    const Stress<Number>& stress, const PhQ::PlanarDirection<Number>& planar_direction)
  : PlanarTraction<Number>(PlanarVector<Number>{stress.Value() * planar_direction}) {}

template <typename Number>
inline constexpr Traction<Number>::Traction(
    const Stress<Number>& stress, const PhQ::Direction<Number>& direction)
  : Traction<Number>(Vector<Number>{stress.Value() * direction}) {}

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
