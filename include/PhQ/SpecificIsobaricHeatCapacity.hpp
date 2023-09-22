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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_ISOBARIC_HEAT_CAPACITY_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_ISOBARIC_HEAT_CAPACITY_HPP

#include "IsobaricHeatCapacity.hpp"
#include "SpecificIsochoricHeatCapacity.hpp"

namespace PhQ {

// Forward declarations for class SpecificIsobaricHeatCapacity.
class DynamicViscosity;
class MassDensity;
class PrandtlNumber;
class ThermalConductivityScalar;
class ThermalDiffusivity;

// Specific isobaric heat capacity. Isobaric heat capacity per unit mass.
class SpecificIsobaricHeatCapacity
  : public DimensionalScalarQuantity<Unit::SpecificHeatCapacity> {
public:
  constexpr SpecificIsobaricHeatCapacity()
    : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>() {}

  SpecificIsobaricHeatCapacity(
      const double value, const Unit::SpecificHeatCapacity unit)
    : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value, unit) {}

  constexpr SpecificIsobaricHeatCapacity(
      const SpecificGasConstant& specific_gas_constant,
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity);

  constexpr SpecificIsobaricHeatCapacity(
      const SpecificGasConstant& specific_gas_constant,
      const SpecificHeatRatio& specific_heat_ratio);

  constexpr SpecificIsobaricHeatCapacity(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity,
      const SpecificHeatRatio& specific_heat_ratio)
    : SpecificIsobaricHeatCapacity(specific_isochoric_heat_capacity.Value()
                                   * specific_heat_ratio.Value()) {}

  constexpr SpecificIsobaricHeatCapacity(
      const IsobaricHeatCapacity& isobaric_heat_capacity, const Mass& mass)
    : SpecificIsobaricHeatCapacity(
        isobaric_heat_capacity.Value() / mass.Value()) {}

  constexpr SpecificIsobaricHeatCapacity(
      const ThermalDiffusivity& thermal_diffusivity,
      const ThermalConductivityScalar& thermal_conductivity_scalar,
      const MassDensity& mass_density);

  constexpr SpecificIsobaricHeatCapacity(
      const PrandtlNumber& prandtl_number,
      const ThermalConductivityScalar& thermal_conductivity_scalar,
      const DynamicViscosity& dynamic_viscosity);

  static constexpr SpecificIsobaricHeatCapacity Zero() {
    return SpecificIsobaricHeatCapacity{0.0};
  }

  template <Unit::SpecificHeatCapacity Unit>
  static constexpr SpecificIsobaricHeatCapacity Create(const double value) {
    return SpecificIsobaricHeatCapacity{
        StaticConvertCopy<Unit::SpecificHeatCapacity, Unit,
                          Standard<Unit::SpecificHeatCapacity>>(value)};
  }

  constexpr SpecificIsobaricHeatCapacity
  operator+(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity)
      const {
    return SpecificIsobaricHeatCapacity{
        value_ + specific_isobaric_heat_capacity.value_};
  }

  constexpr SpecificIsobaricHeatCapacity
  operator-(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity)
      const {
    return SpecificIsobaricHeatCapacity{
        value_ - specific_isobaric_heat_capacity.value_};
  }

  constexpr SpecificGasConstant operator-(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
      const;

  constexpr SpecificIsochoricHeatCapacity operator-(
      const SpecificGasConstant& specific_gas_constant) const;

  constexpr SpecificIsobaricHeatCapacity operator*(const double number) const {
    return SpecificIsobaricHeatCapacity{value_ * number};
  }

  constexpr IsobaricHeatCapacity operator*(const Mass& mass) const {
    return {*this, mass};
  }

  constexpr SpecificIsobaricHeatCapacity operator/(const double number) const {
    return SpecificIsobaricHeatCapacity{value_ / number};
  }

  constexpr SpecificHeatRatio operator/(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
      const {
    return {*this, specific_isochoric_heat_capacity};
  }

  constexpr SpecificIsochoricHeatCapacity operator/(
      const SpecificHeatRatio& specific_heat_ratio) const {
    return {*this, specific_heat_ratio};
  }

  constexpr double
  operator/(const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity)
      const noexcept {
    return value_ / specific_isobaric_heat_capacity.value_;
  }

  constexpr void operator+=(const SpecificIsobaricHeatCapacity&
                                specific_isobaric_heat_capacity) noexcept {
    value_ += specific_isobaric_heat_capacity.value_;
  }

  constexpr void operator-=(const SpecificIsobaricHeatCapacity&
                                specific_isobaric_heat_capacity) noexcept {
    value_ -= specific_isobaric_heat_capacity.value_;
  }

  constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr SpecificIsobaricHeatCapacity(const double value)
    : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value) {}
};

inline constexpr bool operator==(
    const SpecificIsobaricHeatCapacity& left,
    const SpecificIsobaricHeatCapacity& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const SpecificIsobaricHeatCapacity& left,
    const SpecificIsobaricHeatCapacity& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const SpecificIsobaricHeatCapacity& left,
    const SpecificIsobaricHeatCapacity& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const SpecificIsobaricHeatCapacity& left,
    const SpecificIsobaricHeatCapacity& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const SpecificIsobaricHeatCapacity& left,
    const SpecificIsobaricHeatCapacity& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const SpecificIsobaricHeatCapacity& left,
    const SpecificIsobaricHeatCapacity& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) {
  stream << specific_isobaric_heat_capacity.Print();
  return stream;
}

inline constexpr SpecificIsobaricHeatCapacity operator*(
    const double number,
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) {
  return specific_isobaric_heat_capacity * number;
}

inline constexpr SpecificHeatRatio::SpecificHeatRatio(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
  : SpecificHeatRatio(specific_isobaric_heat_capacity.Value()
                      / specific_isochoric_heat_capacity.Value()) {}

inline constexpr Mass::Mass(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
    const IsobaricHeatCapacity& isobaric_heat_capacity)
  : Mass(isobaric_heat_capacity.Value()
         / specific_isobaric_heat_capacity.Value()) {}

inline constexpr IsobaricHeatCapacity::IsobaricHeatCapacity(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
    const Mass& mass)
  : IsobaricHeatCapacity(
      specific_isobaric_heat_capacity.Value() * mass.Value()) {}

inline constexpr SpecificIsochoricHeatCapacity::SpecificIsochoricHeatCapacity(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
    const SpecificHeatRatio& specific_heat_ratio)
  : SpecificIsochoricHeatCapacity(
      specific_isobaric_heat_capacity.Value() / specific_heat_ratio.Value()) {}

inline constexpr IsobaricHeatCapacity Mass::operator*(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const {
  return {specific_isobaric_heat_capacity, *this};
}

inline constexpr SpecificIsobaricHeatCapacity SpecificHeatRatio::operator*(
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
    const {
  return {specific_isochoric_heat_capacity, *this};
}

inline constexpr SpecificIsobaricHeatCapacity IsobaricHeatCapacity::operator/(
    const Mass& mass) const {
  return {*this, mass};
}

inline constexpr Mass IsobaricHeatCapacity::operator/(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity) const {
  return {specific_isobaric_heat_capacity, *this};
}

inline constexpr SpecificIsobaricHeatCapacity
SpecificIsochoricHeatCapacity::operator*(
    const SpecificHeatRatio& specific_heat_ratio) const {
  return {*this, specific_heat_ratio};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::SpecificIsobaricHeatCapacity> {
  inline size_t operator()(
      const PhQ::SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity)
      const {
    return hash<double>()(specific_isobaric_heat_capacity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_ISOBARIC_HEAT_CAPACITY_HPP
