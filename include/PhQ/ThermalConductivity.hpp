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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMAL_CONDUCTIVITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMAL_CONDUCTIVITY_HPP

#include <array>
#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalSymmetricDyad.hpp"
#include "SymmetricDyad.hpp"
#include "ThermalConductivityScalar.hpp"
#include "Unit/ThermalConductivity.hpp"

namespace PhQ {

// Thermal conductivity symmetric dyadic tensor.
class ThermalConductivity : public DimensionalSymmetricDyad<Unit::ThermalConductivity> {
public:
  // Default constructor. Constructs a thermal conductivity tensor with an uninitialized value.
  ThermalConductivity() = default;

  // Constructor. Constructs a thermal conductivity tensor with a given value expressed in a given
  // thermal conductivity unit.
  ThermalConductivity(const SymmetricDyad& value, const Unit::ThermalConductivity unit)
    : DimensionalSymmetricDyad<Unit::ThermalConductivity>(value, unit) {}

  // Constructor. Constructs a thermal conductivity tensor from a given thermal conductivity scalar.
  explicit constexpr ThermalConductivity(
      const ThermalConductivityScalar& thermal_conductivity_scalar)
    : ThermalConductivity(
        {thermal_conductivity_scalar.Value(), 0.0, 0.0, thermal_conductivity_scalar.Value(), 0.0,
         thermal_conductivity_scalar.Value()}) {}

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
    return ThermalConductivity{SymmetricDyad::Zero()};
  }

  // Statically creates a thermal conductivity tensor from the given xx, xy, xz, yy, yz, and zz
  // Cartesian components expressed in a given pressure unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivity Create(const double xx, const double xy, const double xz,
                                              const double yy, const double yz, const double zz) {
    return ThermalConductivity{
        StaticConvertCopy<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            SymmetricDyad{xx, xy, xz, yy, yz, zz})};
  }

  // Statically creates a thermal conductivity tensor from the given xx, xy, xz, yy, yz, and zz
  // Cartesian components expressed in a given pressure unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivity Create(const std::array<double, 6>& xx_xy_xz_yy_yz_zz) {
    return ThermalConductivity{
        StaticConvertCopy<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            SymmetricDyad{xx_xy_xz_yy_yz_zz})};
  }

  // Statically creates a thermal conductivity tensor with a given value expressed in a given
  // thermal conductivity unit.
  template <Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivity Create(const SymmetricDyad& value) {
    return ThermalConductivity{
        StaticConvertCopy<Unit::ThermalConductivity, Unit, Standard<Unit::ThermalConductivity>>(
            value)};
  }

  constexpr ThermalConductivity operator+(const ThermalConductivity& thermal_conductivity) const {
    return ThermalConductivity{value_ + thermal_conductivity.value_};
  }

  constexpr ThermalConductivity operator-(const ThermalConductivity& thermal_conductivity) const {
    return ThermalConductivity{value_ - thermal_conductivity.value_};
  }

  constexpr ThermalConductivity operator*(const double number) const {
    return ThermalConductivity{value_ * number};
  }

  constexpr ThermalConductivity operator/(const double number) const {
    return ThermalConductivity{value_ / number};
  }

  constexpr void operator+=(const ThermalConductivity& thermal_conductivity) noexcept {
    value_ += thermal_conductivity.value_;
  }

  constexpr void operator-=(const ThermalConductivity& thermal_conductivity) noexcept {
    value_ -= thermal_conductivity.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  // Constructor. Constructs a thermal conductivity tensor with a given value expressed in the
  // standard thermal conductivity unit.
  explicit constexpr ThermalConductivity(const SymmetricDyad& value)
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
    return hash<PhQ::SymmetricDyad>()(thermal_conductivity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMAL_CONDUCTIVITY_HPP
