// Copyright © 2020-2024 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical quantities, physical
// models, and units of measure for scientific computing.
//
// Physical Quantities is hosted at:
//     https://github.com/acodcha/phq
//
// Physical Quantities is licensed under the MIT License:
//     https://mit-license.org
//
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and
// associated documentation files (the "Software"), to deal in the Software without restriction,
// including without limitation the rights to use, copy, modify, merge, publish, distribute,
// sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//   - The above copyright notice and this permission notice shall be included in all copies or
//     substantial portions of the Software.
//   - THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
//     BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
//     NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
//     DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM
//     OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

#ifndef PHQ_THERMAL_CONDUCTIVITY_HPP
#define PHQ_THERMAL_CONDUCTIVITY_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalSymmetricDyad.hpp"
#include "ScalarThermalConductivity.hpp"
#include "SymmetricDyad.hpp"
#include "Unit/ThermalConductivity.hpp"

namespace PhQ {

/// \brief Three-dimensional Euclidean Cauchy thermal conductivity symmetric dyadic tensor. Contains
/// six components in Cartesian coordinates: xx, xy = yx, xz = zx, yy, yz = zy, and zz. In general,
/// thermal conductivity is a tensor; however, in isotropic materials, thermal conductivity
/// simplifies to a scalar. For the scalar components or resultants of a thermal conductivity
/// tensor, see PhQ::ScalarThermalConductivity.
template <typename NumericType = double>
class ThermalConductivity
  : public DimensionalSymmetricDyad<Unit::ThermalConductivity, NumericType> {
public:
  /// \brief Default constructor. Constructs a thermal conductivity tensor with an uninitialized
  /// value.
  ThermalConductivity() = default;

  /// \brief Constructor. Constructs a thermal conductivity tensor with a given value expressed in a
  /// given thermal conductivity unit.
  ThermalConductivity(const SymmetricDyad<NumericType>& value, const Unit::ThermalConductivity unit)
    : DimensionalSymmetricDyad<Unit::ThermalConductivity, NumericType>(value, unit) {}

  /// \brief Constructor. Constructs a thermal conductivity tensor from a given scalar thermal
  /// conductivity.
  explicit constexpr ThermalConductivity(
      const ScalarThermalConductivity<NumericType>& scalar_thermal_conductivity)
    : ThermalConductivity<NumericType>(
        {scalar_thermal_conductivity.Value(), 0.0, 0.0, scalar_thermal_conductivity.Value(), 0.0,
         scalar_thermal_conductivity.Value()}) {}

  /// \brief Destructor. Destroys this thermal conductivity tensor.
  ~ThermalConductivity() noexcept = default;

  /// \brief Copy constructor. Constructs a thermal conductivity tensor by copying another one.
  constexpr ThermalConductivity(const ThermalConductivity<NumericType>& other) = default;

  /// \brief Copy constructor. Constructs a thermal conductivity tensor by copying another one.
  template <typename OtherNumericType>
  explicit constexpr ThermalConductivity(const ThermalConductivity<OtherNumericType>& other)
    : ThermalConductivity(static_cast<SymmetricDyad<NumericType>>(other.Value())) {}

  /// \brief Move constructor. Constructs a thermal conductivity tensor by moving another one.
  constexpr ThermalConductivity(ThermalConductivity<NumericType>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this thermal conductivity tensor by copying another
  /// one.
  constexpr ThermalConductivity<NumericType>& operator=(
      const ThermalConductivity<NumericType>& other) = default;

  /// \brief Copy assignment operator. Assigns this thermal conductivity tensor by copying another
  /// one.
  template <typename OtherNumericType>
  constexpr ThermalConductivity<NumericType>& operator=(
      const ThermalConductivity<OtherNumericType>& other) {
    this->value = static_cast<SymmetricDyad<NumericType>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this thermal conductivity tensor by moving another
  /// one.
  constexpr ThermalConductivity<NumericType>& operator=(
      ThermalConductivity<NumericType>&& other) noexcept = default;

  /// \brief Statically creates a thermal conductivity tensor of zero.
  static constexpr ThermalConductivity<NumericType> Zero() {
    return ThermalConductivity<NumericType>{SymmetricDyad<NumericType>::Zero()};
  }

  /// \brief Statically creates a thermal conductivity tensor from the given xx, xy, xz, yy, yz, and
  /// zz Cartesian components expressed in a given pressure unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivity<NumericType> Create(
      const NumericType xx, const NumericType xy, const NumericType xz, const NumericType yy,
      const NumericType yz, const NumericType zz) {
    return ThermalConductivity<NumericType>{
        ConvertStatically<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            SymmetricDyad<NumericType>{xx, xy, xz, yy, yz, zz})};
  }

  /// \brief Statically creates a thermal conductivity tensor from the given xx, xy, xz, yy, yz, and
  /// zz Cartesian components expressed in a given pressure unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivity<NumericType> Create(
      const std::array<NumericType, 6>& xx_xy_xz_yy_yz_zz) {
    return ThermalConductivity<NumericType>{
        ConvertStatically<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            SymmetricDyad<NumericType>{xx_xy_xz_yy_yz_zz})};
  }

  /// \brief Statically creates a thermal conductivity tensor with a given value expressed in a
  /// given thermal conductivity unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivity<NumericType> Create(
      const SymmetricDyad<NumericType>& value) {
    return ThermalConductivity<NumericType>{
        ConvertStatically<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            value)};
  }

  /// \brief Returns the xx Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<NumericType> xx() const noexcept {
    return ScalarThermalConductivity<NumericType>{this->value.xx()};
  }

  /// \brief Returns the xy = yx Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<NumericType> xy() const noexcept {
    return ScalarThermalConductivity<NumericType>{this->value.xy()};
  }

  /// \brief Returns the xz = zx Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<NumericType> xz() const noexcept {
    return ScalarThermalConductivity<NumericType>{this->value.xz()};
  }

  /// \brief Returns the yx = xy Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<NumericType> yx() const noexcept {
    return ScalarThermalConductivity<NumericType>{this->value.yx()};
  }

  /// \brief Returns the yy Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<NumericType> yy() const noexcept {
    return ScalarThermalConductivity<NumericType>{this->value.yy()};
  }

  /// \brief Returns the yz = zy Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<NumericType> yz() const noexcept {
    return ScalarThermalConductivity<NumericType>{this->value.yz()};
  }

  /// \brief Returns the zx = xz Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<NumericType> zx() const noexcept {
    return ScalarThermalConductivity<NumericType>{this->value.zx()};
  }

  /// \brief Returns the zy = yz Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<NumericType> zy() const noexcept {
    return ScalarThermalConductivity<NumericType>{this->value.zy()};
  }

  /// \brief Returns the zz Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<NumericType> zz() const noexcept {
    return ScalarThermalConductivity<NumericType>{this->value.zz()};
  }

  constexpr ThermalConductivity<NumericType> operator+(
      const ThermalConductivity<NumericType>& thermal_conductivity) const {
    return ThermalConductivity<NumericType>{this->value + thermal_conductivity.value};
  }

  constexpr ThermalConductivity<NumericType> operator-(
      const ThermalConductivity<NumericType>& thermal_conductivity) const {
    return ThermalConductivity<NumericType>{this->value - thermal_conductivity.value};
  }

  constexpr ThermalConductivity<NumericType> operator*(const NumericType number) const {
    return ThermalConductivity<NumericType>{this->value * number};
  }

  constexpr ThermalConductivity<NumericType> operator/(const NumericType number) const {
    return ThermalConductivity<NumericType>{this->value / number};
  }

  constexpr void operator+=(const ThermalConductivity<NumericType>& thermal_conductivity) noexcept {
    this->value += thermal_conductivity.value;
  }

  constexpr void operator-=(const ThermalConductivity<NumericType>& thermal_conductivity) noexcept {
    this->value -= thermal_conductivity.value;
  }

  constexpr void operator*=(const NumericType number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const NumericType number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a thermal conductivity tensor with a given value expressed in
  /// the standard thermal conductivity unit.
  explicit constexpr ThermalConductivity(const SymmetricDyad<NumericType>& value)
    : DimensionalSymmetricDyad<Unit::ThermalConductivity, NumericType>(value) {}
};

template <typename NumericType>
inline constexpr bool operator==(const ThermalConductivity<NumericType>& left,
                                 const ThermalConductivity<NumericType>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename NumericType>
inline constexpr bool operator!=(const ThermalConductivity<NumericType>& left,
                                 const ThermalConductivity<NumericType>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename NumericType>
inline constexpr bool operator<(const ThermalConductivity<NumericType>& left,
                                const ThermalConductivity<NumericType>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename NumericType>
inline constexpr bool operator>(const ThermalConductivity<NumericType>& left,
                                const ThermalConductivity<NumericType>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename NumericType>
inline constexpr bool operator<=(const ThermalConductivity<NumericType>& left,
                                 const ThermalConductivity<NumericType>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename NumericType>
inline constexpr bool operator>=(const ThermalConductivity<NumericType>& left,
                                 const ThermalConductivity<NumericType>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename NumericType>
inline std::ostream& operator<<(
    std::ostream& stream, const ThermalConductivity<NumericType>& thermal_conductivity) {
  stream << thermal_conductivity.Print();
  return stream;
}

template <typename NumericType>
inline constexpr ThermalConductivity<NumericType> operator*(
    const NumericType number, const ThermalConductivity<NumericType>& thermal_conductivity) {
  return thermal_conductivity * number;
}

}  // namespace PhQ

namespace std {

template <typename NumericType>
struct hash<PhQ::ThermalConductivity<NumericType>> {
  inline size_t operator()(
      const PhQ::ThermalConductivity<NumericType>& thermal_conductivity) const {
    return hash<PhQ::SymmetricDyad<NumericType>>()(thermal_conductivity.Value());
  }
};

}  // namespace std

#endif  // PHQ_THERMAL_CONDUCTIVITY_HPP
