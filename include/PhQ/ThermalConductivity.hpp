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

// Thermal conductivity symmetric dyadic tensor. See also PhQ::ScalarThermalConductivity.
template <typename Number = double>
class ThermalConductivity : public DimensionalSymmetricDyad<Unit::ThermalConductivity, Number> {
public:
  // Default constructor. Constructs a thermal conductivity tensor with an uninitialized value.
  ThermalConductivity() = default;

  // Constructor. Constructs a thermal conductivity tensor with a given value expressed in a given
  // thermal conductivity unit.
  ThermalConductivity(const SymmetricDyad<Number>& value, const Unit::ThermalConductivity unit)
    : DimensionalSymmetricDyad<Unit::ThermalConductivity, Number>(value, unit) {}

  // Constructor. Constructs a thermal conductivity tensor from a given scalar thermal conductivity.
  explicit constexpr ThermalConductivity(
      const ScalarThermalConductivity<Number>& scalar_thermal_conductivity)
    : ThermalConductivity<Number>(
        {scalar_thermal_conductivity.Value(), 0.0, 0.0, scalar_thermal_conductivity.Value(), 0.0,
         scalar_thermal_conductivity.Value()}) {}

  // Destructor. Destroys this thermal conductivity tensor.
  ~ThermalConductivity() noexcept = default;

  // Copy constructor. Constructs a thermal conductivity tensor by copying another one.
  constexpr ThermalConductivity(const ThermalConductivity<Number>& other) = default;

  // Copy constructor. Constructs a thermal conductivity tensor by copying another one.
  template <typename OtherNumber>
  explicit constexpr ThermalConductivity(const ThermalConductivity<OtherNumber>& other)
    : value(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a thermal conductivity tensor by moving another one.
  constexpr ThermalConductivity(ThermalConductivity<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this thermal conductivity tensor by copying another one.
  constexpr ThermalConductivity<Number>& operator=(
      const ThermalConductivity<Number>& other) = default;

  // Copy assignment operator. Assigns this thermal conductivity tensor by copying another one.
  template <typename OtherNumber>
  constexpr ThermalConductivity<Number>& operator=(const ThermalConductivity<OtherNumber>& other) {
    value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this thermal conductivity tensor by moving another one.
  constexpr ThermalConductivity<Number>& operator=(
      ThermalConductivity<Number>&& other) noexcept = default;

  // Statically creates a thermal conductivity tensor of zero.
  static constexpr ThermalConductivity<Number> Zero() {
    return ThermalConductivity<Number>{SymmetricDyad<Number>::Zero()};
  }

  // Statically creates a thermal conductivity tensor from the given xx, xy, xz, yy, yz, and zz
  // Cartesian components expressed in a given pressure unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivity<Number> Create(
      const Number xx, const Number xy, const Number xz, const Number yy, const Number yz,
      const Number zz) {
    return ThermalConductivity<Number>{
        StaticConvertCopy<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            SymmetricDyad<Number>{xx, xy, xz, yy, yz, zz})};
  }

  // Statically creates a thermal conductivity tensor from the given xx, xy, xz, yy, yz, and zz
  // Cartesian components expressed in a given pressure unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivity<Number> Create(
      const std::array<Number, 6>& xx_xy_xz_yy_yz_zz) {
    return ThermalConductivity<Number>{
        StaticConvertCopy<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            SymmetricDyad<Number>{xx_xy_xz_yy_yz_zz})};
  }

  // Statically creates a thermal conductivity tensor with a given value expressed in a given
  // thermal conductivity unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivity<Number> Create(const SymmetricDyad<Number>& value) {
    return ThermalConductivity<Number>{
        StaticConvertCopy<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            value)};
  }

  // Returns the xx Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> xx() const noexcept {
    return ScalarThermalConductivity<Number>{value.xx()};
  }

  // Returns the xy = yx Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> xy() const noexcept {
    return ScalarThermalConductivity<Number>{value.xy()};
  }

  // Returns the xz = zx Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> xz() const noexcept {
    return ScalarThermalConductivity<Number>{value.xz()};
  }

  // Returns the yx = xy Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> yx() const noexcept {
    return ScalarThermalConductivity<Number>{value.yx()};
  }

  // Returns the yy Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> yy() const noexcept {
    return ScalarThermalConductivity<Number>{value.yy()};
  }

  // Returns the yz = zy Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> yz() const noexcept {
    return ScalarThermalConductivity<Number>{value.yz()};
  }

  // Returns the zx = xz Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> zx() const noexcept {
    return ScalarThermalConductivity<Number>{value.zx()};
  }

  // Returns the zy = yz Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> zy() const noexcept {
    return ScalarThermalConductivity<Number>{value.zy()};
  }

  // Returns the zz Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity<Number> zz() const noexcept {
    return ScalarThermalConductivity<Number>{value.zz()};
  }

  constexpr ThermalConductivity<Number> operator+(
      const ThermalConductivity<Number>& thermal_conductivity) const {
    return ThermalConductivity<Number>{value + thermal_conductivity.value};
  }

  constexpr ThermalConductivity<Number> operator-(
      const ThermalConductivity<Number>& thermal_conductivity) const {
    return ThermalConductivity<Number>{value - thermal_conductivity.value};
  }

  constexpr ThermalConductivity<Number> operator*(const Number number) const {
    return ThermalConductivity<Number>{value * number};
  }

  constexpr ThermalConductivity<Number> operator/(const Number number) const {
    return ThermalConductivity<Number>{value / number};
  }

  constexpr void operator+=(const ThermalConductivity<Number>& thermal_conductivity) noexcept {
    value += thermal_conductivity.value;
  }

  constexpr void operator-=(const ThermalConductivity<Number>& thermal_conductivity) noexcept {
    value -= thermal_conductivity.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a thermal conductivity tensor with a given value expressed in the
  // standard thermal conductivity unit.
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
