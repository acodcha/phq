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
template <typename Number = double>
class LinearThermalExpansionCoefficient : public DimensionalScalar<Unit::ThermalExpansion, Number> {
public:
  // Default constructor. Constructs a linear thermal expansion coefficient with an uninitialized
  // value.
  LinearThermalExpansionCoefficient() = default;

  // Constructor. Constructs a linear thermal expansion coefficient with a given value expressed in
  // a given thermal expansion unit.
  LinearThermalExpansionCoefficient(const Number value, const Unit::ThermalExpansion unit)
    : DimensionalScalar<Unit::ThermalExpansion, Number>(value, unit) {}

  // Destructor. Destroys this linear thermal expansion coefficient.
  ~LinearThermalExpansionCoefficient() noexcept = default;

  // Copy constructor. Constructs a linear thermal expansion coefficient by copying another one.
  constexpr LinearThermalExpansionCoefficient(
      const LinearThermalExpansionCoefficient<Number>& other) = default;

  // Copy constructor. Constructs a linear thermal expansion coefficient by copying another one.
  template <typename OtherNumber>
  explicit constexpr LinearThermalExpansionCoefficient(
      const LinearThermalExpansionCoefficient<OtherNumber>& other)
    : LinearThermalExpansionCoefficient(static_cast<Number>(other.Value())) {}

  // Move constructor. Constructs a linear thermal expansion coefficient by moving another one.
  constexpr LinearThermalExpansionCoefficient(
      LinearThermalExpansionCoefficient<Number>&& other) noexcept = default;

  // Copy assignment operator. Assigns this linear thermal expansion coefficient by copying another
  // one.
  constexpr LinearThermalExpansionCoefficient<Number>& operator=(
      const LinearThermalExpansionCoefficient<Number>& other) = default;

  // Copy assignment operator. Assigns this linear thermal expansion coefficient by copying another
  // one.
  template <typename OtherNumber>
  constexpr LinearThermalExpansionCoefficient<Number>& operator=(
      const LinearThermalExpansionCoefficient<OtherNumber>& other) {
    this->value = static_cast<Number>(other.Value());
    return *this;
  }

  // Move assignment operator. Assigns this linear thermal expansion coefficient by moving another
  // one.
  constexpr LinearThermalExpansionCoefficient<Number>& operator=(
      LinearThermalExpansionCoefficient<Number>&& other) noexcept = default;

  // Statically creates a linear thermal expansion coefficient of zero.
  static constexpr LinearThermalExpansionCoefficient<Number> Zero() {
    return LinearThermalExpansionCoefficient<Number>{static_cast<Number>(0)};
  }

  // Statically creates a linear thermal expansion coefficient with a given value expressed in a
  // given thermal expansion unit.
  template <Unit::ThermalExpansion Unit>
  static constexpr LinearThermalExpansionCoefficient<Number> Create(const Number value) {
    return LinearThermalExpansionCoefficient<Number>{
        StaticConvertCopy<Unit::ThermalExpansion, Unit, Standard<Unit::ThermalExpansion>>(value)};
  }

  constexpr LinearThermalExpansionCoefficient<Number> operator+(
      const LinearThermalExpansionCoefficient<Number>& linear_thermal_expansion_coefficient) const {
    return LinearThermalExpansionCoefficient<Number>{
        this->value + linear_thermal_expansion_coefficient.value};
  }

  constexpr LinearThermalExpansionCoefficient<Number> operator-(
      const LinearThermalExpansionCoefficient<Number>& linear_thermal_expansion_coefficient) const {
    return LinearThermalExpansionCoefficient<Number>{
        this->value - linear_thermal_expansion_coefficient.value};
  }

  constexpr LinearThermalExpansionCoefficient<Number> operator*(const Number number) const {
    return LinearThermalExpansionCoefficient<Number>{this->value * number};
  }

  constexpr ScalarStrain<Number> operator*(
      const TemperatureDifference<Number>& temperature_difference) const {
    return ScalarStrain<Number>{*this, temperature_difference};
  }

  constexpr LinearThermalExpansionCoefficient<Number> operator/(const Number number) const {
    return LinearThermalExpansionCoefficient<Number>{this->value / number};
  }

  constexpr Number operator/(
      const LinearThermalExpansionCoefficient<Number>& linear_thermal_expansion_coefficient)
      const noexcept {
    return this->value / linear_thermal_expansion_coefficient.value;
  }

  constexpr void operator+=(const LinearThermalExpansionCoefficient<Number>&
                                linear_thermal_expansion_coefficient) noexcept {
    this->value += linear_thermal_expansion_coefficient.value;
  }

  constexpr void operator-=(const LinearThermalExpansionCoefficient<Number>&
                                linear_thermal_expansion_coefficient) noexcept {
    this->value -= linear_thermal_expansion_coefficient.value;
  }

  constexpr void operator*=(const Number number) noexcept {
    this->value *= number;
  }

  constexpr void operator/=(const Number number) noexcept {
    this->value /= number;
  }

private:
  // Constructor. Constructs a linear thermal expansion coefficient with a given value expressed in
  // the standard thermal expansion unit.
  explicit constexpr LinearThermalExpansionCoefficient(const Number value)
    : DimensionalScalar<Unit::ThermalExpansion, Number>(value) {}
};

template <typename Number>
inline constexpr bool operator==(const LinearThermalExpansionCoefficient<Number>& left,
                                 const LinearThermalExpansionCoefficient<Number>& right) noexcept {
  return left.Value() == right.Value();
}

template <typename Number>
inline constexpr bool operator!=(const LinearThermalExpansionCoefficient<Number>& left,
                                 const LinearThermalExpansionCoefficient<Number>& right) noexcept {
  return left.Value() != right.Value();
}

template <typename Number>
inline constexpr bool operator<(const LinearThermalExpansionCoefficient<Number>& left,
                                const LinearThermalExpansionCoefficient<Number>& right) noexcept {
  return left.Value() < right.Value();
}

template <typename Number>
inline constexpr bool operator>(const LinearThermalExpansionCoefficient<Number>& left,
                                const LinearThermalExpansionCoefficient<Number>& right) noexcept {
  return left.Value() > right.Value();
}

template <typename Number>
inline constexpr bool operator<=(const LinearThermalExpansionCoefficient<Number>& left,
                                 const LinearThermalExpansionCoefficient<Number>& right) noexcept {
  return left.Value() <= right.Value();
}

template <typename Number>
inline constexpr bool operator>=(const LinearThermalExpansionCoefficient<Number>& left,
                                 const LinearThermalExpansionCoefficient<Number>& right) noexcept {
  return left.Value() >= right.Value();
}

template <typename Number>
inline std::ostream& operator<<(
    std::ostream& stream,
    const LinearThermalExpansionCoefficient<Number>& linear_thermal_expansion_coefficient) {
  stream << linear_thermal_expansion_coefficient.Print();
  return stream;
}

template <typename Number>
inline constexpr LinearThermalExpansionCoefficient<Number> operator*(
    const Number number,
    const LinearThermalExpansionCoefficient<Number>& linear_thermal_expansion_coefficient) {
  return linear_thermal_expansion_coefficient * number;
}

template <typename Number>
inline constexpr ScalarStrain<Number>::ScalarStrain(
    const LinearThermalExpansionCoefficient<Number>& linear_thermal_expansion_coefficient,
    const TemperatureDifference<Number>& temperature_difference)
  : ScalarStrain<Number>(
      linear_thermal_expansion_coefficient.Value() * temperature_difference.Value()) {}

template <typename Number>
inline constexpr ScalarStrain<Number> TemperatureDifference<Number>::operator*(
    const LinearThermalExpansionCoefficient<Number>& linear_thermal_expansion_coefficient) const {
  return ScalarStrain<Number>{linear_thermal_expansion_coefficient, *this};
}

}  // namespace PhQ

namespace std {

template <typename Number>
struct hash<PhQ::LinearThermalExpansionCoefficient<Number>> {
  inline size_t operator()(
      const PhQ::LinearThermalExpansionCoefficient<Number>& linear_thermal_expansion_coefficient)
      const {
    return hash<Number>()(linear_thermal_expansion_coefficient.Value());
  }
};

}  // namespace std

#endif  // PHQ_LINEAR_THERMAL_EXPANSION_COEFFICIENT_HPP
