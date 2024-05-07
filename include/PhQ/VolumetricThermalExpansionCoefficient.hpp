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

#ifndef PHQ_VOLUMETRIC_THERMAL_EXPANSION_COEFFICIENT_HPP
#define PHQ_VOLUMETRIC_THERMAL_EXPANSION_COEFFICIENT_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "TemperatureDifference.hpp"
#include "Unit/ThermalExpansion.hpp"

namespace PhQ {

// Volumetric thermal expansion coefficient. Not to be confused with the linear thermal expansion
// coefficient.
class VolumetricThermalExpansionCoefficient
  : public DimensionalScalar<Unit::ThermalExpansion, double> {
public:
  // Default constructor. Constructs a volumetric thermal expansion coefficient with an
  // uninitialized value.
  VolumetricThermalExpansionCoefficient() = default;

  // Constructor. Constructs a volumetric thermal expansion coefficient with a given value expressed
  // in a given thermal expansion unit.
  VolumetricThermalExpansionCoefficient(const double value, const Unit::ThermalExpansion unit)
    : DimensionalScalar<Unit::ThermalExpansion>(value, unit) {}

  // Destructor. Destroys this volumetric thermal expansion coefficient.
  ~VolumetricThermalExpansionCoefficient() noexcept = default;

  // Copy constructor. Constructs a volumetric thermal expansion coefficient by copying another one.
  constexpr VolumetricThermalExpansionCoefficient(
      const VolumetricThermalExpansionCoefficient& other) = default;

  // Move constructor. Constructs a volumetric thermal expansion coefficient by moving another one.
  constexpr VolumetricThermalExpansionCoefficient(
      VolumetricThermalExpansionCoefficient&& other) noexcept = default;

  // Copy assignment operator. Assigns this volumetric thermal expansion coefficient by copying
  // another one.
  constexpr VolumetricThermalExpansionCoefficient& operator=(
      const VolumetricThermalExpansionCoefficient& other) = default;

  // Move assignment operator. Assigns this volumetric thermal expansion coefficient by moving
  // another one.
  constexpr VolumetricThermalExpansionCoefficient& operator=(
      VolumetricThermalExpansionCoefficient&& other) noexcept = default;

  // Statically creates a volumetric thermal expansion coefficient of zero.
  static constexpr VolumetricThermalExpansionCoefficient Zero() {
    return VolumetricThermalExpansionCoefficient{0.0};
  }

  // Statically creates a volumetric thermal expansion coefficient with a given value expressed in a
  // given thermal expansion unit.
  template <Unit::ThermalExpansion Unit>
  static constexpr VolumetricThermalExpansionCoefficient Create(const double value) {
    return VolumetricThermalExpansionCoefficient{
        StaticConvertCopy<Unit::ThermalExpansion, Unit, Standard<Unit::ThermalExpansion>>(value)};
  }

  constexpr VolumetricThermalExpansionCoefficient operator+(
      const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) const {
    return VolumetricThermalExpansionCoefficient{
        value + volumetric_thermal_expansion_coefficient.value};
  }

  constexpr VolumetricThermalExpansionCoefficient operator-(
      const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) const {
    return VolumetricThermalExpansionCoefficient{
        value - volumetric_thermal_expansion_coefficient.value};
  }

  constexpr VolumetricThermalExpansionCoefficient operator*(const double number) const {
    return VolumetricThermalExpansionCoefficient{value * number};
  }

  constexpr double operator*(const TemperatureDifference& temperature_difference) const {
    return value * temperature_difference.Value();
  }

  constexpr VolumetricThermalExpansionCoefficient operator/(const double number) const {
    return VolumetricThermalExpansionCoefficient{value / number};
  }

  constexpr double operator/(
      const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient)
      const noexcept {
    return value / volumetric_thermal_expansion_coefficient.value;
  }

  constexpr void operator+=(const VolumetricThermalExpansionCoefficient&
                                volumetric_thermal_expansion_coefficient) noexcept {
    value += volumetric_thermal_expansion_coefficient.value;
  }

  constexpr void operator-=(const VolumetricThermalExpansionCoefficient&
                                volumetric_thermal_expansion_coefficient) noexcept {
    value -= volumetric_thermal_expansion_coefficient.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a volumetric thermal expansion coefficient with a given value expressed
  // in the standard thermal expansion unit.
  explicit constexpr VolumetricThermalExpansionCoefficient(const double value)
    : DimensionalScalar<Unit::ThermalExpansion>(value) {}
};

inline constexpr double TemperatureDifference::operator*(
    const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) const {
  return value * volumetric_thermal_expansion_coefficient.Value();
}

inline constexpr bool operator==(const VolumetricThermalExpansionCoefficient& left,
                                 const VolumetricThermalExpansionCoefficient& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const VolumetricThermalExpansionCoefficient& left,
                                 const VolumetricThermalExpansionCoefficient& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const VolumetricThermalExpansionCoefficient& left,
                                const VolumetricThermalExpansionCoefficient& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const VolumetricThermalExpansionCoefficient& left,
                                const VolumetricThermalExpansionCoefficient& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const VolumetricThermalExpansionCoefficient& left,
                                 const VolumetricThermalExpansionCoefficient& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const VolumetricThermalExpansionCoefficient& left,
                                 const VolumetricThermalExpansionCoefficient& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) {
  stream << volumetric_thermal_expansion_coefficient.Print();
  return stream;
}

inline constexpr VolumetricThermalExpansionCoefficient operator*(
    const double number,
    const VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient) {
  return volumetric_thermal_expansion_coefficient * number;
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::VolumetricThermalExpansionCoefficient> {
  inline size_t operator()(
      const PhQ::VolumetricThermalExpansionCoefficient& volumetric_thermal_expansion_coefficient)
      const {
    return hash<double>()(volumetric_thermal_expansion_coefficient.Value());
  }
};

}  // namespace std

#endif  // PHQ_VOLUMETRIC_THERMAL_EXPANSION_COEFFICIENT_HPP
