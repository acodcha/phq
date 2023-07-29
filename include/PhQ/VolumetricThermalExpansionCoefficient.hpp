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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_VOLUMETRIC_THERMAL_EXPANSION_COEFFICIENT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_VOLUMETRIC_THERMAL_EXPANSION_COEFFICIENT_HPP

#include "Temperature.hpp"
#include "Unit/ThermalExpansion.hpp"

namespace PhQ {

// Volumetric thermal expansion coefficient. Not to be confused with the linear
// thermal expansion coefficient.
class VolumetricThermalExpansionCoefficient
  : public DimensionalScalarQuantity<Unit::ThermalExpansion> {
public:
  constexpr VolumetricThermalExpansionCoefficient() noexcept
    : DimensionalScalarQuantity<Unit::ThermalExpansion>() {}

  VolumetricThermalExpansionCoefficient(
      const double value, const Unit::ThermalExpansion unit) noexcept
    : DimensionalScalarQuantity<Unit::ThermalExpansion>(value, unit) {}

  static constexpr VolumetricThermalExpansionCoefficient Zero() noexcept {
    return VolumetricThermalExpansionCoefficient{0.0};
  }

  template<Unit::ThermalExpansion Unit>
  static constexpr VolumetricThermalExpansionCoefficient
  Create(const double value) noexcept {
    return VolumetricThermalExpansionCoefficient{
        StaticConvertCopy<Unit::ThermalExpansion, Unit,
                          StandardUnit<Unit::ThermalExpansion>>(value)};
  }

  inline constexpr VolumetricThermalExpansionCoefficient operator+(
      const VolumetricThermalExpansionCoefficient&
          volumetric_thermal_expansion_coefficient) const noexcept {
    return VolumetricThermalExpansionCoefficient{
        value_ + volumetric_thermal_expansion_coefficient.value_};
  }

  inline constexpr VolumetricThermalExpansionCoefficient operator-(
      const VolumetricThermalExpansionCoefficient&
          volumetric_thermal_expansion_coefficient) const noexcept {
    return VolumetricThermalExpansionCoefficient{
        value_ - volumetric_thermal_expansion_coefficient.value_};
  }

  inline constexpr VolumetricThermalExpansionCoefficient operator*(
      const double number) const noexcept {
    return VolumetricThermalExpansionCoefficient{value_ * number};
  }

  inline constexpr double operator*(
      const TemperatureDifference& temperature_difference) const noexcept {
    return value_ * temperature_difference.Value();
  }

  inline constexpr VolumetricThermalExpansionCoefficient operator/(
      const double number) const noexcept {
    return VolumetricThermalExpansionCoefficient{value_ / number};
  }

  inline constexpr void operator+=(
      const VolumetricThermalExpansionCoefficient&
          volumetric_thermal_expansion_coefficient) noexcept {
    value_ += volumetric_thermal_expansion_coefficient.value_;
  }

  inline constexpr void operator-=(
      const VolumetricThermalExpansionCoefficient&
          volumetric_thermal_expansion_coefficient) noexcept {
    value_ -= volumetric_thermal_expansion_coefficient.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr VolumetricThermalExpansionCoefficient(
      const double value) noexcept
    : DimensionalScalarQuantity<Unit::ThermalExpansion>(value) {}
};

inline constexpr double TemperatureDifference::operator*(
    const VolumetricThermalExpansionCoefficient&
        volumetric_thermal_expansion_coefficient) const noexcept {
  return value_ * volumetric_thermal_expansion_coefficient.Value();
}

inline constexpr bool operator==(
    const VolumetricThermalExpansionCoefficient& left,
    const VolumetricThermalExpansionCoefficient& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const VolumetricThermalExpansionCoefficient& left,
    const VolumetricThermalExpansionCoefficient& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const VolumetricThermalExpansionCoefficient& left,
    const VolumetricThermalExpansionCoefficient& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const VolumetricThermalExpansionCoefficient& left,
    const VolumetricThermalExpansionCoefficient& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const VolumetricThermalExpansionCoefficient& left,
    const VolumetricThermalExpansionCoefficient& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const VolumetricThermalExpansionCoefficient& left,
    const VolumetricThermalExpansionCoefficient& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const VolumetricThermalExpansionCoefficient&
        volumetric_thermal_expansion_coefficient) noexcept {
  stream << volumetric_thermal_expansion_coefficient.Print();
  return stream;
}

inline constexpr VolumetricThermalExpansionCoefficient operator*(
    const double number,
    const VolumetricThermalExpansionCoefficient&
        volumetric_thermal_expansion_coefficient) noexcept {
  return volumetric_thermal_expansion_coefficient * number;
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::VolumetricThermalExpansionCoefficient> {
  size_t operator()(const PhQ::VolumetricThermalExpansionCoefficient&
                        volumetric_thermal_expansion_coefficient) const {
    return hash<double>()(volumetric_thermal_expansion_coefficient.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_VOLUMETRIC_THERMAL_EXPANSION_COEFFICIENT_HPP
