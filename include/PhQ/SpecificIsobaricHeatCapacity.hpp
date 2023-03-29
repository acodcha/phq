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

class SpecificIsobaricHeatCapacity
    : public DimensionalScalarQuantity<Unit::SpecificHeatCapacity> {
public:
  constexpr SpecificIsobaricHeatCapacity() noexcept
      : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>() {}

  SpecificIsobaricHeatCapacity(const double value,
                               const Unit::SpecificHeatCapacity unit) noexcept
      : DimensionalScalarQuantity<Unit::SpecificHeatCapacity>(value, unit) {}

  constexpr SpecificIsobaricHeatCapacity(
      const SpecificGasConstant& specific_gas_constant,
      const SpecificIsochoricHeatCapacity&
          specific_isochoric_heat_capacity) noexcept;

  constexpr SpecificIsobaricHeatCapacity(
      const SpecificGasConstant& specific_gas_constant,
      const SpecificHeatRatio& specific_heat_ratio) noexcept;

  constexpr SpecificIsobaricHeatCapacity(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity,
      const SpecificHeatRatio& specific_heat_ratio) noexcept
      : SpecificIsobaricHeatCapacity(specific_isochoric_heat_capacity.Value() *
                                     specific_heat_ratio.Value()) {}

  constexpr SpecificIsobaricHeatCapacity(
      const IsobaricHeatCapacity& isobaric_heat_capacity,
      const Mass& mass) noexcept
      : SpecificIsobaricHeatCapacity(isobaric_heat_capacity.Value() /
                                     mass.Value()) {}

  constexpr SpecificIsobaricHeatCapacity(
      const ThermalDiffusivity& thermal_diffusivity,
      const ThermalConductivityScalar& thermal_conductivity_scalar,
      const MassDensity& mass_density) noexcept;

  constexpr SpecificIsobaricHeatCapacity(
      const PrandtlNumber& prandtl_number,
      const ThermalConductivityScalar& thermal_conductivity_scalar,
      const DynamicViscosity& dynamic_viscosity) noexcept;

  template <Unit::SpecificHeatCapacity Unit>
  static constexpr SpecificIsobaricHeatCapacity Create(
      const double value) noexcept {
    return SpecificIsobaricHeatCapacity{
        StaticConvertCopy<Unit::SpecificHeatCapacity, Unit,
                          StandardUnit<Unit::SpecificHeatCapacity>>(value)};
  }

  inline SpecificIsobaricHeatCapacity operator+(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity)
      const noexcept {
    return SpecificIsobaricHeatCapacity{value_ +
                                        specific_isobaric_heat_capacity.value_};
  }

  inline SpecificIsobaricHeatCapacity operator-(
      const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity)
      const noexcept {
    return SpecificIsobaricHeatCapacity{value_ -
                                        specific_isobaric_heat_capacity.value_};
  }

  inline SpecificGasConstant operator-(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
      const noexcept;

  inline SpecificIsochoricHeatCapacity operator-(
      const SpecificGasConstant& specific_gas_constant) const noexcept;

  inline SpecificIsobaricHeatCapacity operator*(
      const double number) const noexcept {
    return SpecificIsobaricHeatCapacity{value_ * number};
  }

  inline IsobaricHeatCapacity operator*(const Mass& mass) const noexcept {
    return {*this, mass};
  }

  inline SpecificIsobaricHeatCapacity operator/(
      const double number) const noexcept {
    return SpecificIsobaricHeatCapacity{value_ / number};
  }

  inline SpecificHeatRatio operator/(
      const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
      const noexcept {
    return {*this, specific_isochoric_heat_capacity};
  }

  inline SpecificIsochoricHeatCapacity operator/(
      const SpecificHeatRatio& specific_heat_ratio) const noexcept {
    return {*this, specific_heat_ratio};
  }

  inline constexpr void operator+=(
      const SpecificIsobaricHeatCapacity&
          specific_isobaric_heat_capacity) noexcept {
    value_ += specific_isobaric_heat_capacity.value_;
  }

  inline constexpr void operator-=(
      const SpecificIsobaricHeatCapacity&
          specific_isobaric_heat_capacity) noexcept {
    value_ -= specific_isobaric_heat_capacity.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr SpecificIsobaricHeatCapacity(const double value) noexcept
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

inline std::ostream& operator<<(std::ostream& stream,
                                const SpecificIsobaricHeatCapacity&
                                    specific_isobaric_heat_capacity) noexcept {
  stream << specific_isobaric_heat_capacity.Print();
  return stream;
}

inline SpecificIsobaricHeatCapacity operator*(
    const double number, const SpecificIsobaricHeatCapacity&
                             specific_isobaric_heat_capacity) noexcept {
  return specific_isobaric_heat_capacity * number;
}

inline constexpr SpecificHeatRatio::SpecificHeatRatio(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
    const SpecificIsochoricHeatCapacity&
        specific_isochoric_heat_capacity) noexcept
    : SpecificHeatRatio(specific_isobaric_heat_capacity.Value() /
                        specific_isochoric_heat_capacity.Value()) {}

inline constexpr Mass::Mass(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
    const IsobaricHeatCapacity& isobaric_heat_capacity) noexcept
    : Mass(isobaric_heat_capacity.Value() /
           specific_isobaric_heat_capacity.Value()) {}

inline constexpr IsobaricHeatCapacity::IsobaricHeatCapacity(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
    const Mass& mass) noexcept
    : IsobaricHeatCapacity(specific_isobaric_heat_capacity.Value() *
                           mass.Value()) {}

inline constexpr SpecificIsochoricHeatCapacity::SpecificIsochoricHeatCapacity(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity,
    const SpecificHeatRatio& specific_heat_ratio) noexcept
    : SpecificIsochoricHeatCapacity(specific_isobaric_heat_capacity.Value() /
                                    specific_heat_ratio.Value()) {}

inline IsobaricHeatCapacity Mass::operator*(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity)
    const noexcept {
  return {specific_isobaric_heat_capacity, *this};
}

inline SpecificIsobaricHeatCapacity SpecificHeatRatio::operator*(
    const SpecificIsochoricHeatCapacity& specific_isochoric_heat_capacity)
    const noexcept {
  return {specific_isochoric_heat_capacity, *this};
}

inline SpecificIsobaricHeatCapacity IsobaricHeatCapacity::operator/(
    const Mass& mass) const noexcept {
  return {*this, mass};
}

inline Mass IsobaricHeatCapacity::operator/(
    const SpecificIsobaricHeatCapacity& specific_isobaric_heat_capacity)
    const noexcept {
  return {specific_isobaric_heat_capacity, *this};
}

inline SpecificIsobaricHeatCapacity SpecificIsochoricHeatCapacity::operator*(
    const SpecificHeatRatio& specific_heat_ratio) const noexcept {
  return {*this, specific_heat_ratio};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::SpecificIsobaricHeatCapacity> {
  size_t operator()(const PhQ::SpecificIsobaricHeatCapacity&
                        specific_isobaric_heat_capacity) const {
    return hash<double>()(specific_isobaric_heat_capacity.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_SPECIFIC_ISOBARIC_HEAT_CAPACITY_HPP
