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

/// \brief Three-dimensional Euclidean Cauchy stress symmetric dyadic tensor. Contains six
/// components in Cartesian coordinates: xx, xy = yx, xz = zx, yy, yz = zy, and zz. For the scalar
/// components or resultants of a Cauchy stress tensor, see PhQ::ScalarStress.
template <typename NumericType = double>
class Stress : public DimensionalSymmetricDyad<Unit::Pressure, NumericType> {
public:
  /// \brief Default constructor. Constructs a stress tensor with an uninitialized value.
  Stress() = default;

  /// \brief Constructor. Constructs a stress tensor with a given value expressed in a given
  /// pressure unit.
  Stress(const SymmetricDyad<NumericType>& value, const Unit::Pressure unit)
    : DimensionalSymmetricDyad<Unit::Pressure, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a stress tensor from a given set of scalar stress components.
  Stress(const ScalarStress<NumericType>& xx, const ScalarStress<NumericType>& xy,
         const ScalarStress<NumericType>& xz, const ScalarStress<NumericType>& yy,
         const ScalarStress<NumericType>& yz, const ScalarStress<NumericType>& zz)
    : Stress<NumericType>(
        {xx.Value(), xy.Value(), xz.Value(), yy.Value(), yz.Value(), zz.Value()}) {}

  /// \brief Constructor. Constructs a stress tensor from a given static pressure using the
  /// definition of stress due to pressure. Since pressure is compressive, the negative of the
  /// static pressure contributes to the stress.
  constexpr explicit Stress(const StaticPressure<NumericType>& static_pressure)
    : Stress<NumericType>(
        {static_cast<NumericType>(-1.0) * static_pressure.Value(), static_cast<NumericType>(0.0),
         static_cast<NumericType>(0.0), static_cast<NumericType>(-1.0) * static_pressure.Value(),
         static_cast<NumericType>(0.0), static_cast<NumericType>(-1.0) * static_pressure.Value()}) {
  }

  /// \brief Destructor. Destroys this stress tensor.
  ~Stress() noexcept = default;

  /// \brief Copy constructor. Constructs a stress tensor by copying another one.
  constexpr Stress(const Stress<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a stress tensor by copying another one.
  template <typename OtherNumericType>
  explicit constexpr Stress(const Stress<OtherNumericType>& other)
    : Stress(static_cast<SymmetricDyad<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a stress tensor by moving another one.
  constexpr Stress(Stress<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this stress tensor by copying another one.
  constexpr Stress<NumericType>& operator=(const Stress<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this stress tensor by copying another one.
  template <typename OtherNumericType>
  constexpr Stress<NumericType>& operator=(const Stress<OtherNumericType>& other) {
    this->value = static_cast<SymmetricDyad<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this stress tensor by moving another one.
  constexpr Stress<NumericType>& operator=(Stress<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a stress tensor of zero.
  static constexpr Stress<NumericType> Zero() {
    return Stress<NumericType>{SymmetricDyad<NumericType>::Zero()};
  }

  /// \brief Statically creates a stress tensor from the given xx, xy, xz, yy, yz, and zz Cartesian
  /// components expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Stress<NumericType> Create(
      const NumericType xx, const NumericType xy, const NumericType xz, const NumericType yy,
      const NumericType yz, const NumericType zz) {
    return Stress<NumericType>{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
        SymmetricDyad<NumericType>{xx, xy, xz, yy, yz, zz})};
  }

  /// \brief Statically creates a stress tensor from the given xx, xy, xz, yy, yz, and zz Cartesian
  /// components expressed in a given pressure unit.
  template <Unit::Pressure Unit>
  static constexpr Stress<NumericType> Create(const std::array<NumericType, 6>& xx_xy_xz_yy_yz_zz) {
    return Stress<NumericType>{StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(
        SymmetricDyad<NumericType>{xx_xy_xz_yy_yz_zz})};
  }

  /// \brief Statically creates a stress tensor with a given value expressed in a given pressure
  /// unit.
  template <Unit::Pressure Unit>
  static constexpr Stress<NumericType> Create(const SymmetricDyad<NumericType>& value) {
    return Stress<NumericType>{
        StaticConvertCopy<Unit::Pressure, Unit, Standard<Unit::Pressure>>(value)};
  }

  /// \brief Returns the xx Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<NumericType> xx() const noexcept {
    return ScalarStress<NumericType>{this->value.xx()};
  }

  /// \brief Returns the xy = yx Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<NumericType> xy() const noexcept {
    return ScalarStress<NumericType>{this->value.xy()};
  }

  /// \brief Returns the xz = zx Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<NumericType> xz() const noexcept {
    return ScalarStress<NumericType>{this->value.xz()};
  }

  /// \brief Returns the yx = xy Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<NumericType> yx() const noexcept {
    return ScalarStress<NumericType>{this->value.yx()};
  }

  /// \brief Returns the yy Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<NumericType> yy() const noexcept {
    return ScalarStress<NumericType>{this->value.yy()};
  }

  /// \brief Returns the yz = zy Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<NumericType> yz() const noexcept {
    return ScalarStress<NumericType>{this->value.yz()};
  }

  /// \brief Returns the zx = xz Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<NumericType> zx() const noexcept {
    return ScalarStress<NumericType>{this->value.zx()};
  }

  /// \brief Returns the zy = yz Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<NumericType> zy() const noexcept {
    return ScalarStress<NumericType>{this->value.zy()};
  }

  /// \brief Returns the zz Cartesian component of this stress tensor.
  [[nodiscard]] constexpr ScalarStress<NumericType> zz() const noexcept {
    return ScalarStress<NumericType>{this->value.zz()};
  }

  /// \brief Creates a planar traction vector from this stress tensor and a given planar direction
  /// using the definition of traction.
  [[nodiscard]] constexpr PhQ::PlanarTraction<NumericType> PlanarTraction(
      const PlanarDirection<NumericType>& direction) const {
    return PhQ::PlanarTraction<NumericType>{*this, direction};
  }

  /// \brief Creates a traction vector from this stress tensor and a given direction using the
  /// definition of traction.
  [[nodiscard]] constexpr PhQ::Traction<NumericType> Traction(
      const Direction<NumericType>& direction) const {
    return PhQ::Traction<NumericType>{*this, direction};
  }

  /// \brief Computes the von Mises stress of this stress tensor using the von Mises yield
  /// criterion.
  [[nodiscard]] constexpr ScalarStress<NumericType> VonMises() const {
    return ScalarStress<NumericType>{std::sqrt(
        0.5
        * (std::pow(this->value.xx() - this->value.yy(), 2)
           + std::pow(this->value.yy() - this->value.zz(), 2)
           + std::pow(this->value.zz() - this->value.xx(), 2)
           + 6.0
                 * (std::pow(this->value.xy(), 2) + std::pow(this->value.xz(), 2)
                    + std::pow(this->value.yz(), 2))))};
  }

  constexpr Stress<NumericType> operator+(const Stress<NumericType>& stress) const {
    return Stress<NumericType>{this->value + stress.value};
  }

  constexpr Stress<NumericType> operator-(const Stress<NumericType>& stress) const {
    return Stress<NumericType>{this->value - stress.value};
  }

  constexpr Stress<NumericType> operator*(const NumericType number) const {
    return Stress<NumericType>{this->value * number};
  }

  constexpr Stress<NumericType> operator/(const NumericType number) const {
    return Stress<NumericType>{this->value / number};
  }

  constexpr void operator+=(const Stress<NumericType>& stress) noexcept {
    this->value += stress.value;
  }

  constexpr void operator-=(const Stress<NumericType>& stress) noexcept {
    this->value -= stress.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a stress tensor with a given value expressed in the standard
  /// pressure unit.
  explicit constexpr Stress(const SymmetricDyad<NumericType>& value)
    : DimensionalSymmetricDyad<Unit::Pressure, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(
    const Stress<NumericType>& left, const Stress<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(
    const Stress<NumericType>& left, const Stress<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(
    const Stress<NumericType>& left, const Stress<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(
    const Stress<NumericType>& left, const Stress<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(
    const Stress<NumericType>& left, const Stress<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(
    const Stress<NumericType>& left, const Stress<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(std::ostream& stream, const Stress<NumericType>& stress) {
  stream << stress.Print();
  return stream;
}

template <typename NumericType>
inline constexpr Stress<NumericType> operator*(
    const NumericType number, const Stress<NumericType>& stress) {
  return stress * number;
}

template <typename NumericType>
inline constexpr PlanarTraction<NumericType>::PlanarTraction(
    const Stress<NumericType>& stress, const PhQ::PlanarDirection<NumericType>& planar_direction)
  : PlanarTraction<NumericType>(PlanarVector<NumericType>{stress.Value() * planar_direction}) {}

template <typename NumericType>
inline constexpr Traction<NumericType>::Traction(
    const Stress<NumericType>& stress, const PhQ::Direction<NumericType>& direction)
  : Traction<NumericType>(Vector<NumericType>{stress.Value() * direction}) {}

template <typename NumericType>
inline constexpr PhQ::Stress<NumericType> StaticPressure<NumericType>::Stress() const {
  return PhQ::Stress<NumericType>{*this};
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::Stress<NumericType>> {
  inline size_t operator()(const PhQ::Stress<NumericType>& stress) const {
    return hash<PhQ::SymmetricDyad<NumericType>>()(stress.Value());
  }
};

}  // namespace std

#endif  // PHQ_STRESS_HPP
