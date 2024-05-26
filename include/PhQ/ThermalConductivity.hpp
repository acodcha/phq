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

/// \brief Thermal conductivity symmetric dyadic tensor. See also PhQ::ScalarThermalConductivity.
template <typename Number = double>
class ThermalConductivity : public DimensionalSymmetricDyad<Unit::ThermalConductivity, Number> {
public:
  /// \brief Default constructor. Constructs a thermal conductivity tensor with an uninitialized
  /// value.
  ThermalConductivity() = default;

  /// \brief Constructor. Constructs a thermal conductivity tensor with a given value expressed in a
  /// given thermal conductivity unit.
  ThermalConductivity(const SymmetricDyad<Number>& value, const Unit::ThermalConductivity unit)
    : DimensionalSymmetricDyad<Unit::ThermalConductivity, Number>(value, unit) {}

  /// \brief Constructor. Constructs a thermal conductivity tensor from a given scalar thermal
  /// conductivity.
  explicit constexpr ThermalConductivity(
      const ScalarThermalConductivity<Number>& scalar_thermal_conductivity)
    : ThermalConductivity<Number>(
        {scalar_thermal_conductivity.Value(), 0.0, 0.0, scalar_thermal_conductivity.Value(), 0.0,
         scalar_thermal_conductivity.Value()}) {}

  /// \brief Destructor. Destroys this thermal conductivity tensor.
  ~ThermalConductivity() noexcept = default;

  /// \brief Copy constructor. Constructs a thermal conductivity tensor by copying another one.
  constexpr ThermalConductivity(const ThermalConductivity<Number>& other) = default;

  /// \brief Copy constructor. Constructs a thermal conductivity tensor by copying another one.
  template <typename OtherNumber>
  explicit constexpr ThermalConductivity(const ThermalConductivity<OtherNumber>& other)
    : ThermalConductivity(static_cast<SymmetricDyad<Number>>(other.Value())) {}

  /// \brief Move constructor. Constructs a thermal conductivity tensor by moving another one.
  constexpr ThermalConductivity(ThermalConductivity<Number>&& other) noexcept = default;

  /// \brief Copy assignment operator. Assigns this thermal conductivity tensor by copying another
  /// one.
  constexpr ThermalConductivity<Number>& operator=(
      const ThermalConductivity<Number>& other) = default;

  /// \brief Copy assignment operator. Assigns this thermal conductivity tensor by copying another
  /// one.
  template <typename OtherNumber>
  constexpr ThermalConductivity<Number>& operator=(const ThermalConductivity<OtherNumber>& other) {
    this->value = static_cast<SymmetricDyad<Number>>(other.Value());
    return *this;
  }

  /// \brief Move assignment operator. Assigns this thermal conductivity tensor by moving another
  /// one.
  constexpr ThermalConductivity<Number>& operator=(
      ThermalConductivity<Number>&& other) noexcept = default;

  /// \brief Statically creates a thermal conductivity tensor of zero.
  static constexpr ThermalConductivity<Number> Zero() {
    return ThermalConductivity<Number>{SymmetricDyad<Number>::Zero()};
  }

  /// \brief Statically creates a thermal conductivity tensor from the given xx, xy, xz, yy, yz, and
  /// zz Cartesian components expressed in a given pressure unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivity<Number> Create(
      const Number xx, const Number xy, const Number xz, const Number yy, const Number yz,
      const Number zz) {
    return ThermalConductivity<Number>{
        StaticConvertCopy<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            SymmetricDyad<Number>{xx, xy, xz, yy, yz, zz})};
  }

  /// \brief Statically creates a thermal conductivity tensor from the given xx, xy, xz, yy, yz, and
  /// zz Cartesian components expressed in a given pressure unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivity<Number> Create(
      const std::array<Number, 6>& xx_xy_xz_yy_yz_zz) {
    return ThermalConductivity<Number>{
        StaticConvertCopy<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            SymmetricDyad<Number>{xx_xy_xz_yy_yz_zz})};
  }

  /// \brief Statically creates a thermal conductivity tensor with a given value expressed in a
  /// given thermal conductivity unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivity<Number> Create(const SymmetricDyad<Number>& value) {
    return ThermalConductivity<Number>{
        StaticConvertCopy<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            value)};
  }

  /// \brief Returns the xx Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> xx() const noexcept {
    return ScalarThermalConductivity<Number>{this->value.xx()};
  }

  /// \brief Returns the xy = yx Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> xy() const noexcept {
    return ScalarThermalConductivity<Number>{this->value.xy()};
  }

  /// \brief Returns the xz = zx Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> xz() const noexcept {
    return ScalarThermalConductivity<Number>{this->value.xz()};
  }

  /// \brief Returns the yx = xy Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> yx() const noexcept {
    return ScalarThermalConductivity<Number>{this->value.yx()};
  }

  /// \brief Returns the yy Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> yy() const noexcept {
    return ScalarThermalConductivity<Number>{this->value.yy()};
  }

  /// \brief Returns the yz = zy Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> yz() const noexcept {
    return ScalarThermalConductivity<Number>{this->value.yz()};
  }

  /// \brief Returns the zx = xz Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> zx() const noexcept {
    return ScalarThermalConductivity<Number>{this->value.zx()};
  }

  /// \brief Returns the zy = yz Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> zy() const noexcept {
    return ScalarThermalConductivity<Number>{this->value.zy()};
  }

  /// \brief Returns the zz Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> zz() const noexcept {
    return ScalarThermalConductivity<Number>{this->value.zz()};
  }

  constexpr ThermalConductivity<Number> operator+(
      const ThermalConductivity<Number>& thermal_conductivity) const {
    return ThermalConductivity<Number>{this->value + thermal_conductivity.value};
  }

  constexpr ThermalConductivity<Number> operator-(
      const ThermalConductivity<Number>& thermal_conductivity) const {
    return ThermalConductivity<Number>{this->value - thermal_conductivity.value};
  }

  constexpr ThermalConductivity<Number> operator*(const Number number) const {
    return ThermalConductivity<Number>{this->value * number};
  }

  constexpr ThermalConductivity<Number> operator/(const Number number) const {
    return ThermalConductivity<Number>{this->value / number};
  }

  constexpr void operator+=(const ThermalConductivity<Number>& thermal_conductivity) noexcept {
    this->value += thermal_conductivity.value;
  }

  constexpr void operator-=(const ThermalConductivity<Number>& thermal_conductivity) noexcept {
    this->value -= thermal_conductivity.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  /// \brief Constructor. Constructs a thermal conductivity tensor with a given value expressed in
  /// the standard thermal conductivity unit.
  explicit constexpr ThermalConductivity(const SymmetricDyad<Number>& value)
    : DimensionalSymmetricDyad<Unit::ThermalConductivity, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(
    const ThermalConductivity<Number>& left, const ThermalConductivity<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(
    const ThermalConductivity<Number>& left, const ThermalConductivity<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(
    const ThermalConductivity<Number>& left, const ThermalConductivity<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(
    const ThermalConductivity<Number>& left, const ThermalConductivity<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(
    const ThermalConductivity<Number>& left, const ThermalConductivity<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(
    const ThermalConductivity<Number>& left, const ThermalConductivity<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream, const ThermalConductivity<Number>& thermal_conductivity) {
  stream << thermal_conductivity.Print();
  return stream;
}

template <typename Number>
inline constexpr ThermalConductivity<Number> operator*(
    const Number number, const ThermalConductivity<Number>& thermal_conductivity) {
  return thermal_conductivity * number;
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::ThermalConductivity<Number>> {
  inline size_t operator()(const PhQ::ThermalConductivity<Number>& thermal_conductivity) const {
    return hash<PhQ::SymmetricDyad<Number>>()(thermal_conductivity.Value());
  }
};

}  // namespace std

#endif  // PHQ_THERMAL_CONDUCTIVITY_HPP
