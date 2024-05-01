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
class ThermalConductivity : public DimensionalSymmetricDyad<Unit::ThermalConductivity> {
public:
  // Default constructor. Constructs a thermal conductivity tensor with an uninitialized value.
  ThermalConductivity() = default;

  // Constructor. Constructs a thermal conductivity tensor with a given value expressed in a given
  // thermal conductivity unit.
  ThermalConductivity(const SymmetricDyad<double>& value, const Unit::ThermalConductivity unit)
    : DimensionalSymmetricDyad<Unit::ThermalConductivity>(value, unit) {}

  // Constructor. Constructs a thermal conductivity tensor from a given scalar thermal conductivity.
  explicit constexpr ThermalConductivity(
      const ScalarThermalConductivity& scalar_thermal_conductivity)
    : ThermalConductivity(
        {scalar_thermal_conductivity.Value(), 0.0, 0.0, scalar_thermal_conductivity.Value(), 0.0,
         scalar_thermal_conductivity.Value()}) {}

  // Destructor. Destroys this thermal conductivity tensor.
  ~ThermalConductivity() noexcept = default;

  // Copy constructor. Constructs a thermal conductivity tensor by copying another one.
  constexpr ThermalConductivity(const ThermalConductivity& other) = default;

  // Move constructor. Constructs a thermal conductivity tensor by moving another one.
  constexpr ThermalConductivity(ThermalConductivity&& other) noexcept = default;

  // Copy assignment operator. Assigns this thermal conductivity tensor by copying another one.
  constexpr ThermalConductivity& operator=(const ThermalConductivity& other) = default;

  // Move assignment operator. Assigns this thermal conductivity tensor by moving another one.
  constexpr ThermalConductivity& operator=(ThermalConductivity&& other) noexcept = default;

  // Statically creates a thermal conductivity tensor of zero.
  static constexpr ThermalConductivity Zero() {
    return ThermalConductivity{SymmetricDyad<double>::Zero()};
  }

  // Statically creates a thermal conductivity tensor from the given xx, xy, xz, yy, yz, and zz
  // Cartesian components expressed in a given pressure unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivity Create(const double xx, const double xy, const double xz,
                                              const double yy, const double yz, const double zz) {
    return ThermalConductivity{
        StaticConvertCopy<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            SymmetricDyad<double>{xx, xy, xz, yy, yz, zz})};
  }

  // Statically creates a thermal conductivity tensor from the given xx, xy, xz, yy, yz, and zz
  // Cartesian components expressed in a given pressure unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivity Create(const std::array<double, 6>& xx_xy_xz_yy_yz_zz) {
    return ThermalConductivity{
        StaticConvertCopy<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            SymmetricDyad<double>{xx_xy_xz_yy_yz_zz})};
  }

  // Statically creates a thermal conductivity tensor with a given value expressed in a given
  // thermal conductivity unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivity Create(const SymmetricDyad<double>& value) {
    return ThermalConductivity{
        StaticConvertCopy<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            value)};
  }

  // Returns the xx Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity xx() const noexcept {
    return ScalarThermalConductivity{value.xx()};
  }

  // Returns the xy = yx Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity xy() const noexcept {
    return ScalarThermalConductivity{value.xy()};
  }

  // Returns the xz = zx Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity xz() const noexcept {
    return ScalarThermalConductivity{value.xz()};
  }

  // Returns the yx = xy Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity yx() const noexcept {
    return ScalarThermalConductivity{value.yx()};
  }

  // Returns the yy Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity yy() const noexcept {
    return ScalarThermalConductivity{value.yy()};
  }

  // Returns the yz = zy Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity yz() const noexcept {
    return ScalarThermalConductivity{value.yz()};
  }

  // Returns the zx = xz Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity zx() const noexcept {
    return ScalarThermalConductivity{value.zx()};
  }

  // Returns the zy = yz Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity zy() const noexcept {
    return ScalarThermalConductivity{value.zy()};
  }

  // Returns the zz Cartesian component of this thermal conductivity tensor.
  [[nodiscard]] constexpr ScalarThermalConductivity zz() const noexcept {
    return ScalarThermalConductivity{value.zz()};
  }

  constexpr ThermalConductivity operator+(const ThermalConductivity& thermal_conductivity) const {
    return ThermalConductivity{value + thermal_conductivity.value};
  }

  constexpr ThermalConductivity operator-(const ThermalConductivity& thermal_conductivity) const {
    return ThermalConductivity{value - thermal_conductivity.value};
  }

  constexpr ThermalConductivity operator*(const double number) const {
    return ThermalConductivity{value * number};
  }

  constexpr ThermalConductivity operator/(const double number) const {
    return ThermalConductivity{value / number};
  }

  constexpr void operator+=(const ThermalConductivity& thermal_conductivity) noexcept {
    value += thermal_conductivity.value;
  }

  constexpr void operator-=(const ThermalConductivity& thermal_conductivity) noexcept {
    value -= thermal_conductivity.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a thermal conductivity tensor with a given value expressed in the
  // standard thermal conductivity unit.
  explicit constexpr ThermalConductivity(const SymmetricDyad<double>& value)
    : DimensionalSymmetricDyad<Unit::ThermalConductivity>(value) {}
};

inline constexpr bool operator==(
    const ThermalConductivity& left, const ThermalConductivity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const ThermalConductivity& left, const ThermalConductivity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const ThermalConductivity& left, const ThermalConductivity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const ThermalConductivity& left, const ThermalConductivity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const ThermalConductivity& left, const ThermalConductivity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const ThermalConductivity& left, const ThermalConductivity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const ThermalConductivity& thermal_conductivity) {
  stream << thermal_conductivity.Print();
  return stream;
}

inline constexpr ThermalConductivity operator*(
    const double number, const ThermalConductivity& thermal_conductivity) {
  return thermal_conductivity * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::ThermalConductivity> {
  inline size_t operator()(const PhQ::ThermalConductivity& thermal_conductivity) const {
    return hash<PhQ::SymmetricDyad<double>>()(thermal_conductivity.Value());
  }
};

}  // namespace std

#endif  // PHQ_THERMAL_CONDUCTIVITY_HPP
