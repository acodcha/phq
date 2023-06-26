// Copyright 2020-2023 Alexandre Coderre-Chabot
//
// This file is part of Physical Quantities (PhQ), a C++ library of physical
// quantities, physical models, and units of measure for scientific computation.
//
// Physical Quantities is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or (at your
// option) any later version. Physical Quantities is distributed in the hope
// that it will be useful, but WITHOUT ANY WARRANTY; without even the implied
// warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// Lesser General Public License for more details. You should have received a
// copy of the GNU Lesser General Public License along with Physical Quantities.
// If not, see <https://www.gnu.org/licenses/>.

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMAL_CONDUCTIVITY_SCALAR_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMAL_CONDUCTIVITY_SCALAR_HPP

#include "Quantity/DimensionalScalar.hpp"
#include "Unit/ThermalConductivity.hpp"

namespace PhQ {

// Forward declarations for class ThermalConductivityScalar.
class DynamicViscosity;
class MassDensity;
class PrandtlNumber;
class SpecificIsobaricHeatCapacity;
class ThermalDiffusivity;

class ThermalConductivityScalar
  : public DimensionalScalarQuantity<Unit::ThermalConductivity> {
public:
  constexpr ThermalConductivityScalar() noexcept
    : DimensionalScalarQuantity<Unit::ThermalConductivity>() {}

  ThermalConductivityScalar(
      const double value, const Unit::ThermalConductivity unit) noexcept
    : DimensionalScalarQuantity<Unit::ThermalConductivity>(value, unit) {}

  constexpr ThermalConductivityScalar(
      const ThermalDiffusivity& thermal_diffusivity,
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const MassDensity& mass_density) noexcept;

  constexpr ThermalConductivityScalar(
      const PrandtlNumber& prandtl_number,
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
      const DynamicViscosity& dynamic_viscosity) noexcept;

  template<Unit::ThermalConductivity Unit>
  static constexpr ThermalConductivityScalar
  Create(const double value) noexcept {
    return ThermalConductivityScalar{
        StaticConvertCopy<Unit::ThermalConductivity, Unit,
                          StandardUnit<Unit::ThermalConductivity>>(value)};
  }

  inline constexpr ThermalConductivityScalar
  operator+(const ThermalConductivityScalar& thermal_conductivity_scalar)
      const noexcept {
    return ThermalConductivityScalar{
        value_ + thermal_conductivity_scalar.value_};
  }

  inline constexpr ThermalConductivityScalar
  operator-(const ThermalConductivityScalar& thermal_conductivity_scalar)
      const noexcept {
    return ThermalConductivityScalar{
        value_ - thermal_conductivity_scalar.value_};
  }

  inline constexpr ThermalConductivityScalar operator*(
      const double number) const noexcept {
    return ThermalConductivityScalar{value_ * number};
  }

  inline constexpr ThermalConductivityScalar operator/(
      const double number) const noexcept {
    return ThermalConductivityScalar{value_ / number};
  }

  inline constexpr void operator+=(
      const ThermalConductivityScalar& thermal_conductivity_scalar) noexcept {
    value_ += thermal_conductivity_scalar.value_;
  }

  inline constexpr void operator-=(
      const ThermalConductivityScalar& thermal_conductivity_scalar) noexcept {
    value_ -= thermal_conductivity_scalar.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr ThermalConductivityScalar(const double value) noexcept
    : DimensionalScalarQuantity<Unit::ThermalConductivity>(value) {}
};

inline constexpr bool operator==(
    const ThermalConductivityScalar& left,
    const ThermalConductivityScalar& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const ThermalConductivityScalar& left,
    const ThermalConductivityScalar& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const ThermalConductivityScalar& left,
    const ThermalConductivityScalar& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const ThermalConductivityScalar& left,
    const ThermalConductivityScalar& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const ThermalConductivityScalar& left,
    const ThermalConductivityScalar& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const ThermalConductivityScalar& left,
    const ThermalConductivityScalar& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const ThermalConductivityScalar& thermal_conductivity_scalar) noexcept {
  stream << thermal_conductivity_scalar.Print();
  return stream;
}

inline constexpr ThermalConductivityScalar operator*(
    const double number,
    const ThermalConductivityScalar& thermal_conductivity_scalar) noexcept {
  return thermal_conductivity_scalar * number;
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::ThermalConductivityScalar> {
  size_t operator()(
      const PhQ::ThermalConductivityScalar& thermal_conductivity_scalar) const {
    return hash<double>()(thermal_conductivity_scalar.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_THERMAL_CONDUCTIVITY_SCALAR_HPP
