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

#ifndef PHYSICAL_QUANTITIES_INCLUDE_PHQ_LINEAR_THERMAL_EXPANSION_COEFFICIENT_HPP
#define PHYSICAL_QUANTITIES_INCLUDE_PHQ_LINEAR_THERMAL_EXPANSION_COEFFICIENT_HPP

#include "StrainScalar.hpp"
#include "Temperature.hpp"
#include "Unit/ThermalExpansion.hpp"

namespace PhQ {

// Linear thermal expansion coefficient. Not to be confused with the volumetric
// thermal expansion coefficient.
class LinearThermalExpansionCoefficient
  : public DimensionalScalarQuantity<Unit::ThermalExpansion> {
public:
  constexpr LinearThermalExpansionCoefficient() noexcept
    : DimensionalScalarQuantity<Unit::ThermalExpansion>() {}

  LinearThermalExpansionCoefficient(
      const double value, const Unit::ThermalExpansion unit) noexcept
    : DimensionalScalarQuantity<Unit::ThermalExpansion>(value, unit) {}

  static constexpr LinearThermalExpansionCoefficient Zero() noexcept {
    return LinearThermalExpansionCoefficient{0.0};
  }

  template<Unit::ThermalExpansion Unit>
  static constexpr LinearThermalExpansionCoefficient
  Create(const double value) noexcept {
    return LinearThermalExpansionCoefficient{
        StaticConvertCopy<Unit::ThermalExpansion, Unit,
                          Standard<Unit::ThermalExpansion>>(value)};
  }

  inline constexpr LinearThermalExpansionCoefficient operator+(
      const LinearThermalExpansionCoefficient&
          linear_thermal_expansion_coefficient) const noexcept {
    return LinearThermalExpansionCoefficient{
        value_ + linear_thermal_expansion_coefficient.value_};
  }

  inline constexpr LinearThermalExpansionCoefficient operator-(
      const LinearThermalExpansionCoefficient&
          linear_thermal_expansion_coefficient) const noexcept {
    return LinearThermalExpansionCoefficient{
        value_ - linear_thermal_expansion_coefficient.value_};
  }

  inline constexpr LinearThermalExpansionCoefficient operator*(
      const double number) const noexcept {
    return LinearThermalExpansionCoefficient{value_ * number};
  }

  inline constexpr StrainScalar operator*(
      const TemperatureDifference& temperature_difference) const noexcept {
    return {*this, temperature_difference};
  }

  inline constexpr LinearThermalExpansionCoefficient operator/(
      const double number) const noexcept {
    return LinearThermalExpansionCoefficient{value_ / number};
  }

  inline constexpr double operator/(
      const LinearThermalExpansionCoefficient&
          linear_thermal_expansion_coefficient) const noexcept {
    return value_ / linear_thermal_expansion_coefficient.value_;
  }

  inline constexpr void operator+=(
      const LinearThermalExpansionCoefficient&
          linear_thermal_expansion_coefficient) noexcept {
    value_ += linear_thermal_expansion_coefficient.value_;
  }

  inline constexpr void operator-=(
      const LinearThermalExpansionCoefficient&
          linear_thermal_expansion_coefficient) noexcept {
    value_ -= linear_thermal_expansion_coefficient.value_;
  }

  inline constexpr void operator*=(const double number) noexcept {
    value_ *= number;
  }

  inline constexpr void operator/=(const double number) noexcept {
    value_ /= number;
  }

private:
  explicit constexpr LinearThermalExpansionCoefficient(
      const double value) noexcept
    : DimensionalScalarQuantity<Unit::ThermalExpansion>(value) {}
};

inline constexpr bool operator==(
    const LinearThermalExpansionCoefficient& left,
    const LinearThermalExpansionCoefficient& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(
    const LinearThermalExpansionCoefficient& left,
    const LinearThermalExpansionCoefficient& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(
    const LinearThermalExpansionCoefficient& left,
    const LinearThermalExpansionCoefficient& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(
    const LinearThermalExpansionCoefficient& left,
    const LinearThermalExpansionCoefficient& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(
    const LinearThermalExpansionCoefficient& left,
    const LinearThermalExpansionCoefficient& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(
    const LinearThermalExpansionCoefficient& left,
    const LinearThermalExpansionCoefficient& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream, const LinearThermalExpansionCoefficient&
                              linear_thermal_expansion_coefficient) noexcept {
  stream << linear_thermal_expansion_coefficient.Print();
  return stream;
}

inline constexpr LinearThermalExpansionCoefficient operator*(
    const double number, const LinearThermalExpansionCoefficient&
                             linear_thermal_expansion_coefficient) noexcept {
  return linear_thermal_expansion_coefficient * number;
}

inline constexpr StrainScalar::StrainScalar(
    const LinearThermalExpansionCoefficient&
        linear_thermal_expansion_coefficient,
    const TemperatureDifference& temperature_difference) noexcept
  : StrainScalar(linear_thermal_expansion_coefficient.Value()
                 * temperature_difference.Value()) {}

inline constexpr StrainScalar TemperatureDifference::operator*(
    const LinearThermalExpansionCoefficient&
        linear_thermal_expansion_coefficient) const noexcept {
  return {linear_thermal_expansion_coefficient, *this};
}

}  // namespace PhQ

namespace std {

template<> struct hash<PhQ::LinearThermalExpansionCoefficient> {
  size_t operator()(const PhQ::LinearThermalExpansionCoefficient&
                        linear_thermal_expansion_coefficient) const {
    return hash<double>()(linear_thermal_expansion_coefficient.Value());
  }
};

}  // namespace std

#endif  // PHYSICAL_QUANTITIES_INCLUDE_PHQ_LINEAR_THERMAL_EXPANSION_COEFFICIENT_HPP
