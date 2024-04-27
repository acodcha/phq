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

#ifndef PHQ_LINEAR_THERMAL_EXPANSION_COEFFICIENT_HPP
#define PHQ_LINEAR_THERMAL_EXPANSION_COEFFICIENT_HPP

#include <cstddef>
#include <functional>
#include <ostream>

#include "DimensionalScalar.hpp"
#include "ScalarStrain.hpp"
#include "TemperatureDifference.hpp"
#include "Unit/ThermalExpansion.hpp"

namespace PhQ {

// Linear thermal expansion coefficient. Not to be confused with the volumetric thermal expansion
// coefficient.
class LinearThermalExpansionCoefficient : public DimensionalScalar<Unit::ThermalExpansion> {
public:
  // Default constructor. Constructs a linear thermal expansion coefficient with an uninitialized
  // value.
  LinearThermalExpansionCoefficient() = default;

  // Constructor. Constructs a linear thermal expansion coefficient with a given value expressed in
  // a given thermal expansion unit.
  LinearThermalExpansionCoefficient(const double value, const Unit::ThermalExpansion unit)
    : DimensionalScalar<Unit::ThermalExpansion>(value, unit) {}

  // Destructor. Destroys this linear thermal expansion coefficient.
  ~LinearThermalExpansionCoefficient() noexcept = default;

  // Copy constructor. Constructs a linear thermal expansion coefficient by copying another one.
  constexpr LinearThermalExpansionCoefficient(
      const LinearThermalExpansionCoefficient& other) = default;

  // Move constructor. Constructs a linear thermal expansion coefficient by moving another one.
  constexpr LinearThermalExpansionCoefficient(
      LinearThermalExpansionCoefficient&& other) noexcept = default;

  // Copy assignment operator. Assigns this linear thermal expansion coefficient by copying another
  // one.
  constexpr LinearThermalExpansionCoefficient& operator=(
      const LinearThermalExpansionCoefficient& other) = default;

  // Move assignment operator. Assigns this linear thermal expansion coefficient by moving another
  // one.
  constexpr LinearThermalExpansionCoefficient& operator=(
      LinearThermalExpansionCoefficient&& other) noexcept = default;

  // Statically creates a linear thermal expansion coefficient of zero.
  static constexpr LinearThermalExpansionCoefficient Zero() {
    return LinearThermalExpansionCoefficient{0.0};
  }

  // Statically creates a linear thermal expansion coefficient with a given value expressed in a
  // given thermal expansion unit.
  template <Unit::ThermalExpansion Unit>
  static constexpr LinearThermalExpansionCoefficient Create(const double value) {
    return LinearThermalExpansionCoefficient{
        StaticConvertCopy<Unit::ThermalExpansion, Unit, Standard<Unit::ThermalExpansion>>(value)};
  }

  constexpr LinearThermalExpansionCoefficient operator+(
      const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) const {
    return LinearThermalExpansionCoefficient{value + linear_thermal_expansion_coefficient.value};
  }

  constexpr LinearThermalExpansionCoefficient operator-(
      const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) const {
    return LinearThermalExpansionCoefficient{value - linear_thermal_expansion_coefficient.value};
  }

  constexpr LinearThermalExpansionCoefficient operator*(const double number) const {
    return LinearThermalExpansionCoefficient{value * number};
  }

  constexpr ScalarStrain operator*(const TemperatureDifference& temperature_difference) const {
    return {*this, temperature_difference};
  }

  constexpr LinearThermalExpansionCoefficient operator/(const double number) const {
    return LinearThermalExpansionCoefficient{value / number};
  }

  constexpr double operator/(
      const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient)
      const noexcept {
    return value / linear_thermal_expansion_coefficient.value;
  }

  constexpr void operator+=(
      const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) noexcept {
    value += linear_thermal_expansion_coefficient.value;
  }

  constexpr void operator-=(
      const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) noexcept {
    value -= linear_thermal_expansion_coefficient.value;
  }

  constexpr void operator*=(const double number) noexcept {
    value *= number;
  }

  constexpr void operator/=(const double number) noexcept {
    value /= number;
  }

private:
  // Constructor. Constructs a linear thermal expansion coefficient with a given value expressed in
  // the standard thermal expansion unit.
  explicit constexpr LinearThermalExpansionCoefficient(const double value)
    : DimensionalScalar<Unit::ThermalExpansion>(value) {}
};

inline constexpr bool operator==(const LinearThermalExpansionCoefficient& left,
                                 const LinearThermalExpansionCoefficient& right) noexcept {
  return left.Value() == right.Value();
}

inline constexpr bool operator!=(const LinearThermalExpansionCoefficient& left,
                                 const LinearThermalExpansionCoefficient& right) noexcept {
  return left.Value() != right.Value();
}

inline constexpr bool operator<(const LinearThermalExpansionCoefficient& left,
                                const LinearThermalExpansionCoefficient& right) noexcept {
  return left.Value() < right.Value();
}

inline constexpr bool operator>(const LinearThermalExpansionCoefficient& left,
                                const LinearThermalExpansionCoefficient& right) noexcept {
  return left.Value() > right.Value();
}

inline constexpr bool operator<=(const LinearThermalExpansionCoefficient& left,
                                 const LinearThermalExpansionCoefficient& right) noexcept {
  return left.Value() <= right.Value();
}

inline constexpr bool operator>=(const LinearThermalExpansionCoefficient& left,
                                 const LinearThermalExpansionCoefficient& right) noexcept {
  return left.Value() >= right.Value();
}

inline std::ostream& operator<<(
    std::ostream& stream,
    const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) {
  stream << linear_thermal_expansion_coefficient.Print();
  return stream;
}

inline constexpr LinearThermalExpansionCoefficient operator*(
    const double number,
    const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) {
  return linear_thermal_expansion_coefficient * number;
}

inline constexpr ScalarStrain::ScalarStrain(
    const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient,
    const TemperatureDifference& temperature_difference)
  : ScalarStrain(linear_thermal_expansion_coefficient.Value() * temperature_difference.Value()) {}

inline constexpr ScalarStrain TemperatureDifference::operator*(
    const LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) const {
  return {linear_thermal_expansion_coefficient, *this};
}

}  // namespace PhQ

namespace std {

template <>
struct hash<PhQ::LinearThermalExpansionCoefficient> {
  inline size_t operator()(
      const PhQ::LinearThermalExpansionCoefficient& linear_thermal_expansion_coefficient) const {
    return hash<double>()(linear_thermal_expansion_coefficient.Value());
  }
};

}  // namespace std

#endif  // PHQ_LINEAR_THERMAL_EXPANSION_COEFFICIENT_HPP
